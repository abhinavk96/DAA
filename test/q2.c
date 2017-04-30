// A C / C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

#include <stdio.h>
#include <limits.h>

// Number of vertices in the graph

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree

// driver program to test above function
int main()
{
/* Let us create the example graph discussed above */
int i, j,k,n;

int V=5;
scanf("%d",&n);
// int graph[V][V];
int ** graph;
graph = (int**) malloc(n*sizeof(int*));
for(i=0;i<n;i++)
{
    graph[i] =(int*) malloc(sizeof(int));
}
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        graph[i][j] = 0;
    }
}
int x =8;
while(x--)
{
    scanf("%d %d %d",&i,&j,&k);
    graph[i][j] = k;
    // graph[j][i] = k;
}
// for(i=0;i<n;i++)
// {
//     for(j=0;j<n;j++)
//     {
//         printf("%d %d %d\n",i,j,graph[i][j]);
//     }
// }
     // dijkstra(V, graph, 0);
    findcycle(n,graph,1);
    return 0;
}

