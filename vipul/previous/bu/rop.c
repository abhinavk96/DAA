# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

void radix_sort(char **,int,int);

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
void cs(char **input,int n,int k,int ind)
{
  int c[100]={0};
  int i;
  char op[n][k+1];
  for(i=0;i<n;i++)
  {
    c[input[i][ind]-32]++;
  }  
  for(i=1;i<95;i++)
  {
    c[i]+=c[i-1];
  }
  for(i=n-1;i>=0;i--)
  {
    strcpy(op[c[input[i][ind]-32]-1],input[i]);
    c[input[i][ind]-32]--;
  }
  for(i=0;i<n;i++)
  {
    strcpy(input[i],op[i]);
  }
}
void radix_sort(char **input,int n,int k)
{
  /* The function sorts the array input using radix sort
     Write the two versions of the radix sort here, one after another.
     To execute one of the version just comment out the other version.
   */
  int i;
  for(i=k-1;i>=0;i--)
  {
    cs(input,n,k,i);
  }
}
