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
struct node *pre(struct node *t)
{
	if(t==NULL){
		return t;
	}
	if(t->l==NULL && t->r==NULL){
		printf("%d ",t->data);
		free(t);
		return NULL;
	}
	t->l=pre(t->l);
	t->r=pre(t->r);
	if(t->l==NULL && t->r==NULL){
		printf("%d ",t->data);
		free(t);
		return NULL;
	}
	
}
void main()
{
	struct node *root=NULL;
	int n,i,a;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		root=insert(root,a);
	}
	root=pre(root);
}
