# include<stdio.h>
# include<stdlib.h>
# include<math.h>
int main()
{
	int n,m,t;
	scanf("%d",&t);
	while(t--)
	{
		float f,r;
		int n;
		scanf("%d %d",&n,&m);
		if(n==0)
		{
			printf("-1\n");
		}
		else {
		f = exp(log(m)/n);
		//f=pow(m,r);
		//int h = (int)f;;
		if(ceil(f)==f && floor(f)==f)
		{
			n=(int)f;
			printf("%d\n",n);

		}
		else
			printf("-1\n");
		}
	}
}
