# include <stdio.h>
# include <stdlib.h>
#include <limits.h>

void dijkstra(int ** adj ,int n, int *p1,int *ps,int *p3,int s,int t);

int main()
{
  int **adj, *parent1,*parent2,*parent3;
  int n,k,i,j,t,s;
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
  disjkstra(adj,n, parent1,parent2,parent3,s,t);
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
int minDistance(int distance[], int included[], int n)
{
    // Initialize min value
    int min = INT_MAX, min_index,v;
 
    for (int v = 0; v < n; v++)
        if (included[v] == 0 && distance[v] <= min)
            min = distance[v], min_index = v;
 
    return min_index;
}
void printPath(int parent[], int j)
{
    // Base Case : If j is source
    if (parent[j]==-1)
        return;
    printPath(parent, parent[j]);
 
    printf("%d ", j);
}
 
// A utility function to print the constructed distance
// array
int printSolution(int dist[], int n, int src,int t, int parent[])
{
    int i;
    printf("Vertex\t  Distance\tPath");
    // for (i = 1; i < n; i++)
    // {
        printf("\n%d -> %d \t\t %d\t\t%d ", src, t, dist[t], src);
        printPath(parent, t);
    // }
}
void disjkstra(int ** adj ,int n, int *p1,int *ps,int *p3,int s,int t)
{
	int included[n];
	int distance [n];
	int parent[n];
	int i;
	
	for(i=0;i<n;i++)
	{
		parent[i] = -1;
        distance[i] = INT_MAX;
        included[i] = 0;

	}
	distance[s] = 0;
	 for (int count = 0; count < n-1; count++)
    {
      
        int u = minDistance(distance, included, n);
 
        included[u] = 1;
 
      
        for (i = 0; i < n; i++)
 
     
            if (!included[i] && adj[u][i] &&
                distance[u] + adj[u][i] < distance[i])
            {
                parent[i]  = u;
                distance[i] = distance[u] + adj[u][i];
            }  
    }
     printSolution(distance, n, s,t, parent);

  return;
}