#include<stdio.h>
long long int ar[100][100],n,m;
int main()
{
	for(n=0;n<100;n++)
	{
		for(m=0;m<100;m++)
			ar[n][m]=0;
	}
	for(n=0;n<100;n++)
		printf("%lld  ",ar[1][n]);
}
