%{
#include <stdio.h>
#include "y.tab.h"
%}
%%
= return EQ_TOK;
\+ return PLUS_TOK;
\- return MINUS_TOK;
\/ return DIV_TOK;
\* return MULT_TOK;
\^ return XOR_TOK;
\>\= return GREQ_TOK;
\<\= return LSEQ_TOK;
\> return GR_TOK;
\< return LS_TOK;
\! return NOT_TOK;
\!\= return NOTEQ_TOK;
\&\& return AND_TOK;
\|\| return OR_TOK;
if return IF_TOK;
else return ELSE_TOK;
switch return SWITCH_TOK;
case return CASE_TOK;
while return WHILE_TOK;
for return FOR_TOK;
, return COMMA_TOK;
; return SEMICOL_TOK;
\( return LPAREN_TOK;
\) return RPAREN_TOK;
[A-Za-z][A-Za-z0-9]* {yylval=insert_intconst(); return ID_TOK;}
[0-9]+ {yylval=insert_id(); return NUM_TOK;}
[0-9]+\.?[0-9]+ {yylval=insert_real(); return REAL_TOK;}
[ \t\n ]+ ;
\{ return LBRACE_TOK;
\} return RBRACE_TOK;
%%
int yywrap()
{
    return 1;
}
