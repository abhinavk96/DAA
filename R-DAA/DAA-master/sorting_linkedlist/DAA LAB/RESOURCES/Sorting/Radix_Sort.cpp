#include <iostream>
#define SIZE 10
using namespace std;

void input(int ar[], int n)
{
	for(int i = 0; i < n; i++)
		cin >> ar[i];
}

void display(int ar[], int n)
{
	for(int i = 0; i < n; i++)
		cout << ar[i] << " ";
	cout << endl;
}
int find_max(int ar[], int n)
{
	int max = ar[0];
	for(int i = 0; i < n; i++)
	{
		if(ar[i] > max)
			max = ar[i];
	}
	return max;
}
void counting_sort(int ar[], int n, int expr)
{
	int res[n], i, m, x;
	// No of places required in the count array is 10
	int count[SIZE];
	// Initialize the count array
	for( i = 0; i < SIZE; i++)
	{
		count[i] = 0;
	}
	//display(count, SIZE);
	//Increment the indices of the occuring elements
	for(i = 0; i < n; i++)
	{
		count[(ar[i] / expr) % 10]++;
	}
	// Store the prefix sum of count array
	for( i = 0; i < SIZE-1; i++)
	{
		count[i+1] = count[i] + count[i+1];
	}
	

	for(i = n-1; i >= 0; i--)
	{
		x = count[(ar[i] / expr ) % 10];
		count[(ar[i] / expr) % 10]--;
		res[x-1] = ar[i];
	}
	
	for(i = 0; i < n; i++)
		ar[i] = res[i];
}
void radix_sort(int ar[], int n)
{
	int max = find_max(ar, n);
	
	for(int exp = 1; max/exp > 0; exp *= 10)
	{
		counting_sort(ar, n, exp);
	}
}
int main() {
	int n;
	cin >> n;
	int ar[n];
	input(ar, n);
	radix_sort(ar, n);
	display(ar, n);
	return 0;
}
