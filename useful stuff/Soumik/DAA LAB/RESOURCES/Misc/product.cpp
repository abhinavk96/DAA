/*There is an array of size n, a[n]. The objective is to construct another array of size n, lets call it b[n].
The array b should be such that b[i] (0<=i<n) contains the product of all elements of the array a, except the ith element (i.e. except a[i]).
For example, if array a is
4 3 5 1 10
then the array b will be
150 200 120 600 60
Simple, right? Here’s the catch: you cannot use the division operator. n can be very large, so your solution must be efficient enough to compute the array b in a reasonable amount of time. An O(n) solution would work.

*/

// product.cpp by Soumik Chatterjee
// Copyright 2016 @ Soumik Chatterjee

#include <iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Enter the no of elements in the array:";
	cin>>n;
	int i;
	int ar[n];
	for( i = 0; i < n; i++)
		cin>>ar[i];
	cout<<"The original array is:\n";
	for(i = 0; i < n; i++)
		cout<<ar[i]<<" ";
	cout<<endl;
	int left[n], right[n];
	left[0] = 1;
	right [n-1] = 1;
	for( i = 1; i < n; i++)
	{
		left [i] = left[i-1] * ar[i-1];
	}
	for( i = n-2; i >= 0; i--)
	{
		right[i] = right[i+1] * ar[i+1];
	}
	for( i = 0; i < n; i++)
	{
		ar[i] = left[i] * right[i];
	}
	cout<<"The resultant array is :\n";
	for(i = 0; i < n; i++)
	{
		cout<<ar[i]<<" ";
	}
	cout<<endl;
	return 0;
}
