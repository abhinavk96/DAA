# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include<math.h>
struct stat{
  int item;
  int lenLong;
  float avgComp;
  float stdDev;
};
struct node{
	char *w;
	struct node *link;
	int cmp;
};

struct stat hash_ETH(char **,int);
struct stat hash_cpp(char **,int);
struct stat hash_cc1(char **,int);
int rec1(char *w, int k){
	if(k==0)
		return 1;
	return (w[k-1]*((rec1(w,k-1)%257)+1));
}
int rec2(char *w,int k){
	if(k==0)
		return 0;
	return (4*rec2(w,k-1)+w[k-1]);
}
int rec3(char *w,int k){
	if(k==0)
		return 5;
	return (613*rec3(w,k-1)+w[k-1]);
}
struct node* add_at_end(struct node* start,char *a,int *max,float *sum1,float *sum2)
{
	struct node *p,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	p=start;
	temp->cmp=1;
	
	if(p==NULL){
		*sum1=*sum1+1;
		*sum2=*sum2+1;;
		temp->link=NULL;
		temp->w=a;
		if(temp->cmp>*max)
			*max=temp->cmp;
			
		return temp;
	}
	while(p->link!=NULL){
	p=p->link;
	//(temp->cmp)++;
	}
	temp->cmp=(p->cmp)+1;
	*sum1=*sum1+temp->cmp;
	*sum2=*sum2+((temp->cmp)*(temp->cmp));
	temp->link=NULL;
	p->link=temp;
	temp->w=a;
	if(temp->cmp>*max)
			*max=temp->cmp;
	return start;
}
	

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
	struct node  *a[tablesize];
	int i,max=0;
	float sum1=0,sum2=0;
	for(i=0;i<tablesize;i++)
		a[i]='\0';
	for(i=0;i<1632;i++){
		int h=rec1(input[i],5)%tablesize;
		 //printf("%d ",h);
		a[h]=add_at_end(a[h],input[i],&max,&sum1,&sum2);
			
	}
	hash_stat.lenLong=max;
	hash_stat.avgComp=sum1/1632;
	hash_stat.stdDev=sqrt(sum2/1632-(hash_stat.avgComp*hash_stat.avgComp));
	 //printf("%d,%f,%f,%f,%f\n",max,hash_stat.avgComp,hash_stat.stdDev,sum1,sum2);
	return hash_stat;
		
	

  /* write the program to perform ETH on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
  
  return hash_stat;
}

 struct stat hash_cpp(char **input,int tablesize)
{
  struct stat hash_stat;

	struct node  *a[tablesize];
	int i,max=0;
	float sum1=0,sum2=0;
	for(i=0;i<tablesize;i++)
		a[i]='\0';
	for(i=0;i<1632;i++){
		int h=rec2(input[i],5);
	         h=h & 0x7fffffff;
		h=h%tablesize;
		 //printf("%d ",h);
		a[h]=add_at_end(a[h],input[i],&max,&sum1,&sum2);
			
	}
	hash_stat.lenLong=max;
	hash_stat.avgComp=sum1/1632;
	hash_stat.stdDev=sqrt(sum2/1632-(hash_stat.avgComp*hash_stat.avgComp));
  /* write the program to perform GNU-cpp on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
  
  return hash_stat;
}

struct stat hash_cc1(char **input,int tablesize)
{
  struct stat hash_stat;
	struct node  *a[tablesize];
	int i,max=0;
	float sum1=0,sum2=0;
	for(i=0;i<tablesize;i++)
		a[i]='\0';
	for(i=0;i<1632;i++){
		int h=rec2(input[i],5);
		h=h & 0x3fffffff;
		h=h%tablesize;
		 //printf("%d ",h);
		a[h]=add_at_end(a[h],input[i],&max,&sum1,&sum2);
			
	}
	hash_stat.lenLong=max;
	hash_stat.avgComp=sum1/1632;
	hash_stat.stdDev=sqrt(sum2/1632-(hash_stat.avgComp*hash_stat.avgComp));
  /* write the program to perform GNU-cc1 on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
  
  return hash_stat;
}

