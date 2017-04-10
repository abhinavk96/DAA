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
void push(struct node *s[],struct node *t,int *top){
	(*top)++;
	s[*top]=t;
}
void anc(struct node *s[],struct node *t,int k,int *top){
	if(t==NULL)
	return;
	if(k<t->data){
		push(s,t,top);
		anc(s,t->l,k,top);
	}
	else if(k>t->data){
		push(s,t,top);
		anc(s,t->r,k,top);

	}
	else
	return;
}
int search(struct node *t,int a){
	if(t==NULL)
	return -1;
	if(a==t->data){
		return 0;
	
	}
	if(a<t->data)
	return (search(t->l,a)+1);
	else if(a>t->data)
	return (search(t->r,a)+1);
}
void main(){
	int n,i,a,j,t1=-1,t2=-1,k1,k2;
	struct node *root=NULL,*s1[100],*s2[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		insert(&root,a);
	}
	scanf("%d %d",&k1,&k2);
	anc(s1,root,k1,&t1);
		anc(s2,root,k2,&t2);
		int f=0;
		for(i=t1;i>=0;i--){
			for(j=t2;j>=0;j--){
				if(s1[i]==s2[j]){
					f=1;
					break;
				}
				if(f)
				break;
			}
			if(f)
				break;
		}
		a=search(s1[i],k1);
		int b=search(s2[j],k2);
		printf("%d",a+b);
}
