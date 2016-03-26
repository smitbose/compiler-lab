%{
#include <stdio.h>
#include "y.tab.h"
%}
%%
\+ return PLUSTOK;
\- return SUBTOK;
\/ return DIVTOK;
\* return MULTTOK;
[0-9]+ return INTCONST;
%%
int yywrap()
{
	return 1;
}