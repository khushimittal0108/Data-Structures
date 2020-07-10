#include<stdio.h>
#include<conio.h>

void swap(int ,int);
int gcd(int ,int);

int main()
{
	int a,b,res;
	printf("Enter two numbers:");
	scanf("%d%d",&a,&b);
	if(b>a)
	{
		swap(a,b);
		res=gcd(a,b);
	}
	else
	{
		res=gcd(a,b);
	}
	printf("GCD of %d and %d is %d\n",a,b,res);
	getch();
	return 0;
}

void swap(int x,int y)
{
	int z;
	z=x;
	x=y;
	y=z;
}

int gcd(int a,int b)
{
	if(a%b==0)
	{
		return b;
	}
	else
	{
		return (gcd(b,a%b));
	}
}
