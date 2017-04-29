// Quick_Sort.cpp by Soumik Chatterjee
// Program to implement quick sort for sorting an array of numbers
// Copyright 2016 @ Soumik Chatterjee


#include <iostream>
using namespace std;


int partition(int a[], int low, int high)
{
	int pivot = low;
	int piv = 0;  // Acting as a direction signifying whether the pivot is on the right or the left.
	while( low < high )
	{
		if( piv == 0)
		{
			if( a[pivot] <= a[high])
				high--;
			else
			{
			    swap(a[pivot], a[high]);
				pivot = high;
				piv = 1;
			}
		}
		else
		{
			if( a[pivot] >= a[low])
				low++;
			else
			{
			    swap(a[pivot], a[low]);
				pivot = low;
				piv = 0;
			}
		}
	}
	return pivot;
}


void quick_sort(int ar[], int low, int high)
{
	if(low < high)
	{
		int pivot = partition(ar, low, high);
		quick_sort(ar, low, pivot - 1);
		quick_sort(ar, pivot + 1, high);
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
		for (i = 0; i < n; ++i)
		{
			cin>>ar[i];
        }
		quick_sort(ar, 0, n-1);
		for (i = 0; i < n; ++i)
		{
			cout<<ar[i]<<" ";
		}
		cout<<endl;
	}
//    int n;
//    cin>>n;
//    int ar[n];
//    for(int i = 0; i < n; i++)
//    {
//        cin>>ar[i];
//    }
//    quick_sort(ar, 0, n-1);
//    for(int i = 0; i < n; i++)
//    {
//        cout<<ar[i]<<" ";
//    }
//    cout<<endl;
    return 0;
}
