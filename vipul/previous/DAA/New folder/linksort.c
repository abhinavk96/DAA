#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void insert_beg(struct node **start,int a){
	struct node *p=(struct node *)malloc(sizeof(struct node));
	p->data=a;
	p->next=*start;
	*start=p;
}
void display(struct node *start){
	struct node *p=start;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}
void insort(struct node **start){
	if(*start==NULL){
		return;
	}
	struct node *p,*t,*x,*y;
	p=*start;
	x=*start;
	y=NULL;
	for(t=(*start)->next;t!=NULL;){
		p=*start;
		y=NULL;
		printf("%d %d\n",t->data,x->data);
		while(p->data<t->data&&p!=t){
			y=p;
			p=p->next;
		}
		printf("%d\n",p->data);

		if(p!=t){
			if(p!=*start){
			
		
			x->next=t->next;
			t->next=p;
			y->next=t;
			display(*start);

			
		}
		else{
			x->next=t->next;
			t->next=p;
			*start=t;
			display(*start);
		}
		t=x->next;
	}
	else{
		x=t;
		t=t->next;
	}
}
}
main(){
	int k=1,c,a;
	struct node *start=NULL;
	while(k){
		printf("enter choice ");
		scanf("%d",&c);
		switch(c){
			case 1:
				printf("enter data ");
				scanf("%d",&a);
				insert_beg(&start,a);
				break;
			case 2:
				display(start);
				break;
			case 3:
				insort(&start);
				break;
			default:
				k=0;
				break;
		}
	}
}
