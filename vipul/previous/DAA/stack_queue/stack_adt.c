#include<stdio.h>
#define max 1000
int stack[max];
int top =-1;
void push(int item);
int pop();
int isempty();
int isfull();
void display();
int size();
void main()
{
   int choice,item,x,y,c,n;
   while(1){
   printf("enter 1 for push,2 for deletion,3 for isempty,4 for isfull,5 for display,6 for size,7 for exit\n");
   printf("enter choice\n");
   scanf("%d",&choice);
   switch(choice)
{
  case 1:
	  printf("enter item\n");
	  scanf("%d",&item);
	  push(item);
  break;
  case 2:if(isempty())
  	printf("no pop");
     	 c=pop();	
	printf("%d deleted",c);
 break;
  case 3:
 	 
	 x=isempty();
	printf("%d",x);
break;
  case 4:
 	 
	 y=isfull();
	printf("%d",y);
break;
  case 5: 
   	 display(); 
break;
case 6: n=size(); printf("%d",n);
  default:
  exit(0);
} 
}
}
void push(int item)
{
if(isfull())
{
printf("overflow");
return;
}
top=top+1;
stack[top]=item;
}
int pop()
{
int item;
item=stack[top];
top-=1;
return item;
}
int isempty()
{
if(top==-1)
return 1;
else
return 0;
}
int isfull()
{
if(top==max-1)
return 1;
else
return 0;
}
void display()
{
int i;
for(i=top;i>=0;i--)
printf("%d",stack[i]);
}
int size()
{ return top+1; }



