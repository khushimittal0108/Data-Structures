#include<stdio.h>
#include<conio.h>
#define MAX 50

int rear=-1,front=-1;
int queue[MAX];
void enqueue();
int dequeue();
int peek();
void display();

int main()
{
	int option,value;
	do
	{
		printf("\n---OPERATIONS---\n");
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Peek\n");
		printf("4.Display\n");
		printf("5.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1:
				enqueue();
				break;
			case 2:
				value=dequeue();
				if(value!=-1)
				printf("The element deleted is %d",value);
				break;
			case 3:
				value=peek();
				if(value!=-1)
				printf("The element peeked is %d",value);
				break;
			case 4:
				display();
				break;
		}
	}while(option!=5);
	getch();
	return 0;
}

void enqueue()
{
	int num;
	printf("Enter the value to be inserted:");
	scanf("%d",&num);
	if(rear==MAX-1)
	{
		printf("Overflow\n");
	}
	else if(rear==-1&&front==-1)
	{
		rear=0;
		front=0;
	}
	else
	{
		rear++;
	}
	queue[rear]=num;
}

int dequeue()
{
	int val;
	if(front==-1 ||front>rear)
	{
		printf("Underflow\n");
		return -1;
	}
	else
	{
		val=queue[front];
		front++;
		return val;
	}
}

int peek()
{
	if(front==-1||front>rear)
	{
		printf("Queue is empty\n");
		return -1;
	}
	else
	{
		return queue[front];
	}
}

void display()
{
	int i;
	if(front==-1||front>rear)
	{
		printf("queue is empty\n");
	}
	else
	{
		i=front;
		while(i<=rear)
		{
			printf("->%d",queue[i]);
			i++;
		}	
	}
}
