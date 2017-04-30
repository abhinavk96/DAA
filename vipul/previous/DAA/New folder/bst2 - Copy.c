#include<stdio.h>
struct node{
	int data;
	int f;
};
void insert(struct node a[],int l,int k)
{
	int i=0;
	if(a[0].f==0){
		a[0].data=k;
		a[0].f=1;
		//printf("%d\n",a[0].data);
	}
	else{
		
		while(a[i].f!=0){

			if(k<=a[i].data){
				i=2*i+1;
			}
			else{
				i=2*i+2;
			}
		}
		a[i].data=k;
		a[i].f=1;
		//printf("%d\n",a[0].data);
	}
	/*for(i=0;i<l;i++){
		printf("%d\n",i);
		if(a[i].f!=0)
			printf("%d",a[i].data);
	}
	printf("\n");*/
}
void pre(struct node a[],int l,int i)
{
	if(i<l && a[i].f!=0){
		printf("%d_",a[i].data);
		pre(a,l,i*2+1);
		pre(a,l,i*2+2);
	}
}
void in(struct node a[],int l,int i)
{
	if(i<l && a[i].f!=0){
		in(a,l,i*2+1);
		printf("%d_",a[i].data);
		
		in(a,l,i*2+2);
	}
}
void post(struct node a[],int l,int i)
{
	if(i<l && a[i].f!=0){
		post(a,l,i*2+1);
		post(a,l,i*2+2);
		printf("%d_",a[i].data);
		
	}
}
void main(){
	int n,s,k,i,d=1;
	scanf("%d",&n);
	int size=0;
	for(i=0;i<n;i++){
		size+=d;
		d=d*2;
	}
	//printf("%d\n",size);
	struct node a[size];
	for(i=0;i<size;i++){
		a[i].f=0;
	}
	/*for(i=0;i<size;i++){
		printf("%d",a[i].f);
	}*/
	//printf("\n");
	for(i=0;i<n;i++){
		scanf("%d",&k);
		insert(a,size,k);
	}
	pre(a,size,0);
	printf("\n");
	in(a,size,0);
	printf("\n");
	post(a,size,0);
	printf("\n");
}
