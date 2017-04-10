#include<stdio.h>
#include<stdlib.h>
void max_heapify(int a[],int index)
{
	
//	while(1)
//	{
		int left,right,i;
		left = (2*index)+1;
		right = (2*index)+2;
		int largest=index;
		
		if(a[left]>a[largest])
			largest=left;
		if(a[right]>a[largest])
			largest = right;
	//	if(index==largest)
	//		break;
		if(index!=largest)
		{
			int tmp;
			tmp=a[largest];
			a[largest]=a[index];
			a[index]=tmp;
			max_heapify(a,largest);
		}
//	}
}
void build_heap(int a[],int n)
{
	int i;
	for(i=(n-1)/2;i>=0;i--)
	{
		max_heapify(a,i);
	}
}
void insert(int a[],int *n,int i)
{
	int j;
	j=*n;
	a[*n]=i;
	(*n)++;
	int parent;
	if(*n%2==0)
	{
		parent=(*n-2)/2;
	}
	else
		parent=(*n-1)/2;
	while(1)
	{
		if(a[j]<=a[parent])
			break;
		else
		{
			int temp;
			temp=a[j];
			a[j]=a[parent];
			a[parent]=temp;
			j=parent;
			if(j%2==0)
				parent=(j-2)/2;
			else
				parent=(j-1)/2;
		}
	}
}
int main()
{
	int i,n,a[1000]={0},k1,k2,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d %d",&k1,&k2);
	build_heap(a,n);
	scanf("%d",&j);
	insert(a,&n,j);
	for(i=0;i<n;i++)
		printf("%d   ",a[i]);
	return 0;
}
