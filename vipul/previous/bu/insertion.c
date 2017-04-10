#include <stdio.h>
#define sc(x) scanf("%d",&x)
int main()
{
    int v,j,i,n;
    sc(n);
    int *arr=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        sc(arr[i]);
    }
    for(i=1;i<n;i++)
    {
        v=arr[i];
        j=i;
        while(j>0&&arr[j-1]>v)
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=v;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

