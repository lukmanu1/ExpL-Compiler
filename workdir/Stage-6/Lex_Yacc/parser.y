%{
    #include "./../Code_gen/code_generation.h"
    FILE* outputFile; 
    FILE* inputFile;   

    void yyerror(const char* error);
    int yylex(void);

    table_type* type_variable = NULL;
    table_type* type_function = NULL;
    table_type* type_param = NULL;


    // void makeExecutableFile(struct tnode* node, FILE* fptr);
    extern FILE* yyin;
    extern p_node* param_head;
    extern p_node* param_tail;
    extern lst_node* lst_head;  
    extern lst_node* lst_tail;
    extern ast_node* arg_list_head;
    extern ast_node* arg_list_tail;
    extern int lst_binding;
    
%}

%union{
    ast_node* AST_node;
    gst_node* GST_node;
    lst_node* LST_node;
    p_node* param_node;
    field* field_node;
}

%token PBEGIN END
%token READ WRITE FREE ALLOC INIT
%token IF ELSE THEN ENDIF 
%token WHILE DO REPEAT UNTIL BREAK CONTINUE
%token EQUAL LT GT LE GE NOT NE EQ AND
%token DECL ENDDECL
%token INT STR
%token MAIN
%token RETURN NULL_NODE
%token TYPE ENDTYPE

%type <param_node> ParamList Param
%token <AST_node> NUM ID STRING_LITERAL
%type <LST_node> LDecList LdeclBlock

%type <AST_node> Slist Stmt InputStmt OutputStmt AsgStmt E Body FDefBlock Fdef ArgList
%type <AST_node> IfStmt whileStmt doWhileStmt repeatStmt breakStmt continueStmt returnStmt
%type <AST_node> Field
%type <field_node> FieldDecl FieldDeclList

%right EQUAL
%left LT GT LE GE EQ NE
%left '+' '-' 
%left '*' '/' '%'

%%

Program      :  TypeDefBlock GDeclBlock FDefBlock MainBlock          { }
             |  TypeDefBlock GDeclBlock MainBlock                    { }
             |  TypeDefBlock MainBlock                               { }
             |  MainBlock
             ;



TypeDefBlock  : TYPE TypeDefList ENDTYPE                {   }                                               
              ;

TypeDefList   : TypeDefList TypeDef                     {   }
              | TypeDef                                 {   }
              ;

TypeDef       : ID                                      { type_table_install($1->name, NULL); }
              '{' FieldDeclList '}'                     { table_type* new_type = tLookup($1->name); new_type->fields = $4; }
              ;

FieldDeclList : FieldDeclList FieldDecl                 { $$ = append_field($1, $2); }
              | FieldDecl                               { $$ = $1; }
              ;

FieldDecl    : Type ID ';'                              { $$ = create_field_node($2->name, type_variable); }


GDeclBlock  : DECL GDeclList ENDDECL                    {  print_gstable(); }
            | DECL ENDDECL
            ;

GDeclList   : GDeclList GDecl 
            | GDecl 
            ;

GDecl       : Type GidList ';'
            ;
    
GidList     : GidList ',' Gid 
            | Gid
            ;

Gid         : ID                                        { gst_install($1->name, type_variable, 1, 0, NULL); }
            | ID '[' NUM ']'                            { gst_install($1->name, type_variable, 1, $3->value.iVal, NULL); }
            | ID '(' ParamList ')'                      { gst_install($1->name, type_variable, 0, 0, $3); }
            | '*' ID                                    
                                                        { 
                                                            if(strcmp(type_variable->name, default_types->int_type->name) == 0){
                                                                gst_install($2->name, default_types->int_ptr_type, 1, 0, NULL);
                                                            }else{
                                                                gst_install($2->name, default_types->str_ptr_type, 1, 0, NULL);
                                                            }
                                                        }
            ;


FDefBlock   : FDefBlock Fdef                            { create_connector_node($1, $2); }
            | Fdef                                      { $$ = $1; }
            ;

Fdef :
    INT ID '(' ParamList ')' '{' LdeclBlock             { type_function = default_types->int_type; lst_binding = -2; code_gen_function_definition(outputFile, $2); add_param_list_to_lst($4); lst_binding = 1; lst_display(); }
    Body '}'                                            { $$ = create_function_definition_node(default_types->int_type, $2, $4, $9); lst_head = lst_tail = NULL; codeGen(outputFile, $9); code_gen_exit_function(outputFile); }

  | STR ID '(' ParamList ')' '{' LdeclBlock             { type_function = default_types->str_type; lst_binding = -2; code_gen_function_definition(outputFile, $2); add_param_list_to_lst($4); lst_binding = 1; lst_display(); }
    Body '}'                                            { $$ = create_function_definition_node(default_types->str_type, $2, $4, $9); lst_head = lst_tail = NULL; codeGen(outputFile, $9); code_gen_exit_function(outputFile); }

  | ID ID '(' ParamList ')'  '{' LdeclBlock              { type_function = tLookup($1->name); lst_binding = -2; code_gen_function_definition(outputFile, $2); add_param_list_to_lst($4); lst_binding = 1; lst_display(); }
   Body '}'                                              { $$ = create_function_definition_node(type_function, $2, $4, $9); lst_head = lst_tail = NULL; codeGen(outputFile, $9); code_gen_exit_function(outputFile); }
;


ParamList   : ParamList ',' Param                       { $$ = append_param($1, $3); }
            | Param                                     { $$ = $1; }
            |                                           { $$ = NULL; }
            ;

Param       : INT '*' ID                               { $$ = create_p_node($3->name, default_types->int_ptr_type); }
            | STR '*' ID                               { $$ = create_p_node($3->name, default_types->str_ptr_type); }
            | INT ID                                   { $$ = create_p_node($2->name, default_types->int_type); }
            | STR ID                                   { $$ = create_p_node($2->name, default_types->str_type); }
            | ID ID                                    { type_param = tLookup($1->name); $$ = create_p_node($2->name, type_param); }
            ;

LdeclBlock  : DECL LDecList ENDDECL                     { $$ = lst_head; }
            | DECL ENDDECL                              { }
            ;

LDecList    : LDecList LDecl                            {  }
            | LDecl                                     {  }
            ;

LDecl       : Type IdList ';'
            ;

IdList
    : IdList ',' '*' ID
                                                        {
                                                            if(strcmp(type_variable->name, default_types->int_type->name) == 0)
                                                                lst_install($4->name, default_types->int_ptr_type);
                                                            else
                                                                lst_install($4->name, default_types->str_ptr_type);
                                                        }
    | IdList ',' ID
                                                        { lst_install($3->name, type_variable); }
    | '*' ID
                                                        {
                                                            if(strcmp(type_variable->name, default_types->int_type->name) == 0)
                                                                lst_install($2->name, default_types->int_ptr_type);
                                                            else
                                                                lst_install($2->name, default_types->str_ptr_type);
                                                        }
    | ID
                                                        { lst_install($1->name, type_variable); }
    ;
            

Type        : INT                                       { type_variable = default_types->int_type; }
            | STR                                       { type_variable = default_types->str_type; }
            | ID                                        {
                                                            type_variable = tLookup($1->name);
                                                            
                                                            if (type_variable == NULL) {
                                                                printf("%s\n", $1->name);
                                                                yyerror("Unknown type used in declaration.");
                                                            }
                                                        }
            ;



MainBlock   : INT MAIN '(' ')' '{' LdeclBlock           { type_function = default_types->int_type; lst_display(); }
              Body '}'                                  { code_gen_main_function(outputFile); codeGen(outputFile, $8); lst_head = lst_tail = NULL; }


Body
    : PBEGIN Slist END ';'
        {
            // inorder($2);
            // makeExecutableFile( $2, outputFile);
            // // evaluate($2);
            $$ = $2;
        }
    | PBEGIN END ';'                                    { exit(0); }
    ;

Slist
    : Slist Stmt                                        { $$ = create_connector_node($1, $2); }
    | Stmt                                              { $$ = $1; }
    ;


Stmt
    : InputStmt                                         { $$ = $1; }
    | OutputStmt                                        { $$ = $1; }
    | AsgStmt                                           { $$ = $1; }
    | IfStmt                                            { $$ = $1; }
    | whileStmt                                         { $$ = $1; }
    | doWhileStmt                                       { $$ = $1; }
    | repeatStmt                                        { $$ = $1; }
    | breakStmt                                         { $$ = $1; } 
    | continueStmt                                      { $$ = $1; }
    | returnStmt                                        { $$ = $1; }
    | ID EQUAL ALLOC'(' ')' ';'                         { $$ = create_alloc_function_call_node($1); }
    | Field EQUAL ALLOC'(' ')' ';'                      { $$ = create_alloc_function_call_node($1); }
    | FREE '(' ID ')' ';'                               { $$ = create_free_function_call_node($3); } 
    | FREE '(' Field ')' ';'                            { $$ = create_free_function_call_node($3); } 
    | INIT '(' ')' ';'                                  { $$ = create_init_function_call_node(); }
    ;

InputStmt
    : READ '(' ID ')' ';'
        {
            $3 = create_id_node($3);
            $$ = create_read_node($3);
        }
    | READ '(' ID '[' E ']' ')' ';'
        {
            ast_node* array_node = create_array_node($3, $5);
            $$ = create_read_node(array_node);
        }
    | READ '(' Field ')' ';'
        {
            $$ = create_read_node($3);
        }
    ;

OutputStmt
    : WRITE '(' E ')' ';'
        {
            $$ = create_write_node($3);
        }
    ;

AsgStmt
    : ID EQUAL E ';'
        {
            $1 = create_id_node($1);
            $$ = create_assign_node($1, $3);
        }
    
    | ID '[' E ']' EQUAL E ';'
        {
            ast_node* array_node = create_array_node($1, $3);
            $$ = create_assign_node(array_node, $6);
        }
    | '*' ID EQUAL E ';'
        {
            ast_node* deref_node = create_deref_node($2);
            $$ = create_assign_node(deref_node, $4);
        }
    | Field EQUAL E ';'
        {
            $$ = create_assign_node($1, $3);
        }
    /* | Field EQUAL NULL_NODE ';'
        {
            union Constant value;
            ast_node* null_node = create_ast_node(NODE_TYPE_NULL, NULL, value);
            null_node->type = $1->type;
            $$ = create_assign_node($1, null_node);
        } */
    /* | ID EQUAL NULL_NODE ';'
        {
            ast_node* id_node = create_id_node($1);
            if(id_node->type->fields == NULL){
                yyerror("Assigning NULL to primitive data_type\n");
            }

            union Constant value;
            ast_node* null_node = create_ast_node(NODE_TYPE_NULL, NULL, value);
            null_node->type = id_node->type;
            $$ = create_assign_node(id_node, null_node);

        } */
    ;

IfStmt
    : IF '(' E ')' THEN Slist ELSE Slist ENDIF ';'      { $$ = create_if_else_node($3, $6, $8); }
    | IF '(' E ')' THEN Slist ENDIF ';'                 { $$ = create_if_node($3, $6); }
    ;


whileStmt 
    : WHILE '(' E ')' '{' Slist '}'                     { $$ = create_while_node($3, $6); }
    ;

doWhileStmt
    : DO '{' Slist '}' WHILE '(' E ')' ';'              { $$ = create_do_while_node($7, $3); }
    ;

repeatStmt
    : REPEAT '{' Slist '}' UNTIL '(' E ')' ';'          { $$ = create_repeat_until_node($7, $3); }
    ;

breakStmt
    : BREAK ';'                                         { $$ = create_break_node(); }
    ;

continueStmt
    : CONTINUE ';'                                      { $$ = create_continue_node(); }
    ;

returnStmt : RETURN E ';'                                { $$ = create_return_node(type_function, $2, $2->type); }
           | RETURN ';'                                  { $$ = create_return_node(type_function, NULL, default_types->void_type);}
           ;

E   : E '+' E                                           { $$ = create_operator_node(NODE_TYPE_PLUS, $1, $3); }

    | E '-' E                                           { $$ = create_operator_node(NODE_TYPE_MINUS, $1, $3); }

    | E '*' E                                           { $$ = create_operator_node(NODE_TYPE_MULT, $1, $3); }

    | E '/' E                                           { $$ = create_operator_node(NODE_TYPE_DIV, $1, $3); }

    | E '%' E                                           { $$ = create_operator_node(NODE_TYPE_MOD, $1, $3); }

    | E LT E                                            { $$ = create_boolean_node(NODE_TYPE_LT, $1, $3); }
    
    | E GT E                                            { $$ = create_boolean_node(NODE_TYPE_GT, $1, $3); }

    | E LE E                                            { $$ = create_boolean_node(NODE_TYPE_LE, $1, $3); }
    
    | E GE E                                            { $$ = create_boolean_node(NODE_TYPE_GE, $1, $3); }

    | E EQ E                                            { $$ = create_boolean_node(NODE_TYPE_EQ, $1, $3); }
    
    | E NE E                                            { $$ = create_boolean_node(NODE_TYPE_NE, $1, $3); }

    | ID '(' ')'                                        { $$ = create_function_call_node($1, NULL); }

    | ID '(' ArgList ')'                                { $$ = create_function_call_node($1, $3); arg_list_head = NULL; arg_list_tail = NULL; } 

    | NUM                                               { $$ = assign_type_num_node($1); }

    | STRING_LITERAL                                    { $$ = assign_type_str_node($1); }

    | ID                                                { $1 = create_id_node($1); $$ = $1; }

    | '(' E ')'                                         { $$ = $2; }     

    | ID '[' E ']'                                      { $$ = create_array_node($1, $3); }   

    | AND ID                                            { $$ = create_ref_node($2); }   

    | '*' ID                                            { $$ = create_deref_node($2); }

    | Field                                             { $$ = $1; }

    | NULL_NODE                                         { union Constant value; $$ = create_ast_node(NODE_TYPE_NULL, NULL, value); $$->type = default_types->int_type; }

    ;

Field : Field '.' ID                                    { $$ = extend_tuple_node($1, $3); }
      | ID '.' ID                                       { $$ = create_tuple_node($1, $3); }
      ; 

ArgList : ArgList ',' E                                 { $$ = append_arg_list($$, $3); }
        | E                                             { $$ = $1; }
        ;

%%

void yyerror(const char* error) {
    fprintf(stderr, "Error: %s\n", error);
    exit(0);
}

int main(int argc, char** argv) {
    
    initialize_type_table();
    
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input> <output>\n", argv[0]);
        return 1;
    }
    inputFile = fopen(argv[1], "r");
    outputFile = fopen(argv[2], "w");
    if (!inputFile || !outputFile) {
        perror("File opening failed");
        return 1;
    }

    generateHeader(outputFile);
    
    yyin = inputFile;
    yyparse();
    exit_system_call(outputFile);
    fclose(inputFile);
    fclose(outputFile);
    return 0;

}