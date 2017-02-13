//used to find the kth smallest/largest element
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define K 7
#define SIZE 10
#define MAX_NUM_SIZE 100
int partition(int a[], int start, int end);
void quickSort(int a[], int start, int end);
void display (int *, int );
void swap(int *, int *);
int quickSelect(int *, int , int);
int main ()
{
    srand(time(NULL));
    int a[SIZE],i;
    for(i=0;i<SIZE;i++)
    {
        a[i] = rand()%MAX_NUM_SIZE;
    }

    int z = quickSelect(a,SIZE,K);
    quickSort(a,0,SIZE-1); //just for ease of verifying the result.
    display(a,SIZE);
    printf("The kth(%d) smallest element is %d",K,z);

}

void display(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}

int quickSelect(int *a , int n, int k)
{
	int A1[n], A2[n];
	int counter1 =0, counter2 = 0,i;
	int pivot = a[n-1];
	for(i=0;i<n;i++)
	{
		if(a[i]<pivot)
			A1[counter1++] = a[i];
		else if (a[i]>pivot)
			A2[counter2++] = a[i];
		else
		{

		}

	}
	if(k <= counter1)
	{
		return quickSelect(A1,counter1,k);
	}
	else if(k > n - counter2)
	{
		return quickSelect(A2,counter2,k-(n-counter2));
	}
	else
	{
		return pivot;
	}
}
void quickSort(int a[], int start, int end)
{
    if(start<end)
    {
        int pIndex = partition(a,start,end);// pIndex is partition Index.
        quickSort(a,start, pIndex-1);
        quickSort(a,pIndex+1, end);
    }
}

int partition(int a[], int start, int end)
{
    int i;
    int pivot = a[end];
    int pIndex = start;
    for(i=start;i<end;i++)
    {
        if(a[i]<=pivot)
        {
            swap(&a[i], &a[pIndex]);
            pIndex++;
        }
    }
    swap(&a[pIndex],&a[end]);
    return pIndex;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return;
}
