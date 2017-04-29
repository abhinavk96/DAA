#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
struct point2d {
    int x,y;
};

struct point3d {
    int x,y,z;
};

float closestpair2d(struct point2d *,struct point2d *, int);
void closestpair3d(struct point3d *,struct point3d *,int);
void euclideanMST(struct point2d **,struct point2d *,int);
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
int main()
{
    struct point2d *points,close2d[2],**mst;
    struct point3d *plane,close3d[2];
    int i,n,m;
    scanf("%d",&n);
    points = (struct point2d *)malloc(n*sizeof(struct point2d));
    for(i=0;i<n;i++)
        scanf("%d%d",&(points[i].x),&(points[i].y));

    // scanf("%d",&m);

    // plane = (struct point3d *)malloc(m*sizeof(struct point3d));

    // for(i=0;i<m;i++)
    //     scanf("%d%d%d",&(plane[i].x),&(plane[i].y),&(plane[i].z));

    float dist_2d = closestpair2d(close2d,points,n);
    printf("distance: %f\n" , dist_2d);
    for(i = 0; i < 2; i++)
        printf("%d %d\n", close2d[i].x, close2d[i].y);
    /*closestpair3d(close3d,plane,m);

    mst = (struct point2d **)mallloc((n-1)*sizeof(struct point2d *));

    for(i=0;i<n;i++)
        mst[i]=(struct point2d *)mallloc(2*sizeof(struct point2d));

    euclideanMST(mst,points,n);*/
    return 0;
}
float dist(struct point2d p1, struct point2d p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
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
float closestpair2d(struct point2d *close2d, struct point2d *points, int n)
{

    /* find out the closest pair of points among the points in "points" and store them in the array close2d */
    qsort(points, n, sizeof(struct point2d), cmpX);
    return divide_and_conquer(close2d, points, n);
}

void closestpair3d(struct point3d *close3d, struct point3d *plane,int m)
{

    /* find out the closest pair of points among the points in "plane" and store them in the array close3d */
}

void euclideanMST(struct point2d **mst,struct point2d *points,int n)
{
    /* find out the Euclidean MST and store the MST in 2d-array mst.
     Each of the n-1 edges are store by storing it's two endpoints.
    */
}
