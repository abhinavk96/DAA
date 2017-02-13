#
include < stdio.h > #include < stdlib.h > #include < string.h > #include < time.h > #include < math.h >

  struct stat {
    int item;
    int lenLong;
    float avgComp;
    float stdDev;
  };

struct node {
  char data[6];
  struct node * next;
};

struct stat hash_ETH(char * * , int);
struct stat hash_cpp(char * * , int);
struct stat hash_cc1(char * * , int);

int main() {
  char * * input;
  struct stat hash_stat;
  int n, k, i, j;
  srand(time(NULL));
  n = 1632;
  k = 5;
  input = (char * * ) malloc(n * sizeof(char * ));
  for (i = 0; i < n; i++) {
    input[i] = (char * ) malloc((k + 1) * sizeof(char));
    for (j = 0; j < k; j++)
      input[i][j] = (rand() % 95) + 32;
    input[i][k] = '\0';
  }
  printf("ETH\n");
  for (i = 1040; i <= 1050; i++) {
    hash_stat = hash_ETH(input, i);
    printf("%d,%f,%f\n", i, hash_stat.avgComp, hash_stat.stdDev);
  }
  printf("GNU-cc1\n");
  for (i = 1040; i <= 1050; i++) {
    hash_stat = hash_cc1(input, i);
    printf("%d,%f,%f\n", i, hash_stat.avgComp, hash_stat.stdDev);
  }
  printf("GNU-cpp\n");
  for (i = 1040; i <= 1050; i++) {
    hash_stat = hash_cpp(input, i);
    printf("%d,%f,%f\n", i, hash_stat.avgComp, hash_stat.stdDev);
  }

  return 0;
}

struct stat hash_ETH(char * * input, int tablesize) {
  struct stat hash_stat;

  /* write the program to perform ETH on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
  int length[tablesize] = {
    0
  }, maxLength = 0, validCounter = 0;
  float sumLength = 0.0, sd = 0.0;
  int h[5], i, j, H, M;
  h[0] = 1;
  struct node * hash[tablesize], * key;

  for (i = 0; i < tablesize; i++) {
    hash[i] = NULL;
  }

  for (i = 0; i < 1632; i++) {
    for (j = 1; j < 5; j++) {
      h[j] = input[i][j] * ((h[j - 1] % 257) + 1);
    }
    key = (struct node * ) malloc(sizeof(struct node));
    H = h[4] % tablesize;
    //printf("%s\t\t\t%d\n",input[i],H);	
    strcpy(key - > data, input[i]);
    if (hash[H] != NULL) {

      key - > next = hash[H];
      hash[H] = key;
      length[H]++;
      //printf("Insert into hash[%d] the string %s proof:hash[%d]->data = %s\n", H ,input[i],H,hash[H]->data);
    } else {
      hash[H] = key;
      hash[H] - > next = NULL;
      length[H]++;
      validCounter++;
      // printf("Insert replace into hash[%d] the string %s proof:hash[%d]->data = %s\n", H ,input[i],H,hash[H]->data);
    }

  }
  /*for(i=0;i<tablesize;i++)
  {
  	if(hash[i]!=NULL)
  	{
  	while(hash[i]!=NULL){
  	printf("%s %d\t", hash[i]->data, i);
  	hash[i]=hash[i]->next;
  	}
  	printf("\n");
  	}
  	
  }*/
  for (i = 0; i < tablesize; i++) {
    sumLength = sumLength + length[i];
    if (length[i] > maxLength)
      maxLength = length[i];
  }
  int mean = sumLength / validCounter;
  for (i = 0; i < tablesize; i++) {
    sd = sd + (mean - length[i]) * (mean - length[i]);
  }
  sd = sd / validCounter;
  sd = sqrt(sd);
  hash_stat.item = sumLength;
  hash_stat.lenLong = maxLength;
  hash_stat.avgComp = sumLength / validCounter;
  hash_stat.stdDev = sd;

  return hash_stat;
}

struct stat hash_cpp(char * * input, int tablesize) {
  struct stat hash_stat;

  /* write the program to perform ETH on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
  int length[tablesize] = {
    0
  }, maxLength = 0, validCounter = 0;
  int h[5], i, j, H, M;
  float sd = 0.0, sumLength = 0.0;
  h[0] = 0;
  struct node * hash[tablesize], * key;

  for (i = 0; i < tablesize; i++) {
    hash[i] = NULL;
  }

  for (i = 0; i < 1632; i++) {
    for (j = 1; j < 5; j++) {
      h[j] = 4 * h[j - 1] + input[i][j];
    }
    key = (struct node * ) malloc(sizeof(struct node));
    h[4] = h[4] % (long long) pow(2, 32);
    H = h[4] % tablesize;
    //printf("%s\t\t\t%d\n",input[i],H);	
    strcpy(key - > data, input[i]);
    if (hash[H] != NULL) {

      key - > next = hash[H];
      hash[H] = key;
      length[H]++;
      //printf("Insert into hash[%d] the string %s proof:hash[%d]->data = %s\n", H ,input[i],H,hash[H]->data);
    } else {
      hash[H] = key;
      hash[H] - > next = NULL;
      length[H]++;
      validCounter++;
      // printf("Insert replace into hash[%d] the string %s proof:hash[%d]->data = %s\n", H ,input[i],H,hash[H]->data);
    }

  }
  /*for(i=0;i<tablesize;i++)
  {
  	if(hash[i]!=NULL)
  	{
  	while(hash[i]!=NULL){
  	printf("%s %d\t", hash[i]->data, i);
  	hash[i]=hash[i]->next;
  	}
  	printf("\n");
  	}
  	
  }*/
  for (i = 0; i < tablesize; i++) {
    sumLength = sumLength + length[i];
    if (length[i] > maxLength)
      maxLength = length[i];
  }
  int mean = sumLength / validCounter;
  for (i = 0; i < tablesize; i++) {
    sd = sd + (mean - length[i]) * (mean - length[i]);
  }
  sd = sd / validCounter;
  sd = sqrt(sd);
  hash_stat.item = sumLength;
  hash_stat.lenLong = maxLength;
  hash_stat.avgComp = sumLength / validCounter;
  hash_stat.stdDev = sd;

  return hash_stat;
}

struct stat hash_cc1(char * * input, int tablesize) {
  struct stat hash_stat;

  /* write the program to perform ETH on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
  int length[tablesize] = {
    0
  }, maxLength = 0, validCounter = 0;
  int h[5], i, j, H, M;
  float sd = 0.0, sumLength = 0.0;
  h[0] = 1;
  struct node * hash[tablesize], * key;

  for (i = 0; i < tablesize; i++) {
    hash[i] = NULL;
  }

  for (i = 0; i < 1632; i++) {
    for (j = 1; j < 5; j++) {
      h[j] = 613 * h[j - 1] + input[i][j];
    }
    key = (struct node * ) malloc(sizeof(struct node));
    h[4] = h[4] % (long long) pow(2, 31);
    H = h[4] % tablesize;
    //printf("%s\t\t\t%d\n",input[i],H);	
    strcpy(key - > data, input[i]);
    if (hash[H] != NULL) {

      key - > next = hash[H];
      hash[H] = key;
      length[H]++;
      //printf("Insert into hash[%d] the string %s proof:hash[%d]->data = %s\n", H ,input[i],H,hash[H]->data);
    } else {
      hash[H] = key;
      hash[H] - > next = NULL;
      length[H]++;
      validCounter++;
      // printf("Insert replace into hash[%d] the string %s proof:hash[%d]->data = %s\n", H ,input[i],H,hash[H]->data);
    }

  }
  /*for(i=0;i<tablesize;i++)
  {
  	if(hash[i]!=NULL)
  	{
  	while(hash[i]!=NULL){
  	printf("%s %d\t", hash[i]->data, i);
  	hash[i]=hash[i]->next;
  	}
  	printf("\n");
  	}
  	
  }*/
  for (i = 0; i < tablesize; i++) {
    sumLength = sumLength + length[i];
    if (length[i] > maxLength)
      maxLength = length[i];
  }
  int mean = sumLength / validCounter;
  for (i = 0; i < tablesize; i++) {
    sd = sd + (mean - length[i]) * (mean - length[i]);
  }
  sd = sd / validCounter;
  sd = sqrt(sd);
  hash_stat.item = sumLength;
  hash_stat.lenLong = maxLength;
  hash_stat.avgComp = sumLength / validCounter;
  hash_stat.stdDev = sd;
  return hash_stat;
}
