#include "parse_tree.h"
void yyerror(const char *s);
ast_node* arg_list_head = NULL;
ast_node* arg_list_tail = NULL;


ast_node* create_ast_node(int nodetype, char *name, union Constant value) {
    struct ASTNode *node = (struct ASTNode*)malloc(sizeof(struct ASTNode));
    if (!node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    node->nodetype = nodetype;
    node->name = name ? strdup(name) : NULL;  // duplicate string if not NULL
    node->value = value;                       // set the constant value

    node->type = NULL;
    node->arglist = NULL;

    node->ptr1 = node->ptr2 = node->ptr3 = NULL;
    
    node->Gentry = NULL;
    node->Lentry = NULL;

    return node;
}

void compare_param_list(p_node* list1, p_node* list2){
    while(list1 && list2){
        if(strcmp(list1->type->name, list2->type->name) != 0){
            yyerror("Error: function, parameter type mismatch.\n"); 
        }

        if(strcmp(list1->name, list2->name) != 0){
            yyerror("Error: function, parameter name mismatch.\n"); 
        }
        list1 = list1->next;
        list2 = list2->next;
    }

    if(list1){
        yyerror("Error: less parameter defined.\n");
    }
    if(list2){
        yyerror("Error: extra parameter defined.\n");
    }
}

ast_node* append_arg_list(ast_node* arg_list, ast_node* expr){
    ast_node* temp = arg_list;
    while(temp->arglist){
        temp = temp->arglist;
    }
    temp->arglist = expr;
    return arg_list;
}

void compare_function_arguments(p_node* list1, ast_node* list2){
    
    while(list1 && list2){

        if(strcmp(list1->type->name, list2->type->name) != 0){
            yyerror("Error: function call, argument type mismatch.\n"); 
        }
        list1 = list1->next;
        list2 = list2->arglist;
    }

    if(list1){
        // printf("%s ", list1->name);
        yyerror("Error: less argument passed.\n");
    }
    if(list2){
        // printf("%s ", list2->name);
        yyerror("Error: extra argument passed.\n");
    }
}

ast_node* create_function_definition_node(table_type* type, ast_node* id, p_node* param_list, ast_node* body){
    gst_node* temp = look_up(id->name);
    if(temp == NULL){
        yyerror("Error: function is not declared.\n");   
    }
    if(strcmp(type->name, temp->type->name) != 0){
        yyerror("Error: function Data Type Mismatch.\n"); 
    }

    compare_param_list(temp->param_list, param_list);

    id->type = temp->type;
    id->Gentry = temp;
    id->nodetype = NODE_TYPE_FUNCT_DEFINITION;

    id->ptr1 = body;

    return id;
}

ast_node* create_function_call_node(ast_node* function, ast_node* arg_list){

    gst_node* temp = look_up(function->name);
    if(temp == NULL){
        yyerror("Error: function is not declared.\n");
    }

    if(temp->flag_label == -1){
        yyerror("Error: invalied function call.\n");
    }

    compare_function_arguments(temp->param_list, arg_list);

    function->Gentry = temp;

    union Constant val;

    ast_node* function_call = create_ast_node(NODE_TYPE_FUNCT_CALL, NULL, val);

    // function_call->arglist = arg_list;
    function_call->type = temp->type;
    function_call->ptr1 = function;
    function->arglist = arg_list;
    
    return function_call;

}

ast_node* create_return_node(table_type* function_type, ast_node* expr, table_type* expr_type){

    if(strcmp(function_type->name, expr_type->name) != 0){
        yyerror("FUNCTION TYPE AND RETURN TYPE MISMATCH\n");
    }

    union Constant val;
    ast_node* return_node = create_ast_node(NODE_TYPE_RETURN, NULL, val);

    return_node->ptr1 = expr;
    return_node->type = function_type;
    return return_node;
}

ast_node* create_connector_node(ast_node* left, ast_node* right){

    union Constant val;
    ast_node* connector = create_ast_node(NODE_TYPE_CONNECTOR, NULL, val);

    connector->ptr1 = left;
    connector->ptr2 = right;
    connector->type = default_types->void_type;

    return connector;
}

ast_node* create_id_node(ast_node* id){

    lst_node* local_temp = lst_look_up(id->name);
    gst_node* global_temp = NULL;

    if(local_temp != NULL){
        id->type = local_temp->type;
        id->Lentry = local_temp;
    }else{

        printf("variable is not declared in the local symbol table.\n");
        gst_node* global_temp = look_up(id->name);
        if(global_temp == NULL){
            yyerror("ID is not neither declared in local symbol table nor declared in global table.\n");
        }

        id->type = global_temp->type;
        id->Gentry = global_temp;

    }

    return id;

}

ast_node* create_ref_node(ast_node* id){
    lst_node* local_temp = lst_look_up(id->name);
    gst_node* global_temp = NULL;

    if(local_temp != NULL){
        id->type = local_temp->type;
        id->Lentry = local_temp;
    }else{

        printf("variable is not declared in the local symbol table.\n");
        gst_node* global_temp = look_up(id->name);
        if(global_temp == NULL){
            yyerror("ID is not neither declared in local symbol table nor declared in global table.\n");
        }

        id->type = global_temp->type;
        id->Gentry = global_temp;

    }

    union Constant val;
    ast_node* ref_node = create_ast_node(NODE_TYPE_REF, NULL, val);
    ref_node->ptr1 = id;
    if(strcmp(id->type->name, "int") == 0){
        ref_node->type = default_types->int_ptr_type;
    }else{
        ref_node->type = default_types->str_ptr_type;
    }

    return ref_node;
}

ast_node* create_deref_node(ast_node* id){
    lst_node* local_temp = lst_look_up(id->name);
    gst_node* global_temp = NULL;

    if(local_temp != NULL){
        id->type = local_temp->type;
        id->Lentry = local_temp;
    }else{

        printf("variable is not declared in the local symbol table.\n");
        gst_node* global_temp = look_up(id->name);
        if(global_temp == NULL){
            yyerror("ID is not neither declared in local symbol table nor declared in global table.\n");
        }

        id->type = global_temp->type;
        id->Gentry = global_temp;

    }

    union Constant val;
    ast_node* deref_node = create_ast_node(NODE_TYPE_DEREF, NULL, val);
    deref_node->ptr1 = id;
    if(strcmp(id->type->name, "int_ptr") == 0){
        deref_node->type = default_types->int_type;
    }else{
        deref_node->type = default_types->str_type;
    }

    return deref_node;
}

ast_node* create_read_node(ast_node* id){

    union Constant value;
    ast_node* read_node = create_ast_node(NODE_TYPE_READ, NULL, value);
    read_node->ptr1 = id;
    read_node->type = default_types->void_type;
    return read_node;
}

ast_node* create_write_node(ast_node* expr){

    if(strcmp(expr->type->name, "bool") == 0){
        yyerror("create node accept either string or integer.\n");
    }

    union Constant value;
    ast_node* write_node = create_ast_node(NODE_TYPE_WRITE, NULL, value);
    write_node->ptr1 = expr;
    write_node->type = default_types->void_type;
    return write_node;

}

ast_node* create_assign_node(ast_node* left, ast_node* right){

    if(strcmp(left->type->name, right->type->name) != 0){
        yyerror("Type Mismatch in Assignment\n");
    }

    union Constant value;
    ast_node* assign_node = create_ast_node(NODE_TYPE_ASSIGN, NULL, value);

    assign_node->ptr1 = left;
    assign_node->ptr2 = right;
    assign_node->type = default_types->void_type;
    
    return assign_node;

}

ast_node* create_operator_node(int node_type, ast_node* left, ast_node* right){

    if(strcmp(left->type->name, "int") != 0 || strcmp(right->type->name, "int") != 0){
        yyerror("Type Mismatch in operator node\n");
    }

    union Constant value;
    ast_node* operator_node = create_ast_node(node_type, NULL, value);
    operator_node->ptr1 = left;
    operator_node->ptr2 = right;
    operator_node->type = default_types->int_type;
    return operator_node;
}

ast_node* create_boolean_node(int node_type, ast_node* left, ast_node* right){

    if(strcmp(left->type->name, "int") != 0 || strcmp(right->type->name, "int") != 0){
        yyerror("Type Mismatch in boolean node\n");
    }

    union Constant value;
    ast_node* boolean_node = create_ast_node(node_type, NULL, value);
    boolean_node->ptr1 = left;
    boolean_node->ptr2 = right;
    boolean_node->type = default_types->bool_type;

    return boolean_node;
}

ast_node* assign_type_num_node(ast_node* num){
    num->type = default_types->int_type;
    return num;
}

ast_node* assign_type_str_node(ast_node* str){
    str->type = default_types->str_type;
    return str;
}

void insert_argument(ast_node* argument){
    if(arg_list_head == NULL){
        arg_list_head = arg_list_tail = argument;
    }else{
        arg_list_tail->arglist = argument;
        arg_list_tail = arg_list_tail->arglist;
    }
}

ast_node* create_if_else_node(ast_node* condition, ast_node* thenBranch, ast_node* elseBranch){

    if(strcmp(condition->type->name, "bool") != 0){
        yyerror("Condition in IF-ELSE should be Boolean\n");
    }
    union Constant val;
    ast_node* if_else_node = create_ast_node(NODE_TYPE_IF_ELSE, NULL, val);

    if_else_node->ptr1 = condition;
    if_else_node->ptr2 = thenBranch;
    if_else_node->ptr3 = elseBranch;

    if_else_node->type = default_types->void_type;

    return if_else_node;
}

ast_node* create_if_node(ast_node* condition, ast_node* thenBranch){

    if(strcmp(condition->type->name, "bool") != 0){
        yyerror("Condition in IF_NODE should be Boolean\n");
    }
    union Constant val;
    ast_node* if_node = create_ast_node(NODE_TYPE_IF, NULL, val);

    if_node->ptr1 = condition;
    if_node->ptr2 = thenBranch;
    if_node->type = default_types->void_type;

    return if_node;
}

ast_node* create_while_node(ast_node* condition, ast_node* body){

    if(strcmp(condition->type->name, "bool") != 0){
        yyerror("Condition in WHILE should be Boolean\n");
    }

    union Constant val;

    ast_node* while_node = create_ast_node(NODE_TYPE_WHILE, NULL, val);

    while_node->ptr1 = condition;
    while_node->ptr2 = body;
    while_node->type = default_types->void_type;

    return while_node;
}

ast_node* create_do_while_node(ast_node* condition, ast_node* body){

    if(strcmp(condition->type->name, "bool") != 0){
        yyerror("Condition in DO_WHILE should be Boolean\n");
    }

    union Constant val;

    ast_node* do_while = create_ast_node(NODE_TYPE_DO_WHILE, NULL, val);

    do_while->ptr1 = condition;
    do_while->ptr2 = body;
    do_while->type = default_types->void_type;

    return do_while;
}

ast_node* create_repeat_until_node(ast_node* condition, ast_node* body){

    if(strcmp(condition->type->name, "bool") != 0){
        yyerror("Condition in REPEAT_UNTIL should be Boolean\n");
    }

    union Constant val;

    ast_node* repeat_until = create_ast_node(NODE_TYPE_WHILE, NULL, val);

    repeat_until->ptr1 = condition;
    repeat_until->ptr2 = body;
    repeat_until->type = default_types->void_type;

    return repeat_until;

}

ast_node* create_break_node(){
    union Constant val;
    ast_node* break_node = create_ast_node(NODE_TYPE_BREAK, NULL, val);
    break_node->type = default_types->void_type;
    return break_node;
}

ast_node* create_continue_node(){
    union Constant val;
    ast_node* continue_node = create_ast_node(NODE_TYPE_CONTINUE, NULL, val);
    continue_node->type = default_types->void_type;
    return continue_node;
}

ast_node* create_array_node(ast_node* array, ast_node* index){

    gst_node* temp = look_up(array->name);
    if(temp->inner_size == 0){
        yyerror("VARIABLE MISMATCH.\n");
    }

    array->type = temp->type;
    array->Gentry = temp;
    
    union Constant val;
    ast_node* expr_node = create_ast_node(NODE_TYPE_ARRAY, NULL, val);
    expr_node->type = temp->type;
    expr_node->ptr1 = array;
    expr_node->ptr2 = index;
    
    return expr_node;
}