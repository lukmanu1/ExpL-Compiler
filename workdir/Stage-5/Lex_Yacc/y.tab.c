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

    table_type* type_variable = NULL;
    table_type* type_function = NULL;

    // void makeExecutableFile(struct tnode* node, FILE* fptr);
    extern FILE* yyin;
    extern p_node* param_head;
    extern p_node* param_tail;
    extern lst_node* lst_head;  
    extern lst_node* lst_tail;
    extern ast_node* arg_list_head;
    extern ast_node* arg_list_tail;
    extern int lst_binding;
    

#line 94 "y.tab.c"

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
    PBEGIN = 258,
    END = 259,
    READ = 260,
    WRITE = 261,
    IF = 262,
    ELSE = 263,
    THEN = 264,
    ENDIF = 265,
    WHILE = 266,
    DO = 267,
    REPEAT = 268,
    UNTIL = 269,
    BREAK = 270,
    CONTINUE = 271,
    EQUAL = 272,
    LT = 273,
    GT = 274,
    LE = 275,
    GE = 276,
    NOT = 277,
    NE = 278,
    EQ = 279,
    AND = 280,
    DECL = 281,
    ENDDECL = 282,
    INT = 283,
    STR = 284,
    MAIN = 285,
    RETURN = 286,
    TUPLE = 287,
    TYPE = 288,
    ENDTYPE = 289,
    NUM = 290,
    ID = 291,
    STRING_LITERAL = 292
  };
#endif
/* Tokens.  */
#define PBEGIN 258
#define END 259
#define READ 260
#define WRITE 261
#define IF 262
#define ELSE 263
#define THEN 264
#define ENDIF 265
#define WHILE 266
#define DO 267
#define REPEAT 268
#define UNTIL 269
#define BREAK 270
#define CONTINUE 271
#define EQUAL 272
#define LT 273
#define GT 274
#define LE 275
#define GE 276
#define NOT 277
#define NE 278
#define EQ 279
#define AND 280
#define DECL 281
#define ENDDECL 282
#define INT 283
#define STR 284
#define MAIN 285
#define RETURN 286
#define TUPLE 287
#define TYPE 288
#define ENDTYPE 289
#define NUM 290
#define ID 291
#define STRING_LITERAL 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "parser.y"

    ast_node* AST_node;
    gst_node* GST_node;
    lst_node* LST_node;
    p_node* param_node;
    field* field_node;

#line 228 "y.tab.c"

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   533

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  257

#define YYUNDEFTOK  2
#define YYMAXUTOK   292


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
       2,     2,     2,     2,     2,     2,     2,    42,     2,     2,
      49,    50,    40,    38,    46,    39,    51,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    45,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    60,    61,    62,    65,    66,    69,    70,
      73,    74,    78,    79,    82,    83,    86,    89,    90,    93,
      94,    95,    96,   107,   108,   112,   112,   115,   115,   120,
     121,   122,   125,   126,   127,   128,   131,   132,   135,   136,
     139,   143,   150,   152,   159,   164,   165,   166,   174,   174,
     179,   186,   190,   191,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   209,   214,   219,   227,   234,   240,
     245,   250,   258,   259,   264,   268,   272,   276,   280,   283,
     284,   286,   288,   290,   292,   294,   296,   298,   300,   302,
     304,   306,   308,   310,   312,   314,   316,   318,   320,   322,
     324,   326,   330,   331
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PBEGIN", "END", "READ", "WRITE", "IF",
  "ELSE", "THEN", "ENDIF", "WHILE", "DO", "REPEAT", "UNTIL", "BREAK",
  "CONTINUE", "EQUAL", "LT", "GT", "LE", "GE", "NOT", "NE", "EQ", "AND",
  "DECL", "ENDDECL", "INT", "STR", "MAIN", "RETURN", "TUPLE", "TYPE",
  "ENDTYPE", "NUM", "ID", "STRING_LITERAL", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'{'", "'}'", "';'", "','", "'['", "']'", "'('", "')'", "'.'",
  "$accept", "Program", "TypeDecl", "FieldList", "Field", "GDeclBlock",
  "GDeclList", "GDecl", "GidList", "Gid", "FDefBlock", "Fdef", "$@1",
  "$@2", "ParamList", "Param", "LdeclBlock", "LDecList", "LDecl", "IdList",
  "Type", "MainBlock", "$@3", "Body", "Slist", "Stmt", "InputStmt",
  "OutputStmt", "AsgStmt", "IfStmt", "whileStmt", "doWhileStmt",
  "repeatStmt", "breakStmt", "continueStmt", "returnStmt", "E", "ArgList", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,    43,    45,
      42,    47,    37,   123,   125,    59,    44,    91,    93,    40,
      41,    46
};
# endif

#define YYPACT_NINF (-134)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      49,     5,    67,     9,   161,  -134,   -43,  -134,    35,  -134,
      58,   200,  -134,    13,   203,  -134,  -134,  -134,    47,    70,
    -134,    34,   -25,    56,   200,  -134,  -134,    77,    91,    94,
     -21,    88,    96,  -134,  -134,   130,   117,   188,  -134,   129,
     159,  -134,  -134,   190,  -134,  -134,   125,   180,  -134,   223,
     205,   223,  -134,  -134,    34,   223,   223,   156,  -134,  -134,
    -134,    83,    92,   -34,  -134,   197,   114,  -134,   151,   167,
    -134,   192,  -134,    99,   250,  -134,   221,  -134,   229,   223,
    -134,  -134,  -134,   225,   226,  -134,  -134,  -134,   230,   215,
     150,   228,  -134,  -134,  -134,   190,   190,  -134,  -134,   110,
     237,   224,   235,   236,   238,   227,   249,   241,   260,    89,
     -14,   281,   187,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,   285,  -134,
     286,   133,   133,   133,   243,   243,  -134,  -134,   287,  -134,
     -13,  -134,   288,  -134,   133,     1,   133,   133,   289,   313,
     261,  -134,   250,   250,  -134,   124,   257,   270,   295,    60,
     100,  -134,   133,    44,   302,  -134,   308,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,  -134,   419,
     371,   322,   133,  -134,   296,   297,   133,   298,   306,   299,
     350,   312,   349,   347,   382,  -134,   491,   176,  -134,  -134,
     262,   262,   262,   262,   262,   262,    20,    20,  -134,  -134,
    -134,  -134,   345,   133,   447,  -134,  -134,   408,  -134,   318,
    -134,   243,   243,   314,   327,  -134,   133,  -134,   133,   455,
    -134,   328,   332,   199,   136,   133,   133,   491,   483,  -134,
     334,  -134,   243,   335,  -134,   333,   346,  -134,  -134,   231,
    -134,   336,   337,   348,  -134,  -134,  -134
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     5,     0,     7,     0,     1,
       0,     0,     4,     0,     0,    13,    45,    46,     0,     0,
      15,     0,     0,     0,     0,    24,     3,     0,     0,     0,
       0,     0,     0,    12,    14,    19,     0,     0,    18,     0,
       0,    23,     2,     0,    10,    11,     0,     0,     9,    31,
       0,    31,    22,    16,     0,    31,    31,     0,    48,     6,
       8,     0,     0,     0,    30,     0,     0,    17,     0,     0,
      37,     0,    39,     0,     0,    34,     0,    35,     0,     0,
      47,    20,    21,     0,     0,    36,    38,    44,     0,     0,
       0,     0,    32,    33,    29,     0,     0,    43,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    49,    25,    27,    42,     0,    51,
       0,     0,     0,     0,     0,     0,    77,    78,     0,    94,
      96,    95,     0,    80,     0,     0,     0,     0,     0,     0,
       0,    52,     0,     0,    41,     0,     0,     0,     0,     0,
       0,    99,     0,     0,     0,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,   103,     0,   101,    97,
      86,    87,    88,    89,    91,    90,    81,    82,    83,    84,
      85,    68,     0,     0,     0,    26,    28,     0,    64,     0,
      67,     0,     0,     0,     0,    98,     0,    93,     0,     0,
      70,     0,     0,     0,     0,     0,     0,   102,     0,    71,
       0,    66,     0,     0,    74,     0,     0,    69,    65,     0,
      73,     0,     0,     0,    75,    76,    72
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,  -134,  -134,   367,  -134,  -134,   379,  -134,   353,
    -134,   375,  -134,  -134,   -24,   325,   168,  -134,   343,  -134,
     -53,     6,  -134,    43,  -133,  -112,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,  -118,  -134
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    30,    31,    11,    19,    20,    37,    38,
      24,    25,   152,   153,    63,    64,    58,    71,    72,    89,
      21,     5,    74,    91,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   145,   197
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     151,   159,   160,   146,    73,     6,    13,    28,    29,     9,
      12,    39,    79,   156,   157,   158,    80,    26,    73,   167,
     168,   169,   170,    46,   171,   172,   166,    66,   179,   180,
      42,    68,    69,   147,   162,     6,   163,   148,   164,   173,
     174,   175,   176,   177,   194,   196,   178,   151,   151,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     175,   176,   177,    27,   214,   101,   102,   103,   217,   138,
      35,   104,   105,   106,    36,   107,   108,     1,    14,   139,
     140,   141,     2,    32,   142,    15,    16,    17,   233,   234,
      18,   109,    40,   144,   195,   229,   110,    33,    16,    17,
     111,     7,    18,     8,   192,   101,   102,   103,   237,   249,
     238,   104,   105,   106,   138,   107,   108,   245,   246,    75,
      43,   151,   151,    76,   139,   140,   141,    44,    77,   142,
      45,   109,    78,    48,   143,    87,   110,   151,   144,    88,
     111,   101,   102,   103,   193,    49,   127,   104,   105,   106,
     128,   107,   108,    52,   100,   101,   102,   103,   138,    59,
      79,   104,   105,   106,    82,   107,   108,   109,   139,   140,
     141,   186,   110,   142,   187,   188,   111,    50,    55,    51,
     244,   109,   144,    70,    16,    17,   110,    10,    18,     1,
     111,   150,   101,   102,   103,   184,   185,    79,   104,   105,
     106,    83,   107,   108,   101,   102,   103,   242,    56,   243,
     104,   105,   106,    79,   107,   108,    57,    84,   109,    85,
      16,    17,   226,   110,    18,    60,   227,   111,    22,    23,
     109,    28,    29,    53,    54,   110,   101,   102,   103,   111,
      65,   253,   104,   105,   106,    81,   107,   108,   101,   102,
     103,    61,    62,    90,   104,   105,   106,    92,   107,   108,
      98,    99,   109,   125,   126,    93,    97,   110,    95,    96,
     134,   111,   124,   130,   109,   167,   168,   169,   170,   110,
     171,   172,   129,   111,   131,   132,   136,   133,   167,   168,
     169,   170,   135,   171,   172,   173,   174,   175,   176,   177,
     173,   174,   175,   176,   177,   137,   183,   189,   173,   174,
     175,   176,   177,   167,   168,   169,   170,   149,   171,   172,
     190,   154,   155,   161,   165,   181,   167,   168,   169,   170,
     182,   171,   172,   173,   174,   175,   176,   177,   198,   213,
     215,   216,   219,   218,   220,   191,   173,   174,   175,   176,
     177,   167,   168,   169,   170,   222,   171,   172,   199,   221,
     223,   224,   228,   235,   167,   168,   169,   170,   232,   171,
     172,   173,   174,   175,   176,   177,   236,   241,   240,   248,
     250,   254,   255,   251,   173,   174,   175,   176,   177,   167,
     168,   169,   170,   256,   171,   172,   252,    47,    34,    41,
     167,   168,   169,   170,    94,   171,   172,    67,     0,   173,
     174,   175,   176,   177,    86,     0,     0,     0,     0,   212,
     173,   174,   175,   176,   177,     0,   167,   168,   169,   170,
     225,   171,   172,     0,     0,     0,     0,   167,   168,   169,
     170,     0,   171,   172,     0,     0,   173,   174,   175,   176,
     177,     0,     0,     0,     0,     0,   231,   173,   174,   175,
     176,   177,     0,     0,   211,   167,   168,   169,   170,     0,
     171,   172,     0,   167,   168,   169,   170,     0,   171,   172,
       0,     0,     0,     0,     0,   173,   174,   175,   176,   177,
       0,     0,   230,   173,   174,   175,   176,   177,     0,     0,
     239,   167,   168,   169,   170,     0,   171,   172,     0,   167,
     168,   169,   170,     0,   171,   172,     0,     0,     0,     0,
       0,   173,   174,   175,   176,   177,     0,     0,   247,   173,
     174,   175,   176,   177
};

static const yytype_int16 yycheck[] =
{
     112,   134,   135,    17,    57,    30,    49,    28,    29,     0,
       4,    36,    46,   131,   132,   133,    50,    11,    71,    18,
      19,    20,    21,    44,    23,    24,   144,    51,   146,   147,
      24,    55,    56,    47,    47,    30,    49,    51,    51,    38,
      39,    40,    41,    42,   162,   163,    45,   159,   160,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
      40,    41,    42,    50,   182,     5,     6,     7,   186,    25,
      36,    11,    12,    13,    40,    15,    16,    28,    43,    35,
      36,    37,    33,    36,    40,    27,    28,    29,   221,   222,
      32,    31,    36,    49,    50,   213,    36,    27,    28,    29,
      40,    34,    32,    36,    44,     5,     6,     7,   226,   242,
     228,    11,    12,    13,    25,    15,    16,   235,   236,    36,
      43,   233,   234,    40,    35,    36,    37,    36,    36,    40,
      36,    31,    40,    45,    45,    36,    36,   249,    49,    40,
      40,     5,     6,     7,    44,    49,    36,    11,    12,    13,
      40,    15,    16,    36,     4,     5,     6,     7,    25,    34,
      46,    11,    12,    13,    50,    15,    16,    31,    35,    36,
      37,    47,    36,    40,    50,    51,    40,    47,    49,    49,
      44,    31,    49,    27,    28,    29,    36,    26,    32,    28,
      40,     4,     5,     6,     7,   152,   153,    46,    11,    12,
      13,    50,    15,    16,     5,     6,     7,     8,    49,    10,
      11,    12,    13,    46,    15,    16,    26,    50,    31,    27,
      28,    29,    46,    36,    32,    45,    50,    40,    28,    29,
      31,    28,    29,    45,    46,    36,     5,     6,     7,    40,
      35,    10,    11,    12,    13,    48,    15,    16,     5,     6,
       7,    28,    29,     3,    11,    12,    13,    36,    15,    16,
      45,    46,    31,    95,    96,    36,    36,    36,    43,    43,
      43,    40,    44,    49,    31,    18,    19,    20,    21,    36,
      23,    24,    45,    40,    49,    49,    45,    49,    18,    19,
      20,    21,    43,    23,    24,    38,    39,    40,    41,    42,
      38,    39,    40,    41,    42,    45,    45,    50,    38,    39,
      40,    41,    42,    18,    19,    20,    21,    36,    23,    24,
      50,    36,    36,    36,    36,    36,    18,    19,    20,    21,
      17,    23,    24,    38,    39,    40,    41,    42,    36,    17,
      44,    44,    36,    45,    45,    50,    38,    39,    40,    41,
      42,    18,    19,    20,    21,    43,    23,    24,    50,     9,
      11,    14,    17,    49,    18,    19,    20,    21,    50,    23,
      24,    38,    39,    40,    41,    42,    49,    45,    50,    45,
      45,    45,    45,    50,    38,    39,    40,    41,    42,    18,
      19,    20,    21,    45,    23,    24,    50,    30,    19,    24,
      18,    19,    20,    21,    79,    23,    24,    54,    -1,    38,
      39,    40,    41,    42,    71,    -1,    -1,    -1,    -1,    48,
      38,    39,    40,    41,    42,    -1,    18,    19,    20,    21,
      48,    23,    24,    -1,    -1,    -1,    -1,    18,    19,    20,
      21,    -1,    23,    24,    -1,    -1,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    48,    38,    39,    40,
      41,    42,    -1,    -1,    45,    18,    19,    20,    21,    -1,
      23,    24,    -1,    18,    19,    20,    21,    -1,    23,    24,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      -1,    -1,    45,    38,    39,    40,    41,    42,    -1,    -1,
      45,    18,    19,    20,    21,    -1,    23,    24,    -1,    18,
      19,    20,    21,    -1,    23,    24,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    -1,    -1,    45,    38,
      39,    40,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    28,    33,    53,    54,    73,    30,    34,    36,     0,
      26,    57,    73,    49,    43,    27,    28,    29,    32,    58,
      59,    72,    28,    29,    62,    63,    73,    50,    28,    29,
      55,    56,    36,    27,    59,    36,    40,    60,    61,    36,
      36,    63,    73,    43,    36,    36,    44,    56,    45,    49,
      47,    49,    36,    45,    46,    49,    49,    26,    68,    34,
      45,    28,    29,    66,    67,    35,    66,    61,    66,    66,
      27,    69,    70,    72,    74,    36,    40,    36,    40,    46,
      50,    48,    50,    50,    50,    27,    70,    36,    40,    71,
       3,    75,    36,    36,    67,    43,    43,    36,    45,    46,
       4,     5,     6,     7,    11,    12,    13,    15,    16,    31,
      36,    40,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    44,    68,    68,    36,    40,    45,
      49,    49,    49,    49,    43,    43,    45,    45,    25,    35,
      36,    37,    40,    45,    49,    88,    17,    47,    51,    36,
       4,    77,    64,    65,    36,    36,    88,    88,    88,    76,
      76,    36,    47,    49,    51,    36,    88,    18,    19,    20,
      21,    23,    24,    38,    39,    40,    41,    42,    45,    88,
      88,    36,    17,    45,    75,    75,    47,    50,    51,    50,
      50,    50,    44,    44,    88,    50,    88,    89,    36,    50,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    45,    48,    17,    88,    44,    44,    88,    45,    36,
      45,     9,    43,    11,    14,    48,    46,    50,    17,    88,
      45,    48,    50,    76,    76,    49,    49,    88,    88,    45,
      50,    45,     8,    10,    44,    88,    88,    45,    45,    76,
      45,    50,    50,    10,    45,    45,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    53,    53,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    59,    60,    60,    61,
      61,    61,    61,    62,    62,    64,    63,    65,    63,    66,
      66,    66,    67,    67,    67,    67,    68,    68,    69,    69,
      70,    71,    71,    71,    71,    72,    72,    72,    74,    73,
      75,    75,    76,    76,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    79,    80,    80,
      80,    80,    81,    81,    82,    83,    84,    85,    86,    87,
      87,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    89,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     1,     6,     2,     3,     2,
       2,     2,     3,     2,     2,     1,     3,     3,     1,     1,
       4,     4,     2,     2,     1,     0,    10,     0,    10,     3,
       1,     0,     3,     3,     2,     2,     3,     2,     2,     1,
       3,     4,     3,     2,     1,     1,     1,     5,     0,     9,
       4,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     8,     7,     5,     4,     7,
       5,     6,    10,     8,     7,     9,     9,     2,     2,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     1,     1,     1,     3,     4,     2,
       2,     3,     3,     1
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
  case 2:
#line 59 "parser.y"
                                                                 { }
#line 1626 "y.tab.c"
    break;

  case 3:
#line 60 "parser.y"
                                                                 { }
#line 1632 "y.tab.c"
    break;

  case 4:
#line 61 "parser.y"
                                                                 { }
#line 1638 "y.tab.c"
    break;

  case 6:
#line 65 "parser.y"
                                                        { type_table_install((yyvsp[-4].AST_node)->name, (yyvsp[-2].field_node)); }
#line 1644 "y.tab.c"
    break;

  case 7:
#line 66 "parser.y"
                                                        { }
#line 1650 "y.tab.c"
    break;

  case 8:
#line 69 "parser.y"
                                                           { (yyval.field_node) = append_field((yyvsp[-2].field_node), (yyvsp[-1].field_node)); }
#line 1656 "y.tab.c"
    break;

  case 9:
#line 70 "parser.y"
                                                           { (yyval.field_node) = (yyvsp[-1].field_node); }
#line 1662 "y.tab.c"
    break;

  case 10:
#line 73 "parser.y"
                                                        { (yyval.field_node) = create_field_node((yyvsp[0].AST_node)->name, default_types->int_type); }
#line 1668 "y.tab.c"
    break;

  case 11:
#line 74 "parser.y"
                                                        { (yyval.field_node) = create_field_node((yyvsp[0].AST_node)->name, default_types->str_type); }
#line 1674 "y.tab.c"
    break;

  case 12:
#line 78 "parser.y"
                                                        {  print_gstable(); }
#line 1680 "y.tab.c"
    break;

  case 19:
#line 93 "parser.y"
                                                        { gst_install((yyvsp[0].AST_node)->name, type_variable, type_variable->size, 0, NULL); }
#line 1686 "y.tab.c"
    break;

  case 20:
#line 94 "parser.y"
                                                        { gst_install((yyvsp[-3].AST_node)->name, type_variable, type_variable->size, (yyvsp[-1].AST_node)->value.iVal, NULL); }
#line 1692 "y.tab.c"
    break;

  case 21:
#line 95 "parser.y"
                                                        { gst_install((yyvsp[-3].AST_node)->name, type_variable, 0, 0, (yyvsp[-1].param_node)); }
#line 1698 "y.tab.c"
    break;

  case 22:
#line 97 "parser.y"
                                                        { 
                                                            if(strcmp(type_variable->name, default_types->int_type->name) == 0){
                                                                gst_install((yyvsp[0].AST_node)->name, default_types->int_ptr_type, 1, 0, NULL);
                                                            }else{
                                                                gst_install((yyvsp[0].AST_node)->name, default_types->str_ptr_type, 1, 0, NULL);
                                                            }
                                                        }
#line 1710 "y.tab.c"
    break;

  case 23:
#line 107 "parser.y"
                                                        { create_connector_node((yyvsp[-1].AST_node), (yyvsp[0].AST_node)); }
#line 1716 "y.tab.c"
    break;

  case 24:
#line 108 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 1722 "y.tab.c"
    break;

  case 25:
#line 112 "parser.y"
                                                        { type_function = default_types->int_type; lst_binding = -2; code_gen_function_definition(outputFile, (yyvsp[-5].AST_node)); add_param_list_to_lst((yyvsp[-3].param_node)); lst_binding = 1; lst_display(); }
#line 1728 "y.tab.c"
    break;

  case 26:
#line 113 "parser.y"
                                                        { (yyval.AST_node) = create_function_definition_node(default_types->int_type, (yyvsp[-8].AST_node), (yyvsp[-6].param_node), (yyvsp[-1].AST_node)); lst_head = lst_tail = NULL; codeGen(outputFile, (yyvsp[-1].AST_node)); code_gen_exit_function(outputFile); }
#line 1734 "y.tab.c"
    break;

  case 27:
#line 115 "parser.y"
                                                        { type_function = default_types->str_type; lst_binding = -2; code_gen_function_definition(outputFile, (yyvsp[-5].AST_node)); add_param_list_to_lst((yyvsp[-3].param_node)); lst_binding = 1; lst_display(); }
#line 1740 "y.tab.c"
    break;

  case 28:
#line 116 "parser.y"
                                                        { (yyval.AST_node) = create_function_definition_node(default_types->str_type, (yyvsp[-8].AST_node), (yyvsp[-6].param_node), (yyvsp[-1].AST_node)); lst_head = lst_tail = NULL; codeGen(outputFile, (yyvsp[-1].AST_node)); code_gen_exit_function(outputFile); }
#line 1746 "y.tab.c"
    break;

  case 29:
#line 120 "parser.y"
                                                        { (yyval.param_node) = append_param((yyval.param_node), (yyvsp[0].param_node)); }
#line 1752 "y.tab.c"
    break;

  case 30:
#line 121 "parser.y"
                                                        { (yyval.param_node) = (yyvsp[0].param_node); }
#line 1758 "y.tab.c"
    break;

  case 31:
#line 122 "parser.y"
                                                        { (yyval.param_node) = NULL; }
#line 1764 "y.tab.c"
    break;

  case 32:
#line 125 "parser.y"
                                                       { (yyval.param_node) = create_p_node((yyvsp[0].AST_node)->name, default_types->int_ptr_type); }
#line 1770 "y.tab.c"
    break;

  case 33:
#line 126 "parser.y"
                                                       { (yyval.param_node) = create_p_node((yyvsp[0].AST_node)->name, default_types->str_ptr_type); }
#line 1776 "y.tab.c"
    break;

  case 34:
#line 127 "parser.y"
                                                       { (yyval.param_node) = create_p_node((yyvsp[0].AST_node)->name, default_types->int_type); }
#line 1782 "y.tab.c"
    break;

  case 35:
#line 128 "parser.y"
                                                       { (yyval.param_node) = create_p_node((yyvsp[0].AST_node)->name, default_types->str_type); }
#line 1788 "y.tab.c"
    break;

  case 36:
#line 131 "parser.y"
                                                        { (yyval.LST_node) = lst_head; }
#line 1794 "y.tab.c"
    break;

  case 37:
#line 132 "parser.y"
                                                        { }
#line 1800 "y.tab.c"
    break;

  case 38:
#line 135 "parser.y"
                                                        {  }
#line 1806 "y.tab.c"
    break;

  case 39:
#line 136 "parser.y"
                                                        {  }
#line 1812 "y.tab.c"
    break;

  case 41:
#line 144 "parser.y"
                                                        {
                                                            if(strcmp(type_variable->name, default_types->int_type->name) == 0)
                                                                lst_install((yyvsp[0].AST_node)->name, default_types->int_ptr_type);
                                                            else
                                                                lst_install((yyvsp[0].AST_node)->name, default_types->str_ptr_type);
                                                        }
#line 1823 "y.tab.c"
    break;

  case 42:
#line 151 "parser.y"
                                                        { lst_install((yyvsp[0].AST_node)->name, type_variable); }
#line 1829 "y.tab.c"
    break;

  case 43:
#line 153 "parser.y"
                                                        {
                                                            if(strcmp(type_variable->name, default_types->int_type->name) == 0)
                                                                lst_install((yyvsp[0].AST_node)->name, default_types->int_ptr_type);
                                                            else
                                                                lst_install((yyvsp[0].AST_node)->name, default_types->str_ptr_type);
                                                        }
#line 1840 "y.tab.c"
    break;

  case 44:
#line 160 "parser.y"
                                                        { lst_install((yyvsp[0].AST_node)->name, type_variable); }
#line 1846 "y.tab.c"
    break;

  case 45:
#line 164 "parser.y"
                                                        { type_variable = default_types->int_type; }
#line 1852 "y.tab.c"
    break;

  case 46:
#line 165 "parser.y"
                                                        { type_variable = default_types->str_type; }
#line 1858 "y.tab.c"
    break;

  case 47:
#line 166 "parser.y"
                                                        {
                                                            validate_type((yyvsp[-3].AST_node)->name, (yyvsp[-1].param_node)); 
                                                            type_variable = tLookup((yyvsp[-3].AST_node)->name);   /* Important! */
                                                        }
#line 1867 "y.tab.c"
    break;

  case 48:
#line 174 "parser.y"
                                                        { type_function = default_types->int_type; lst_display(); }
#line 1873 "y.tab.c"
    break;

  case 49:
#line 175 "parser.y"
                                                        { code_gen_main_function(outputFile); codeGen(outputFile, (yyvsp[-1].AST_node)); lst_head = lst_tail = NULL; }
#line 1879 "y.tab.c"
    break;

  case 50:
#line 180 "parser.y"
        {
            // inorder($2);
            // makeExecutableFile( $2, outputFile);
            // // evaluate($2);
            (yyval.AST_node) = (yyvsp[-2].AST_node);
        }
#line 1890 "y.tab.c"
    break;

  case 51:
#line 186 "parser.y"
                                                        { exit(0); }
#line 1896 "y.tab.c"
    break;

  case 52:
#line 190 "parser.y"
                                                        { (yyval.AST_node) = create_connector_node((yyvsp[-1].AST_node), (yyvsp[0].AST_node)); }
#line 1902 "y.tab.c"
    break;

  case 53:
#line 191 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 1908 "y.tab.c"
    break;

  case 54:
#line 196 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 1914 "y.tab.c"
    break;

  case 55:
#line 197 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 1920 "y.tab.c"
    break;

  case 56:
#line 198 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 1926 "y.tab.c"
    break;

  case 57:
#line 199 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 1932 "y.tab.c"
    break;

  case 58:
#line 200 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 1938 "y.tab.c"
    break;

  case 59:
#line 201 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 1944 "y.tab.c"
    break;

  case 60:
#line 202 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 1950 "y.tab.c"
    break;

  case 61:
#line 203 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 1956 "y.tab.c"
    break;

  case 62:
#line 204 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 1962 "y.tab.c"
    break;

  case 63:
#line 205 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 1968 "y.tab.c"
    break;

  case 64:
#line 210 "parser.y"
        {
            (yyvsp[-2].AST_node) = create_id_node((yyvsp[-2].AST_node));
            (yyval.AST_node) = create_read_node((yyvsp[-2].AST_node));
        }
#line 1977 "y.tab.c"
    break;

  case 65:
#line 215 "parser.y"
        {
            ast_node* array_node = create_array_node((yyvsp[-5].AST_node), (yyvsp[-3].AST_node));
            (yyval.AST_node) = create_read_node(array_node);
        }
#line 1986 "y.tab.c"
    break;

  case 66:
#line 220 "parser.y"
        {
            ast_node* tuple_node = create_tuple_node((yyvsp[-4].AST_node), (yyvsp[-2].AST_node));
            (yyval.AST_node) = create_read_node(tuple_node);
        }
#line 1995 "y.tab.c"
    break;

  case 67:
#line 228 "parser.y"
        {
            (yyval.AST_node) = create_write_node((yyvsp[-2].AST_node));
        }
#line 2003 "y.tab.c"
    break;

  case 68:
#line 235 "parser.y"
        {
            (yyvsp[-3].AST_node) = create_id_node((yyvsp[-3].AST_node));
            (yyval.AST_node) = create_assign_node((yyvsp[-3].AST_node), (yyvsp[-1].AST_node));
        }
#line 2012 "y.tab.c"
    break;

  case 69:
#line 241 "parser.y"
        {
            ast_node* array_node = create_array_node((yyvsp[-6].AST_node), (yyvsp[-4].AST_node));
            (yyval.AST_node) = create_assign_node(array_node, (yyvsp[-1].AST_node));
        }
#line 2021 "y.tab.c"
    break;

  case 70:
#line 246 "parser.y"
        {
            ast_node* deref_node = create_deref_node((yyvsp[-3].AST_node));
            (yyval.AST_node) = create_assign_node(deref_node, (yyvsp[-1].AST_node));
        }
#line 2030 "y.tab.c"
    break;

  case 71:
#line 251 "parser.y"
        {
            ast_node* tuple_node = create_tuple_node((yyvsp[-5].AST_node), (yyvsp[-3].AST_node));
            (yyval.AST_node) = create_assign_node(tuple_node, (yyvsp[-1].AST_node));
        }
#line 2039 "y.tab.c"
    break;

  case 72:
#line 258 "parser.y"
                                                        { (yyval.AST_node) = create_if_else_node((yyvsp[-7].AST_node), (yyvsp[-4].AST_node), (yyvsp[-2].AST_node)); }
#line 2045 "y.tab.c"
    break;

  case 73:
#line 259 "parser.y"
                                                        { (yyval.AST_node) = create_if_node((yyvsp[-5].AST_node), (yyvsp[-2].AST_node)); }
#line 2051 "y.tab.c"
    break;

  case 74:
#line 264 "parser.y"
                                                        { (yyval.AST_node) = create_while_node((yyvsp[-4].AST_node), (yyvsp[-1].AST_node)); }
#line 2057 "y.tab.c"
    break;

  case 75:
#line 268 "parser.y"
                                                        { (yyval.AST_node) = create_do_while_node((yyvsp[-2].AST_node), (yyvsp[-6].AST_node)); }
#line 2063 "y.tab.c"
    break;

  case 76:
#line 272 "parser.y"
                                                        { (yyval.AST_node) = create_repeat_until_node((yyvsp[-2].AST_node), (yyvsp[-6].AST_node)); }
#line 2069 "y.tab.c"
    break;

  case 77:
#line 276 "parser.y"
                                                        { (yyval.AST_node) = create_break_node(); }
#line 2075 "y.tab.c"
    break;

  case 78:
#line 280 "parser.y"
                                                        { (yyval.AST_node) = create_continue_node(); }
#line 2081 "y.tab.c"
    break;

  case 79:
#line 283 "parser.y"
                                                         { (yyval.AST_node) = create_return_node(type_function, (yyvsp[-1].AST_node), (yyvsp[-1].AST_node)->type); }
#line 2087 "y.tab.c"
    break;

  case 80:
#line 284 "parser.y"
                                                         { (yyval.AST_node) = create_return_node(type_function, NULL, default_types->void_type);}
#line 2093 "y.tab.c"
    break;

  case 81:
#line 286 "parser.y"
                                                        { (yyval.AST_node) = create_operator_node(NODE_TYPE_PLUS, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2099 "y.tab.c"
    break;

  case 82:
#line 288 "parser.y"
                                                        { (yyval.AST_node) = create_operator_node(NODE_TYPE_MINUS, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2105 "y.tab.c"
    break;

  case 83:
#line 290 "parser.y"
                                                        { (yyval.AST_node) = create_operator_node(NODE_TYPE_MULT, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2111 "y.tab.c"
    break;

  case 84:
#line 292 "parser.y"
                                                        { (yyval.AST_node) = create_operator_node(NODE_TYPE_DIV, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2117 "y.tab.c"
    break;

  case 85:
#line 294 "parser.y"
                                                        { (yyval.AST_node) = create_operator_node(NODE_TYPE_MOD, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2123 "y.tab.c"
    break;

  case 86:
#line 296 "parser.y"
                                                        { (yyval.AST_node) = create_boolean_node(NODE_TYPE_LT, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2129 "y.tab.c"
    break;

  case 87:
#line 298 "parser.y"
                                                        { (yyval.AST_node) = create_boolean_node(NODE_TYPE_GT, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2135 "y.tab.c"
    break;

  case 88:
#line 300 "parser.y"
                                                        { (yyval.AST_node) = create_boolean_node(NODE_TYPE_LE, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2141 "y.tab.c"
    break;

  case 89:
#line 302 "parser.y"
                                                        { (yyval.AST_node) = create_boolean_node(NODE_TYPE_GE, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2147 "y.tab.c"
    break;

  case 90:
#line 304 "parser.y"
                                                        { (yyval.AST_node) = create_boolean_node(NODE_TYPE_EQ, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2153 "y.tab.c"
    break;

  case 91:
#line 306 "parser.y"
                                                        { (yyval.AST_node) = create_boolean_node(NODE_TYPE_NE, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2159 "y.tab.c"
    break;

  case 92:
#line 308 "parser.y"
                                                        { (yyval.AST_node) = create_function_call_node((yyvsp[-2].AST_node), NULL); }
#line 2165 "y.tab.c"
    break;

  case 93:
#line 310 "parser.y"
                                                        { (yyval.AST_node) = create_function_call_node((yyvsp[-3].AST_node), (yyvsp[-1].AST_node)); arg_list_head = NULL; arg_list_tail = NULL; }
#line 2171 "y.tab.c"
    break;

  case 94:
#line 312 "parser.y"
                                                        { (yyval.AST_node) = assign_type_num_node((yyvsp[0].AST_node)); }
#line 2177 "y.tab.c"
    break;

  case 95:
#line 314 "parser.y"
                                                        { (yyval.AST_node) = assign_type_str_node((yyvsp[0].AST_node)); }
#line 2183 "y.tab.c"
    break;

  case 96:
#line 316 "parser.y"
                                                        { (yyvsp[0].AST_node) = create_id_node((yyvsp[0].AST_node)); (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2189 "y.tab.c"
    break;

  case 97:
#line 318 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[-1].AST_node); }
#line 2195 "y.tab.c"
    break;

  case 98:
#line 320 "parser.y"
                                                        { (yyval.AST_node) = create_array_node((yyvsp[-3].AST_node), (yyvsp[-1].AST_node)); }
#line 2201 "y.tab.c"
    break;

  case 99:
#line 322 "parser.y"
                                                        { (yyval.AST_node) = create_ref_node((yyvsp[0].AST_node)); }
#line 2207 "y.tab.c"
    break;

  case 100:
#line 324 "parser.y"
                                                        { (yyval.AST_node) = create_deref_node((yyvsp[0].AST_node)); }
#line 2213 "y.tab.c"
    break;

  case 101:
#line 326 "parser.y"
                                                        { (yyval.AST_node) = create_tuple_node((yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2219 "y.tab.c"
    break;

  case 102:
#line 330 "parser.y"
                                                        { (yyval.AST_node) = append_arg_list((yyval.AST_node), (yyvsp[0].AST_node)); }
#line 2225 "y.tab.c"
    break;

  case 103:
#line 331 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2231 "y.tab.c"
    break;


#line 2235 "y.tab.c"

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
#line 334 "parser.y"


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
