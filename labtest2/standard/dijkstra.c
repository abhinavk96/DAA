#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

void dijkstra(int *,int *,int *,int, int, int**, int, int []);

int main()
{
    int **adj, *parent1,*parent2,*parent3;
    int n, k, i, j, t, s, temp;
    scanf("%d",&n);
    int d1[n];
    for(i = 0; i < n; i++)
        d1[i] = INT_MAX;

    adj = (int **)calloc(n,sizeof(int *));
    
    for(i=0;i<n;i++) {
        adj[i] = (int *)calloc(n,sizeof(int));
    }
    
    parent1 = (int *)calloc(n,sizeof(int));
    parent2 = (int *)calloc(n,sizeof(int));
    parent3 = (int *)calloc(n,sizeof(int));
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            adj[i][j] = 0;
    }
    scanf("%d%d%d",&i,&j,&k);
    while(i!=-1) {
        adj[i][j] = k;
        adj[j][i] = k;
        scanf("%d%d%d",&i,&j,&k);
    }
    scanf("%d%d",&s,&t);
    dijkstra(parent1, parent2, parent3, s, t, adj, n, d1);
    temp=t;
    printf("\npath1: %d",t);
    while(temp != s) {
        printf("->%d",parent1[temp]);
        temp=parent1[temp];
    }
    printf("\nDistance: %d\n",d1[t]);
    return 0;
}

int min_dist(int set[], int dist[], int n)
{
    int i;
    int min = INT_MAX; int index = -1;
    for(i = 0; i < n; i++) {
        if(set[i] == 0 && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int *p1,int *ps,int *p3,int s,int t, int** adj, int n, int d1[])
{
    int set[n];
    int i;
    d1[s] = 0;
    for(i = 0; i < n; i++) {
        p1[i] = -1;
        set[i] = 0;
    }
    int j;
    for(j = 0; j < n; j++) {
        int u = min_dist(set, d1, n);
        set[u] = 1;
        for(i = 0; i < n; i++) {
            if(adj[u][i] && set[i] == 0 && d1[i] > d1[u] + adj[u][i] && d1[u] != INT_MAX) {
                d1[i] = d1[u] + adj[u][i];
                p1[i] = u;
            }
        }
    }
    return;
}