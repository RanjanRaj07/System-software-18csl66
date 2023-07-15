/*Design develop and implement a C/java program to generate the machine code using Triples for a statement 
A=-B*(c+D) whose intermediate code in three-adress form :
T1 -B = ?
T2 C + D
T3 T1 + T2
A  T3 = ?*/
#include <stdio.h>
#include <string.h>


char op[2],arg1[5],arg2[5],result[5];
int count = 0;

void main(){
    FILE *f1,*f2;
    f1 = fopen("input.txt","r");
    f2 = fopen("output.txt","w");
    while(!feof(f1)&&count<4){
        fscanf(f1,"%s %s %s %s",result,arg1,op,arg2);


        if(strcmp(op,"+")==0){
            fprintf(f2,"\nLD   R0  %s",arg1);
            fprintf(f2,"\nADD  R0  %s",arg2);
            fprintf(f2,"\nST   %s  R0",result);
        }
                if(strcmp(op,"*")==0){
            fprintf(f2,"\nLD   R0  %s",arg1);
            fprintf(f2,"\nMUL  R0  %s",arg2);
            fprintf(f2,"\nST   %s  R0",result);
        }
                if(strcmp(op,"-")==0){
            fprintf(f2,"\nLD   R0  %s",arg1);
            fprintf(f2,"\nSUB  R0  %s",arg2);
            fprintf(f2,"\nST   %s  R0",result);
        }
                if(strcmp(op,"/")==0){
            fprintf(f2,"\nLD   R0  %s",arg1);
            fprintf(f2,"\nDIV  R0  %s",arg2);
            fprintf(f2,"\nST   %s  R0",result);
        }
                if(strcmp(op,"=")==0){
            fprintf(f2,"\nLD   R0  %s",arg1);
            fprintf(f2,"\nST   %s  R0",result);
        }
    }
    fclose(f1); 
    fclose(f2);
}