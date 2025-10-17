#include "local_symbol_table.h"
#include <stdlib.h>
#include <string.h>

lst_node* lst_head = NULL;
lst_node* lst_tail = NULL;
int lst_binding = 1;

lst_node* create_lst_node(char* name, table_type* type){

    lst_node* new_node = (lst_node*)malloc(sizeof(lst_node));

    new_node->name = strdup(name);
    new_node->type = type;
    new_node->binding = lst_binding;
    new_node->next = NULL;
    lst_binding++;

    return new_node;
}
void lst_install(char *name, table_type* type){


   lst_node* temp = lst_look_up(name);

    if (temp != NULL) {
        fprintf(stderr, "Error: local variable '%s' is already declared.\n", name);
        exit(1);   
    } 

    lst_node* new_node = create_lst_node(name, type);

    if(!lst_head){
        lst_head = lst_tail = new_node;
    }else{
        lst_tail->next = new_node;
        lst_tail = lst_tail->next;
    }

}

lst_node* lst_look_up(char* name){

    lst_node* temp = lst_head;

    while(temp){
        if(strcmp(temp->name, name) == 0)return temp;
        temp = temp->next;
    }

    return NULL;
}

int param_count(p_node* param_list){
    p_node* temp = param_list;
    while(temp){
        temp = temp->next;
        lst_binding--;
    }

    return lst_binding;
}


void add_param_list_to_lst(p_node* param_list){
    lst_binding = param_count(param_list);
    p_node* temp = param_list;
    while(temp){
        lst_install(temp->name, temp->type);
        temp = temp->next;
    }
    
}

void lst_display() {
    printf("\n-------------------- LOCAL SYMBOL TABLE --------------------\n");
    printf("%-20s %-15s %-10s\n", "Name", "Type", "Binding");
    printf("-------------------------------------------------------------\n");

    lst_node* temp = lst_head;
    if (!temp) {
        printf("No local variables declared.\n");
        return;
    }

    while (temp) {
        printf("%-20s %-15s %-10d\n", 
               temp->name, 
               temp->type ? temp->type->name : "N/A", 
               temp->binding);
        temp = temp->next;
    }

    printf("-------------------------------------------------------------\n");
}