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
	
void search(struct node a[],int l,int k)
{
	int i=0;
	while(a[i].f!=0 && i<l){
		if(a[i].data==k){
			printf("y\n");
			return;
		}
		else if(k<a[i].data){
			i=i*2+1;
		}
		else{
			i=i*2+2;
		}
	}
	printf("n\n");
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
	scanf("%d",&s);
	int b[s];
	for(i=0;i<s;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<s;i++){
		search(a,size,b[i]);
	}
	/*for(i=0;i<size;i++){
		if(a[i].f!=0)
			printf("%d",a[i].data);
	}*/
	printf("\n");
}

