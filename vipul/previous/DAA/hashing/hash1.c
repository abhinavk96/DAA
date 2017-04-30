#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	char data;
	struct node *next;
};
void insert(struct node **s,char a)
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
			t=t->next;
		}
		t->next=p;
	}
}
int size(struct node *s)
{
	struct node *t=s;
	int c=0;
	while(t!=NULL){
		t=t->next;
		c++;
	}
	return c;
}
void main()
{
	int n,i,a,j,h;
	struct node *hash[52];
	for(i=0;i<52;i++){
		hash[i]=NULL;
	}
	
	scanf("%d",&n);
	char s[100];
	for(i=0;i<n;i++){
		scanf("%s",s);
		for(j=0;j<strlen(s);j++){
			h=s[j]%65;
			
			if(h>25){
				h=h-6;
			}
			insert(&hash[h],s[j]);
		}
			
	}
	for(i=0;i<52;i++){
		if(hash[i]!=NULL){
			printf("frequency of %c is %d\n",hash[i]->data,size(hash[i]));
		}
	}
	printf("\n");		
	
}

		
