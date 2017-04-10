#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str1[1000][1000],str2[1000][1000],c,g[1000],h[2],str[1000][1000];
long long int n,m,i,j,k,l,q,z,a,b;
int main()
{
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%s",str1[i]);
	scanf("%lld",&m);
	for(i=1;i<=m;i++)
		scanf("%s",str2[i]);
	scanf("%lld",&q);
	for(k=0;k<=q;k++)
	{
		
		//printf("g\n");
		gets(str[k]);
	    //printf("g\n");
		h[0]=0;
		 h[1]=str[i][0];

		 l=atoi(h);
		if(l==3)
		{
			z=0;
			b=0;
			for(i=2;i<strlen(str);i++)
			{
				g[z++]=str[i];
			}
			a=atoi(g);
			for(i=1;i<=n;i++)
			{
				if((strstr(str1[i],str2[a]))!=NULL)
					b++;
			}
			printf("%lld\n",b);
		}
	}
}
