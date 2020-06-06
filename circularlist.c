#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};

struct node *start=NULL;
struct node *create(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);

int main()
{
	int option;
	do
	{
		printf("\n-----DOUBLY LINKLIST OPERATIONS-----\n");
		printf("1.Create a list\n");
		printf("2.Display the list\n");
		printf("3.Insert a node at the beginning\n");
		printf("4.Insert a node at the end\n");
		printf("5.Delete a node from the beginning\n");
		printf("6.Delete a node from the end\n");
		printf("7.Delete a node after a given node\n");
		printf("8.Delete the entire list\n");
		printf("9.Exit\n");
		printf("Enter your option:");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1: start=create(start);
					break;
			case 2: start=display(start);
					break;
			case 3: start=insert_beg(start);
			        break;
			case 4: start=insert_end(start);
					break;
			case 5: start=delete_beg(start);
					break;
			case 6: start=delete_end(start);
					break;
			case 7: start=delete_after(start);
					break;
			case 8: start=delete_list(start);
					break;				
		}
		
	}while(option!=9);
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
		if(start==NULL)
		{
			newnode->next=newnode;
			start=newnode;
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
			{
				ptr=ptr->next;
			}
			ptr->next=newnode;
			newnode->next=start;
		}
		printf("enter data");
		scanf("%d",&num);
	}
	return start;
}

struct node *display(struct node *start)
{
	struct node *temp;
	temp=start;
	if(start==NULL)
	{
		printf("list is empty");
		return start;
	}
	else
	{
		while(temp->next!=start)
		{
			printf("->%d",temp->data);
			temp=temp->next;
		}
		printf("->%d",temp->data);
	}
	return start;
}

struct node *insert_beg(struct node *start)
{
	struct node *newnode,*ptr;
	int num;
	printf("enter data:");
	scanf("%d",&num);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
	newnode->next=start;
	start=newnode;
	return start;
}

struct node *insert_end(struct node *start)
{
	struct node *newnode,*ptr;
	int num;
	printf("enter data:");
	scanf("%d",&num);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
	newnode->next=start;
	return start;	
}

struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=start->next;
	free(start);
	start=ptr->next;
	return start;
}

struct node *delete_end(struct node *start)
{
	struct node *ptr,*preptr;
	ptr=start;
	while(ptr->next!=start)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=start;
	free(ptr);
	return start;
}

struct node *delete_after(struct node *start)
{
	struct node *ptr,*preptr;
	int val;
	printf("enter the number after which node is to be deleted");
	scanf("%d",&val);
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	if(ptr==start)
	{
		start=preptr->next;
	}
	free(ptr);
	return start;
}

struct node *delete_list(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	{
		start=delete_end(start);
	    ptr=start;
	}
	start=NULL;
	free(start);
	printf("Entire list is deleted");
	return start;
}
