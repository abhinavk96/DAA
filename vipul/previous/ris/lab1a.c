# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void hybridSort(int *,int);
void swap (int *a, int *b);
int partition ( int a[], int low, int high);
void quicksort ( int a[], int low, int high, int k);
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
	for ( k = 1 ; k <= 100 ; k++){
		for ( i = 0; i < n ; i++){
			array[i] = arr[i];
		}
		begin = clock();
		quicksort ( array, 0, n-1, k);
		end = clock();

		t =(double)( end - begin) / CLOCKS_PER_SEC;
		printf("%d\t%lf\n",k,t);
	}
}

void swap (int *a, int *b)
{
	(*b) = (*a) + (*b) - ( (*a)=(*b) );
}

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
			isort(a, low, high);
		}
		else {
			q = partition ( a, low, high);
			quicksort ( a, low,q-1, k);
			quicksort ( a, q+1, high, k);
		}
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

