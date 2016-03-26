/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
    ID = 258,
    EQ_TOK = 259,
    PLUS_TOK = 260,
    MINUS_TOK = 261,
    DIV_TOK = 262,
    MULT_TOK = 263,
    XOR_TOK = 264,
    GREQ_TOK = 265,
    LSEQ_TOK = 266,
    GR_TOK = 267,
    LS_TOK = 268,
    NOT_TOK = 269,
    NOTEQ_TOK = 270,
    AND_TOK = 271,
    OR_TOK = 272,
    IF_TOK = 273,
    ELSE_TOK = 274,
    SWITCH_TOK = 275,
    CASE_TOK = 276,
    FOR_TOK = 277,
    COMMA_TOK = 278,
    SEMICOL_TOK = 279,
    WHILE_TOK = 280,
    LPAREN_TOK = 281,
    RPAREN_TOK = 282,
    RBRACE_TOK = 283,
    LBRACE_TOK = 284
  };
#endif
/* Tokens.  */
#define ID 258
#define EQ_TOK 259
#define PLUS_TOK 260
#define MINUS_TOK 261
#define DIV_TOK 262
#define MULT_TOK 263
#define XOR_TOK 264
#define GREQ_TOK 265
#define LSEQ_TOK 266
#define GR_TOK 267
#define LS_TOK 268
#define NOT_TOK 269
#define NOTEQ_TOK 270
#define AND_TOK 271
#define OR_TOK 272
#define IF_TOK 273
#define ELSE_TOK 274
#define SWITCH_TOK 275
#define CASE_TOK 276
#define FOR_TOK 277
#define COMMA_TOK 278
#define SEMICOL_TOK 279
#define WHILE_TOK 280
#define LPAREN_TOK 281
#define RPAREN_TOK 282
#define RBRACE_TOK 283
#define LBRACE_TOK 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
