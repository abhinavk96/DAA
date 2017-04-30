#include<stdio.h>
#include<stdlib.h>
struct node {
	int rank;
	int data;
	struct node *parent;
};
struct node *makeset(int n)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=n;
	tmp->rank=0;
	tmp->parent=tmp;
	return tmp;
}
struct node *findset(struct node *n)
{
	struct node *tmp=n->parent;
	if(tmp==n)
		return tmp;
	n->parent=findset(n->parent);
	return n->parent;
}
struct node *unionset(struct node *n1,struct node *n2)
{
	struct node *parent1=findset(n1);
	struct node *parent2=findset(n2);
	if(parent1->rank>=parent2->rank)
	{
		parent2->parent=parent1;
		parent1->rank+=1;
		return parent1;
	}
	else
	{
		parent1->parent=parent2;
		parent2->rank+=1;
		return parent2;
	}
}
int main()
{
	int adj[4][4],n,i,j,k,l;
	struct node *a[4],*start;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	for(i=0;i<3;i++)
		a[i]=makeset(i);

	for(i = 0;i <3; i++)

	{

		for(j=0;j<3;j++)

		{

			if(adj[i][j] == 1)

			{

				start = unionset(a[i],a[j]);

			}

		}

	}

	for(i = 0;i<3 ;i++)

	{

		start = findset(a[i]);

		printf("\n%d",start->data);

	}

	return 0;
}
