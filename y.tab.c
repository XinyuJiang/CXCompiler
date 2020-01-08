/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM = 258,
     RNUM = 259,
     ID = 260,
     RELOP = 261,
     INT = 262,
     BOOL = 263,
     DOUBLE = 264,
     CONST = 265,
     IF = 266,
     ELSE = 267,
     SWITCH = 268,
     CASE = 269,
     WHILE = 270,
     DO = 271,
     FOR = 272,
     REPEAT = 273,
     UNTIL = 274,
     BREAK = 275,
     CONTINUE = 276,
     EXIT = 277,
     WRITE = 278,
     READ = 279,
     PLUS = 280,
     MINUS = 281,
     TIMES = 282,
     DIVIDES = 283,
     COMPLEMENT = 284,
     ODD = 285,
     XOR = 286,
     SPLUS = 287,
     SMINUS = 288,
     ASSIGN = 289,
     OR = 290,
     AND = 291,
     NOT = 292,
     SEMI = 293,
     COLON = 294,
     LP = 295,
     RP = 296,
     LB = 297,
     RB = 298,
     LAN = 299,
     RAN = 300,
     LETTER = 301,
     DIGIT = 302,
     BLANK = 303,
     ANNO = 304,
     TRUE = 305,
     FALSE = 306
   };
#endif
/* Tokens.  */
#define NUM 258
#define RNUM 259
#define ID 260
#define RELOP 261
#define INT 262
#define BOOL 263
#define DOUBLE 264
#define CONST 265
#define IF 266
#define ELSE 267
#define SWITCH 268
#define CASE 269
#define WHILE 270
#define DO 271
#define FOR 272
#define REPEAT 273
#define UNTIL 274
#define BREAK 275
#define CONTINUE 276
#define EXIT 277
#define WRITE 278
#define READ 279
#define PLUS 280
#define MINUS 281
#define TIMES 282
#define DIVIDES 283
#define COMPLEMENT 284
#define ODD 285
#define XOR 286
#define SPLUS 287
#define SMINUS 288
#define ASSIGN 289
#define OR 290
#define AND 291
#define NOT 292
#define SEMI 293
#define COLON 294
#define LP 295
#define RP 296
#define LB 297
#define RB 298
#define LAN 299
#define RAN 300
#define LETTER 301
#define DIGIT 302
#define BLANK 303
#define ANNO 304
#define TRUE 305
#define FALSE 306




/* Copy the first part of user declarations.  */
#line 1 "cx.y"

 #include <stdio.h>
 #include <string.h>
 #include "pcode.h"
 int yylex(void);
 FILE *yyin;
 int yyerror(char*);
 extern int yylineno;
 extern char* yytext;
 #define MAXLOOP 10
 int cx1[MAXLOOP];//if的嵌套栈
 int cx1count = 0;
 int cx2[MAXLOOP];//while的嵌套栈
 int cx2count = 0;
 int cx3[MAXLOOP];//case的嵌套栈
 int cx3count = 0;
 int cx4[MAXLOOP];//break的数组。因为语句中可能有多个break所以还是要一个数据结构来存储每一个位置
 int cx4count = 0;
 int cx5[MAXLOOP];//回标for语句中jpc用.每三条语句为一组，组内第一个记录for中第二个表达式之前的位置，第二个记录第二个表达式之后的位置，第三个记录stmt结束位置
 int cx5count = 0;
 int cx6[MAXLOOP];//continue的数组。因为语句中可能有多个continue所以还是要一个数据结构来存储每一个位置
 int cx6count = 0;
 int cx61[MAXLOOP];//continue的数组。应对do while，repeat until的情况
 int cx61count = 0;
 int cx7[MAXLOOP]; //exit返回地址
 int cx7count = 0;
 int cx8[MAXLOOP];//do while的嵌套栈
 int cx8count = 0;
 int cx9[MAXLOOP];//repeat until的嵌套栈
 int cx9count = 0;
 

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 33 "cx.y"
{
	double var;
	char* name;
}
/* Line 193 of yacc.c.  */
#line 235 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 248 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   214

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNRULES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,    10,    13,    14,    18,    22,    26,
      27,    35,    36,    44,    45,    53,    56,    57,    62,    67,
      68,    69,    78,    79,    80,    88,    89,    90,    91,   106,
     107,   115,   116,   124,   128,   132,   134,   142,   145,   148,
     151,   156,   159,   162,   163,   167,   168,   169,   176,   177,
     183,   187,   191,   193,   197,   201,   205,   209,   213,   215,
     219,   223,   225,   227,   229,   233,   237,   239,   242,   246,
     250,   252,   254,   256,   258,   261,   265,   267,   271,   275
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    54,    -1,    42,    55,    60,    43,    -1,
      55,    56,    -1,    -1,     7,     5,    38,    -1,     8,     5,
      38,    -1,     9,     5,    38,    -1,    -1,    10,     7,     5,
      57,    34,    77,    38,    -1,    -1,    10,     8,     5,    58,
      34,    80,    38,    -1,    -1,    10,     9,     5,    59,    34,
      77,    38,    -1,    60,    61,    -1,    -1,     5,    34,    77,
      38,    -1,     5,    34,    80,    38,    -1,    -1,    -1,    11,
      40,    80,    41,    62,    61,    63,    72,    -1,    -1,    -1,
      15,    64,    40,    80,    41,    65,    61,    -1,    -1,    -1,
      -1,    17,    40,     5,    34,    77,    38,    66,    83,    38,
      67,    71,    68,    41,    61,    -1,    -1,    16,    69,    61,
      15,    40,    80,    41,    -1,    -1,    18,    70,    60,    19,
      40,    80,    41,    -1,    23,    77,    38,    -1,    24,     5,
      38,    -1,    54,    -1,    13,    40,    77,    41,    42,    74,
      43,    -1,    71,    38,    -1,    20,    38,    -1,    21,    38,
      -1,    22,    40,    41,    38,    -1,     5,    32,    -1,     5,
      33,    -1,    -1,    12,    73,    61,    -1,    -1,    -1,    74,
      14,    77,    75,    39,    60,    -1,    -1,    14,    77,    76,
      39,    60,    -1,    78,    25,    78,    -1,    78,    26,    78,
      -1,    78,    -1,     5,    34,    77,    -1,    79,    27,    79,
      -1,    79,    28,    79,    -1,    79,    29,    79,    -1,    79,
      31,    79,    -1,    79,    -1,    78,    25,    78,    -1,    78,
      26,    78,    -1,     5,    -1,     3,    -1,     4,    -1,    40,
      77,    41,    -1,    80,    35,    81,    -1,    81,    -1,    30,
      79,    -1,     5,    34,    80,    -1,    81,    36,    82,    -1,
      82,    -1,     5,    -1,    50,    -1,    51,    -1,    37,    82,
      -1,    40,    80,    41,    -1,    83,    -1,     5,     6,    77,
      -1,     3,     6,    77,    -1,     4,     6,    77,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    43,    43,    49,    51,    51,    53,    59,    65,    70,
      70,    83,    83,    96,    96,   110,   110,   112,   134,   151,
     156,   151,   161,   165,   161,   184,   207,   212,   184,   234,
     234,   250,   250,   265,   266,   275,   276,   285,   286,   291,
     302,   308,   320,   332,   332,   338,   346,   346,   357,   357,
     368,   371,   374,   376,   380,   383,   386,   389,   392,   393,
     396,   400,   409,   412,   415,   418,   421,   422,   425,   429,
     432,   434,   447,   451,   454,   457,   458,   460,   498,   527
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "RNUM", "ID", "RELOP", "INT",
  "BOOL", "DOUBLE", "CONST", "IF", "ELSE", "SWITCH", "CASE", "WHILE", "DO",
  "FOR", "REPEAT", "UNTIL", "BREAK", "CONTINUE", "EXIT", "WRITE", "READ",
  "PLUS", "MINUS", "TIMES", "DIVIDES", "COMPLEMENT", "ODD", "XOR", "SPLUS",
  "SMINUS", "ASSIGN", "OR", "AND", "NOT", "SEMI", "COLON", "LP", "RP",
  "LB", "RB", "LAN", "RAN", "LETTER", "DIGIT", "BLANK", "ANNO", "TRUE",
  "FALSE", "$accept", "program", "block", "decls", "decl", "@1", "@2",
  "@3", "stmts", "stmt", "@4", "@5", "@6", "@7", "@8", "@9", "@10", "@11",
  "@12", "selfop", "elses", "@13", "cases", "@14", "@15", "aexpr", "aterm",
  "afactor", "bexpr", "bterm", "bfactor", "rel", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    55,    55,    56,    56,    56,    57,
      56,    58,    56,    59,    56,    60,    60,    61,    61,    62,
      63,    61,    64,    65,    61,    66,    67,    68,    61,    69,
      61,    70,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    71,    71,    73,    72,    72,    75,    74,    76,    74,
      77,    77,    77,    77,    78,    78,    78,    78,    78,    78,
      78,    79,    79,    79,    79,    80,    80,    80,    80,    81,
      81,    82,    82,    82,    82,    82,    82,    83,    83,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     2,     0,     3,     3,     3,     0,
       7,     0,     7,     0,     7,     2,     0,     4,     4,     0,
       0,     8,     0,     0,     7,     0,     0,     0,    14,     0,
       7,     0,     7,     3,     3,     1,     7,     2,     2,     2,
       4,     2,     2,     0,     3,     0,     0,     6,     0,     5,
       3,     3,     1,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     1,     1,     3,     3,     1,     2,     3,     3,
       1,     1,     1,     1,     2,     3,     1,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     2,    16,     1,     0,     0,     0,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    29,     0,    31,     0,     0,     0,     0,     0,
       3,    35,    15,     0,     6,     7,     8,     9,    11,    13,
      41,    42,     0,     0,     0,     0,     0,     0,    16,    38,
      39,     0,    62,    63,    61,     0,     0,    52,    58,     0,
      37,     0,     0,     0,    62,    63,    61,     0,     0,     0,
      72,    73,     0,     0,    66,    70,    76,     0,     0,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     0,     0,     0,    34,     0,     0,
       0,     0,     0,     0,     0,    61,    67,    71,    74,     0,
      17,     0,    18,     0,     0,    19,     0,     0,     0,     0,
       0,    40,    53,    64,    50,    51,    54,    55,    56,    57,
       0,     0,     0,    78,    79,    77,    68,    75,    65,    69,
       0,     0,    23,     0,     0,     0,     0,     0,    10,    12,
      14,    20,     0,     0,     0,     0,    25,     0,    59,    60,
      45,    48,     0,    36,    24,    30,     0,    32,    43,    21,
       0,    46,     0,     0,     0,    16,     0,    26,    44,    49,
      16,     0,    47,     0,    27,     0,     0,    28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    31,     4,    10,    61,    62,    63,    11,    32,
     140,   160,    45,   154,   166,   181,   185,    46,    48,    33,
     169,   174,   153,   176,   170,    89,    57,    58,   109,    74,
      75,    76
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -90
static const yytype_int16 yypact[] =
{
      -6,   -90,    43,   -90,    12,   -90,    59,    67,    94,   146,
     -90,    80,    72,    81,    83,   106,   119,   121,   125,    87,
      90,   -90,   -90,    92,   -90,    91,    96,    97,    22,   133,
     -90,   -90,   -90,   104,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,   -90,     5,     9,    22,   120,   151,   156,   -90,   -90,
     -90,   122,   -90,   -90,   131,    22,   141,    58,    89,   142,
     -90,   147,   148,   149,   178,   179,    17,    25,    29,     5,
     -90,   -90,   150,     3,   153,   -90,   -90,   178,   179,    10,
       9,   -17,   145,     9,   172,   157,   128,   152,    22,   154,
     -90,    25,    25,    25,    25,    25,    25,   -90,    22,     9,
      22,    22,    22,    22,     5,   -90,   -90,   186,   -90,    -4,
     -90,    29,   -90,    29,     9,   -90,   155,    13,   158,    22,
     159,   -90,   -90,   -90,    64,    64,   -90,   -90,   -90,   -90,
     162,    32,   163,   -90,   -90,   -90,   161,   -90,   153,   -90,
     151,   180,   -90,     9,   164,     9,    25,    25,   -90,   -90,
     -90,   -90,    22,    -3,   151,    46,   -90,    47,    64,    64,
     191,   -90,    22,   -90,   -90,   -90,   173,   -90,   -90,   -90,
     165,   -90,   186,   167,   151,   -90,   168,   -90,   -90,   151,
     -90,   201,   151,    73,   -90,   169,   151,   -90
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -90,   -90,   208,   -90,   -90,   -90,   -90,   -90,   -44,   -46,
     -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,    28,
     -90,   -90,   -90,   -90,   -90,   -27,   -89,    19,   -36,   100,
     -63,    48
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -72
static const yytype_int16 yytable[] =
{
      84,    56,   124,   125,    86,   108,    73,    81,    64,    65,
      66,   162,    77,    78,    79,    72,   103,    82,   111,     6,
       7,     8,     9,   103,   115,    52,    53,    54,    52,    53,
     105,   111,    77,    78,   107,    67,     1,   137,   111,    67,
     163,   112,    68,     5,   114,    69,    68,   117,   111,    80,
     139,   104,   -71,   -71,   142,    70,    71,   158,   159,    70,
      71,   122,    55,   131,    12,    55,    68,   111,   136,    80,
     149,   130,    13,   132,   133,   134,   135,   122,   136,    70,
      71,   111,   111,    91,    92,    18,   106,   165,   167,   146,
     147,    19,   144,    20,   151,    21,    22,    23,    24,    14,
      25,    26,    27,    28,    29,    40,    41,   155,   164,   157,
      34,    37,   126,   127,   128,   129,    93,    94,    95,    35,
      96,    36,     1,    30,    38,   161,    39,    43,   178,    49,
      44,   179,    47,    18,    50,   171,   182,    51,    59,    19,
     187,    20,    60,    21,    22,    23,    24,   120,    25,    26,
      27,    28,    29,    15,    16,    17,    18,    40,    41,    42,
      83,    85,    19,    87,    20,    88,    21,    22,    23,    24,
       1,    25,    26,    27,    28,    29,    77,    78,   172,    90,
      97,    98,    99,   100,   101,   102,   116,   118,   110,   113,
     121,   119,   103,     1,   152,   123,   111,   141,   143,   145,
     148,   150,   156,   168,   175,   177,   183,   180,     3,   184,
     186,   138,     0,     0,   173
};

static const yytype_int16 yycheck[] =
{
      46,    28,    91,    92,    48,    68,    42,    43,     3,     4,
       5,    14,     3,     4,     5,    42,     6,    44,    35,     7,
       8,     9,    10,     6,    41,     3,     4,     5,     3,     4,
       5,    35,     3,     4,     5,    30,    42,    41,    35,    30,
      43,    38,    37,     0,    34,    40,    37,    83,    35,    40,
     113,    34,    35,    36,    41,    50,    51,   146,   147,    50,
      51,    88,    40,    99,     5,    40,    37,    35,   104,    40,
      38,    98,     5,   100,   101,   102,   103,   104,   114,    50,
      51,    35,    35,    25,    26,     5,    67,    41,    41,    25,
      26,    11,   119,    13,   140,    15,    16,    17,    18,     5,
      20,    21,    22,    23,    24,    32,    33,   143,   154,   145,
      38,     5,    93,    94,    95,    96,    27,    28,    29,    38,
      31,    38,    42,    43,     5,   152,     5,    40,   174,    38,
      40,   175,    40,     5,    38,   162,   180,    40,     5,    11,
     186,    13,    38,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     7,     8,     9,     5,    32,    33,    34,
      40,     5,    11,    41,    13,    34,    15,    16,    17,    18,
      42,    20,    21,    22,    23,    24,     3,     4,     5,    38,
      38,    34,    34,    34,     6,     6,    41,    15,    38,    36,
      38,    34,     6,    42,    14,    41,    35,    42,    40,    40,
      38,    38,    38,    12,    39,    38,     5,    39,     0,   181,
      41,   111,    -1,    -1,   166
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    53,    54,    55,     0,     7,     8,     9,    10,
      56,    60,     5,     5,     5,     7,     8,     9,     5,    11,
      13,    15,    16,    17,    18,    20,    21,    22,    23,    24,
      43,    54,    61,    71,    38,    38,    38,     5,     5,     5,
      32,    33,    34,    40,    40,    64,    69,    40,    70,    38,
      38,    40,     3,     4,     5,    40,    77,    78,    79,     5,
      38,    57,    58,    59,     3,     4,     5,    30,    37,    40,
      50,    51,    77,    80,    81,    82,    83,     3,     4,     5,
      40,    80,    77,    40,    61,     5,    60,    41,    34,    77,
      38,    25,    26,    27,    28,    29,    31,    38,    34,    34,
      34,     6,     6,     6,    34,     5,    79,     5,    82,    80,
      38,    35,    38,    36,    34,    41,    41,    80,    15,    34,
      19,    38,    77,    41,    78,    78,    79,    79,    79,    79,
      77,    80,    77,    77,    77,    77,    80,    41,    81,    82,
      62,    42,    41,    40,    77,    40,    25,    26,    38,    38,
      38,    61,    14,    74,    65,    80,    38,    80,    78,    78,
      63,    77,    14,    43,    61,    41,    66,    41,    12,    72,
      76,    77,     5,    83,    73,    39,    75,    38,    61,    60,
      39,    67,    60,     5,    71,    68,    41,    61
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 43 "cx.y"
    {
 	int temp;
 	for(temp = 0; temp < cx7count; temp++)
 		code[cx7[temp]-1].a = cx;
 }
    break;

  case 6:
#line 53 "cx.y"
    {
 	id = (yyvsp[(2) - (3)].name);
	printf("aid\n");
	gen(inn,0,1,int_t);
 	enter(variable,int_t);
 }
    break;

  case 7:
#line 59 "cx.y"
    {
  	id = (yyvsp[(2) - (3)].name);
	printf("bid\n");
	gen(inn,0,1,bool_t);
 	enter(variable,bool_t);
 }
    break;

  case 8:
#line 65 "cx.y"
    {
  	id = (yyvsp[(2) - (3)].name);
	printf("bid\n");
	gen(inn,0,1,bool_t);
 	enter(variable,double_t);
 }
    break;

  case 9:
#line 70 "cx.y"
    {
	id = (yyvsp[(3) - (3)].name);
	gen(inn,0,1,int_t);
 	enter(constant,int_t);
 }
    break;

  case 10:
#line 74 "cx.y"
    {
 	int t = position((yyvsp[(3) - (7)].name));
	if(t > 0){
		gen(sto,0,getaddr(t),gettype(t));
	}
	else{
	yyerror("this variable don't exists.");
	}
 }
    break;

  case 11:
#line 83 "cx.y"
    {
	id = (yyvsp[(3) - (3)].name);
	gen(inn,0,1,bool_t);
 	enter(constant,bool_t);
 }
    break;

  case 12:
#line 87 "cx.y"
    {
 	int t = position((yyvsp[(3) - (7)].name));
	if(t > 0){
		gen(sto,0,getaddr(t),bool_t);
	}
	else{
		yyerror("this variable don't exists.");
	}
 }
    break;

  case 13:
#line 96 "cx.y"
    {
	id = (yyvsp[(3) - (3)].name);
	gen(inn,0,1,bool_t);
 	enter(constant,double_t);
 }
    break;

  case 14:
#line 100 "cx.y"
    {
 	int t = position((yyvsp[(3) - (7)].name));
 	if(t > 0){
		gen(sto,0,getaddr(t),gettype(t));
	}
	else{
	yyerror("this variable don't exists.");
	}
 }
    break;

  case 17:
#line 112 "cx.y"
    {
 	//printf("process int or double;\n");
	int t = position((yyvsp[(1) - (4)].name));
	if(t > 0){
		if(table[t].kind != variable)
			yyerror("this identifier should be a variable!");
		else if(table[t].type == 1){
			if(!(judgeeq(1,(yyvsp[(3) - (4)].var))||judgeeq(0,(yyvsp[(3) - (4)].var)))) {
				yyerror("this bool variable cannot be assigned by number excepts 1 and 0");
			}
			else{
				gen(sto,0,getaddr(t),bool_t);
			}
		}
		else{
			gen(sto,0,getaddr(t),gettype(t));
		}
	}
	else{
	yyerror("this variable don't exists.");
	}
 }
    break;

  case 18:
#line 134 "cx.y"
    {
 	//printf("process bool;\n");
	int t = position((yyvsp[(1) - (4)].name));
	if(t > 0){
		if(table[t].kind != variable)
			yyerror("this identifier should be a variable!");
		else if(table[t].type != 1){
			yyerror("this variable is not boolean type.");
		}
		else{
			gen(sto,0,getaddr(t),bool_t);
		}
	}
	else{
		yyerror("this variable don't exists.");	
	}
 }
    break;

  case 19:
#line 151 "cx.y"
    {
 	printf("process if\n");
 	cx1[cx1count] = cx;
 	cx1count+=1;
 	gen(jpc,0,0,int_t);
 }
    break;

  case 20:
#line 156 "cx.y"
    {
	cx1[cx1count] = cx;
 	cx1count+=1;
 	gen(jmp,0,0,int_t);
 }
    break;

  case 22:
#line 161 "cx.y"
    {
 	printf("process while\n");
 	cx2[cx2count] = cx;
 	cx2count+=1;
 }
    break;

  case 23:
#line 165 "cx.y"
    {
 	cx2[cx2count] = cx;
 	cx2count+=1;
 	gen(jpc,0,0,int_t);
 }
    break;

  case 24:
#line 169 "cx.y"
    {
	int temp;
	for(temp = 0; temp < cx6count; temp++){
 		code[cx6[temp]-1].a = cx;
 	}
 	cx6count = 0;

 	gen(jmp,0,cx2[cx2count-2],int_t);
	code[cx2[cx2count-1]].a = cx;
	cx2count -= 2;
 	for(temp = 0; temp < cx4count; temp++){
 		code[cx4[temp]-1].a = cx;
 	}
 	cx4count = 0;
 }
    break;

  case 25:
#line 184 "cx.y"
    {
 	printf("process int variable;\n");
	int t = position((yyvsp[(3) - (6)].name));
	if(t > 0){
		if(table[t].kind != variable)
			yyerror("this identifier should be a variable!");
		else if(table[t].type == 1){
			if(!(judgeeq(1,(yyvsp[(5) - (6)].var))||judgeeq(0,(yyvsp[(5) - (6)].var)))) {
				yyerror("this bool variable cannot be assigned by number excepts 1 and 0");
			}
			else{
				gen(sto,0,getaddr(t),bool_t);
			}
		}
		else{
			gen(sto,0,getaddr(t),gettype(t));
		}
	}
	else{
	yyerror("this variable don't exists.");
	}
	cx5[cx5count] = cx;
	cx5count+=1;
 }
    break;

  case 26:
#line 207 "cx.y"
    {
 	gen(jpc,0,0,int_t);//不满足跳到stmt后结束循环
 	gen(jmp,0,0,int_t);//否则执行stmt
 	cx5[cx5count] = cx;//注意gen和cx[cxcount]语句的先后，此时存储的是jmp后的那一条语句的位置。
 	cx5count+=1; 
 }
    break;

  case 27:
#line 212 "cx.y"
    {
   	gen(jmp,0,cx5[cx5count-2],int_t);//跳到第二个表达式前
 	cx5[cx5count] = cx;
 	cx5count+=1;
 	code[cx5[cx5count-2]-1].a = cx;
 }
    break;

  case 28:
#line 217 "cx.y"
    {
 	int temp;
  	//continue
  	for(temp = 0; temp < cx6count; temp++){
 		code[cx6[temp]-1].a = cx;
 	}
 	cx6count = 0;
 	//跳到第二个表达式后
 	gen(jmp,0,cx5[cx5count-2],int_t);
 	code[cx5[cx5count-2]-2].a = cx;
 	cx5count -= 3;
 	//break
 	for(temp = 0; temp < cx4count; temp++){
 		code[cx4[temp]-1].a = cx;
 	}
 	cx4count = 0;
 }
    break;

  case 29:
#line 234 "cx.y"
    {
	cx61[cx61count] = cx;
 	cx61count += 1;
 	cx8[cx8count] = cx;
 	cx8count += 1;
 	//printf("oooops%d\n",cx);
 }
    break;

  case 30:
#line 241 "cx.y"
    { 	
 	gen(jpc2,0,code[cx8[cx8count-1]].a,int_t);
 	cx8count -= 1;
 	int temp;
 	for(temp = 0; temp < cx4count; temp++){
 		code[cx4[temp]-1].a = cx;
 	}
 	cx4count = 0;
 }
    break;

  case 31:
#line 250 "cx.y"
    {
	cx61[cx61count] = cx;
 	cx61count += 1;
 	cx9[cx9count] = cx;
 	cx9count += 1;
 }
    break;

  case 32:
#line 256 "cx.y"
    { 	
 	gen(jpc,0,code[cx9[cx9count-1]].a,int_t);
 	cx9count -= 1;
 	int temp;
 	for(temp = 0; temp < cx4count; temp++){
 		code[cx4[temp]-1].a = cx;
 	}
 	cx4count = 0;
 }
    break;

  case 34:
#line 266 "cx.y"
    {
 	int t = position((yyvsp[(2) - (3)].name));
 	if(t > 0){
 		gen(red, 0, getaddr(t), gettype(t));
 	}
 	else{
 		yyerror("this variable don't exists.");
 	}
 }
    break;

  case 36:
#line 276 "cx.y"
    {
 	int temp;
 	//printf("cxxxxxxxxxxxx%d\n",cx);
 	for(temp = 0; temp < cx4count; temp++){
 		code[cx4[temp]-1].a = cx;
 		//printf("%d\n",cx4[temp]);
 	}
 	cx4count = 0;
 }
    break;

  case 38:
#line 286 "cx.y"
    {
 	gen(jmp,0,0,int_t);
 	cx4[cx4count] = cx;
 	cx4count += 1;
 }
    break;

  case 39:
#line 291 "cx.y"
    {
  	if(cx61count != 0){
 		gen(jmp,0,cx61[cx61count - 1],int_t);
 		cx61count -= 1;
 	}
 	else{
	 	gen(jmp,0,0,int_t);
	 	cx6[cx6count] = cx;
	 	cx6count += 1;
	}
 }
    break;

  case 40:
#line 302 "cx.y"
    {
 	gen(jmp,0,0,int_t);
 	cx7[cx7count] = cx;
 	cx7count += 1;
 }
    break;

  case 41:
#line 308 "cx.y"
    {
 	int t = position((yyvsp[(1) - (2)].name));
 	if(t > 0){
 		gen(lod,0,getaddr(t),gettype(t));
 	}
 	else{
 		yyerror("this variable don't exists."); 		
 	}
  	genplus(lit,0,1,int_t,1);
 	gen(opr,0,2,int_t);
 	gen(sto,0,getaddr(t),bool_t);
 }
    break;

  case 42:
#line 320 "cx.y"
    {
 	int t = position((yyvsp[(1) - (2)].name));
 	if(t > 0){
 		gen(lod,0,getaddr(t),gettype(t));
 	}
 	else{
 		yyerror("this variable don't exists."); 		
 	}
  	genplus(lit,0,1,int_t,1);
 	gen(opr,0,3,int_t);
 	gen(sto,0,getaddr(t),bool_t);
 }
    break;

  case 43:
#line 332 "cx.y"
    {
 	printf("else statement\n");
 	code[cx1[cx1count-2]].a = cx;
 }
    break;

  case 44:
#line 335 "cx.y"
    {
 	code[cx1[cx1count-1]].a = cx;
 	cx1count -= 2;
 }
    break;

  case 45:
#line 338 "cx.y"
    {
 	cx1count-=1;
 	code[cx1[cx1count]].a = cx;
 	cx1count-=1;
 	code[cx1[cx1count]].a = cx;
 	//printf("code:%d,%d\n",code[cx1[cx1count]].f,cx);
 }
    break;

  case 46:
#line 346 "cx.y"
    {
 	//现在数据栈栈顶t是上一次的比较结果，t-1是switch里的aexpr的值
 	gen(jpcc2,0,cx+2,bool_t);//如果t是1那么直接忽略case语句,也就是往后跳2条语句
 	gen(opr,0,19,bool_t);//走到这里说明上一次的case语句不符合，也就没必要再存了，因此现在t-1是switch的aexpr，t是第二次比较的结果
 	cx3[cx3count] = cx;
 	cx3count+=1;
 	gen(jpc,0,0,int_t);
 }
    break;

  case 47:
#line 353 "cx.y"
    {
 	code[cx3[cx3count-1]].a = cx;
 	//gen(del,0,1,int_t);//栈顶比较完后就删了，保证栈顶变成t
 }
    break;

  case 48:
#line 357 "cx.y"
    {
 	gen(opr,0,18,bool_t);//t-1是switch的aexpr，t是第二次比较的结果，
 	cx3[cx3count] = cx;
 	printf("cx3:%d\n",cx3[cx3count]);
 	cx3count+=1;
 	gen(jpcc,0,0,int_t);//这一条肯定是第一条case，因此要保留第一个比较结果
 }
    break;

  case 49:
#line 363 "cx.y"
    {
 	code[cx3[cx3count-1]].a = cx;
 	//gen(del,0,1,int_t);
 }
    break;

  case 50:
#line 368 "cx.y"
    {
 	gen(opr,0,2,int_t);
 	}
    break;

  case 51:
#line 371 "cx.y"
    {
 	gen(opr,0,3,int_t);
 	}
    break;

  case 52:
#line 374 "cx.y"
    {
 }
    break;

  case 53:
#line 376 "cx.y"
    {
	yyerror("cannot apply multiply assign symbol.");
 }
    break;

  case 54:
#line 380 "cx.y"
    {
 	gen(opr,0,4,int_t);
 	}
    break;

  case 55:
#line 383 "cx.y"
    {
 	gen(opr,0,5,int_t);
 	}
    break;

  case 56:
#line 386 "cx.y"
    {
 	gen(opr,0,16,int_t);
 	}
    break;

  case 57:
#line 389 "cx.y"
    {
 	gen(opr,0,17,int_t);
 	}
    break;

  case 59:
#line 393 "cx.y"
    {
 	yyerror("cann't apply more than one plus without p."); 		
 	}
    break;

  case 60:
#line 396 "cx.y"
    {
 yyerror("cann't apply more than one minus without p."); 		
 }
    break;

  case 61:
#line 400 "cx.y"
    {
 	int t = position((yyvsp[(1) - (1)].name));
 	if(t > 0){
 		gen(lod,0,getaddr(t),gettype(t));
 	}
 	else{
 		yyerror("this variable don't exists."); 		
 	}
 }
    break;

  case 62:
#line 409 "cx.y"
    {
 	genplus(lit,0,(yyvsp[(1) - (1)].var),int_t,(yyvsp[(1) - (1)].var));
 	}
    break;

  case 63:
#line 412 "cx.y"
    {
 	genplus(lit,0,(yyvsp[(1) - (1)].var),double_t,(yyvsp[(1) - (1)].var));
 	}
    break;

  case 64:
#line 415 "cx.y"
    {
 }
    break;

  case 65:
#line 418 "cx.y"
    {
 	gen(opr,0,15,bool_t);
 	}
    break;

  case 67:
#line 422 "cx.y"
    {
 	gen(opr,0,6,bool_t); 	
 }
    break;

  case 68:
#line 425 "cx.y"
    {
	yyerror("cannot apply multiply assign symbol.");
 }
    break;

  case 69:
#line 429 "cx.y"
    {
 	gen(opr,0,14,bool_t);
 }
    break;

  case 71:
#line 434 "cx.y"
    {
 	int t = position((yyvsp[(1) - (1)].name));
 	if(t > 0){
 		if(table[t].type != 1)
			yyerror("this variable is not boolean type.");
		else{
 			gen(lod,0,getaddr(t),gettype(t));
		}
 	}
 	else{
 		yyerror("this variable don't exists"); 	
 	}
 }
    break;

  case 72:
#line 447 "cx.y"
    {
  	printf("bool variable;\n");
 	genplus(lit,0,1,bool_t,1);
 }
    break;

  case 73:
#line 451 "cx.y"
    {
 	genplus(lit,0,0,bool_t,1);
 }
    break;

  case 74:
#line 454 "cx.y"
    {
 	gen(opr,0,1,bool_t);
 	}
    break;

  case 77:
#line 460 "cx.y"
    {
 	int t = position((yyvsp[(1) - (3)].name));
 	double temp = 0;
 	if(t > 0){
 		if(table[t].type != 0){
			yyerror("this variable don't have correct type.");		
 		}
 	}
 	else{
 		yyerror("this variable don't exists."); 	
 	}
 	if(strcmp((yyvsp[(2) - (3)].name), "<") == 0){
 	 	gen(lod,0,getaddr(t),gettype(t));
 	 	gen(opr,0,10,bool_t);
 	}
 	else if(strcmp((yyvsp[(2) - (3)].name), "<=") == 0){
 	 	gen(lod,0,getaddr(t),gettype(t));
 	 	gen(opr,0,13,bool_t);
 	}
 	else if(strcmp((yyvsp[(2) - (3)].name), ">") == 0){
 	 	gen(lod,0,getaddr(t),gettype(t));
 	 	gen(opr,0,12,bool_t);
 	}
 	else if(strcmp((yyvsp[(2) - (3)].name), ">=") == 0){
 	 	gen(lod,0,getaddr(t),gettype(t));
 	 	gen(opr,0,11,bool_t);
 	}
 	else if(strcmp((yyvsp[(2) - (3)].name), "==") == 0){
 	 	gen(lod,0,getaddr(t),gettype(t));
 	 	gen(opr,0,8,bool_t);
 	}
 	else if(strcmp((yyvsp[(2) - (3)].name), "!=") == 0){
 	 	gen(lod,0,getaddr(t),gettype(t));
 	 	gen(opr,0,9,bool_t);
 	}
 	else
 		yyerror("wrong relop type\n");	
 }
    break;

  case 78:
#line 498 "cx.y"
    {
 	printf("num,relop,expr\n");
 	if(strcmp((yyvsp[(2) - (3)].name), "<") == 0){
 	 	genplus(lit,0,(yyvsp[(1) - (3)].var),int_t,(yyvsp[(1) - (3)].var));
 	 	gen(opr,0,10,bool_t);
 	}
 	else if(strcmp((yyvsp[(2) - (3)].name), "<=") == 0){
 	 	genplus(lit,0,(yyvsp[(1) - (3)].var),int_t,(yyvsp[(1) - (3)].var));
 	 	gen(opr,0,13,bool_t);
 	}
 	else if(strcmp((yyvsp[(2) - (3)].name), ">") == 0){
 	 	genplus(lit,0,(yyvsp[(1) - (3)].var),int_t,(yyvsp[(1) - (3)].var));
 	 	gen(opr,0,12,bool_t);
 	}
 	else if(strcmp((yyvsp[(2) - (3)].name), ">=") == 0){
 	 	genplus(lit,0,(yyvsp[(1) - (3)].var),int_t,(yyvsp[(1) - (3)].var));
 	 	gen(opr,0,11,bool_t);
 	}
 	else if(strcmp((yyvsp[(2) - (3)].name), "==") == 0){
 	 	genplus(lit,0,(yyvsp[(1) - (3)].var),int_t,(yyvsp[(1) - (3)].var));
 	 	gen(opr,0,8,bool_t);
 	}
 	else if(strcmp((yyvsp[(2) - (3)].name), "!=") == 0){
 	 	genplus(lit,0,(yyvsp[(1) - (3)].var),int_t,(yyvsp[(1) - (3)].var));
 	 	gen(opr,0,9,bool_t);
 	}
 	else
 		yyerror("wrong relop type\n");
 }
    break;

  case 79:
#line 527 "cx.y"
    {
 	printf("rnum,relop,expr\n");
 	if(strcmp((yyvsp[(2) - (3)].name), "<") == 0){
 	 	genplus(lit,0,(yyvsp[(1) - (3)].var),double_t,(yyvsp[(1) - (3)].var));
 	 	gen(opr,0,10,bool_t);
 	}
 	else if(strcmp((yyvsp[(2) - (3)].name), "<=") == 0){
 	 	genplus(lit,0,(yyvsp[(1) - (3)].var),double_t,(yyvsp[(1) - (3)].var));
 	 	gen(opr,0,13,bool_t);
 	}
 	else if(strcmp((yyvsp[(2) - (3)].name), ">") == 0){
 	 	genplus(lit,0,(yyvsp[(1) - (3)].var),double_t,(yyvsp[(1) - (3)].var));
 	 	gen(opr,0,12,bool_t);
 	}
 	else if(strcmp((yyvsp[(2) - (3)].name), ">=") == 0){
 	 	genplus(lit,0,(yyvsp[(1) - (3)].var),double_t,(yyvsp[(1) - (3)].var));
 	 	gen(opr,0,11,bool_t);
 	}
 	else if(strcmp((yyvsp[(2) - (3)].name), "==") == 0){
 	 	genplus(lit,0,(yyvsp[(1) - (3)].var),double_t,(yyvsp[(1) - (3)].var));
 	 	gen(opr,0,8,bool_t);
 	}
 	else if(strcmp((yyvsp[(2) - (3)].name), "!=") == 0){
 	 	genplus(lit,0,(yyvsp[(1) - (3)].var),double_t,(yyvsp[(1) - (3)].var));
 	 	gen(opr,0,9,bool_t);
 	}
 	else
 		yyerror("wrong relop type\n");
 }
    break;


/* Line 1267 of yacc.c.  */
#line 2360 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 557 "cx.y"

 int main(int argc, char *argv[])
 {
 	int i;
 	for(i = 0; i < argc ; i++){
 		if (strcmp(argv[i],"-f") == 0 && argc > i)
 		{
 			yyin = fopen(argv[++i] ,"r");
 		}
 	}
 	printf("**********CX Compiler:************\n");
	yyparse();
	printf("************pcode:****************\n");
	printpcode();
	interpret();

	return 0;
 }
 int yyerror(char *msg)
 {
 printf("Error encountered: %d:  %s at %s\n", yylineno, msg, yytext);
 return 1;
 }
