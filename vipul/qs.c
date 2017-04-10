#include <stdio.h>

void qsort(int a[], int l, int h);
int part(int a[], int l, int h);

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for ( i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	qsort(a,0,n-1);
	for ( i = 0; i < n; i++)
	printf("%d", a[i]);
	return 0;
}

void qsort(int a[],int l, int h)
{
	if ( l < h){
		int mid = part(a,l,h);
		qsort(a,l,mid-1);
		qsort(a,mid+1,h);
	}
}
int part(int a[],int l, int h)
{
	int i, j, index;
	index = h;
	i = l;
	j = i-1;
	for ( ;i < h;i++ ){
		if (a[i] < a[index]){
			j++;
			a[j]=a[i]+a[j]-(a[i]=a[j]);
		}
	}
	j++;
	a[j] = a[index]+a[j] - (a[index] = a[j]);
	return j;
}
