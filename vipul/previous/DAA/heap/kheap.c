# include <stdio.h>
# include <stdlib.h>

int check_MAX_heap(int *,int,int);
void build_MAX_heap(int *,int, int);
int extract_MAX(int *,int, int);
void insert(int *,int,int,int);
void change(int *,int,int,int,int);
void heapify(int *,int,int,int);
void increase(int *,int,int,int);
void swap(int *,int *);
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
  if(!check_MAX_heap(arr,n,k)){
	//printf("%d",check_MAX_heap(arr,n,k));
    build_MAX_heap(arr,n,k);
	}
	//for(i=0;i<n;i++){
		//printf("%d ",arr[i]);
	//}
  do
    {
      while(getchar()!='\n'); /* To clear the buffer of any leftover characters*/
      ch=getchar();
      switch(ch)
	{
	case 'i':
	  scanf("%d",&new);
	  insert(arr,n,k,new);
	  n++;
	  break;
	case 'd':
	  printf("%d",extract_MAX(arr,n,k));
	  n--;
	  break;
	case 'c':
	  scanf("%d",&i);
	  scanf("%d",&new);
	  change(arr,n,k,i,new);
	  break;
	}
    }while(ch!='q');
  return 0;
}

int check_MAX_heap(int arr[],int n,int k)
{
  /* The function returns 0 if arr is NOT a k-ary MAX-heap.*/
	int i;
	for(i=0;i<n;i++){
		int j;
		for(j=1;j<=k;j++){
			if(i*k+j<n && arr[i]<arr[i*k+j])
				return 0;
		}
	}
	return 1;
}

void build_MAX_heap(int arr[],int n,int k)
{
  /* This function shuffle the elements of arr till it is a k-ary MAX-heap*/
	int i;
	for(i=(n-1)/k;i>=0;i--){
		heapify(arr,i,n,k);
	}
		
}

void insert(int arr[],int n,int k,int new)
{
  /* This function inserts a new element into the k-ary MAX-heap arr*/
	arr[n]=new;
	int i;
	//for(i=0;i<=n;i++){
		//printf("%d ",arr[i]);
	//}
	increase(arr,n,n+1,k);
	for(i=0;i<=n;i++){
		printf("%d ",arr[i]);
	}
}

int extract_MAX(int arr[],int n,int k)
{
  /* This function extracts the maximum element of a k-ary MAX-heap and returns it*/
	int max = arr[0],i;
	swap(&arr[0],&arr[n-1]);
	heapify(arr,0,n-1,k);
	//for(i=0;i<n-1;i++){
		//printf("%d ",arr[i]);
	//}
	return max;
}

void change(int arr[],int n,int k,int i,int new)
{
  /* This function changes the value of arr[i]= new and makes arr a k-ary max-heap*/
	arr[i]=new;
	if(arr[i]>arr[(i-1)/k])
		increase(arr,i,n,k);
	else 
		heapify(arr,i,n,k);
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
void heapify(int arr[],int i,int n,int k){
	int max,j;
	while(1){
		max=i;
		for(j=1;j<=k;j++){
			if((i*k+j)<n && arr[max]<arr[i*k+j])
				max=i*k+j;
		}
		if(max!=i){
			swap(&arr[i],&arr[max]);
			i=max;
		}
		else
			break;
	}
}
void increase(int arr[],int i,int n,int k){
	while(i>0){
		int p=(i-1)/k;
		if(arr[i]>arr[p]){
			swap(&arr[i],&arr[p]);
			i=p;
		}
		else
			break;
	}
} 
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}  

