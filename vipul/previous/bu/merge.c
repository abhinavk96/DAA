#include <stdio.h>
#define sc(x) scanf("%d",&x)
void merge(int arr[],int s,int m,int e)
{
    int nl,nr,i,j,k;
    nl=m-s+1;
    nr=e-(m+1)+1;
    int *l=(int *)malloc(nl*sizeof(int));
    int *r=(int *)malloc(nr*sizeof(int));
    for(i=s;i<=m;i++)
    {
        l[i-s]=arr[i];
    }
    for(i=m+1;i<=e;i++)
    {
        r[i-m-1]=arr[i];
    }
    i=j=0;
    k=s;
    while(i<nl&&j<nr)
    {
        if(l[i]<=r[j])
        {
            arr[k++]=l[i++];
        }
        else
        {
            arr[k++]=r[j++];
        }
    }
    while(i<nl)
    {
        arr[k++]=l[i++];
    }
    while(j<nr)
    {
        arr[k++]=r[j++];
    }
}
void merge_sort(int arr[],int s,int e)
{
    if(s<e)
    {
        int m=(s+e)/2;
        merge_sort(arr,s,m);
        merge_sort(arr,m+1,e);
        merge(arr,s,m,e);
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
    merge_sort(arr,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

