#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <limits.h>

struct point2d {
  int x,y;
};

struct point3d {
  int x,y,z;
};

void closestpair2d(struct point2d *,struct point2d *, int);
void closestpair3d(struct point3d *,struct point3d *,int);
void euclideanMST(struct point2d **,struct point2d *,int);

int main()
{
  struct point2d *points,close2d[2],**mst;
  struct point3d *plane,close3d[2];
  int i,n,m;
  scanf("%d",&n);
  points = (struct point2d *)malloc(n*sizeof(struct point2d));
  for(i=0;i<n;i++)
    scanf("%d%d",&(points[i].x),&(points[i].y));
/*  scanf("%d",&m);
  plane = (struct point3d *)malloc(m*sizeof(struct point3d));
  for(i=0;i<m;i++)
    scanf("%d%d%d",&(plane[i].x),&(plane[i].y),&(plane[i].z));*/
 // closestpair2d(close2d,points,n);
  //closestpair3d(close3d,plane,m);
  //printf ("2dpoints: %d %d and %d %d\n", close2d[0].x, close2d[0].y, close2d[1].x, close2d[1].y);
  //printf ("3dpoints: %d %d %d and %d %d %d\n", close3d[0].x, close3d[0].y, close3d[0].z, close3d[1].x, close3d[1].y, close3d[1].z);
 mst = (struct point2d **)malloc((n-1)*sizeof(struct point2d *));
  for(i=0;i<n;i++)
    mst[i]=(struct point2d *)malloc(2*sizeof(struct point2d));
  euclideanMST(mst,points,n);
	for (i = 0; i < n-1; i++) {
		printf ("%d %d   %d %d\n", mst[i][0].x, mst[i][0].y, mst[i][1].x, mst[i][1].y);
	}
  return 0;
}
int compareX (const void *a, const void *b) {
	struct point2d *p = (struct point2d *)a;
	struct point2d *q = (struct point2d *)b;
	return ((p->x)-(q->x));
}

int compareY (const void *a, const void *b) {
	struct point2d *p = (struct point2d *)a;
	struct point2d *q = (struct point2d *)b;
	return ((p->y) - (q->y));
}

float dist1 (struct point2d *a, struct point2d *b) {
	float temp;
	temp = (((a->x) - (b->x)) * ((a->x) - (b->x))) + (((a->y) - (b->y)) * ((a->y) - (b->y)));
	return sqrt(temp);
}

float brute_force (struct point2d *c, int n, struct point2d *ans, float prev) {
	int i, j;
	float m = FLT_MAX;
	for (i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {
			if (dist1(&c[i], &c[j]) < m && dist1 (&c[i], &c[j]) > prev){
				m = dist1 (&c[i], &c[j]);
				//printf ("jkfhk: in brute: 2dpoints: %d %d and %d %d\n", ans[0].x, ans[0].y, ans[1].x, ans[1].y);
				//printf ("ghdgj: %f\n",dist1(&(ans[0]), &(ans[1])));
				if (dist1(&(ans[0]), &(ans[1])) > m) {
					ans[0] = c[i];
					ans[1] = c[j];
				}
			}
		}
	}
	//printf ("in brute: 2dpoints: %d %d and %d %d\n", ans[0].x, ans[0].y, ans[1].x, ans[1].y);
	return m;
}

float min(float x, float y)
{
    return (x < y)? x : y;
}

float small3(struct point2d strip[], int size, float d, struct point2d *ans, float prev)
{
    float min = d;
    int i, j;
    qsort(strip, size, sizeof(struct point2d), compareY); 
    for (i = 0; i < size; ++i)
        for (j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist1(&strip[i],&strip[j]) < min && dist1 (&strip[i], &strip[j]) > prev) {
                min = dist1(&strip[i], &strip[j]);
		if (dist1(&(ans[0]), &(ans[1])) > min) {
			ans[0] = strip[i];
			ans[1] = strip[j];
		}
 	}
    return min;
}



float small2 (struct point2d *p, int n, struct point2d *ans, float prev) {
	if (n <= 3) {
		return brute_force (p, n, ans, prev);
	}
	int mid = n/2;
	float dl = small2 (p, mid, ans, prev);
	//printf ("after dl: 2dpoints: %d %d and %d %d\n", ans[0].x, ans[0].y, ans[1].x, ans[1].y);
	float dr = small2 (p+mid, n-mid, ans, prev);
	//printf ("after dr: 2dpoints: %d %d and %d %d\n", ans[0].x, ans[0].y, ans[1].x, ans[1].y);
	float d = min (dl, dr);
	struct point2d mp = p[mid];
	struct point2d strip[100];
	int k = 0;
	int i, j;
	//printf ("after d: 2dpoints: %d %d and %d %d\n", ans[0].x, ans[0].y, ans[1].x, ans[1].y);
	//printf ("midpoint: %d %d\n",mp.x, mp.y);
	for (i = 0; i < n; i++) {
		if (abs (p[i].x - mp.x) < d) {
			strip[k] = p[i];
			k++;
		}
	}
	float temp = small3 (strip, k, d, ans, prev);
	//printf ("after strip: 2dpoints: %d %d and %d %d\n", ans[0].x, ans[0].y, ans[1].x, ans[1].y);
	return min(d, temp);
	//return d;
}

int find_node (struct point2d *p, int x1, int y1, int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (p[i].x == x1 && p[i].y == y1) {
			return i;
		}
	}
}

int find (int parent[100], int x) {
	if (parent[x] != x) {
		parent[x] = find (parent, parent[x]);
	}
	return parent[x];
}

void union_n (int x, int y, int parent[100], int rank[100]) {
	int p = find(parent, x);
	int q = find(parent, y);
	if (p == q) {
		return;
	}
	if (rank[p] < rank[q]) {
		parent[p] = q;
	}
	else if (rank[p] > rank[q]) {
		parent[q] = p;
	}
	else {
		parent[q] = p;
		rank[p]++;
	}
}

void euclideanMST(struct point2d **mst,struct point2d *points,int n)
{
  /* find out the Euclidean MST and store the MST in 2d-array mst.
     Each of the n-1 edges are store by storing it's two endpoints.
  */
	qsort (points, n, sizeof (struct point2d), compareX);
	struct point2d ans[3];
	struct point2d t[100][3];
	int i;
	float prev = FLT_MIN;
	float ds[100];
	for (i = 0; i < (n*(n-1)); i++) {
		ans[0].x = 0;
		ans[0].y = 0;
		ans[1].x = 9999;
		ans[1].y = 9999;
		ds[i] = small2 (points, n, ans, prev);
		if (ans[0].x == 0 && ans[1].x == 9999) {
			break;
		}
		t[i][0] = ans[0];
		t[i][1] = ans[1];
		prev = ds[i];
		//printf ("prev: %f\n", prev);
	}
	int k = i-1;
	/*for (i = 0; i <= k; i++) {
		printf ("%d %d-%d  %d-%d : %f\n",i, t[i][0].x, t[i][0].y, t[i][1].x, t[i][1].y, ds[i]);
	}*/
	int nodes[100][3];
	for (i = 0; i <=k; i++) {
		nodes[i][0] = find_node (points, t[i][0].x, t[i][0].y, n);
		nodes[i][1] = find_node (points, t[i][1].x, t[i][1].y, n);
	}
	/*for (i = 0; i < n; i++) {
		printf ("%d %d\n", points[i].x, points[i].y);
	}
	for (i = 0; i <= k; i++) {
		printf ("%d %d\n", nodes[i][0], nodes[i][1]);
	}*/
	int parent[100], rank[100];
	for (i = 0; i < n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
	int f = 0;
	int r, s;
	int c = 0;
	int final[100][3];
	while (f < n-1) {
		r = find (parent, nodes[c][0]);
		s = find (parent, nodes[c][1]);
		if (r != s) {
			final[f][0] = nodes[c][0];
			final[f][1] = nodes[c][1];
			f++;
			union_n (r, s, parent, rank);
		}
		c++;
		
	}
	/*printf ("final: \n");
	for (i = 0; i < f; i++) {
		printf ("%d %d\n", final[i][0], final[i][1]);
	}*/
	for (i = 0; i < f; i++) {
		mst[i][0] = points[final[i][0]];
		mst[i][1] = points[final[i][1]];
	}
}

