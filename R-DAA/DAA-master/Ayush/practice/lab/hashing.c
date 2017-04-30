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

struct node {
	char data[6];
	struct node* next;
};

struct node* getnode(char data[])
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp -> next = NULL;
	strcpy(temp -> data, data);
	return temp;
}

void insert(struct node* table[],char data[],int pos)
{
		struct node* temp;
		temp = getnode(data);
		if(table[pos] == NULL)
			table[pos] = temp;
		else {
			struct node* head = table[pos];
			while(head -> next != NULL)
				head = head -> next;
			head -> next = temp;
		}
}

int cmp(struct node* table[],char data[],int pos)
{
	struct node* head = table[pos];
	int count = 0;
	while(head != NULL) {
		if(!strcmp(head->data,data))
			return count + 1;
		head = head -> next;
		count++;
	}
	return 0;
}

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
void display(struct node* table[],int tablesize) {
	int i;
	struct node* head;
	for(i = 0; i < tablesize; i++) {
		head = table[i];
		while(head!=NULL) {
			printf("%s->",table[i]->data);
			head = head -> next;
		}
		printf("\n");
	}
}

struct stat hash_ETH(char **input,int tablesize)
{
	struct node* table[tablesize];
	int i;
	for(i = 0 ; i < tablesize; i++)
		table[i] = NULL;

  	struct stat hash_stat;
	int hash[tablesize];
	int value = 1;
	int j;
	for(i = 0; i < tablesize; i++)
		hash[i] = 0;

	int sum = 0;
	int avg = 0;
	for(i = 0; i < 1632; i++) {
		value = 1;
		for(j = 0; j < 5; j++) {
			value = ((value % 257) + 1) * input[i][j];
		}
		insert(table,input[i],value%tablesize);
		long long int ans = cmp(table,input[i],value%tablesize);
		//printf("%d\n",ans);
		avg = avg + ans;
		sum = sum + ans * ans;
		hash[value % tablesize]++;
	}
	//printf("%d %d\n",avg,sum);
	//display(table,tablesize);
	int mx = 0;
	int max = 0;
	for(i = 0; i < tablesize; i++) {
		//printf("yes\n");
		struct node* head = table[i];
		mx = 0;
		while(head!=NULL) {
			mx++;
			head = head -> next;
		}
		if(mx > max)
		max = mx;
	}
	hash_stat.item = 1632;
	hash_stat.lenLong = max;
	hash_stat.avgComp = (float)(avg) / 1632.0;
	hash_stat.stdDev = sqrt(((float)sum / 1632.0) - (hash_stat.avgComp * hash_stat.avgComp));
	return hash_stat;
}

struct stat hash_cpp(char **input,int tablesize)
{
	struct stat hash_stat;
	struct node* table[tablesize];
	int i;
	for(i = 0 ; i < tablesize; i++)
		table[i] = NULL;
	int hash[tablesize];
	long long int value = 0;
	int j;
	long long int p = 1;
	for(i = 1; i <= 32; i++)
		p = p * 2;
    p--;
	for(i = 0; i < tablesize; i++)
		hash[i] = 0;

	int sum = 0;
	int avg = 0;
	int loc;
	for(i = 0; i < 1632; i++) {
		value = 0;
		for(j = 0; j < 5; j++) {
			value = (4 * value) + input[i][j];
		}
		loc = (value & p) % tablesize;

		hash[loc]++;
		insert(table,input[i],value%tablesize);
		int ans = cmp(table,input[i],loc);
		//printf("%d\n",ans);
		avg = avg + ans;
		sum = sum + ans * ans;
	}
	int mx = 0;
	int max = 0;
	for(i = 0; i < tablesize; i++) {
		//printf("yes\n");
		struct node* head = table[i];
		mx = 0;
		while(head!=NULL) {
			mx++;
			head = head -> next;
		}
		if(mx > max)
		max = mx;
	}
	hash_stat.item = 1632;
	hash_stat.lenLong = max;
	hash_stat.avgComp = (float)(avg) / 1632.0;
	hash_stat.stdDev = sqrt(((float)sum / 1632.0) - (hash_stat.avgComp * hash_stat.avgComp));
	return hash_stat;
}

struct stat hash_cc1(char **input,int tablesize)
{
  	struct stat hash_stat;
	int hash[tablesize];
	struct node* table[tablesize];
	int i;
	for(i = 0 ; i < tablesize; i++)
		table[i] = NULL;
	long long int value = 0;
	int j;
	long long int p = 1;
	for(i = 1; i <= 31; i++)
		p = p * 2;
    p--;
    //printf("%lld\n",p);
	for(i = 0; i < tablesize; i++)
		hash[i] = 0;

	long long int sum = 0;
	long long int avg = 0;
	long long int loc;
	for(i = 0; i < 1632; i++) {
		value = 5;
		for(j = 0; j < 5; j++) {
			value = (631 * value) + input[i][j];
		}
		loc = (value & p)  % tablesize;
		//printf("%lld\n",loc);
		insert(table,input[i],loc);
		long long int ans = cmp(table,input[i],loc);
		//printf("%d\n",ans);
		avg = avg + ans;
		sum = sum + ans * ans;
		hash[loc]++;
	}
		int mx = 0;
        int max = 0;
        for(i = 0; i < tablesize; i++) {
		//printf("yes\n");
		struct node* head = table[i];
		mx = 0;
		while(head!=NULL) {
			mx++;
			head = head -> next;
		}
		if(mx > max)
		max = mx;
	}
	hash_stat.item = 1632;
	hash_stat.lenLong = mx;
	hash_stat.avgComp = (float)(avg) / 1632.0;
	hash_stat.stdDev = sqrt((sum / 1632.0) - (hash_stat.avgComp * hash_stat.avgComp));
	return hash_stat;
}
