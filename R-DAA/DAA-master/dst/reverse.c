#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *link;
};
struct node *add(struct node *start,int n)
{
	struct node *tmp,*p;
	p=start;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(start==NULL)
	{
		tmp->data=n;
		tmp->link=NULL;
		start=tmp;
		return start;
	}
	else
	{
		while(p->link!=NULL)
		{
			p=p->link;
		}
		tmp->data=n;
		tmp->link=NULL;
		p->link=tmp;
		return start;
	}
}
struct node *reverse(struct node *start)
{
	struct node *p,*prev,*next;
	p=start;
	prev=NULL;
	while(p!=NULL)
	{
		next=p->link;
		p->link=prev;
		prev=p;
		p=next;
	}
	return prev;
}
void display(struct node *start)
{
	struct node *p=start;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->link;
	}
	printf("\n");
}
int main()
{
	int n,p,i;
	struct node *start=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&p);
		start=add(start,p);
	}
	display(start);
	start=reverse(start);
	display(start);
}
