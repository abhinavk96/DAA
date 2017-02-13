#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion(int a[100],int low, int high)
{
    int i,j,key;
    for(i = low + 1; i <= high; i++) {
        key = a[i];
        j = i - 1;
        while(a[j] > key && j >= 0) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    insertion(a,0,n - 1);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}

