%{
#include <stdio.h>
#include <stdlib.h>
int id=0,key=0,op=0;
%}

%token ID KEY OP 
%%
input : ID input {id++;}
    | KEY input {key++;}
    | OP input {op++;}
    | ID {id++;}
    | KEY {key++;}
    | OP {op++;}
    ;
%%

extern FILE*yyin;

main(){
    FILE *myfile = fopen("in.txt","r");
    yyin = myfile;

    yyparse();
    printf("Keywords = %d\nIdentifiers = %d\nOperators = %d\n",key,id,op);
}

int  yyerror(){
    printf("parse Error! messege");
    exit(-1);
}

int yywrap() {
    return 1;
}