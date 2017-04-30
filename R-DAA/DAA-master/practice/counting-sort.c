#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100
#define MAX_NUM_SIZE 1000
void countSort(int *, int n);
void display (int *, int n);
int main()
{
	srand(time(NULL));
    int a[SIZE],i;
    for(i=0;i<SIZE;i++)
    {
        a[i] = rand()%MAX_NUM_SIZE;
    }

    countSort(a,SIZE);
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

void countSort(int a[], int n)
{
	int output[n], count[MAX_NUM_SIZE], i;

	for(i=0;i<MAX_NUM_SIZE;i++)
	{
		count[i] = 0;
	}

	for(i=0;i<n;i++)
	{
		count[a[i]]++;
	}

	for(i = 1; i<MAX_NUM_SIZE; i++)
	{
		count[i] = count[i] + count[i-1];
	}
	for(i=0;i<n;i++)
	{
		output[count[a[i]]-1] = a[i]; // the -1 is there because we count the 'occurences' of a particular number which naturally begins with a 1;
		count[a[i]]--;
	}
	for(i=0;i<n;i++)
	{
		a[i] = output[i];
	}
}
