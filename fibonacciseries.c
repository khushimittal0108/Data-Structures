#include<stdio.h>
#include<conio.h>

int fibonacci(int);

int main()
{
	int n,i,res;
	printf("Enter the no. of terms:");
	scanf("%d",&n);
	printf("Fibonacci Series:\n");
	for(i=0;i<n;i++)
	{
		res=fibonacci(i);
		printf("%d\t",res);
	}
	getch();
	return 0;
}

int fibonacci(int x)
{
	if(x==0)
		return 0;
	else if(x==1)
		return 1;
	else
		return (fibonacci(x-1)+fibonacci(x-2));
}
