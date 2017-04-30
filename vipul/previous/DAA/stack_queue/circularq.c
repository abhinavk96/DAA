#include<stdio.h>
#include<math.h>
void enque(int a[],int *rear,int *front,int value);
int deque(int a[],int *rear,int *front);
int size(int a[],int rear,int front);
int isfull(int a[],int *rear,int *front);
int isempty(int a[],int *rear,int *front);
void display(int a[],int *rear,int *front);
void main()
{  
	int n,op,choice,item,front=-1,rear=-1;
        
       
	int a[100],i;
	printf("Enter no of operations\n");
	scanf("%d",&op);
	printf("Enter 1 for enque\n2 for deque\n3 for size");
	for(i=0;i<op;i++)
		{  scanf("%d",&choice);
		    switch(choice)
                     	{
			    case 1: printf("Enter item to be enqueued");
				    scanf("%d",&item);
				    enque(a,&rear,&front,item);
				    printf("%d enqueued\n",item);
				     break;
                            case 2: item=deque(a,&rear,&front);
				    printf("%d dequeued\n",item);
				     break;
			    case 3: item=size(a,rear,front);
                                    printf("Size is %d\n",item);
			            break;
			    default : printf("Wrong choice\n");
                         }
                  }
   display(a,&rear,&front);
}
void enque(int a[],int *rear,int *front,int item)
{
	if( isfull(a,&rear,&front))
          { 
		printf("Overflow\n");
		return;
	   }	
        if( *front==-1)
	      *front=0;
           if(*rear==99)
                  *rear=0;
     a[++(*rear)]=item;
}
int deque(int a[],int *rear,int *front)
{		if(isempty( a, *rear, *front))
		{	printf("Underflow");
			return;
		}
             int f;
		f=a[*front];
	      if( *front == *rear)
		{  *front=-1;*rear=-1;
		}
		else if(*front==99)
			*front=0;
		else		
 		*front+=1;
 return f;
}
int size(int a[],int rear,int front)
{  return abs(rear-front)+1;
}
int isfull( int a[], int *rear, int *front)
{	if( (*front==0 && *rear==99 )||*front==*rear+1)
         return 1;
        else
        return 0;
}
int isempty(int a[],int *rear,int *front)
{  if( *front==-1)
      return 1;
    else 
	return 0;
}	
void display(int a[],int *rear,int *front)
{  	int i;
	i= *front;
	if( *front<= *rear)
	{ while(i<=*rear) 
		printf("%d",a[i++]);}
        else
   		{ while(i<=99)  
			printf("%d",a[i++]);
                   i=0;
			while(i<= *rear)
				printf("%d",a[i++]);
                    }
}
