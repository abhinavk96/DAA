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
int partition(int *arr,int s,int e)
{
	int pi,i,v,t;
	pi=s;
	v=arr[e];
	for(i=s;i<e;i++)
	{
		if(arr[i]<=v)
		{
			t=arr[i];
			arr[i]=arr[pi];
			arr[pi]=t;
			pi=pi+1;
		}
	}
	t=arr[pi];
	arr[pi]=v;
	arr[e]=t;
	for(i=s;i<=e;i++)
	{
		//printf("%d ",arr[i]);
	}
	//printf("%d ",pi);
	return pi;
}
void quicksort(int *arr,int s,int e,int k)
{
	if(s<e)
	{
		if(e-s+1<k)
		{	
			int i,j,t,flag;
			//printf("%d %d \n",s,e);
			for(i=s;i<=e;i++)
			{
				//printf("%d ",arr[i]);
			}
			//printf("\n");
			for(i=s;i<=e;i++)
			{
				flag=0;
				for(j=s;j<e;j++)
				{
					if(arr[j]>arr[j+1])
					{
						t=arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=t;
						flag=1;
					}
				}
				if(!flag)
				{
					break;
				}
			}
			for(i=s;i<=e;i++)
			{
				//printf("%d ",arr[i]);
			}
			//printf("\n");
			return;
		}
		else
		{
			int pi=partition(arr,s,e);
			quicksort(arr,s,pi-1,k);
			quicksort(arr,pi+1,e,k);
		}
	}
}
void hybridSort(int *arr, int n)
{
	clock_t begin,end;
	int i,k;
	for(i=0;i<n;i++)
	{
		arr[i]=n-i;
		//printf("%d ",arr[i]);
	}
	int *b;
	b = (int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		b[i]=arr[i];
	}
	FILE *fp;
	fp=fopen("qsrev.dat","w+");
	for(k=1;k<=100;k++)
	{
	//printf("\n");
	    begin = clock();
	    quicksort(arr,0,n-1,k);
	    for(i=0;i<n;i++)
	    {
	    	//printf("%d ",arr[i]);
	    	arr[i]=b[i];
	    }
	    end = clock();
	    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	    fprintf(fp,"%d %lf\n",k,time_spent);
	}
}
