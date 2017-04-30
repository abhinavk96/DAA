#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n,a[50],b[50],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	int g = 0;
	sort(a,a+n);
	sort(b,b+n);
	for(i=0;i<n;i++)
	{
		if(a[i]<b[i])
		{
			g=1;
			break;
		}
	}
	if(g==0)
		printf("Yes\n");
	else
		printf("No\n");
}
