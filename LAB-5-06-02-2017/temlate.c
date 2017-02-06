# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct stat{
  int item;
  int lenLong;
  float avgComp;
  float stdDev;
};

void hash_ETH(char **);
void hash_cpp(char **);
void hash_cc1(char **);

int main()
{
  char **input;
  struct stat hash_stat;
  int n,k,i,j;
  srand(time(NULL));
  n=1632;
  k=5;
  input = (char **)malloc(n*sizeof(char *));
  for(i=0;i<n;i++)
    {
      input[i]=(char *)malloc((k+1)*sizeof(char));
      for(j=0;j<k;j++)
	input[i][j]=(rand()%95)+32;
      input[i][k]='\0';
    }
  printf("ETH\n");
  for(i=1040;i<=1050;i++)
    {
      hash_stat = hash_ETH(input,i);
      printf("%d,%f,%f\n",i,hash_stat.avgComp,hash_stat.stdDev);
    }
  printf("GNU-cc1\n");
  for(i=1040;i<=1050;i++)
    {
      hash_stat = hash_cc1(input,i);
      printf("%d,%f,%f\n",i,hash_stat.avgComp,hash_stat.stdDev);
    }
  printf("GNU-cpp\n");
  for(i=1040;i<=1050;i++)
    {
      hash_stat = hash_cpp(input,i);
      printf("%d,%f,%f\n",i,hash_stat.avgComp,hash_stat.stdDev);
    }
  
  return 0;
}

struct stat hash_ETH(char **input,int tablesize)
{
  struct stat hash_stat;

  /* write the program to perform ETH on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
  
  return hash_stat;
}

 struct stat hash_cpp(char **input,int tablesize)
{
  struct stat hash_stat;

  /* write the program to perform GNU-cpp on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
  
  return hash_stat;
}

struct stat hash_cc1(char **input,int tablesize)
{
  struct stat hash_stat;

  /* write the program to perform GNU-cc1 on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
  
  return hash_stat;
}

