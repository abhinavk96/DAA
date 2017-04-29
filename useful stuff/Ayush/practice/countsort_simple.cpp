#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void countsort(int a[100], int n)
{
    int max,min;
    max = INT_MIN;
    min = INT_MAX;
    int i;
    for(i = 0; i < n; i++) {
        if(a[i] > max)
            max = a[i];
        if(a[i] < min)
            min = a[i];
    }
    int count [max - min + 1];

    for(i = 0; i < max - min + 1; i++)
        count[i] = 0;

    for(i = n - 1; i >= 0; i--) {
        count[a[i] - min]++;
    }
    for(i = 1; i <= max - min; i++) {
        count[i] = count[i] + count[i - 1];
    }
    int output[n];
    for(i = n - 1; i >= 0; i--) {
        output[count[a[i] - min] - 1] = a[i];
        count[a[i] - min]--;
    }
    for(i = 0; i < n; i++)
        a[i] = output[i];
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    countsort(a,n);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
