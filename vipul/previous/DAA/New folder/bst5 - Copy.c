#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *l,*r;
};
struct node *insert(struct node *r1,int a){
	if(r1==NULL){
		struct node *p=(struct node *)malloc(sizeof(struct node));
		p->data=a;
		p->l=p->r=NULL;
		return p;
	}
	if(a<r1->data){
		r1->l=insert(r1->l,a);
		return r1;
	}
	else if(a>r1->data){
		r1->r=insert(r1->r,a);
		return r1;
	}
}
int pre(struct node *t,int c)
{
	if(t==NULL){
		return c;
	}
	if(t->l==NULL && t->r==NULL){
		c++;
		return c;
	}
	c=pre(t->l,c);
	c=pre(t->r,c);
	return c;
}
void main()
{
	struct node *root=NULL;
	int n,i,a,c;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		root=insert(root,a);
	}
	c=pre(root,0);
	printf("%d\n",c);
}
	
