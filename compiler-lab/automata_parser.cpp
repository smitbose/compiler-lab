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

int accept[50];

int yylex(FILE *);
int dfa(char,int);

int main(int argc,char *argv[])
{
	int token;
	yytext = (char *)malloc(10*sizeof(char));
	for(int i=0;i<50;i++)
	{
		accept[i] = -1;
	}
	accept[6] = ID_TOK;
	accept[8] = FOR_TOK;
	accept[12] = WHILE_TOK;
	accept[13] = IF_TOK;
	accept[16] = ELSE_TOK;
	accpet[17] = PLUS_TOK;
	accpet[18] = PLUSPLUS_TOK;
	accept[19] = PLUSEQUAL_TOK;
	accept[20] = MINUS_TOK;
	accept[21] = MULT_TOK;
	accept[22] = DIV_TOK;
	accept[23] = LPAREN_TOK;
	accept[24] = RPAREN_TOK;
	accept[25] = LBRACE_TOKEN;
	accept[26] = RBRACE_TOKEN;
	accept[27] = EQ_TOK;
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
	int state = dfa(ch,0);
	if(inaccepting(state))
		return accept[state];
}

int dfa(FILE *ch,int state)
{
	char inp = getc(file);
	if(state == 0)
	{
		if(inp == 'f')
		{
			return dfa(ch,2);
		}
		else if(inp == 'w')
		{
			return dfa(ch,3);
		}
		else if(inp == 'i')
		{
			return dfa(ch,4);
		}
		else if(inp == 'e')
			return dfa(ch,5);
		else if(inp == '+')
			return dfa(ch,17);
		else if(inp == '-')
			return dfa(ch,20);
		else if(inp == '-')
			return dfa(ch,21);
		else if(inp == '{')
			return dfa(ch,25);
		else if(inp == '}')
			return dfa(inp,26);
		else if(inp == '/')
			return dfa(ch,22);
		else if(inp == '(')
			return dfa(ch,23);
		else if(inp == ')')
			return dfa(ch,24);
		else if(inp == '=')
			return dfa(ch,27);
	}
	else if(state == 2)
	{
		if(inp == 'o')
			return dfa(ch,7);
		else if((inp<='z' && inp>='a') || (inp<='Z' && inp>='A') || (inp<='9' && inp>='0'))
			return dfa(ch,6);
	}
	else if(state == 3)
	{
		if(inp == 'h')
			return dfa(ch,9);
		else if((inp<='z' && inp>='a') || (inp<='Z' && inp>='A') || (inp<='9' && inp>='0'))
			return dfa(ch,6);
	}
	else if(state == 4)
	{
		if(inp == 'f')
			return dfa(ch,13);
		else if((inp<='z' && inp>='a') || (inp<='Z' && inp>='A') || (inp<='9' && inp>='0'))
			return dfa(ch,6);
	}
	else if(state == 5)
	{
		if(inp == 'l')
			return dfa(ch,14);
		else if((inp<='z' && inp>='a') || (inp<='Z' && inp>='A') || (inp<='9' && inp>='0'))
			return dfa(ch,6);
	}
	else if(state == 6)
	{
		if((inp<='z' && inp>='a') || (inp>='A' && inp<='Z') || (inp<='9' && inp>='0'))
			return dfa(ch,6);
		else
		{
			ungetc(inp,ch);
			return state;
		}
	}
	else if(state == 7)
	{
		if(inp == 'r')
			return dfa(ch,8);
		else if((inp<='z' && inp>='a') || (inp<='Z' && inp>='A') || (inp<='9' && inp>='0'))
			return dfa(ch,6);
	}
	else if(state == 8)
	{
		ungetc(inp,ch);
		return state;
	}
	else if(state == 9)
	{
		if(inp == 'i')
			return dfa(ch,10);
		else if((inp<='z' && inp>='a') || (inp<='Z' && inp>='A') || (inp<='9' && inp>='0'))
			return dfa(ch,6);
			
	}
	else if(state == 10)
	{
		if(inp == 'l')
			return dfa(ch,11);
		else if((inp<='z' && inp>='a') || (inp<='Z' && inp>='A') || (inp<='9' && inp>='0'))
			return dfa(ch,6);
	}
	else if(state == 11)
	{
		if(inp == 'e')
			return dfa(ch,12);
		else if((inp<='z' && inp>='a') || (inp<='Z' && inp>='A') || (inp<='9' && inp>='0'))
			return dfa(ch,6);
	}
	else if(state == 12)
	{
		ungetc(inp,ch);
		return state;
	}
	else if(state == 13)
	{
		ungetc(inp,ch);
		return state;
	}
	else if(state == 14)
	{
		if(inp == 's')
			return dfa(ch,15);
		if((inp<='z' && inp>='a') || (inp<='Z' && inp>='A') || (inp<='9' && inp>='0'))
			return dfa(ch,6);
	}
	else if(state == 15)
	{
		if(inp == 'e')
			return dfa(ch,16);
		else if((inp<='z' && inp>='a') || (inp<='Z' && inp>='A') || (inp<='9' && inp>='0'))
			return dfa(ch,6);
	}
	else if(state == 16)
	{
		ungetc(inp,ch);
		return state;
	}
	else if(state == 17)
	{
		if(inp == '+')
			return dfa(ch,18);
		else if(inp == '=')
			return dfa(ch,19);
		else
		{
			ungetc(inp,ch);
			return state;
		}
	}
	else if(state == 18)
	{
		ungetc(inp,ch);
		return state;
	}
	else if(state == 19)
	{
		ungetc(inp,ch);
		return state;
	}
	else if(state == 20 || state == 21 || state == 22 || state == 23 || state == 24 || state == 25|| state == 26 || state == 27)
	{
		ungetc(inp,ch);
		return state;
	}
	
}

bool inaccepting(int state)
{
	if(accept[state] != -1)
		return true;
	return false;
}