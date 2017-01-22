#include <stdio.h>
#include <limits.h>

int left(int i);

int right(int i);

int parent(int i);

void Max_Heapify(int arr[], int i);

void Build_Max_Heap(int arr[]);

void display(int arr[]);

int delete(int arr[]);

void increase(int arr[], int val, int i);

void insert(int arr[], int e);

int heapsize;

int main ()
{
	int a[10] = {1,2,3,4,5,6};
	heapsize = 6;
	printf("Heapsize : %d \n", heapsize);
	Build_Max_Heap(a);
	display(a);
	delete(a);
	increase(a,10,2);
	display(a);
	delete(a);
	insert(a, 25);
	display(a);
	delete(a);
	insert(a, 30);
	display(a);

}

int left(int i)
{
	return 2*i + 1;

}

int right(int i)
{
	return 2*i + 2;
}

int parent(i)
{
	if(i==0)
		return 0;
	if(i%2==0)
		return i/2 -1;
	else
		return i/2;
}

void Max_Heapify(int a[], int i)
{
	int l, r, temp, largest;
	l = left(i);
	r = right(i);
	if(l<heapsize && a[i]<a[l])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if(r<heapsize  && 	a[largest]<a[r])
	{
		largest = r;
	}
	if (largest!=i)
	{
		temp = a[largest];
		a[largest] = a[i];
		a[i] = temp;
		Max_Heapify(a,largest);
	}

}

void Build_Max_Heap(int a[])
{
	int n,i;
	n = heapsize;
	for(i = n/2; i>=0; i--)
	{
		Max_Heapify(a,i);
	}
}

int delete(int a[])
{
	int max, temp;
	max = a[0];
	temp = a[0];
	a[0] = a[heapsize-1];
	a[heapsize-1] = temp;
	heapsize--;
	Max_Heapify(a,0);
	return max;
}

void increase(int a[], int val, int i)
{
	int temp;
	if( a[i]>val )
		return;
	a[i] = val;
	while(i>0 && a[parent(i)] < a[i])
	{
		temp = a[parent(i)];
		a[parent(i)] = a[i];
		a[i] = temp;
		i = parent(i);
	}
}

void insert(int a[], int e)
{
	heapsize++;
	a[heapsize-1] = INT_MIN;
	increase(a, e, heapsize-1);
}

void display(int a[])
{
	int n,i;
	n = heapsize;
	for(i=0;i<n;i++)
	{
		printf("\n%d", a[i]);
	}
	printf("\n================\n");
}