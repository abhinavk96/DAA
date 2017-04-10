///heaps
#include <stdio.h>

void build_min_heap(int a[],  int *hs);
void min_heapify(int a[], int i, int *hs);
void increase_priority(int a[], int i, int np);
void delete_min(int a[], int *hs);
int peek_front(int a[]);
void insert(int a[], int elem, int *hs);

int main()
{
	int i;
	int hs;//size of heap
	scanf("%d", &hs);
	int a[n];
	for (i = 0 ; i < hs; i++)
	while (1) {
		
	}
	
	return 0;
}

void min_heapify(int a[], int i, int *hs)
{
	int parent, lchild, rchild, min;
	parent = i;
	lchild = 2*i +1;
	rchild = 2*i + 2;
	min = parent;
	if ( lchild < *hs && a[parent] > a[lchild])
		min = lchild;
	if ( rchild < *hs && a[min]> a[rchild])
		min = rchild;
	
	if ( min != parent){
		a[parent] = a[min]+a[parent] - (a[min] = a[parent]);
		parent = min;
		min_heapify(a, parent, hs);
	}
	
}

void build_min_heap(int a[],  int *hs)
{
	int i = (*hs -1)/2;
	for ( ; i >= 0; i--){
		min_heapify (a, i, hs);
	}
}

void decrease_priority(int a[], int i, int np)
{
	a[i] = np;
	int parent = (i - 1) / 2 ;
	while ( a[i] < a[parent] && parent >= 0){
		a[parent] = a[i] + a[parent] - (a[i] = a[parent]);
		i = parent;
		parent = (i - 1) / 2 ;
	}
}

void delete_min(int a[], int *hs)
{
	a[0] = a[0] + a[(*hs)-1] - (a[(*hs)-1] = a[0]);
	(*hs)-- ;
	min_heapify(a, 0, hs);
}


