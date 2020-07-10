#include<stdio.h>
#include<conio.h>
int factorial(int);

int main()
{
	int n,v;
	printf("Calculate factorial of Number\n");
	printf("Enter a number:");
	scanf("%d",&n);
	v=factorial(n);
	printf("The result is %d",v);
	getch();
	return 0;
}

int factorial(int n)
{
	if(n==1)
	{
		return 1;
	}
	else
	{
		return (n*factorial(n-1));
	}
}
