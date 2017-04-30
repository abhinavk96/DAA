# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

void radix_sort(char **,int);
void count_sort(char **input,int n,int index)
{
	int i;
	int a=0;
	char output[n][100];
	int count[101]={0};
	for(i=0;i<n;i++)
	{
		int l;
		l=strlen(input[i]);
		if(index+1>l)
		{
			strcpy(output[a],input[i]);
			a++;
//			printf("%d\n",l);
		}
		else
		{
			count[input[i][index]-32]+=1;
		}

	}
	for(i=1;i<100;i++)
	{
		count[i]=count[i]+count[i-1];
	}
	for(i=n-1;i>=0;i--)
	{
		int t;
		t=strlen(input[i]);
		if(t>=(index+1))
		{
			strcpy(output[a+(count[input[i][index]-32]-1)],input[i]);
			count[input[i][index]-32]--;
		}

	}
	for(i=0;i<n;i++)
		strcpy(input[i],output[i]);

}
int main()
{
	char **input;
	char ch=' ';
	int n,k,i,j;
//	srand(time(NULL));
	scanf("%d",&n);
//	scanf("%d",&k);
	input = (char **)malloc(n*sizeof(char *));
	for(i=0;i<n;i++)
	{
		input[i]=(char *)malloc((20)*sizeof(char));
//		for(j=0;j<k;j++)
		scanf("%s",input[i]);
//		input[i][k]='\0';
	}
	radix_sort(input,n);
	for(i=0;i<n;i++)
	{
		printf("%s\n",input[i]);
	}

	return 0;
}

void radix_sort(char **input,int n)
{
	int i;
	int k,l;
	k=0;
	for(i=0;i<n;i++)
	{
		l=strlen(input[i]);
		if(l>k)
			k=l;	
	}
//	printf("%d",k);
	for(i=k-1;i>=0;i++)
		count_sort(input,n,i);
}


