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
    

#line 95 "y.tab.c"

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

#line 235 "y.tab.c"

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   629

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  287

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


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
       2,     2,     2,     2,     2,     2,     2,    45,     2,     2,
      52,    53,    43,    41,    49,    42,    54,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    61,    61,    62,    63,    64,    69,    72,    73,    76,
      76,    80,    81,    84,    87,    88,    91,    92,    95,    98,
      99,   102,   103,   104,   105,   116,   117,   121,   121,   124,
     124,   127,   127,   132,   133,   134,   137,   138,   139,   140,
     141,   144,   145,   148,   149,   152,   156,   163,   165,   172,
     177,   178,   179,   191,   191,   196,   203,   207,   208,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   231,   236,   241,   248,   255,   261,
     266,   271,   298,   299,   304,   308,   312,   316,   320,   323,
     324,   327,   329,   331,   333,   335,   337,   339,   341,   343,
     345,   347,   349,   351,   353,   355,   357,   359,   361,   363,
     365,   367,   369,   373,   374,   377,   378
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PBEGIN", "END", "READ", "WRITE", "FREE",
  "ALLOC", "INIT", "IF", "ELSE", "THEN", "ENDIF", "WHILE", "DO", "REPEAT",
  "UNTIL", "BREAK", "CONTINUE", "EQUAL", "LT", "GT", "LE", "GE", "NOT",
  "NE", "EQ", "AND", "DECL", "ENDDECL", "INT", "STR", "MAIN", "RETURN",
  "NULL_NODE", "TYPE", "ENDTYPE", "NUM", "ID", "STRING_LITERAL", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'{'", "'}'", "';'", "','", "'['", "']'",
  "'('", "')'", "'.'", "$accept", "Program", "TypeDefBlock", "TypeDefList",
  "TypeDef", "$@1", "FieldDeclList", "FieldDecl", "GDeclBlock",
  "GDeclList", "GDecl", "GidList", "Gid", "FDefBlock", "Fdef", "$@2",
  "$@3", "$@4", "ParamList", "Param", "LdeclBlock", "LDecList", "LDecl",
  "IdList", "Type", "MainBlock", "$@5", "Body", "Slist", "Stmt",
  "InputStmt", "OutputStmt", "AsgStmt", "IfStmt", "whileStmt",
  "doWhileStmt", "repeatStmt", "breakStmt", "continueStmt", "returnStmt",
  "E", "Field", "ArgList", YY_NULLPTR
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
     295,    43,    45,    42,    47,    37,   123,   125,    59,    44,
      91,    93,    40,    41,    46
};
# endif

#define YYPACT_NINF (-143)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -24,   -25,    36,    88,    64,  -143,    69,  -143,    16,  -143,
    -143,   -21,    18,  -143,    51,    80,  -143,  -143,  -143,  -143,
    -143,  -143,   -17,  -143,    55,    -4,    89,    96,    18,  -143,
    -143,   120,   100,  -143,  -143,    63,   130,    -5,  -143,    93,
     123,   126,  -143,  -143,   159,    52,  -143,   169,   160,   109,
    -143,  -143,    55,   109,   109,   109,    50,  -143,  -143,  -143,
     162,   168,    90,    99,   181,   107,  -143,  -143,   134,   146,
     147,  -143,    86,  -143,   118,   224,  -143,  -143,  -143,   191,
    -143,   193,  -143,   109,  -143,   203,   206,   208,  -143,  -143,
    -143,   227,   106,   219,   214,  -143,  -143,  -143,   159,   159,
     159,  -143,  -143,   178,   240,   218,   239,   248,   253,   276,
     283,   291,   292,   293,   294,   577,   -16,   300,   241,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
     -15,  -143,  -143,  -143,  -143,  -143,   304,  -143,   314,    62,
     318,   305,    62,    62,   297,   297,  -143,  -143,   320,  -143,
    -143,     4,  -143,   321,  -143,    62,   466,   307,    68,    62,
     327,   354,   329,  -143,    84,   336,   224,   224,   224,  -143,
      24,   188,   303,   225,   264,   330,   328,   341,   158,   175,
    -143,    62,   -12,  -143,   366,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,  -143,   324,   494,   417,
    -143,    62,  -143,   339,   502,  -143,   332,   333,   348,    62,
     349,   350,   351,   356,   364,  -143,   384,   367,   400,   398,
     429,  -143,   566,   190,  -143,   108,   108,   108,   108,   108,
     108,   238,   238,  -143,  -143,  -143,   363,  -143,   397,   530,
     365,  -143,  -143,  -143,  -143,   455,  -143,  -143,  -143,  -143,
    -143,   297,   297,   377,   381,  -143,    62,  -143,   386,    62,
    -143,   387,   383,   258,   197,    62,    62,   566,  -143,   538,
    -143,   389,   297,   394,  -143,   379,   404,  -143,  -143,   280,
    -143,   406,   415,   416,  -143,  -143,  -143
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     5,     0,     9,     0,     8,
       1,     0,     0,     4,     0,     0,     6,     7,    15,    50,
      51,    52,     0,    17,     0,     0,     0,     0,     0,    26,
       3,     0,     0,    14,    16,    21,     0,     0,    20,     0,
       0,     0,    25,     2,     0,     0,    12,     0,     0,    35,
      24,    18,     0,    35,    35,    35,     0,    53,    10,    11,
       0,     0,     0,     0,     0,     0,    34,    19,     0,     0,
       0,    42,     0,    44,     0,     0,    13,    22,    38,     0,
      39,     0,    40,     0,    23,     0,     0,     0,    41,    43,
      49,     0,     0,     0,     0,    36,    37,    33,     0,     0,
       0,    48,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    54,    27,    29,    31,    47,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    87,    88,     0,   112,
     104,   106,   105,     0,    90,     0,     0,   111,     0,     0,
       0,     0,     0,    57,     0,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,     0,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,     0,     0,     0,
     114,     0,    55,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,     0,     0,     0,     0,
       0,   102,   116,     0,   107,    96,    97,    98,    99,   101,
     100,    91,    92,    93,    94,    95,     0,    78,     0,     0,
       0,    81,    28,    30,    32,     0,    74,    76,    77,    71,
      72,     0,     0,     0,     0,   108,     0,   103,     0,     0,
      80,     0,     0,     0,     0,     0,     0,   115,    69,     0,
      70,     0,     0,     0,    84,     0,     0,    79,    75,     0,
      83,     0,     0,     0,    85,    86,    82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,  -143,  -143,   457,  -143,  -143,   421,  -143,  -143,
     445,  -143,   423,  -143,   441,  -143,  -143,  -143,   255,   401,
     222,  -143,   411,  -143,   -26,    20,  -143,   166,  -142,  -117,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -122,   -93,  -143
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     8,     9,    15,    45,    46,    12,    22,
      23,    37,    38,    28,    29,   166,   167,   168,    65,    66,
      57,    72,    73,    92,    24,     5,    75,    94,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     156,   157,   223
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     130,   163,   178,   179,   158,   164,    47,     1,     6,    18,
      19,    20,     2,    33,    19,    20,   148,   172,    21,    47,
     176,   177,    21,   149,    13,   130,   150,   151,   152,     6,
      74,   153,    30,   184,   159,    39,   198,   199,   160,   165,
     155,   221,   204,    51,    52,   171,    74,   174,    43,    25,
      26,   130,   130,    16,   181,     7,   182,    27,   160,   220,
     222,   163,   163,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   209,     7,   197,   210,   160,   239,
      71,    19,    20,    19,    20,   130,   130,   245,    10,    21,
     148,    21,   203,    11,    35,     1,   148,   149,    36,    58,
     150,   151,   152,   149,    31,   153,   150,   151,   152,   263,
     264,   153,   148,    48,   155,    49,    88,    19,    20,   149,
     155,    14,   150,   151,   152,    21,    32,   153,    40,    78,
     279,    19,    20,    79,   267,    41,   155,   269,    80,    21,
      62,    63,    81,   275,   276,    53,   163,   163,    64,   191,
     192,   193,   194,   195,   102,   103,    83,    90,   130,   130,
      84,    91,   163,   105,   106,   107,    44,   108,   109,    50,
     130,   130,   110,   111,   112,    54,   113,   114,    55,   130,
     105,   106,   107,    83,   108,   109,   130,    85,    56,   110,
     111,   112,   115,   113,   114,    83,    83,   116,    61,    86,
      87,   117,   105,   106,   107,   218,   108,   109,    60,   115,
      76,   110,   111,   112,   116,   113,   114,   135,   117,    77,
      82,   136,   219,   104,   105,   106,   107,    93,   108,   109,
      95,   115,    96,   110,   111,   112,   116,   113,   114,   256,
     117,   211,   165,   257,   274,   162,   105,   106,   107,    98,
     108,   109,    99,   115,   100,   110,   111,   112,   116,   113,
     114,   131,   117,   105,   106,   107,   101,   108,   109,   272,
     138,   273,   110,   111,   112,   115,   113,   114,   213,   160,
     116,   193,   194,   195,   117,   105,   106,   107,   137,   108,
     109,   139,   115,   283,   110,   111,   112,   116,   113,   114,
     140,   117,   105,   106,   107,   141,   108,   109,    68,    69,
      70,   110,   111,   112,   115,   113,   114,   214,   165,   116,
     132,   133,   134,   117,   185,   186,   187,   188,   142,   189,
     190,   115,   206,   207,   208,   143,   116,   144,   145,   161,
     117,   146,   147,   169,   191,   192,   193,   194,   195,   185,
     186,   187,   188,   170,   189,   190,   212,   173,   175,   180,
     183,   165,   185,   186,   187,   188,   200,   189,   190,   191,
     192,   193,   194,   195,   201,   205,   236,   202,   215,   242,
     243,   216,   191,   192,   193,   194,   195,   185,   186,   187,
     188,   240,   189,   190,   217,   244,   251,   246,   247,   248,
     185,   186,   187,   188,   249,   189,   190,   191,   192,   193,
     194,   195,   250,   252,   253,   254,   258,   259,   261,   224,
     191,   192,   193,   194,   195,   185,   186,   187,   188,   265,
     189,   190,   281,   266,   268,   270,   271,   278,   185,   186,
     187,   188,   280,   189,   190,   191,   192,   193,   194,   195,
     185,   186,   187,   188,   284,   189,   190,   282,   191,   192,
     193,   194,   195,   285,   286,    17,    59,    34,   238,    42,
     191,   192,   193,   194,   195,    67,   185,   186,   187,   188,
     255,   189,   190,    89,    97,     0,     0,   185,   186,   187,
     188,     0,   189,   190,     0,     0,   191,   192,   193,   194,
     195,     0,     0,     0,     0,     0,   262,   191,   192,   193,
     194,   195,     0,     0,   196,   185,   186,   187,   188,     0,
     189,   190,     0,   185,   186,   187,   188,     0,   189,   190,
       0,     0,     0,     0,     0,   191,   192,   193,   194,   195,
       0,     0,   237,   191,   192,   193,   194,   195,     0,     0,
     241,   185,   186,   187,   188,     0,   189,   190,     0,   185,
     186,   187,   188,     0,   189,   190,     0,     0,     0,     0,
       0,   191,   192,   193,   194,   195,     0,     0,   260,   191,
     192,   193,   194,   195,     0,     0,   277,   185,   186,   187,
     188,     0,   189,   190,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,     0,   191,   192,   193,
     194,   195,   149,     0,     0,   150,   151,   152,     0,     0,
     153,     0,     0,     0,     0,   154,     0,     0,     0,   155
};

static const yytype_int16 yycheck[] =
{
      93,   118,   144,   145,    20,    20,    32,    31,    33,    30,
      31,    32,    36,    30,    31,    32,    28,   139,    39,    45,
     142,   143,    39,    35,     4,   118,    38,    39,    40,    33,
      56,    43,    12,   155,    50,    39,   158,   159,    54,    54,
      52,    53,   164,    48,    49,   138,    72,   140,    28,    31,
      32,   144,   145,    37,    50,    39,    52,    39,    54,   181,
     182,   178,   179,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,    50,    39,     8,    53,    54,   201,
      30,    31,    32,    31,    32,   178,   179,   209,     0,    39,
      28,    39,     8,    29,    39,    31,    28,    35,    43,    47,
      38,    39,    40,    35,    53,    43,    38,    39,    40,   251,
     252,    43,    28,    50,    52,    52,    30,    31,    32,    35,
      52,    52,    38,    39,    40,    39,    46,    43,    39,    39,
     272,    31,    32,    43,   256,    39,    52,   259,    39,    39,
      31,    32,    43,   265,   266,    52,   263,   264,    39,    41,
      42,    43,    44,    45,    48,    49,    49,    39,   251,   252,
      53,    43,   279,     5,     6,     7,    46,     9,    10,    39,
     263,   264,    14,    15,    16,    52,    18,    19,    52,   272,
       5,     6,     7,    49,     9,    10,   279,    53,    29,    14,
      15,    16,    34,    18,    19,    49,    49,    39,    38,    53,
      53,    43,     5,     6,     7,    47,     9,    10,    39,    34,
      48,    14,    15,    16,    39,    18,    19,    39,    43,    51,
      39,    43,    47,     4,     5,     6,     7,     3,     9,    10,
      39,    34,    39,    14,    15,    16,    39,    18,    19,    49,
      43,    53,    54,    53,    47,     4,     5,     6,     7,    46,
       9,    10,    46,    34,    46,    14,    15,    16,    39,    18,
      19,    47,    43,     5,     6,     7,    39,     9,    10,    11,
      52,    13,    14,    15,    16,    34,    18,    19,    53,    54,
      39,    43,    44,    45,    43,     5,     6,     7,    48,     9,
      10,    52,    34,    13,    14,    15,    16,    39,    18,    19,
      52,    43,     5,     6,     7,    52,     9,    10,    53,    54,
      55,    14,    15,    16,    34,    18,    19,    53,    54,    39,
      98,    99,   100,    43,    21,    22,    23,    24,    52,    26,
      27,    34,   166,   167,   168,    52,    39,    46,    46,    39,
      43,    48,    48,    39,    41,    42,    43,    44,    45,    21,
      22,    23,    24,    39,    26,    27,    53,    39,    53,    39,
      39,    54,    21,    22,    23,    24,    39,    26,    27,    41,
      42,    43,    44,    45,    20,    39,    52,    48,    48,    47,
      47,    53,    41,    42,    43,    44,    45,    21,    22,    23,
      24,    52,    26,    27,    53,    47,    12,    48,    48,    48,
      21,    22,    23,    24,    48,    26,    27,    41,    42,    43,
      44,    45,    48,    46,    14,    17,    53,    20,    53,    53,
      41,    42,    43,    44,    45,    21,    22,    23,    24,    52,
      26,    27,    53,    52,    48,    48,    53,    48,    21,    22,
      23,    24,    48,    26,    27,    41,    42,    43,    44,    45,
      21,    22,    23,    24,    48,    26,    27,    53,    41,    42,
      43,    44,    45,    48,    48,     8,    45,    22,    51,    28,
      41,    42,    43,    44,    45,    52,    21,    22,    23,    24,
      51,    26,    27,    72,    83,    -1,    -1,    21,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    51,    41,    42,    43,
      44,    45,    -1,    -1,    48,    21,    22,    23,    24,    -1,
      26,    27,    -1,    21,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      -1,    -1,    48,    41,    42,    43,    44,    45,    -1,    -1,
      48,    21,    22,    23,    24,    -1,    26,    27,    -1,    21,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    -1,    -1,    48,    41,
      42,    43,    44,    45,    -1,    -1,    48,    21,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    41,    42,    43,
      44,    45,    35,    -1,    -1,    38,    39,    40,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    31,    36,    56,    57,    80,    33,    39,    58,    59,
       0,    29,    63,    80,    52,    60,    37,    59,    30,    31,
      32,    39,    64,    65,    79,    31,    32,    39,    68,    69,
      80,    53,    46,    30,    65,    39,    43,    66,    67,    39,
      39,    39,    69,    80,    46,    61,    62,    79,    50,    52,
      39,    48,    49,    52,    52,    52,    29,    75,    47,    62,
      39,    38,    31,    32,    39,    73,    74,    67,    73,    73,
      73,    30,    76,    77,    79,    81,    48,    51,    39,    43,
      39,    43,    39,    49,    53,    53,    53,    53,    30,    77,
      39,    43,    78,     3,    82,    39,    39,    74,    46,    46,
      46,    39,    48,    49,     4,     5,     6,     7,     9,    10,
      14,    15,    16,    18,    19,    34,    39,    43,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      96,    47,    75,    75,    75,    39,    43,    48,    52,    52,
      52,    52,    52,    52,    46,    46,    48,    48,    28,    35,
      38,    39,    40,    43,    48,    52,    95,    96,    20,    50,
      54,    39,     4,    84,    20,    54,    70,    71,    72,    39,
      39,    96,    95,    39,    96,    53,    95,    95,    83,    83,
      39,    50,    52,    39,    95,    21,    22,    23,    24,    26,
      27,    41,    42,    43,    44,    45,    48,     8,    95,    95,
      39,    20,    48,     8,    95,    39,    82,    82,    82,    50,
      53,    53,    53,    53,    53,    48,    53,    53,    47,    47,
      95,    53,    95,    97,    53,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    52,    48,    51,    95,
      52,    48,    47,    47,    47,    95,    48,    48,    48,    48,
      48,    12,    46,    14,    17,    51,    49,    53,    53,    20,
      48,    53,    51,    83,    83,    52,    52,    95,    48,    95,
      48,    53,    11,    13,    47,    95,    95,    48,    48,    83,
      48,    53,    53,    13,    48,    48,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    56,    56,    56,    57,    58,    58,    60,
      59,    61,    61,    62,    63,    63,    64,    64,    65,    66,
      66,    67,    67,    67,    67,    68,    68,    70,    69,    71,
      69,    72,    69,    73,    73,    73,    74,    74,    74,    74,
      74,    75,    75,    76,    76,    77,    78,    78,    78,    78,
      79,    79,    79,    81,    80,    82,    82,    83,    83,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    85,    85,    85,    86,    87,    87,
      87,    87,    88,    88,    89,    90,    91,    92,    93,    94,
      94,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    96,    96,    97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     1,     3,     2,     1,     0,
       5,     2,     1,     3,     3,     2,     2,     1,     3,     3,
       1,     1,     4,     4,     2,     2,     1,     0,    10,     0,
      10,     0,    10,     3,     1,     0,     3,     3,     2,     2,
       2,     3,     2,     2,     1,     3,     4,     3,     2,     1,
       1,     1,     1,     0,     9,     4,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     6,
       6,     5,     5,     4,     5,     8,     5,     5,     4,     7,
       5,     4,    10,     8,     7,     9,     9,     2,     2,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     1,     1,     1,     3,     4,     2,
       2,     1,     1,     3,     3,     3,     1
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
#line 61 "parser.y"
                                                                     { }
#line 1667 "y.tab.c"
    break;

  case 3:
#line 62 "parser.y"
                                                                     { }
#line 1673 "y.tab.c"
    break;

  case 4:
#line 63 "parser.y"
                                                                     { }
#line 1679 "y.tab.c"
    break;

  case 6:
#line 69 "parser.y"
                                                        {   }
#line 1685 "y.tab.c"
    break;

  case 7:
#line 72 "parser.y"
                                                        {   }
#line 1691 "y.tab.c"
    break;

  case 8:
#line 73 "parser.y"
                                                        {   }
#line 1697 "y.tab.c"
    break;

  case 9:
#line 76 "parser.y"
                                                        { type_table_install((yyvsp[0].AST_node)->name, NULL); }
#line 1703 "y.tab.c"
    break;

  case 10:
#line 77 "parser.y"
                                                        { table_type* new_type = tLookup((yyvsp[-4].AST_node)->name); new_type->fields = (yyvsp[-1].field_node); }
#line 1709 "y.tab.c"
    break;

  case 11:
#line 80 "parser.y"
                                                        { (yyval.field_node) = append_field((yyvsp[-1].field_node), (yyvsp[0].field_node)); }
#line 1715 "y.tab.c"
    break;

  case 12:
#line 81 "parser.y"
                                                        { (yyval.field_node) = (yyvsp[0].field_node); }
#line 1721 "y.tab.c"
    break;

  case 13:
#line 84 "parser.y"
                                                        { (yyval.field_node) = create_field_node((yyvsp[-1].AST_node)->name, type_variable); }
#line 1727 "y.tab.c"
    break;

  case 14:
#line 87 "parser.y"
                                                        {  print_gstable(); }
#line 1733 "y.tab.c"
    break;

  case 21:
#line 102 "parser.y"
                                                        { gst_install((yyvsp[0].AST_node)->name, type_variable, 1, 0, NULL); }
#line 1739 "y.tab.c"
    break;

  case 22:
#line 103 "parser.y"
                                                        { gst_install((yyvsp[-3].AST_node)->name, type_variable, 1, (yyvsp[-1].AST_node)->value.iVal, NULL); }
#line 1745 "y.tab.c"
    break;

  case 23:
#line 104 "parser.y"
                                                        { gst_install((yyvsp[-3].AST_node)->name, type_variable, 0, 0, (yyvsp[-1].param_node)); }
#line 1751 "y.tab.c"
    break;

  case 24:
#line 106 "parser.y"
                                                        { 
                                                            if(strcmp(type_variable->name, default_types->int_type->name) == 0){
                                                                gst_install((yyvsp[0].AST_node)->name, default_types->int_ptr_type, 1, 0, NULL);
                                                            }else{
                                                                gst_install((yyvsp[0].AST_node)->name, default_types->str_ptr_type, 1, 0, NULL);
                                                            }
                                                        }
#line 1763 "y.tab.c"
    break;

  case 25:
#line 116 "parser.y"
                                                        { create_connector_node((yyvsp[-1].AST_node), (yyvsp[0].AST_node)); }
#line 1769 "y.tab.c"
    break;

  case 26:
#line 117 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 1775 "y.tab.c"
    break;

  case 27:
#line 121 "parser.y"
                                                        { type_function = default_types->int_type; lst_binding = -2; code_gen_function_definition(outputFile, (yyvsp[-5].AST_node)); add_param_list_to_lst((yyvsp[-3].param_node)); lst_binding = 1; lst_display(); }
#line 1781 "y.tab.c"
    break;

  case 28:
#line 122 "parser.y"
                                                        { (yyval.AST_node) = create_function_definition_node(default_types->int_type, (yyvsp[-8].AST_node), (yyvsp[-6].param_node), (yyvsp[-1].AST_node)); lst_head = lst_tail = NULL; codeGen(outputFile, (yyvsp[-1].AST_node)); code_gen_exit_function(outputFile); }
#line 1787 "y.tab.c"
    break;

  case 29:
#line 124 "parser.y"
                                                        { type_function = default_types->str_type; lst_binding = -2; code_gen_function_definition(outputFile, (yyvsp[-5].AST_node)); add_param_list_to_lst((yyvsp[-3].param_node)); lst_binding = 1; lst_display(); }
#line 1793 "y.tab.c"
    break;

  case 30:
#line 125 "parser.y"
                                                        { (yyval.AST_node) = create_function_definition_node(default_types->str_type, (yyvsp[-8].AST_node), (yyvsp[-6].param_node), (yyvsp[-1].AST_node)); lst_head = lst_tail = NULL; codeGen(outputFile, (yyvsp[-1].AST_node)); code_gen_exit_function(outputFile); }
#line 1799 "y.tab.c"
    break;

  case 31:
#line 127 "parser.y"
                                                         { type_function = tLookup((yyvsp[-6].AST_node)->name); lst_binding = -2; code_gen_function_definition(outputFile, (yyvsp[-5].AST_node)); add_param_list_to_lst((yyvsp[-3].param_node)); lst_binding = 1; lst_display(); }
#line 1805 "y.tab.c"
    break;

  case 32:
#line 128 "parser.y"
                                                         { (yyval.AST_node) = create_function_definition_node(type_function, (yyvsp[-8].AST_node), (yyvsp[-6].param_node), (yyvsp[-1].AST_node)); lst_head = lst_tail = NULL; codeGen(outputFile, (yyvsp[-1].AST_node)); code_gen_exit_function(outputFile); }
#line 1811 "y.tab.c"
    break;

  case 33:
#line 132 "parser.y"
                                                        { (yyval.param_node) = append_param((yyvsp[-2].param_node), (yyvsp[0].param_node)); }
#line 1817 "y.tab.c"
    break;

  case 34:
#line 133 "parser.y"
                                                        { (yyval.param_node) = (yyvsp[0].param_node); }
#line 1823 "y.tab.c"
    break;

  case 35:
#line 134 "parser.y"
                                                        { (yyval.param_node) = NULL; }
#line 1829 "y.tab.c"
    break;

  case 36:
#line 137 "parser.y"
                                                       { (yyval.param_node) = create_p_node((yyvsp[0].AST_node)->name, default_types->int_ptr_type); }
#line 1835 "y.tab.c"
    break;

  case 37:
#line 138 "parser.y"
                                                       { (yyval.param_node) = create_p_node((yyvsp[0].AST_node)->name, default_types->str_ptr_type); }
#line 1841 "y.tab.c"
    break;

  case 38:
#line 139 "parser.y"
                                                       { (yyval.param_node) = create_p_node((yyvsp[0].AST_node)->name, default_types->int_type); }
#line 1847 "y.tab.c"
    break;

  case 39:
#line 140 "parser.y"
                                                       { (yyval.param_node) = create_p_node((yyvsp[0].AST_node)->name, default_types->str_type); }
#line 1853 "y.tab.c"
    break;

  case 40:
#line 141 "parser.y"
                                                       { type_param = tLookup((yyvsp[-1].AST_node)->name); (yyval.param_node) = create_p_node((yyvsp[0].AST_node)->name, type_param); }
#line 1859 "y.tab.c"
    break;

  case 41:
#line 144 "parser.y"
                                                        { (yyval.LST_node) = lst_head; }
#line 1865 "y.tab.c"
    break;

  case 42:
#line 145 "parser.y"
                                                        { }
#line 1871 "y.tab.c"
    break;

  case 43:
#line 148 "parser.y"
                                                        {  }
#line 1877 "y.tab.c"
    break;

  case 44:
#line 149 "parser.y"
                                                        {  }
#line 1883 "y.tab.c"
    break;

  case 46:
#line 157 "parser.y"
                                                        {
                                                            if(strcmp(type_variable->name, default_types->int_type->name) == 0)
                                                                lst_install((yyvsp[0].AST_node)->name, default_types->int_ptr_type);
                                                            else
                                                                lst_install((yyvsp[0].AST_node)->name, default_types->str_ptr_type);
                                                        }
#line 1894 "y.tab.c"
    break;

  case 47:
#line 164 "parser.y"
                                                        { lst_install((yyvsp[0].AST_node)->name, type_variable); }
#line 1900 "y.tab.c"
    break;

  case 48:
#line 166 "parser.y"
                                                        {
                                                            if(strcmp(type_variable->name, default_types->int_type->name) == 0)
                                                                lst_install((yyvsp[0].AST_node)->name, default_types->int_ptr_type);
                                                            else
                                                                lst_install((yyvsp[0].AST_node)->name, default_types->str_ptr_type);
                                                        }
#line 1911 "y.tab.c"
    break;

  case 49:
#line 173 "parser.y"
                                                        { lst_install((yyvsp[0].AST_node)->name, type_variable); }
#line 1917 "y.tab.c"
    break;

  case 50:
#line 177 "parser.y"
                                                        { type_variable = default_types->int_type; }
#line 1923 "y.tab.c"
    break;

  case 51:
#line 178 "parser.y"
                                                        { type_variable = default_types->str_type; }
#line 1929 "y.tab.c"
    break;

  case 52:
#line 179 "parser.y"
                                                        {
                                                            type_variable = tLookup((yyvsp[0].AST_node)->name);
                                                            
                                                            if (type_variable == NULL) {
                                                                printf("%s\n", (yyvsp[0].AST_node)->name);
                                                                yyerror("Unknown type used in declaration.");
                                                            }
                                                        }
#line 1942 "y.tab.c"
    break;

  case 53:
#line 191 "parser.y"
                                                        { type_function = default_types->int_type; lst_display(); }
#line 1948 "y.tab.c"
    break;

  case 54:
#line 192 "parser.y"
                                                        { code_gen_main_function(outputFile); codeGen(outputFile, (yyvsp[-1].AST_node)); lst_head = lst_tail = NULL; }
#line 1954 "y.tab.c"
    break;

  case 55:
#line 197 "parser.y"
        {
            // inorder($2);
            // makeExecutableFile( $2, outputFile);
            // // evaluate($2);
            (yyval.AST_node) = (yyvsp[-2].AST_node);
        }
#line 1965 "y.tab.c"
    break;

  case 56:
#line 203 "parser.y"
                                                        { exit(0); }
#line 1971 "y.tab.c"
    break;

  case 57:
#line 207 "parser.y"
                                                        { (yyval.AST_node) = create_connector_node((yyvsp[-1].AST_node), (yyvsp[0].AST_node)); }
#line 1977 "y.tab.c"
    break;

  case 58:
#line 208 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 1983 "y.tab.c"
    break;

  case 59:
#line 213 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 1989 "y.tab.c"
    break;

  case 60:
#line 214 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 1995 "y.tab.c"
    break;

  case 61:
#line 215 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2001 "y.tab.c"
    break;

  case 62:
#line 216 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2007 "y.tab.c"
    break;

  case 63:
#line 217 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2013 "y.tab.c"
    break;

  case 64:
#line 218 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2019 "y.tab.c"
    break;

  case 65:
#line 219 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2025 "y.tab.c"
    break;

  case 66:
#line 220 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2031 "y.tab.c"
    break;

  case 67:
#line 221 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2037 "y.tab.c"
    break;

  case 68:
#line 222 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2043 "y.tab.c"
    break;

  case 69:
#line 223 "parser.y"
                                                        { (yyval.AST_node) = create_alloc_function_call_node((yyvsp[-5].AST_node)); }
#line 2049 "y.tab.c"
    break;

  case 70:
#line 224 "parser.y"
                                                        { (yyval.AST_node) = create_alloc_function_call_node((yyvsp[-5].AST_node)); }
#line 2055 "y.tab.c"
    break;

  case 71:
#line 225 "parser.y"
                                                        { (yyval.AST_node) = create_free_function_call_node((yyvsp[-2].AST_node)); }
#line 2061 "y.tab.c"
    break;

  case 72:
#line 226 "parser.y"
                                                        { (yyval.AST_node) = create_free_function_call_node((yyvsp[-2].AST_node)); }
#line 2067 "y.tab.c"
    break;

  case 73:
#line 227 "parser.y"
                                                        { (yyval.AST_node) = create_init_function_call_node(); }
#line 2073 "y.tab.c"
    break;

  case 74:
#line 232 "parser.y"
        {
            (yyvsp[-2].AST_node) = create_id_node((yyvsp[-2].AST_node));
            (yyval.AST_node) = create_read_node((yyvsp[-2].AST_node));
        }
#line 2082 "y.tab.c"
    break;

  case 75:
#line 237 "parser.y"
        {
            ast_node* array_node = create_array_node((yyvsp[-5].AST_node), (yyvsp[-3].AST_node));
            (yyval.AST_node) = create_read_node(array_node);
        }
#line 2091 "y.tab.c"
    break;

  case 76:
#line 242 "parser.y"
        {
            (yyval.AST_node) = create_read_node((yyvsp[-2].AST_node));
        }
#line 2099 "y.tab.c"
    break;

  case 77:
#line 249 "parser.y"
        {
            (yyval.AST_node) = create_write_node((yyvsp[-2].AST_node));
        }
#line 2107 "y.tab.c"
    break;

  case 78:
#line 256 "parser.y"
        {
            (yyvsp[-3].AST_node) = create_id_node((yyvsp[-3].AST_node));
            (yyval.AST_node) = create_assign_node((yyvsp[-3].AST_node), (yyvsp[-1].AST_node));
        }
#line 2116 "y.tab.c"
    break;

  case 79:
#line 262 "parser.y"
        {
            ast_node* array_node = create_array_node((yyvsp[-6].AST_node), (yyvsp[-4].AST_node));
            (yyval.AST_node) = create_assign_node(array_node, (yyvsp[-1].AST_node));
        }
#line 2125 "y.tab.c"
    break;

  case 80:
#line 267 "parser.y"
        {
            ast_node* deref_node = create_deref_node((yyvsp[-3].AST_node));
            (yyval.AST_node) = create_assign_node(deref_node, (yyvsp[-1].AST_node));
        }
#line 2134 "y.tab.c"
    break;

  case 81:
#line 272 "parser.y"
        {
            (yyval.AST_node) = create_assign_node((yyvsp[-3].AST_node), (yyvsp[-1].AST_node));
        }
#line 2142 "y.tab.c"
    break;

  case 82:
#line 298 "parser.y"
                                                        { (yyval.AST_node) = create_if_else_node((yyvsp[-7].AST_node), (yyvsp[-4].AST_node), (yyvsp[-2].AST_node)); }
#line 2148 "y.tab.c"
    break;

  case 83:
#line 299 "parser.y"
                                                        { (yyval.AST_node) = create_if_node((yyvsp[-5].AST_node), (yyvsp[-2].AST_node)); }
#line 2154 "y.tab.c"
    break;

  case 84:
#line 304 "parser.y"
                                                        { (yyval.AST_node) = create_while_node((yyvsp[-4].AST_node), (yyvsp[-1].AST_node)); }
#line 2160 "y.tab.c"
    break;

  case 85:
#line 308 "parser.y"
                                                        { (yyval.AST_node) = create_do_while_node((yyvsp[-2].AST_node), (yyvsp[-6].AST_node)); }
#line 2166 "y.tab.c"
    break;

  case 86:
#line 312 "parser.y"
                                                        { (yyval.AST_node) = create_repeat_until_node((yyvsp[-2].AST_node), (yyvsp[-6].AST_node)); }
#line 2172 "y.tab.c"
    break;

  case 87:
#line 316 "parser.y"
                                                        { (yyval.AST_node) = create_break_node(); }
#line 2178 "y.tab.c"
    break;

  case 88:
#line 320 "parser.y"
                                                        { (yyval.AST_node) = create_continue_node(); }
#line 2184 "y.tab.c"
    break;

  case 89:
#line 323 "parser.y"
                                                         { (yyval.AST_node) = create_return_node(type_function, (yyvsp[-1].AST_node), (yyvsp[-1].AST_node)->type); }
#line 2190 "y.tab.c"
    break;

  case 90:
#line 324 "parser.y"
                                                         { (yyval.AST_node) = create_return_node(type_function, NULL, default_types->void_type);}
#line 2196 "y.tab.c"
    break;

  case 91:
#line 327 "parser.y"
                                                        { (yyval.AST_node) = create_operator_node(NODE_TYPE_PLUS, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2202 "y.tab.c"
    break;

  case 92:
#line 329 "parser.y"
                                                        { (yyval.AST_node) = create_operator_node(NODE_TYPE_MINUS, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2208 "y.tab.c"
    break;

  case 93:
#line 331 "parser.y"
                                                        { (yyval.AST_node) = create_operator_node(NODE_TYPE_MULT, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2214 "y.tab.c"
    break;

  case 94:
#line 333 "parser.y"
                                                        { (yyval.AST_node) = create_operator_node(NODE_TYPE_DIV, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2220 "y.tab.c"
    break;

  case 95:
#line 335 "parser.y"
                                                        { (yyval.AST_node) = create_operator_node(NODE_TYPE_MOD, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2226 "y.tab.c"
    break;

  case 96:
#line 337 "parser.y"
                                                        { (yyval.AST_node) = create_boolean_node(NODE_TYPE_LT, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2232 "y.tab.c"
    break;

  case 97:
#line 339 "parser.y"
                                                        { (yyval.AST_node) = create_boolean_node(NODE_TYPE_GT, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2238 "y.tab.c"
    break;

  case 98:
#line 341 "parser.y"
                                                        { (yyval.AST_node) = create_boolean_node(NODE_TYPE_LE, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2244 "y.tab.c"
    break;

  case 99:
#line 343 "parser.y"
                                                        { (yyval.AST_node) = create_boolean_node(NODE_TYPE_GE, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2250 "y.tab.c"
    break;

  case 100:
#line 345 "parser.y"
                                                        { (yyval.AST_node) = create_boolean_node(NODE_TYPE_EQ, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2256 "y.tab.c"
    break;

  case 101:
#line 347 "parser.y"
                                                        { (yyval.AST_node) = create_boolean_node(NODE_TYPE_NE, (yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2262 "y.tab.c"
    break;

  case 102:
#line 349 "parser.y"
                                                        { (yyval.AST_node) = create_function_call_node((yyvsp[-2].AST_node), NULL); }
#line 2268 "y.tab.c"
    break;

  case 103:
#line 351 "parser.y"
                                                        { (yyval.AST_node) = create_function_call_node((yyvsp[-3].AST_node), (yyvsp[-1].AST_node)); arg_list_head = NULL; arg_list_tail = NULL; }
#line 2274 "y.tab.c"
    break;

  case 104:
#line 353 "parser.y"
                                                        { (yyval.AST_node) = assign_type_num_node((yyvsp[0].AST_node)); }
#line 2280 "y.tab.c"
    break;

  case 105:
#line 355 "parser.y"
                                                        { (yyval.AST_node) = assign_type_str_node((yyvsp[0].AST_node)); }
#line 2286 "y.tab.c"
    break;

  case 106:
#line 357 "parser.y"
                                                        { (yyvsp[0].AST_node) = create_id_node((yyvsp[0].AST_node)); (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2292 "y.tab.c"
    break;

  case 107:
#line 359 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[-1].AST_node); }
#line 2298 "y.tab.c"
    break;

  case 108:
#line 361 "parser.y"
                                                        { (yyval.AST_node) = create_array_node((yyvsp[-3].AST_node), (yyvsp[-1].AST_node)); }
#line 2304 "y.tab.c"
    break;

  case 109:
#line 363 "parser.y"
                                                        { (yyval.AST_node) = create_ref_node((yyvsp[0].AST_node)); }
#line 2310 "y.tab.c"
    break;

  case 110:
#line 365 "parser.y"
                                                        { (yyval.AST_node) = create_deref_node((yyvsp[0].AST_node)); }
#line 2316 "y.tab.c"
    break;

  case 111:
#line 367 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2322 "y.tab.c"
    break;

  case 112:
#line 369 "parser.y"
                                                        { union Constant value; (yyval.AST_node) = create_ast_node(NODE_TYPE_NULL, NULL, value); (yyval.AST_node)->type = default_types->int_type; }
#line 2328 "y.tab.c"
    break;

  case 113:
#line 373 "parser.y"
                                                        { (yyval.AST_node) = extend_tuple_node((yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2334 "y.tab.c"
    break;

  case 114:
#line 374 "parser.y"
                                                        { (yyval.AST_node) = create_tuple_node((yyvsp[-2].AST_node), (yyvsp[0].AST_node)); }
#line 2340 "y.tab.c"
    break;

  case 115:
#line 377 "parser.y"
                                                        { (yyval.AST_node) = append_arg_list((yyval.AST_node), (yyvsp[0].AST_node)); }
#line 2346 "y.tab.c"
    break;

  case 116:
#line 378 "parser.y"
                                                        { (yyval.AST_node) = (yyvsp[0].AST_node); }
#line 2352 "y.tab.c"
    break;


#line 2356 "y.tab.c"

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
#line 381 "parser.y"


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
