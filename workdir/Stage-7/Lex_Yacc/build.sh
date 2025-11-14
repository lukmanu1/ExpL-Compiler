yacc -d parser.y
flex lexical.l 
gcc lex.yy.c y.tab.c ./../Parse_Tree/parse_tree.c ./../Symbol_Table/global_symbol_table.c ./../Symbol_Table/local_symbol_table.c ./../Type_Table/type_table.c ./../Code_gen/code_generation.c ./../Classtable/class_table.c -o secondFinal
./secondFinal input1.txt output.txt
./label_transition output.txt output.xsm 