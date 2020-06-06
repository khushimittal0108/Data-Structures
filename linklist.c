#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

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
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *del_beg(struct node *);
struct node *del_end(struct node *);
struct node *del_node(struct node *);
struct node *del_after(struct node *);
struct node *del_list(struct node *);
struct node *sort(struct node *);
struct node *search(struct node *);

int main()
{
	int option;
	do
	{
		printf("\n------OPERATIONS ON LINK LIST------\n");
		printf("1.Create a list\n");
		printf("2.Display the list\n");
		printf("3.Add a node at the beginning\n");
		printf("4.Add a node at the end\n");
		printf("5.Add a node before a given node\n");
		printf("6.Add a node after a given node\n");
		printf("7.Delete a node from beginning\n");
		printf("8.Delete a node from the end\n");
		printf("9.Delete a given node\n");
		printf("10.Delete a node after a given node\n");
		printf("11.Delete the entire list\n");
		printf("12.Sort the list\n");
		printf("13.Search a given data element\n");
		printf("14.Exit\n");
		printf("Enter your option");
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
			case 7: start=del_beg(start);
					break;
			case 8: start=del_end(start);
					break;
			case 9: start=del_node(start);
			  		break;
			case 10: start=del_after(start);
					 break;
			case 11: start=del_list(start);		  		
					 break;
			case 12: start=sort(start);
			         break;
			case 13: start=search(start);
			         break;         
			}
    }while(option!=14); 
    getch();
    return 0;
}

struct node *create(struct node *start)
{
	struct node *newnode,*ptr;
	int item;
	printf("To end list enter -1\n");
	printf("Enter the data:");
	scanf("%d",&item);
	while(item!=-1)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=item;
		if(start==NULL)
		{
			newnode->next=NULL;
			start=newnode;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=newnode;
			newnode->next=NULL;
		}
		printf("enter data:");
		scanf("%d",&item);
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
		while(temp!=NULL)
		{
			printf("->%d",temp->data);
			temp=temp->next;
		}
	}
	return start;
}

struct node *insert_beg(struct node *start)
{
	struct node *newnode;
	int num;
	printf("enter data:");
	scanf("%d",&num);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
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
	newnode->next=NULL;
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
	return start;
}

struct node *insert_before(struct node *start)
{
	struct node *newnode,*ptr,*preptr;
	int num,val;
	printf("enter data");
	scanf("%d",&num);
	printf("enter value before which data is to be inserted:");
	scanf("%d",&val);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	while(ptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=newnode;
	newnode->next=ptr;
	return start;
}

struct node *insert_after(struct node *start)
{
	struct node *newnode,*ptr,*preptr;
	int num,val;
	printf("enter data");
	scanf("%d",&num);
	printf("enter value after which data is to be inserted:");
	scanf("%d",&val);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=newnode;
	newnode->next=ptr;
	return start;
}

struct node *del_beg(struct node *start)
{
	struct node *ptr;
	ptr=start;
	start=start->next;
	free(ptr);
	return start;
}

struct node *del_end(struct node *start)
{
	struct node *ptr,*preptr;
	ptr=start;
	while(ptr->next!=NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
	free(ptr);
	return start;
}

struct node *del_node(struct node *start)
{
	struct node *ptr,*preptr;
	int num;
	printf("enter node to be deleted:");
	scanf("%d",&num);
	ptr=start;
	if(ptr->data==num)
	{
		start=del_beg(start);
		return start;
	}
	else
	{
		while(ptr->data!=num)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=ptr->next;
		free(ptr);
	    return start;	
	}
}

struct node *del_after(struct node *start)
{
	struct node *ptr,*preptr;
	int num;
	printf("enter value after which the node is to be deleted:");
	scanf("%d",&num);
	ptr=start;
	preptr=ptr;
		while(preptr->data!=num)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
	preptr->next=ptr->next;
	free(ptr);
	return start;	
}

struct node *del_list(struct node *start)
{
	struct node *ptr;
	if(start!=NULL)
	{
		ptr=start;
		while(ptr!=NULL)
		{
			start=del_beg(start);
			ptr=start;
		}
	}
	printf("entire list is deleted");
	return start;
}

struct node *sort(struct node *start)
{
	struct node *ptr1,*ptr2;
	int temp;
	ptr1=start;
	while(ptr1!=NULL)
	{
		ptr2=ptr1->next;
		while(ptr2!=NULL)
		{
			if(ptr1->data>ptr2->data)
			{
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
	return start;
}

struct node *search(struct node *start)
{
	struct node *ptr;
	int val;
	printf("enter the element to search");
	scanf("%d",&val);
	ptr=start;
	while(ptr!=NULL)
	{
		if(val==ptr->data)
		{
			printf("element present");
			return start;
		}
		else
		{
			ptr=ptr->next;
		}
	}
	printf("element not present");
	return start;
}
