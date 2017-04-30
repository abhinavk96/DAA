#include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <time.h>
#define n 1632
struct node {
	char a[100];
	struct node *link;
};
struct stat{
	int item;
	int lenLong;
	float avgComp;
	float stdDev;
};

struct stat hash_ETH(char **,int);
//void hash_cpp(char **);
//void hash_cc1(char **);

int main()
{
	char **input;
	struct stat hash_stat;
	int k,i,j;
	srand(time(NULL));
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
	/*	printf("GNU-cc1\n");
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
		}*/

	return 0;
}

struct stat hash_ETH(char **input,int tablesize)
{
	struct stat hash_stat;
	int i,j,g;
	struct node *ar[1051];
	int counter=0,length[1051]={0},total=0;
	for(i=0;i<tablesize;i++)
		ar[i]=NULL;
	for(i=0;i<tablesize;i++)
	{
		g=1;
		for(j=1;j<5;j++)
		{
			g=input[i][j]*((g%257)+1);
		}
		g=g%tablesize;
		struct node *tmp;
		tmp=(struct node *)malloc(sizeof(struct node));
		for(j=0;j<5;j++)
		{
			tmp->a[j] = input[i][j];
		}
		tmp->a[j]='\0';
		if(ar[g]==NULL)
		{
			ar[g]=tmp;
			ar[g]->link=NULL;
		}
		else
		{
			struct node *p;
			p=ar[g];
			while(p->link!=NULL)
				p=p->link;
			p->link=tmp;
			tmp->link=NULL;
		}
	}
	for(i=0;i<tablesize;i++)
	{
		if(ar[i]!=NULL)
		{
			counter=counter+1;
			if(ar[i]->link==NULL)
			{	
				length[i]=length[i]+1;
			}
			else
			{
				struct node *p;
					p = ar[i];
				while(p!=NULL)
				{
					length[i] = length[i] + 1;
					p=p->link;
				}

			}
		}
		total=total+length[i];
	}
	float mean;
	mean=total/counter;
	printf("%f",mean);
	float sd=0.0;
	for(i=0;i<tablesize;i++)
	{
		sd=sd+(mean-length[i])*(mean-length[i]);
	}
	sd=sd/counter;
	hash_stat.avgComp=mean;
	hash_stat.stdDev=sd;
	return hash_stat;
}




/*struct stat hash_cpp(char **input,int tablesize)
{
	struct stat hash_stat;

	return hash_stat;
}
struct stat hash_cc1(char **input,int tablesize)
{
	struct stat hash_stat;

	return hash_stat
}*/

