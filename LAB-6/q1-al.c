# include <stdio.h>
# include <stdlib.h>

void disjkstra( int n,int **adj,int *,int *,int *,int,int);
int globalC = 0;
int globalPath[100][100];
int globalLength[100];
int main()
{
  int **adj, *parent1,*parent2,*parent3;
  int n,k,i,j,s,t;
  scanf("%d",&n);
  adj = (int **)calloc(n,sizeof(int *));
  for(i=0;i<n;i++)
    {
      adj[i] = (int *)calloc(n,sizeof(int));
    }
  parent1 = (int *)calloc(n,sizeof(int));
  parent2 = (int *)calloc(n,sizeof(int));
  parent3 = (int *)calloc(n,sizeof(int));
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      adj[i][j] = 0;
    }
  }
  scanf("%d %d %d",&i,&j,&k);
  while(i!=-1)
    {
      adj[i][j]=k;
      scanf("%d %d %d",&i,&j,&k);
    }
   
  scanf("%d %d",&s,&t);
   disjkstra(n,adj,  parent1,parent2,parent3,s,t);
  // temp=t;
  // printf("\n path1: %d",t);
  // while(temp!=s)
  //   {
  //     printf("->%d",parent1[temp]);
  //     temp=parent1[temp];
  //   }
  // temp=t;
  // printf("\n path2: %d",t);
  // while(temp!=s)
  //   {
  //     printf("->%d",parent2[temp]);
  //     temp=parent2[temp];
  //   }
  // temp=t;
  // printf("\n path3: %d",t);
  // while(temp!=s)
  //   {
  //     printf("->%d",parent3[temp]);
  //     temp=parent3[temp];
  //   }
  return 0;
}

void disjkstra(int n,int **adj,  int *p1,int *ps,int *p3,int s,int t)
{
  int visited[n];
  int path[n];
  int pathweight[n];
  int path_index = 0, i=0;
  for(i=0; i<n; i++)
  {
    visited[i] = 0;
  }
  recurse( n,adj, s,t,visited,path, path_index, pathweight);


  return;
}

void recurse(int n,int **adj,  int s, int t, int visited[], int path[], int path_index, int pathweight[])
{
  // printf("%d recurse %d\n", s,t);
  visited[s] = 1;
  path[path_index] = s;
  if(path_index==0)
    pathweight[path_index] = 0;

  path_index++;
  int i, temp=0;
  if(s==t)
  {
    printf("Path : \n");
    for(i=0;i<path_index;i++)
    {
      printf("%d ", path[i]);
      temp+=pathweight[i];
      globalPath[globalC][i] = path[i];
    }
    printf("\n");
    printf("\nweight: %d\n", temp);
    globalC++;
    if(globalC==3)
        return;

  }
  else
  {
    for(i=0;i<n;i++)
    {
      if(adj[s][i]!=0 && visited[i]!=1)
      {
        pathweight[path_index] = adj[s][i];
        recurse( n,adj, i, t, visited, path, path_index,pathweight);
      }
      
    }
  }
  path_index--;
  visited[s] = 0;

}