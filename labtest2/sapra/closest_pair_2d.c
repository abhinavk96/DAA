#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include<limits.h>
struct Point
{
    int x, y;
};
struct Point_pair{
	struct Point point1;
	struct Point point2;
};
int compareX(const void* a, const void* b)
{
    struct Point *p1 = (struct Point *)a,  *p2 = (struct Point *)b;
    return (p1->x - p2->x);
}
int compareY(const void* a, const void* b)
{
    struct Point *p1 = (struct Point *)a,   *p2 = (struct Point *)b;
    return (p1->y - p2->y);
}

float dist(struct Point p1,struct Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}

// A Brute Force method to return the smallest distance between two points
// in P[] of size n
struct Point_pair bruteForce(struct Point P[], int n)
{
    float min = FLT_MAX;
    struct Point_pair pair;
    int i,j;
    for (i = 0; i < n; ++i)
        for (j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min){
                min = dist(P[i], P[j]);
                pair.point1 = P[i];
                pair.point2 = P[j];
               }
    return pair;
}

// A utility function to find minimum of two float values
float min(float x, float y)
{
    return (x < y)? x : y;
}


// A utility function to find the distance beween the closest points of
// strip of given size. All points in strip[] are sorted accordint to
// y coordinate. They all have an upper bound on minimum distance as d.
// Note that this method seems to be a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
struct Point_pair stripClosest(struct Point strip[], int size, float d)
{
    float min = d;  // Initialize the minimum distance as d
    int i,j;
    qsort(strip, size, sizeof(struct Point), compareY);
    struct Point_pair pair;
    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (i = 0; i < size; ++i)
        for (j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min){
                min = dist(strip[i], strip[j]);
                pair.point1 = strip[i];
                pair.point2 = strip[j];
               }

    return pair;
}

// A recursive function to find the smallest distance. The array P contains
// all points sorted according to x coordinate
struct Point_pair closestUtil(struct Point P[], int n)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(P, n);

    // Find the middle point
    int mid = n/2;
    struct Point midPoint = P[mid];

    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    struct Point_pair pair1,pair2,this_pair;
    pair1 = closestUtil(P, mid);
    pair2 = closestUtil(P + mid, n-mid);
    float dl  = dist(pair1.point1,pair1.point2);
    float dr  = dist(pair2.point1,pair2.point2);
    // Find the smaller of two distances
    this_pair = pair1;
    if(dr < dl)
     this_pair = pair2;
    float d = min(dl, dr);

    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    struct Point strip[n];
    int i,j = 0;
    for (i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;

    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]
    struct Point_pair strip_pair;
    strip_pair = stripClosest(strip, j, d);
    float strip_dist = dist(strip_pair.point1,strip_pair.point2);
    if( strip_dist < d)
       this_pair = strip_pair;
    return this_pair;
}

// The main functin that finds the smallest distance
// This method mainly uses closestUtil()
struct Point_pair closest_pair_2d(struct Point P[], int n)
{
    qsort(P, n, sizeof(struct Point), compareX);

    // Use recursive function closestUtil() to find the smallest distance
    return closestUtil(P, n);
}
//------------------------------------------------------
//------------------------------------------------------
//--------------------------set version below-----------

struct Point_pair bruteForce_1(struct Point P[],int total_size, int n,int set[])
{
    float min = FLT_MAX;
    struct Point_pair pair;
    pair.point1.x = 0;
    pair.point1.y = 0;
    pair.point2.x = 0;
    pair.point2.y = 111111111;
    int i,j;
    int p1,p2;
    for (i = 0; i < n; ++i){
        for (j = i+1; j < n; ++j){
                p1 = find_index(P,P[i],total_size);
                p2 = find_index(P,P[j],total_size);
            if (dist(P[i], P[j]) < min && root(set,p1) != root(set,p2)){
                min = dist(P[i], P[j]);
                pair.point1 = P[i];
                pair.point2 = P[j];
               }
    }
    }
             //  printf("brute return (%d,%d)  (%d,%d)\n",pair.point1.x,pair.point1.y,pair.point2.x,pair.point2.y);

    return pair;
}

// A utility function to find minimum of two float values



// A utility function to find the distance beween the closest points of
// strip of given size. All points in strip[] are sorted accordint to
// y coordinate. They all have an upper bound on minimum distance as d.
// Note that this method seems to be a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
struct Point_pair stripClosest_1(struct Point P[],int total_size,int set[],struct Point strip[], int size, float d)
{
    float min = d;  // Initialize the minimum distance as d
    int i,j;
    //qsort(strip, size, sizeof(struct Point), compareY);
    struct Point_pair pair;
    pair.point1.x = 0;
    pair.point1.y = 0;
    pair.point2.x = 0;
    pair.point2.y = 1111111;

    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    int p1,p2;
    for (i = 0; i < size; ++i){
        for (j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j){
                p1 = find_index(P,P[i],total_size);
                p2 = find_index(P,P[j],total_size);
                //printf("strip %d %d\n",p1,p2);
            if (dist(strip[i],strip[j]) < min && root(set,p1) != root(set,p2)){
                min = dist(strip[i], strip[j]);
                pair.point1 = strip[i];
                pair.point2 = strip[j];
               }
        }
    }
    // printf("strip return (%d,%d)  (%d,%d)\n",pair.point1.x,pair.point1.y,pair.point2.x,pair.point2.y);

    return pair;
}

// A recursive function to find the smallest distance. The array P contains
// all points sorted according to x coordinate
struct Point_pair closestUtil_1(struct Point P[], int n,int set[],int total_size)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce_1(P,total_size,n,set);

    // Find the middle point
    int mid = n/2;
    struct Point midPoint = P[mid];

    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    struct Point_pair pair1,pair2,this_pair;
    pair1 = closestUtil_1(P, mid,set,total_size);
    pair2 = closestUtil_1(P + mid, n-mid,set,total_size);
    float dl  = dist(pair1.point1,pair1.point2);
    float dr  = dist(pair2.point1,pair2.point2);
    // Find the smaller of two distances
    this_pair = pair1;
    if(dr < dl)
     this_pair = pair2;
    float d = min(dl, dr);

    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    struct Point strip[n];
    int i,j = 0;
    for (i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;

    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]
    struct Point_pair strip_pair;
    strip_pair = stripClosest_1(P,total_size,set,strip,j, d);
    float strip_dist = dist(strip_pair.point1,strip_pair.point2);

    if( strip_dist < d)
       this_pair = strip_pair;

    //printf("func return (%d,%d)  (%d,%d)\n",this_pair.point1.x,this_pair.point1.y,this_pair.point2.x,this_pair.point2.y);
    return this_pair;
}

// The main functin that finds the smallest distance
// This method mainly uses closestUtil()
struct Point_pair closest_pair_2d_1(struct Point P[], int n,int set[])
{
    qsort(P, n, sizeof(struct Point), compareX);

    // Use recursive function closestUtil() to find the smallest distance
    return closestUtil_1(P, n,set,n);
}

void initialize(int set[],int n)
{
    int i;
    for( i = 0;i < n;++i)
        set[i] = i;
}

int root(int set[],int x)
{
    while(set[x] != x)
    {
        set[x] = set[set[x]];
        x = set[x];
    }
    return x;
}

void union1(int set[],int x, int y)
{
    int p = root(set,x);
    int q = root(set,y);
    set[p] = set[q];
}
int find_index(struct Point P[],struct Point pl,int size){
    int i;
    for(i=0;i<size;i++){
        if(P[i].x == pl.x && P[i].y == pl.y){
            return i;
        }
    }


}
int all_marked(int set[],int n){
    int i,x = set[0];

    for(i=0;i<n;i++){
       if(set[i] != x){
        return 0;
       }

    }
    return 1;


}
 long long kruskal(struct Point P[],struct Point_pair mst[],int n)
{
    struct Point_pair pair;
    float cost, minimumCost = 0;
    int edges = (n*(n-1))/2;
    int set[n];
    initialize(set,n);
    int i,j = 0;

    for(i = 0;i < edges;++i)
    {
        pair = closest_pair_2d_1(P,n,set);
        // Selecting edges one by one in increasing order from the beginning
        cost = dist(pair.point1,pair.point2);
        // Check if the selected edge is creating a cycle or not
        int p1,p2;
        p1 = find_index(P,pair.point1,n);
        p2 = find_index(P,pair.point2,n);
        if(all_marked(set,n))
            break;
        //printf("(%d,%d)  (%d,%d)\n",pair.point1.x,pair.point1.y,pair.point2.x,pair.point2.y);
        //printf("before %d %d\n",root(set,p1),root(set,p2));
        if(root(set,p1) != root(set,p2))
        {
            minimumCost += cost;
            union1(set,p1, p2);
            mst[j++] = pair;
        }
        //printf("after %d %d\n",root(set,p1),root(set,p2));


    }
     int length = j;
    for(j = 0;j<length;j++){
            printf("(%d,%d)  (%d,%d)\n",mst[j].point1.x,mst[j].point1.y,mst[j].point2.x,mst[j].point2.y);
        }
    return minimumCost;
}
// Driver program to test above functions
int main()
{
    struct Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    struct Point_pair pair;
    pair = closest_pair_2d(P,n);
    printf("The closest pair is (%d,%d) (%d,%d)\n", pair.point1.x,pair.point1.y,pair.point2.x,pair.point2.y);
    struct Point mst[n][2];
    int p = kruskal(P,mst,n);
    printf("%d\n",p);
    return 0;
}
