#include <stdio.h>
#define sc(x) scanf("%d",&x)
void cs(int arr[],int n)
{
    int i,j,p=0;
    int mx=0;
    for(i=0;i<n;i++)
    {
        if(mx<arr[i])
        {
            mx=arr[i];
        }
    }
    int *c=(int *)calloc((mx+5),sizeof(int));
    for(i=0;i<n;i++)
    {
        c[arr[i]]++;
    }
    for(i=0;i<=mx;i++)
    {
        for(j=0;j<c[i];j++)
        {
            arr[p++]=i;
        }
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
    cs(arr,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}


