/*recognize valid operator and identifier*/
%{
#include <stdio.h>
#include "y.tab.h"    
extern yylval;
%}
%%
#include[ a-z|<|>|"|\.]* ;

("/*"[^*/]*"*/")|"//"(.)*\n ;

(["| a-z|A-Z|0-9]*])  ;

[+|-|*|//|<|>|=]  {printf("operator is %s\n", yytext); return OP;}

int|float|char|bool|void|for|do|while|if|else|return|printf|scanf|main|unsigned {printf("keyword is %s\n",yytext); return KEY;}

[a-z|A-Z][a-z|A-Z|0-9|_]* {printf("Idetifier is %s\n",yytext); return ID;}
. ;
%%

