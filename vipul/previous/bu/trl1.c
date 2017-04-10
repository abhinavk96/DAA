#include <stdio.h>
#include <limits.h>
void merge(int *arr,int s,int m,int e)
{
    int k,nl,nr,i,j;
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
    i=0;j=0;k=s;
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
void merge_sort(int *arr,int s,int e)
{
    if(e-s+1<k)
    {
        int i,j,n=e-s+1,tmp;
        int *b=(int *)malloc(n*sizeof(int));
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-1-i;j++)
            {
                if(b[j]>b[j+1])
                {
                    tmp=b[j];
                    b[j]=b[j+1];
                    b[j+1]=tmp;
                }
            }
        }
        for(i=s;i<=e;i++)
        {
            arr[i]=b[i-s];
        }
    }
    else if(s<e)
    {
        int m=(s+e)/2;
        merge_sort(arr,s,m);
        merge_sort(arr,m+1,e);
    }
}
int main()
{
    int n;
    int i;
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
