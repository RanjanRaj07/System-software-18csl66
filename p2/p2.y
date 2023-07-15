%{
#include<stdio.h>
#include<stdlib.h>
%}
%token A B
%%
input :  s'\n' {printf("Successful Grammar\n");exit(0);}
                s : A s1 B | B
                s1 : ; | A s1
%%

int yyerror() {
    printf(" error!! \n");
    exit(0);
}
int main(){
    printf("\n enter A String \n");
    yyparse();
    return 0;
}



