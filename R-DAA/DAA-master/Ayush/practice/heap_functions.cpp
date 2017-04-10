#include <bits/stdc++.h>
using namespace std;


void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b =temp;
}

void heapify(int a[],int n, int i)
{
    while(i < n) {
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        if(left < n && a[left] > a[largest])
            largest = left;
        if(right < n && a[right] > a[largest])
            largest = right;
        if(i!=largest) {
            swap(&a[largest],&a[i]);
            i = largest;
        }
        else{
            break;
        }
    }
}
void ins(int a[],int n,int d)
{
    a[n] = d;
    int child = n;
    int parent = (n -1)/2;
    while(parent >= 0 && a[parent] < a[child]){
        swap(&a[parent],&a[child]);
        child = parent;
        parent = (child - 1)/2;
    }

}

int del(int a[],int* n)
{
    int temp = a[0];
    a[0] = a[*n - 1];
    (*n)--;
    heapify(a,*n,0);
    return temp;
}



void buildheap(int a[],int n)
{
    int i;
    for(i = n/2 - 1; i >=0; i--)
        heapify(a,n,i);
}

int main()
{
    int a[1000];
    int n,i;
    cin >> n;
    for(i = 0 ; i < n; i++)
        cin >> a[i];

    buildheap(a,n);

    for(i = 0 ; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    int count = 1;
    for(i = 0; i < n ; i++) {
        if(a[i] == -1) {
            swap(&a[i],&a[n - 1]);
            n--;
            heapify(a,n,i);
        }
    }
    for(i = 0 ; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
        return 0;
}
