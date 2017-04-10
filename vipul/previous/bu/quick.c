#include <stdio.h>
#define sc(x) scanf("%d",&x)
int part(int arr[],int s,int e)
{
    int pi,piv,i,tmp;
    pi=s;
    piv=arr[e];
    for(i=s;i<e;i++)
    {
        if(arr[i]<=piv)
        {
            tmp=arr[i];
            arr[i]=arr[pi];
            arr[pi]=tmp;
            pi++;
        }
    }
    tmp=arr[e];
    arr[e]=arr[pi];
    arr[pi]=tmp;
    return pi;
}
void qs(int arr[],int s,int e)
{
    if(s<e)
    {
        int pi=part(arr,s,e);
        qs(arr,s,pi-1);
        qs(arr,pi+1,e);
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
    qs(arr,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

