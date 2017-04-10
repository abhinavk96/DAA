#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 50
char arr[max];
int top=-1;
int match(char a,char b)
{
    if(a=='(' && b==')')
        return 1;
    if(a=='{' && b=='}')
        return 1;
    if(a=='[' && b==']')
        return 1;
    else
        return 0;
}
void push(char n)
{
    if(top==(max-1))
    {
        printf("full stack");
        return ;
    }
    else
        arr[++top]=n;
}
char pop()
{
    if(top==-1)
    {
        printf("empty stack");
        exit(0);
    }
    return (arr[top--]);
}
int check(char nm[max])
{
    int i;
    char temp;
    for(i=0;i<strlen(nm);i++)
    {
        if(nm[i]=='('||nm[i]=='['||nm[i]=='{')
            push(nm[i]);
        if(nm[i]==')'||nm[i]==']'||nm[i]=='}')
        {
            if(top==-1)
            {
                printf("\nright>left");
                return 0;
            }
            else
            {
                temp=pop();
                if(!match(temp,nm[i]))
                {
                    printf("mismatched parenthesis");
                    return 0;
                }
            }
        }
    }
}
main()
{
    char nm[max];
    printf("\nenter an exp:");
    gets(nm);
    int valid;
    valid=check(nm);
    if(valid==0)
        printf("\ninvalid");
    else
        printf("\nvalid");
}
