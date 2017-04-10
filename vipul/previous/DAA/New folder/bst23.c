#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *l,*r;
};
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
		if(a<=t->data){
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
void pre(struct node *t){
	if(t==NULL){
		return;
	}

		printf("%d ",t->data);
		

	pre(t->l);
	pre(t->r);
}
struct node *search(struct node *t,int a){
	if(t==NULL)
	return t;
	if(a<t->data)
	t->l= (search(t->l,a));
	else if(a>t->data)
	t->r=(search(t->r,a));
	else{
		if(t->l==NULL)
		return t->r;
		else if(t->r==NULL)
		return t->l;
		else{
			struct node *p=t->r;
			while(p->l!=NULL){
				p=p->l;
			}
			t->data=p->data;
			
			t->r=search(t->r,p->data);
			
			
		}
	}
	
	t->l= (search(t->l,a));
	t->r= (search(t->r,a));
	return t;
}
struct node * preorder(struct node *t){
	if(t==NULL){
		return t;
}
t->l=search(t->l,t->data);
	t->l=preorder(t->l);
	t->r=preorder(t->r);
}
void main(){
	int n,i,a,j,t1=-1,t2=-1,k1,k2;
	struct node *root=NULL,*s1[100],*s2[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		insert(&root,a);
	}
	pre(root);
	root=preorder(root);
	pre(root);
}
