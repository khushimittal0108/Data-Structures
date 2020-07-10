#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 10

char stack[MAX];
int top=-1;
void push(char);
char pop();

int main()
{
	char arr[10],temp;
	int i,flag=1;
	printf("enter the arithmetic expression:");
	gets(arr);
	for(i=0;i<strlen(arr);i++)
	{
		if(arr[i]=='('||arr[i]=='{'||arr[i]=='[')
		{
			push(arr[i]);
		}
		if(arr[i]==')'||arr[i]=='}'||arr[i]==']')
		{
			if(top==-1)
			flag=0;
			else
			{
				temp=pop();
				if(arr[i]==')'&&(temp=='{'||temp=='['))
					flag=0;
				if(arr[i]==']'&&(temp=='{'||temp=='('))
					flag=0;
				if(arr[i]=='}'&&(temp=='('||temp=='['))
					flag=0;
			}
		}
	}
	if(top>=0)
		flag=0;
	if(flag==0)
	{
		printf("INVALID EXPRESSION\n");
	}
	else
	{
		printf("VALID EXPRESSION\n");
	}
	return 0;
}

void push(char t)
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

char pop()
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
