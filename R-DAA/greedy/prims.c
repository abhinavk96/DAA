#include<stdio.h>
#include<stdlib.h>
#define perm 1
#define temp 0
void make_tree(int [][100], int, int, int*);
int min_temp(int status[], int length[], int n)
{
	int min = 9999;
	int k = -1, i;
	for(i = 0;i < n; i++)
	{
		if(status[i] == temp && length[i] < min)
		{
			min = length[i];
			k = i;
		}
	}
	return k;
}
int main()
{
	int adj[100][100], n, i, r, pred[100], j;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			scanf("%d",&adj[i][j]);
	}
	scanf("%d",&r);
	for(i  =0; i < n; i++)
		pred[i] = -1;
	make_tree(adj, r, n, pred);
	for(i = 0; i < n; i++)
		printf("%d ",pred[i]);
}
void make_tree(int adj[][100], int r, int n, int pred[])
{
	int length[100], status[100], i, j, k, current;
	for(i = 0; i < n; i++)
	{
		length[i] = 9999;
		status[i] = temp;
		pred[i] = -1;
	}
	length[r] = 0;
	while(1)
	{
		current = min_temp(status, length, n);
		if(current == -1)
		{
			for(i = 0; i < n; i++)
				printf("%d  ",length[i]);
			printf("\n");
			return;
		}
		status[current] = perm;
		for(i = 0; i < n; i++)
		{
			if(adj[current][i] > 0 && status[i] == temp)
			{
				if(adj[current][i] <length[i])
				{	
					length[i] = adj[current][i];
					pred[i] = current;
				}
			}
		}
	}
}
