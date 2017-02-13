# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void hybridSort(int *,int);

int main()
{
    int *arr,n;
    srand((unsigned int)time(NULL));
    scanf("%d",&n);
    arr = (int *)malloc(n * sizeof(int));
    hybridSort(arr,n);
    return 0;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int* arr, int low, int high)
{
    int j;
    int pivot = arr[high];
    int pindex = low;
    for(j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            swap(&arr[pindex], &arr[j]);
            pindex++;
        }
    }
    swap(&arr[pindex], &arr[high]);
    return pindex;
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

void quickSort(int* arr, int low, int high, int k)
{
    if(low < high) {
		int x = high - low + 1;
        if(x <= k) {
            bubbleSort(arr, low, high);
        }
		else {
            int pindex = partition(arr, low, high);
			quickSort(arr, low, pindex - 1, k);
            quickSort(arr, pindex + 1, high, k);
		}
    }
}

void hybridSort(int *arr, int n)
{
    clock_t begin, end;
    int i, k;
    int* a = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++) {
        a[i] =  rand() % 100;
    }
    quickSort(a, 0, (n - 1) / 2 , -1);
    for(k = 1; k <= 100; k++) {
        for(i = 0; i < n; i++)
            arr[i] =  a[i];
        begin = clock();
        quickSort(arr, 0, n - 1, k);
        end = clock();
        double time = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("%d %lf\n", k, time);
    }
}
