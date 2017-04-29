#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int ar[][2], int low, int high)
{
	int pivot = low;
	int piv = 0;  // Acting as a direction signifying whether the pivot is on the right or the left.
	while( low < high )
	{
		if( piv == 0)
		{
			if( (ar[pivot][0] < ar[high][0]) || (ar[pivot][0] == ar[high][0] && ar[pivot][1] <= ar[high][1]))
				high--;
			else
			{
			    swap(&ar[pivot][0], &ar[high][0]);
			    swap(&ar[pivot][1], &ar[high][1]);
				pivot = high;
				piv = 1;
			}
		}
		else
		{
			if( (ar[pivot][0] > ar[low][0]) || (ar[pivot][0] == ar[low][0] && ar[pivot][1] >= ar[low][1]))
				low++;
			else
			{
			    swap(&ar[pivot][0], &ar[low][0]);
			    swap(&ar[pivot][1], &ar[low][1]);
				pivot = low;
				piv = 0;
			}
		}
	}
	return pivot;
}
void quick_sort(int ar[][2], int left, int right)
{
	if(left <= right)
	{
		int pivot = partition(ar, left, right);
		quick_sort(ar, left, pivot - 1);
		quick_sort(ar, pivot + 1, right);
	}
}
void display(int ar[][2], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d %d\n", ar[i][0], ar[i][1]);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int ar[n][2];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &ar[i][0]);
		scanf("%d", &ar[i][1]);
	}
	quick_sort(ar, 0, n-1);
	display(ar, n);
	return 0;
}