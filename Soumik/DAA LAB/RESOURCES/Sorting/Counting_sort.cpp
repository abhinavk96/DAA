// Counting_sort.cpp by Soumik Chatterjee
// To implement counting sort algorithm.
// The time complexity of this algorithm is O(n).
// Copyright 2016 @ Soumik Chatterjee.

#include <iostream>
using namespace std;

void count_sort(int ar[], int n, int res[])
{
	int i;
	int min, max;
	min = max = ar[0];
	for( i = 0; i < n; i++)
	{
		if(ar[i] > max)
			max = ar[i];
		if(ar[i] < min)
			min = ar[i];
	}
	int m;
	m = max - min + 1;
	int count[m];
	int x;
	for( i = 0; i < m; i++)
	{
		count[i] = 0;
	}
	for(i = 0; i < n; i++)
	{
		count[ar[i] - min]++;
	}
	for( i = 0; i < m-1; i++)
	{
		count[i+1] = count[i] + count[i+1];
	}
	

	for(i = 0; i < n; i++)
	{
		x = count[ar[i] - min];
		count[ar[i] - min]--;
		res[x-1] = ar[i];
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
		int ar[n];
		int i;
		for( i = 0; i < n; i++)
			cin>>ar[i];
		int res[n];
		count_sort(ar, n, res);
		for( i = 0; i < n; i++)
			cout<<res[i]<<" ";
		cout<<endl;
	}
	return 0;
}