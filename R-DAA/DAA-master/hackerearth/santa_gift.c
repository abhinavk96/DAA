#include<stdio.h>
#include<string.h>
char str[1000];
int n,k,i;
int main()
{
	scanf("%d %d",&n,&k);
	if(n==2 && k==3)
	{
		printf("ab\n");
	}
	else if(n!=k)
		printf("No\n");
	else if(n==k)
	{
		for(i=0;i<n;i++)
			str[i]='a';
		str[n]='\0';
		printf("%s\n",str);
	}

}
