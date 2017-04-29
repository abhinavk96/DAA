#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

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

printmst(int visited[], int par[], int n) {
    int i;
    for(i = 1; i < n; i++) {
        printf("%d  %d\n",par[i], i);
    }
}

void prim(int n, int adj[][n], int key[], int par[])
{
    int visited[n];
    int i;
    int j;
    for(i = 0; i < n; i++) {
        visited[i] = 0;    
        key[i] = INT_MAX;
        par[i] = -1;
    }
    key[0] = 0;
    for(i = 0; i < n - 1; i++) {
        int u = min_dist(visited, key, n);
        visited[u] = 1;
        for(j = 0; j < n; j++) {
            if(adj[u][j] && visited[j] == 0 && adj[u][j] < key[j]) {
                key[j] = adj[u][j];
                par[j] = u;
            }
        }
    }
    printmst(visited, par, n);
    return;
}

int main()
{
    int n, k, i, j, t, s, temp;
    scanf("%d",&n);
    int adj[n][n];
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            adj[i][j] = 0;
    int dist[n];
    int par[n];
    scanf("%d%d%d",&i,&j,&k);
    while(i!=-1) {
        adj[i][j] = k;
        adj[j][i] = k;
        scanf("%d%d%d",&i,&j,&k);
    }
    prim(n, adj, dist, par);

    return 0;
}
