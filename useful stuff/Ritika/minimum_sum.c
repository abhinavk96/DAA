/*Minimu sum of two numbers formed from the digits of an array */
#include<stdio.h>
#include<stdlib.h>
void min_heapify(int ar[],int n,int index)
{
	int left=(2*index)+1;
	int right = (2*index)+2;
	int smallest=index;
	if(left<n && ar[left]<ar[smallest])
		smallest = left;
	if(right<n && ar[right] < ar[smallest])
		smallest = right;
	if(smallest != index)
	{
		int tmp;
		tmp = ar[index];
		ar[index]  = ar[smallest];
		ar[smallest] = tmp;
		min_heapify(ar,n,smallest);
	}
}
void build_heap(int ar[],int n)
{
	int i;
	for(i=(n-1)/2;i>=0;i--)
	{
		min_heapify(ar,n,i);
	}
}
int extract_min(int ar[],int n)
{
	int min;
	min =ar[0];
	ar[0]=ar[n-1];
	n--;
	min_heapify(ar,n,0);
	return min;
}
int main()
{
	int ar[100],i,j,k,g=0,b[51],c[51],n1=0,n2=0;
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&ar[i]);
	build_heap(ar,n);
	j=n;
	k=n;
	for(i=0;i<j;i++)
	{
		int min;
		min=extract_min(ar,n);
		n--;
	//	printf("%d  ",min);
		if(g%2==0)
		{
			c[n1++]=min;
			g++;
		}
		else
		{
			b[n2++]=min;
			g++;
		}
	}
	for(i=0;i<n1;i++)
		printf("%d   ",c[i]);
	printf("\n");
	for(i=0;i<n2;i++)
		printf("%d   ",b[i]);
	printf("\n");
}
