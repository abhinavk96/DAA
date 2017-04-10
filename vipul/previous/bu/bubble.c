#include <stdio.h>
#define sc(x) scanf("%d",&x)
int main()
{
    int j,i,n;
    sc(n);
    int *arr=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        sc(arr[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
