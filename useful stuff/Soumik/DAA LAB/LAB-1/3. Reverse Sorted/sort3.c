# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void hybridSort(int *,int);
int partition(int a[], int low, int high);
void quick_sort(int ar[], int low, int high, int k);
void bubbleSort(int *arr,int start, int n);
void swap(int *a, int *b);
int main()
{
	int *arr,n;
	srand((unsigned int)time(NULL));
	scanf("%d",&n);
	arr = (int *)malloc(n*sizeof(int));
	hybridSort(arr,n);
	return 0;
}

void hybridSort(int *arr, int n)
{
	time_t start, end;
	double times;
	int new_arr[n];
	for(int i = 0; i < n; i++)
	{
		new_arr[i] = n - i;
		//printf("%d ", arr[i]);
	}
	
	printf("#k #time\n");
	//FILE *fp = fopen("1.txt", "w");
	for(int k = 1; k <= 100; k++)
	{

		for(int i = 0; i < n; i++)
		{
			arr[i] = new_arr[i];
			//printf("%d ", arr[i]);
		}
		//printf("\nSorted:\n");
		start = clock();
		quick_sort(arr, 0, n - 1, k);
		end = clock();
		times = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("%d    %f\n",k ,times );
		 /*for(int i = 0; i < n; i++)
		 {
		 	printf("%d ", arr[i]);
		 }
		printf("\n");*/
		//fclose(fp);
	}
}

int partition(int *arr, int low, int high)
{
	int pivot = low;
	int piv = 0;  // Acting as a direction signifying whether the pivot is on the right or the left.
	while( low < high )
	{
		if( piv == 0)
		{
			if( arr[pivot] <= arr[high])
				high--;
			else
			{
			    swap(&arr[pivot], &arr[high]);
				pivot = high;
				piv = 1;
			}
		}
		else
		{
			if( arr[pivot] >= arr[low])
				low++;
			else
			{
			    swap(&arr[pivot], &arr[low]);
				pivot = low;
				piv = 0;
			}
		}
	}
	return pivot;
}

void quick_sort(int *arr, int low, int high, int k)
{
	if(low < high) 
	{
		if((high - low + 1) > k)
		{
		int pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot - 1, k);
		quick_sort(arr, pivot + 1, high, k);
		}
		else
			bubbleSort(arr, low, high);
	}
}


void bubbleSort(int *arr,int start, int high) 
{ 
	for(int i=start; i <= high; i++) 
	{ 
		int flag = 0; 
		for(int j=start; j<= high; j++) 
		{ 
			if(arr[j]>arr[j+1]) 
			{ 
				flag = 1; 
				int temp = arr[j+1]; 
				arr[j+1] = arr[j]; 
				arr[j] = temp; 
			} 
		} 
		// No Swapping happened, array is sorted 
		if(!flag)
			return; 
		
	}
} 

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
