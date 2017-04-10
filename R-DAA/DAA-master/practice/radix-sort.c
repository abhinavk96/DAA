#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 100
#define MAX_NUM_SIZE 1000
void countSort(int *, int , int);
void display (int *, int );
int maxNum(int *, int );
void radixSort(int *, int);

int main()
{
	srand(time(NULL));
    int a[SIZE],i;
    for(i=0;i<SIZE;i++)
    {
        a[i] = rand()%MAX_NUM_SIZE;
    }

    radixSort(a,SIZE);
    display(a,SIZE);
}

void display(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}

void countSort(int a[], int n, int exp)
{
	int output[n], count[10], i;
	for(i=0;i<10;i++)
	{
		count[i] = 0;
	}

	for(i=0;i<n;i++)
	{
		count[(a[i]/exp)%10]++;
	}

	for(i = 1; i<10; i++)
	{
		count[i] = count[i] + count[i-1];
	}
	for(i=n-1;i>=0;i--)
	{
		output[count[(a[i]/exp)%10]-1] = a[i];
		count[(a[i]/exp)%10]--;
	}
	for(i=0;i<n;i++)
	{
		a[i] = output[i];
	}
}

int  maxNum (int a[], int n)
{
	int i, max = INT_MIN;
	for(i=0;i<n;i++)
	{
		if(a[i] > max)
			max = a[i];
	}
	return max;
}

void radixSort(int a[], int n)
{
	int m = maxNum(a,n), exp;
	for(exp = 1; m/exp>0; exp*=10)
	{
		countSort(a,n,exp);
	}
}