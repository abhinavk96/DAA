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
}

void build_MAX_heap(int arr[],int n,int k)
{
  /* This function shuffle the elements of arr till it is a k-ary MAX-heap*/
}

void insert(int arr[],int n,int k,int new)
{
  /* This function inserts a new element into the k-ary MAX-heap arr*/
}

int extract_MAX(int arr[],int n,int k)
{
  /* This function extracts the maximum element of a k-ary MAX-heap and returns it*/
}

void change(int arr[],int n,int k,int i,int new)
{
  /* This function changes the value of arr[i]= new and makes arr a k-ary max-heap*/
}

