#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct graph graph;
typedef struct edge edge; 
typedef struct subset subset;

struct edge 
{
	int src;
	int dst;
	int weight;
};

struct graph
{
	int v;
	int e;
	edge* edges;
};

struct subset
{
	int parent;
	int rank;
};

graph* creategraph(int v) 
{
	graph* temp = (graph*)malloc(sizeof(graph));
	temp -> v = v;
	temp -> e = 0;
	temp -> edges = (edge*)malloc(sizeof(edge) * temp -> v * temp -> v); 
	return temp;
}

void insert_edge(graph* g, int u, int v, int w)
{
	g -> edges[g -> e].src = u;
	g -> edges[g -> e].dst = v;
	g -> edges[g -> e].weight = w;
	(g -> e)++;
}

int cmp(const void* a, const void* b)
{
    edge* a1 = (edge*)a;
    edge* b1 = (edge*)b;
    return a1 -> weight - b1 -> weight;
}

int find(subset set[], int i)
{
	if(set[i].parent != i) {
		set[i].parent = find(set, set[i].parent);
	}
	return set[i].parent;
}

void Union(subset set[], int x, int y)
{
	int x1 = find(set, x);
	int x2 = find(set, y);
		if(set[x1].rank < set[x2].rank) {
			set[x1].parent = x2;
		}
		else if (set[x1].rank > set[x2].rank) {
			set[x2].parent =x1;
		}
		else {
			set[x1].parent = x2;
			set[x2].rank++;
		}

}

void kruskal(graph* g)
{
	int v = g -> v;
	edge mst[v - 1];
	int i;
	qsort(g -> edges, g -> e, sizeof(g -> edges[0]), cmp);
	subset* set = (subset*)malloc(sizeof(subset) * v); // subset set[v]
	for(i = 0; i < v; i++) {
		set[i].parent = i;
		set[i].rank = 0; 
	}
	int e = 0;
	int j = 0;
	while(e < v - 1) {
		edge temp = g -> edges[j++];
		int x = find(set, temp.src);
		int y = find(set, temp.dst);
		if(x != y) {
			mst[e++] = temp;
			Union(set, x , y);
		}
	}
	printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", mst[i].src, mst[i].dst, mst[i].weight);
}

int main()
{
	int n;
	scanf("%d",&n);
	graph* g = creategraph(n);
	//printf("hello");
	int u, v, w;
	scanf("%d%d%d",&u,&v,&w);
	while(u != -1) {
		insert_edge(g, u, v, w);
		scanf("%d%d%d",&u,&v,&w);
	}
	kruskal(g);
	return 0;
}
