# include <stdio.h>
# include <stdlib.h>

int check_MAX_heap(int *,int,int);
void build_MAX_heap(int *,int, int);
int extract_MAX(int *,int *, int);
void insert(int *,int *,int,int);
void change(int *,int,int,int,int);
void max_heapify( int *, int, int, int);
void increase_pr(int *, int , int );
void print(int *, int);
int main()
{
  char ch=' ';
  int *arr,n,k,i,new;
  scanf("%d",&k);
  scanf("%d",&n); /* To have anything non-trivial, n should be >2*n*k*/
  arr = (int *)malloc(2*n*sizeof(int));
  for(i=0;i<n;i++)
    {
      scanf("%d",&arr[i]);
    }
  if(!check_MAX_heap(arr,n,k))
    build_MAX_heap(arr,n,k);
  do
    {
      while(getchar()!='\n'); /* To clear the buffer of any leftover characters*/
      ch=getchar();
      switch(ch)
	{
	case 'i':
	  scanf("%d",&new);
	  insert(arr,&n,k,new);
		print(arr, n);
	  break;
	case 'd':
	  printf("%d",extract_MAX(arr,&n,k));
		print(arr, n);	  
	  break;
	case 'c':
	  scanf("%d",&i);
	  scanf("%d",&new);
	  change(arr,n,k,i,new);
		print(arr, n);
	  break;
	}
    }while(ch!='q');
  return 0;
}

int check_MAX_heap(int arr[],int n,int k)
{
  /* The function returns 0 if arr is NOT a k-ary MAX-heap.*/
	int a[k];
	int i;
	int j;
	for ( i = 0; i <= (n-1)/k; i++){
		for ( j = 1; j <=  k ; j++){
			if ( ((k*i)+j) < n ) {
				a[j-1] = arr[(k*i)+j] ;
			}
			else 
				a[j-1] = -1000 ;
		}
		int max = -1000;

		for ( j = 0; j < k; j++){
			if ( max < a[j]) max = a[j];
		}

		if ( max > arr[i]) return 0;
	}
	return 1;	
}
void print(int a[], int n){
	int i;
	printf("\n");
	for (i = 0; i < n ; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
void max_heapify( int arr[], int index, int n, int k)
{
    int a[k+1];
 
    while (1)
    {

        for (int i=1; i<=k; i++){
			if ((k*index + i) < n)
				a[i] = (k*index + i) ;
			else
				a[i] = -1;
		}
        int max_a = -1, max ;

        for (int i=1; i<=k; i++)
        {
            if (a[i] != -1 &&
                arr[a[i]] > max_a)
            {
                max = a[i];
                max_a = arr[a[i]];
            }
        }
 
        if (max_a == -1)
            break;
 

        if (arr[index] < arr[max]){
			arr[index] = arr[max] + arr[index] - (arr[max] = arr[index]) ;
 		}
        index = max;
    }
}
void increase_pr(int arr[], int index, int k)
{

    int parent = (index-1)/k;
 
    while (parent>=0)
    {
        if (arr[index] > arr[parent])
        {
            arr[index]= arr[parent] + arr[index] - (arr[parent] = arr[index]);
            index = parent;
            parent = (index -1)/k;
        }

        else
            break;
    }
}
 
void build_MAX_heap(int arr[],int n,int k)
{
  /* This function shuffle the elements of arr till it is a k-ary MAX-heap*/
	int i;
	for ( i = (n-1)/k ; i >=0 ; i--){
		max_heapify(arr, i, n, k);
	}
		
	
}

void insert(int arr[],int *n,int k,int new)
{
  /* This function inserts a new element into the k-ary MAX-heap arr*/
		if ((*n) == (2*(*n)-1)){
			printf("Heap is full\n");
			return;
		}
		(*n)++;
		arr[(*n)-1] = new;
		increase_pr(arr, ((*n)-1), k);
	
	
}

int extract_MAX(int arr[],int *n,int k)
{
  /* This function extracts the maximum element of a k-ary MAX-heap and returns it*/
	if ((*n) == 0){
		printf("Heap Empty\n");
		return -1;
	}
	int elt;
	elt = arr[0];
	arr[0] = arr[(*n)-1];
	arr[(*n)-1] = elt;
	(*n)--;
	max_heapify(arr, 0, (*n), k);
	return elt;
}

void change(int arr[],int n,int k,int i,int new)
{
  /* This function changes the value of arr[i]= new and makes arr a k-ary max-heap*/
	if (arr[i] < new){
		arr[i] = new;
		increase_pr(arr, i, k);
	}
	else {
		arr[i] = new;
		max_heapify(arr, i , n , k);
	}
}

