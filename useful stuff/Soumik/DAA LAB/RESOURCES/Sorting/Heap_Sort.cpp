// Heap_Sort.cpp by Soumik Chatterjee
// To implement Heap sort algorithm.
// The time complexity of this algorithm is O(nlogn).
// Here 1 based indexing is used for heapsort.
// Copyright 2016 @ Soumik Chatterjee.
#include <iostream>
using namespace std;

int leftchild(int i)
{
	return (2 * i);
}

int rightchild(int i)
{
	return ((2 * i) + 1);
}

void heapify(int ar[], int n, int i)
{
	// ar is the array, n is the total size of the array(heap), i is the index on which heapify is to be applied.
	int largest = i;
	int left = leftchild(i);
	int right = rightchild(i);

	if( left <= n && ar[left] > ar[largest])
		largest = left;
	if( right <= n && ar[right] > ar[largest])
		largest = right;

	if( largest != i)
	{
		swap(ar[largest], ar[i]);
		heapify(ar, n, largest);
	}
}

void build_heap(int ar[], int n)
{
	int i;
	for( i = n/2; i >=1; i--)
		heapify(ar, n, i);
}

void display(int ar[], int n)
{
	for(int i = 1; i <= n; i++)
		cout<<ar[i]<<" ";
}

void heapsort(int ar[], int n)
{
	build_heap(ar, n);
	int i;
	// display(ar, n);
	// cout<<endl;
	for(i = n; i>=1 ; i--)
	{
		swap(ar[1], ar[i]);
		heapify(ar, i-1, 1);
	}

}

int main()
{
	int t;
	cin>>t;
	while( t-- )
	{
		int n;
		cin>>n;
		int ar[n+1];
		int i;
		for( i = 1; i <= n; i++)
			cin>>ar[i];
		heapsort(ar, n);
		display(ar, n);
		cout<<endl;
	}
	return 0;
}