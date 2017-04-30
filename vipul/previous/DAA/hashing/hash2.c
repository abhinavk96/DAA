#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void insert(struct node **s,int a)
{
	struct node *p=(struct node *)malloc(sizeof(struct node));
	p->data=a;
	p->next=NULL;
	if(*s==NULL){
		*s=p;
	}
	else{
		struct node *t=*s;

		while(t->next!=NULL){
			if(t->data!=a)
				t=t->next;
			else
				break;
		}
		if(t->next==NULL&&t->data!=a)
			t->next=p;
	}
	
}
void display(struct node *s)
{
	struct node *t=s;
	while(t!=NULL){
		printf("%d\n",t->data);
		t=t->next;
	}
}
	
void main()
{
	int n,i,h,a;
	scanf("%d",&n);
	struct node *hash[10];
	for(i=0;i<10;i++){
		hash[i]=NULL;
	}
	for(i=0;i<n;i++){
		scanf("%d",&a);
		h=a%10;
		insert(&hash[h],a);
	}
	for(i=0;i<10;i++){
		if(hash[i]!=NULL){
			display(hash[i]);
		}
	}
	printf("\n");
} 

		
