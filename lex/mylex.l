%{
#include <stdio.h>
#include "symtable.c"

#define PLUS_TOK '+'
#define MINUS_TOK '-'
#define MULT_TOK '*'
#define DIV_TOK '/'
#define EQ_TOK '='
#define LPAREN_TOK '('
#define RPAREN_TOK ')'
#define LBRACE_TOK '{'
#define RBRACE_TOK '}'
#define GT_TOK '>'
#define LS_TOK '<'
#define OR_TOK '|'
#define AND_TOK '&'
#define NOT_TOK '!'
#define COMMA_TOK ','
#define SEMI_TOK ';'
#define OROR_TOK 257
#define ANDAND_TOK 258
#define GTEQ_TOK 259
#define LSEQ_TOK 260
#define NOTEQ_TOK 261
#define PLUSPLUS_TOK 262
#define MINUSMINUS_TOK 263
#define PLUSEQ_TOK 264
#define MINUSEQ_TOK 265
#define WHILE_TOK 266
#define FOR_TOK 267
#define IF_TOK 268
#define ELSE_TOK 269
#define INT_TOK 270
#define CHAR_TOK 271
#define FLOAT_TOK 272
#define MAIN_TOK 273
#define FUNC_TOK 274
#define ID_TOK 275
#define INTCONST_TOK 276
#define EQEQ_TOK 277
%}
%%
\= {return EQ_TOK;}
\+ {return PLUS_TOK;}
\- {return MINUS_TOK;}
\* {return MULT_TOK;}
\/ {return DIV_TOK;}
\( {return LPAREN_TOK;}
\) {return RPAREN_TOK;}
\{ {return LBRACE_TOK;}
\} {return RBRACE_TOK;}
\> {return GT_TOK;}
\< {return LS_TOK;}
\>\= {return GTEQ_TOK;}
\<\= {return LSEQ_TOK;}
\=\= {return EQEQ_TOK;}
\! {return NOT_TOK;}
\| {return OR_TOK;}
\& {return AND_TOK;}
\|\| {return OROR_TOK;}
\&\& {return ANDAND_TOK;}
\!\= {return NOTEQ_TOK;}
\, {return COMMA_TOK;}
\; {return SEMI_TOK;}
\+\+ {return PLUSPLUS_TOK;}
\-\- {return MINUSMINUS_TOK;}
\+\= {return PLUSEQ_TOK;}
\-\= {return MINUSEQ_TOK;}
while {return WHILE_TOK;}
for {return FOR_TOK;}
if {return IF_TOK;}
else {return ELSE_TOK;}
main {  insert(yytext,MAIN_TOK);
        return MAIN_TOK;}
int {return INT_TOK;}
char {return CHAR_TOK;}
float {return FLOAT_TOK;}
[A-Za-z]+ { insert(yytext,ID_TOK);
            return ID_TOK;}
[0-9]+ { insert(yytext,INTCONST_TOK); 
         return INTCONST_TOK;}
[A-Za-z]+/\( {  insert(yytext,FUNC_TOK);
                return FUNC_TOK;}
[\t\n ] {}
%%
int main(int argc,char *argv[])
{
    if(argc > 1)
    {
        yyin = fopen(argv[1],"r");
    }
    else
        yyin = stdin;
    int tok;
    while((tok = yylex())!='\0')
    {
        printf("%d\n",tok);
    }
    return 0;
}
int yywrap()
{
    return 1;
}
