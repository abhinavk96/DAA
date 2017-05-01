#include <stdio.h>


int issafe(int v, int graph[][v], int color[], int x, int i)
{
	int j;
	for(j = 0; j < v; j++) {
		if(graph[x][j] == 1 && color[j] == i)
			return 0;
	}
	return 1;
}

int utility(int v, int graph[][v], int color[], int x, int m) 
{
	if(x == v)
		return 1;
	int i;
	for(i = 1; i <= m; i++) {
		if(issafe(v, graph, color, x, i)) {
			
			color[x] = i;
			
			if(utility(v, graph, color, x + 1, m))
				return 1;

			color[x] = 0;
		}
	}
	return 0;
}

void graphColoring(int n, int graph[][n], int m)
{
	int color[n];
	int j;
	for(j = 0; j < n; j++)
		color[j] = 0;
	if(utility(n, graph, color, 0, m) == 0) {
		printf("No solution possible\n");
	}
	else {
		int i;
		for(i = 0; i < n; i++) 
			printf("%d ",color[i]);
		printf("\n");
	}
}

int main()
{
    int n;
    scanf("%d", &n);
    int graph[n][n];
   	int u = 0, v = 0;
   	while(u != -1 || v != -1) {
   		scanf("%d%d",&u,&v);
   		graph[u][v] = 1;
   		graph[v][u] = 1;
   	}
    int m;
    scanf("%d",&m);
    graphColoring (n, graph, m);
    return 0;
}