#include <iostream>
using namespace std;

void merge(int ar[], int l1, int h1, int l2, int h2)
{
	int n1, n2;
	n1 = h1 - l1 + 1;  // No of elements in first array
	n2 = h2 - l2 + 1;  // No of elements in second array
	int L[n1];
	int R[n2];
	int i, j;
	
	// Copying the elements in the two seperate arrays for merging
	
	for(i = 0; i < n1; i++)
		L[i] = ar[l1 + i];
	for(i = 0; i < n2; i++)
		R[i] = ar[l2 + i];
		
	int k = l1;  // Resultant array indexing
	i = 0;  // First array indexing
	j = 0;  // Second array indexing
	while( i < n1 && j < n2)  // Merging
	{
		if(L[i] <= R[j])
			ar[k++] = L[i++];
		else
			ar[k++] = R[j++];
	}
	// Copy remaining elements into the final array
	while( i < n1)
		ar[k++] = L[i++];
	
	
	while( j < n2)
		ar[k++] = R[j++];
}
void merge_sort(int ar[], int l, int r)
{
	if( l < r ) // While there are more than 1 element
	{
		int mid = ( l + r ) / 2;
		merge_sort( ar, l , mid);
		merge_sort( ar, mid + 1, r);
		merge(ar, l, mid, mid+1, r);
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
		for(int i = 0; i < n; i++)
			cin>>ar[i];
		merge_sort(ar, 0, n-1);
		for(int i = 0; i < n; i++)
			cout<<ar[i]<<" ";
		cout<<endl;
	}
	return 0;
}
