# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
int check_MAX_heap(int *,int,int);
void build_MAX_heap(int *,int, int);
int extract_MAX(int *,int, int);
void insert(int *,int,int,int);
void change(int *,int,int,int,int);
void Max_Heapify(int *, int , int, int);
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
	int i,j,child;
	for(i=0;i<n;i++)
	{
		for(j=1; j<=k && j<n; j++)
		{
			child = k * i + j;
			if(child > arr[i])
				return 0;
		}
	}
	return 1;
}

void build_MAX_heap(int arr[],int n,int k)
{
  /* This function shuffle the elements of arr till it is a k-ary MAX-heap*/
	int i, j;
	printf("\n");
	for(i = (n-1)/k;i>=0;i--)
	{
			Max_Heapify(arr, n, i, k);
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

void insert(int arr[],int n,int k,int new)
{
  /* This function inserts a new element into the k-ary MAX-heap arr*/
	int i;
	arr[n] = INT_MIN;
	change(arr, n+1, k, n, new);
	for(i=0;i<=n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

int extract_MAX(int arr[],int n,int k)
{
  /* This function extracts the maximum element of a k-ary MAX-heap and returns it*/
    int max = arr[0],i;
    arr[0] = arr[n-1];
    Max_Heapify(arr, n-1, 0, k);
for(i=0;i<n-1;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
    return max;
}

void change(int arr[],int n,int k,int i,int new)
{
  /* This function changes the value of arr[i]= new and makes arr a k-ary max-heap*/
	if(arr[i]<new)
	{
		arr[i] = new;	
	    int parent = (i-1)/k, temp;
	    while (parent>=0)
	    {
		if (arr[i] > arr[parent])
		{
		    temp = arr[i];
		    arr[i] = arr[parent];
		    arr[parent] = temp;
		    i = parent;
		    parent = (i -1)/k;
		}
		else
		    break;
	    }
		}
	if(arr[i]>new)
	{
		arr[i] = new;
		Max_Heapify(arr,n,i,k);
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
	
}

void Max_Heapify(int arr[], int n, int i, int k)
{
	int kchildren[k+1], temp, j;
	while(1)
	{
		for(j=1;j<=k;j++)
		{
			kchildren[j] = k * i + j;
			if(kchildren[j]>=n)
				kchildren[j] = INT_MIN;
		}
	int max = INT_MIN, maxIndex ;
 

        for (int j=1; j<=k; j++)
        {
            if (kchildren[j] != INT_MIN &&
                arr[kchildren[j]] > max)
            {
                maxIndex = kchildren[j];
                max = arr[kchildren[j]];
            }
        }
		//printf("ola ola 2");
	if (max == INT_MIN)
            break;
	if (arr[i] < arr[maxIndex])
		{
		temp = arr[i];
		arr[i] = arr[maxIndex];
		arr[maxIndex] = temp;
		}
 
        i = maxIndex;
	}
}


