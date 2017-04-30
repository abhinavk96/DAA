#include<cstdio>
#include<iostream>
#include<algorithm>
#define max 100000
using namespace std;
long long int a[max],n;
int main()
{
	long long int i,mult,j;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	printf("k");
	for(i=0;i<n;i++){
	if(i==0)
		printf("-1\n");
	else if(i==1)
		printf("-1\n");
	else if(i>1)
	{
		j=i+1;
		sort(a,a+j);
		mult=((a[i]*a[i-1])*a[i-2]);
		printf("%lld\n",mult);

	}}
	return 0;
}
