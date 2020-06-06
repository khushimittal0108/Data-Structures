#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct node 
{
	int data;
	struct node *next;
};

struct node *start=NULL;
struct node *create(struct node *);
struct node *display(struct node *);

int main()
{
	int option;
	do
	{
		printf("\n----OPERATIONS----\n");
		printf("1.create a list\n");
		printf("2.display a list\n");
		printf("3.exit\n");
		printf("enter your choice:");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1: start=create(start);
					break;
			case 2: start=display(start);
					break;
		}
	}while(option!=3);
	getch();
	return 0;
}

struct node *create(struct node *start)
{
	struct node *newnode,*ptr;
	int num;
	printf("enter -1 to end\n");
	printf("enter data:");
	scanf("%d",&num);
	while(num!=-1)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=num;
		newnode->next=NULL;
		if(start==NULL)
		{
			start=(struct node *)malloc(sizeof(struct node));
			start->next=newnode;
		}
		else
		{
			ptr=start->next;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=newnode;
		}
		printf("enter data:");
		scanf("%d",&num);
	}
	return start;
}

struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start->next;
	while(ptr!=NULL)
	{
		printf("->%d",ptr->data);
		ptr=ptr->next;
	}
	return start;
}

