#include<stdio.h>
#include<conio.h>
int stack[10],top=-1;
void push(int);
int pop();
 int main()
 {
 	int arr[10],n,i,val;
 	printf("enter the no. of elements in array:");
 	scanf("%d",&n);
 	printf("enter array elements\n");
 	for(i=0;i<n;i++)
 		scanf("%d",&arr[i]);
 	for(i=0;i<n;i++)
 		push(arr[i]);
 	for(i=0;i<n;i++)
 	{
 		val=pop();
		arr[i]=val;	
	}
	printf("the reversed array is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
	getch();
 	return 0;
 }
 
 void push(int val)
 {
 	top++;
	stack[top]=val;
 }
 int pop()
 {
 	return stack[top--];
 	
 }
