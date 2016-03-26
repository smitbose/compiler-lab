#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSIZE 20

//Create the Parsing Table

char PrsTable[6][7][10] = {
	"NT",  "<id>",   "+",     "*",     "(",    ")",      "$",
	"E" ,  "TH",    "Error", "Error", "TH",    "Error",  "Error",
    "H",  "Error",  "+TH",  "Error",  "Error", " ",      " ",
    "T",   "FU",    "Error", "Error", "FU",    "Error",  "Error",
    "U",  "Error",  " ",     "*FU",   "Error", " ",      " ",
	"F",   "i",     "Error", "Error", "(E)",   "Error",  "Error"
};

//————————————————————————————————————

void ParsingTable_View(); //TODO
void parse(char []);
char * strrev(char []); //TODO
void push(char []);
char TOS(); //read only the Top Symbol TODO
void pop(); //TODO
void display(); // Display the Stack Content TODO
void display1(char [], int); // Display the Content From Input Buffer TODO

//——————————————————————————————————————

int main(int argc, char *argv[])
{
	char ip[30];
	ParsingTable_View();
	printf("Enter The String To Be Parsed:");
	scanf("%s", string);
	yyin = fopen(argv[1], “r”);
	i= 0;
	while(!feof(yyin))
	{

		token = yylex();
		if ( token >= id_min && token <= id_max )
			ip[i] = 'i';
		else
			ip[i] = tpken;
		i++;
	}
	ip[i] = ‘$’;


	printf("Starting parser...\n");
	parse(ip);

	return 0;
}	

void ParsingTable_View()
{
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<7;j++)
		{
			printf("%s",PrsTable[i][j]);
		}
		printf("\n");
	}
}

void parse(char ip[])
{
  int j = 0, ir, ic;
  char an,st,r[20];

  push("$E");
  display(); 
  printf("          ");
  display1(ip,j);
  printf("\n");

  for (j = 0; ip[j]!='\0';)
  {
 
  		//read the top and left most symbol from the input buffer
      an = ip[j];        
      st = TOS();

	//     printf("st ==== %c ==== an=== %c", st,an);

     if (st == 'E') ir = 1;
     else if(st == 'H') ir = 2;
     else if(st == 'T')  ir = 3;
     else if(st == 'U') ir = 4;
     else if(st == 'F') ir = 5;
    
	 if(an == 'i')
	 	ic = 1;
	 else if(an == '+')
	 	ic = 2;
	 else if(an == '*')
	 	ic = 3;
	 else if(an == '(')
	 	ic = 4;
	 else if(an == ')')
	 	ic = 5;
	 else if(an == 's')
	 	ic = 6;    
    if (TOS()=='$' && an == '$') 
    {
    	printf("Accept");
    	break;
    }

    else if(st  == an)
              {
                pop();
              	display();
                printf("*****=");
                display1(ip,j+1);
                st=TOS();
                printf("==========>"); display();
                printf("\n");             
                j++;     
              }
    else if((st == 'E' || st == 'H' || st == 'T' || st == 'U' || st == 'F') && (strcmp(PrsTable[ir][ic], " ")!=0 ))
          {
           // printf("TOP is NT \n");         
            pop();
            strrev(PrsTable[ir][ic]);
            push(rev);
            display(); 
            printf("**********Stk");
            display1(ip,j);
            printf("st=%c %c----- rev =%s",st,TOS(),rev);
            st = TOS();   
            printf("\n");
          }
    else if(strcmp(PrsTable[ir][ic], " ")==0)
          {
            pop();
            display(); 
            printf("**********P");
            display1(ip,j);   
            printf("\n");
          }
      else
              {
                 printf("Syntax Error");
                 break;
                }  
    }
}

%——————————————————————————————

void push(char k[])
{
    int i;
	for (i=0;k[i]!='\0';i++)
	{
		if (top < 9)
			a[++top]=k[i];
	}
}
void pop()
{
	top--;
}
char *strrev(char str[])
{
	int l = strlen(str);
	char *newstr = (char *)malloc((l+1)*sizeof(char));
	for(int i=0;i<l;i++)
	{
		newstr[i] = str[l-i-1];
	}
	return newstr;
}
char TOS()
{
	return a[top];
}
void display()
{
	for(int i=0;i<=top;i++)
		printf("%c\n",a[i]);
}
void display1(char str[], int pos)
{
	printf("%c",str[pos]);
}