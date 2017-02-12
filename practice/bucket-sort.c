#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bucketSort(float *, int);
void display (float *, int );
void bubbleSort(float * , int);
#define SIZE 10

int main()
{
	float a[SIZE] = {0.002f, 0.245f ,0.235f, 0.89f, 0.292f , 0.775f, 0.271f, 0.664f, 0.887f , 0.895f};
	bucketSort(a,SIZE);
	display(a,SIZE);
}
void bucketSort(float a[], int n)
{
	float buckets[n][n];
	int bucketIndex[n],i,j,count = 0;
	for(i=0;i<n;i++)
	{
		bucketIndex[i] = 0;
	}
	for(i=0;i<n;i++)
	{
		int key = n*a[i];
		printf("Key %f : %d\n",a[i],key);
		buckets[key][bucketIndex[key]++] = a[i];
	}
	for(i=0;i<n;i++)
	{
		bubbleSort(buckets[i],bucketIndex[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<bucketIndex[i];j++)
		{
			a[count++] = buckets[i][j];
		}
	}
}
void display(float a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%f\n",a[i]);
    }
}

void bubbleSort(float a[], int n)
{
	int i,j;
	float temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[i]>a[i+1])
			{
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
		}
	}
	for(i = 0; i<n;i++)
	{
		printf("Bubblesort : %f\n",a[i]);
	}
	printf("break========||");
}