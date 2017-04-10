#include<stdio.h>
#include<string.h>
#include<stdlib'h>
#define max 10
int top=-1;
//int max=10;
int arr[max];
void push(int ele)
{
    if(top==max-1)
    {
        printf("stack full");
        return;
    }
    else
        arr[++top]=ele;
}
char pop()
{
    if(top==-1)
    {
        printf("empty stack");
        exit(0);
    }
    else
    {
        int item=arr[top];
        top--;
        return item;
    }
}
int main()
{
    int i;
    char nm[25];
    printf("enter the string");
    gets(nm);
    for(i=0;i<strlen(nm);i++)
        push(nm[i]);
    for(i=0;i<strlen(nm);i++)
        nm[i]=pop();
    printf("\nthe reversed string is %s",nm);
    return 0;
}
