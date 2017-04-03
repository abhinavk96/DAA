#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
 
struct Point
{
    int x, y,z;
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
                 (p1.y - p2.y)*(p1.y - p2.y) + (p1.z - p2.z)*(p1.z - p2.z) );
}
 

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
 

float min(float x, float y)
{
    return (x < y)? x : y;
}
 
 

struct Point_pair stripClosest(struct Point strip[], int size, float d)
{
    float min = d;  
    int i,j;
    qsort(strip, size, sizeof(struct Point), compareY); 
    struct Point_pair pair;
    
    for (i = 0; i < size; ++i)
        for (j = i+1; j < size ; ++j)
            if (dist(strip[i],strip[j]) < min){
                min = dist(strip[i], strip[j]);
                pair.point1 = strip[i];
                pair.point2 = strip[j];
               }
 
    return pair;
}
 

struct Point_pair closestUtil(struct Point P[], int n)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(P, n);
 
    // Find the middle point
    int mid = n/2;
    struct Point midPoint = P[mid];
 
    
    struct Point_pair pair1,pair2,this_pair;
    pair1 = closestUtil(P, mid);
    pair2 = closestUtil(P + mid, n-mid);
    float dl  = dist(pair1.point1,pair1.point2);
    float dr  = dist(pair2.point1,pair2.point2);
    
    this_pair = pair1;
    if(dr < dl)
     this_pair = pair2;
    float d = min(dl, dr);
 
   
    struct Point strip[n];
    int i,j = 0;
    for (i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;
 
   
    struct Point_pair strip_pair;
    strip_pair = stripClosest(strip, j, d);
    float strip_dist = dist(strip_pair.point1,strip_pair.point2);
    if( strip_dist < d)
       this_pair = strip_pair;
    return this_pair;
}
 

struct Point_pair closest_pair_3d(struct Point P[], int n)
{
    qsort(P, n, sizeof(struct Point), compareX);
 
   
    return closestUtil(P, n);
}
 

int main()
{
    struct Point P[] = {{2, 3, 1}, {12, 30,45}, {40, 50,60}, {5, 1 , 4}, {12, 10, 25}, {3, 4, 5}};
    int n = sizeof(P) / sizeof(P[0]);
    struct Point_pair pair;
    pair = closest_pair_3d(P,n);
    printf("The closest pair is (%d,%d,%d) (%d,%d,%d)", pair.point1.x,pair.point1.y,pair.point1.z,pair.point2.x,pair.point2.y,pair.point2.z);
    return 0;
}
