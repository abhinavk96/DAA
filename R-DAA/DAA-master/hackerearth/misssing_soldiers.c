#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	long long int x,y,d,sum=0;
	long long int a[100000]={0};
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lld %lld %lld",&x,&y,&d);
		long long int i;
		for(i=x;i<=(x+d);i++)
		{
			if(a[i]!=1)
			{
				a[i]=1;
				sum=sum+1;
			}
		}
	}
	printf("%lld\n",sum);
}
