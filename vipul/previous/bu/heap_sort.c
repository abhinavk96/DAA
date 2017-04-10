#include <stdio.h>
#define sc(x) scanf("%d",&x)
int max_heapify(int arr[],int ind,int hs)
{
    int l,r,mx,tmp;
    l=2*ind+1;
    r=2*ind+2;
    if(l<hs&&arr[l]>arr[ind])
    {
        mx=l;
    }
    else
    {
        mx=ind;
    }
    if(r<hs&&arr[r]>arr[mx])
    {
        mx=r;
    }
    if(mx!=ind)
    {
        tmp=arr[ind];
        arr[ind]=arr[mx];
        arr[mx]=tmp;
        max_heapify(arr,mx,hs);
    }
}
void build_heap(int arr[],int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
    {
        max_heapify(arr,i,n);
    }
}
void heap_sort(int arr[],int n)
{
    build_heap(arr,n);
    int i,tmp,hs=n;
    for(i=n-1;i>0;i--)
    {
        tmp=arr[hs-1];
        arr[hs-1]=arr[0];
        arr[0]=tmp;
        hs--;
        max_heapify(arr,0,hs);
    }
}
int main()
{
    int j,i,n;
    sc(n);
    int *arr=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        sc(arr[i]);
    }
    heap_sort(arr,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
