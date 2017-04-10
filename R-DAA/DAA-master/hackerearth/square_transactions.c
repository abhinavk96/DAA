#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,a[100000],q,r,g=0;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++)
		scanf("%d",&a[i]);
	for(i=1;i<t;i++)
		a[i]=a[i]+a[i-1];
	scanf("%d",&q);
	while(q--)
	{
		g=0;
		scanf("%d",&r);
		for(i=0;i<t;i++)
		{
			if(r<=a[i])
			{
				printf("%d\n",i+1);
				g=1;
				break;
			}
		}
		if(g==0)
			printf("-1\n");
	}
}
