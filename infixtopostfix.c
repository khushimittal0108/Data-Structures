#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

char stack[MAX];
int top=-1;
void push(char stack[],char);
char pop(char stack[]);
void infixtopostfix(char source[],char target[]);
int priority(char);

int main()
{
	char infix[50],postfix[50];
	printf("Enter the infix expression:\n");
	gets(infix);
	strcpy(postfix,"");
	infixtopostfix(infix,postfix);
	printf("The equivalent postfix expression is:\n");
	puts(postfix);
	getch();
	return 0;
}

void infixtopostfix(char source[],char target[])
{
	int i=0,j=0;
	char temp;
	strcpy(target,"");
	while(source[i]!='\0')
	{
		if(source[i]=='(')
		{
			push(stack,source[i]);
			i++;
		}
		else if(source[i]==')')
		{
			while((top!=-1) && (stack[top]!='('))
			{
				target[j]=pop(stack);
				j++;
			}
			if(top==-1)
			{
				printf("Invalid expression\n");
				exit(1);
			}
			temp=pop(stack);				//remove left parentheses
			i++;
		}
		else if(isdigit(source[i])||isalpha(source[i]))
		{
			target[j]=source[i];
			i++;
			j++;
		}
		else if(source[i]=='%'||source[i]=='*'||source[i]=='+'||source[i]=='-'||source[i]=='/')
		{
			while((top!=-1 )&& (stack[top]!='(')&& (priority(stack[top])>=priority(source[i])))
			{
				target[j]=pop(stack);
				j++;
			}
			push(stack,source[i]);
			i++;
		}
		else
		{
			printf("incorrect element in expression\n");
			exit(1);
		}
	
	}
	while((top!=-1)&& (stack[top]!='('))
	{
	target[j] = pop(stack);
	j++;
	}
	target[j]='\0';
}

void push(char stack[],char t)
{
	if(top==MAX-1)
	{
		printf("Stack overflow\n");
	}
	else
	{
		top++;
		stack[top]=t;
	}
}

char pop(char stack[])
{
	char val;
	if(top==-1)
	{
		printf("Stack underflow\n");
	}
	else
	{
		val=stack[top];
		top--;
	}
	return val;
}

int priority(char t)
{
	if(t=='*'||t=='%'||t=='/')
		return 1;
	if(t=='+'||t=='-')
		return 0;
}


