#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sc(x) scanf("%d",&x)
void cs(char **arr,int n,int d)
{
    int i,j;
    int *c=(int *)calloc(27,sizeof(int));
    char **op=(char **)malloc(n*sizeof(char *));
    for(i=0;i<n;i++)
    {
        op[i]=(char *)malloc(1000*sizeof(char));
    }
    for(i=0;i<n;i++)
    {
        c[arr[i][d]-96]++;
    }
    for(i=1;i<27;i++)
    {
        c[i]+=c[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        strcpy(op[c[arr[i][d]-96]-1],arr[i]);
        c[arr[i][d]-96]--;
    }
    for(i=0;i<n;i++)
    {
        strcpy(arr[i],op[i]);
    }
}
void rs(char **arr,int n,int m)
{
    int i;
    for(i=m-1;i>=0;i--)
    {
        cs(arr,n,i);
    }
}
int main()
{
    char **arr;
    int j,i,n,k,m;
    int t,g;
    sc(t);
    while(t--)
    {
        sc(n);m=0;
        arr=(char **)malloc(n*sizeof(char *));
        for(i=0;i<n;i++)
        {
            arr[i]=(char *)malloc(1000*sizeof(char));
            scanf("%s",arr[i]);
            if(m<strlen(arr[i]))
            {
                m=strlen(arr[i]);
            }
        }
        for(i=0;i<n;i++)
        {
            g=strlen(arr[i]);
            for(j=g;j<m;j++)
            {
                arr[i][j]=96;
            }
            arr[i][j]='\0';
        }
        rs(arr,n,m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(arr[i][j]!=96)
                {
                    printf("%c",arr[i][j]);
                }
                else
                {
                    break;
                }
            }
            printf("\n");
        }
    }
    return 0;
}




