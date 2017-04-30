# include <stdio.h>
# include <stdlib.h>

int check_MAX_heap(int *,int,int);
void build_MAX_heap(int *,int, int);
int extract_MAX(int *,int, int);
void insert(int *,int,int,int);
void change(int *,int,int,int,int);

int main()
{
    char ch=' ';
    int *arr,n,k,i,new;
    scanf("%d",&k);
    scanf("%d",&n);
    arr = (int *)malloc(2*n*sizeof(int));
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    if(!check_MAX_heap(arr,n,k))
        build_MAX_heap(arr,n,k);

    do {
        while(getchar()!='\n');
        ch = getchar();
        switch(ch) {
            case 'i':{
                scanf("%d",&new);
                insert(arr,n,k,new);
                n++;
                break;
            }
            case 'd':{
                printf("%d",extract_MAX(arr,n,k));
                n--;
                break;
            }
            case 'c':{
                scanf("%d",&i);
                scanf("%d",&new);
                change(arr,n,k,i,new);
                break;
            }
            case 'p': {
                for(i = 0; i < n;i++)
                printf("%d ",arr[i]);
                printf("\n");
            }
        }
    }while(ch!='q');
    return 0;
}

int check_MAX_heap(int arr[],int n,int k)
{

	int i,j,t;
	int max;
	for(i = 0; i <= n/k - 1; i++) {
		for(j = k*i + 1; j <= k*i + k; j++) {
			if(arr[i] < arr[j])
				return 0;
		}
	}
	return 1;
}

void heapify(int arr[],int n, int k, int i)
{
	while(i < n) {
		int largest = i;
		int temp;
		int j;
		for(j = k*i+1; (j < n) && (j <= k*i+k);j++) {
			if(arr[j] > arr[largest])
				largest = j;
		}
		if(i != largest) {
			temp = arr[largest];
			arr[largest] = arr[i];
			arr[i] = temp;
			i = largest;
		}
		else
			break;
	}
}

void build_MAX_heap(int arr[],int n,int k)
{
    int i;
	for(i = n - 1;i >= 0; i--)
		heapify(arr,n,k,i);
}

void restoreup(int arr[], int n, int k, int i)
{
	int child = i;
	int parent = (i - 1)/k;
	int temp;
	while(parent >= 0 && arr[parent] < arr[child]) {
		temp = arr[parent];
		arr[parent] = arr[child];
		arr[child] = temp;
		child = parent;
		parent = (child - 1) / k;
	}
}

void insert(int arr[],int n,int k,int new)
{
  	arr[n] = new;
	restoreup(arr,n + 1,k,n);
}

int extract_MAX(int arr[],int n,int k)
{
	int max = arr[0];
	arr[0] = arr[n-1];
	heapify(arr,n-1,k,0);
	return max;
}

void change(int arr[],int n,int k,int i,int new)
{
  	if(arr[i] < new) {
		arr[i] = new;
		restoreup(arr,n,k,i);
	}
	else if(arr[i] > new) {
		arr[i] = new;
		heapify(arr,n,k,i);
	}
	else
		arr[i] = new;
}
