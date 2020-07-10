#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node 
{
	int data;
	struct node *next;
};

struct node *top=NULL;
struct node *push(struct node *,int);
struct node *pop(struct node *);
int peek(struct node *);
struct node *display(struct node *);

int main()
{
	int option,val;
	do
	{
		printf("\n---OPERATIONS---\n");
		printf("1.PUSH\n");
		printf("2.POP\n");
		printf("3.PEEK\n");
		printf("4.DISPLAY\n");
		printf("5.EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1:
				printf("enter the value to be pushed to stack:");
				scanf("%d",&val);
				top=push(top,val);
				break;
			case 2:
				top=pop(top);
				break;
			case 3:
				val=peek(top);
				if(val==-1)
					printf("stack is empty\n");
				else
					printf("the topmost element of the stack is %d",val);
				break;
			case 4:
				top=display(top);
				break;
		}
	}while(option!=5);
	getch();
	return 0;
}

struct node *push(struct node *top,int val)
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=val;
	if(top==NULL)
	{
		ptr->next=NULL;
		top=ptr;
	}
	else
	{
		ptr->next=top;
		top=ptr;
	}
	return top;
}

struct node *pop(struct node *top)
{
	struct node *ptr;
	if(top==NULL)
	{
		printf("Stack underflow\n");
	}
	else
	{
		ptr=top;
		top=top->next;
		printf("Element deleted from stack is %d",ptr->data);
		free(ptr);
	}
	return top;
}

int peek(struct node *top)
{
	if(top==NULL)
	{
		return -1;
	}
	else
	{
		return top->data;
	}
}

struct node *display(struct node *top)
{
	struct node *ptr;
	if(top==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
		ptr=top;
		while(ptr!=NULL)
		{
			printf("->%d",ptr->data);
			ptr=ptr->next;
		}
	}
	return top;
}
