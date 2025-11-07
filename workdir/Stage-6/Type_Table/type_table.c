#include "type_table.h"
#include "../Symbol_Table/global_symbol_table.h"

table_type* table_head = NULL;
table_type* table_tail = NULL;
struct primitive_types* default_types = NULL;
void yyerror(const char *s);
typedef struct Paramstruct p_node;

table_type* create_type_table(char* name, int size) {
    table_type* new_entry = (table_type*) malloc(sizeof(table_type));

    new_entry->name = strdup(name);
    new_entry->size = size;
    new_entry->num_fields = 0;
    new_entry->fields = NULL;
    new_entry->next = NULL;

    if (table_head == NULL) {
        table_head = table_tail = new_entry;
    } else {
        table_tail->next = new_entry;
        table_tail = new_entry;
    }

    return new_entry;
}

field* create_field_node(char* name, table_type* type) {
    field* new_field = (field*) malloc(sizeof(field));
    new_field->name = strdup(name);
    new_field->type = type;
    new_field->field_index = 0;
    new_field->next = NULL;   
    return new_field;
}

field* append_field(field* head, field* new_field) {

    int field_count = 1;
    field* temp = head;

    
    while (temp->next) {
        if (strcmp(temp->name, new_field->name) == 0) {
            yyerror("Duplicate field name in type definition.");
        }
        temp = temp->next;
        field_count++;
    }

    if (strcmp(temp->name, new_field->name) == 0) {
        yyerror("Duplicate field name in type definition.");
    }

    temp->next = new_field;
    new_field->field_index = field_count;

    return head;
}

table_type* tLookup(char* name) {
    table_type* temp = table_head;
    while (temp) {
        if (strcmp(temp->name, name) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

table_type* type_table_install(char* name, field* fields) {
    if (tLookup(name) != NULL) {
        yyerror("Type already defined with the same name.");
    }

    table_type* new_type = create_type_table(name, 1);

    // Count fields and assign indexes
    int count = 0;
    field* temp = fields;
    while (temp) {
        count++;
        temp->field_index = count;
        temp = temp->next;
    }

    new_type->fields = fields;
    new_type->num_fields = count;
    new_type->size = count; // for now, assume each field = 1 unit size

    return new_type;
}

void validate_type(char* data_type, p_node* fields) {
    table_type* temp = tLookup(data_type);

    if (temp == NULL) {
        yyerror("Type undeclared.");
    }

    field* fields1 = temp->fields;   // type definition fields
    p_node* fields2 = fields;        // param list from grammar

    while (fields1 && fields2) {
        if (strcmp(fields1->name, fields2->name) != 0) {
            yyerror("Field name mismatch in tuple type.");
        }
        if (strcmp(fields1->type->name, fields2->type->name) != 0) {
            yyerror("Field type mismatch in tuple type.");
        }
        fields1 = fields1->next;
        fields2 = fields2->next;
    }

    if (fields1) {
        yyerror("Missing fields in tuple initialization.");
    }

    if (fields2) {
        yyerror("Extra fields in tuple initialization.");
    }
}

void initialize_type_table() {
    table_head = NULL;
    table_tail = NULL;

    table_type* int_type   = create_type_table("int", 1);
    table_type* str_type   = create_type_table("str", 1);
    table_type* bool_type  = create_type_table("bool", 1);
    table_type* void_type  = create_type_table("void", 0);
    table_type* arr_type   = create_type_table("arr", 1);
    table_type* ptr_type   = create_type_table("ptr", 1);
    table_type* func_type  = create_type_table("func", 0);
    table_type* unset_type = create_type_table("unset", 0);
    table_type* int_ptr_type   = create_type_table("int_ptr", 1);
    table_type* str_ptr_type   = create_type_table("str_ptr", 1);

    default_types = (struct primitive_types*) malloc(sizeof(struct primitive_types));

    default_types->int_type     = int_type;
    default_types->str_type     = str_type;
    default_types->bool_type    = bool_type;
    default_types->void_type    = void_type;
    default_types->arr_type     = arr_type;
    default_types->ptr_type     = ptr_type;
    default_types->unset_type   = unset_type;
    default_types->func_type    = func_type;
    default_types->int_ptr_type = int_ptr_type;
    default_types->str_ptr_type = str_ptr_type;
}