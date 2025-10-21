TulpeElementList  : TulpeElementList ',' TulpeElement
                  | TulpeElement

TulpeElement   : INT ID 
               | STR ID
               | TUPLE ID '(' TulpeElementList ')' ID      
               ;
            

Type        : INT                                       { type_variable = default_types->int_type; }
            | STR                                       { type_variable = default_types->str_type; }
            | TUPLE ID '(' TulpeElementList ')'         {   }
            ;