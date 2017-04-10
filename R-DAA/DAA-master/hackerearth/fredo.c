#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n;
		
		scanf("%lld",&n);
		long long int f = n, s = 0 , e=n , t=0,i = 1,r=0;
		if(n==1)
		{
			t=1;
			printf("%lld\n",t);
			break;
		}
	//	printf("%lld %lld \n",e,s);
		while(1)

		{
			if(e==s||e<s)
				break;
			t = t + i;
			
			s = s + 1;
			e = e - i;
			i = i +1;


		}
		if(e < s)
		{
			i=i-1;
			s=s-1;
			e=e+i;
			t=t-i;
		}
//		printf("%lld %lld %lld\n",t,e,s);
		while(1)
		{
			if(e==s)
				break;
			t++;
			e--;
		 
		}
//		printf("%lld\n",t);
		if(e == s)
		{
			t=t+((n)-e);
		}
		printf("%lld\n",t);

	}
	return 0;
}

