# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void hybridSort(int *,int);
void bubble_sort(int *arr,int low,int high)
{
	int i,j;
	for(i=low;i<high;i++)
	{
		for(j=low;j<high;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int tmp;
				tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
	}
}
void merge(int *arr,int low,int mid,int high)
{
	int n1,n2;
	int left[100],right[100];
	n1=mid-low+1;
	n2=high-mid;
	int i,j;
	for(i=0;i<n1;i++)
	{
		left[i]=arr[low+i];
	}
	for(j=0;j<n2;j++)
	{
		right[j]=arr[mid+1+j];
	}
	int k=low;
	i=0;j=0;
	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
		{
			arr[k]=left[i];
			k++;
			i++;
		}
		else
		{
			arr[k]=right[j];
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		arr[k]=left[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=right[j];
		k++;
		j++;
	}
}
void merge_sort(int *arr,int low,int high,int k)
{
	if(low<high)
	{
		int mid;
		mid=low+(high-low)/2;
		if((high-low)<k)
		{
			bubble_sort(arr,low,high);
		}
		else
		{
			merge_sort(arr,low,mid,k);
			merge_sort(arr,mid+1,high,k);
			merge(arr,low,mid,high);
		}
	}
}
int main()
{
	int *arr,n;
	srand((unsigned int)time(NULL));
	scanf("%d",&n);
	arr = (int *)malloc(n*sizeof(int));
	hybridSort(arr,n);
	int i;
	for(i=0;i<n;i++)
		printf("%d   ",arr[i]);
	return 0;
}


void hybridSort(int *arr, int n)
{
	clock_t begin,end;
	int i,k;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&k);
	begin = clock();
	merge_sort(arr,0,n-1,k);
	end = clock();
	double time;
	time=(double)(end-begin);
	printf("%d,%lf\n",k,time);
}

