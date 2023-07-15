/* recognize valid arithmatic expression ,Identifiers in the expression could be +and* */ 
/* count the Identifiers and Operartors in the expression print them seperately*/

%{
#include<stdio.h>
int v=0,op=0,id=0,flag=0;
%}

%%
[0-9].[0-9]*  {id++;printf("\n\n Identifier: \t"); ECHO;}
[\+\*]{1}     {op++;printf("\n\n Operartor: \t");ECHO;}
"("  {v++;} 
")"  {v--;}
"[^[0-9] \+ \* ( )]"  {flag = 1;}
\n  {return 0;}
%%

int yywrap() {return 1;}

int main()
{
printf("Enter the expression "); 
yylex();
if((op+1)==id && v==0 && flag==0) {
    printf("\n\n Expression is Valid \n"); 
    printf("\tIdentifier count=%d,\n\tOperartor count=%d\n",id,op); 
}
else printf("\n Expression is Invalid \n"); 

return 0;
}