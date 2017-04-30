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

void merge(int array[], int b[], int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(array[l1] <= array[l2])
         b[i] = array[l1++];
      else
         b[i] = array[l2++];
   }
   
   while(l1 <= mid)    
      b[i++] = array[l1++];

   while(l2 <= high)   
      b[i++] = array[l2++];

   for(i = low; i <= high; i++)
      array[i] = b[i];
}


void mergeSort(int array[], int b[], int low, int high, int k)
{

	if(low<high)
	{
		int mid = (high+low)/2;
		if(high-low>k){
		mergeSort(array,b, low, mid,k);
		mergeSort(array,b, mid+1, high, k);
		merge(array,b,low, mid, high);
		}
		else
			bubblesort(array,low,high+1);
	}
	
}

void hybridSort(int *arr, int n)
{

	int i,k, *b;
	b = (int*)malloc(sizeof(int)*n);
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

	mergeSort(arr,b,0,n-1,k);
      	 end = clock();
	time=((double)(end-begin))/CLOCKS_PER_SEC;
     printf("%d %f\n",k,time);
	/*for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}*/
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


