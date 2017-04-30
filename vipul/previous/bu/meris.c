# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void hybridSort(int *,int);

int main()
{
  int *arr,n;
  srand((unsigned int)time(NULL));
  scanf("%d",&n);
  arr = (int *)malloc(n*sizeof(int));
  hybridSort(arr,n);
  return 0;
}
void merge(int *arr,int s,int mid,int e)
{
	int n1,n2,i,j,k;
	n1=mid-s+1;
	n2=e-mid;
	k=s;
	int l[n1],r[n2];
	for(i=s;i<=mid;i++)
	{
		l[i-s]=arr[i];
	}
	for(i=mid+1;i<=e;i++)
	{
		r[i-mid-1]=arr[i];
	}
	i=0;
	j=0;
	while((i<n1)&&(j<n2))
	{
		if(l[i]<=r[j])
		{
			arr[k++]=l[i++];
		}
		else
		{
			arr[k++]=r[j++];
		}
	}
	while(i<n1)
	{
		arr[k++]=l[i++];
	}
	while(j<n2)
	{
		arr[k++]=r[j++];
	}
}
void mergesort(int *a,int s,int e,int k)
{
	if(s<e)
	{
		if(e-s+1<k)
		{
			int i,j,hole;
			for(i=s+1;i<=e;i++)
			{
				hole=i;
				j=a[i];
				while(hole>0&&a[hole-1]>j)
				{
					a[hole]=a[hole-1];
					hole--;
				}
				a[hole]=j;
			}
		}
		else
		{
			int mid=(s+e)/2;
			mergesort(a,s,mid,k);
			mergesort(a,mid+1,e,k);
			merge(a,s,mid,e);
		}
	}
}
void hybridSort(int *arr, int n)
{
	clock_t begin,end;
	int i,k=1;
	for(i=0;i<n;i++)
	{
		arr[i]=rand();
		//arr[i]=n-i;
		//printf("%d ",arr[i]);
	}
	//printf("\n");
    begin = clock();
    mergesort(arr,0,n-1,k);
    for(i=0;i<n;i++)
    {
    	//printf("%d ",arr[i]);
    }
    end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%d , %lf\n",k,time_spent);
}

