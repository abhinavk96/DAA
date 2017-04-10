#include<stdio.h>
#include<stdlib.h>
void max_heapify(long long int a[],long long int index,long long int n)
{
	long long int left,right,largest;
	left=(2*index)+1;
	right=(2*index)+2;
	largest=index;
	if(left<n && a[largest]<a[left])
		largest=left;
	if(right<n && a[largest]<a[right])
		largest = right;
	if(largest != index)
	{
		int tmp;
		tmp=a[largest];
		a[largest]=a[index];
		a[index]=tmp;
		max_heapify(a,largest,n);
	}
}

void build_heap(long long int a[],long long int n)
{
	long long int i;
	for(i=(n-1)/2;i>=0;i--)
		max_heapify(a,i,n);
}
long long int extract_max(long long int a[],long long int n)
{
	long long int t;
	t=a[0];
	a[0]=a[0]-1;
	max_heapify(a,0,n);
	return t;
}
int main()
{
	long long int n,m;
	scanf("%lld %lld",&m,&n);
	long long int i,j,a[m+1];
	for(i=0;i<m;i++)
		scanf("%lld",&a[i]);
	build_heap(a,m);
	long long int max,sum=0;
	for(i=0;i<n;i++)
	{
		max=extract_max(a,m);
		sum=sum+max;
	}
	printf("%lld\n",sum);
}
