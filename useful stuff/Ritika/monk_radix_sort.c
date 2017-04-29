#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(char str[][21],int a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				char str1[21];
				int tmp;
				tmp=a[j];
				strcpy(str1,str[j]);
				a[j]=a[j+1];
				strcpy(str[j],str[j+1]);
				a[j+1]=tmp;
				strcpy(str[j+1],str1);
			}
		}
	}
}
int main()
{
	int n,t;
	scanf("%d",&n);
	char str[n+1][21],str1[6],str2[6];
	int i,j,k=0;
	int a[n+1];
	for(i=0;i<n;i++)
		scanf("%s",str[i]);
	int m=0,l;
	for(i=0;i<n;i++)
	{
		l=strlen(str[i]);
		if(l>m)
			m=l;
	}
	int r=m;
	int ab=0;
	int h;
	do{
	for(i=0;i<n;i++)
	{
	//		printf("hello");
		
		j=(strlen(str[i]))-1;
		
			j=j-(ab*5);
		
		k=0;
		h=5;
		while(h--)
		{
			if(j<0)
				str1[k++]='0';
			else{
			str1[k++]=str[i][j];}
			j--;
		}
		str1[k]='\0';
		int q=k-1;
		for(t=0;t<k;t++)
		{
			str2[t]=str1[q];
			q--;
		}
		str2[t]='\0';
		a[i]=atoi(str2);
	}ab++;
	 
	sort(str,a,n);
	r=r-5;
	for(i=0;i<n;i++)
		printf("%s   ",str[i]);
	printf("\n");
	}while(r>=0);
}

