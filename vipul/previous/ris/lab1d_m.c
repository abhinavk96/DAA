# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void hybridSort(int *,int);
void swap (int *a, int *b);
void mergesort(int arr[], int l, int r, int k);
void merge(int arr[], int l, int m, int r);
void bsort( int a[], int low, int high);


void isort(int arr[], int l, int r)
{
   int i, key, j;
   for (i = l+1; i <= r; i++)
   {
       key = arr[i];
       j = i-1;
 
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
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

//half sorted
void hybridSort(int *arr, int n)
{
	int i, k;
	int array[n];
	clock_t begin, end;
	double t;
  /* write your program here.....
     use the following block of code to find out the time of running a particular routine
     clock_t begin,end;



     begin = clock();
     
     perform your computation here

     end = clock();

     time required will be end-begin


     For random input use the following code

     arr[i] = rand();


     output should be printed in the following way for each k.

     printf("%d,%d",k,end-begin);

  */
	for ( i = 0; i < n; i++) {
		arr[i] = rand(); 
	}
	mergesort(arr, 0, n-1, 10);
	for ( i = n/2; i < n; i++){
		arr[i] = rand();
	}
	for ( k = 1 ; k <= 100 ; k++){
		for ( i = 0; i < n ; i++){
			array[i] = arr[i];
		}
		begin = clock();
		mergesort ( array, 0, n-1, k);
		end = clock();

		t =(double)( end - begin) / CLOCKS_PER_SEC;
		printf("%d\t%lf\n",k,t);
	}
}

void swap (int *a, int *b)
{
	(*b) = (*a) + (*b) - ( (*a)=(*b) );
}
/*
int partition ( int a[], int low, int high)
{
	int c, i, pivot;
	pivot = high;
	c = low;
	i = low-1;
	while ( c < high ) {
		if ( a[c] < a[pivot] ){
			i++;
			swap ( &a[i], &a[c] );
		}
		c++;
	}
	swap (&a[pivot], &a[i+1] );
	return i+1;
}

void quicksort ( int a[], int low, int high, int k)
{
	int q;
	if ( high > low){
		if ( (high - low) < k) {
			bsort(a, low, high);
		}
		else {
			q = partition ( a, low, high);
			quicksort ( a, low,q-1, k);
			quicksort ( a, q+1, high, k);
		}
	}		
}*/
void mergesort(int arr[], int l, int r, int k)
{
    if (l < r)
    {
		if  (r - l < k){
//			bsort( arr, l, r);
			isort( arr, l, r);
		}
		else {
    	    int m = l+(r-l)/2;
 
    	    mergesort(arr, l, m, k);
    	    mergesort(arr, m+1, r, k);
 	
    	    merge(arr, l, m, r);
    	}
	}
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 

    int L[n1], R[n2];
 
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    
    i = 0; 
    j = 0; 
    k = l; 
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
 

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void bsort( int a[], int low, int high)
{

	int i, j, n;
	n = high;
	for ( i = low; i < n; i++){
		for ( j = i; j < n ; j++) {
			if ( a[j] > a[j+1]){
				swap(&a[j],&a[j+1]);
			}
		}
	}
}

