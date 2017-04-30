#include<stdio.h>
long long int ar[10000][10000],ar1[10000],n,m,t,i,j,k,a,b;
int main()
{
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld %lld",&a,&b);
		ar[a][b]=1;
		ar[b][a]=1;
	}
//	printf("v %lld\n",ar[2][4]);
	for(i=0;i<1000;i++)
		ar1[i]=2;
	for(i=1;i<=n;i++)
	{
		
		if(ar1[i]==2){
			ar1[i]=1;
		//	printf("%lld\n",i);
			}
		else
			continue;
		for(j=1;j<=m;j++)
		{
			if(ar[i][j]==1&&ar1[j]==2)
			{
				ar1[j]=0;
		//		printf("j=%lld\n",j);
			}
		}
	}
	for(i=1;i<=n;i++)
		printf("%lld ",ar1[i]);
	printf("\n");
}
