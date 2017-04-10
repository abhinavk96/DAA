# include <stdio.h>
# include <stdlib.h>
# include <time.h>
#define MAX 10
void hybridSort(int *,int);
void bubblesort(int array[], int start, int end)
{
	int i,j,temp;
	for(i=start;i<end-1;i++)
		{
			for(j=start;j<end-1;j++)
				{
					if(array[j+1]<array[j])
					{
						temp = array[j];
						array[j] = array[j+1];
						array[j+1] = temp;
					}
				}
		}
}
int partition(int array[], int start, int end)
{
	int pivot, pIndex, i, temp;
	pivot = array[end];
	pIndex = start;
	for(i=start;i<end;i++)
	{
		if(array[i]<=pivot)
		{
			temp = array[i];
			array[i] = array[pIndex];
			array[pIndex] = temp;
			pIndex++;
		}
	}
	temp = array[pIndex];
	array[pIndex] = array[end];
	array[end] = temp;
	return pIndex;
}

void quicksort(int array[], int start, int end, int k)
{
	int pIndex;
	if(start<end)
		{
			if(end-start>k)
			{
			pIndex = partition(array,start,end);
			quicksort(array, start, pIndex-1,k);
			quicksort(array,pIndex+1, end,k);   
			}
			else
			{
				//printf("Initiating bubble sort\n\n%d\n========\n ",end-start);
				bubblesort(array,start,end+1);
			}
		}

}
void hybridSort(int *arr, int n)
{

	int i,k;
	scanf("%d",&k);
	/*for(i=0;i<n;i++)
		arr[i]=i;*/
		
	for(k=1;k<=100;k++){
	clock_t begin,end;
	for(i=0;i<n;i++)
	{
	arr[i] = rand()%100000;		
	}
	double time;
	
	
  begin = clock();

	quicksort(arr,0,n-1,k);
      	 end = clock();
	time=((double)(end-begin))/CLOCKS_PER_SEC;
     printf("%d %f\n",k,time);
}
for(i=0;i<n;i++)
	{
//printf("%d\t",arr[i]);
	}
}
int main()
{
  int *arr,n;
  srand((unsigned int)time(NULL));
  scanf("%d",&n);
  arr = (int *)malloc(n*sizeof(int));
  hybridSort(arr,n);
  return 0;
}


