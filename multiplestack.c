#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#define MAX 20

int stack[MAX],topa=-1,topb=MAX;

void pusha(int val);
int popa();
void displaya();
void pushb(int val);
int popb();
void displayb();

int main()
{
	int option,val;
	do
	{
		printf("\n---OPERATIONS---\n");
		printf("1.PUSH in stack A\n");
		printf("2.PUSH in stack B\n");
		printf("3.POP from stack A\n");
		printf("4.POP from stack B\n");
		printf("5.Display stack A\n");
		printf("6.Display stack B\n");
		printf("7.Exit\n");
		printf("enter your choice:");
		scanf("%d",&option);
		
		
		switch(option)
		{
			case 1:
				printf("enter a value to be pushed on stack A");
				scanf("%d",&val);
				pusha(val);
				break;
			case 2:
				printf("enter a value to be pushed on stack B");
				scanf("%d",&val);
				pushb(val);
				break;
			case 3:
				val=popa();
				if(val!=-1)
					printf("value popped from stack A is %d",val);
				break;
			case 4:
				val=popb();
				if(val!=-1)
					printf("value popped from stack B is %d",val);
				break;
			case 5:
				displaya();
				break;
			case 6:
				displayb();
				break;
					
		}
	}while(option!=7);
	getch();
	return 0;
}

void pusha(int val)
{
	if(topa==topb-1)
	{
		printf("OVERFLOW\n");
	}
	else
	{
		topa++;
		stack[topa]=val;
	}
}

int popa()
{
	int val;
	if(topa==-1)
	{
		printf("UNDERFLOW\n");
		return -1;
	}
	else
	{
		val=stack[topa];
		topa--;
		
	}
	return val;
}

void displaya()
{
	int i;
	if(topa==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		for(i=topa;i>=0;i--)
		{
			printf("%d\t",stack[i]);
		}	
	}
}

void pushb(int val)
{
	if(topb-1==topa)
	{
		printf("OVERFLOW\n");
	}
	else
	{
		topb--;
		stack[topb]=val;
	}
}

int popb()
{
	int val;
	if(topb==MAX)
	{
		printf("UNDERFLOW\n");
		return -1;
	}
	else
	{
		val=stack[topb];
		topb++;
	}
	return val;
}

void displayb()
{
	int i;
	if(topb==MAX)
	{
		printf("Stack is empty\n");
	}
	else
	{
		for(i=topb;i<MAX;i++)
		{
			printf("%d\t",stack[i]);
		}
	}
}
