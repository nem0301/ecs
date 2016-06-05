/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "parser.y" /* yacc.c:339  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <fcntl.h>
#include "myString.h"
#include "table.c"


/* ====================================================================== */

#define UNDEFINED_VAR 0
#define UNDEFINED_FUNC 1
#define REDEFINED_VAR 10
#define REDEFINED_FUNC 11
#define WORNG_TYPE_VAR 20
#define WORNG_TYPE_FUNC 21

#define MINUS_TYPE 0
#define NOT_TYPE 1


/* ====================================================================== */

extern FILE *yyin;
extern char *yytext;
extern int source_line_no;
extern char *lex;

extern char *kind_list[];
extern char *type_list[];

unsigned char subroutine;
unsigned char position = CLASS_KIND;
unsigned char type = -1;
char *lexeme;

unsigned int field_count = 0;
unsigned int static_count = 0;
unsigned int local_count = 0;
unsigned int arg_count = 0;
char *classname = NULL;

int while_count = 0;
int if_count = 0;

extern struct table *global_table;
extern struct table *local_table;
extern struct table *current_table;

typedef struct t_type_struct {
    unsigned char type;
}t_type;

typedef struct l_type_struct {
    char *lex;
}l_type;


/* ====================================================================== */

int yyerror(char *message);
int semanticError(char *fmt, unsigned char err_type);

void printVar(char *name)
{
    struct symbol *symbole = lookupTable(name);

    if ( symbole != NULL )
    {
        printf("%-20s %-20s %-20s %-20s %-20d\n", name, 
                                            kind_list[symbole->kind],
                                            type_list[symbole->type],
                                            symbole->type_name,
                                            symbole->num
                                            );
    }
    else
    {
        printf("%s is not in any table\n", name);
    }
}


#line 154 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    CLASS = 258,
    CONSTRUCTOR = 259,
    FUNCTION = 260,
    METHOD = 261,
    FIELD = 262,
    STATIC = 263,
    VAR = 264,
    INT = 265,
    CHAR = 266,
    BOOLEAN = 267,
    VOID = 268,
    TRUE = 269,
    FALSE = 270,
    NULLVAL = 271,
    THIS = 272,
    LET = 273,
    DO = 274,
    IF = 275,
    ELSE = 276,
    WHILE = 277,
    RETURN = 278,
    LBRACE = 279,
    RBRACE = 280,
    LPAR = 281,
    RPAR = 282,
    LBRACKET = 283,
    RBRACKET = 284,
    DOT = 285,
    COMMA = 286,
    SEMICOLON = 287,
    PLUS = 288,
    MINUS = 289,
    MULTIPLY = 290,
    DIVIDE = 291,
    AND = 292,
    OR = 293,
    LT = 294,
    GT = 295,
    EQ = 296,
    NOT = 297,
    NUM = 298,
    STRING = 299,
    ID = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 96 "parser.y" /* yacc.c:355  */

    l_type lval;
    t_type tval;
    int nval;

#line 246 "parser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 261 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   247

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   122,   122,   135,   122,   147,   148,   153,   152,   160,
     159,   168,   175,   180,   184,   188,   192,   201,   215,   232,
     233,   238,   249,   237,   260,   264,   268,   275,   276,   283,
     284,   288,   296,   300,   296,   321,   320,   325,   329,   334,
     346,   347,   351,   352,   353,   354,   355,   360,   359,   369,
     368,   377,   388,   387,   396,   403,   412,   411,   424,   431,
     435,   443,   447,   451,   455,   456,   457,   462,   463,   464,
     465,   481,   487,   497,   496,   507,   506,   526,   530,   534,
     542,   546,   550,   554,   558,   562,   566,   570,   574,   581,
     585,   592,   597,   601,   602,   609
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "CONSTRUCTOR", "FUNCTION",
  "METHOD", "FIELD", "STATIC", "VAR", "INT", "CHAR", "BOOLEAN", "VOID",
  "TRUE", "FALSE", "NULLVAL", "THIS", "LET", "DO", "IF", "ELSE", "WHILE",
  "RETURN", "LBRACE", "RBRACE", "LPAR", "RPAR", "LBRACKET", "RBRACKET",
  "DOT", "COMMA", "SEMICOLON", "PLUS", "MINUS", "MULTIPLY", "DIVIDE",
  "AND", "OR", "LT", "GT", "EQ", "NOT", "NUM", "STRING", "ID", "$accept",
  "class", "$@1", "$@2", "classVarDecList", "classVarDec", "$@3", "$@4",
  "identifier", "type", "identifierList", "subroutineDecList",
  "subroutineDec", "$@5", "$@6", "subroutineKind", "parameters",
  "parameterList", "parameter", "subroutineBody", "$@7", "$@8", "varDecs",
  "$@9", "varDecList", "statements", "statement", "letStatement", "$@10",
  "$@11", "preif", "ifStatement", "$@12", "prewhile", "whileStatement",
  "$@13", "doStatement", "returnStatement", "expression", "term",
  "numConstant", "stringConstant", "subroutineCall", "$@14", "$@15",
  "expressionList", "op", "unaryOp", "keywordConstant", "empty", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -74

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -95,     8,    16,   -95,   -20,   -95,   -95,    27,   -95,    28,
     -95,     4,     4,   -95,     7,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,     4,   -20,
     -20,   -20,   -95,    11,    13,   -95,   -20,   -95,   -95,     5,
     -95,     4,   -20,    30,    39,   -95,   -95,   -95,   -95,     4,
     -95,   -95,   -95,    34,   -95,    62,   -95,     4,   -95,   -95,
     198,   -95,   -20,   -20,   -20,    46,   -95,    52,   -95,   -95,
     -95,    49,   -95,    48,   -95,   -95,   -95,   -95,    22,    47,
      53,    44,    65,   -95,   -95,   -95,   -95,    65,   -95,   -95,
     -95,   -95,   -95,    -6,   145,   -95,   -95,   -95,   -95,    65,
     -95,   -95,    65,   -20,   -95,    36,    57,   -20,    63,   -95,
      79,    94,    65,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,    65,   -95,   206,   109,   -95,    65,    65,
     -95,    65,   -95,   -95,   122,   -95,    67,   -95,   155,   135,
      66,   174,    10,   -95,   -95,    72,    74,   -95,    59,    65,
     -95,    65,    78,   -95,    65,    25,   174,   -95,   214,   165,
     -95,   222,   -95,   -95,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,    11,     3,     0,    95,    95,
       6,     0,     0,     5,     0,    20,    13,    14,    15,    12,
      16,     9,     7,    24,    25,    26,     4,    19,     0,     0,
       0,     0,    18,     0,     0,    21,     0,    10,     8,     0,
      17,    95,     0,     0,    27,    30,    28,    31,    22,     0,
      32,    29,    23,     0,    95,    33,    37,     0,    95,    35,
       0,    41,     0,     0,     0,     0,    55,     0,    34,    40,
      42,     0,    43,     0,    44,    45,    46,    39,     0,    47,
      73,     0,     0,    91,    92,    93,    94,     0,    60,    89,
      90,    71,    72,    66,     0,    62,    63,    64,    68,     0,
      65,    95,     0,     0,    36,     0,     0,     0,     0,    58,
       0,     0,     0,    59,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,    70,     0,     0,    38,     0,     0,
      75,    95,    51,    69,     0,    61,    54,    56,     0,     0,
       0,    78,     0,    79,    67,     0,     0,    48,     0,    95,
      74,     0,     0,    95,     0,     0,    77,    95,     0,     0,
      76,     0,    57,    50,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,    -2,    -7,
      73,   -95,   -95,   -95,   -95,   -95,   -95,   -95,    55,   -95,
     -95,   -95,   -95,   -95,   -95,   -94,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -64,   -93,
     -95,   -95,    58,   -95,   -95,   -38,   -95,   -95,   -95,    -8
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,     9,    13,    30,    29,    93,    42,
      33,    14,    27,    39,    50,    28,    43,    44,    45,    52,
      53,    58,    55,    62,    78,    60,    69,    70,   105,   106,
      71,    72,   145,    73,    74,   146,    75,    76,   141,    95,
      96,    97,    98,   108,   140,   142,   123,    99,   100,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,    15,     6,    94,    21,    22,   124,   125,     3,    20,
      20,    23,    24,    25,    16,    17,    18,    19,   110,     4,
     -73,    31,   112,   111,   107,     5,    20,    32,    32,    35,
     135,    41,    26,    46,    40,    11,    12,   150,   126,    20,
      47,   151,    36,    37,    36,    38,    56,    20,   134,     5,
      59,     8,   160,   103,   104,    20,   151,    48,    54,   158,
      77,    79,    80,   161,   138,   139,    83,    84,    85,    86,
      49,    57,    82,   101,   102,   -49,   109,   128,    87,    83,
      84,    85,    86,   107,    88,   129,    89,   156,   -52,   131,
     159,    87,   149,   152,    90,    91,    92,     5,   153,    89,
     154,   127,   157,    34,    51,   130,   132,    90,    91,    92,
       5,   155,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   133,    81,   143,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   137,     0,     0,     0,
       0,   143,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   144,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   148,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   147,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   163,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    63,    64,    65,     0,
      66,    67,     0,    68,    63,    64,    65,     0,    66,    67,
       0,   136,    63,    64,    65,     0,    66,    67,     0,   162,
      63,    64,    65,     0,    66,    67,     0,   164
};

static const yytype_int16 yycheck[] =
{
       8,     9,     4,    67,    11,    12,    99,   101,     0,    11,
      12,     4,     5,     6,    10,    11,    12,    13,    82,     3,
      26,    28,    28,    87,    30,    45,    28,    29,    30,    31,
     123,    26,    25,    41,    36,     7,     8,    27,   102,    41,
      42,    31,    31,    32,    31,    32,    54,    49,   112,    45,
      57,    24,    27,    31,    32,    57,    31,    27,    24,   153,
      62,    63,    64,   157,   128,   129,    14,    15,    16,    17,
      31,     9,    26,    24,    26,    28,    32,    41,    26,    14,
      15,    16,    17,    30,    32,    28,    34,   151,    21,    26,
     154,    26,    26,    21,    42,    43,    44,    45,    24,    34,
      41,   103,    24,    30,    49,   107,    27,    42,    43,    44,
      45,   149,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    27,    64,   131,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    27,    -1,    -1,    -1,
      -1,   149,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    29,    -1,    -1,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    29,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    18,    19,    20,    -1,
      22,    23,    -1,    25,    18,    19,    20,    -1,    22,    23,
      -1,    25,    18,    19,    20,    -1,    22,    23,    -1,    25,
      18,    19,    20,    -1,    22,    23,    -1,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,    48,     0,     3,    45,    54,    49,    24,    50,
      95,     7,     8,    51,    57,    95,    10,    11,    12,    13,
      54,    55,    55,     4,     5,     6,    25,    58,    61,    53,
      52,    55,    54,    56,    56,    54,    31,    32,    32,    59,
      54,    26,    55,    62,    63,    64,    95,    54,    27,    31,
      60,    64,    65,    66,    24,    68,    95,     9,    67,    55,
      71,    95,    69,    18,    19,    20,    22,    23,    25,    72,
      73,    76,    77,    79,    80,    82,    83,    54,    70,    54,
      54,    88,    26,    14,    15,    16,    17,    26,    32,    34,
      42,    43,    44,    54,    84,    85,    86,    87,    88,    93,
      94,    24,    26,    31,    32,    74,    75,    30,    89,    32,
      84,    84,    28,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    92,    85,    71,    84,    54,    41,    28,
      54,    26,    27,    27,    84,    85,    25,    27,    84,    84,
      90,    84,    91,    95,    29,    78,    81,    32,    29,    26,
      27,    31,    21,    24,    41,    91,    84,    24,    71,    84,
      27,    71,    25,    32,    25
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    48,    49,    47,    50,    50,    52,    51,    53,
      51,    54,    55,    55,    55,    55,    55,    56,    56,    57,
      57,    59,    60,    58,    61,    61,    61,    62,    62,    63,
      63,    64,    66,    67,    65,    69,    68,    68,    70,    70,
      71,    71,    72,    72,    72,    72,    72,    74,    73,    75,
      73,    76,    78,    77,    77,    79,    81,    80,    82,    83,
      83,    84,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    86,    87,    89,    88,    90,    88,    91,    91,    91,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    93,
      93,    94,    94,    94,    94,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     8,     2,     1,     0,     5,     0,
       5,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       1,     0,     0,     9,     1,     1,     1,     1,     1,     3,
       1,     2,     0,     0,     6,     0,     6,     1,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     0,     6,     0,
       9,     4,     0,     9,     4,     1,     0,     8,     3,     3,
       2,     3,     1,     1,     1,     1,     1,     4,     1,     3,
       2,     1,     1,     0,     5,     0,     7,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 122 "parser.y" /* yacc.c:1646  */
    {
        field_count = 0;
        static_count = 0;
        local_count = 0;

        global_table = current_table = createTable("global");
        /*
        printf("---------- ---------- ---------- ----------\n");
        printf("%-10s %-10s %-10s %-10s\n", "name", "kind", "type", "type_name");
        printf("---------- ---------- ---------- ----------\n");
        */
    }
#line 1490 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 135 "parser.y" /* yacc.c:1646  */
    {
        classname = (char*) malloc (strlen((yyvsp[0].lval).lex) + 1);
        strcpy(classname, (yyvsp[0].lval).lex);
        insertTable ( global_table, classname, CLASS_KIND, CLASS_TYPE, 0, "");
    }
#line 1500 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 141 "parser.y" /* yacc.c:1646  */
    {
        //printTable(global_table);
    }
#line 1508 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 153 "parser.y" /* yacc.c:1646  */
    {
        position = STATIC_KIND;
        type = (yyvsp[0].tval).type;
    }
#line 1517 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 160 "parser.y" /* yacc.c:1646  */
    {
        position = FIELD_KIND;
        type = (yyvsp[0].tval).type;
    }
#line 1526 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 169 "parser.y" /* yacc.c:1646  */
    {
        (yyval.lval).lex = lex;
    }
#line 1534 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 176 "parser.y" /* yacc.c:1646  */
    {
        (yyval.tval).type = VOID_TYPE;

    }
#line 1543 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 181 "parser.y" /* yacc.c:1646  */
    {
        (yyval.tval).type = INT_TYPE;
    }
#line 1551 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 185 "parser.y" /* yacc.c:1646  */
    {
        (yyval.tval).type = CHAR_TYPE;
    }
#line 1559 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 189 "parser.y" /* yacc.c:1646  */
    {
        (yyval.tval).type = BOOLEAN_TYPE;
    }
#line 1567 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 193 "parser.y" /* yacc.c:1646  */
    {
        (yyval.tval).type = OBJECT_TYPE;
        lexeme = (char*) malloc (strlen(lex));;
        strcpy(lexeme, lex);
    }
#line 1577 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 202 "parser.y" /* yacc.c:1646  */
    {
        int count;
        if (position == FIELD_KIND)
        {
            count = field_count++;
        }
        else if (position == STATIC_KIND)
        {
            count = static_count++;
        }
        
        insertTable(current_table, (yyvsp[0].lval).lex, position, type, count, lexeme);
    }
#line 1595 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 216 "parser.y" /* yacc.c:1646  */
    {
        int count;
        if (position == FIELD_KIND)
        {
            count = field_count++;
        }
        else if (position == STATIC_KIND)
        {
            count = static_count++;
        }
        
        insertTable(current_table, (yyvsp[0].lval).lex, position, type, count, lexeme);
    }
#line 1613 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 238 "parser.y" /* yacc.c:1646  */
    {
        insertTable(global_table, (yyvsp[0].lval).lex, (yyvsp[-2].tval).type, (yyvsp[-1].tval).type, 0, lexeme);
        local_table = createTable((yyvsp[0].lval).lex);
        current_table = local_table;
        arg_count = 0;
        local_count = 0;
        while_count = 0;
        if_count = 0;

    }
#line 1628 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 249 "parser.y" /* yacc.c:1646  */
    {
    }
#line 1635 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 252 "parser.y" /* yacc.c:1646  */
    {
        //printTable(local_table);
        isInHashTable(global_table, (yyvsp[-6].lval).lex)->num = local_count;
        current_table = global_table;
    }
#line 1645 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 261 "parser.y" /* yacc.c:1646  */
    {
        subroutine = CONSTRUCTOR_KIND;
    }
#line 1653 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 265 "parser.y" /* yacc.c:1646  */
    {
        subroutine = FUNCTION_KIND;
    }
#line 1661 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 269 "parser.y" /* yacc.c:1646  */
    {
        subroutine = METHOD_KIND;
    }
#line 1669 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 277 "parser.y" /* yacc.c:1646  */
    {
        arg_count = 0;
    }
#line 1677 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 289 "parser.y" /* yacc.c:1646  */
    {
        insertTable(current_table, (yyvsp[0].lval).lex, ARGUMENT_KIND, (yyvsp[-1].tval).type, arg_count, lexeme);
        arg_count++;
    }
#line 1686 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 296 "parser.y" /* yacc.c:1646  */
    {
        position = LOCAL_KIND;
    }
#line 1694 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 300 "parser.y" /* yacc.c:1646  */
    {
        
        printf("function %s.%s %d\n", classname, current_table->name, local_count);
        if (subroutine == CONSTRUCTOR_KIND)
        {
            printf("push constant %d\n", field_count + static_count);
            printf("call Memory.alloc 1\n");
            printf("pop pointer 0\n");
        }
        else if (subroutine == METHOD_KIND)
        {
            printf("push argument 0\n");
            printf("pop pointer 0\n");
        }

    }
#line 1715 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 321 "parser.y" /* yacc.c:1646  */
    {
        type = (yyvsp[0].tval).type;
    }
#line 1723 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 330 "parser.y" /* yacc.c:1646  */
    {
        insertTable(current_table, (yyvsp[0].lval).lex, position, type, local_count, lexeme);
        local_count++;
    }
#line 1732 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 335 "parser.y" /* yacc.c:1646  */
    {
        insertTable(current_table, (yyvsp[0].lval).lex, position, type, local_count, lexeme);
        local_count++;
    }
#line 1741 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 360 "parser.y" /* yacc.c:1646  */
    {
    }
#line 1748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 363 "parser.y" /* yacc.c:1646  */
    {
        struct symbol* symbole = lookupTable((yyvsp[-4].lval).lex);
        printf("pop %s %d\n", kind_list[symbole->kind], symbole->num);
    }
#line 1757 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 369 "parser.y" /* yacc.c:1646  */
    {
    }
#line 1764 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 372 "parser.y" /* yacc.c:1646  */
    {
    }
#line 1771 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 378 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nval) = if_count++;
        printf("if-goto IF_TRUE%d\n", (yyval.nval));
        printf("goto IF_FALSE%d\n", (yyval.nval));
        printf("label IF_TRUE%d\n", (yyval.nval));
    }
#line 1782 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 388 "parser.y" /* yacc.c:1646  */
    {
        printf("goto IF_END%d\n", (yyvsp[-3].nval));
        printf("label IF_FALSE%d\n", (yyvsp[-3].nval));
    }
#line 1791 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 393 "parser.y" /* yacc.c:1646  */
    {
        printf("label IF_END%d\n", (yyvsp[-8].nval));
    }
#line 1799 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 397 "parser.y" /* yacc.c:1646  */
    {
        printf("label IF_FALSE%d\n", (yyvsp[-3].nval));
    }
#line 1807 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 404 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nval) = while_count++;
        printf("label WHILE_EXP%d\n", (yyval.nval));
    }
#line 1816 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 412 "parser.y" /* yacc.c:1646  */
    {
        printf("not\n");
        printf("if-goto WHILE_END%d\n", (yyvsp[-3].nval));
    }
#line 1825 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 417 "parser.y" /* yacc.c:1646  */
    {
        printf("goto WHILE_EXP%d\n", (yyvsp[-7].nval));
        printf("label WHILE_END%d\n", (yyvsp[-7].nval));
    }
#line 1834 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 425 "parser.y" /* yacc.c:1646  */
    {
        printf("pop temp 0\n");
    }
#line 1842 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 432 "parser.y" /* yacc.c:1646  */
    {
        printf("return\n");
    }
#line 1850 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 436 "parser.y" /* yacc.c:1646  */
    {
        printf("push constant 0\n");
        printf("return\n");
    }
#line 1859 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 444 "parser.y" /* yacc.c:1646  */
    {
        printf("%s\n", (yyvsp[-1].lval).lex);
    }
#line 1867 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 452 "parser.y" /* yacc.c:1646  */
    {
        printf("push constant %s\n", (yyvsp[0].lval).lex);
    }
#line 1875 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 458 "parser.y" /* yacc.c:1646  */
    {
        struct symbol* symbole = lookupTable((yyvsp[0].lval).lex);
        printf("push %s %d\n", kind_list[symbole->kind], symbole->num);        
    }
#line 1884 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 466 "parser.y" /* yacc.c:1646  */
    {
        if ( (yyvsp[-1].tval).type == MINUS_TYPE )
        {
            printf("neg\n");
        }
        else if ( (yyvsp[-1].tval).type == NOT_TYPE )
        {
            printf("not\n");
        }
        
    }
#line 1900 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 482 "parser.y" /* yacc.c:1646  */
    {
        (yyval.lval).lex = lex;
    }
#line 1908 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 488 "parser.y" /* yacc.c:1646  */
    {
        (yyval.lval).lex = lex;
    }
#line 1916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 497 "parser.y" /* yacc.c:1646  */
    {
        arg_count = 0;
    }
#line 1924 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 501 "parser.y" /* yacc.c:1646  */
    {
        printf("push pointer 0\n");
        printf("call %s.%s %d\n", classname, (yyvsp[-4].lval).lex, arg_count+1);
    }
#line 1933 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 507 "parser.y" /* yacc.c:1646  */
    {
        arg_count  = 0;
    }
#line 1941 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 511 "parser.y" /* yacc.c:1646  */
    {
        struct symbol* symbole = lookupTable((yyvsp[-6].lval).lex);
        if (symbole != NULL)
        {
            printf ("push %s %d\n", kind_list[symbole->kind], symbole->num);
            printf("call %s.%s %d\n", symbole->type_name, (yyvsp[-4].lval).lex, arg_count + 1);
        }
        else
        {
            printf("call %s.%s %d\n", (yyvsp[-6].lval).lex, (yyvsp[-4].lval).lex, arg_count);
        }
    }
#line 1958 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 527 "parser.y" /* yacc.c:1646  */
    {
        arg_count++;
    }
#line 1966 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 531 "parser.y" /* yacc.c:1646  */
    {
        arg_count = 1;
    }
#line 1974 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 535 "parser.y" /* yacc.c:1646  */
    {
        arg_count = 0;
    }
#line 1982 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 543 "parser.y" /* yacc.c:1646  */
    {
        (yyval.lval).lex = "add"; 
    }
#line 1990 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 547 "parser.y" /* yacc.c:1646  */
    {
        (yyval.lval).lex = "sub"; 
    }
#line 1998 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 551 "parser.y" /* yacc.c:1646  */
    {
        (yyval.lval).lex = "call Math.multiply 2"; 
    }
#line 2006 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 555 "parser.y" /* yacc.c:1646  */
    {
        (yyval.lval).lex = "call Math.divide 2"; 
    }
#line 2014 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 559 "parser.y" /* yacc.c:1646  */
    {
        (yyval.lval).lex = "and"; 
    }
#line 2022 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 563 "parser.y" /* yacc.c:1646  */
    {
        (yyval.lval).lex = "or"; 
    }
#line 2030 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 567 "parser.y" /* yacc.c:1646  */
    {
        (yyval.lval).lex = "lt"; 
    }
#line 2038 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 571 "parser.y" /* yacc.c:1646  */
    {
        (yyval.lval).lex = "gt"; 
    }
#line 2046 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 575 "parser.y" /* yacc.c:1646  */
    {
        (yyval.lval).lex = "eq"; 
    }
#line 2054 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 582 "parser.y" /* yacc.c:1646  */
    {
        (yyval.tval).type = MINUS_TYPE;
    }
#line 2062 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 586 "parser.y" /* yacc.c:1646  */
    {
        (yyval.tval).type = NOT_TYPE;
    }
#line 2070 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 593 "parser.y" /* yacc.c:1646  */
    {
        printf("push constant 0\n");
        printf("not\n");
    }
#line 2079 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 598 "parser.y" /* yacc.c:1646  */
    {
        printf("push constant 0\n");
    }
#line 2087 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 603 "parser.y" /* yacc.c:1646  */
    {
        //printf("%s\n", kind_list[position]);
        printf("push pointer 0\n");
    }
#line 2096 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2100 "parser.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 623 "parser.y" /* yacc.c:1906  */



/* ====================================================================== */

int yyerror(char *message)
{
    fprintf(stderr, "line %d: %s at \"%s\"\n", source_line_no, message, yytext);
}

/* ====================================================================== */

void run(char *fname)
{
    int fd;
    char *vmName;

    vmName = (char*) malloc (strlen(fname) - 1);
    strcpy ( vmName, fname );

    stringReplace(vmName, fname, ".jack", ".vm");


    remove(vmName);
    fd = open (vmName, O_CREAT | O_WRONLY, 0664);
    dup2(fd, 1);

    yyin = fopen(fname, "r"); 
    yyparse();
    free(vmName);
    close(fd);
    fflush(stdout);
}

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *dent;
    char *fname;

    char *dirPath;

    dir = opendir(argv[1]);
    

    /*
    if (argc < 3)
    {
    }
    */
   
    if (dir == NULL)
    {
        run(argv[1]);
    }
    else 
    {
        // distinguish directory sign from only name (dir/ or dir)
        // and that make string to do not have '/' char
        if ( argv[1][strlen(argv[1])-1] == '/' ) 
        {
            dirPath = (char*) malloc (strlen(argv[1]));
            strcpy(dirPath, argv[1]);
            *(dirPath + strlen(argv[1]) - 1) = '\0';
        }
        else
        {
            dirPath = (char*) malloc (strlen(argv[1]) + 1);
            strcpy(dirPath, argv[1]);
        }
        while ( (dent = readdir(dir)) != NULL )
        {
            if( strstr(dent->d_name, ".jack") != NULL &&
                strstr(dent->d_name, ".swp") == NULL)
            {
                int len = strlen(dirPath) + strlen(dent->d_name) + 1;
                char* fullPath = (char*) malloc (len);

                sprintf(fullPath, "%s/%s", dirPath, dent->d_name);
                run(fullPath);
            }
        }

    }

    return 0;
}

/* ====================================================================== */
