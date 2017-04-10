# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

void radix_sort(char **,int,int);
void CountSort(char **input,int n,int index);

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
  radix_sort(input,n,k);
  for(i=0;i<n;i++)
    {
      printf("%s\n",input[i]);
    }

  return 0;
}
void radix_sort(char **input,int n,int k){
	int exp;
	for(exp=k-1;exp>=0;exp--)
            CountSort(input,n,exp);

}
void CountSort(char **input,int n,int index)
{
   int count[100]={0},i,j;
   char output[n+1][1001];
    for(i=0;i<n;i++)
    {	
        count[input[i][index]-32]++;
    }
    for(i=1;i<100;i++)
        count[i]=count[i]+count[i-1];

    for(i=n-1;i>=0;i--)
    {	int x=input[i][index]-32;
        strcpy(output[count[x]-1],input[i]);
        count[x]--;
    }

    for(i=0;i<n;i++)
    	strcpy(input[i],output[i]);

}
