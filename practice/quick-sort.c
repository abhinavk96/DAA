#include <stdio.h>
#define SIZE 10
int partition(int a[], int start, int end);
void quickSort(int a[], int start, int end);
void display (int *, int );
void swap(int *, int *);
int main ()
{
    int a[SIZE] = {100,-25,96,10000,2567,890302,33,-456, 890};
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