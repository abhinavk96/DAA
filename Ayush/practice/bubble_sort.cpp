#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble(int a[100], int low, int high)
{
    int flag = 0;
    int i,j;
    for(i = 0; i <= high; i++) {
        flag = 0;
        for(j = 0; j <= high - i; j++) {
            if(a[j] > a[j+1]) {
                flag = 1;
                swap(&a[j],&a[j+1]);
            }
        }
        if(!flag)
            break;
    }
}
int main()
{
    int a[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    bubble(a,0,n - 1);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
