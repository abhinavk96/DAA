#include<stdio.h>
long long int ar[10000],n,t,i,p,q;
int main()
{
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		ar[i]=i;
	p=2;
	q=2;
	for(i=2;i<=n;i++)
	{
		if(ar[i]%2==0)
			q++;
		else
		{
			t=ar[p];
			ar[p]=ar[q];
			ar[q]=t;
			p++;
			q++;
		}
	}
	for(i=1;i<=n;i++)
		printf("%lld ",ar[i]);
	printf("\n");

}
