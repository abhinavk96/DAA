/* 1 v adds v; 2 v deletes v; 3 prints minimum; */
#include<stdio.h>
#include<stdlib.h>
void min_heapify(int ar[],int n,int index)
{
	int left=(2*index)+1;
	int right = (2*index)+2;
	int smallest=index;
	if(left<n&&ar[left]<ar[smallest])
		smallest=left;
	if(right<n&&ar[right]<ar[smallest])
		smallest=right;
	if(index!=smallest)
	{
		int tmp;
		tmp=ar[smallest];
		ar[smallest]=ar[index];
		ar[index]=tmp;
		min_heapify(ar,n,smallest);
	}
}
void build_heap(int ar[],int n)
{
	int i;
	for(i=(n-1)/2;i>=0;i--)
		min_heapify(ar,n,i);
}
int extract_min(int ar[],int n)
{
	int min;
	min=ar[0];
	ar[0]=ar[n-1];
	n--;
	min_heapify(ar,n,0);
	return min;
}
int main()
{
	
	int t,v,ar[1000],n=0,n1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n1);
		if(n1==1)
		{
			scanf("%d",&v);
			ar[n++]=v;
			build_heap(ar,n);
		}
		else if(n1==2)
		{
			scanf("%d",&v);
			int min;
			min=extract_min(ar,n);
			n--;
			if(min!=v)
			{
				ar[n++]=v;
				build_heap(ar,n);
			}
		}
		else if(n1==3)
		{
			int min;
			min=ar[0];
			printf("%d\n",min);
		}
	}
}
