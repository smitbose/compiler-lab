%{
#include <stdio.h>
#include "lex.yy.c"
%}
%token INTCONST PLUSTOK SUBTOK MULTTOK DIVTOK
%start E
%left '-' '+'
%left '*' '/'
%%
E	:	E PLUSTOK E {}
E	:	INTCONST {}
%%
int main(int argc,char *argv[])
{
	yyparse();
}
yyerror(s)
{
	printf("Got an error\n");
}