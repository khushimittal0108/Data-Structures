#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXSIZE 1000

typedef struct stack_t{
    char item[MAXSIZE];
    int top;
} stack;

void stackinit(stack *s)
{
    s->top=-1;
}

int stackisempty(stack *s)
{
    if(s->top==-1)
    {
        return 1;
    }
    return 0;
}

int isfull(stack *s)
{
    if(s->top==MAXSIZE-1)
        return 1;
    return 0;
}

void push(stack *s,int element)
{
    s->top++;
    s->item[s->top]=element;
}

char pop(stack *s)
{
    return s->item[s->top--];

}


int evaluatepostfix(char arr[])
{
    stack s;
    int opr1,opr2,val;
    stackinit(&s);
    char substr[15];
    int i=0,j=0;
    while(i<=strlen(arr))
    {
        if(arr[i]==' ' || i==strlen(arr))
        {
            if(isdigit(substr[0]))
            {
                push(&s,atoi(substr));
            }
            else
            {
                if(stackisempty(&s))
                {
                    return 0;
                }
                opr2=pop(&s);
                if(stackisempty(&s))
                {
                    return 0;
                }
                opr1=pop(&s);
                if(!strcmp(substr,"+"))
                    val = opr1+opr2;
                if(!strcmp(substr,"-"))
                    val = opr1-opr2;
                if(!strcmp(substr,"/"))
                    val = opr1/opr2;
                if(!strcmp(substr,"*"))
                    val = opr1*opr2;
                if(!strcmp(substr,"%"))
                    val = opr1%opr2;
                push(&s,val);

            }
            memset ( substr, '\0', 15);
            j=0;

        }
        else
        {
            substr[j]=arr[i];
            j++;

        }
        i++;

    }
    if(s.top!=0)
    {
        return 0;
    }
    return(pop(&s));
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char arr[1000];
    int val;
    scanf("%[^\n]%*c",arr);
    val = evaluatepostfix(arr);
    printf("%d",val);
    return 0;
}
