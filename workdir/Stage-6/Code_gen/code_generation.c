#include "code_generation.h"

void yyerror(const char *s);
int loop_label = 0;
int if_label = 0;
int reg = -1;

extern lst_node *lst_head;

int get_reg()
{
    if (reg < 19)
    {
        reg++;
        return reg;
    }
    else
    {
        fprintf(stderr, "register is full.\n");
        return E_REG_FULL; // assume E_REG_FULL is defined
    }
}

void free_reg()
{
    if (reg > -1)
    {
        reg--;
    }
    else
    {
        fprintf(stderr, "There is no register to free.%d\n", reg);
        exit(1);
    }
}

void generateHeader(FILE *fptr)
{
    fprintf(fptr, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(fptr, "MOV SP, 4222\n");
    fprintf(fptr, "JMP MAIN\n");
}


void exit_system_call(FILE *fptr)
{
    int reg = get_reg();
    fprintf(fptr, "MOV R%d, \"exit\"\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "CALL 0\n");

    int returnReg = get_reg();
    fprintf(fptr, "POP R%d\n", returnReg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);

    free_reg();
    free_reg();
}

int system_call_function(FILE *fptr, char* system_call, int arg1, int arg2)
{

    int returnReg = get_reg();
    int reg = get_reg();

    fprintf(fptr, "MOV R%d, \"%s\"\n", reg, system_call);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "MOV R%d, %d\n", reg, arg1);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "MOV R%d, R%d\n", reg, arg2);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "CALL 0\n");

    fprintf(fptr, "POP R%d\n", returnReg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);

    free_reg();
    return returnReg;
}

int code_gen_system_calls(FILE* fptr, ast_node* node){
    int ret = -1;
    switch (node->nodetype)
    {
        case NODE_TYPE_READ:{
            /* code */
            int addr_reg = resolve_address(fptr, node->ptr1);
            free_reg();
            ret = system_call_function(fptr, "read", -1, addr_reg);
            break;
        }

        case NODE_TYPE_WRITE:{
            int val_reg = codeGen(fptr, node->ptr1);
            free_reg();
            ret = system_call_function(fptr, "write", -2, val_reg);
            break;
        }

        case NODE_TYPE_INIT_FUNCT_CALL:{
            ret = system_call_function(fptr, "init", 0, 0);
            break;
        }

        case NODE_TYPE_ALLOC_FUNCT_CALL:{
            ret = system_call_function(fptr, "alloc", 0, 0);
            break;
        }

        case NODE_TYPE_FREE_FUNCT_CALL:{
            int val_reg = codeGen(fptr, node->arglist);
            free_reg();
            ret = system_call_function(fptr, "alloc", val_reg, 0);
            break;
        }

        default:
            break;
    }

    return ret;
}

void code_gen_function_definition(FILE *fptr, ast_node *funct)
{

    gst_node *temp = look_up(funct->name);

    fprintf(fptr, "%s%d:\n", funct->name, temp->flag_label);
    fprintf(fptr, "PUSH BP\n");
    fprintf(fptr, "MOV BP, SP\n");

    lst_node *ltemp = lst_head;

    int count = 0;
    while (ltemp)
    {
        count += 1;
        ltemp = ltemp->next;
    }

    int i = 0;
    int lst_reg = get_reg();
    while (i < count)
    {
        fprintf(fptr, "PUSH R%d\n", lst_reg);
        i++;
    }

    free_reg();
}

int code_gen_main_function(FILE *fptr)
{

    fprintf(fptr, "MAIN:\n");
    fprintf(fptr, "PUSH BP\n");
    fprintf(fptr, "MOV BP, SP\n");

    lst_node *ltemp = lst_head;

    int count = 0;
    while (ltemp)
    {
        count += 1;
        ltemp = ltemp->next;
    }

    int i = 0;
    int lst_reg = get_reg();
    while (i < count)
    {
        fprintf(fptr, "PUSH R%d\n", lst_reg);
        i++;
    }

    free_reg();
}

int code_gen_return(FILE *fptr, ast_node *node)
{
    if (strcmp(node->type->name, default_types->void_type->name) == 0)
    {

        return -1;
    }
    else
    {

        int return_val = codeGen(fptr, node->ptr1);
        int return_addr_reg = get_reg();
        fprintf(fptr, "MOV R%d, BP\n", return_addr_reg);
        fprintf(fptr, "ADD R%d, -2\n", return_addr_reg);
        fprintf(fptr, "MOV [R%d], R%d\n", return_addr_reg, return_val);

        free_reg();
        free_reg();

        return -1;
    }
}

void code_gen_exit_function(FILE *fptr)
{
    fprintf(fptr, "MOV SP, BP\n");
    fprintf(fptr, "POP BP\n");
    fprintf(fptr, "RET\n");
}

void push_registers(FILE *fptr)
{

    int register_use = reg + 1;
    for (int i = 0; i < register_use; i++)
    {
        fprintf(fptr, "PUSH R%d\n", i);
    }

    reg = -1;
}

void push_arguments(FILE *fptr, ast_node *arguments)
{
    ast_node *temp = arguments;
    int val_reg = -1;
    while (temp)
    {
        val_reg = codeGen(fptr, temp);
        fprintf(fptr, "PUSH R%d\n", val_reg);
        free_reg();
        temp = temp->arglist;
    }
}

void pop_registers(FILE *fptr, int reg_count)
{

    for (int i = reg_count - 1; i >= 0; i--)
    {
        fprintf(fptr, "POP R%d\n", i);
    }
    // reg = reg_count;
}

int code_gen_function_call(FILE *fptr, ast_node *calle)
{
    // Save registers in use
    int current_reg_val = reg + 1;
    push_registers(fptr);

    // Push arguments
    // push_arguments(fptr, calle->arglist);
    push_arguments(fptr, calle->ptr1->arglist);

    // Reserve space for return value
    fprintf(fptr, "PUSH R0\n");

    // Call the function
    fprintf(fptr, "CALL %s%d\n", calle->ptr1->name, calle->ptr1->Gentry->flag_label);

    // Retrieve return value
    reg = current_reg_val - 1;
    int ret_reg = get_reg();
    fprintf(fptr, "POP R%d\n", ret_reg);

    // Pop arguments
    // ast_node* t = calle->arglist;
    ast_node *t = calle->ptr1->arglist;
    int argCount = 0;
    while (t)
    {
        argCount++;
        t = t->arglist;
    }

    int temp_reg = get_reg();

    for (int i = 0; i < argCount; i++)
    {
        fprintf(fptr, "POP R%d\n", temp_reg);
    }

    free_reg();

    // Restore registers
    // (Add pop_registers(fptr) if implemented)f
    pop_registers(fptr, current_reg_val);

    return ret_reg;
}

int code_gen_number(FILE *fptr, ast_node *node)
{
    int val_reg = get_reg();
    fprintf(fptr, "MOV R%d, %d\n", val_reg, node->value.iVal);
    return val_reg;
}

int code_gen_string(FILE *fptr, ast_node *node)
{
    int str_reg = get_reg();
    fprintf(fptr, "MOV R%d, \"%s\"\n", str_reg, node->value.sVal);
    return str_reg;
}

int code_gen_id(FILE *fptr, ast_node *node)
{
    if (node->Lentry)
    {
        int val_reg = get_reg();
        int addr_reg = get_reg();

        fprintf(fptr, "MOV R%d, %d\n", addr_reg, node->Lentry->binding);
        fprintf(fptr, "ADD R%d, BP\n", addr_reg);
        fprintf(fptr, "MOV R%d, [R%d]\n", val_reg, addr_reg);

        free_reg();
        return val_reg;
    }
    else
    {

        int val_reg = get_reg();
        fprintf(fptr, "MOV R%d, [%d]\n", val_reg, node->Gentry->binding);
        return val_reg;
    }
}

int code_gen_tuple(FILE *fptr, ast_node *node)
{
    
    int addr_reg = resolve_address(fptr, node);
    fprintf(fptr, "MOV R%d, [R%d]\n", addr_reg, addr_reg);
    return addr_reg;

}

int code_gen_tuple_list(FILE* fptr, ast_node* node){

    int addr_reg = resolve_address(fptr, node);
    fprintf(fptr, "MOV R%d, [R%d]\n", addr_reg, addr_reg);
    return addr_reg;
}

int code_gen_operator(FILE *fptr, ast_node *node, const char *op)
{
    int left_reg = codeGen(fptr, node->ptr1);
    int right_reg = codeGen(fptr, node->ptr2);

    fprintf(fptr, "%s R%d, R%d\n", op, left_reg, right_reg);
    free_reg();
    return left_reg;
}


int find_field_index(field *field_list, char *field_name)
{
    field *temp = field_list;

    while (temp)
    {
        if (strcmp(temp->name, field_name) == 0)
        {
            return temp->field_index - 1;
        }
        temp = temp->next;
    }

    yyerror("Field not found in tuple type.\n");
    return -1;
}

int resolve_address(FILE *fptr, ast_node *node)
{
    if (node->nodetype == NODE_TYPE_ID)
    {
        int addr_reg = get_reg();
        if (node->Lentry)
        {
            fprintf(fptr, "MOV R%d, %d\n", addr_reg, node->Lentry->binding);
            fprintf(fptr, "ADD R%d, BP\n", addr_reg);
        }
        else
        {
            fprintf(fptr, "MOV R%d, %d\n", addr_reg, node->Gentry->binding);
        }
        return addr_reg;
    }
    else if (node->nodetype == NODE_TYPE_ARRAY)
    {

        ast_node *id_node = node->ptr1;
        int addr_reg = resolve_address(fptr, id_node);
        int index_reg = codeGen(fptr, node->ptr2);
        fprintf(fptr, "ADD R%d, R%d\n", addr_reg, index_reg);

        free_reg();
        return addr_reg;
    }
    else if (node->nodetype == NODE_TYPE_DEREF)
    {
        ast_node *id_node = node->ptr1;
        int addr_deref_node = get_reg();
        int addr_reg = resolve_address(fptr, id_node);
        fprintf(fptr, "MOV R%d, [R%d]\n", addr_deref_node, addr_reg);
        free_reg();
        return addr_deref_node;
    }
    else if (node->nodetype == NODE_TYPE_TUPLE)
    {
        int addr_reg = get_reg();
        int field_offset = 0;

        if (node->ptr1->Lentry)
        {

            fprintf(fptr, "MOV R%d, %d\n", addr_reg, node->ptr1->Lentry->binding);
            fprintf(fptr, "ADD R%d, BP\n", addr_reg);
            fprintf(fptr, "MOV R%d, [R%d]\n", addr_reg, addr_reg);
            field_offset = find_field_index(node->ptr1->Lentry->type->fields, node->ptr2->name);
        }
        else
        {
            fprintf(fptr, "MOV R%d, %d\n", addr_reg, node->ptr1->Gentry->binding);
            fprintf(fptr, "MOV R%d, [R%d]\n", addr_reg, addr_reg);
            field_offset = find_field_index(node->ptr1->Gentry->type->fields, node->ptr2->name);
        }

        fprintf(fptr, "ADD R%d, %d\n", addr_reg, field_offset);
        return addr_reg;
    }
    else if (node->nodetype == NODE_TYPE_TUPLE_LIST)
    {

        int addr_reg = resolve_address(fptr, node->ptr1);
        int field_offset = find_field_index(node->ptr1->type->fields, node->ptr2->name);

        fprintf(fptr, "MOV R%d, [R%d]\n", addr_reg, addr_reg);
        fprintf(fptr, "ADD R%d, %d\n", addr_reg, field_offset);

        return addr_reg;
    }
    else
    {
        fprintf(stderr, "resolve_address: not an identifier :: %d\n", node->nodetype);
        yyerror("error addr_resolve\n");
        return -1;
    }
}


int code_gen_while(FILE *fptr, ast_node *node)
{

    int temp_label = loop_label;
    loop_label++;

    fprintf(fptr, "LOOP%d:\n", temp_label);
    int condition_reg = codeGen(fptr, node->ptr1);
    fprintf(fptr, "JZ R%d, LOOP_END%d\n", condition_reg, temp_label);
    codeGen(fptr, node->ptr2);
    fprintf(fptr, "JMP LOOP%d\n", temp_label);
    fprintf(fptr, "LOOP_END%d:\n", temp_label);

    free_reg();

    return -1;
}

int code_gen_do_while(FILE *fptr, ast_node *node)
{
    int temp_label = loop_label;
    loop_label++;

    fprintf(fptr, "LOOP%d:\n", temp_label);
    codeGen(fptr, node->ptr2);
    int condition_reg = codeGen(fptr, node->ptr1);
    fprintf(fptr, "JZ R%d, LOOP_END%d\n", condition_reg, temp_label);
    fprintf(fptr, "JMP LOOP%d\n", temp_label);
    fprintf(fptr, "LOOP_END%d:\n", temp_label);

    free_reg();

    return -1;
}

int code_gen_repeat_until(FILE *fptr, ast_node *node)
{

    int temp_label = loop_label;
    loop_label++;

    fprintf(fptr, "LOOP%d:\n", temp_label);
    codeGen(fptr, node->ptr2);
    int condition_reg = codeGen(fptr, node->ptr1);
    fprintf(fptr, "JNZ R%d, LOOP_END%d\n", condition_reg, temp_label);
    fprintf(fptr, "JMP LOOP%d\n", temp_label);
    fprintf(fptr, "LOOP_END%d:\n", temp_label);

    free_reg();

    return -1;
}

int code_gen_if(FILE *fptr, ast_node *node)
{
    int condition_reg = codeGen(fptr, node->ptr1);
    int label = if_label;
    if_label++;

    fprintf(fptr, "JZ R%d, S.next%d\n", condition_reg, label);

    codeGen(fptr, node->ptr2);

    fprintf(fptr, "S.next%d:\n", label);

    free_reg();

    return -1;
}

int code_gen_if_else(FILE *fptr, ast_node *node)
{

    int condition_reg = codeGen(fptr, node->ptr1);
    int label = if_label;
    if_label++;

    fprintf(fptr, "JZ R%d, B.false%d\n", condition_reg, label);
    codeGen(fptr, node->ptr2);
    fprintf(fptr, "JMP S.next%d\n", label);
    fprintf(fptr, "B.false%d:\n", label);
    codeGen(fptr, node->ptr3);
    fprintf(fptr, "S.next%d:\n", label);

    free_reg();

    return -1;
}

int code_gen_assign(FILE *fptr, ast_node *node)
{
    int val_reg = codeGen(fptr, node->ptr2);
    int addr_reg = resolve_address(fptr, node->ptr1);

    fprintf(fptr, "MOV [R%d], R%d\n", addr_reg, val_reg);

    free_reg();
    free_reg();

    return -1;
}

int code_gen_array(FILE *fptr, ast_node *node)
{
    int val_reg = get_reg();
    int addr_reg = resolve_address(fptr, node);
    fprintf(fptr, "MOV R%d, [R%d]\n", val_reg, addr_reg);
    return val_reg;
}

int code_gen_ref_node(FILE *fptr, ast_node *node)
{
    int add_reg = resolve_address(fptr, node->ptr1);
    return add_reg;
}

int code_gen_deref_node(FILE *fptr, ast_node *node)
{

    ast_node *id = node->ptr1;
    int val_reg = get_reg();
    int addr_reg = get_reg();
    if (id->Lentry != NULL)
    {
        int addr_val_reg = get_reg();
        fprintf(fptr, "MOV R%d, %d\n", addr_reg, id->Lentry->binding);
        fprintf(fptr, "ADD R%d, BP\n", addr_reg);
        fprintf(fptr, "MOV R%d, [R%d]\n", addr_val_reg, addr_reg);
        fprintf(fptr, "MOV R%d, [R%d]\n", val_reg, addr_val_reg);

        free_reg();
    }
    else
    {
        fprintf(fptr, "MOV R%d, [%d]\n", addr_reg, id->Gentry->binding);
        fprintf(fptr, "MOV R%d, [R%d]\n", val_reg, addr_reg);
    }

    free_reg();

    return val_reg;
}

int code_gen_tuple_copy(FILE *fptr, ast_node *node)
{
    int addr_reg_t2 = resolve_address(fptr, node->ptr1);
    int addr_reg_t1 = resolve_address(fptr, node->ptr2);

    int num_fields = node->ptr1->type->num_fields;

    int index_reg = get_reg();
    int size_reg = get_reg();
    int cmp_reg = get_reg();

    fprintf(fptr, "MOV R%d, 0\n", index_reg);
    fprintf(fptr, "MOV R%d, %d\n", size_reg, num_fields);

    int temp_label = loop_label++;

    fprintf(fptr, "LOOP%d:\n", temp_label);
    fprintf(fptr, "MOV R%d, R%d\n", cmp_reg, index_reg);
    fprintf(fptr, "LT R%d, R%d\n", cmp_reg, size_reg);
    fprintf(fptr, "JZ R%d, END_LOOP%d\n", cmp_reg, temp_label);

    int val_reg = get_reg();
    fprintf(fptr, "MOV R%d, [R%d]\n", val_reg, addr_reg_t1);
    fprintf(fptr, "MOV [R%d], R%d\n", addr_reg_t2, val_reg);
    free_reg(); // val_reg

    fprintf(fptr, "ADD R%d, 1\n", index_reg);
    fprintf(fptr, "ADD R%d, 1\n", addr_reg_t1);
    fprintf(fptr, "ADD R%d, 1\n", addr_reg_t2);

    fprintf(fptr, "JMP LOOP%d\n", temp_label);
    fprintf(fptr, "END_LOOP%d:\n", temp_label);

    free_reg(); // cmp_reg
    free_reg(); // size_reg
    free_reg(); // index_reg

    return -1;
}

int codeGen(FILE *fptr, ast_node *node)
{
    switch (node->nodetype)
    {
    case NODE_TYPE_VALUE:
        return code_gen_number(fptr, node);

    case NODE_TYPE_STRING:
        return code_gen_string(fptr, node);

    case NODE_TYPE_ID:
        return code_gen_id(fptr, node);

    case NODE_TYPE_TUPLE:
        return code_gen_tuple(fptr, node);
    
    case NODE_TYPE_TUPLE_LIST:
        return code_gen_tuple_list(fptr, node);

    case NODE_TYPE_REF:
        return code_gen_ref_node(fptr, node);

    case NODE_TYPE_DEREF:
        return code_gen_deref_node(fptr, node);

    case NODE_TYPE_ARRAY:
        return code_gen_array(fptr, node);

    case NODE_TYPE_FUNCT_CALL:
        return code_gen_function_call(fptr, node);

    case NODE_TYPE_PLUS:
        return code_gen_operator(fptr, node, "ADD");

    case NODE_TYPE_MINUS:
        return code_gen_operator(fptr, node, "SUB");

    case NODE_TYPE_MULT:
        return code_gen_operator(fptr, node, "MUL");

    case NODE_TYPE_DIV:
        return code_gen_operator(fptr, node, "DIV");

    case NODE_TYPE_MOD:
        return code_gen_operator(fptr, node, "MOD");

    case NODE_TYPE_LT:
        return code_gen_operator(fptr, node, "LT");

    case NODE_TYPE_LE:
        return code_gen_operator(fptr, node, "LE");

    case NODE_TYPE_GT:
        return code_gen_operator(fptr, node, "GT");

    case NODE_TYPE_GE:
        return code_gen_operator(fptr, node, "GE");

    case NODE_TYPE_EQ:
        return code_gen_operator(fptr, node, "EQ");

    case NODE_TYPE_NE:
        return code_gen_operator(fptr, node, "NE");

    case NODE_TYPE_WRITE:
        code_gen_system_calls(fptr, node);
        free_reg(); 
        return -1;
    case NODE_TYPE_READ:
        code_gen_system_calls(fptr, node);
        free_reg(); 
        return -1;

    case NODE_TYPE_WHILE:
        return code_gen_while(fptr, node);

    case NODE_TYPE_DO_WHILE:
        return code_gen_do_while(fptr, node);

    case NODE_TYPE_REPEAT_UNTIL:
        return code_gen_repeat_until(fptr, node);

    case NODE_TYPE_IF:
        return code_gen_if(fptr, node);

    case NODE_TYPE_IF_ELSE:
        return code_gen_if_else(fptr, node);

    case NODE_TYPE_ASSIGN:
            return code_gen_assign(fptr, node);

    case NODE_TYPE_CONNECTOR:
        codeGen(fptr, node->ptr1);
        codeGen(fptr, node->ptr2);
        return -1;

    case NODE_TYPE_RETURN:
        code_gen_return(fptr, node);
        return -1;

    case NODE_TYPE_INIT_FUNCT_CALL:
        code_gen_system_calls(fptr, node);
        free_reg(); // return valued is not used anywhere what is why this free, function return register holding the return value.
        return -1;

    case NODE_TYPE_FREE_FUNCT_CALL:{}
        code_gen_system_calls(fptr, node);            
        free_reg(); 
        return -1; // HERE I AM AVOIDING free_reg function, i should add here one free_reg function, code_gen_free_funciton_call function is returning a Reg holding 1000, which is not going to be used any-where in the code according to my grammar.

    case NODE_TYPE_ALLOC_FUNCT_CALL:
        return code_gen_system_calls(fptr, node);
    
    case NODE_TYPE_NULL:{
        int reg = get_reg();
        fprintf(fptr, "MOV R%d, -1000000\n", reg);
        return reg;
    }

    default:
        fprintf(stderr, "Unhandled node type: %d\n", node->nodetype);
        return -1;
    }

}