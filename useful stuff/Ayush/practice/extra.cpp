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

struct stat hash_ETH(char **,int);
struct stat hash_cpp(char **,int);
struct stat hash_cc1(char **,int);
int createmask(int,int);
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
	int hasht[tablesize];
	int i,j;
	for( i = 0; i < tablesize;i++) {
		hasht[i] = 0;
	}
	//int size = 0;
	int cmp[1632];
	for( i = 0; i < 1632 ;i++ ) {
		int h = 1;
		for(j = 0; j < 5;j++) {
			h = ((int)(input[i][j]) - 32 )*((h%257)+1);
			//printf("%d\n",h);
		}
		h = h%tablesize;
		if ( hasht[h] == 0 ) {
			cmp[i] = 1;
			hasht[h]+=1;
		} else {
			cmp[i] = hasht[h];
			hasht[h]+=1;
		}
	}

	hash_stat.item = 1632;
	int maxx = -1;
	for( i = 0; i < 1632;i++ ) {
		if ( cmp[i] > maxx ) {
			maxx = cmp[i];
		}
	}
	hash_stat.lenLong = maxx;

	long long int sum = 0;
	float avg;
	for( i = 0; i < 1632;i++) {
		sum+=cmp[i];
	}
	avg = (float)(sum)/1632.0;
	hash_stat.avgComp = avg;

	float sum1 = 0.0;
	for( i = 0; i < 1632;i++ ) {
		sum1+= (float)( (float)(cmp[i]) - avg )*( (float)(cmp[i]) - avg );
	}
	sum1 = sum1/1632.0;
	hash_stat.stdDev =  (float)sqrt(sum1);

	/* write the program to perform ETH on the given input and given hash table size.
	   collect statistics as specified in the question and store it in the structure hash_stat
	 */

	return hash_stat;
}

struct stat hash_cpp(char **input,int tablesize)
{
	struct stat hash_stat;
	int hasht[tablesize];
	int i,j;
	for( i = 0; i < tablesize;i++) {
		hasht[i] = 0;
	}
	//int size = 0;
	int cmp[1632];
	for( i = 0; i < 1632 ;i++ ) {
		int h = 0;
		for(j = 0; j < 5;j++) {
			h = ( 4*h + (int)(input[i][j]) -32 );
			//printf("%d\n",h);
		}
		int r = createmask(0,31);
		h = h&r;
		h = h%tablesize;
		if ( hasht[h] == 0 ) {
			cmp[i] = 1;
			hasht[h]+=1;
		} else {
			cmp[i] = hasht[h];
			hasht[h]+=1;
		}
	}

	hash_stat.item = 1632;
	int maxx = -1;
	for( i = 0; i < 1632;i++ ) {
		if ( cmp[i] > maxx ) {
			maxx = cmp[i];
		}
	}
	hash_stat.lenLong = maxx;

	long long int sum = 0;
	float avg;
	for( i = 0; i < 1632;i++) {
		sum+=cmp[i];
	}
	avg = (float)(sum)/1632.0;
	hash_stat.avgComp = avg;

	float sum1 = 0.0;
	for( i = 0; i < 1632;i++ ) {
		sum1+= (float)( (float)(cmp[i]) - avg )*( (float)(cmp[i]) - avg );
	}
	sum1 = sum1/1632.0;
	hash_stat.stdDev =  (float)sqrt(sum1);
	/* write the program to perform GNU-cpp on the given input and given hash table size.
	   collect statistics as specified in the question and store it in the structure hash_stat
	 */

	return hash_stat;
}

struct stat hash_cc1(char **input,int tablesize)
{
	struct stat hash_stat;
	int hasht[tablesize];
	int i,j;
	for( i = 0; i < tablesize;i++) {
		hasht[i] = 0;
	}
	//int size = 0;
	int cmp[1632];
	for( i = 0; i < 1632 ;i++ ) {
		int h = 0;
		for(j = 0; j < 5;j++) {
			h = ( 613*h + (int)(input[i][j]) -32 );
			//printf("%d\n",h);
		}
		int r = createmask(0,30);
		h = h&r;
		h = h%tablesize;
		if ( hasht[h] == 0 ) {
			cmp[i] = 1;
			hasht[h]+=1;
		} else {
			cmp[i] = hasht[h];
			hasht[h]+=1;
		}
	}

	hash_stat.item = 1632;
	int maxx = -1;
	for( i = 0; i < 1632;i++ ) {
		if ( cmp[i] > maxx ) {
			maxx = cmp[i];
		}
	}
	hash_stat.lenLong = maxx;

	long long int sum = 0;
	float avg;
	for( i = 0; i < 1632;i++) {
		sum+=cmp[i];
	}
	avg = (float)(sum)/1632.0;
	hash_stat.avgComp = avg;

	float sum1 = 0.0;
	for( i = 0; i < 1632;i++ ) {
		sum1+= (float)( (float)(cmp[i]) - avg )*( (float)(cmp[i]) - avg );
	}
	sum1 = sum1/1632.0;
	hash_stat.stdDev =  (float)sqrt(sum1);
	/* write the program to perform GNU-cc1 on the given input and given hash table size.
	   collect statistics as specified in the question and store it in the structure hash_stat
	 */

	return hash_stat;
}

int createmask(int a,int b)
{
	int r = 0;
	int i;
	for( i = a; i <=b;i++) {
		r |= 1 << i;
	}
	return r;
}

