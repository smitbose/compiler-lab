%{
#define INT_TOK 1
#define FLOAT_TOK 2
#define CHAR_TOK 3
#define EQ_TOK 4
#define PLUS_TOK 5
#define MINUS_TOK 6
#define DIV_TOK 7
#define MULT_TOK 8
#define XOR_TOK 9
#define GREQ_TOK 10
#define LSEQ_TOK 11
#define GR_TOK 12
#define LS_TOK 13
#define NOT_TOK 14
#define NOTEQ_TOK 15
#define AND_TOK 16
#define OR_TOK 17
#define IF_TOK 18
#define ELSE_TOK 19
#define SWITCH_TOK 20
#define CASE_TOK 21
#define WHILE_TOK 22
#define FOR_TOK 23
#define COMMA_TOK 24
#define SEMICOL_TOK 25
#define LPAREN_TOK 26
#define RPAREN_TOK 27
#define ID_TOK 28
#define NUM_TOK 29
#define REAL_TOK 30
#define LBRACE_TOK 31
#define RBRACE_TOK 32
char *yylval;
char *insert_id();
char *insert_intconst();
char *insert_real();
struct tok
{
	int type;
	char *lexeme;
	struct tok *next;
};
struct table
{
	struct tok *arr[255];	
}symtable;
%}
%%

int return INT_TOK;
float return FLOAT_TOK;
char return CHAR_TOK;
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
[ \t\n]+ ;
\{ return LBRACE_TOK;
\} return RBRACE_TOK;
%%
int main(int argc,char *argv[])
{
	int i;
	for(i=0;i<255;i++)
		symtable.arr[i] = NULL;
	if(argc == 1)
		yyin = stdin;
	else
		yyin = fopen(argv[1],"r");
	int token;
	while((token = yylex())!=0)
	{
		printf("%d\n",token);
	}
	return 0;
}
int yywrap()
{
	return 1;
}
char *insert_intconst()
{
	struct tok *newtok = (struct tok *)malloc(sizeof(struct tok));
	newtok->lexeme = (char *)malloc((yyleng+1)*sizeof(char));
	strcpy(newtok->lexeme,yytext);
	newtok->type = 1;
	int pos = (yytext[0]+yytext[yyleng-1])/2;
	newtok->next = symtable.arr[pos];
	symtable.arr[pos] = newtok;
	return yytext;
}
char *insert_id()
{
	struct tok *newtok = (struct tok *)malloc(sizeof(struct tok));
	newtok->lexeme = (char *)malloc((yyleng+1)*sizeof(char));
	strcpy(newtok->lexeme,yytext);
	newtok->type = 2;
	int pos = (yytext[0]+yytext[yyleng-1])/2;
	newtok->next = symtable.arr[pos];
	symtable.arr[pos] = newtok;
	return yytext;
}
char *insert_real()
{
	struct tok *newtok = (struct tok *)malloc(sizeof(struct tok));
	newtok->lexeme = (char *)malloc((yyleng+1)*sizeof(char));
	strcpy(newtok->lexeme,yytext);
	newtok->type = 3;
	int pos = (yytext[0]+yytext[yyleng-1])/2;
	newtok->next = symtable.arr[pos];
	symtable.arr[pos] = newtok;
	return yytext;
}