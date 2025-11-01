#ifndef LOCAL_SYMBOL_TABLE_H
#define LOCAL_SYMOBL_TABLE_H


#include<stdio.h>
#include "global_symbol_table.h"

typedef struct Lsymbol lst_node;

struct Lsymbol{
  char* name;
  table_type* type;
  int binding;
  lst_node* next;
};

lst_node* create_lst_node(char* name, table_type* type);
void lst_install(char *name, table_type* type);
lst_node* lst_look_up(char* name);
int param_count(p_node* param_list);
void add_param_list_to_lst(p_node* param_list);
void lst_display();

#endif