# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <time.h>
struct stat{
  int item;
  int lenLong;
  float avgComp;
  float stdDev;
};

struct node{
	char str[50];
	struct node *next;
};

int ETH(char *, int);
int cpp(char *, int);
long long int cc1(char *, int);	
void insert( struct node **, char *);
int find(struct node *, char *);
int find_max(struct node *);

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
	struct node *hashtable[tablesize];
	int i;
	int tmp;
	int n = 1632;
	int cmps[n];
	
	for (i = 0; i < tablesize; i++)
		hashtable[i] = NULL;

	for ( i = 0; i < n; i++) {
		tmp = ETH(input[i], 5) % tablesize;
		insert(&hashtable[tmp], input[i]);
	}
	hash_stat.item = 1632;
	hash_stat.lenLong = 0;
	for ( i = 0; i < tablesize; i++){
		tmp = find_max(hashtable[i]);
		if ( tmp > hash_stat.lenLong) hash_stat.lenLong = tmp;
	}
	for ( i = 0 ; i < n; i++){
		tmp = ETH(input[i], 5) % tablesize;
		cmps[i] = find(hashtable[tmp], input[i]);
	}
	int sum = 0;
	for ( i = 0; i < n; i++){
		sum += cmps[i];
	}
	hash_stat.avgComp = sum/1632.0 ;
	float dev = 0.0;
	for ( i = 0; i < n; i++){
		dev += ( (hash_stat.avgComp - cmps[i])*(hash_stat.avgComp - cmps[i]) );
	}
	dev /= 1632.0;
	hash_stat.stdDev = (float)sqrt(dev);

  return hash_stat;
}

 struct stat hash_cpp(char **input,int tablesize)
{
  struct stat hash_stat;

  /* write the program to perform GNU-cpp on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
	struct node *hashtable[tablesize];
	int i;
	int tmp;
	int n = 1632;
	int cmps[n];
	
	for (i = 0; i < tablesize; i++)
		hashtable[i] = NULL;

	for ( i = 0; i < n; i++) {
		tmp = ((cpp(input[i], 5)<<1)/2) % tablesize;
		insert(&hashtable[tmp], input[i]);
	}
	hash_stat.item = 1632;
	hash_stat.lenLong = 0;
	for ( i = 0; i < tablesize; i++){
		tmp = find_max(hashtable[i]);
		if ( tmp > hash_stat.lenLong) hash_stat.lenLong = tmp;
	}
	for ( i = 0 ; i < n; i++){
		tmp = ((cpp(input[i], 5)<<1)/2) % tablesize;
		cmps[i] = find(hashtable[tmp], input[i]);
	}
	int sum = 0;
	for ( i = 0; i < n; i++){
		sum += cmps[i];
	}
	hash_stat.avgComp = sum/1632.0 ;
	float dev = 0.0;
	for ( i = 0; i < n; i++){
		dev += ( (hash_stat.avgComp - cmps[i])*(hash_stat.avgComp - cmps[i]) );
	}
	dev /= 1632.0;
	hash_stat.stdDev = (float)sqrt(dev);


  
  return hash_stat;
}

struct stat hash_cc1(char **input,int tablesize)
{
  struct stat hash_stat;

  /* write the program to perform GNU-cc1 on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
	struct node *hashtable[tablesize];
	int i;
	long long int tmp;
	int n = 1632;
	int cmps[n];
	
	for (i = 0; i < tablesize; i++)
		hashtable[i] = NULL;

	for ( i = 0; i < n; i++) {
		tmp = ( (cc1(input[i], 5)<<2)/4 )%tablesize;
		insert(&hashtable[tmp], input[i]);
	}
	hash_stat.item = 1632;
	hash_stat.lenLong = 0;
	for ( i = 0; i < tablesize; i++){
		tmp = find_max(hashtable[i]);
		if ( tmp > hash_stat.lenLong) hash_stat.lenLong = tmp;
	}
	for ( i = 0 ; i < n; i++){
		tmp = ( (cc1(input[i], 5)<<2)/4 )%tablesize;
		cmps[i] = find(hashtable[tmp], input[i]);
	}
	int sum = 0;
	for ( i = 0; i < n; i++){
		sum += cmps[i];
	}
	hash_stat.avgComp = sum/1632.0 ;
	float dev = 0.0;
	for ( i = 0; i < n; i++){
		dev += ( (hash_stat.avgComp - cmps[i])*(hash_stat.avgComp - cmps[i]) );
	}
	dev /= 1632.0;
	hash_stat.stdDev = (float)sqrt(dev);


  
  return hash_stat;
}



int ETH(char *word, int k)
{
	if ( k == 0)
		return 1;

	return ( word[k-1]*((ETH(word,k-1)%257)+1) );
}
int cpp(char *word, int k)
{
	if ( k == 0)
		return 0;

	return ( 4*cpp(word,k-1) +word[k-1] );
}
long long int cc1(char *word, int k)
{
	if ( k == 0)
		return 5;

	return ( (613)*cc1(word,k-1) +word[k-1] );
}

void insert( struct node **head, char *word)
{
	struct node *tmp = malloc(sizeof(struct node));
	strcpy(tmp->str,word);
	tmp->next = NULL;
	if (*head == NULL){
		*head = tmp;
		return;
	}
	tmp->next = *head ;
	*head = tmp;

}
int find(struct node *head, char *word)
{
	int cmp = 0;
	struct node *i = head;
	while ( i->next != NULL) {
		cmp++;
		if ( strcmp(i->str, word)==0) break;
		i = i->next;
	}
	return cmp;
}
int find_max(struct node *head){
	int l = 0;
	struct node *i = head;
	while (i != NULL){
		l++;
		i = i->next;
	}
	return l;
}



