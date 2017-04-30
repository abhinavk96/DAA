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
struct node
{
  char s[105];
  struct node *next;
};
int hash_eth(char s[105],int ts)
{
  int i,l,ans=1;
  l=strlen(s);
  for(i=0;i<l;i++)
  {
    ans=s[i]*(ans%257+1);
  }
  ans=ans%ts;
  return ans;
}
int hash_cpp(char s[105],int tas)
{
  int i,l,ans=0;
  l=strlen(s);
  for(i=0;i<l;i++)
  {
    ans=4*ans+s[i];
  }
  ans=ans>>1;
  ans=ans%tas;
  return ans;
}
int hash_cc1(char s[105],int tas)
{
  long long int i,l,ans=5;
  l=strlen(s);
  for(i=0;i<l;i++)
  {
    ans=613*ans+s[i];
  }
  printf("%lld\n",ans);
  ans=ans>>1;
  ans=ans>>1;
  ans=(ans+tas)%tas;
  printf("%lld\n",ans);
  return ans;
}
struct node *insert(char s[105])
{
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  strcpy(temp->s,s);
  return temp;
}
struct stat hash_ETH(char **input,int tablesize);
struct stat hash_CPP(char **input,int tablesize);
struct stat hash_CC1(char **input,int tablesize);
int main()
{
  char **input;
  struct stat hash_stat;
  int n,k,i,j;
  srand(time(NULL));
  n=100;
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
      printf("%d,%d,%f,%f\n",i,hash_stat.lenLong,hash_stat.avgComp,hash_stat.stdDev);
    }
  printf("GNU-CC1\n");
  for(i=1040;i<=1050;i++)
    {
      hash_stat = hash_CC1(input,i);
      printf("%d,%d,%f,%f\n",i,hash_stat.lenLong,hash_stat.avgComp,hash_stat.stdDev);
    }
  printf("GNU-CPP\n");
  for(i=1040;i<=1050;i++)
    {
      hash_stat = hash_CPP(input,i);
      printf("%d,%d,%f,%f\n",i,hash_stat.lenLong,hash_stat.avgComp,hash_stat.stdDev);
    }
  printf("%d\n",sizeof(int));
  return 0;
}

struct stat hash_ETH(char **input,int tablesize)
{
  struct stat hash_stat;
  struct node *tmp;
  struct node *arr[tablesize+10];
  int x,i,n,k;
  n=100;
  k=5;
  int avg[n+10];
  for(i=0;i<tablesize;i++)
  {
    arr[i]=NULL;
  }
  for(i=0;i<n;i++)
  {
    x=hash_eth(input[i],tablesize);
    tmp=insert(input[i]);
    tmp->next=arr[x];
    arr[x]=tmp;
  }
 /* for(i=0;i<tablesize;i++)
  {
    tmp=arr[i];
    printf("List %d: ",i+1);
    while(tmp!=NULL)
    {
      printf("%s ",tmp->s);
      tmp=tmp->next;
    }
    printf("\n");
  }*/
  int item=0,lenLong=0;
  float avgComp,stdDev;
  float sum=0.0;
  for(i=0;i<tablesize;i++)
  {
    tmp=arr[i];
    x=0;
    //printf("List %d: ",i+1);
    while(tmp!=NULL)
    {
      x++;
     // printf("%s ",tmp->s);
      item++;
      tmp=tmp->next;
    }
    if(lenLong<x)
    {
      lenLong=x;
    }
  //  printf("\n");
  }
  int sz=0;
  for(i=0;i<tablesize;i++)
  {
    tmp=arr[i];
    x=0;
    while(tmp!=NULL)
    {
      avg[sz++]=x;
      x++;
      tmp=tmp->next;
    }
  }
  for(i=0;i<sz;i++)
  {
    //printf("%d ",avg[i]);
    sum+=avg[i];
  }
  avgComp=sum/item;
  for(i=0;i<sz;i++)
  {
    stdDev+=(avg[i]-avgComp)*(avg[i]-avgComp);
  }
  stdDev/=item;
  hash_stat.stdDev=sqrt(stdDev);
  hash_stat.avgComp=avgComp;
  hash_stat.item=item;
  hash_stat.lenLong=lenLong;
  return hash_stat;
}

 struct stat hash_CPP(char **input,int tablesize)
{
  struct stat hash_stat;
  struct node *tmp;
  struct node *arr[tablesize+10];
  int x,i,n,k;
  n=100;
  k=5;
  int avg[n+10];
  for(i=0;i<tablesize;i++)
  {
    arr[i]=NULL;
  }
  for(i=0;i<n;i++)
  {
    x=hash_cpp(input[i],tablesize);
    tmp=insert(input[i]);
    tmp->next=arr[x];
    arr[x]=tmp;
  }
 /* for(i=0;i<tablesize;i++)
  {
    tmp=arr[i];
    printf("List %d: ",i+1);
    while(tmp!=NULL)
    {
      printf("%s ",tmp->s);
      tmp=tmp->next;
    }
    printf("\n");
  }*/
  int item=0,lenLong=0;
  float avgComp,stdDev;
  float sum=0.0;
  for(i=0;i<tablesize;i++)
  {
    tmp=arr[i];
    x=0;
    //printf("List %d: ",i+1);
    while(tmp!=NULL)
    {
      x++;
     // printf("%s ",tmp->s);
      item++;
      tmp=tmp->next;
    }
    if(lenLong<x)
    {
      lenLong=x;
    }
  //  printf("\n");
  }
  int sz=0;
  for(i=0;i<tablesize;i++)
  {
    tmp=arr[i];
    x=0;
    while(tmp!=NULL)
    {
      avg[sz++]=x;
      x++;
      tmp=tmp->next;
    }
  }
  for(i=0;i<sz;i++)
  {
    //printf("%d ",avg[i]);
    sum+=avg[i];
  }
  avgComp=sum/item;
  for(i=0;i<sz;i++)
  {
    stdDev+=(avg[i]-avgComp)*(avg[i]-avgComp);
  }
  stdDev/=item;
  hash_stat.stdDev=sqrt(stdDev);
  hash_stat.avgComp=avgComp;
  hash_stat.item=item;
  hash_stat.lenLong=lenLong;
  return hash_stat;
}

struct stat hash_CC1(char **input,int tablesize)
{
  struct stat hash_stat;
  struct node *tmp;
  struct node *arr[tablesize+10];
  int x,i,n,k;
  n=100;
  k=5;
  int avg[n+10];
  for(i=0;i<tablesize;i++)
  {
    arr[i]=NULL;
  }
  for(i=0;i<n;i++)
  {
    x=hash_cc1(input[i],tablesize);
    tmp=insert(input[i]);
    tmp->next=arr[x];
    arr[x]=tmp;
  }
 /* for(i=0;i<tablesize;i++)
  {
    tmp=arr[i];
    printf("List %d: ",i+1);
    while(tmp!=NULL)
    {
      printf("%s ",tmp->s);
      tmp=tmp->next;
    }
    printf("\n");
  }*/
  int item=0,lenLong=0;
  float avgComp,stdDev;
  float sum=0.0;
  for(i=0;i<tablesize;i++)
  {
    tmp=arr[i];
    x=0;
    //printf("List %d: ",i+1);
    while(tmp!=NULL)
    {
      x++;
     // printf("%s ",tmp->s);
      item++;
      tmp=tmp->next;
    }
    if(lenLong<x)
    {
      lenLong=x;
    }
  //  printf("\n");
  }
  int sz=0;
  for(i=0;i<tablesize;i++)
  {
    tmp=arr[i];
    x=0;
    while(tmp!=NULL)
    {
      avg[sz++]=x;
      x++;
      tmp=tmp->next;
    }
  }
  for(i=0;i<sz;i++)
  {
    //printf("%d ",avg[i]);
    sum+=avg[i];
  }
  avgComp=sum/item;
  for(i=0;i<sz;i++)
  {
    stdDev+=(avg[i]-avgComp)*(avg[i]-avgComp);
  }
  stdDev/=item;
  hash_stat.stdDev=sqrt(stdDev);
  hash_stat.avgComp=avgComp;
  hash_stat.item=item;
  hash_stat.lenLong=lenLong;
  return hash_stat;
}
