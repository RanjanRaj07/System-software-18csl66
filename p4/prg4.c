/*Design develop an implemet yacc/c program to demonstrate shift reduce parsing technique for the grammer 
E->E+T/T
T->T*F/F
F->(E)/id
and parse the sentence : id+id*id */
#include <stdio.h>
#include <string.h>

int k=0,z=0,i=0,j=0,c=0;
char a[16],ac[20],stk[15],act[10];

void check();

void main(){
    printf("Grammer :\n\tE->E+T|T\n\tT->T*F|F\n\tF->(E)|id\n\n");
    printf("enter the string to shift down parse\n");
    scanf("%s",a);
    c=strlen(a);
    a[c]='$';
    stk[i++]='$';
    strcpy(act,"SHIFT-> ");
    printf("\n\nStack \t\t Input \t\t\t Acion \t");

    printf("\n%s\t\t%s",stk,a);
    // printf("\n%s\t\t%s\t\t%s %c%c",stk,a,act,a[j],a[j+1]);
    for(k=0;j<c;j++,i++){
        if(a[j]=='i'&&a[j+1]=='d'){
            stk[i]=a[j];
            stk[i+1]=a[j+1];
            stk[i+2]='\0';
            printf("\n%s\t\t%s\t\t%s %c%c",stk,a,act,a[j],a[j+1]);
            a[j]=' ';
            a[j+1]=' ';
            check();
        }
        else {
            stk[i]=a[j];
            stk[i+1]='\0';
            printf("\n%s\t\t%s\t\t%s %c",stk,a,act,a[j]);
            a[j]=' ';
            check();
        }
    }printf("\n");
}

void check(){
    strcpy(ac,"REDUCE");
    for(z=0;z<c;z++){
        if(stk[z]=='('&&stk[z+1]=='E'&&stk[z+2]==')'){
            stk[z]='F';
            stk[z+1]=stk[z+2]='\0';
            printf("\n%s\t\t%s\t\t%s F->(E)",stk,a,ac);
            i=i-2;
        }
        else if(stk[z]=='i'&&stk[z+1]=='d'){
            stk[z]='F';
            stk[z+1]='\0';
            printf("\n%s\t\t%s\t\t%s F->id",stk,a,ac);
            j++; //i--;
        }
    }
    for(z=0;z<c;z++){
        if(stk[z]=='T'&&stk[z+1]=='*'&&stk[z+2]=='F'){
            stk[z]='T';
            stk[z+1]=stk[z+2]='\0';
            printf("\n%s\t\t%s\t\t%s T->T*F",stk,a,ac);
            i-=2;
        }
        else if(stk[z]=='F'){
            stk[z]='T';
            printf("\n%s\t\t%s\t\t%s T->F",stk,a,ac);
        }
    }
    for(z=0;z<c;z++){
        if(stk[z]=='E'&&stk[z+1]=='+'&&stk[z+2]=='T'&&stk[z+3]=='*')  break;
        if(stk[z]=='E'&&stk[z+1]=='+'&&stk[z+2]=='T'){
            if(a[j+1]=='*')  break;
            else {
                stk[z]='E';
                stk[z+1]='\0';
                stk[z+2]='\0';
                printf("\n%s\t\t%s\t\t%s E->E+T",stk,a,ac);
                i-=2;
            }
        }
        else if(stk[z]=='T'){
            if(stk[z+1]=='*'||a[j+1]=='*') break;
            stk[z]='E';
            printf("\n%s\t\t%s\t\t%s E->T",stk,a,ac);
        }
    }
}