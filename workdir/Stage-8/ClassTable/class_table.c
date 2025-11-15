#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class_table.h"
#include "./../Symbol_Table/global_symbol_table.h"

/* --------------------- GLOBAL VARIABLES --------------------- */

Classtable *ClassTable = NULL;
int CLASS_INDEX_COUNTER = 0;
int FUNC_LABEL_COUNTER = 0;

/* --------------------- LOOKUP FUNCTIONS --------------------- */

Classtable *CLookup(char *name) {
    Classtable *temp = ClassTable;
    while (temp != NULL) {
        if (strcmp(temp->Name, name) == 0)
            return temp;
        temp = temp->Next;
    }
    return NULL;
}

Fieldlist *Class_Flookup(Classtable *Ctype, char *Name) {
    Fieldlist *fld = Ctype->Memberfield;
    while (fld != NULL) {
        if (strcmp(fld->Name, Name) == 0)
            return fld;
        fld = fld->Next;
    }
    return NULL;
}

Memberfunclist* Class_Mlookup(Classtable *cptr, char *name, p_node *Paramlist) {

    Memberfunclist *mth = cptr->Vfuncptr;
    Memberfunclist *exactMatch = NULL;

    while (mth != NULL) {
        if (strcmp(mth->Name, name) == 0) {

            // try param matching -> override or find exact for call
            if (CompareParamLists(mth->Paramlist, Paramlist)) {
                exactMatch = mth;
                break;
            }
        }
        mth = mth->Next;
    }

    return exactMatch;  // NULL means: overload or new method
}

/* --------------------- CLASS INSTALLATION --------------------- */

void CopyParentFields(Classtable *child, Classtable *parent) {
    Fieldlist *pfield = parent->Memberfield;

    while (pfield != NULL) {
        Fieldlist *newField = (Fieldlist *)malloc(sizeof(Fieldlist));
        newField->Name = strdup(pfield->Name);
        newField->Type = pfield->Type;
        newField->Ctype = pfield->Ctype;
        newField->Fieldindex = child->Fieldcount++; // maintain field index order
        newField->Next = NULL;

        // Append to child field list
        if (child->Memberfield == NULL)
            child->Memberfield = newField;
        else {
            Fieldlist *temp = child->Memberfield;
            while (temp->Next != NULL)
                temp = temp->Next;
            temp->Next = newField;
        }

        pfield = pfield->Next;
    }
}

void CopyParentMethods(Classtable *child, Classtable *parent) {
    Memberfunclist *pmethod = parent->Vfuncptr;

    while (pmethod != NULL) {
        Memberfunclist *newMethod = (Memberfunclist *)malloc(sizeof(Memberfunclist));
        newMethod->Name = strdup(pmethod->Name);
        newMethod->Type = pmethod->Type;
        newMethod->Paramlist = pmethod->Paramlist;
        newMethod->Funcposition = pmethod->Funcposition;  // same slot used for overriding
        newMethod->Flabel = pmethod->Flabel;              // inherited label
        newMethod->Next = NULL;

        // Append to child's Vfunc pointer list
        if (child->Vfuncptr == NULL)
            child->Vfuncptr = newMethod;
        else {
            Memberfunclist *temp = child->Vfuncptr;
            while (temp->Next != NULL)
                temp = temp->Next;
            temp->Next = newMethod;
        }

        child->Methodcount++;
        pmethod = pmethod->Next;
    }
}

Classtable *CInstall(char *name, char *parent_class_name) {

    if (CLookup(name) != NULL) {
        printf("Class Error: Class '%s' already defined.\n", name);
        exit(1);
    }

    Classtable *newClass = (Classtable *)malloc(sizeof(Classtable));
    newClass->Name = strdup(name);
    newClass->Memberfield = NULL;
    newClass->Vfuncptr = NULL;
    newClass->Parentptr = NULL;
    newClass->Fieldcount = 0;
    newClass->Methodcount = 0;
    newClass->Class_index = CLASS_INDEX_COUNTER++;
    newClass->Next = NULL;

    if (parent_class_name != NULL) {
        Classtable *P = CLookup(parent_class_name);
        if (P == NULL) {
            printf("Class Error: Parent class '%s' not defined.\n",
                   parent_class_name);
            exit(1);
        }

        newClass->Parentptr = P;

        // copy fields & methods
        CopyParentFields(newClass, P);
        CopyParentMethods(newClass, P);
    }

    // Add to class table
    if (ClassTable == NULL)
        ClassTable = newClass;
    else {
        Classtable *temp = ClassTable;
        while (temp->Next != NULL)
            temp = temp->Next;
        temp->Next = newClass;
    }

    return newClass;
}

/* --------------------- FIELD INSTALLATION --------------------- */

void Class_Finstall(Classtable *cptr, char *typename, char *name) {
    if (cptr == NULL) {
        printf("Class Error: No active class to install field '%s'.\n", name);
        exit(1);
    }

    if (cptr->Fieldcount >= 8) {
        printf("Class Error: Too many fields in class '%s'. (Limit: 8)\n", cptr->Name);
        exit(1);
    }

    if (Class_Flookup(cptr, name) != NULL) {
        printf("Class Error: Duplicate field '%s' in class '%s'.\n", name, cptr->Name);
        exit(1);
    }

    Fieldlist *newField = (Fieldlist *)malloc(sizeof(Fieldlist));
    newField->Name = strdup(name);
    newField->Next = NULL;
    newField->Fieldindex = cptr->Fieldcount++;

    table_type *typePtr = tLookup(typename);
    if (typePtr != NULL) {
        newField->Type = typePtr;
        newField->Ctype = NULL;
    } else {
        Classtable *classPtr = CLookup(typename);
        if (classPtr == NULL) {
            printf("Class Error: Unknown type '%s' for field '%s' in class '%s'.\n",
                   typename, name, cptr->Name);
            exit(1);
        }
        newField->Type = NULL;
        newField->Ctype = classPtr;
    }

    if (cptr->Memberfield == NULL)
        cptr->Memberfield = newField;
    else {
        Fieldlist *temp = cptr->Memberfield;
        while (temp->Next != NULL)
            temp = temp->Next;
        temp->Next = newField;
    }
}

/* --------------------- METHOD INSTALLATION --------------------- */

// Helper: compare two parameter lists for exact match
int CompareParamLists(p_node *p1, p_node *p2) {
    while (p1 != NULL && p2 != NULL) {
        // Assuming p_node has fields: Name, Type (table_type* or Classtable*), etc.
        // Adjust comparison logic to your param node structure

        if (p1->type != p2->type) {
            return 0; // mismatch
        }

        p1 = p1->next;
        p2 = p2->next;
    }
    // both must end together
    return (p1 == NULL && p2 == NULL);
}

// void Class_Minstall(Classtable *cptr, char *name, table_type *type, p_node *Paramlist) {
//     if (cptr == NULL) {
//         printf("Class Error: No active class to install method '%s'.\n", name);
//         exit(1);
//     }

//     // Look for existing method with same name in Vfuncptr
//     Memberfunclist *existing = Class_Mlookup(cptr, name, Paramlist);

//     // If method already exists with this name
//     if (existing != NULL) {

//         int inheritedMethodLimit = 0;
//         if (cptr->Parentptr != NULL)
//             inheritedMethodLimit = cptr->Parentptr->Methodcount;

//         if (cptr->Parentptr != NULL && existing->Funcposition < inheritedMethodLimit) {
//             /* ---------- This is an inherited method: OVERRIDING ---------- */

//             // 1. Check if return type matches
//             if (existing->Type != type) {
//                 printf("Class Error: Return type mismatch in overriding method '%s' in class '%s'.\n",
//                        name, cptr->Name);
//                 exit(1);
//             }

//             // 2. Check parameter list compatibility
//             if (!CompareParamLists(existing->Paramlist, Paramlist)) {
//                 printf("Class Error: Parameter list mismatch in overriding method '%s' in class '%s'.\n",
//                        name, cptr->Name);
//                 exit(1);
//             }

//             // 3. Override: keep same Funcposition, assign new label & Paramlist if required
//             existing->Paramlist = Paramlist;
//             existing->Flabel = FUNC_LABEL_COUNTER++;
//             // NOTE: Methodcount is NOT incremented for overriding
//             return;
//         } else {
//             /* ---------- Method already defined in THIS class ---------- */
//             printf("Class Error: Duplicate method '%s' in class '%s'.\n",
//                    name, cptr->Name);
//             exit(1);
//         }
//     }

//     /* ---------- No existing method: NEW METHOD DEFINITION ---------- */

//     if (cptr->Methodcount >= 8) {
//         printf("Class Error: Too many methods in class '%s'. (Limit: 8)\n", cptr->Name);
//         exit(1);
//     }

//     Memberfunclist *newMethod = (Memberfunclist *)malloc(sizeof(Memberfunclist));
//     newMethod->Name = strdup(name);
//     newMethod->Type = type;
//     newMethod->Paramlist = Paramlist;
//     newMethod->Funcposition = cptr->Methodcount++;     // New VFT slot
//     newMethod->Flabel = FUNC_LABEL_COUNTER++;          // New function label
//     newMethod->Next = NULL;

//     if (cptr->Vfuncptr == NULL)
//         cptr->Vfuncptr = newMethod;
//     else {
//         Memberfunclist *temp = cptr->Vfuncptr;
//         while (temp->Next != NULL)
//             temp = temp->Next;
//         temp->Next = newMethod;
//     }
// }



void Class_Minstall(Classtable *cptr, char *name, table_type *type, p_node *Paramlist) {

    if (cptr == NULL) {
        printf("Class Error: No active class to install method '%s'.\n", name);
        exit(1);
    }

    // Lookup exact signature match -> used to determine override possibility
    Memberfunclist *overrideTarget = Class_Mlookup(cptr, name, Paramlist);

    // Check if a method with the same name exists (for overload detection)
    Memberfunclist *mth = cptr->Vfuncptr;
    int sameNameExists = 0;

    while (mth != NULL) {
        if (strcmp(mth->Name, name) == 0)
            sameNameExists = 1;
        mth = mth->Next;
    }

    /* ---------------- OVERRIDE CASE ---------------- */
    if (overrideTarget != NULL) {

        // Find inherited method limit (from parent)
        int inheritedMethodLimit = 0;
        if (cptr->Parentptr != NULL)
            inheritedMethodLimit = cptr->Parentptr->Methodcount;

        // Ensure overriding only inherited method, not replacing a method defined in this class
        if (overrideTarget->Funcposition >= inheritedMethodLimit) {
            printf("Class Error: Duplicate method '%s' in class '%s'. Cannot override.\n",
                   name, cptr->Name);
            exit(1);
        }

        // Return type must match
        if (overrideTarget->Type != type) {
            printf("Class Error: Return type mismatch in overriding method '%s' in class '%s'.\n",
                   name, cptr->Name);
            exit(1);
        }

        // Perform overriding: same Funcposition, new label
        overrideTarget->Paramlist = Paramlist;
        overrideTarget->Flabel = FUNC_LABEL_COUNTER++;
        return;  // Methodcount not incremented
    }

    /* ---------------- OVERLOAD CASE ---------------- */
    if (sameNameExists) {
        // Method with same name exists but signature is different -> OVERLOAD

        if (cptr->Methodcount >= 8) {
            printf("Class Error: Too many methods in class '%s'. Limit = 8.\n", cptr->Name);
            exit(1);
        }

        Memberfunclist *newMethod = (Memberfunclist *)malloc(sizeof(Memberfunclist));
        newMethod->Name = strdup(name);
        newMethod->Type = type;
        newMethod->Paramlist = Paramlist;
        newMethod->Funcposition = cptr->Methodcount++;  // allocate new slot in VFT
        newMethod->Flabel = FUNC_LABEL_COUNTER++;
        newMethod->Next = NULL;

        if (cptr->Vfuncptr == NULL)
            cptr->Vfuncptr = newMethod;
        else {
            Memberfunclist *temp = cptr->Vfuncptr;
            while (temp->Next != NULL) temp = temp->Next;
            temp->Next = newMethod;
        }

        return;
    }

    /* ---------------- BRAND NEW METHOD ---------------- */
    if (cptr->Methodcount >= 8) {
        printf("Class Error: Too many methods in class '%s'. Limit = 8.\n", cptr->Name);
        exit(1);
    }

    Memberfunclist *newMethod = (Memberfunclist *)malloc(sizeof(Memberfunclist));
    newMethod->Name = strdup(name);
    newMethod->Type = type;
    newMethod->Paramlist = Paramlist;
    newMethod->Funcposition = cptr->Methodcount++;
    newMethod->Flabel = FUNC_LABEL_COUNTER++;
    newMethod->Next = NULL;

    if (cptr->Vfuncptr == NULL)
        cptr->Vfuncptr = newMethod;
    else {
        Memberfunclist *temp = cptr->Vfuncptr;
        while (temp->Next != NULL) temp = temp->Next;
        temp->Next = newMethod;
    }
}

/* --------------------- DEBUG PRINT --------------------- */
void PrintParamList(p_node* P) {
    printf("(");
    while (P != NULL) {

        if (P->type != NULL)
            printf("%s", P->type->name);   // print type name
        else
            printf("unknown");             // just for safety

        if (P->next != NULL)
            printf(", ");

        P = P->next;
    }
    printf(")");
}

void PrintClassTable() {
    Classtable *C = ClassTable;

    printf("\n===================== CLASS TABLE =====================\n");

    while (C != NULL) {

        printf("\nClass Name   : %s\n", C->Name);
        printf("Class Index  : %d\n", C->Class_index);
        printf("Parent Class : %s\n", (C->Parentptr ? C->Parentptr->Name : "None"));

        printf("\n-- Fields (%d) --\n", C->Fieldcount);
        Fieldlist *F = C->Memberfield;
        while (F != NULL) {
            if (F->Type)
                printf("  [%d] %s : type = %s\n", F->Fieldindex, F->Name, F->Type->name);
            else if (F->Ctype)
                printf("  [%d] %s : class = %s\n", F->Fieldindex, F->Name, F->Ctype->Name);

            F = F->Next;
        }

        printf("\n-- Methods (%d) --\n", C->Methodcount);
        Memberfunclist *M = C->Vfuncptr;

        while (M != NULL) {

            printf("  [%d] %s ", M->Funcposition, M->Name);

            // Print parameter list
            PrintParamList(M->Paramlist);

            if (M->Type)
                printf(" : returns %s", M->Type->name);
            else
                printf(" : returns <class>");

            printf(" | Label = L%d\n", M->Flabel);

            M = M->Next;
        }

        printf("\n--------------------------------------------------------\n");

        C = C->Next;
    }

    printf("\n========================================================\n");
}