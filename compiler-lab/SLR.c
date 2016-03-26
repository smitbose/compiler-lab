#include<stdio.h>
#include<string.h>

//#include<stdlib.h>
#define MAXSIZE 20

///---------------------------------------------------------------------

//Create the SLR Parsing Table
char PrsTable[13][12][10] = {
    {"State",    "<id>",   "+",     "*",     "(",    ")",     "$",    "E",  "T",  "F"},
    {"0" ,       "s5",     "",      "",      "s4",   "",      "",     "1",  "2",  "3"},
    {"1",        "",       "s6",    "",      "",     "",      "acc",  "",   "",   ""},
    {"2",        "",       "r2",    "s7",    "",     "r2",    "r2",   "",   "",   ""},
    {"3",        "",       "r4",    "r4",    "",     "r4",    "r4",   "",   "",   ""},
    {"4",        "s5",     "",      "",      "s4",   "",      "",     "8",  "2",   "3"},
    {"5",        "",       "r6",    "r6",    "",     "r6",    "r6",   "",   "",   ""},
    {"6",        "s5",     "",      "",      "s4",   "",      "",     "",   "9",  "3"},
    {"7",        "s5",     "",      "",      "s4",   "",      "",     "",   "",   "10"},
    {"8",        "",       "s6",    "",      "",     "s11",   "",     "",   "",   ""},
    {"9",        "",       "r1",    "s7",    "",     "r1",    "r1",   "",   "",   ""},
    {"10",       "",       "r3",    "r3",    "",     "r3",    "r3",   "",   "",   ""},
    {"11",       "",       "r5",    "r5",    "",     "r5",    "r5",   "",   "",   ""}};


struct prodn{
    char prdlhs;
    char prdrhs[10];
}productions[6];



void ParsingTable_View();
void initialize();
void parse(char []);
//char * strrev(char []);

//For Stack operations
void push(char []);
char TOS();
void pop();

// To display the contents of Stack and input buffer
void display();
void display1(char [], int);


char a[10], rev[30];
int top=-1;

int main(int argc, char *argv[])
{
    int i,j;
    char ip[100];
    
    ParsingTable_View();
    initialize();
    
    printf("Enter The String::=====>");
    scanf("%s",ip);
    
/*
     yyin = fopen(argv[1], “r”);
     i= 0;
     while(!feof(yyin))
     {
     token = yylex();
     if ( token >= id_min  && token <= id_max )
     ip[i] =  ‘i’;
     else
     ip[i] = token;
     i++;
     }
     ip[i] = ‘$’;
*/

    
    printf("Start Parseing ........ ......> %s    >  \n");
    parse(ip);
    
    //        yylex();
    return(0);
    
}

void initialize()  /// Set of Production Rules
{
    productions[0].prdlhs = 'E';
    strcpy(productions[0].prdrhs, "E+T");
    productions[1].prdlhs = 'E';
    strcpy(productions[1].prdrhs, "T");
    productions[2].prdlhs = 'E';
    strcpy(productions[2].prdrhs, "T*F");
    productions[3].prdlhs = 'T';
    strcpy(productions[3].prdrhs, "F");
    productions[4].prdlhs = 'F';
    strcpy(productions[4].prdrhs, "(E)");
    productions[5].prdlhs = 'F';
    strcpy(productions[5].prdrhs, "i");
    
}


void parse(char ip[])
{
    int j = 0, ir, ic, prod_id, state_id = 0;
    char an,st,r[20];
    
    //set Initial Stack symbol
    push("0");
    display();
    printf("   *********");
    display1(ip,j);
    printf("\n");
    
    
    for (j = 0; ip[j]!='\0';)
    {
        an = ip[j];
        st = TOS();
       
        //To consult with parse table, find the row number (ir)
        if (strcmp(st,"0")== 0) ir = 1;
        else if (strcmp(state_id,"1")== 0) ir = 2;
            .
            .
            .
            .
        //To consult with action-part of parse table, find the column number (ic)
        if (an == 'i') ic = 1;
        else if (an == '+') ic = 2;
        else if (an == '*') ic = 3;
               .
               .
               .
               .
        
        //Shift
        if (Table[ir][ic][0]== 's' ) {
            printf("Do Shifting .... \n");
            push(an);
            push(Table[ir][ic]+1);
            j++;
            display();
            display1(ip, j);
        }
        
        //Reduce by a Production
        else if (Table[ir][ic][0] == 'r') {
            printf("Reduce By a Production...... \n ");
            prod_id=atoi(Table[ir][ic]+1);
            length = strlen(productions[prod_id].prdrhs);
            
            //pop two times of length of rhs of a prodn
            for (i=0; i< 2*length; i++)
                pop();
            
            stpx = TOS();
            push(productions[prod_id].prd_lhs);
            
            //To consult with goto-part of the parse table, find the column number (ic)
            if (productions[prod_id].prd_lhs == 'E')  ic = 7;
            else if (productions[prod_id].prd_lhs == 'T')  ic = 8;
                   .
                   .
                   .
            
            push(Table[ir][ic]);
            
            display();
            display1(ip,j);
            
            
            
        }
        
        
        //Accept
        else if (strcmp(Table[ir][ic],"Acc") == 0) {
            display();
            display1();
            printf("Accept  \n");
            break;
        }
        
        //Error
        else
        {
            printf ("Syntax Error. ");
        }
        
    }
    
}

%------------------------
void ParsingTable_View()
{
    int i,j, ir, ic;
    char st, an;
    //        push("$E");
    for(i=0;i<=12;i++)
    {
        for(j=0;j<10;j++)
        {
            printf("%10s",PrsTable[i][j]);
        }
        printf("\n");
    }
}

