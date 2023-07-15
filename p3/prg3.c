/*Design develop and implement yacc/c program to construct predictive/ll(1) parse table for the grammer
A->aBa
B->bB
B->@
use this table to parse the string :abba$*/

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
char prod[3][10]={"A->aBa","B->bB","B->@"}, input[10],stack[25];
int top=-1; int j=0,k,l;

void push(char item){	stack[++top]=item; }

void pop(){	top=top-1;	}

void display()
{
	int j;
	for(j=top;j>=0;j--)
		printf("%c",stack[j]);
}

void stackpush(char p)
{
	if(p=='A')
	{
		pop();
		for(j=strlen(prod[0])-1;j>=3;j--)
			push(prod[0][j]);
	}
	else
	{
		pop();
		for(j=strlen(prod[1])-1;j>=3;j--)
			push(prod[1][j]);
	}
}

void main()
{
	char c; int i;
	printf("FIRST[A] = {a}\tFOLLOW[A]={$}\n");
	printf("FIRST[B]={b,@}\tFOLLOW[B]={a}\n");
	printf("\n\n--------Parse Table--------");
	printf("\n\t a \t b \t $ \n");
	printf("A\t%s\tE\tE\n",prod[0]);
	printf("B\t%s\t%s\tE\n",prod[2],prod[1]);
	printf("\nenter the input string terminated with $ to parse:-");
	scanf("%s",input);
	for(i=0;input[i]!='\0';i++)
	{
		if((input[i]!='a')&&(input[i]!='b')&&(input[i]!='$'))
		{
			printf("invalid string\n");
			exit(0);
		}
	}
	if(input[i-1]!='$')
		input[i]='$';
	push('$');
	push('A');
	i=0;
	printf("\n\n");
	printf("stack\tInput\taction");
	printf("\n---------------------------");
	while(i!=strlen(input)&&stack[top]!='$')
	{
		printf("\n");
		display();
		printf("\t");
		for(l=i;l<strlen(input);l++)
			printf("%c",input[l]);
		printf("\t");
		if(stack[top]=='A')
		{
			printf("A->aBa");
			stackpush('A');
		}
		else if(stack[top]=='B')
		{
			if(input[i]!='b')
			{
				printf("B->@"); 
				printf("\t matched @");
				pop();
			}
			else
			{
				printf("B->bB");
				stackpush('B');
			}
		}
		else
		{
			if(stack[top]==input[i])
			{
				printf("pop %c",input[i]);
				printf("\tmatched %c",input[i]);
				pop();
				i++;
			}
			else  //2condition where rejection i)stack[top]=terminal, ii)m[x,a]=err
				break;
		}
	}
	if(stack[top]=='$' && input[i]=='$')
	{
		printf("\n$\t$");
		printf("\nValid string Accepted\n");
	}
	else
		printf("\nInvalid string rejected\n"); 
}

