/*eliminate comment lines in a C program into seperate file*/

%{
#include <stdio.h>
int cl = 0;    
%}
%%
("/*"[^*/]*"*/")|"//"(.)*\n {++cl; fprintf(yyout,"");} 
%%
void main (int argc, char* argv[]){
    yyin = fopen(argv[1],"r");
    yyout = fopen(argv[2],"w");
    yylex();

    printf("The number of comment lines are %d: \n", cl);
    fclose(yyin);
    fclose(yyout);
}
int yywrap() {
    return 1;
}