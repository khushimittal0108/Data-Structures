#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define MAX 50

float stack[MAX];
int top=-1;
void push(float stack[],float val);
float pop(float stack[]);
float evaluatepostfix(char arr[]);

int main()
{
	char arr[50];
	float val;
	printf("enter a postfix expression:\n");
	gets(arr);
	val=evaluatepostfix(arr);
	printf("The expression evaluates to %.2f",val);
	getch();
	return 0;	
}

float evaluatepostfix(char arr[])
{
	int i=0;
	float op1,op2,value;
	while(arr[i]!='\0')
	{
		if(isdigit(arr[i]))
		{
			push(stack,(float)(arr[i]-'0'));
		}
		else
		{
			op2=pop(stack);
			op1=pop(stack);
			switch(arr[i])
			{
				case '+':
					value=op1+op2;
					break;
				case '-':
					value=op1-op2;
					break;
				case '/':
					value=op1/op2;
					break;
				case '*':
					value=op1*op2;
					break;
				case '%':
					value=(int)op1%(int)op2;
					break;	
			}
			push(stack,value);
		}
		i++;
	}
	return (pop(stack));
}

void push(float stack[],float val)
{
	if(top==MAX-1)
	{
		printf("Stack overflow\n");
	}
	else
	{
		top++;
		stack[top]=val;
	}
}

float pop(float stack[])
{
	float val=-1;
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

