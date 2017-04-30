#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void merge(int a[100],int low, int high, int mid)
{
    int nl,nr,i;
    nl = mid - low + 1;
    nr = high - mid;
    int left[nl];
    int right[nr];

    for(i = 0; i < nl; i++) {
        left[i] = a[i + low];
    }
    for(i = 0; i < nr; i++) {
        right[i] = a[i + mid + 1];
    }
    int j,k;
    i = 0;
    j = 0;
    k = low;
    while(i < nl && j < nr) {
        if(left[i] < right[j]) {
            a[k] = left[i];
            k++;
            i++;
        }
        if(right[j] < left[i]) {
            a[k] = right[j];
            j++;
            k++;
        }
    }
    while(i < nl){
        a[k] = left[i];
        k++;
        i++;
    }
    while(j < nr){
        a[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int a[100], int low, int high)
{
    if(low < high) {
        int mid = (low + high)/ 2;
        mergesort(a,low,mid);
        mergesort(a,mid + 1,high);
        merge(a,low,high,mid);
    }
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    mergesort(a,0,n - 1);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}


