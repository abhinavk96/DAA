#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[100], int low, int high)
{
    int i,j;
    int index = low + rand() % (high - low + 1);
    swap(&a[index],&a[high]);
    int pivot = a[high];
    int pindex = 0;
    for(i = 0; i <= high; i++) {
        if(a[i] < pivot) {
            swap(&a[i],&a[pindex]);
            pindex++;
        }
    }
    swap(&a[pindex],&a[high]);
    return pindex;
}

void quicksort(int a[100],int low,int high)
{
    if(low < high) {
        int pindex = partition(a,low,high);
        quicksort(a,low,pindex - 1);
        quicksort(a,pindex+1,high);
    }
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    quicksort(a,0,n - 1);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}

