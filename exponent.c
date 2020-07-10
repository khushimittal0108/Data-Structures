#include<stdio.h>
#include<conio.h>

int exp(int,int);

int main()
{
	int b,p,e;
	printf("Enter the Base:");
	scanf("%d",&b);
	printf("Enter the Power:");
	scanf("%d",&p);
	e=exp(b,p);
	printf("Result=%d",e);
	getch();
	return 0;
}

int exp(int b,int p)
{
	if(p==0)
		return 1;
	else
		return (b*exp(b,p-1));
}
