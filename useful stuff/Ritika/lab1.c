# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void hybridSort(int *,int);
void bubble_sort(int *a,int low,int high)
{
	int i,j;
	for(i=low;i<high;i++)
	{
		for(j=low;j<high-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int tmp;
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
}
int partition(int *a,int low,int high)
{
	int pivot,tmp;
	pivot=a[high];
	int i=low-1;
	int j;
	for(j=low;j<high;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
		//	int tmp;
			tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
		}
	}
	tmp=a[i+1];
	a[i+1]=a[high];
	a[high]=tmp;
	return i+1;
}
void quick_sort(int *a,int low,int high,int k)
{
	if(low<high)
	{
		int pivot;
		pivot=partition(a,low,high);
		if(pivot<k)
		{
			bubble_sort(a,low,high);
		}
		else
		{
			quick_sort(a,low,pivot-1,k);
			quick_sort(a,pivot+1,high,k);
		}
	}
}
int main()
{
	int *arr,n,i;
	srand((unsigned int)time(NULL));
	scanf("%d",&n);
	arr = (int *)malloc(n*sizeof(int));
	hybridSort(arr,n);
	for(i=0;i<n;i++)
		printf("%d   ",arr[i]);
	return 0;
}


void hybridSort(int *arr, int n)
{
	int k;
	clock_t begin,end;
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&k);
	begin = clock();
	
	quick_sort(arr,0,n-1,k);
	end = clock();
	double time;
	time=(double)(end-begin);
	printf("%d,%lf\n",k,time);

}

