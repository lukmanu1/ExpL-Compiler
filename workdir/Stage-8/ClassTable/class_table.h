#ifndef CLASS_TABLE_H
#define CLASS_TABLE_H


#include "./../Type_Table/type_table.h"   // for table_type and p_node (Paramstruct)
// #include "./../Symbol_Table/global_symbol_table.h"


// Forward declarations to break circular dependency
typedef struct Classtable Classtable;
typedef struct Fieldlist Fieldlist;
typedef struct Memberfunclist Memberfunclist;

/* --------------------- FIELDLIST --------------------- */
struct Fieldlist {
    char *Name;               // Field name
    int Fieldindex;           // Position index in class (0..7)
    table_type *Type;         // Pointer to type_table entry
    Classtable *Ctype;        // Pointer to class (if field type is a class)
    Fieldlist *Next;          // Next field in list
};

/* --------------------- MEMBER FUNCTION LIST --------------------- */
struct Memberfunclist {
    char *Name;               // Method name
    table_type *Type;         // Return type
    p_node *Paramlist;        // Formal parameter list
    int Funcposition;         // Position index (0..7)
    int Flabel;               // Label for code generation
    Memberfunclist *Next;     // Next function
};

/* --------------------- CLASS TABLE --------------------- */
struct Classtable {
    char *Name;               // Class name
    Fieldlist *Memberfield;   // Linked list of fields
    Memberfunclist *Vfuncptr; // Linked list of methods
    Classtable *Parentptr;    // Parent class (NULL for this stage)
    int Class_index;          // Position in class table
    int Fieldcount;           // Field count
    int Methodcount;          // Method count
    Classtable *Next;         // Next class entry
};

/* --------------------- FUNCTION PROTOTYPES --------------------- */
// Copy Functions
void CopyParentFields(Classtable *child, Classtable *parent);
void CopyParentMethods(Classtable *child, Classtable *parent);

// Class Table functions
Classtable *CInstall(char *name, char *parent_class_name);
Classtable *CLookup(char *name);

// Field operations
void Class_Finstall(Classtable *cptr, char *typename, char *name);
Fieldlist *Class_Flookup(Classtable *Ctype, char *Name);

// Method operations
void Class_Minstall(Classtable *cptr, char *name, table_type *type, p_node *Paramlist);
Memberfunclist *Class_Mlookup(Classtable *Ctype, char *Name);

// Debug helper
void PrintClassTable();

#endif