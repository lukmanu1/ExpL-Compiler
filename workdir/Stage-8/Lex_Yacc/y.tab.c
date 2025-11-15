/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include "./../Code_gen/code_generation.h"
    FILE* outputFile; 
    FILE* inputFile;   

    void yyerror(const char* error);
    int yylex(void);
    extern int yylineno;      // Line number (from lexer)
    extern char *yytext;      // Current token text (from lexer)
    extern int yychar;        // Current token code (from parser)

    table_type* type_variable = NULL;
    table_type* type_function = NULL;
    table_type* type_param = NULL;
    Classtable* current_class = NULL;
    Classtable* class_type = NULL;


    // void makeExecutableFile(struct tnode* node, FILE* fptr);
    extern FILE* yyin;
    extern p_node* param_head;
    extern p_node* param_tail;
    extern lst_node* lst_head;  
    extern lst_node* lst_tail;
    extern ast_node* arg_list_head;
    extern ast_node* arg_list_tail;
    extern int lst_binding;
    extern int binding_addr;
    

#line 101 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 256 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   796

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  404

#define YYUNDEFTOK  2
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    51,     2,     2,
      55,    56,    49,    47,    57,    48,    60,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    54,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    73,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    89,    92,    93,    96,    96,   100,
     101,   104,   109,   109,   113,   114,   117,   120,   121,   124,
     125,   128,   129,   130,   133,   134,   137,   138,   139,   142,
     143,   150,   151,   154,   155,   158,   161,   162,   165,   166,
     167,   168,   181,   182,   186,   186,   203,   203,   206,   206,
     211,   212,   213,   216,   217,   218,   219,   220,   223,   224,
     227,   228,   231,   235,   242,   244,   251,   256,   257,   258,
     273,   273,   282,   289,   293,   294,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   321,   326,   331,   338,   345,
     351,   356,   361,   368,   369,   374,   378,   382,   386,   390,
     393,   394,   397,   399,   401,   403,   405,   407,   409,   411,
     413,   415,   417,   419,   421,   423,   425,   427,   429,   431,
     433,   435,   437,   439,   441,   445,   446,   447,   448,   451,
     452,   456,   457,   458
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NEW", "DELETE", "PBEGIN", "END", "DECL",
  "ENDDECL", "TYPE", "ENDTYPE", "CLASS", "ENDCLASS", "EXTENDS", "READ",
  "WRITE", "FREE", "ALLOC", "INIT", "IF", "ELSE", "THEN", "ENDIF", "WHILE",
  "DO", "REPEAT", "UNTIL", "BREAK", "CONTINUE", "EQUAL", "LT", "GT", "LE",
  "GE", "NOT", "NE", "EQ", "AND", "INT", "STR", "MAIN", "RETURN",
  "NULL_NODE", "NUM", "ID", "STRING_LITERAL", "SELF", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'{'", "'}'", "';'", "'('", "')'", "','", "'['", "']'",
  "'.'", "$accept", "Program", "TypeDefBlock", "TypeDefList", "TypeDef",
  "$@1", "FieldDeclList", "FieldDecl", "ClassDefBlock", "$@2",
  "ClassDefList", "ClassDef", "ClassName", "VariableList", "VariableDecl",
  "MethodDecl", "MDecl", "MethodDefns", "GDeclBlock", "GDeclList", "GDecl",
  "GidList", "Gid", "FDefBlock", "Fdef", "$@3", "$@4", "$@5", "ParamList",
  "Param", "LdeclBlock", "LDecList", "LDecl", "IdList", "Type",
  "MainBlock", "$@6", "Body", "Slist", "Stmt", "InputStmt", "OutputStmt",
  "AsgStmt", "IfStmt", "whileStmt", "doWhileStmt", "repeatStmt",
  "breakStmt", "continueStmt", "returnStmt", "E", "Field", "ArgList",
  "FieldFunction", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,    43,    45,    42,
      47,    37,   123,   125,    59,    40,    41,    44,    91,    93,
      46
};
# endif

#define YYPACT_NINF (-214)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,     1,    10,  -214,    85,   150,    25,    15,    76,  -214,
    -214,  -214,  -214,  -214,     4,  -214,   -33,  -214,     0,  -214,
     118,   120,  -214,    15,    76,  -214,    76,  -214,   -16,   149,
     164,    76,  -214,  -214,  -214,  -214,    93,   168,   115,  -214,
     184,  -214,  -214,   235,     3,  -214,   198,   205,    76,  -214,
      76,  -214,    76,  -214,   213,   218,   227,  -214,  -214,   194,
     241,  -214,  -214,   -33,   196,   253,  -214,  -214,   297,   266,
      76,  -214,  -214,  -214,   194,   194,   194,   -24,    34,   265,
     -49,  -214,   261,  -214,   148,  -214,   278,  -214,   207,   325,
    -214,    83,   159,   289,  -214,   303,  -214,   306,  -214,  -214,
     194,  -214,  -214,  -214,   283,   310,   323,   329,   221,  -214,
      38,  -214,   334,   340,   348,  -214,  -214,  -214,  -214,   302,
     336,   349,   360,   361,   365,  -214,    41,  -214,  -214,   139,
    -214,    92,   359,   325,   325,   325,  -214,  -214,  -214,     6,
     294,   304,   257,   368,   369,   370,  -214,  -214,  -214,  -214,
     371,   131,   347,   363,  -214,  -214,  -214,   194,   194,   194,
     373,   167,  -214,   364,   366,   367,  -214,  -214,   135,   375,
     372,   376,   381,   384,   385,   390,   393,   397,   398,   374,
     399,   232,    58,   358,   407,   383,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,    21,  -214,   359,
     359,   359,   312,   320,   322,  -214,  -214,  -214,   408,    42,
    -214,   158,   268,   268,   400,   268,   268,   455,   455,  -214,
    -214,   410,  -214,  -214,     9,  -214,   395,   413,  -214,   268,
     652,   401,  -214,   100,   268,   414,   418,   391,   412,  -214,
     154,   420,   422,   423,   424,   427,   430,   431,  -214,    12,
      49,   181,    63,   546,   556,   432,   578,   588,   203,   239,
    -214,   740,   268,   428,   443,  -214,   610,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,  -214,   448,
     440,   442,   677,   458,  -214,  -214,   268,  -214,   445,   447,
     685,  -214,  -214,  -214,  -214,  -214,  -214,  -214,   444,   268,
     449,   460,   268,   464,   465,   466,  -214,   404,   415,   498,
     496,  -214,   743,   324,   480,   468,   469,  -214,   293,   293,
     293,   293,   293,   293,   110,   110,  -214,  -214,  -214,   470,
     482,   484,  -214,    44,   710,   492,   485,  -214,  -214,   502,
    -214,  -214,   524,  -214,  -214,  -214,   455,   455,   487,   488,
    -214,   268,   486,   268,   268,   268,   489,   490,   121,   503,
    -214,   506,   494,   486,    66,   311,   275,   268,   268,   743,
     326,   328,   338,   504,  -214,   508,   718,  -214,   510,  -214,
     511,   455,   512,  -214,   620,   642,  -214,  -214,  -214,  -214,
     513,  -214,  -214,  -214,   419,  -214,   514,   516,   526,   530,
    -214,  -214,  -214,  -214
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    22,     0,     0,     0,     0,     0,    13,
      42,    77,    78,    79,     0,    44,     0,    17,     0,    16,
       0,     0,     1,     0,     0,     7,     0,    10,     0,     0,
       0,     0,    53,    12,    41,    43,    48,     0,     0,    47,
       0,    14,    15,    27,     0,    25,     0,     0,     0,     4,
       0,     6,     0,     9,     0,     0,     0,    52,    11,    62,
       0,    51,    45,     0,     0,     0,    23,    24,     0,     0,
       0,     3,     5,     8,    62,    62,    62,     0,     0,     0,
       0,    61,     0,    46,     0,    20,     0,    28,     0,     0,
       2,     0,     0,     0,    65,     0,    66,     0,    67,    50,
       0,    49,    18,    19,     0,     0,     0,     0,     0,    30,
       0,    80,     0,     0,     0,    63,    64,    60,    21,     0,
       0,     0,     0,     0,     0,    29,     0,    35,    69,     0,
      71,     0,     0,     0,     0,     0,    31,    32,    33,     0,
       0,     0,     0,     0,     0,     0,    34,    68,    70,    76,
       0,     0,     0,     0,    54,    56,    58,    62,    62,    62,
       0,     0,    40,     0,     0,     0,    75,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,    81,     0,
       0,     0,     0,     0,     0,    26,    39,    74,     0,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,   118,
     119,     0,   143,   135,   137,   136,     0,     0,   121,     0,
       0,   142,   144,     0,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     140,     0,     0,     0,     0,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   120,     0,
       0,     0,     0,     0,   146,   148,     0,    82,     0,     0,
       0,   145,    55,    57,    59,    37,    38,    36,     0,     0,
       0,     0,     0,     0,     0,     0,    99,     0,     0,     0,
       0,   133,   150,     0,     0,   146,   148,   138,   127,   128,
     129,   130,   132,   131,   122,   123,   124,   125,   126,   145,
       0,     0,   109,     0,     0,     0,     0,   112,   104,     0,
     103,   105,     0,   107,   108,    98,     0,     0,     0,     0,
     134,     0,   139,     0,     0,     0,     0,     0,     0,     0,
     111,     0,     0,     0,     0,     0,     0,     0,     0,   149,
       0,     0,     0,     0,    96,     0,     0,   147,     0,    97,
       0,     0,     0,   115,     0,     0,   152,   151,   153,   101,
       0,   110,   102,   106,     0,   114,     0,     0,     0,     0,
     116,   117,   100,   113
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -214,  -214,  -214,  -214,   549,  -214,  -214,   501,   584,  -214,
    -214,   554,  -214,  -214,   491,  -214,   474,  -214,     7,  -214,
     587,  -214,   552,   105,   -29,  -214,  -214,  -214,   -57,   517,
      90,  -214,   493,  -214,   -58,   104,  -214,    71,  -213,  -184,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -178,  -152,   -47,  -214
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    18,    19,    40,    84,    85,     7,    20,
      44,    45,    46,   108,   109,   126,   127,   161,     8,    14,
      15,    38,    39,    31,    32,   199,   200,   201,    80,    81,
     111,   129,   130,   151,    16,     9,   132,   153,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     312,   231,   313,   232
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     197,   239,    57,   230,   258,   259,    86,    99,   100,    10,
      41,    36,    34,    24,    26,    66,    37,    91,    92,    93,
      94,    57,     1,    57,    21,    95,    86,     1,    54,     2,
      48,     3,     1,   197,   253,   254,     3,   256,   257,    11,
      12,    57,    11,    12,    17,    13,   128,    43,    13,   142,
     240,   266,   131,     4,    17,   282,   283,   250,     4,   252,
     136,   157,   290,     4,   261,   197,   197,   262,   298,   263,
     299,   131,   235,   358,   239,   239,    11,    12,    96,   143,
     144,   241,    13,    97,   314,   145,   249,   233,   183,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     202,   203,   204,   280,   359,   300,   197,   197,   334,   241,
      25,    27,    33,   162,    28,    29,   234,   281,   235,   303,
      30,   339,   380,   241,   342,    21,   359,    49,    51,    50,
      53,    52,   206,   365,   366,    58,   149,   221,   375,   112,
     100,   150,   222,   223,   224,   225,   226,   147,    59,   227,
      22,    60,    71,    70,    72,   229,    73,   288,   221,   275,
     276,   277,    43,   222,   223,   224,   225,   226,   394,    62,
     227,   289,    63,   369,    90,    47,   229,    11,    12,   207,
     376,   239,   239,    13,   208,   167,    11,    12,   168,   384,
     385,   221,    13,    55,   197,   197,   222,   223,   224,   225,
     226,   102,   251,   227,   183,   160,    29,   169,    56,   229,
     239,    30,    61,   197,   197,   113,   100,   171,   172,   173,
     205,   174,   175,   154,   155,   156,   176,   177,   178,   197,
     179,   180,    77,    78,    11,    12,    64,   301,    79,   302,
      13,   235,   197,   169,   181,   105,   106,   182,    65,   183,
      68,   107,   184,   171,   172,   173,   309,   174,   175,   122,
     123,    69,   176,   177,   178,   124,   179,   180,    74,   221,
     242,   243,   244,    75,   222,   223,   224,   225,   226,   169,
     181,   227,    76,   182,    82,   183,   228,   229,   184,   171,
     172,   173,   310,   174,   175,   160,    29,    87,   176,   177,
     178,    30,   179,   180,    88,   221,   370,   371,   372,    98,
     222,   223,   224,   225,   226,   169,   181,   227,    89,   182,
     101,   183,   104,   229,   184,   171,   172,   173,   383,   174,
     175,   381,   110,   382,   176,   177,   178,   118,   179,   180,
     273,   274,   275,   276,   277,   114,   100,   115,   137,   158,
     116,   169,   181,   170,   119,   182,   136,   183,   138,   159,
     184,   171,   172,   173,   152,   174,   175,   120,   245,   100,
     176,   177,   178,   121,   179,   180,   246,   100,   247,   100,
     350,   351,   386,   351,   387,   351,   133,   169,   181,   238,
     137,   182,   134,   183,   388,   351,   184,   171,   172,   173,
     135,   174,   175,   138,   139,   140,   176,   177,   178,   141,
     179,   180,   163,   164,   165,   166,   198,    54,   236,   157,
     286,   158,   159,   169,   181,   346,   210,   182,   219,   183,
     209,   211,   184,   171,   172,   173,   212,   174,   175,   213,
     214,   399,   176,   177,   178,   215,   179,   180,   216,   217,
     218,   237,   248,   220,   260,   264,   255,   265,   284,   169,
     181,   279,   285,   182,   291,   183,   287,   347,   184,   171,
     172,   173,   315,   174,   175,   292,   293,   294,   176,   177,
     178,   295,   179,   180,   296,   297,   306,   316,   267,   268,
     269,   270,   329,   271,   272,   330,   181,   331,   338,   182,
     335,   183,   336,   340,   184,   273,   274,   275,   276,   277,
     267,   268,   269,   270,   341,   271,   272,   333,   343,   344,
     345,   348,   349,   353,   354,   355,   356,   273,   274,   275,
     276,   277,   267,   268,   269,   270,   361,   271,   272,   352,
     357,   362,   367,   368,   374,   373,   359,   377,   379,   273,
     274,   275,   276,   277,   267,   268,   269,   270,   389,   271,
     272,   363,   378,   390,   392,   393,   395,    42,   400,   398,
     401,   273,   274,   275,   276,   277,   267,   268,   269,   270,
     402,   271,   272,   364,   403,   103,   267,   268,   269,   270,
      23,   271,   272,   273,   274,   275,   276,   277,    67,   125,
     146,    35,   304,   273,   274,   275,   276,   277,   267,   268,
     269,   270,   305,   271,   272,    83,     0,   117,   267,   268,
     269,   270,   148,   271,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,   307,   273,   274,   275,   276,   277,
     267,   268,   269,   270,   308,   271,   272,     0,     0,     0,
     267,   268,   269,   270,     0,   271,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,   317,   273,   274,   275,
     276,   277,   267,   268,   269,   270,   396,   271,   272,     0,
       0,     0,   267,   268,   269,   270,     0,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,   397,   273,
     274,   275,   276,   277,     0,     0,   278,   267,   268,   269,
     270,     0,   271,   272,     0,   267,   268,   269,   270,     0,
     271,   272,     0,     0,   273,   274,   275,   276,   277,     0,
       0,   332,   273,   274,   275,   276,   277,     0,     0,   337,
     267,   268,   269,   270,     0,   271,   272,     0,   267,   268,
     269,   270,     0,   271,   272,     0,     0,   273,   274,   275,
     276,   277,     0,     0,   360,   273,   274,   275,   276,   277,
       0,     0,   391,   267,   268,   269,   270,   221,   271,   272,
       0,     0,   222,   223,   224,   225,   226,     0,     0,   227,
     273,   274,   275,   276,   277,   229,   311
};

static const yytype_int16 yycheck[] =
{
     152,   185,    31,   181,   217,   218,    64,    56,    57,     8,
      10,    44,     8,     6,     7,    12,    49,    74,    75,    76,
      44,    50,     7,    52,    40,    49,    84,     7,    44,     9,
      23,    11,     7,   185,   212,   213,    11,   215,   216,    38,
      39,    70,    38,    39,    44,    44,     8,    44,    44,     8,
      29,   229,   110,    38,    44,   233,   234,   209,    38,   211,
      54,    55,   240,    38,    55,   217,   218,    58,    56,    60,
      58,   129,    60,    29,   258,   259,    38,    39,    44,    38,
      39,    60,    44,    49,   262,    44,    44,    29,    46,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     157,   158,   159,     3,    60,    56,   258,   259,   286,    60,
       6,     7,     8,   142,    38,    39,    58,    17,    60,    56,
      44,   299,    56,    60,   302,    40,    60,    23,    24,    24,
      26,    26,   161,   346,   347,    31,    44,    37,    17,    56,
      57,    49,    42,    43,    44,    45,    46,     8,    55,    49,
       0,    58,    48,    48,    50,    55,    52,     3,    37,    49,
      50,    51,    44,    42,    43,    44,    45,    46,   381,    54,
      49,    17,    57,   351,    70,    55,    55,    38,    39,    44,
     358,   365,   366,    44,    49,    54,    38,    39,    57,   367,
     368,    37,    44,    44,   346,   347,    42,    43,    44,    45,
      46,    53,    44,    49,    46,    38,    39,     4,    44,    55,
     394,    44,    44,   365,   366,    56,    57,    14,    15,    16,
      53,    18,    19,   133,   134,   135,    23,    24,    25,   381,
      27,    28,    38,    39,    38,    39,    52,    56,    44,    58,
      44,    60,   394,     4,    41,    38,    39,    44,    13,    46,
      52,    44,    49,    14,    15,    16,    53,    18,    19,    38,
      39,    56,    23,    24,    25,    44,    27,    28,    55,    37,
     199,   200,   201,    55,    42,    43,    44,    45,    46,     4,
      41,    49,    55,    44,    43,    46,    54,    55,    49,    14,
      15,    16,    53,    18,    19,    38,    39,    44,    23,    24,
      25,    44,    27,    28,     7,    37,   353,   354,   355,    44,
      42,    43,    44,    45,    46,     4,    41,    49,    52,    44,
      59,    46,    44,    55,    49,    14,    15,    16,    53,    18,
      19,    20,     7,    22,    23,    24,    25,    54,    27,    28,
      47,    48,    49,    50,    51,    56,    57,    44,    54,    55,
      44,     4,    41,     6,    44,    44,    54,    46,    54,    55,
      49,    14,    15,    16,     5,    18,    19,    44,    56,    57,
      23,    24,    25,    44,    27,    28,    56,    57,    56,    57,
      56,    57,    56,    57,    56,    57,    52,     4,    41,     6,
      54,    44,    52,    46,    56,    57,    49,    14,    15,    16,
      52,    18,    19,    54,    44,    44,    23,    24,    25,    44,
      27,    28,    44,    44,    44,    44,    53,    44,    60,    55,
      29,    55,    55,     4,    41,    21,    54,    44,    54,    46,
      55,    55,    49,    14,    15,    16,    55,    18,    19,    55,
      55,    22,    23,    24,    25,    55,    27,    28,    55,    52,
      52,    44,    44,    54,    44,    60,    56,    44,    44,     4,
      41,    60,    44,    44,    44,    46,    54,    52,    49,    14,
      15,    16,    44,    18,    19,    53,    53,    53,    23,    24,
      25,    54,    27,    28,    54,    54,    54,    44,    30,    31,
      32,    33,    44,    35,    36,    55,    41,    55,    54,    44,
      55,    46,    55,    54,    49,    47,    48,    49,    50,    51,
      30,    31,    32,    33,    54,    35,    36,    59,    54,    54,
      54,    23,    26,    55,    55,    55,    44,    47,    48,    49,
      50,    51,    30,    31,    32,    33,    44,    35,    36,    59,
      56,    56,    55,    55,    54,    56,    60,    44,    54,    47,
      48,    49,    50,    51,    30,    31,    32,    33,    54,    35,
      36,    59,    56,    55,    54,    54,    54,    18,    54,    56,
      54,    47,    48,    49,    50,    51,    30,    31,    32,    33,
      54,    35,    36,    59,    54,    84,    30,    31,    32,    33,
       6,    35,    36,    47,    48,    49,    50,    51,    44,   108,
     126,    14,    56,    47,    48,    49,    50,    51,    30,    31,
      32,    33,    56,    35,    36,    63,    -1,   100,    30,    31,
      32,    33,   129,    35,    36,    47,    48,    49,    50,    51,
      -1,    -1,    -1,    -1,    56,    47,    48,    49,    50,    51,
      30,    31,    32,    33,    56,    35,    36,    -1,    -1,    -1,
      30,    31,    32,    33,    -1,    35,    36,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    -1,    56,    47,    48,    49,
      50,    51,    30,    31,    32,    33,    56,    35,    36,    -1,
      -1,    -1,    30,    31,    32,    33,    -1,    35,    36,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    -1,    56,    47,
      48,    49,    50,    51,    -1,    -1,    54,    30,    31,    32,
      33,    -1,    35,    36,    -1,    30,    31,    32,    33,    -1,
      35,    36,    -1,    -1,    47,    48,    49,    50,    51,    -1,
      -1,    54,    47,    48,    49,    50,    51,    -1,    -1,    54,
      30,    31,    32,    33,    -1,    35,    36,    -1,    30,    31,
      32,    33,    -1,    35,    36,    -1,    -1,    47,    48,    49,
      50,    51,    -1,    -1,    54,    47,    48,    49,    50,    51,
      -1,    -1,    54,    30,    31,    32,    33,    37,    35,    36,
      -1,    -1,    42,    43,    44,    45,    46,    -1,    -1,    49,
      47,    48,    49,    50,    51,    55,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     9,    11,    38,    62,    63,    69,    79,    96,
       8,    38,    39,    44,    80,    81,    95,    44,    64,    65,
      70,    40,     0,    69,    79,    96,    79,    96,    38,    39,
      44,    84,    85,    96,     8,    81,    44,    49,    82,    83,
      66,    10,    65,    44,    71,    72,    73,    55,    79,    96,
      84,    96,    84,    96,    44,    44,    44,    85,    96,    55,
      58,    44,    54,    57,    52,    13,    12,    72,    52,    56,
      84,    96,    96,    96,    55,    55,    55,    38,    39,    44,
      89,    90,    43,    83,    67,    68,    95,    44,     7,    52,
      96,    89,    89,    89,    44,    49,    44,    49,    44,    56,
      57,    59,    53,    68,    44,    38,    39,    44,    74,    75,
       7,    91,    56,    56,    56,    44,    44,    90,    54,    44,
      44,    44,    38,    39,    44,    75,    76,    77,     8,    92,
      93,    95,    97,    52,    52,    52,    54,    54,    54,    44,
      44,    44,     8,    38,    39,    44,    77,     8,    93,    44,
      49,    94,     5,    98,    91,    91,    91,    55,    55,    55,
      38,    78,    85,    44,    44,    44,    44,    54,    57,     4,
       6,    14,    15,    16,    18,    19,    23,    24,    25,    27,
      28,    41,    44,    46,    49,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   112,    53,    86,
      87,    88,    89,    89,    89,    53,    85,    44,    49,    55,
      54,    55,    55,    55,    55,    55,    55,    52,    52,    54,
      54,    37,    42,    43,    44,    45,    46,    49,    54,    55,
     111,   112,   114,    29,    58,    60,    60,    44,     6,   100,
      29,    60,    98,    98,    98,    56,    56,    56,    44,    44,
     112,    44,   112,   111,   111,    56,   111,   111,    99,    99,
      44,    55,    58,    60,    60,    44,   111,    30,    31,    32,
      33,    35,    36,    47,    48,    49,    50,    51,    54,    60,
       3,    17,   111,   111,    44,    44,    29,    54,     3,    17,
     111,    44,    53,    53,    53,    54,    54,    54,    56,    58,
      56,    56,    58,    56,    56,    56,    54,    56,    56,    53,
      53,    56,   111,   113,   111,    44,    44,    56,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,    44,
      55,    55,    54,    59,   111,    55,    55,    54,    54,   111,
      54,    54,   111,    54,    54,    54,    21,    52,    23,    26,
      56,    57,    59,    55,    55,    55,    44,    56,    29,    60,
      54,    44,    56,    59,    59,    99,    99,    55,    55,   111,
     113,   113,   113,    56,    54,    17,   111,    44,    56,    54,
      56,    20,    22,    53,   111,   111,    56,    56,    56,    54,
      55,    54,    54,    54,    99,    54,    56,    56,    56,    22,
      54,    54,    54,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    63,    64,    64,    66,    65,    67,
      67,    68,    70,    69,    71,    71,    72,    73,    73,    74,
      74,    75,    75,    75,    76,    76,    77,    77,    77,    78,
      78,    79,    79,    80,    80,    81,    82,    82,    83,    83,
      83,    83,    84,    84,    86,    85,    87,    85,    88,    85,
      89,    89,    89,    90,    90,    90,    90,    90,    91,    91,
      92,    92,    93,    94,    94,    94,    94,    95,    95,    95,
      97,    96,    98,    98,    99,    99,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   101,   101,   101,   102,   103,
     103,   103,   103,   104,   104,   105,   106,   107,   108,   109,
     110,   110,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   112,   112,   112,   112,   113,
     113,   114,   114,   114
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     4,     3,     2,     4,     3,
       2,     3,     2,     1,     3,     2,     1,     0,     5,     2,
       1,     3,     0,     4,     2,     1,     8,     1,     3,     2,
       1,     3,     3,     3,     2,     1,     6,     6,     6,     2,
       1,     3,     2,     2,     1,     3,     3,     1,     1,     4,
       4,     2,     2,     1,     0,    10,     0,    10,     0,    10,
       3,     1,     0,     3,     3,     2,     2,     2,     3,     2,
       2,     1,     3,     4,     3,     2,     1,     1,     1,     1,
       0,     9,     4,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     6,     6,     5,     4,
       9,     7,     7,     5,     5,     5,     8,     5,     5,     4,
       7,     5,     4,    10,     8,     7,     9,     9,     2,     2,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     1,     1,     1,     3,     4,
       2,     2,     1,     1,     1,     3,     3,     6,     3,     3,
       1,     6,     6,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 14:
#line 89 "parser.y"
                                                        {  }
#line 1777 "y.tab.c"
    break;

  case 15:
#line 92 "parser.y"
                                                        {   }
#line 1783 "y.tab.c"
    break;

  case 16:
#line 93 "parser.y"
                                                        {   }
#line 1789 "y.tab.c"
    break;

  case 17:
#line 96 "parser.y"
                                                        { type_table_install((yyvsp[0].AST_node)->name, NULL); }
#line 1795 "y.tab.c"
    break;

  case 18:
#line 97 "parser.y"
                                                        { table_type* new_type = tLookup((yyvsp[-4].AST_node)->name); new_type->fields = (yyvsp[-1].field_node); }
#line 1801 "y.tab.c"
    break;

  case 19:
#line 100 "parser.y"
                                                        { (yyval.field_node) = append_field((yyvsp[-1].field_node), (yyvsp[0].field_node)); }
#line 1807 "y.tab.c"
    break;

  case 20:
#line 101 "parser.y"
                                                        { (yyval.field_node) = (yyvsp[0].field_node); }
#line 1813 "y.tab.c"
    break;

  case 21:
#line 104 "parser.y"
                                                        { (yyval.field_node) = create_field_node((yyvsp[-1].AST_node)->name, type_variable); }
#line 1819 "y.tab.c"
    break;

  case 22:
#line 109 "parser.y"
                                                   {  }
#line 1825 "y.tab.c"
    break;

  case 23:
#line 110 "parser.y"
                                                   { current_class = NULL; PrintClassTable(); }
#line 1831 "y.tab.c"
    break;

  case 24:
#line 113 "parser.y"
                                                           { }
#line 1837 "y.tab.c"
    break;

  case 25:
#line 114 "parser.y"
                                                           { }
#line 1843 "y.tab.c"
    break;

  case 26:
#line 117 "parser.y"
                                                                                    { }
#line 1849 "y.tab.c"
    break;

  case 27:
#line 120 "parser.y"
                                            { (yyval.class_node) = CInstall((yyvsp[0].AST_node)->name, NULL); current_class = (yyval.class_node); binding_addr += 8; }
#line 1855 "y.tab.c"
    break;

  case 28:
#line 121 "parser.y"
                                            { (yyval.class_node) = CInstall((yyvsp[-2].AST_node)->name, (yyvsp[0].AST_node)->name); current_class = (yyval.class_node); binding_addr += 8; }
#line 1861 "y.tab.c"
    break;

  case 29:
#line 124 "parser.y"
                                              { }
#line 1867 "y.tab.c"
    break;

  case 30:
#line 125 "parser.y"
                                              { }
#line 1873 "y.tab.c"
    break;

  case 31:
#line 128 "parser.y"
                                            { Class_Finstall(current_class, "int", (yyvsp[-1].AST_node)->name); }
#line 1879 "y.tab.c"
    break;

  case 32:
#line 129 "parser.y"
                                            { Class_Finstall(current_class, "str", (yyvsp[-1].AST_node)->name); }
#line 1885 "y.tab.c"
    break;

  case 33:
#line 130 "parser.y"
                                            { Class_Finstall(current_class, (yyvsp[-2].AST_node)->name, (yyvsp[-1].AST_node)->name); }
#line 1891 "y.tab.c"
    break;

  case 36:
#line 137 "parser.y"
                                              { Class_Minstall(current_class, (yyvsp[-4].AST_node)->name, tLookup((yyvsp[-5].AST_node)->name), (yyvsp[-2].param_node)); }
#line 1897 "y.tab.c"
    break;

  case 37:
#line 138 "parser.y"
                                              { Class_Minstall(current_class, (yyvsp[-4].AST_node)->name, default_types->int_type, (yyvsp[-2].param_node)); }
#line 1903 "y.tab.c"
    break;

  case 38:
#line 139 "parser.y"
                                              { Class_Minstall(current_class, (yyvsp[-4].AST_node)->name, default_types->str_type, (yyvsp[-2].param_node)); }
#line 1909 "y.tab.c"
    break;

  case 41:
#line 150 "parser.y"
                                                        {  print_gstable(); }
#line 1915 "y.tab.c"
    break;

  case 48:
#line 165 "parser.y"
                                                        { gst_install((yyvsp[0].AST_node)->name, type_variable, class_type, 1, 0, NULL); }
#line 1921 "y.tab.c"
    break;

  case 49:
#line 166 "parser.y"
                                                        { gst_install((yyvsp[-3].AST_node)->name, type_variable, class_type, 1, (yyvsp[-1].AST_node)->value.iVal, NULL); }
#line 1927 "y.tab.c"
    break;

  case 50:
#line 167 "parser.y"
                                                        { gst_install((yyvsp[-3].AST_node)->name, type_variable, class_type, 0, 0, (yyvsp[-1].param_node)); }
#line 1933 "y.tab.c"
    break;

  case 51:
#line 169 "parser.y"
                                                        { 
                                                            if(strcmp(type_variable->name, default_types->int_type->name) == 0){
                                                                gst_install((yyvsp[0].AST_node)->name, default_types->int_ptr_type, class_type, 1, 0, NULL);
                                                            }else{
                                                                gst_install((yyvsp[0].AST_node)->name, default_types->str_ptr_type, class_type, 1, 0, NULL);
                                                            }
                                                        }
#line 1945 "y.tab.c"
    break;

  case 52:
#line 181 "parser.y"
                                                        { create_connector_node((yyvsp[-1].AST_node), (yyvsp[0].AST_node)); }
#line 1951 "y.tab.c"
    break;

  case 53:
#line 182 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 1957 "y.tab.c"
    break;

  case 54:
#line 186 "parser.y"
                                                        { 
                                                            type_function = default_types->int_type;
                                                            lst_binding = -4; 
                                                            code_gen_function_definition(outputFile, (yyvsp[-5].AST_node), current_class, (yyvsp[-3].param_node)); 
                                                            add_param_list_to_lst((yyvsp[-3].param_node));
                                                            if(current_class) { insert_self(current_class);}
                                                            lst_binding = 1; 
                                                            lst_display(); 
                                                        }
#line 1971 "y.tab.c"
    break;

  case 55:
#line 196 "parser.y"
                                                        { 
                                                            (yyval.AST_node) = create_function_definition_node(default_types->int_type, (yyvsp[-8].AST_node), (yyvsp[-6].param_node), (yyvsp[-1].AST_node), current_class); 
                                                            lst_head = lst_tail = NULL; 
                                                            codeGen(outputFile, (yyvsp[-1].AST_node)); 
                                                            code_gen_exit_function(outputFile); 
                                                        }
#line 1982 "y.tab.c"
    break;

  case 56:
#line 203 "parser.y"
                                                        { type_function = default_types->str_type; lst_binding = -4; code_gen_function_definition(outputFile, (yyvsp[-5].AST_node), current_class, (yyvsp[-3].param_node)); add_param_list_to_lst((yyvsp[-3].param_node)); if(current_class) { insert_self(current_class);} lst_binding = 1; lst_display(); }
#line 1988 "y.tab.c"
    break;

  case 57:
#line 204 "parser.y"
                                                        { (yyval.AST_node) = create_function_definition_node(default_types->str_type, (yyvsp[-8].AST_node), (yyvsp[-6].param_node), (yyvsp[-1].AST_node), current_class); lst_head = lst_tail = NULL; codeGen(outputFile, (yyvsp[-1].AST_node)); code_gen_exit_function(outputFile); }
#line 1994 "y.tab.c"
    break;

  case 58:
#line 206 "parser.y"
                                                         { type_function = tLookup((yyvsp[-6].AST_node)->name); lst_binding = -4; code_gen_function_definition(outputFile, (yyvsp[-5].AST_node), current_class, (yyvsp[-3].param_node)); add_param_list_to_lst((yyvsp[-3].param_node)); if(current_class) { insert_self(current_class);} lst_binding = 1; lst_display(); }
#line 2000 "y.tab.c"
    break;

  case 59:
#line 207 "parser.y"
                                                         { (yyval.AST_node) = create_function_definition_node(type_function, (yyvsp[-8].AST_node), (yyvsp[-6].param_node), (yyvsp[-1].AST_node), current_class); lst_head = lst_tail = NULL; codeGen(outputFile, (yyvsp[-1].AST_node)); code_gen_exit_function(outputFile); }
#line 2006 "y.tab.c"
    break;

  case 60:
#line 211 "parser.y"
                                                        { (yyval.param_node) = append_param((yyvsp[-2].param_node), (yyvsp[0].param_node)); }
#line 2012 "y.tab.c"
    break;

  case 61:
#line 212 "parser.y"
                                                        { (yyval.param_node) = (yyvsp[0].param_node); }
#line 2018 "y.tab.c"
    break;

  case 62:
#line 213 "parser.y"
                                                        { (yyval.param_node) = NULL; }
#line 2024 "y.tab.c"
    break;

  case 63:
#line 216 "parser.y"
                                                       { (yyval.param_node) = create_p_node((yyvsp[0].AST_node)->name, default_types->int_ptr_type); }
#line 2030 "y.tab.c"
    break;

  case 64:
#line 217 "parser.y"
                                                       { (yyval.param_node) = create_p_node((yyvsp[0].AST_node)->name, default_types->str_ptr_type); }
#line 2036 "y.tab.c"
    break;

  case 65:
#line 218 "parser.y"
                                                       { (yyval.param_node) = create_p_node((yyvsp[0].AST_node)->name, default_types->int_type); }
#line 2042 "y.tab.c"
    break;

  case 66:
#line 219 "parser.y"
                                                       { (yyval.param_node) = create_p_node((yyvsp[0].AST_node)->name, default_types->str_type); }
#line 2048 "y.tab.c"
    break;

  case 67:
#line 220 "parser.y"
                                                       { type_param = tLookup((yyvsp[-1].AST_node)->name); (yyval.param_node) = create_p_node((yyvsp[0].AST_node)->name, type_param); }
#line 2054 "y.tab.c"
    break;

  case 68:
#line 223 "parser.y"
                                                        { (yyval.LST_node) = lst_head; }
#line 2060 "y.tab.c"
    break;

  case 69:
#line 224 "parser.y"
                                                        { (yyval.LST_node) = lst_head; }
#line 2066 "y.tab.c"
    break;

  case 70:
#line 227 "parser.y"
                                                        {  }
#line 2072 "y.tab.c"
    break;

  case 71:
#line 228 "parser.y"
                                                        {  }
#line 2078 "y.tab.c"
    break;

  case 73:
#line 236 "parser.y"
                                                        {
                                                            if(strcmp(type_variable->name, default_types->int_type->name) == 0)
                                                                lst_install((yyvsp[0].AST_node)->name, default_types->int_ptr_type, class_type);
                                                            else
                                                                lst_install((yyvsp[0].AST_node)->name, default_types->str_ptr_type, class_type);
                                                        }
#line 2089 "y.tab.c"
    break;

  case 74:
#line 243 "parser.y"
                                                        { lst_install((yyvsp[0].AST_node)->name, type_variable, class_type); }
#line 2095 "y.tab.c"
    break;

  case 75:
#line 245 "parser.y"
                                                        {
                                                            if(strcmp(type_variable->name, default_types->int_type->name) == 0)
                                                                lst_install((yyvsp[0].AST_node)->name, default_types->int_ptr_type, class_type);
                                                            else
                                                                lst_install((yyvsp[0].AST_node)->name, default_types->str_ptr_type, class_type);
                                                        }
#line 2106 "y.tab.c"
    break;

  case 76:
#line 252 "parser.y"
                                                        { lst_install((yyvsp[0].AST_node)->name, type_variable, class_type); }
#line 2112 "y.tab.c"
    break;

  case 77:
#line 256 "parser.y"
                                                        { type_variable = default_types->int_type; class_type = NULL; }
#line 2118 "y.tab.c"
    break;

  case 78:
#line 257 "parser.y"
                                                        { type_variable = default_types->str_type; class_type = NULL; }
#line 2124 "y.tab.c"
    break;

  case 79:
#line 258 "parser.y"
                                                        {
                                                            type_variable = tLookup((yyvsp[0].AST_node)->name);
                                                            class_type = CLookup((yyvsp[0].AST_node)->name);
                                                            
                                                            if (type_variable == NULL && class_type == NULL) {
                                                                
                                                                printf("%s\n", (yyvsp[0].AST_node)->name);
                                                                yyerror("Unknown type used in declaration(not in typeTable and classTable).");
                                                                
                                                            } 
                                                        }
#line 2140 "y.tab.c"
    break;

  case 80:
#line 273 "parser.y"
                                                        { type_function = default_types->int_type; lst_display(); }
#line 2146 "y.tab.c"
    break;

  case 81:
#line 274 "parser.y"
                                                        { code_gen_main_function(outputFile); codeGen(outputFile, (yyvsp[-1].AST_node)); lst_head = lst_tail = NULL; }
#line 2152 "y.tab.c"
    break;

  case 82:
#line 283 "parser.y"
        {
            // inorder($2);
            // makeExecutableFile( $2, outputFile);
            // // evaluate($2);
            (yyval.AST_node) = (yyvsp[-2].AST_node);
        }
#line 2163 "y.tab.c"
    break;

  case 83:
#line 289 "parser.y"
                                                        { exit(0); }
#line 2169 "y.tab.c"
    break;

  case 84:
#line 293 "parser.y"
                                                        { (yyval.AST_node) = create_connector_node((yyvsp[-1].AST_node), (yyvsp[0].AST_node)); }
#line 2175 "y.tab.c"
    break;

  case 85:
#line 294 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2181 "y.tab.c"
    break;

  case 86:
#line 299 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2187 "y.tab.c"
    break;

  case 87:
#line 300 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2193 "y.tab.c"
    break;

  case 88:
#line 301 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2199 "y.tab.c"
    break;

  case 89:
#line 302 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2205 "y.tab.c"
    break;

  case 90:
#line 303 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2211 "y.tab.c"
    break;

  case 91:
#line 304 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2217 "y.tab.c"
    break;

  case 92:
#line 305 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2223 "y.tab.c"
    break;

  case 93:
#line 306 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2229 "y.tab.c"
    break;

  case 94:
#line 307 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2235 "y.tab.c"
    break;

  case 95:
#line 308 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2241 "y.tab.c"
    break;

  case 96:
#line 309 "parser.y"
                                                        { (yyval.AST_node) = create_alloc_function_call_node((yyvsp[-5].AST_node)); }
#line 2247 "y.tab.c"
    break;

  case 97:
#line 310 "parser.y"
                                                        { (yyval.AST_node) = create_alloc_function_call_node((yyvsp[-5].AST_node)); }
#line 2253 "y.tab.c"
    break;

  case 98:
#line 311 "parser.y"
                                                        { (yyval.AST_node) = create_free_function_call_node((yyvsp[-2].AST_node)); }
#line 2259 "y.tab.c"
    break;

  case 99:
#line 312 "parser.y"
                                                        { (yyval.AST_node) = create_init_function_call_node(); }
#line 2265 "y.tab.c"
    break;

  case 100:
#line 313 "parser.y"
                                                        { ast_node* arr_node = create_array_node((yyvsp[-8].AST_node), (yyvsp[-6].AST_node)); (yyval.AST_node) = create_alloc_function_call_node(arr_node); }
#line 2271 "y.tab.c"
    break;

  case 101:
#line 314 "parser.y"
                                                        { (yyvsp[-6].AST_node) = create_id_node((yyvsp[-6].AST_node)); (yyval.AST_node) = create_new_function_call_node((yyvsp[-6].AST_node), (yyvsp[-2].AST_node)); }
#line 2277 "y.tab.c"
    break;

  case 102:
#line 315 "parser.y"
                                                        { (yyval.AST_node) = create_new_function_call_node((yyvsp[-6].AST_node), (yyvsp[-2].AST_node)); }
#line 2283 "y.tab.c"
    break;

  case 103:
#line 316 "parser.y"
                                                        { (yyval.AST_node) = create_delete_node((yyvsp[-2].AST_node)); }
#line 2289 "y.tab.c"
    break;

  case 104:
#line 317 "parser.y"
                                                        { (yyvsp[-2].AST_node) = create_id_node((yyvsp[-2].AST_node)); (yyval.AST_node) = create_delete_node((yyvsp[-2].AST_node)); }
#line 2295 "y.tab.c"
    break;

  case 105:
#line 322 "parser.y"
        {
            (yyvsp[-2].AST_node) = create_id_node((yyvsp[-2].AST_node));
            (yyval.AST_node) = create_read_node((yyvsp[-2].AST_node));
        }
#line 2304 "y.tab.c"
    break;

  case 106:
#line 327 "parser.y"
        {
            ast_node* array_node = create_array_node((yyvsp[-5].AST_node), (yyvsp[-3].AST_node));
            (yyval.AST_node) = create_read_node(array_node);
        }
#line 2313 "y.tab.c"
    break;

  case 107:
#line 332 "parser.y"
        {
            (yyval.AST_node) = create_read_node((yyvsp[-2].AST_node));
        }
#line 2321 "y.tab.c"
    break;

  case 108:
#line 339 "parser.y"
        {
            (yyval.AST_node) = create_write_node((yyvsp[-2].AST_node));
        }
#line 2329 "y.tab.c"
    break;

  case 109:
#line 346 "parser.y"
        {
            (yyvsp[-3].AST_node) = create_id_node((yyvsp[-3].AST_node));
            (yyval.AST_node) = create_assign_node((yyvsp[-3].AST_node), (yyvsp[-1].AST_node));
        }
#line 2338 "y.tab.c"
    break;

  case 110:
#line 352 "parser.y"
        {
            ast_node* array_node = create_array_node((yyvsp[-6].AST_node), (yyvsp[-4].AST_node));
            (yyval.AST_node) = create_assign_node(array_node, (yyvsp[-1].AST_node));
        }
#line 2347 "y.tab.c"
    break;

  case 111:
#line 357 "parser.y"
        {
            ast_node* deref_node = create_deref_node((yyvsp[-3].AST_node));
            (yyval.AST_node) = create_assign_node(deref_node, (yyvsp[-1].AST_node));
        }
#line 2356 "y.tab.c"
    break;

  case 112:
#line 362 "parser.y"
        {
            (yyval.AST_node) = create_assign_node((yyvsp[-3].AST_node), (yyvsp[-1].AST_node));
        }
#line 2364 "y.tab.c"
    break;

  case 113:
#line 368 "parser.y"
                                                        { (yyval.AST_node) = create_if_else_node((yyvsp[-7].AST_node), (yyvsp[-4].AST_node), (yyvsp[-2].AST_node)); }
#line 2370 "y.tab.c"
    break;

  case 114:
#line 369 "parser.y"
                                                        { (yyval.AST_node) = create_if_node((yyvsp[-5].AST_node), (yyvsp[-2].AST_node)); }
#line 2376 "y.tab.c"
    break;

  case 115:
#line 374 "parser.y"
                                                        { (yyval.AST_node) = create_while_node((yyvsp[-4].AST_node), (yyvsp[-1].AST_node)); }
#line 2382 "y.tab.c"
    break;

  case 116:
#line 378 "parser.y"
                                                        { (yyval.AST_node) = create_do_while_node((yyvsp[-2].AST_node), (yyvsp[-6].AST_node)); }
#line 2388 "y.tab.c"
    break;

  case 117:
#line 382 "parser.y"
                                                        { (yyval.AST_node) = create_repeat_until_node((yyvsp[-2].AST_node), (yyvsp[-6].AST_node)); }
#line 2394 "y.tab.c"
    break;

  case 118:
#line 386 "parser.y"
                                                        { (yyval.AST_node) = create_break_node(); }
#line 2400 "y.tab.c"
    break;

  case 119:
#line 390 "parser.y"
                                                        { (yyval.AST_node) = create_continue_node(); }
#line 2406 "y.tab.c"
    break;

  case 120:
#line 393 "parser.y"
                                                         { (yyval.AST_node) = create_return_node(type_function, (yyvsp[-1].AST_node), (yyvsp[-1].AST_node)->type); }
#line 2412 "y.tab.c"
    break;

  case 121:
#line 394 "parser.y"
                                                         { (yyval.AST_node) = create_return_node(type_function, NULL, default_types->void_type);}
#line 2418 "y.tab.c"
    break;

  case 122:
#line 397 "parser.y"
                                                        { (yyval.AST_node) = create_operator_node(NODE_TYPE_PLUS, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2424 "y.tab.c"
    break;

  case 123:
#line 399 "parser.y"
                                                        { (yyval.AST_node) = create_operator_node(NODE_TYPE_MINUS, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2430 "y.tab.c"
    break;

  case 124:
#line 401 "parser.y"
                                                        { (yyval.AST_node) = create_operator_node(NODE_TYPE_MULT, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2436 "y.tab.c"
    break;

  case 125:
#line 403 "parser.y"
                                                        { (yyval.AST_node) = create_operator_node(NODE_TYPE_DIV, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2442 "y.tab.c"
    break;

  case 126:
#line 405 "parser.y"
                                                        { (yyval.AST_node) = create_operator_node(NODE_TYPE_MOD, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2448 "y.tab.c"
    break;

  case 127:
#line 407 "parser.y"
                                                        { (yyval.AST_node) = create_boolean_node(NODE_TYPE_LT, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2454 "y.tab.c"
    break;

  case 128:
#line 409 "parser.y"
                                                        { (yyval.AST_node) = create_boolean_node(NODE_TYPE_GT, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2460 "y.tab.c"
    break;

  case 129:
#line 411 "parser.y"
                                                        { (yyval.AST_node) = create_boolean_node(NODE_TYPE_LE, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2466 "y.tab.c"
    break;

  case 130:
#line 413 "parser.y"
                                                        { (yyval.AST_node) = create_boolean_node(NODE_TYPE_GE, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2472 "y.tab.c"
    break;

  case 131:
#line 415 "parser.y"
                                                        { (yyval.AST_node) = create_boolean_node(NODE_TYPE_EQ, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2478 "y.tab.c"
    break;

  case 132:
#line 417 "parser.y"
                                                        { (yyval.AST_node) = create_boolean_node(NODE_TYPE_NE, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2484 "y.tab.c"
    break;

  case 133:
#line 419 "parser.y"
                                                        { (yyval.AST_node) = create_function_call_node((yyvsp[-2].AST_node), NULL); }
#line 2490 "y.tab.c"
    break;

  case 134:
#line 421 "parser.y"
                                                        { (yyval.AST_node) = create_function_call_node((yyvsp[-3].AST_node), (yyvsp[-1].AST_node)); arg_list_head = NULL; arg_list_tail = NULL; }
#line 2496 "y.tab.c"
    break;

  case 135:
#line 423 "parser.y"
                                                        { (yyval.AST_node) = assign_type_num_node((yyvsp[0].AST_node)); }
#line 2502 "y.tab.c"
    break;

  case 136:
#line 425 "parser.y"
                                                        { (yyval.AST_node) = assign_type_str_node((yyvsp[0].AST_node)); }
#line 2508 "y.tab.c"
    break;

  case 137:
#line 427 "parser.y"
                                                        { (yyvsp[0].AST_node) = create_id_node((yyvsp[0].AST_node)); (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2514 "y.tab.c"
    break;

  case 138:
#line 429 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[-1].AST_node); }
#line 2520 "y.tab.c"
    break;

  case 139:
#line 431 "parser.y"
                                                        { (yyval.AST_node) = create_array_node((yyvsp[-3].AST_node), (yyvsp[-1].AST_node)); }
#line 2526 "y.tab.c"
    break;

  case 140:
#line 433 "parser.y"
                                                        { (yyval.AST_node) = create_ref_node((yyvsp[0].AST_node)); }
#line 2532 "y.tab.c"
    break;

  case 141:
#line 435 "parser.y"
                                                        { (yyval.AST_node) = create_deref_node((yyvsp[0].AST_node)); }
#line 2538 "y.tab.c"
    break;

  case 142:
#line 437 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2544 "y.tab.c"
    break;

  case 143:
#line 439 "parser.y"
                                                        { union Constant value; (yyval.AST_node) = create_ast_node(NODE_TYPE_NULL, NULL, value); (yyval.AST_node)->type = default_types->int_type; }
#line 2550 "y.tab.c"
    break;

  case 144:
#line 441 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2556 "y.tab.c"
    break;

  case 145:
#line 445 "parser.y"
                                                        { (yyval.AST_node) = extend_tuple_node((yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2562 "y.tab.c"
    break;

  case 146:
#line 446 "parser.y"
                                                        { (yyval.AST_node) = create_tuple_node((yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2568 "y.tab.c"
    break;

  case 147:
#line 447 "parser.y"
                                                        { (yyval.AST_node) = create_tuple_array_node((yyvsp[-5].AST_node), (yyvsp[-3].AST_node), (yyvsp[0].AST_node)); }
#line 2574 "y.tab.c"
    break;

  case 148:
#line 448 "parser.y"
                                                        { (yyval.AST_node) = create_tuple_node((yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2580 "y.tab.c"
    break;

  case 149:
#line 451 "parser.y"
                                                        { (yyval.AST_node) = append_arg_list((yyval.AST_node), (yyvsp[0].AST_node)); }
#line 2586 "y.tab.c"
    break;

  case 150:
#line 452 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2592 "y.tab.c"
    break;

  case 151:
#line 456 "parser.y"
                                        { (yyval.AST_node) = create_class_function_call_node(create_self_node(current_class), (yyvsp[-3].AST_node), (yyvsp[-1].AST_node)); }
#line 2598 "y.tab.c"
    break;

  case 152:
#line 457 "parser.y"
                                        { (yyvsp[-5].AST_node) = create_id_node((yyvsp[-5].AST_node)); (yyval.AST_node) = create_class_function_call_node((yyvsp[-5].AST_node), (yyvsp[-3].AST_node), (yyvsp[-1].AST_node)); }
#line 2604 "y.tab.c"
    break;

  case 153:
#line 458 "parser.y"
                                        { (yyval.AST_node) = create_class_function_call_node((yyvsp[-5].AST_node), (yyvsp[-3].AST_node), (yyvsp[-1].AST_node)); }
#line 2610 "y.tab.c"
    break;


#line 2614 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 461 "parser.y"


void yyerror(const char* error) {
    fprintf(stderr, "\nSyntax error at line %d: %s\n", yylineno, error);

    if (yytext && *yytext) {
        fprintf(stderr, "    Offending token: '%s'\n", yytext);
    }

    // If yychar is defined, print its numeric ID too (optional)
    if (yychar != YYEMPTY) {
        fprintf(stderr, "    Token code: %d\n", yychar);
    }

    exit(1);
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
