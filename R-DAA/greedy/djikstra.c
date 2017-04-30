#include<stdio.h>
#include<stdlib.h>
#define perm 1
#define temp 0
int min(int distance[], int status[], int n)
{
	int i;
	int mini = 9999;
	int k = -1;
	for(i = 0; i < n; i++)
	{
		if(status[i] == temp && distance[i] < mini)
		{
			mini = distance[i];
			k = i;
		}
	}
	return k;	
}
void dj(int adj[][100], int n)
{
	int distance[100], status[100];
	int i, j, current;
	for(i = 0; i < n; i++)
	{
		distance[i] = 9999;
		status[i] = temp;
	}
	distance[0] = 0;
	while(1)
	{
		current = min(distance, status, n);
		if(current == -1)
		{
			for(i = 0; i < n; i++)
				printf("%d  ",distance[i]);
			return;
		}

		status[current] = perm;
		for(i = 0; i < n; i++)
		{
			if(adj[current][i] != 0 && status[i] ==temp)
			{
				if(distance[current]+adj[current][i]<distance[i]
)
				{
					distance[i]=distance[current]+adj[current][i];
				}
			}
		}
	}

}
int main()
{
	int adj[100][100], n, src;
	scanf("%d",&n);
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			scanf("%d",&adj[i][j]);
	}
	dj(adj, n);
}
