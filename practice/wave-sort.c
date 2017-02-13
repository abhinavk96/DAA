#include <stdio.h>
#define SIZE 8
void swap(int *, int *);
int main()
{
	int i,j;
	int a[SIZE] = {10, 5, 6, 3, 2, 20, 100, 80};
	for(i=1;i<SIZE;i++)
	{
		if(i%2==0)
		{
		if(a[i]<a[i-1])
			swap(&a[i],&a[i-1]);
		}
		else
		{
			if(a[i]>a[i-1])
			{
				swap(&a[i],&a[i-1]);
			}
		}
	}
	for(i=0;i<SIZE;i++)
	{
		printf("%d\n", a[i]);
	}
}

void swap(int* a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}