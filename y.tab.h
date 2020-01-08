/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 33 "cx.y"
{
	double var;
	char* name;
}
/* Line 1529 of yacc.c.  */
#line 156 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

