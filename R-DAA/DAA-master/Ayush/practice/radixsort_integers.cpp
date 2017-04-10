#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void countsort(int a[100], int n,int exp)
{
    int count [10];
    int i;
    for(i = 0; i < 10; i++)
        count[i] = 0;

    for(i = n - 1; i >= 0; i--)
        count[(a[i]/exp)%exp]++;

    for(i = 1; i < 10; i++)
        count[i] = count[i] + count[i - 1];

    int output[n];
    for(i = n - 1; i >= 0; i--) {
        output[count[(a[i]/exp)%exp] - 1] = a[i];
        count[(a[i]/exp)%exp]--;
    }
    for(i = 0; i < n; i++)
        a[i] = output[i];
}

int radixsort(int a[],int n)
{
    int i, j;
    int max = INT_MIN;
    for(i = 0; i < n; i++) {
        if(a[i] > max)
            max = a[i];
    }
    for(i = 1; max/i != 0; i = i * 10) {
        countsort(a,n,i);
    }
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    radixsort(a,n);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
