#include<stdio.h>
#include<stdlib.h>
int getmax(int a[],int n)
{
	int max;
	max=a[0];
	int i;
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	return max;
}
void count_sort(int a[],int n,int exp)
{
	int count[100]={0},m;
	int output[100],i;
	for(i=0;i<n;i++)
	{
		count[(a[i]/exp)%10]++;
	}
	for(i=1;i<10;i++)
		count[i]=count[i]+count[i-1];
	for(i=n-1;i>=0;i--)
	{
		output[count[(a[i]/exp)%10]-1]=a[i];
		count[(a[i]/exp)%10]--;
	}
	for(i=0;i<n;i++)
		a[i]=output[i];
}
void radix_sort(int a[100],int n)
{
	int exp,i,m;
	m=getmax(a,n);
	for(exp=1;m/exp>0;exp*=10)
		count_sort(a,n,exp);
	
}
int main()
{
	int n,ar[100],i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&ar[i]);
	radix_sort(ar,n);
	for(i=0;i<n;i++)
		printf("%d  ",ar[i]);
	return 0;
}
