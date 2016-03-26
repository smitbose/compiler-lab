#include <bits/stdc++.h>
using namespace std;
/*single character tokens */
#define LPAREN_TOK '('
#define GT_TOK '>'
#define RPAREN_TOK ')'
#define EQ_TOK '='
#define MINUS_TOK '-'
#define SEMICOLON_TOK ';'
#define COMMA_TOK ','
#define LT_TOK '<'
#define PLUS_TOK '+'
#define MULT_TOK '*'
#define DIV_TOK '/'
#define RBRACE_TOKEN '}'
#define LBRACE_TOKEN '{'

/*reserved keywords*/
#define WHILE_TOK 256
#define FOR_TOK 257
#define IF_TOK 258
#define ELSE_TOK 259

/*identifiers*/
#define ID_TOK 350
#define INTCONST_TOK 351

/*error token*/
#define ERR_TOK 400

FILE *yyin;
char *yytext;
int yyleng;

int yylex(FILE *);

int main(int argc,char *argv[])
{
	int token;
	yytext = (char *)malloc(10*sizeof(char));
	if(argc<2)
		yyin = stdin;
	else
		yyin = fopen(argv[1],"r");

	while(!feof(yyin))
	{
		token = yylex(yyin);
		printf("%d\n",token);
	}
	return 0;
}


int yylex(FILE *file)
{
	char ch = getc(file);
	while(isspace(ch))
		ch = getc(file);
	//cout<<ch<<endl;
	int i;
	for(int i=0;i<10;i++)
		yytext[i] = '\0';
	switch(ch)
	{
		case '=':
		case '+':
		case '-':
		case '/':
		case '*':
		case '>':
		case '<':
		case '(':
		case ')':
		case '{':
		case '}':
		case ';':
		case ',':
			yytext[0] = ch;
			yyleng = 1;
			return ch;

		case 'a':case 'b':case 'c':case 'd':case 'e':case 'f':case 'g':case 'h':case 'i':case 'j':case 'k':case 'l':case 'm':
		case 'n':case 'o':case 'p':case 'q':case 'r':case 's':case 't':case 'u':case 'v':case 'w':case 'x':case 'y':case 'z':
		case 'A':case 'B':case 'C':case 'D':case 'E':case 'F':case 'G':case 'H':case 'I':case 'J':case 'K':case 'L':case 'M':
		case 'N':case 'O':case 'P':case 'Q':case 'R':case 'S':case 'T':case 'U':case 'V':case 'W':case 'X':case 'Y':case 'Z':


			yytext[0] = ch;
			i = 1;
			ch = getc(file);
			while(((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')) && !feof(file))
			{
				yytext[i++] = ch;
				ch = getc(file);
			}
			ungetc(ch,file);
			yyleng = i;
			//cout<<yytext<<endl;
			if(strcmp(yytext,"while") == 0)
				return WHILE_TOK;
			else if(strcmp(yytext,"if") == 0)
				return IF_TOK;
			else if(strcmp(yytext,"else") == 0)
				return ELSE_TOK;
			else if(strcmp(yytext,"for") == 0)
				return FOR_TOK;
			else
				return ID_TOK;

		case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':

			yytext[0] = ch;
			i = 1;
			ch = getc(file);
			while(ch>='0' && ch<='9')
			{
				yytext[i++] = ch;
				ch = getc(file);
			}
			ungetc(ch,file);
			//cout<<yytext<<endl;
		default:
			return ERR_TOK;
	}
}