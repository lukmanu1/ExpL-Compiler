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
    PBEGIN = 258,
    END = 259,
    READ = 260,
    WRITE = 261,
    FREE = 262,
    ALLOC = 263,
    INIT = 264,
    IF = 265,
    ELSE = 266,
    THEN = 267,
    ENDIF = 268,
    WHILE = 269,
    DO = 270,
    REPEAT = 271,
    UNTIL = 272,
    BREAK = 273,
    CONTINUE = 274,
    EQUAL = 275,
    LT = 276,
    GT = 277,
    LE = 278,
    GE = 279,
    NOT = 280,
    NE = 281,
    EQ = 282,
    AND = 283,
    DECL = 284,
    ENDDECL = 285,
    INT = 286,
    STR = 287,
    MAIN = 288,
    RETURN = 289,
    NULL_NODE = 290,
    TYPE = 291,
    ENDTYPE = 292,
    NUM = 293,
    ID = 294,
    STRING_LITERAL = 295
  };
#endif
/* Tokens.  */
#define PBEGIN 258
#define END 259
#define READ 260
#define WRITE 261
#define FREE 262
#define ALLOC 263
#define INIT 264
#define IF 265
#define ELSE 266
#define THEN 267
#define ENDIF 268
#define WHILE 269
#define DO 270
#define REPEAT 271
#define UNTIL 272
#define BREAK 273
#define CONTINUE 274
#define EQUAL 275
#define LT 276
#define GT 277
#define LE 278
#define GE 279
#define NOT 280
#define NE 281
#define EQ 282
#define AND 283
#define DECL 284
#define ENDDECL 285
#define INT 286
#define STR 287
#define MAIN 288
#define RETURN 289
#define NULL_NODE 290
#define TYPE 291
#define ENDTYPE 292
#define NUM 293
#define ID 294
#define STRING_LITERAL 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "parser.y"

    ast_node* AST_node;
    gst_node* GST_node;
    lst_node* LST_node;
    p_node* param_node;
    field* field_node;

#line 145 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
