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
  {
    build_MAX_heap(arr,n,k);
  }
  for(i=0;i<n;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
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
  printf("  Heap is : ");
  for(i=0;i<n;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
    }while(ch!='q');
  return 0;
}
void max_heapify(int arr[],int ind,int k,int n)
{
  int child[k+1],tmp,p,mx,i;
  while(1)
  {
    for(i=1;i<=k;i++)
    {
      child[i]=(k*ind+i)<n ? k*ind+i : -1;
    }
    mx=arr[ind];
    p=ind;
    for(i=1;i<=k;i++)
    {
      if(child[i]!=-1&&arr[child[i]]>mx)
      {
        mx=arr[child[i]];
        p=child[i];
      }
    }
    if(p!=ind)
    {
      tmp=arr[ind];
      arr[ind]=arr[p];
      arr[p]=tmp;
      ind=p;
    }
    else
    {
      break;
    }
  }
}
int parent(int ind,int k)
{
  return (ind-1)/k;
}
void increase_key(int arr[],int ind,int x,int k)
{
  if(arr[ind]>=x)
  {
    return;
  }
  arr[ind]=x;
  int tmp;
  while(ind>0&&arr[ind]>arr[parent(ind,k)])
  {
    tmp=arr[ind];
    arr[ind]=arr[parent(ind,k)];
    arr[parent(ind,k)]=tmp;
    ind=parent(ind,k);
  }
}
int check_MAX_heap(int arr[],int n,int k)
{
  /* The function returns 0 if arr is NOT a k-ary MAX-heap.*/
  int i,mx,j;
  for(i=0;i<n;i++)
  {
    int child[k+1];
    for(j=1;j<=k;j++)
    {
      child[j]=(k*i+j)<n ? k*i+j : -1;
    }
    mx=0;
    for(j=1;j<=k;j++)
    {
      if(child[j]!=-1&&arr[child[j]]>mx)
      {
        mx=arr[child[j]];
      }
    }
    if(mx>arr[i])
    {
      return 0;
    }
  }
  return 1;
}
void build_MAX_heap(int arr[],int n,int k)
{
  /* This function shuffle the elements of arr till it is a k-ary MAX-heap*/
  int i;
  for(i=(n-1)/k;i>=0;i--)
  {
      max_heapify(arr,i,k,n);
  }
}

void insert(int arr[],int n,int k,int new)
{
  /* This function inserts a new element into the k-ary MAX-heap arr*/
  arr[n]=-1000;
  n++;
  increase_key(arr,n-1,new,k);
}

int extract_MAX(int arr[],int n,int k)
{
  /* This function extracts the maximum element of a k-ary MAX-heap and returns it*/
  int mx=arr[0];
  arr[0]=arr[n-1];
  n--;
  max_heapify(arr,0,k,n);
  return mx;
}

void change(int arr[],int n,int k,int i,int new)
{
  /* This function changes the value of arr[i]= new and makes arr a k-ary max-heap*/
  if(new>arr[i])
  {
      increase_key(arr,i,new,k);
  }
  else if(new<arr[i])
  {
    arr[i]=new;
    max_heapify(arr,i,k,n);
  }
}
