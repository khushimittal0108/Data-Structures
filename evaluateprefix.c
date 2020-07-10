#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 50

float stack[MAX];
int top=-1;
float pop(float stack[]);
void push(float stack[],float val);
float evaluate(char arr[] );
int get_type(char );

int main()
{
	char prefix[50];
	float val;
	printf("enter a prefix expression:\n");
	gets(prefix);
	val=evaluate(prefix);
	printf("the expression evaluates to give %f",val);
	getch();
	return 0;
}

float evaluate(char arr[])
{
	int i,len;
	float op1,op2,val,x;
	len=strlen(arr);
	for(i=len;i>=0;i--)
	{
		switch(get_type(arr[i]))
		{	
		case 0:
			x=arr[i]-'0';
			push(stack,x);
			break;
		case 1:
			op2=pop(stack);
			op1=pop(stack);
			switch(arr[i])
			{
				case '+':
					val=op1+op2;
					break;
				case '-':
					val=op1-op2;
					break;
				case '/':
					val=op1/op2;
					break;
				case '*':
					val=op1*op2;
					break;
				case '%':
					val=(int)op1%(int)op2;
					break;
			}
			push(stack,val);
		}
	}
	return pop(stack);
}

void push(float stack[],float val)
{
	if(top==MAX)
	{
		printf("Stack overflow\n");
	}
	else
	{
		top++;
		stack[top]=val;
	}
}

float pop(float stack[])
{
	float val;
	if(top==-1)
	{
		printf("Stack underflow\n");
	}
	else
	{
		val=stack[top];
		top--;
	}
	return val;
}

int get_type(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/'||c=='%')
	return 1;
	else return 0;
}
