#include<stdio.h>
void counting_sort(int a[],int n,int exp)
{
	int b[n],count[10]={0};
	int i;
/*	for(i=0;i<=k;i++)
		count[i]=0;*/
	for(i=0;i<n;i++)
		count[(a[i]/exp)%10]+=1;
	for(i=1;i<10;i++)
		count[i]+=count[i-1];
	for(i=n-1;i>=0;i--)
	{
		b[count[(a[i]/exp)%10]-1]=a[i];
		count[(a[i]/exp)%10]-=1;
	}
	for(i=0;i<n;i++)
		a[i]=b[i];
}
int max_no(int a[],int n)
{
	int max=a[0];
	int i;
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
	return max;
 } 
void radix_sort(int a[],int n)
{
	int m=max_no(a,n);
	int exp;
	for(exp=1;m/exp>0;exp*=10)
		counting_sort(a,n,exp);
}
int main()
{
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radix_sort(arr, n);
    int i;
    for(i=0;i<n;i++)
    	printf("%d ",arr[i]);
    return 0;
}
