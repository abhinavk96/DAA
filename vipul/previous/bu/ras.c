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
      {
        input[i][j]=(rand()%26)+97;
      }
      input[i][k]='\0';
    }
    //strcpy(input[0],"lbt");
    //strcpy(input[1],"lat");
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
  char s[20];
  int i,cnt,j;
  for(i=0;i<n;i++)
  {
    c[input[i][ind]-32]++;
  }
  for(i=1;i<95;i++)
  {
    c[i]+=c[i-1];
  }
  cnt=1;
  while(cnt<=n)
  {
    for(i=0;i<95;i++)
    {
      if(c[i]!=0)
      {
        break;
      }
    }
    j=i;
    for(i=cnt-1;i<n;i++)
    {
      if(input[i][ind]-32==j)
      {
        strcpy(s,input[i]);
        strcpy(input[i],input[cnt-1]);
        strcpy(input[cnt-1],s);
        break;
      }
    }
    for(i=0;i<95;i++)
    {
      c[i]=0;
    }
    for(i=cnt;i<n;i++)
    {
      c[input[i][ind]-32]++;
    }
    for(i=1;i<95;i++)
    {
      c[i]+=c[i-1];
    }
    cnt++;
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
