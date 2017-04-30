# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void hybridSort(int *,int);

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void ins(int a[],int low,int high)
{
    int i, j, key;
    for(i = 1; i <= high; i++) {
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void bubbleSort(int* arr, int low, int high)
{
    int i, j;
    for (i = low; i <= high ; i++) {
        for (j = low; j <= high; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int merge(int a[],int low, int mid, int high)
{
    int nL, nR, t;
    nL = mid - low + 1;
    nR = high - mid;
    int i , j , k;
    i = 0;
    j = 0;
    k = low;
    int left[nL];
    int right[nR];
    for(t = 0; t < nL; t++)
        left[t] = a[low + t];
    for(t = 0; t < nR ; t++)
        right[t] = a[mid + t + 1];
    while(i < nL && j < nR) {
        if(left[i] < right[j]) {
            a[k] = left[i];
            k++;
            i++;
        }
        else {
            a[k] = right[j];
            k++;
            j++;
        }
    }
    while(i < nL) {
        a[k] = left[i];
        k++;
        i++;
    }
    while(j < nR) {
        a[k] = right[j];
        k++;
        j++;
    }
}

int mergesort(int a[],int l, int r, int k)
{
    if(l < r) {
	int x = r - l + 1;
	if(x <= k) {
		//bubbleSort(a, l, r);
		ins(a, l, r);	
	}
	else {
        	int mid = (r + l) / 2;
        	mergesort(a,l, mid, k);
        	mergesort(a,mid + 1,r, k);
        	merge(a,l,mid,r);
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
  	return 0;
}


void hybridSort(int *arr, int n)
{

  	clock_t begin,end;
    	int i, k;
    	int* a = (int *)malloc(n * sizeof(int));
    	for(i = 0; i < n; i++) {
        	arr[i] =  rand() % 100;
    	}
	mergesort(arr, 0, n - 1, k);
	/*	
	for(i = 0; i < n; i++)
		printf("%d ",a[i]);
	printf("\n");
	*/
    	for(k = 1; k <= 100; k++) {
        	begin = clock();
        	mergesort(arr, 0, n - 1, k);
		
		/*for(i = 0; i < n; i++)
			printf("%d ",arr[i]);
		printf("\n");*/

        	end = clock();
		double time = (double)(end - begin) / CLOCKS_PER_SEC;
        	printf("%d %lf\n", k, time);
    }
}

