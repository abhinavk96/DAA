# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

struct stat{
  int item;
  int lenLong;
  float avgComp;
  float stdDev;
};

struct stat hash_ETH(char **,int);
struct stat hash_cpp(char **,int);
struct stat hash_cc1(char **,int);


int main()
{
  	char **input;
  	struct stat hash_stat;
  	int n,k,i,j;
  	srand(time(NULL));
  	n=1632;
  	k=5;
  	input = (char **)malloc(n*sizeof(char *));
  	for(i=0;i<n;i++) {
      	input[i]=(char *)malloc((k+1)*sizeof(char));
      	for(j=0;j<k;j++)
		input[i][j]=(rand()%95)+32;
      	input[i][k]='\0';
    }
  	printf("ETH\n");
  	for(i=1040;i<=1050;i++) {
    	hash_stat = hash_ETH(input,i);
      	printf("%d, %d, %f, %f\n",i,hash_stat.lenLong,hash_stat.avgComp,hash_stat.stdDev);
    }
  	printf("GNU-cc1\n");
  	for(i=1040;i<=1050;i++) {
      	hash_stat = hash_cc1(input,i);
      	printf("%d, %d, %f, %f\n",i,hash_stat.lenLong,hash_stat.avgComp,hash_stat.stdDev);
    }
  	printf("GNU-cpp\n");
  	for(i=1040;i<=1050;i++) {
      	hash_stat = hash_cpp(input,i);
      	printf("%d, %d, %f, %f\n",i,hash_stat.lenLong,hash_stat.avgComp,hash_stat.stdDev);
    }
	return 0;
}

struct stat hash_ETH(char **input,int tablesize)
{
  	struct stat hash_stat;
	int hash[tablesize];
	struct node* table[tablesize];
	int value = 1;
	int i,j;
	for(i = 0; i < tablesize; i++)
        table[i] = NULL;
	for(i = 0; i < tablesize; i++)
		hash[i] = 0;
    //display(table,tablesize);
	float sum = 0;
	int avg = 0;
	for(i = 0; i < 1632; i++) {
		value = 1;
		for(j = 0; j < 5; j++) {
			value = ((value % 257) + 1) * input[i][j];
		}
		//printf("yes\n");
		hash[value % tablesize]++;
	}

	for(i = 0; i < tablesize; i++) {
		avg = avg + (hash[i] * hash[i] + 1)/2;
		sum = sum + ((hash[i] * hash[i] + 1)/2) * ((hash[i] * hash[i] + 1)/2);
	}
	int mx = 0;
	for(i = 0; i < tablesize; i++) {
		if(hash[i] > mx)
			mx = hash[i];
	}
	hash_stat.item = 1632;
	hash_stat.lenLong = mx;
	hash_stat.avgComp = (float)(avg) / 1632.0;
	hash_stat.stdDev = sqrt((sum / 1632.0) - (hash_stat.avgComp * hash_stat.avgComp));
	return hash_stat;
}

struct stat hash_cpp(char **input,int tablesize)
{
	struct stat hash_stat;

	int hash[tablesize];
	long long int value = 0;
	int i,j;
	long long int p = 1;
	for(i = 1; i <= 31; i++)
		p = p * 2;
	for(i = 0; i < tablesize; i++)
		hash[i] = 0;

	float sum = 0;
	int avg = 0;
	int loc;
	for(i = 0; i < 1632; i++) {
		value = 0;
		for(j = 0; j < 5; j++) {
			value = (4 * value) + input[i][j];
		}
		loc = (value % p) % tablesize;
		hash[loc]++;
	}
	for(i = 0; i < tablesize; i++) {
		avg = avg + (hash[i] * hash[i] + 1)/2;
		sum = sum + ((hash[i] * hash[i] + 1)/2) * ((hash[i] * hash[i] + 1)/2);
	}
	int mx = 0;
	for(i = 0; i < tablesize; i++) {
		if(hash[i] > mx)
			mx = hash[i];
	}
	hash_stat.item = 1632;
	hash_stat.lenLong = mx;
	hash_stat.avgComp = (float)(avg) / 1632.0;
	hash_stat.stdDev = sqrt((sum / 1632.0) - (hash_stat.avgComp * hash_stat.avgComp));
	return hash_stat;
}

struct stat hash_cc1(char **input,int tablesize)
{
  	struct stat hash_stat;
	int hash[tablesize];
	long long int value = 0;
	int i,j;
	long long int p = 1;
	for(i = 1; i <= 31; i++)
		p = p * 2;
	for(i = 0; i < tablesize; i++)
		hash[i] = 0;

	float sum = 0;
	int avg = 0;
	int loc;
	for(i = 0; i < 1632; i++) {
		value = 0;
		for(j = 0; j < 5; j++) {
			value = (631 * value) + input[i][j];
		}
		loc = (value % p)  % tablesize;
		hash[loc]++;
	}
	for(i = 0; i < tablesize; i++) {
		avg = avg + (hash[i] * hash[i] + 1)/2;
		sum = sum + ((hash[i] * hash[i] + 1)/2) * ((hash[i] * hash[i] + 1)/2);
	}
	int mx = 0;
	for(i = 0; i < tablesize; i++) {
		if(hash[i] > mx)
			mx = hash[i];
	}
	hash_stat.item = 1632;
	hash_stat.lenLong = mx;
	hash_stat.avgComp = (float)(avg) / 1632.0;
	hash_stat.stdDev = sqrt((sum / 1632.0) - (hash_stat.avgComp * hash_stat.avgComp));
	return hash_stat;
}
