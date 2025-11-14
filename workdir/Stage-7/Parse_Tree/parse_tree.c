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

ast_node* create_function_definition_node(table_type* type, ast_node* id, p_node* param_list, ast_node* body, Classtable* current_class){

    if(current_class){
        Memberfunclist* function = Class_Mlookup(current_class, id->name);
        if(!function){
            printf("Function : %s ", id->name);
            yyerror("| Is undeclared.\n");
        }

        if(strcmp(type->name, function->Type->name) != 0){
            yyerror("Error: Method Data Type Mismatch.\n"); 
        }

        compare_param_list(function->Paramlist, param_list);

        id->type = function->Type;
        id->nodetype = NODE_TYPE_FUNCT_DEFINITION;
        id->ptr1 = body;

    }else{
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
    }

    return id;
}



ast_node* create_free_function_call_node(ast_node* arg){

    if(arg->type == NULL && arg->nodetype != NODE_TYPE_TUPLE && arg->nodetype != NODE_TYPE_TUPLE_LIST ){
        lst_node* lst_temp = lst_look_up(arg->name);
        gst_node* gst_temp = look_up(arg->name);

        if(lst_temp != NULL){
            arg->Lentry = lst_temp;
            arg->type = lst_temp->type;
        }else if(gst_temp != NULL){
            arg->Gentry = gst_temp;
            arg->type = gst_temp->type;
        }else{
            yyerror("variable is not declared neither in lst nor gst\n");
        }
    }

    if(arg->type->fields == NULL){
        yyerror("it is not user defined variable\n");
    }

    union Constant val;
    ast_node* free_funct = create_ast_node(NODE_TYPE_FREE_FUNCT_CALL, NULL, val);
    free_funct->arglist = arg;
    
    return free_funct;
}

ast_node* create_new_function_call_node(ast_node* left, ast_node* right){

    if (right == NULL || right->name == NULL) {
        yyerror("Internal: NEW needs a class name\n");
    }

    
    Classtable* cptr = CLookup(right->name);
    if (cptr == NULL) {
        printf("Class Name : %s\n", right->name);
        yyerror("Undefined class used in NEW statement.\n");
    }

    
    if (left->Ctype == NULL) {
        printf("Variable Name : %s\n", left->name ? left->name : "<temp>");
        yyerror("NEW can only be used with class variables.\n");
    }

    if (strcmp(left->Ctype->Name, cptr->Name) != 0) {
        yyerror("Type mismatch: class variable and class being allocated are different.\n");
    }

    union Constant val;

    ast_node* new_function_call = create_ast_node(NODE_TYPE_ALLOC_FUNCT_CALL, NULL, val);

    ast_node* assign_node = create_ast_node(NODE_TYPE_ASSIGN, NULL, val);
    assign_node->ptr1 = left;
    assign_node->ptr2 = new_function_call;
    assign_node->type = default_types->void_type;

    return assign_node;

}

ast_node* create_delete_node(ast_node* obj) {
    if (obj->Ctype == NULL) {
        printf("Variable : %s\n", obj->name ? obj->name : "<temp>");
        yyerror("DELETE expects a class object variable.\n");
    }

    union Constant val;
    ast_node* del_node = create_ast_node(NODE_TYPE_DELETE, NULL, val);
    del_node->Ctype = obj->Ctype;               
    del_node->ptr1  = obj;                      
    del_node->type  = default_types->void_type; 
    return del_node;
}

ast_node* create_alloc_function_call_node(ast_node* user_variable){

    if(user_variable->Ctype != NULL){
        yyerror("alloc is used to allocate space for user-defined types.\n");
    }

    if(user_variable->type == NULL && user_variable->nodetype != NODE_TYPE_TUPLE && user_variable->nodetype != NODE_TYPE_TUPLE_LIST ){
        lst_node* lst_temp = lst_look_up(user_variable->name);
        gst_node* gst_temp = look_up(user_variable->name);

        if(lst_temp != NULL){
            user_variable->Lentry = lst_temp;
            user_variable->type = lst_temp->type;
        }else if(gst_temp != NULL){
            user_variable->Gentry = gst_temp;
            user_variable->type = gst_temp->type;
        }else{
            yyerror("variable is not declared neither in lst nor gst\n");
        }
    }

    if (user_variable->type == NULL || user_variable->type->fields == NULL) {
        yyerror("ALLOC can only be used for user-defined (TypeDef) structures.\n");
    }
    
    union Constant val;

    ast_node* alloc_function = create_ast_node(NODE_TYPE_ALLOC_FUNCT_CALL, NULL, val);

    ast_node* assign_node = create_ast_node(NODE_TYPE_ASSIGN, NULL, val);
    assign_node->ptr1 = user_variable;
    assign_node->ptr2 = alloc_function;

    return assign_node;
}

ast_node* create_init_function_call_node(){
    union Constant val;

    ast_node* init_function = create_ast_node(NODE_TYPE_INIT_FUNCT_CALL, NULL, val);
    return init_function;   
}

Memberfunclist* compare_methods(Memberfunclist* method_list, char* method_name){
    Memberfunclist* temp = method_list;
    while(temp){
        if(strcmp(temp->Name, method_name) == 0){
            return temp;
        }

        temp = temp->Next;
    }

    return NULL;
}

ast_node* create_class_function_call_node(ast_node* class, ast_node* method, ast_node* arg_list){

    
    if(class->Ctype == NULL){
        printf("hey\n");
        printf("Object Name : %s", class->name);
        yyerror("Calling Methods for undefined Class.\n");
    }

    Memberfunclist* temp = compare_methods(class->Ctype->Vfuncptr, method->name);

    if(temp == NULL){
        printf("Function Name : %s ", method->name);
        yyerror("Undefined Method Call.\n");
    }

    compare_function_arguments(temp->Paramlist, arg_list);

    method->arglist = arg_list;

    union Constant val;
    ast_node* function_call_node = create_ast_node(NODE_TYPE_CLASS_FUNCTION_CALL, NULL, val);

    function_call_node->type = temp->Type;
    function_call_node->ptr1 = class;
    function_call_node->ptr2 = method;
    
    return function_call_node;

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

ast_node* create_self_node( Classtable* current_class) {
    if(current_class == NULL){
        yyerror("NOT a class to refer it as classs.\n");
    }
    lst_node* temp = lst_look_up("self");

    if(!temp){
        yyerror("Self is invalid refference.\n");
    }
    
    union Constant val;
    ast_node* node = create_ast_node(NODE_TYPE_SELF, "self", val);
    node->Ctype = current_class;   // the class this 'self' refers to
    node->type = NULL;    // or default_types->int_ptr_type, if you use generic pointers
    node->Lentry = temp;
    return node;
}

ast_node* create_id_node(ast_node* id){

    lst_node* local_temp = lst_look_up(id->name);
    gst_node* global_temp = NULL;

    if(local_temp != NULL){
        id->type = local_temp->type;
        id->Lentry = local_temp;
        id->Ctype = local_temp->Ctype;
    }else{

        printf("variable is not declared in the local symbol table.\n");
        gst_node* global_temp = look_up(id->name);
        if(global_temp == NULL){
            printf("%s\n", id->name);
            yyerror("ID is not neither declared in local symbol table nor declared in global table.\n");
        }

        id->type = global_temp->type;
        id->Gentry = global_temp;
        id->Ctype = global_temp->Ctype;

    }

    return id;

}

field* find_field(field* field_list, char* field_name){
    field* temp = field_list;

    while (temp)
    {
        if(strcmp(temp->name, field_name) == 0)return temp;
        temp = temp->next;
    }

    return NULL;
    
}

Fieldlist* find_class_field(Fieldlist* field_list, char* field_name){
    Fieldlist* temp = field_list;

    while (temp)
    {
        if(strcmp(temp->Name, field_name) == 0)return temp;
        temp = temp->Next;
    }

    return NULL;
}

ast_node* extend_tuple_node(ast_node* tuple_list, ast_node* field_node){

    if (tuple_list->type == NULL && tuple_list->Ctype == NULL) {
        yyerror("Tuple variable has no field definitions.\n");
    }

    field* field_type = NULL;
    Fieldlist* class_field = NULL;

    if(tuple_list->type){
        field_type = find_field(tuple_list->type->fields, field_node->name);
    }else{
        class_field = find_class_field(tuple_list->Ctype->Memberfield, field_node->name);
    }

    if (field_type == NULL && class_field == NULL) {
        yyerror("Undeclared field in tuple type.\n");
    }

    union Constant val;
    ast_node* tuple_node = create_ast_node(NODE_TYPE_TUPLE_LIST, NULL, val);

    tuple_node->ptr1 = tuple_list;
    tuple_node->ptr2 = field_node;
    // tuple_node->type = field_type->type == NULL ? class_field->Type : field_node->type ;
    tuple_node->Ctype = class_field != NULL ? class_field->Ctype : NULL;

    if(field_type){
        tuple_node->type = field_type->type;
    }else{
        tuple_node->type = class_field->Type;
    }

    return tuple_node;
}

ast_node* create_tuple_node(ast_node* tuple, ast_node* field_node) {

    lst_node* local_temp = lst_look_up(tuple->name);
    gst_node* global_temp = NULL;
    field* field_type = NULL;
    Fieldlist* class_field = NULL;

    printf("%s->%s\n", tuple->name, field_node->name);

    if (local_temp != NULL) {
        tuple->Lentry = local_temp;
        tuple->type = local_temp->type;
        tuple->Ctype = local_temp->Ctype;

        if(tuple->Lentry->type != NULL && tuple->Lentry->type->fields == NULL){
            yyerror("Tuple variable has no field definitions.\n");
        }

        if(tuple->Lentry->Ctype != NULL && tuple->Lentry->Ctype->Memberfield == NULL){
            yyerror("Class variable has no field definitions.\n");
        }

        if(tuple->Lentry->type) field_type = find_field(tuple->Lentry->type->fields, field_node->name);
        else class_field = find_class_field(tuple->Lentry->Ctype->Memberfield, field_node->name);

    } else {
        printf("Variable '%s' is not declared in the local symbol table.\n", tuple->name);

        global_temp = look_up(tuple->name);
        if (global_temp == NULL) {
            yyerror("Identifier not declared in either local or global symbol table.\n");
        }

        tuple->Gentry = global_temp;
        tuple->type = global_temp->type;
        tuple->Ctype = global_temp->Ctype;

        // if (tuple->Gentry->type == NULL || tuple->Gentry->type->fields == NULL) {
        //     yyerror("Tuple variable has no field definitions.\n");
        // }

        if(tuple->Gentry->type != NULL && tuple->Gentry->type->fields == NULL){
            yyerror("Tuple variable has no field definitions.\n");
        }

        if(tuple->Gentry->Ctype != NULL && tuple->Gentry->Ctype->Memberfield == NULL){
            yyerror("Class variable has no field definitions.\n");
        }

        if(tuple->Gentry->type) field_type = find_field(tuple->Gentry->type->fields, field_node->name);
        else class_field = find_class_field(tuple->Gentry->Ctype->Memberfield, field_node->name);
    }

    if (field_type == NULL && class_field == NULL) {
        yyerror("Undeclared field in tuple type.\n");
    }

    union Constant val;
    ast_node* tuple_node = create_ast_node(NODE_TYPE_TUPLE, NULL, val);

    tuple_node->ptr1 = tuple;
    tuple_node->ptr2 = field_node;
    // tuple_node->type = field_type->type == NULL ? class_field->Type : field_type->type;
    tuple_node->Ctype = class_field != NULL ? class_field->Ctype : NULL;

    if(field_type){
        tuple_node->type = field_type->type;
    }else{
        tuple_node->type = class_field->Type;
    }

    return tuple_node;
}

ast_node* create_tuple_array_node(ast_node* arr, ast_node* expr, ast_node* field_node){
    ast_node* arr_node = create_array_node(arr, expr);
    field* field_type = find_field(arr_node->type->fields, field_node->name);

    union Constant val;
    ast_node* tuple_node = create_ast_node(NODE_TYPE_TUPLE, NULL, val);
    tuple_node->ptr1 = arr_node;
    tuple_node->ptr2 = field_node;
    tuple_node->type = field_type->type;

    return tuple_node;
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
    if(right->nodetype == NODE_TYPE_NULL && left->type->fields == NULL){
        yyerror("trying to assign null value to primitive data-type\n");
    }else if(strcmp(left->type->name, right->type->name) != 0 && right->nodetype != NODE_TYPE_NULL){
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

    if((strcmp(left->type->name, "int") != 0 || strcmp(right->type->name, "int") != 0 ) && right->nodetype != NODE_TYPE_NULL){
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

