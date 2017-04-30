#include<stdio.h>
#include<limits.h>
struct node
{	int data;
	int priority;
} a[100];
int value(int n)
{	return n%17;
}
void maxheapify(int i,int hs,struct node heap[])
{	if(i>=hs)
		return;
	int l,max,r,j=i,tmp,t;	
		while(j<hs)
		{
		 l=(2*j)+1;
		r=(2*j)+2;
			max=j;
			if(l<hs && heap[l].priority>heap[max].priority)
			     max= l;
			if(r<hs && heap[r].priority>heap[max].priority) 
			   max=r;
		if(max!=j)
		{  tmp=heap[j].data;
			heap[j].data=heap[max].data;
			heap[max].data=tmp;
			t=heap[j].priority;
			heap[j].priority=heap[max].priority;
			heap[max].priority=t;
			j=max;	   
		}	      
		else
		break; 
	    }
}
int extractmax(struct node heap[],int *n)
{	if((*n)<=0)
		return 0;
	int max=heap[0].data;
	(*n)-=1;
	heap[0].data=heap[*n].data;
	int x= heap[0].priority;
	heap[0].priority=heap[*n].priority;
	
	maxheapify(0,*n,heap);
	return max;	
}
void increaseval(struct node q[],int i,int val,int pr)
{	int tmp;
	if(val<q[i].data)
		{
		printf("Cannot be inserted");  return;
	    }
	q[i].data=val;
	q[i].priority=pr;
	while(i>0 && q[i/2].priority<q[i].priority)
	{    tmp=q[i].data; q[i].data=q[i/2].data; q[i/2].data=tmp;
		tmp=q[i].priority; q[i].priority=q[i/2].priority; q[i/2].priority=tmp;
			i=i/2; 
	}
}
void enq(struct node q[],int data,int p,int *n)
{		if((*n)==99)
			printf("Overflow");
		(*n)+=1;
		q[*n-1].data=INT_MIN;
		
		increaseval(q,(*n)-1,data,p);	
}
void display(struct node q[],int n)
{	if(n<=0)
		printf("Queue is empty");
	int i;
	for(i=0;i<n;i++)
			printf("%d\t%d\n",q[i].data,q[i].priority);
}
main()
{	
	int l= 0,num,i,j,k;
	while(1)
	{	printf("\nEnter 1 for insertion\nEnter 2 for deletion\nEnter 3 for display\nEnter 4 for exit\n");
		scanf("%d",&num);
		switch(num)
		{	case 1:  printf("Enter data:\t"); scanf("%d",&i); j=value(i);enq(a,i,j,&l);
						break;
			case 2:  if(l!=0)
						printf("%d deleted",extractmax(a,&l));
						else
						printf("Empty");
					   break;
			case 3: display(a,l);
						break;
			case 4: printf("Wrong choice");
						return;
			
											   				 
		}
	}
}
