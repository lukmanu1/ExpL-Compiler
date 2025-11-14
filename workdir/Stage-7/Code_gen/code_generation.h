#ifndef CODE_GENERATION_H
#define CODE_GENERATION_H

#include <stdio.h>
#include <stdlib.h>
#include "./../Parse_Tree/parse_tree.h"

// ---------- Register Management ----------
int get_reg();
void free_reg();

// ---------- Code Generation Setup ----------
void generateHeader(FILE *fptr);

// ---------- System Calls ----------
void exit_system_call(FILE *fptr);
void write_system_call(FILE *fptr, int dataReg);
void read_system_call(FILE *fptr, int addrReg);

// ---------- Function Handling ----------
int code_gen_main_function(FILE* fptr);
void code_gen_function_definition(FILE *fptr, ast_node *funct, Classtable* current_class);
int code_gen_return(FILE* fptr, ast_node* node);
void code_gen_exit_function(FILE *fptr);
int code_gen_function_call(FILE *fptr, ast_node *calle);
void push_registers(FILE *fptr);
void push_arguments(FILE *fptr, ast_node *arguments);
void pop_registers(FILE *fptr, int reg_count);

// ---------- Expression Generators ----------
int code_gen_number(FILE *fptr, ast_node *node);
int code_gen_string(FILE *fptr, ast_node *node);
int code_gen_id(FILE *fptr, ast_node *node);
int code_gen_ref_node(FILE* fptr, ast_node* node);
int code_gen_deref_node(FILE* fptr, ast_node* node);
int code_gen_operator(FILE *fptr, ast_node *node, const char *op);

// ---------- I/O ----------
int code_gen_write(FILE *fptr, ast_node *node);
int code_gen_read(FILE *fptr, ast_node *node);

// ---------- Assignment & Address ----------
int resolve_address(FILE *fptr, ast_node *node);
int code_gen_assign(FILE *fptr, ast_node *node);

// ---------- Conditional & Loop Constructs ----------
int code_gen_if(FILE *fptr, ast_node *node);
int code_gen_if_else(FILE *fptr, ast_node *node);
int code_gen_while(FILE *fptr, ast_node *node);
int code_gen_do_while(FILE *fptr, ast_node *node);
int code_gen_repeat_until(FILE *fptr, ast_node *node);

int code_gen_array(FILE* fptr, ast_node* node);

// ---------- Master Dispatcher ----------
int codeGen(FILE *fptr, ast_node *node);

int find_field_index(field* field_list, char* field_name);
int code_gen_tuple(FILE* fptr, ast_node* node);
int code_gen_tuple_copy(FILE* fptr, ast_node* node);
int code_gen_tuple_list(FILE* fptr, ast_node* node);

int code_gen_free_function(FILE* fptr, ast_node* node);
int code_gen_system_calls(FILE* fptr, ast_node* node);
int system_call_function(FILE *fptr, char* system_call, int arg1, int arg2);

Memberfunclist* find_class_function_index(Memberfunclist* method_list, char* method_name);
int find_class_field_index(Fieldlist* field_list, char *field_name);

#endif // CODE_GENERATION_H