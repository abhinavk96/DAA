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

printmst(int par[], int n) {
    int i;
    for(i = 1; i < n; i++) {
        printf("%d  %d\n",par[i], i);
    }
}

int prim(int n, int adj[][n], int key[], int par[])
{
    int mst[n];
    int i;
    int j;
    for(i = 0; i < n; i++) {
        mst[i] = 0; 
        par[i] = -1;
        key[i] = INT_MAX;   
    }
    key[0] = 0;
    for( i = 0; i < n - 1; i++) {
        int u = min_dist(mst, key, n);
        //if(u == -1)
        //    return INT_MAX;
        mst[u] = 1;
        for(j = 0; j < n; j++) {
            if(adj[u][j] && mst[j] == 0 && adj[u][j] < key[j]) {
                key[j] = adj[u][j];
                par[j] = u;
            }
        }
    }
    for(i = 0; i < n; i++) {
    	if(key[i] == INT_MAX)
    		return INT_MAX;
    }
    int sum = 0;
    for(i = 1; i < n; i++) {
        sum += adj[i][par[i]];
    }
    //printf("%d\n",sum );
    //printmst(par, n);
    return sum;
}
void modify(int temp[], int par2[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        par2[i] = temp[i];
}

int mst2(int n, int adj[][n], int par2[])
{
    int par1[n];
    int key[n];
    int w1 = prim(n, adj, key, par1);
    int w2;
    int temp[n];
    int w;
    int minw = INT_MAX;
    int i;
    int flag = -1;
    for(i = 1; i < n; i++) {
        int x = par1[i];
        int y = i;
        w = adj[x][y];
        adj[x][y] = 0;
        adj[y][x] = 0;
        w2 = prim(n, adj, key, temp);
        if(w2 < minw && w2 > w1) {
        	flag = 0;
            modify(temp, par2, n);
            minw = w2;
        }
        adj[x][y] = w;
        adj[y][x] = w;
    }
    if(flag == -1)
    	printf("No 2nd mst\n");
    else
    	printmst(par2, n);
    return minw;
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
    int par2[n];  
    scanf("%d%d%d",&i,&j,&k);
    while(i!=-1) {
        adj[i][j] = k;
        adj[j][i] = k;
        scanf("%d%d%d",&i,&j,&k);
    }

    //int ans = prim(n, adj, dist, par);
    //printf("\nw1: %d\n",ans);
    int ans2 = mst2(n, adj, par2);
    //printf("\nw2: %d\n",ans2);
    return 0;
}
