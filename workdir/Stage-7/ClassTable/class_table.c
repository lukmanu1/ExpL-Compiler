#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class_table.h"

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

Memberfunclist *Class_Mlookup(Classtable *Ctype, char *Name) {
    Memberfunclist *mth = Ctype->Vfuncptr;
    while (mth != NULL) {
        if (strcmp(mth->Name, Name) == 0)
            return mth;
        mth = mth->Next;
    }
    return NULL;
}

/* --------------------- CLASS INSTALLATION --------------------- */

Classtable *CInstall(char *name, char *parent_class_name) {
    if (CLookup(name) != NULL) {
        printf("Class Error: Class '%s' already defined.\n", name);
        exit(1);
    }

    Classtable *newClass = (Classtable *)malloc(sizeof(Classtable));
    newClass->Name = strdup(name);
    newClass->Memberfield = NULL;
    newClass->Vfuncptr = NULL;
    newClass->Parentptr = NULL;  // Extension not supported
    newClass->Fieldcount = 0;
    newClass->Methodcount = 0;
    newClass->Class_index = CLASS_INDEX_COUNTER++;
    newClass->Next = NULL;

    // Append to class table
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

void Class_Minstall(Classtable *cptr, char *name, table_type *type, p_node *Paramlist) {
    if (cptr == NULL) {
        printf("Class Error: No active class to install method '%s'.\n", name);
        exit(1);
    }

    if (cptr->Methodcount >= 8) {
        printf("Class Error: Too many methods in class '%s'. (Limit: 8)\n", cptr->Name);
        exit(1);
    }

    if (Class_Mlookup(cptr, name) != NULL) {
        printf("Class Error: Duplicate method '%s' in class '%s'.\n", name, cptr->Name);
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
        while (temp->Next != NULL)
            temp = temp->Next;
        temp->Next = newMethod;
    }
}

/* --------------------- DEBUG PRINT --------------------- */

void PrintClassTable() {
    Classtable *C = ClassTable;
    printf("\n========= CLASS TABLE =========\n");
    while (C != NULL) {
        printf("\nClass: %s | Index: %d\n", C->Name, C->Class_index);
        printf("Fields (%d):\n", C->Fieldcount);
        Fieldlist *F = C->Memberfield;
        while (F != NULL) {
            if (F->Type)
                printf("  #%d %s : type=%s\n", F->Fieldindex, F->Name, F->Type->name);
            else if (F->Ctype)
                printf("  #%d %s : class=%s\n", F->Fieldindex, F->Name, F->Ctype->Name);
            F = F->Next;
        }

        printf("Methods (%d):\n", C->Methodcount);
        Memberfunclist *M = C->Vfuncptr;
        while (M != NULL) {
            printf("  #%d %s : returns=%s | Flabel=%d\n",
                   M->Funcposition, M->Name,
                   M->Type ? M->Type->name : "unknown", M->Flabel);
            M = M->Next;
        }

        C = C->Next;
    }
    printf("===============================\n");
}