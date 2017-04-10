#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *link;
};
struct node *add_at_beg(struct node *start,int n)
{
	struct node *tmp;
	tmp=(struct node*)malloc(sizeof(struct node));	
	tmp->data=n;
	tmp->link=start;
	start=tmp;
	return start;
}
void display(struct node *start)
{
	struct node *p=start;
	while(p!=NULL)
	{
		printf("%d -->",p->data);
		p=p->link;
	}
}
struct node *add_at_end(struct node *start,int n)
{
	struct node *p,*tmp;
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
		p->link=tmp;
		tmp->link=NULL;
		return start;
	}
}
int main()
{
	int n,p,t,r;
	struct node *start=NULL;
	printf("Enter data");
	scanf("%d",&n);
	start=add_at_beg(start,n);
	scanf("%d",&p);
	start=add_at_beg(start,p);
	scanf("%d",&t);
	start=add_at_end(start,t);
	display(start);
}

