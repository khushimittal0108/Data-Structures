#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

struct node *start=NULL;
struct node *create(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_before(struct node *);
struct node *delete_after(struct node *);
struct node *delete_node(struct node *);
struct node *delete_list(struct node *);

int main()
{
	int option;
	do
	{
		printf("\n----DOUBLY LINK LIST OPERATIONS----\n");
		printf("1.Create a list\n");
		printf("2.Display the list\n");
		printf("3.Add a node at the beginning\n");
		printf("4.Add a node at the end\n");
		printf("5.Add a node before a given node\n");
		printf("6.Add a node after a given node\n");
		printf("7.Delete a node from beginning\n");
		printf("8.Delete a node from the end\n");
		printf("9.Delete a node before a given node\n");
		printf("10.Delete a node after a given node\n");
		printf("11.Delete a given node\n");
		printf("12.Delete the entire list\n");
		printf("13.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1:	start=create(start);
					break;
			case 2:	start=display(start);
					break;
			case 3: start=insert_beg(start);
					break;	
			case 4:	start=insert_end(start);
					break;
			case 5:	start=insert_before(start);
			    	break;
			case 6:	start=insert_after(start);
					break;	
			case 7: start=delete_beg(start);
					break;
			case 8: start=delete_end(start);
					break;
			case 9: start=delete_before(start);
			  		break;
			case 10: start=delete_after(start);
					 break;
			case 11: start=delete_node(start);
			         break;
			case 12: start=delete_list(start);		  		
					 break;
		}
	}while(option!=13);
	getch();
	return 0;
}

struct node *create(struct node *start)
{
	struct node *newnode,*ptr;
	int item;
	printf("enter -1 to end\n");
	printf("enter data:");
	scanf("%d",&item);
	while(item!=-1)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=item;
		if(start==NULL)
		{
		    newnode->prev=start;
			newnode->next=start;
			start=newnode;
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
			{
				ptr=ptr->next;
			}
			newnode->prev=ptr;
			ptr->next=newnode;
		    newnode->next=start;
			start->prev=newnode;
		}
		printf("enter data:");
		scanf("%d",&item);
	}
	return start;
}

struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	if(start==NULL)
	{
		printf("list is empty");
		return start;
	} 
	else
	{
		while(ptr->next!=start)
		{
			printf("->%d",ptr->data);
			ptr=ptr->next;
		}
		printf("->%d",ptr->data);
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
	newnode->next=start;
	start->prev=newnode;
	newnode->prev=ptr;
	ptr->next=newnode;
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
	newnode->prev=ptr;
	start->prev=newnode;
	return start;
}

struct node *insert_before(struct node *start)
{
	struct node *newnode,*ptr;
	int num,val;
	printf("enter data:");
	scanf("%d",&num);
	printf("enter the value before which new node is to be inserted");
    scanf("%d",&val);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	while(ptr->data!=val)
	{
		ptr=ptr->next;
	}
	newnode->next=ptr;
	newnode->prev=ptr->prev;
	ptr->prev->next=newnode;
    ptr->prev=newnode;
    return start;
}

struct node *insert_after(struct node *start)
{
	struct node *newnode,*ptr;
	int num,val;
	printf("enter data:");
	scanf("%d",&num);
	printf("enter the value after which new node is to be inserted");
    scanf("%d",&val);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	while(ptr->data!=val)
	{
		ptr=ptr->next;	
	}	
	newnode->prev=ptr;
	newnode->next=ptr->next;
	ptr->next->prev=newnode;
	ptr->next=newnode;
	return start;
}

struct node *delete_beg(struct node *start)
{
	struct node *ptr,*temp;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=start->next;
	temp=start;
	start=start->next;
	start->prev=ptr;
	free(temp);
	return start;
}

struct node *delete_end(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->prev->next=start;
	start->prev=ptr->prev;
	free(ptr);
	return start;
}


struct node *delete_before(struct node *start)
{
	struct node *ptr,*temp;
	int val;
	printf("enter the value before which node is to be deleted");
	scanf("%d",&val);
	ptr=start;
	while(ptr->data!=val)
	{
		ptr=ptr->next;
	}
	temp=ptr->prev;
	if(temp==start)
	{
		start=delete_beg(start);
	}
	else
	{
		ptr->prev=temp->prev;
		temp->prev->next=ptr;
	}
	free(temp);
	return start;
}

struct node *delete_after(struct node *start)
{
	struct node *ptr,*temp;
	int val;
	printf("enter the value after which node is to be deleted");
	scanf("%d",&val);
	ptr=start;
	while(ptr->data!=val)
	{
		ptr=ptr->next;
	}
	temp=ptr->next;
	ptr->next=temp->next;
	temp->next->prev=ptr;
	free(temp);
	return start;
}

struct node *delete_node(struct node *start)
{
	struct node *ptr;
	int num;
	printf("enter a node to delete:");
	scanf("%d",&num);
	ptr=start;
	if(ptr->data==num)
	{
		start=delete_beg(start);
		return start;
	}
	else
	{
		while(ptr->data!=num)
		{
			ptr=ptr->next;
		}
		ptr->next->prev=ptr->prev;
		ptr->prev->next=ptr->next;
		free(ptr);
		return start;
	}
}

struct node *delete_list(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=NULL)
	{
		start=delete_end(start);
		ptr=start;
	}
	start=NULL;
	free(start);
	printf("entire list is deleted");
	return start;
}
