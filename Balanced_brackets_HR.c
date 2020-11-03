#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the isBalanced function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//
int notsimilarbraces(char a,char b)
{
    if(a=='(' && b==')')
        return 0;
    if(a=='{' && b=='}')
        return 0;
    if(a=='[' && b==']')
        return 0;
    return 1;
    
}
char* isBalanced(char* s) {
    static char yes[]="YES";
    static char no[]="NO";
    char stack[1000];
    int top=-1,i,flag=1;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            stack[++top]=s[i]; //push to stack
        }
        if(s[i]==')' || s[i]=='}' || s[i]==']')
        {
            if(top==-1)
                flag=0;
            else
            {
                if(notsimilarbraces(stack[top--], s[i])) //pop and compare
                {
                    flag=0;
                }
            }
        }
    }
    if(top!=-1)
    {
        flag=0;
    }
    if(flag==1)
        return yes;
    else
        return no;
    

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char* s = readline();

        char* result = isBalanced(s);

        fprintf(fptr, "%s\n", result);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
