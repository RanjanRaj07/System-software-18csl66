#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class grm{
    public:
        char V[10][5]={"A\0","B\0"};
        char T[10][5]={"a\0","b\0"};
        char P[3][15]={"A->aBa\0","B->bB\0","B->@\0"};
        char S[5]={"A\0"};
};

int num(char c)
{
  switch(c)
  {
    case 'A':return 0;
    case 'B':return 1;
    case 'a':return 0;
    case 'b':return 1;
    case '@':return 2;
    default : return -1;
  }
}

int main(){
    grm G;
    char first[3][20][3]={{"a\0"},{"b\0","@\0"}};
    char follow[3][20][3]={{"$\0"},{"a\0"}};
    char m[2][3][10]={{"E\0","E\0","E\0"},{"E\0","E\0","E\0"}};
    char LHS[3][3] = {"A\0","B\0","B\0"};
    char RHS[3][5] = {"aBa\0","bB\0","@\0"};

    for(int i=0;i<3;i++)
    {
    	if(first[i][0][0]!='@')
    	    strcpy(m[num(LHS[i][0])][num(first[i][0][0])],RHS[i]);
   	else 
            strcpy(m[num(LHS[i][0])][num(follow[i][0][0])],RHS[i]);   		
    }
        printf("Parsing Table\n");
    for(int p=0;p<2;p++)
    {
	for(int q=0;q<3;q++)
		printf("%s\t",m[p][q]);
	printf("\n");
    }
    return 0;
}


