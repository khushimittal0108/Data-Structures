#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

struct node 
{
	int num;
	int coeff;
	struct node *next;
};

struct node *start1=NULL;
struct node *start2=NULL;
struct node *start3=NULL;
struct node *start4=NULL;
struct node *last3=NULL;
struct node *create(struct node *);
struct node *display(struct node *);
struct node *add(struct node *,struct node *,struct node *);
struct node *sub(struct node *,struct node *,struct node *);
struct node *add_node(struct node *,int,int);

int main()
{
	int option;
	do
	{
		printf("\n---OPERATIONS---\n");
		printf("1.Enter first polynomial\n");
		printf("2.Display first polynomial\n");
		printf("3.Enter second polynomial\n");
		printf("4.Display second polynomial\n");
		printf("5.Add the polynomials\n");
		printf("6.Display the addition\n");
		printf("7.Subtract the polynomials\n");
		printf("8.Display the subtraction\n");
		printf("9.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1:
				start1=create(start1);
				break;
			case 2:
				start1=display(start1);
				break;
			case 3:
				start2=create(start2);
				break;
			case 4:
				start2=display(start2);
				break;
			case 5:
				start3=add(start1,start2,start3);
				break;
			case 6:
				start3=display(start3);
				break;
			case 7:
				start4=sub(start1,start2,start4);
				break;
			case 8:
				start4=display(start4);
				break;			
		}
		
	}while(option!=9);
	getch();
	return 0;
}


struct node *create(struct node *start)
{
	struct node *newnode,*ptr;
	int item,c;
	printf("To end list enter -1\n");
	printf("Enter the data:");
	scanf("%d",&item);
	printf("Enter the coefficient:");
	scanf("%d",&c);
	while(item!=-1)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->num=item;
		newnode->coeff=c;
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
		if(item==-1)
			break;
		printf("enter coefficient:");
		scanf("%d",&c);
	}
	return start;
}

struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%dx^%d+",ptr->num,ptr->coeff);
		ptr=ptr->next;
	}
	return start;
}

struct node *add(struct node *start1,struct node *start2,struct node *start3)
{
	struct node *ptr1,*ptr2;
	int sum_num,c;
	ptr1=start1;
	ptr2=start2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->coeff==ptr2->coeff)
		{
			sum_num=ptr1->num+ptr2->num;
			start3=add_node(start3,sum_num,ptr1->coeff);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->coeff<ptr2->coeff)
		{
			start3=add_node(start3,ptr2->num,ptr2->coeff);
			ptr2=ptr2->next;
		}
		else if(ptr1->coeff>ptr2->coeff)
		{
			start3=add_node(start3,ptr1->num,ptr1->coeff);
			ptr1=ptr1->next;
		}
	}
	if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			start3=add_node(start3,ptr2->num,ptr2->coeff);
			ptr2=ptr2->next;
		}
	}
	if(ptr2==NULL)
	{
		while(ptr1!=NULL)
		{
			start3=add_node(start3,ptr1->num,ptr1->coeff);
			ptr1=ptr1->next;
		}
	}
	return start3;
}

struct node *sub(struct node *start1,struct node *start2,struct node *start4)
{
	struct node *ptr1,*ptr2;
	int sub_num,c;
	ptr1=start1;
	ptr2=start2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->coeff==ptr2->coeff)
		{
			sub_num=ptr1->num-ptr2->num;
			start4=add_node(start4,sub_num,ptr1->coeff);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->coeff<ptr2->coeff)
		{
			start4=add_node(start4,-(ptr2->num),ptr2->coeff);
			ptr2=ptr2->next;
		}
		else if(ptr1->coeff>ptr2->coeff)
		{
			start4=add_node(start4,ptr1->num,ptr1->coeff);
			ptr1=ptr1->next;
		}
	}
	if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			start4=add_node(start4,ptr2->num,ptr2->coeff);
			ptr2=ptr2->next;
		}
	}
	if(ptr2==NULL)
	{
		while(ptr1!=NULL)
		{
			start4=add_node(start4,ptr1->num,ptr1->coeff);
			ptr1=ptr1->next;
		}
	}
	return start4;
}

struct node *add_node(struct node *start, int n, int c)
{
	struct node *ptr, *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode -> num = n;
	newnode -> coeff = c;
	if(start == NULL)
	{
		newnode -> next = NULL;
		start = newnode;
	}
	else
	{
		ptr = start;
		while(ptr -> next != NULL)
		ptr = ptr -> next;
		newnode -> next = NULL;
		ptr -> next = newnode;
	}	
	return start;
}


