# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void hybridSort(int *,int, int);
void quickSort(int *, int, int, int);
int partition(int *, int, int);
void swap(int *, int *);
void bubbleSort(int *, int, int);

int main()
{
  int *arr,n,k,i;
  srand((unsigned int)time(NULL));
 // printf("Enter n");
  //scanf("%d",&n);
n=10000;
  arr = (int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
  {
	 //arr[i]=rand();
	 scanf("%d",&arr[i]);
  }
   //printf("Enter k");
//  scanf("%d",&k);
  hybridSort(arr,n,k);
  return 0;
}


void hybridSort(int *arr, int n,int k)
{
    clock_t begin,end;
	int i;
	double t;
  for(k=1;k<=100;k++){ 	
    begin = clock();
     quickSort(arr,0,n-1,k);
     end = clock();
	t=(double)end-begin;

	printf("beginning time :%f and ending time: %f\n",(double)begin,(double)end);
		
	printf("k: %d \t time taken: %f \n",k, t);
	FILE *f= fopen("quick.dat","a+");
	fprintf(f,"%d \t %f\n",k,t);
	fclose(f);
	/*for(i=0;i<n;i++)
	{
		printf("\n%d ",arr[i]);
	}*/

}
}

void quickSort(int *arr, int low, int high, int k) 
{
	if(low<high)
	{
		int p=partition(arr,low,high);
		if(p-low > k)
			quickSort(arr,low,p-1,k);
		else
			bubbleSort(arr,low,p-1);
		
		if(high-p > k)
			quickSort(arr,p+1,high,k);
		else
			bubbleSort(arr,p+1,high);
	}
}

int partition(int *arr, int low, int high)
{
	int pivot=arr[high];
	int i= low-1;
	int j;
	for(j=low;j<=high-1;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return (i+1);
}

void swap(int *a, int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

void bubbleSort(int *arr,int l,int h)
{
	int i,j;
	for(i=l;i<h;i++)
	{
		for(j=l;j<h-i;j++)
		{
			if(arr[j]>arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
}












	






























