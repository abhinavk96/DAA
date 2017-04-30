#include<stdlib.h>
#include<stdio.h>
# include <time.h>

void bubbleSort(int *, int, int);
void swap(int *a,int *b);
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r,int k)
{
    if (l < r)
    {
        if(r-l<=k)
		bubbleSort(arr,l,r);
	else{
        int m = l+(r-l)/2;


        mergeSort(arr, l, m,k);
        mergeSort(arr, m+1, r,k);

        merge(arr, l, m, r);
    }}
}


void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
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
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
void hybridSort(int *arr, int n,int k)
{
    clock_t begin,end;
    int i;
	double t;



    begin = clock();

     mergeSort(arr,0,n-1,k);
    end = clock();
	t=(double)end-begin;

	printf("%f %f\n",(double)begin,(double)end);

	printf("%d %f \n",k, t);
	FILE *f= fopen("hm1.dat","a+");
	fprintf(f,"%d \t %f\n",k,t);
	fclose(f);
	/*for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}*/

}

int main()
{
  int *arr,*ar,n,k,i,j;
  srand((unsigned int)time(NULL));
  n=100000;
  //scanf("%d",&n);
  arr = (int *)malloc(n*sizeof(int));
  ar = (int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
  {
	 arr[i]=rand();
	 ar[i]=rand();
	 //scanf("%d",&arr[i]);
  }
	//bubbleSort(ar,0,9999);
	//bubbleSort(ar,0,5000);
	/*for(i=1;i<9999;i++)
	{
		for(j=0;j<9999-i;j++)
		{
			if(ar[j]<ar[j+1])
				swap(&ar[j], &ar[j+1]);
		}
	}*/
  //scanf("%d",&k);
  //k=rand()%100;
  for(i=2;i<=100;i++){
        for(j=0;j<n;j++)
        {
            arr[j]=ar[j];
        }
         hybridSort(arr,n,i);

  }

  return 0;
}
