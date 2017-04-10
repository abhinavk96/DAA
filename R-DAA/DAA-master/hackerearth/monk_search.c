#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,a[100000],q,x,t,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	while(q--)
	{
		int sum=0;
		scanf("%d",&t);
		if(t==0)
		{
			scanf("%d",&x);
			for(i=0;i<n;i++)
			{
				if(a[i]>=x)
					sum=sum+1;
			}
			printf("%d\n",sum);
		}
		if(t==1)
		{
			scanf("%d",&x);
			for(i=0;i<n;i++)
			{
				if(a[i]>x)
					sum=sum+1;
			}
			printf("%d\n",sum);
		}

	}
}
