#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection(int a[], int low, int high)
{
    int smallest;
    int i,j;
    for(i = 0; i <= high; i++) {
        smallest = i;
        for(j = i + 1; j <= high; j++) {
            if(a[j] < a[smallest])
                smallest = j;
        }
        swap(&a[i],&a[smallest]);
    }
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    selection(a,0,n - 1);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
