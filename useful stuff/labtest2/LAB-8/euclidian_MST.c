#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
struct point2d {
    int x;
    int y;
};

struct edge
{
	int src;
	int dst;
	float weight;
};

struct subset
{
	int parent;
	int rank;
};

float dist(struct point2d p1, struct point2d p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}
int cmpX(const void* p1, const void* p2)
{
    struct point2d *a, *b;
    a = (struct point2d*) p1;
    b = (struct point2d*) p2;
    return (a->x - b->x);
}
int cmpY(const void* p1, const void* p2)
{
    struct point2d *a, *b;
    a = (struct point2d*) p1;
    b = (struct point2d*) p2;
    return (a->y - b->y);
}

float min(float a, float b)
{
    return (a < b)? a : b;
}
float base_case(struct point2d close2d[], struct point2d p[], int n)
{
    float min_dist = FLT_MAX;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(dist(p[i], p[j]) < min_dist)
            {
                min_dist = dist(p[i], p[j]);
                close2d[0] = p[i];
                close2d[1] = p[j];
            }
    return min_dist;
}
float strip_min_dist(struct point2d close2d[], struct point2d s_p[], int n, float d)
{
    float min_dist = d;
    qsort(s_p, n, sizeof(struct point2d), cmpY);

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n && (s_p[j].y - s_p[i].y) < min_dist; ++j)
            if(dist(s_p[j], s_p[i]) < min_dist)
            {
                min_dist = dist(s_p[i], s_p[j]);
                close2d[0] = s_p[i];
                close2d[1] = s_p[j];
            }
    return min_dist;
}
float divide_and_conquer(struct point2d close2d[], struct point2d p[], int n)
{
    if(n <= 3)
        return base_case(close2d, p, n);
    int mid = n / 2;
    struct point2d midp = p[mid];

    struct point2d left[2];
    struct point2d right[2];
    float dist_left = divide_and_conquer(left, p, mid);
    float dist_right = divide_and_conquer(right, p + mid, n - mid);

    float d = min(dist_left, dist_right);

    if(d == dist_left)
    {
        close2d[0] = left[0];
        close2d[1] = left[1];
    }
    if(d == dist_right)
    {
        close2d[0] = right[0];
        close2d[1] = right[1];
    }
    struct point2d s_p[n];
    int k = 0;
    for(int i = 0; i < n; i++)
        if(abs(p[i].x - midp.x) < d)
            s_p[k++] = p[i];
    return min(d, strip_min_dist(close2d, s_p, k, d));
}

void closestpair2d(struct point2d *close2d, struct point2d *points, int n)
{
	qsort(points, n, sizeof(struct point2d), cmpX);
    float ans = divide_and_conquer(close2d, points, n);
}

void bubblesort(struct edge edges[], int n)
{
	int i;
	int j;
	for(i = 0; i < n - 1; i++) {
		for(j = 0; j < n - 1 - i; j++) {
			if(edges[j + 1].weight < edges[j].weight) {
				struct edge temp = edges[j + 1];
				edges[j + 1] = edges[j];
				edges[j] = temp;
			}
		}
	}
}

int insert_edge(struct point2d *points, struct edge edges[], int n)
{
	int i;
	int j;
	int ctr = 0;
	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n; j++) {
			edges[ctr].src = i;
			edges[ctr].dst = j;
			edges[ctr].weight = dist(points[i], points[j]);
			ctr++;
		}
	}
	return ctr;
}

int find(struct subset set[], int i)
{
	if(set[i].parent != i) {
		set[i].parent = find(set, set[i].parent);
	}
	return set[i].parent;
}

void Union(struct subset set[], int x, int y)
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

void euclideanMST(struct point2d **mst,struct point2d *points,int n)
{
    /* find out the Euclidean MST and store the MST in 2d-array mst.
     Each of the n-1 edges are store by storing it's two endpoints.
    */
    int i;
    struct edge edges[n * n];
    int v = insert_edge(points, edges, n);
    //qsort(edges, v, sizeof(edges[0]), cmp);
    //bubblesort(edges, v);
    /*for(i = 0; i < v; i++) {
    	printf("%d %d %f\n",edges[i].src,edges[i].dst,edges[i].weight);
    }*/
    struct edge tree[n - 1];
    int e_tree = 0;
    int cur_edge = 0;
    struct subset set[n];
    for(i = 0; i < n; i++) {
    	set[i].parent = i;
    	set[i].rank = 0;
    }

    while(e_tree < n - 1) {
    	struct point2d minpoint[2];
    	closestpair2d(points, minpoint, n);
    	int s,t;
    	for(i = 0; i < n; i++) {
    		if(minpoint[0].x == points[i].x && minpoint[0].y == points[i].y)
    			s = i;
    		if(minpoint[1].x == points[i].x && minpoint[1].y == points[i].y)
    			t = i;
    	}
		struct edge temp = edges[cur_edge++];
    	int x = find(set, temp.src);
    	int y = find(set, temp.dst);
    	if(x != y) {
    		tree[e_tree++] = temp;
    		Union(set, x, y);
    	}
    }
    for(i = 0; i < e_tree; i++) {
    	mst[i][0] = points[tree[i].src];
    	mst[i][1] = points[tree[i].dst];
    }
    for(i = 0; i < n - 1; i++) {
 		printf("%d,%d -- %d,%d -- %f\n",mst[i][0].x,mst[i][0].y,mst[i][1].x,mst[i][1].y,tree[i].weight);
 	}
}

int main()
{
    struct point2d *points,**mst;
    int i,n,m;
    scanf("%d",&n);
    points = (struct point2d *)malloc(n*sizeof(struct point2d));
    for(i=0;i<n;i++)
        scanf("%d%d",&(points[i].x),&(points[i].y));

    mst = (struct point2d **)malloc((n-1)*sizeof(struct point2d *));

    for(i=0;i<n;i++)
        mst[i]=(struct point2d *)malloc(2*sizeof(struct point2d));

    euclideanMST(mst, points, n);
    return 0;
}
