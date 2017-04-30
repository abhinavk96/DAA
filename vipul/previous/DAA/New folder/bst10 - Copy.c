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
struct node *mirror(struct node *r1,struct node *r2)
{
	if(r2==NULL){
		struct node *p=(struct node *)malloc(sizeof(struct node));
		p->data=r1->data;
		p->l=p->r=NULL;
		r2=p;

		if(r1->l==NULL && r1->r==NULL)
		return p;
		else{
			if(r1->l!=NULL)
				r2->r=mirror(r1->l,r2->r);
			if(r1->r!=NULL)
				r2->l=mirror(r1->r,r2->l);
		return r2;
		}
	}
	

	
}
void in(struct node *r1)
{
	if(r1==NULL){
		return;
	}
	in(r1->l);
	printf("%d ",r1->data);
	in(r1->r);
}
void main()
{
	struct node *r1=NULL,*r2=NULL;
	int n,i,a;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		r1=insert(r1,a);
	}
	r2=mirror(r1,r2);
	in(r2);
}
