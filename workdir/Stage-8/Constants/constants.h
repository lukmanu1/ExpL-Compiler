#ifndef CONSTANTS_H
#define CONSTANTS_H

/* ==========================================================
   📘 constants.h
   Centralized header for all constant enums and macros
   Used throughout the compiler (AST, Symbol Table, etc.)
   ========================================================== */

/* ----------------------------------------------------------
   🌳 Node Types (for Abstract Syntax Tree)
   ---------------------------------------------------------- */
enum ast_node_type {
    NODE_TYPE_CONNECTOR = 0,
    NODE_TYPE_VALUE = 1,
    NODE_TYPE_STRING = 2,
    NODE_TYPE_ID = 3,
    NODE_TYPE_TUPLE = 4,
    NODE_TYPE_TUPLE_LIST = 5,
    NODE_TYPE_DEREF = 6,
    NODE_TYPE_REF = 7,
    NODE_TYPE_WRITE = 8,
    NODE_TYPE_READ = 9,
    NODE_TYPE_ASSIGN = 10,
    NODE_TYPE_PLUS = 11,
    NODE_TYPE_MINUS = 12,
    NODE_TYPE_MULT = 13,
    NODE_TYPE_DIV = 14,
    NODE_TYPE_MOD = 15,
    NODE_TYPE_LT = 16,
    NODE_TYPE_LE = 17,
    NODE_TYPE_GT = 18,
    NODE_TYPE_GE = 19,
    NODE_TYPE_EQ = 20,
    NODE_TYPE_NE = 21,
    NODE_TYPE_IF = 22,
    NODE_TYPE_IF_ELSE = 23,
    NODE_TYPE_WHILE = 24,
    NODE_TYPE_DO_WHILE = 25,
    NODE_TYPE_REPEAT_UNTIL = 26,
    NODE_TYPE_BREAK = 27,
    NODE_TYPE_CONTINUE = 28,
    NODE_TYPE_ARR_ASSIGN = 29,
    NODE_TYPE_ARR_READ = 30,
    NODE_TYPE_ARRAY = 31,
    NODE_TYPE_2D_ARRAY = 32,
    NODE_TYPE_FUNCT_DEFINITION = 33,
    NODE_TYPE_FUNCT_CALL = 34,
    NODE_TYPE_RETURN = 35,
    NODE_TYPE_ALLOC_FUNCT_CALL = 36,
    NODE_TYPE_FREE_FUNCT_CALL = 37,
    NODE_TYPE_INIT_FUNCT_CALL = 38,
    NODE_TYPE_NULL = 39,
    NODE_TYPE_CLASS_FUNCTION_CALL = 40,
    NODE_TYPE_SELF = 41,
    NODE_TYPE_NEW_FUNCT_CALL = 42,
    NODE_TYPE_DELETE = 43
};

/* ----------------------------------------------------------
   🔢 Data Types (for Symbol Table / Type Checking)
   ---------------------------------------------------------- */
   
enum data_type {
    DATA_TYPE_INTEGER,
    DATA_TYPE_BOOLEAN,
    DATA_TYPE_VOID,
    DATA_TYPE_STRING,
    DATA_TYPE_ARRAY,
    DATA_TYPE_INTEGER_PTR,
    DATA_TYPE_STRING_PTR
};

enum error{
   E_REG_FULL = -10
};

#endif /* CONSTANTS_H */