#include<stdio.h>
#include<stdlib.h>
void max_heapify(int a[],int n,int index)
{
	int left,right,largest;
	left=(2*index)+1;
	right=(2*index)+2;
	largest=index;
	if(left<n && a[left]>a[largest])
		largest=left;
	if(right<n && a[right]>a[largest])
		largest=right;
	if(largest!=index)
	{
		int tmp;
		tmp=a[largest];
		a[largest]=a[index];
		a[index]=tmp;
		max_heapify(a,n,largest);
	}
}
void build_heap(int a[],int n)
{
	int i;
	for(i=(n-1)/2;i>=0;i--)
		max_heapify(a,n,i);
}
void heap_sort(int a[],int n)
{
	int i;
	for(i=n-1;i>=0;i--)
	{
		int tmp;
		tmp=a[0];
		a[0]=a[i];
		a[i]=tmp;
		max_heapify(a,i,0);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[100],i,j,k;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	build_heap(a,n);
	heap_sort(a,n);
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
}
