#ifndef PARSE_TREE_H
#define PARSE_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../Symbol_Table/global_symbol_table.h"
#include "./../Symbol_Table/local_symbol_table.h"
#include "./../Type_Table/type_table.h"
#include "./../Constants/constants.h"
#include "./../ClassTable/class_table.h"

typedef struct ASTNode ast_node;

union Constant{
    int iVal;
    char* sVal;
};

struct ASTNode{
  table_type* type;                 //pointer to the type table entry
  Classtable* Ctype;
  int nodetype;                     //node type information,eg : NODETYPE_WHILE,NODETYPE_PLUS,NODETYPE_STMT etc 
  char *name;                       //stores the variable/function name in case of variable/function nodes
  union Constant value;             //stores the value of the constant if the node corresponds to a constant
  struct ASTNode *arglist;          //pointer to the expression list given as arguments to a function call
  struct ASTNode *ptr1,*ptr2,*ptr3; //Subtrees of the node. (Maximum Subtrees for IF THEN ELSE)
  struct Gsymbol *Gentry;           //pointer to GST entry for global variables and functions
  struct Lsymbol *Lentry;           //pointer to the function's LST for local variables and arguements
};

void insert_argument(ast_node* argument);

struct ASTNode* create_ast_node(int nodetype, char *name, union Constant value);
void compare_param_list(p_node* list1, p_node* list2);
ast_node* create_free_function_call_node(ast_node* arg);
ast_node* create_alloc_function_call_node(ast_node* arg);
ast_node* create_init_function_call_node();
ast_node* create_function_definition_node(table_type* type, ast_node* id, p_node* param_list, ast_node* body, Classtable* current_class);
ast_node* create_function_call_node(ast_node* function, ast_node* arg_list);
ast_node* create_connector_node(ast_node* left, ast_node* right);
ast_node* create_return_node(table_type* function_type, ast_node* expr, table_type* expr_type);

ast_node* create_id_node(ast_node* id);
field* find_field(field* field_list, char* field_name);
ast_node* create_tuple_node(ast_node* tuple, ast_node* field_node);
ast_node* extend_tuple_node(ast_node* tuple_list, ast_node* field_node);
ast_node* create_tuple_array_node(ast_node* arr, ast_node* expr, ast_node* field_node);
ast_node* create_ref_node(ast_node* id);
ast_node* create_deref_node(ast_node* id);
ast_node* create_operator_node(int node_type, ast_node* left, ast_node* right);
ast_node* create_boolean_node(int node_type, ast_node* left, ast_node* right);

ast_node* assign_type_num_node(ast_node* num);
ast_node* assign_type_str_node(ast_node* str);

ast_node* create_read_node(ast_node* id);
ast_node* create_write_node(ast_node* expr);
ast_node* create_assign_node(ast_node* left, ast_node* right);

ast_node* create_if_else_node(ast_node* condition, ast_node* thenBranch, ast_node* elseBranch);
ast_node* create_if_node(ast_node* condition, ast_node* thenBranch);
ast_node* create_while_node(ast_node* condition, ast_node* body);
ast_node* create_do_while_node(ast_node* condition, ast_node* body);
ast_node* create_repeat_until_node(ast_node* condition, ast_node* body);

ast_node* create_break_node();
ast_node* create_continue_node();

ast_node* append_arg_list(ast_node* arg_list, ast_node* expr);
ast_node* create_array_node(ast_node* array, ast_node* index);


ast_node* create_class_function_call_node(ast_node* class, ast_node* method, ast_node* arg_list);
ast_node* create_delete_node(ast_node* obj);
ast_node* create_new_function_call_node(ast_node* left, ast_node* right);
int isSubclass(Classtable *child, Classtable *parent);

ast_node* create_self_node( Classtable* current_class);

#endif