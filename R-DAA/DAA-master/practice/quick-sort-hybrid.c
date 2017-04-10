#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 1000
#define MAX_NUM_SIZE 1000000
int partition(int a[], int start, int end);
void quickSort(int a[], int start, int end);
void display (int *, int );
void swap(int *, int *);
int main ()
{
    srand(time(NULL));
    int a[SIZE],i;
    for(i=0;i<SIZE;i++)
    {
        a[i] = rand()%MAX_NUM_SIZE;
    }

    quickSort(a,0,SIZE-1);
    display(a,SIZE);

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

void display(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}