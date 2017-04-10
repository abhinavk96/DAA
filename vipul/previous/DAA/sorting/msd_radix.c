#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char **in;
    int n,i,k;
    scanf("%d%d",&n,&k);
    in=(char **)malloc(n*sizeof(char *));
    for(i=0;i<n;i++)
        in[i]=(char*)malloc((k+1)*sizeof(char));
    for(i=0;i<n;i++)
        scanf("%s",in[i]);
        //for(i=0;i<k;i++)
    msd(in,0,n,0,k,n);
   for(i=0;i<n;i++)
printf("%s\n",in[i]);
}
msd(char **in,int l, int r, int k,int d,int n){
    if(r<=l+1)
        return;
        int i;
    char *temp,*c;
    char **out;
    temp=(int *)malloc(sizeof(int)*256);
    c=(int *)malloc(sizeof(int)*256);
    out=(char **)malloc(n*sizeof(char *));
    for(i=0;i<n;i++)
        out[i]=(char*)malloc((k+1)*sizeof(char));
    for(i=0;i<256;i++)
        temp[i]=0;
    for(i=l;i<r;i++)
        temp[in[i][k]+1]++;
    for(i=0;i<255;i++)
        temp[i+1]+=temp[i];
    for(i=0;i<256;i++)
        c[i]=temp[i];
    for(i=l;i<r;i++)
        strcpy(out[temp[in[i][k]]++],in[i]);
    for(i=l;i<r;i++)
        strcpy(in[i],out[i-l ]);
    for(i=1;i<255;i++)
        msd(in,l+temp[i],l+temp[i+1],k+1,d,n);
}
