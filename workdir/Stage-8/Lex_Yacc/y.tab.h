/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NEW = 258,
    DELETE = 259,
    PBEGIN = 260,
    END = 261,
    DECL = 262,
    ENDDECL = 263,
    TYPE = 264,
    ENDTYPE = 265,
    CLASS = 266,
    ENDCLASS = 267,
    EXTENDS = 268,
    READ = 269,
    WRITE = 270,
    FREE = 271,
    ALLOC = 272,
    INIT = 273,
    IF = 274,
    ELSE = 275,
    THEN = 276,
    ENDIF = 277,
    WHILE = 278,
    DO = 279,
    REPEAT = 280,
    UNTIL = 281,
    BREAK = 282,
    CONTINUE = 283,
    EQUAL = 284,
    LT = 285,
    GT = 286,
    LE = 287,
    GE = 288,
    NOT = 289,
    NE = 290,
    EQ = 291,
    AND = 292,
    INT = 293,
    STR = 294,
    MAIN = 295,
    RETURN = 296,
    NULL_NODE = 297,
    NUM = 298,
    ID = 299,
    STRING_LITERAL = 300,
    SELF = 301
  };
#endif
/* Tokens.  */
#define NEW 258
#define DELETE 259
#define PBEGIN 260
#define END 261
#define DECL 262
#define ENDDECL 263
#define TYPE 264
#define ENDTYPE 265
#define CLASS 266
#define ENDCLASS 267
#define EXTENDS 268
#define READ 269
#define WRITE 270
#define FREE 271
#define ALLOC 272
#define INIT 273
#define IF 274
#define ELSE 275
#define THEN 276
#define ENDIF 277
#define WHILE 278
#define DO 279
#define REPEAT 280
#define UNTIL 281
#define BREAK 282
#define CONTINUE 283
#define EQUAL 284
#define LT 285
#define GT 286
#define LE 287
#define GE 288
#define NOT 289
#define NE 290
#define EQ 291
#define AND 292
#define INT 293
#define STR 294
#define MAIN 295
#define RETURN 296
#define NULL_NODE 297
#define NUM 298
#define ID 299
#define STRING_LITERAL 300
#define SELF 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 32 "parser.y"

    ast_node* AST_node;
    gst_node* GST_node;
    lst_node* LST_node;
    p_node* param_node;
    field* field_node;
    Classtable* class_node;
    Fieldlist* cfield_node;
    Memberfunclist* member_node;

#line 160 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
