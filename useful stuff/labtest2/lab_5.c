# include <stdio.h>
# include <stdlib.h>
# include <time.h>
int min_temp(int d1[], int status[], int n)
{
	int k = -1, i;
	int min = 9999;
	for(i = 0; i < n; i++)
	{
		if(status[i] == 0 && d1[i] < min)
		{
			min = d1[i];
			k = i;
		}
	}
	return k;
}
void shortest_1(int *parent1, int src, int dest, int n, int **adj, int *d1)
{
	int i, current;
	int status[100];
	for(i = 0; i < n; i++)
	{
		parent1[i] = -1;
		status[i] = 0;
		d1[i] = 9999;
	}
	d1[src] = 0;
	while(1)
	{
		current = min_temp(d1, status, n);
		if(current == -1)
		{
			//if(adj[1][3] == 0 && adj[5][6] == 0)
			return;

		}
		status[current] = 1;
		for(i = 0; i < n; i++)
		{
			if(adj[current][i] != 0 && status[i] == 0 && d1[i] > d1[current]+adj[current][i])
			{
				d1[i] = d1[current] + adj[current][i];
				parent1[i] = current;
			}
		}
	}

	
}
void shortest_2(int *parent1, int *parent2, int src, int dest, int n, int **adj, int *d2)
{
	int edge = 0, i, v1, v2;
	int temp = dest;
	while(temp != src)
	{
		edge = edge + 1;
		temp = parent1[temp];
	}
	temp = dest;
	int min = 9999;
	int parent[100], dist[100];
	for(i = 0; i < edge; i++)
	{
		v1 = adj[temp][parent1[temp]];
		v2 = adj[parent1[temp]][temp];
		adj[temp][parent1[temp]] = 0;
		adj[parent1[temp]][temp] = 0;
		shortest_1(parent, src, dest, n, adj, dist);
		if(dist[dest] < min)
		{
			min = dist[dest];
			
			for(i = 0; i < n; i++)
			{
				parent2[i] = parent[i];
				d2[i] = dist[i];
			}
		}
		adj[temp][parent1[temp]] = v1;
		adj[parent1[temp]][temp] = v2;		
		temp = parent1[temp];
	}
	
}
void shortest_3(int *parent1, int *parent2, int *parent3, int src, int dest, int n,int **adj, int *d3)
{
	int edge1 = 0, edge2 = 0;
	int temp = dest;
	while(temp != src)
	{
		edge1 = edge1 + 1;
		temp = parent1[temp];
	}
	temp = dest;
	while(temp != src)
	{
		edge2 = edge2 + 1;
		temp = parent2[temp];
	}
	int i, j, k, d[100], parent[100];
	temp = dest;
	for(i = 0; i < n; i++)
	{
		parent[i] = -1;
		d[i] = 9999;
	}
	int t1, t2, v1, v2, v3, v4, min;
	min = 9999;
	t1 = dest;
	t2 = dest;

	for(i = 0; i < edge1; i++)
	{
		v1 = adj[t1][parent1[t1]];
		v2 = adj[parent1[t1]][t1];
		adj[t1][parent1[t1]] = 0;
		adj[parent1[t1]][t1] = 0;
		t2 = dest;
		for(j = 0; j < edge2; j++)
		{
			v3 = adj[t2][parent2[t2]];
			v4 = adj[parent2[t2]][t2];
			adj[t2][parent2[t2]] = 0;
			adj[parent2[t2]][t2] = 0;
			//printf("%d %d \n",v3,v4 );
			shortest_1(parent, src, dest, n, adj, d);
			//printf("%d\n",d[dest]);
			/*if(v2 == 2 && v4 == 6)
			{
				printf("%d\n",d[dest]);
			}*/

			if(d[dest] < min)
			{
				min = d[dest];
				for(k = 0; k < n; k++)
				{
					d3[k] = d[k];
					parent3[k] = parent[k];
				}
			}
			adj[parent2[t2]][t2] = v4;
			adj[t2][parent2[t2]] = v3;
			t2 = parent2[t2];

		}
		adj[t1][parent1[t1]] = v1;
		adj[parent1[t1]][t1] = v2;
		t1 = parent1[t1];
	}
}
void dijkstra(int **adj, int n, int *parent1, int *parent2, int *parent3, int src,int dest)
{
	int d1[100], d2[100], d3[100];
	int i;
	for(i = 0; i < n; i++)
	{
		d1[i] = 9999;
		d2[i] = 9999;
		d3[i] = 9999;
	}
	
	shortest_1(parent1, src, dest, n, adj, d1);
	shortest_2(parent1, parent2, src, dest, n, adj, d2);
	shortest_3(parent1, parent2, parent3, src, dest, n, adj, d3);
}

int main()
{
	int **adj, *parent1,*parent2,*parent3;
	int n,k,i,j, s, t;
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
		adj[j][i] = k;
		scanf("%d%d%d",&i,&j,&k);
	}
	scanf("%d%d",&s,&t);
	dijkstra(adj, n, parent1,parent2,parent3,s,t);
	int temp=t;
	printf("\n path1: %d",t);
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
	}
	return 0;
}

