#include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

void radix_sort(char **,int,int);
void countsort(char**,int,int);

int main()
{
	char **input;
	char ch=' ';
	int n,k,i,j;
	srand(time(NULL));
	scanf("%d",&n);
	scanf("%d",&k);
	input = (char **)malloc(n*sizeof(char *));
	for(i=0;i<n;i++)
	{
		input[i]=(char *)malloc((k+1)*sizeof(char));
		for(j=0;j<k;j++)
			input[i][j]=(rand()%95)+32;
		input[i][k]='\0';
	}
//	printf("hell");
	radix_sort(input,n,k);
//	printf("P");
	for(i=0;i<n;i++)
	{
		printf("%s\n",input[i]);
	}

	return 0;
}

void radix_sort(char **input,int n,int k)
{
	int i;
//	printf("hello");
	for(i=k-1;i>=0;i--)
		countsort(input,n,i);
//	printf("hello");
}
void countsort(char **input,int n,int index)
{
	int i,j;
	int count[100]={0};
	char output[n+1][1001];
	for(i=0;i<n;i++)
		count[input[i][index]-32]++;
	for(i=1;i<n;i++)
		count[i]=count[i]+count[i-1];
	for(i=n-1;i>=0;i--)
	{
		int x= input[i][index]-32;
		strcpy(output[count[x]-1],input[i]);
		count[x]--;
	}
	for(i=0;i<n;i++)
		strcpy(input[i],output[i]);

}

