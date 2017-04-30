#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 char str[3001],str1[3001][3001];
int n,i,k,l,a,s,d,o=0;
int ar[3001];
int main()
{
//	char str[3001],str1[3001][3001];
//	int n,l,l1,k,i;
//	printf("fn");
	gets(str);
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s",str1[i]);
	l=strlen(str);
	for(k=0;k<l;k++)
	{
		if(str[k]=='*')
			ar[o++]=k;	
	}
	for(i=0;i<n;i++)
	{
		for(k=0;k<o;k++)
			str1[i][ar[k]]='*';
	}
//	for(k=0;k<n;k++)
//		printf("%s\n",str1[k]);
	int h=0;
	char q,w;
	for(d=0;d<l;d++)
	{
	a=0;
	w=str[d];
	str[d]='*';	
	for(k=0;k<n;k++)
	{
		q=str1[k][d];

		 str1[k][d]='*';
		 if((strcmp(str,str1[k]))==0)
			a++;
		str1[k][d]=q;
	}
	if(a>h)
	h=a;
	str[d]=w;
	}
	printf("%d\n",h);
}
