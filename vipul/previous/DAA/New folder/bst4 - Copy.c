#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *l,*r;
};
void insert(struct node **r1,int a);
void preorder(struct node *root,struct node *t);
void search(struct node *r1,int a);
void main()
{
	int n,i,a,j;
	struct node *root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		insert(&root,a);
	}
	preorder(root,root);
}
void insert(struct node **r1,int a)
{
	struct node *p=(struct node*)malloc(sizeof(struct node));
	p->data=a;
	p->l=p->r=NULL;
	if(*r1==NULL){
		*r1=p;
		return;
	}
	struct node *t=*r1,*s=NULL;
	while(t!=NULL){
		s=t;
		if(a<t->data){
			t=t->l;
		}
		else{
			t=t->r;
		}
	}
	if(a<s->data){
		s->l=p;
		return;
	}
	s->r=p;
}
void preorder(struct node *r1,struct node *t){
	if(t==NULL){
		return;
	}
	if(t->l==NULL && t->r==NULL){
		search(r1,t->data);
		printf("\n");
		return;
	}
	preorder(r1,t->l);
	preorder(r1,t->r);
}
void search(struct node *r1,int a)
{
	if(a==r1->data){
		printf("%d ",a);
		return;
	}
	printf("%d ",r1->data);
	if(a<r1->data){
		search(r1->l,a);
	}
	else{
		search(r1->r,a);
	}
}	
	
		
		
