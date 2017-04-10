#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int t;
	char a[100000];
	int l,i;
	int sum;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%s",a);
		l=strlen(a);
		for(i=0;i<l;i++)
		{
			if(a[i]=='a'||a[i]=='o'||a[i]=='e'||a[i]=='i'||a[i]=='u'||a[i]=='A'||a[i]=='O'||a[i]=='E'||a[i]=='I'||a[i]=='U')
				sum=sum+1;
		}
		printf("%d\n",sum);
	}
}
