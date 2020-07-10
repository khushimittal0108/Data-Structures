#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#define MAX 20

int stack[MAX],top=-1;
void push(int stack[],int val);
int pop(int stack[]);
int peek(int stack[]);
void display(int stack[]);

int main()
{
	int val,option;
	do
	{
		printf("\n---OPERATIONS---\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Peek\n");
		printf("4.Display\n");
		printf("5.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1:
				printf("enter the value to be pushed in stack\n");
				scanf("%d",&val);
				push(stack,val);
				break;
			case 2:
				val=pop(stack);
				if(val!=-1)
				printf("the value popped from stack is %d",val);
				break;
			case 3:
				val=peek(stack);
				if(val!=-1)
				printf("the topmost element of the stack is %d",val);
				break;
			case 4:
				printf("The stack is:\n");
				display(stack);
				break;
		}
	}while(option!=5);
	getch();
	return 0;
}

void push(int stack[],int val)
{
	if(top==MAX-1)
	{
		printf("stack overflow\n");
	}
	else
	{
		top++;
		stack[top]=val;
	}
}

int pop( int stack[])
{
	 int val;
	 if(top==-1)
	{
		printf("stack underflow\n");
		return -1;
	}
	else
	{
		val=stack[top];
		top--;
		return val;
	}
}

int peek( int stack[])
{
	if(top==-1)
	{
		printf("stack is empty\n");
		return -1;
	}
	else
	{
		return stack[top];
	}
}

void display(int stack[])
{
	int i;
	if(top==-1)
	{
		printf("stack is empty\n");
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("%d\t",stack[i]);
		}
	}
}


