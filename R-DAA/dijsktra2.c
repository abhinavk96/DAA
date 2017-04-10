#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void heapify (int heap[], int dist[], int n, int i) {
	int l = 2*i + 1;
	int r = 2*i + 2;
	int min = i;
	if (l < n && (dist[heap[l]] < dist[heap[i]]))
		min = l;
	if (r < n && (dist[heap[r]] < dist[heap[min]]))
		min = r;
	if (min != i) {
		int temp = heap[i];
		heap[i] = heap[min];
		heap[min]= temp;
		heapify (heap, dist, n, min);
	}
}

int extract_min (int heap[], int dist[], int *n) {
	int temp = heap[0];
	*n = *n - 1;
	if (*n == 0) {
		return temp;
	}
	heap[0] = heap[*n];
	heapify (heap, dist, *n, 0);
	return temp;
}

void restoreup (int heap[], int dist[], int *n, int v) {
	heap[*n] = v;
	int i = *n;
	int par = (i - 1)/2;
	while (par >= 0 && (dist[heap[i]] < dist[heap[par]])) {
		int temp = heap[i];
		heap[i] = heap[par];
		heap[par]= temp;
		i = par;
		par = (i-1) / 2;
	}
	*n = *n + 1;
}

int dijkstra (int **adj, int n, int src, int des, int *parent) {
	int dist[n+1], heap[n+1];
	int i, j;
	for (i = 0; i < n; i++) {
		dist[i] = INT_MAX;
		parent[i] = -1;
	}
	dist[src] = 0;
	int size = 0, u;
	restoreup (heap, dist, &size, src);
	while (size) {
		u = extract_min (heap, dist, &size);
		if (u == des) {
			break;
		}
		for (i = 0; i < n; i++) {
			if (adj[u][i] != 0 && dist[i] > dist[u]+adj[u][i]) {
				dist[i] = dist[u]+adj[u][i];
				restoreup (heap, dist, &size, i);
				parent[i] = u;
			}
		}
	}
	return dist[des];
	
	/*for (i = 0; i <= c; i++) {
		printf ("%d ",path1[i]);
	}
	printf ("\n");*/
	
}

void print_path (int parent[], int src, int des) {
	if (des == src) {
		printf ("%d ",src);
	}
	else {
		print_path(parent, src, parent[des]);
		printf ("%d ",des);
	}
}

void shortest_path (int **adj, int n, int src, int des, int *parent1, int *parent2, int *parent3) {
	int i, j, l;
	int d1 = dijkstra (adj, n, src, des, parent1);
	printf ("Distance1: %d\n",d1);
	print_path (parent1, src, des);
	printf ("\n");
	int path1[100];
	int c = 0;
	path1[0] = des;
	int temp = des;
	while (temp != src) {
		c++;
		path1[c] = parent1[temp];
		temp = parent1[temp];
	}
	/*for (i = 0; i <= c; i++) {
		printf ("%d ",path1[i]);
	}
	printf ("\n");*/
	for (i = 0; i <= (c/2); i++) {
		temp = path1[i];
		path1[i] = path1[c-i];
		path1[c-i] = temp;
	}
	/*for (i = 0; i <= c; i++) {
		printf ("%d ",path1[i]);
	}
	printf ("\n");*/
	int min = INT_MAX;
	int val, minid;
	for (i = 0; i < c; i++) {
		temp = adj[path1[i]][path1[i+1]];
		adj[path1[i]][path1[i+1]] = 999999;
		adj[path1[i+1]][path1[i]] = 999999;
		val = dijkstra (adj, n, src, des, parent2);
		//printf ("val: %d\n", val);
		if (val < min) {
			min = val;
			minid = i;
		}
		adj[path1[i]][path1[i+1]] = temp;
		adj[path1[i+1]][path1[i]] = temp;
		//printf ("hey\n");
	}
	//printf ("%d\n", minid);
	temp = adj[path1[minid]][path1[minid+1]];
	adj[path1[minid]][path1[minid+1]] = 999999;
	adj[path1[minid+1]][path1[minid]] = 999999;
	int d2 = dijkstra (adj, n, src, des, parent2);
	printf ("distance2: %d\n",d2);
	print_path (parent2, src, des);
	printf ("\n");
	adj[path1[minid]][path1[minid+1]] = temp;
	adj[path1[minid+1]][path1[minid]] = temp;
	int path2[100];
	int c1 = 0;
	path2[c1] = des;
	temp = des;
	while (temp != src) {
		c1++;
		path2[c1] = parent2[temp];
		temp = parent2[temp];
	}
	for (i = 0; i <= (c1/2); i++) {
		temp = path2[i];
		path2[i] = path2[c1-i];
		path2[c1-i] = temp;
	}
	/*for (i = 0; i <= c1; i++) {
		printf ("%d ",path2[i]);
	}
	printf ("\n");*/
	int t2, t;
	int val2, minid2, min2 = INT_MAX, minid3;
	for (i = 0; i < c; i++) {
		t = adj[path1[i]][path1[i+1]];
		adj[path1[i]][path1[i+1]] = 999999;
		adj[path1[i+1]][path1[i]] = 999999;
		for (j = 0; j < c1; j++) {
			t2 = adj[path2[j]][path2[j+1]];
			adj[path2[j]][path2[j+1]] = 999999;
			adj[path2[j+1]][path2[j]] = 999999;
			val2 = dijkstra (adj, n, src, des, parent3);
			if (val2 < min2) {
				min2 = val2;
				minid2 = i;
				minid3 = j;
			}
			adj[path2[j]][path2[j+1]] = t2;
			adj[path2[j+1]][path2[j]] = t2;
		}
		adj[path1[i]][path1[i+1]] = t;
		adj[path1[i+1]][path1[i]] = t;
	}
	t = adj[path1[minid2]][path1[minid2+1]];
	adj[path1[minid2]][path1[minid2+1]] = 999999;
	adj[path1[minid2+1]][path1[minid2]] = 999999;
	t2 = adj[path2[minid3]][path2[minid3+1]]; 
	adj[path2[minid3]][path2[minid3+1]] = 999999;
	adj[path2[minid3+1]][path2[minid3]] = 999999;
	int d3 = dijkstra (adj, n, src, des, parent3);
	printf ("distance3: %d\n",d3);
	print_path (parent3, src, des);
	printf ("\n");
}



int main () {
	freopen("input_graph.txt", "r+", stdin);
	int n;
	scanf("%d", &n);
	//printf ("n: %d\n",n);
	int **adj;
	adj = (int **)(calloc(n, sizeof(int *)));
	int i, j;
	for(i = 0; i < n; i++) {
		adj[i] = (int *)(calloc(n, sizeof(int)));
	}
	int *parent1, *parent2, *parent3;
	int a, b, c;
	parent1 = (int *)(calloc(n, sizeof(int)));
	parent2 = (int *)(calloc(n, sizeof(int)));
	parent3 = (int *)(calloc(n, sizeof(int)));
	while(1) {
		scanf("%d %d %d", &a, &b, &c);
		if(a == -1) {
			break;
		}
		adj[a][b] = c;
		adj[b][a] = c;
	}
	/*for (i= 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf ("%d ",adj[i][j]);
		}
		printf ("\n");
	}*/
	int src, des;
	scanf("%d %d", &src, &des);
	//dijkstra (adj, n, src, des, parent1, parent2, parent3);
	shortest_path (adj, n, src, des, parent1, parent1, parent3);
	//printf ("src: %d %d\n", src, des);
	//printf ("Distance: %d\n", dijkstra(adj, n, src, des, parent1));
	//print_path (parent1, src, des);
	return 0;
}
