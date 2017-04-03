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

void print(int p1[], int s, int t) 
{
    if(t == s) {
        printf("%d ",t);
        return;
    }
    print(p1,s,p1[t]);
    printf("%d ", t);
}

void dijkstra(int *p1,int s,int t, int** adj, int n, int d1[])
{
    int set[n];
    int i;
    for(i = 0; i < n; i++)
        d1[i] = INT_MAX;
    d1[s] = 0;
    for(i = 0; i < n; i++) {
        p1[i] = -1;
        set[i] = 0;
    }
    int j;
    for(j = 0; j < n; j++) {
        int u = min_dist(set, d1, n);
        if(u == -1)
            continue;
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

void modify(int temp[], int parent[], int n) {
    int i;
    for(i = 0; i < n; i++)
        parent[i] = temp[i];
}

void second_shortest(int** adj, int parent1[], int parent2[], int s, int t, int n, int d2[])
{

    int t_path[n];
    int i;
    for(i = 0; i < n; i++) {
        t_path[i] = -1;
    }
    int edges = 0;
    int temp = t;
    while(s != temp) {
        edges++;
        temp = parent1[temp];
    }
    //printf("edges=%d\n",edges);
    int dtemp[n];
    for(i = 0; i < n; i++)
        d2[i] = INT_MAX;
    temp = t;
    int minsum = INT_MAX;
    for(i = 0; i < edges; i++) {
        int v1 = temp;
        int v2 = parent1[temp];
        int w = adj[v1][v2];
        adj[v1][v2] = 0;
        adj[v2][v1] = 0;

        dijkstra(t_path, s, t, adj, n, dtemp);
        if(dtemp[t] < minsum) {
            minsum = dtemp[t];
            modify(t_path, parent2, n);
            modify(dtemp, d2, n);
        }
        //printf("Cost:%d\n",dtemp[t]);
        //print(t_path, s, t);
        adj[v1][v2] = w;
        adj[v2][v1]= w;
        temp = parent1[temp];
    }
}

void third_shortest(int** adj, int parent1[], int parent2[], int parent3[], int s, int t, int n, int d3[])
{
    int t_path[n];
    int i;
    for(i = 0; i < n; i++) {
        t_path[i] = -1;
    }
    int edges1 = 0;
    int edges2 = 0;
    int temp = t;
    while(s != temp) {
        edges1++;
        temp = parent1[temp];
    }
    temp = t;
    while(s != temp) {
        edges2++;
        temp = parent2[temp];
    }
    int dtemp[n];
    for(i = 0; i < n; i++)
        d3[i] = INT_MAX;
    temp = t;
    int t1 = t;
    int t2 = t;
    int w1;
    int w2;
    int v1, v2, v3, v4;
    int minsum = INT_MAX;
    int j;
    for(i = 0; i < edges1; i++) {
        v1 = t1;
        v2 = parent1[t1];
        w1 = adj[v1][v2];
        adj[v1][v2] = 0;
        adj[v2][v1] = 0;
        t2 = t;
        for(j = 0; j < edges2; j++) {
            v3 = t2;
            v4 = parent2[t2];
            w2 = adj[v3][v4];
            adj[v3][v4] = 0;
            adj[v4][v3] = 0;
            dijkstra(t_path, s, t, adj, n, dtemp);
            if(dtemp[t] < minsum) {
                minsum = dtemp[t];
                modify(t_path, parent3, n);
                modify(dtemp, d3, n);
            }
            adj[v3][v4] = w2;
            adj[v4][v3]= w2;
            t2 = parent2[t2];
        }
        adj[v1][v2] = w1;
        adj[v2][v1]= w1;
        t1 = parent1[t1];
    }
}

int main()
{
    int **adj, *parent1,*parent2,*parent3;
    int n, k, i, j, t, s, temp;
    scanf("%d",&n);
    int d1[n];
    int d2[n];
    int d3[n];
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
    /*for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }*/
    printf("\n");
    dijkstra(parent1, s, t, adj, n, d1);
    temp=t;
    printf("\npath1:\n");
    if(d1[t] == INT_MAX) {
        printf("NO PATH\n");
    }
    else {
        print(parent1, s, t);
        printf("\n%d\n",d1[t]);

    }
    second_shortest(adj, parent1, parent2, s, t ,n, d2);
    
    printf("\npath2:\n");
    if(d2[t] == INT_MAX) {
        printf("NO PATH\n");
    }
    else {
        print(parent2, s, t);
        printf("\n%d\n",d2[t]);
    }
    third_shortest(adj, parent1, parent2, parent3, s, t, n, d3);
    printf("\npath3:\n");
    if(d3[t] == INT_MAX) {
        printf("NO PATH\n");
    }
    else {
        print(parent3, s, t);
        printf("\n%d\n",d3[t]);
    }
    return 0;
}