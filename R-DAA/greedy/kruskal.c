#include<stdio.h>
#include<stdlib.h>
struct node
{
	int u;
	int v;
	int weight;
};
struct subset 
{
	int parent ;
	int rank;
};
int find_parent(int a, struct subset sub[])
{
	if(sub[a].parent != a)
		sub[a].parent = find_parent(sub[a].parent, sub);
	return sub[a].parent;
}
void union_(int x, int y, struct subset sub[])
{
	int x_,y_;
	x_ = find_parent(x, sub);
	y_ = find_parent(y, sub);
	if(sub[x_].rank <= sub[y_].rank)
	{
		sub[x_].parent = y_;
		sub[y_].rank++;
	}
	else
	{
		sub[y_].parent = x_;
		sub[x_].rank++;
	}
}
void Kruskal(int adj[][100], int n)
{
	struct node graph[100];
	int k = 0, i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(adj[i][j] != 0)
			{
				graph[k].u = i;
				graph[k].v = j;
				graph[k].weight = adj[i][j];
				k = k + 1;
			}
		}
	}
	for(i = 0; i < k; i++)
	{
		for(j = 0; j < k-1; j++)
		{
			if(graph[j].weight > graph[j+1].weight)
			{
				struct node p;
				p = graph[j];
				graph[j] = graph[j+1];
				graph[j+1] = p;
			}
		}
	}
	struct subset sub[100];
	for(i = 0; i < n; i++)
	{
		sub[i].parent = i;
		sub[i].rank = 0;
	}
	int e = 0;
	i = 0;
	struct node result[100];
	while(e < n - 1)
	{
		int x, y;
		x = find_parent(graph[i].u, sub);
		y = find_parent(graph[i].v, sub);
		if(x != y)
		{
			result[e++] = graph[i];
			union_(x, y, sub);
		}
		i = i + 1;
	}
	for(i = 0; i < e; i++)
	{
		printf("%d--%d==%d\n",result[i].u,result[i].v,result[i].weight);
	}
	
}
int main()
{
	int adj[100][100], n, i, j;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			scanf("%d",&adj[i][j]);
	}
	Kruskal(adj, n);
}
