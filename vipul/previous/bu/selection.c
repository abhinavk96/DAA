#include <stdio.h>
#define sc(x) scanf("%d",&x)
int main()
{
    int j,i,n,mn,tmp;
    sc(n);
    int *arr=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        sc(arr[i]);
    }
    for(i=0;i<n-1;i++)
    {
        mn=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[mn])
            {
                mn=j;
            }
        }
        tmp=arr[i];
        arr[i]=arr[mn];
        arr[mn]=tmp;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

