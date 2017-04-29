#include<stdio.h>
#include<stdlib.h>
int pivot(int a[],int low,int high)
{
	int p,i,j;
	p=a[high];
	i=low-1;
	for(j=low;j<high;j++)
	{
		if(p>=a[j])
		{
			i++;
			int tmp;
			tmp=a[j];
			a[j]=a[i];
			a[i]=tmp;
		}
	}
	int t;
	t=a[i+1];
	a[i+1]=a[high];
	a[high]=t;
	return (i+1);

}
void quick_sort(int a[],int low,int high)
{
	int partition;
	if(low<high)
	{
		partition=pivot(a,low,high);
		quick_sort(a,low,partition-1);
		quick_sort(a,partition,high);
	}
}	
int main()
{
	int a[100],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quick_sort(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%d   ",a[i]);
}
