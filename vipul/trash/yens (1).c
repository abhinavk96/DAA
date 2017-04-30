# include <stdio.h>
# include <stdlib.h>

void dijkstra(int ** adj,int *,int *,int *,int,int,int);

int main()
{
  int **adj, *parent1,*parent2,*parent3;
  int n,k,i,j,w,t,s;
  scanf("%d",&n);
  adj = (int **)calloc(n,sizeof(int *));
  for(i=0;i<n;i++)
    {
      adj[i] = (int *)calloc(n,sizeof(int));
    }
  parent1 = (int *)calloc(n,sizeof(int));
  parent2 = (int *)calloc(n,sizeof(int));
  parent3 = (int *)calloc(n,sizeof(int));
  
  scanf("%d%d%d",&i,&j,&k);
  while(i!=-1)
    {
      adj[i][j]=k;
      scanf("%d%d%d",&i,&j,&k);
    }
  scanf("%d%d",&s,&t);
  dijkstra(adj,parent1,parent2,parent3,s,t,n);
  int temp=t;
 /* printf("\n path1: %d",t);
  while(temp!=s)
    {
      printf("->%d",parent1[temp]);
      temp=parent1[temp];
    }
temp=t;
  printf("\n path2: %d",t);
  while(temp!=s)
    {
      printf("->%d",parent2[temp]);
      temp=parent2[temp];
    }
  temp=t;
  printf("\n path3: %d",t);
  while(temp!=s)
    {
      printf("->%d",parent3[temp]);
      temp=parent3[temp];
    }*/
  return 0;
}
void dij(int **adj,int *d,int *par,int s,int t,int n)
{
  int color[n+1];
  int i,j,p,mn;
  for(i=0;i<n;i++)
  {
    color[i]=0;
  }
  d[s]=0;
  while(1)
  {
      mn=100000;
      p=-1;
      for(i=0;i<n;i++)
      {
         if(mn>d[i]&&color[i]==0)
         {
            p=i;
            mn=d[i];
         }
      }
      if(p==-1)
      {
        break;
      }
      //printf("%d   %d\n",p,d[p]);
      color[p]=1;
      for(i=0;i<n;i++)
      {
        //printf("%d %d %d \n",p,i,adj[p][i]);
        if(adj[p][i]!=0&&d[i]>d[p]+adj[p][i]&&color[i]==0)
        {
          d[i]=adj[p][i]+d[p];
          par[i]=p;
       //   printf("%d  \n",d[p]);
        }
      }
  }
}
void pp(int *p1,int *par,int s,int t,int *sz)
{
  if(s==t)
  {
    p1[*sz]=s;
    (*sz)++;
   // printf("%d ",s);
    return;
  }
  else if(par[t]==-1)
  {
  //  printf("No path ");
  }
  else
  {
    pp(p1,par,s,par[t],sz);
    p1[*sz]=t;
    (*sz)++;
    //printf("%d ",t);
  }
}
void dijkstra(int **adj,int *p1,int *p2,int *p3,int s,int t,int n)
{   
  int i,j,x,y,szz=0;
  int d[n+1],par[n+1],mn;
  for(i=0;i<n;i++)
  {
    d[i]=100005;
    par[i]=-1;
  }
  dij(adj,d,par,s,t,n);
 // printf("%d   %d\n",t,d[t]);
  int sz=0;
  pp(p1,par,s,t,&sz);
 // printf("\n");
  mn=100005;
  for(i=0;i<sz-1;i++)
  {
    x=adj[p1[i]][p1[i+1]];
    adj[p1[i]][p1[i+1]]=0;
  for(j=0;j<n;j++)
  {
    d[j]=100005;
    par[j]=-1;
  }
  dij(adj,d,par,s,t,n);
 // printf("%d   %d\n",t,d[t]);
  if(mn>d[t]&&d[t]!=100005)
  {
    mn=d[t];
    szz=0;
    pp(p2,par,s,t,&szz); 
  // printf("   %d\n",d[t]);
}
adj[p1[i]][p1[i+1]]=x;
}
  mn=100005;
  int k,szzz=0;
  for(i=0;i<sz-1;i++)
  {
    x=adj[p1[i]][p1[i+1]];
    adj[p1[i]][p1[i+1]]=0;
    for(k=0;k<szz-1;k++)
    {
      y=adj[p2[k]][p2[k+1]];
      adj[p2[k]][p2[k+1]]=0;
  for(j=0;j<n;j++)
  {
    d[j]=100005;
    par[j]=-1;
  }
  dij(adj,d,par,s,t,n);
 // printf("%d   %d\n",t,d[t]);
  if(mn>d[t]&&d[t]!=100005)
  {
    mn=d[t];
     szzz=0;
    pp(p3,par,s,t,&szzz); 
   //printf("   %d\n",d[t]);
}
adj[p2[k]][p2[k+1]]=y;
}
adj[p1[i]][p1[i+1]]=x;
}
if(sz!=0&&szz!=0&&szzz!=0)
{
	printf("Three shortest paths are : \n");
}
else if(sz!=0&&szz!=0)
{
 printf("Two shortest paths are : \n");
}
else if(sz!=0)
{
printf("Only shortest path is : \n");
}
else
{
 printf("No path b/w %d and %d \n",s,t);
}
if(sz!=0)
{
	for(i=0;i<sz;i++)
	{
  	printf("%d  ",p1[i]);
	}
printf("\n");
}
if(szz!=0)
{
	for(i=0;i<szz;i++)
	{
  printf("%d  ",p2[i]);
	}
	printf("\n");
}
if(szz!=0)
{
	for(i=0;i<szzz;i++)
	{
  	printf("%d  ",p3[i]);
	}
}
/*int tmp[n+1];
if(sz!=0)
{
	for(i=0;i<n;i++)
	{
		tmp[i]=-1;
	}
   for(i=sz-1;i>0;i--)
   {
      tmp[p1[i]]=p1[i-1];
   }
   for(i=0;i<n;i++)
   {
      p1[i]=tmp[i];
   }
}
else
{
	p1[t]=-1;
}
if(szz!=0)
{
	for(i=0;i<n;i++)
	{
		tmp[i]=-1;
	}
   for(i=szz-1;i>0;i--)
   {
      tmp[p2[i]]=p2[i-1];
   }
   for(i=0;i<n;i++)
   {
      p2[i]=tmp[i];
   }
}
else
{
	p2[t]=-1;
}
if(szzz!=0)
{
	for(i=0;i<n;i++)
	{
		tmp[i]=-1;
	}
   for(i=szzz-1;i>0;i--)
   {
      tmp[p3[i]]=p3[i-1];
   }
   for(i=0;i<n;i++)
   {
      p3[i]=tmp[i];
   }
}
else
{
	p3[t]=-1;
}*/
return;
}