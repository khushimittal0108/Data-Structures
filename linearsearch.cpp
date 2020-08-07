#include<stdio.h>
#include<conio.h>
#define MAX 20

int main()
{
	int a[MAX],i,n,item,pos=-1,count=0;
	printf("Enter the no. of elements in the array:");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the number to search:");
	scanf("%d",&item);
	for(i=0;i<n;i++)
	{
		if(a[i]==item)
		{
			count=1;
			pos=i+1;
			printf("%d Element found at position %d\n",item,pos);
		}
	}
	if(count==0)
	{
		printf("Element not found\n");
	}
	getch();
	return 0;
}
