#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};

struct queue
{
	struct node *front;
	struct node *rear;
};

struct queue *q;
void create(struct queue *);
struct queue *enqueue(struct queue *);
struct queue *dequeue(struct queue *);
struct queue *display(struct queue *);
int peek(struct queue *);

int main()
{
	int option,val;
	create(q);
	do
	{
		printf("\n----OPERATIONS----\n");
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Peek\n");
		printf("4.Display\n");
		printf("5.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1:
				q=enqueue(q);
				break;
			case 2:
				q=dequeue(q);
				break;
			case 3:
				val=peek(q);
				if(val!=-1)
				{
					printf("the peeked value is %d",val);
				}
				break;
			case 4:
				q=display(q);
				break;
		}
	}while(option!=5);
	getch();
	return 0;
}

void create(struct queue *q)
{
	q->front=NULL;
	q->rear=NULL;
}

struct queue *enqueue(struct queue *q)
{
	int val;
	struct node *ptr;
	printf("enter data:");
	scanf("%d",&val);
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=val;
	if(q->front==NULL)
	{
		q->front=ptr;
		q->rear=ptr;
		q->front->next=NULL;
		q->rear->next=NULL;
	}
	else
	{
		q->rear->next=ptr;
		q->rear=ptr;
		q->rear->next=NULL;
	}
	return q;
}

struct queue *dequeue(struct queue *q)
{
	struct node *ptr;
	ptr=q->front;
	if(q->front==NULL)
	{
		printf("Underflow\n");
	}
	else
	{
		q->front=q->front->next;
		printf("the value being deleted is %d",ptr->data);
		free(ptr);
	}
	return q;
}

struct queue *display(struct queue *q)
{
	struct node *ptr;
	ptr=q->front;
	if(ptr==NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		while(ptr!=q->rear)
		{
			printf("->%d",ptr->data);
			ptr=ptr->next;
		}
		printf("->%d",ptr->data);
	}
	return q;
}

int peek(struct queue *q)
{
	if(q->front==NULL)
	{
		printf("Queue is empty\n");
		return -1;
	}
	else
	{
		return q->front->data;
	}
}
