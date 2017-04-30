# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <math.h>
struct stat{
  int item;
  int lenLong;
  float avgComp;
  float stdDev;
};

struct stat hash_ETH(char **, int);
struct stat hash_cpp(char **, int);
struct stat hash_cc1(char **, int);

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
	//printf("%d %d %d %f %f\n", i, hash_stat.item, hash_stat.lenLong, hash_stat.avgComp, hash_stat.stdDev);
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

struct stat hash_ETH(char **input,int tablesize) {
	struct stat hash_stat;
  /* write the program to perform ETH on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
	int cnt[tablesize];
	int i;
	for(i = 0; i < tablesize; i++) {
		cnt[i] = 0;
	}
	int j;
	for(i = 0; i < 1632; i++) {
		int h = 1;
		for(j = 0; j < 5; j++) {
			h = input[i][j] * (h%257 + 1);
		}
		h = h%tablesize;
		cnt[h]++;
	}
	float sum1, sum2;
	sum1 = 0;
	sum2 = 0;
	int mx = 0;
	for(i = 0; i < tablesize; i++) {
		float val = (cnt[i] * (cnt[i] + 1));
		val/=2;
		sum1 = sum1 + val;
		float nval;
		nval = val;
		nval = nval * (2 * cnt[i] + 1);
		nval/=3;
		sum2 = sum2 + nval;
		if(cnt[i] > mx) {
			mx = cnt[i];
		}
	}
	//printf("%f\n", sum2);
	hash_stat.item = 1632;
	hash_stat.lenLong = mx;
	hash_stat.avgComp = sum1/1632;
	hash_stat.stdDev = sum2/1632 - hash_stat.avgComp*hash_stat.avgComp;
	hash_stat.stdDev = sqrt(hash_stat.stdDev);
	return hash_stat;
}

struct stat hash_cpp(char **input,int tablesize) {
	struct stat hash_stat;

  /* write the program to perform GNU-cpp on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
	long long int mod1 = 0;
	int cnt[tablesize];
	int i;
	for(i = 0; i <= 31; i++) {
		mod1 = mod1|(1LL << i);
	}
	for(i = 0; i < tablesize; i++) {
		cnt[i] = 0;
	}
	int j;
	//printf("%lld %d\n", mod1, tablesize);
	for(i = 0; i < 1632; i++) {
		long long int h = 0;
		for(j = 0; j < 5; j++) {
			h = 4 * h + input[i][j];
		}
		h = h&mod1;
		h = h%tablesize;
		cnt[h]++;
	}
	float sum1, sum2;
	sum1 = 0;
	sum2 = 0;
	int mx = 0;
	for(i = 0; i < tablesize; i++) {
		float val = (cnt[i] * (cnt[i] + 1));
		val/=2;
		sum1 = sum1 + val;
		float nval;
		nval = val;
		nval = nval * (2 * cnt[i] + 1);
		nval/=3;
		sum2 = sum2 + nval;
		if(cnt[i] > mx) {
			mx = cnt[i];
		}
	}
	
	hash_stat.item = 1632;
	hash_stat.lenLong = mx;
	hash_stat.avgComp = sum1/1632;
	hash_stat.stdDev = sum2/1632 - hash_stat.avgComp*hash_stat.avgComp;
	hash_stat.stdDev = sqrt(hash_stat.stdDev);
 
	
	return hash_stat;
}

struct stat hash_cc1(char **input,int tablesize) {
  struct stat hash_stat;

  /* write the program to perform GNU-cc1 on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
	long long int mod1 = 0;
	int cnt[tablesize];
	int i;
	for(i = 0; i <= 30; i++) {
		mod1 = mod1|(1LL << i);
	}
	for(i = 0; i < tablesize; i++) {
		cnt[i] = 0;
	}
	int j;
	//printf("%lld %d\n", mod1, tablesize);
	for(i = 0; i < 1632; i++) {
		long long int h = 5;
		for(j = 0; j < 5; j++) {
			h = 613 * h + input[i][j];
		}
		h = h&mod1;
		h = h%tablesize;
		cnt[h]++;
	}
	float sum1, sum2;
	sum1 = 0;
	sum2 = 0;
	int mx = 0;
	for(i = 0; i < tablesize; i++) {
		float val = (cnt[i] * (cnt[i] + 1));
		val/=2;
		sum1 = sum1 + val;
		float nval;
		nval = val;
		nval = nval * (2 * cnt[i] + 1);
		nval/=3;
		sum2 = sum2 + nval;
		if(cnt[i] > mx) {
			mx = cnt[i];
		}
	}
	
	hash_stat.item = 1632;
	hash_stat.lenLong = mx;
	hash_stat.avgComp = sum1/1632;
	hash_stat.stdDev = sum2/1632 - hash_stat.avgComp*hash_stat.avgComp;
	hash_stat.stdDev = sqrt(hash_stat.stdDev);
  	return hash_stat;
}
