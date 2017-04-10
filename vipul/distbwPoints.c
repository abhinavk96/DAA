#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

struct point2d {
  int x,y;
};

struct point3d {
  int x,y,z;
};

void closestpair2d(struct point2d *,struct point2d *, int);
void closestpair3d(struct point3d *,struct point3d *,int);
void euclideanMST(struct point2d **,struct point2d *,int);
float distance2d(struct point2d p1,struct point2d p2);
float distance3d(struct point3d p1, struct point3d p2);
int cmp2d(const void *a, const void *b);
int cmp2dy(const void *a, const void *b);
int cmp3d(const void *a, const void *b);
void merge2d(struct point2d *close2d,struct point2d *points,int n,float d);
void merge3d(struct point3d *close3d,struct point3d *points,int n,float d);
float findmin(float a, float b)
{
	return ( (a<b)?a:b);
}
float findmin3( float a, float b, float c)
{
	return ( (a<findmin(b,c))?a:findmin(b,c) );
}

void make_set(int a[], int n);
void Union(int a[], int n1, int n2);
int find_set(int n, int a[]);

int main()
{
  struct point2d *points,close2d[2],**mst;
  struct point3d *plane,close3d[2];
  int i,n,m;
  scanf("%d",&n);
  points = (struct point2d *)malloc(n*sizeof(struct point2d));
  for(i=0;i<n;i++)
    scanf("%d%d",&(points[i].x),&(points[i].y));
  scanf("%d",&m);
  plane = (struct point3d *)malloc(m*sizeof(struct point3d));
  for(i=0;i<m;i++)
    scanf("%d%d%d",&(plane[i].x),&(plane[i].y),&(plane[i].z));
	qsort(points,n,sizeof(struct point2d),cmp2d);

  closestpair2d(close2d,points,n);
  closestpair3d(close3d,plane,m);
 // mst = (struct point2d **)malloc((n-1)*sizeof(struct point2d *));
  //for(i=0;i<n;i++)
    //mst[i]=(struct point2d *)malloc(2*sizeof(struct point2d));
  //euclideanMST(mst,points,n);
	printf("(%d %d),(%d %d) -> %f\n",close3d[0].x,close3d[0].y,close3d[1].x,close3d[1].y, distance3d(close3d[0], close3d[1]));
  return 0;
}
void make_set(int a[], int n)
{
	int i;
	for ( i = 0; i < n; ++i ) {
		a[i] = -1;
	}
}
void Union(int a[], int n1, int n2)
{
	int p1, p2;
	p1 = find_set ( n1, a);
	p2 = find_set ( n2, a);
	a[p1] = p2;
}
int find_set(int n, int a[])
{
	if ( a[n] == -1 )
		return n;
	else return find_set ( a[n], a);
	
}

void closestpair2d(struct point2d *close2d, struct point2d *points, int n)
{
	
  /* find out the closest pair of points among the points in "points" and store them in the array close2d */


	if ( n <= 3) {
		int i,j;
		float min = FLT_MAX;
		for ( i = 0; i < n; i++){
			for ( j = i+1; j < n; j++){
				if(distance2d(points[i],points[j]) < min){
					min = distance2d(points[i],points[j]);
					printf("%f\n",min);
					close2d[0] = points[i];
					close2d[1] = points[j];
				}
			}
		}
		return;
	}
	int i, j, mid;
	float dl,dr;
	mid = n/2;
	struct point2d close2dl[2], close2dr[2];
	struct point2d left[mid],right[n-mid];
	for ( i = 0; i < mid; i++){
		left[i] = points[i];
	}
   	for(i=mid;i<n;i++){
   		right[i-mid]=points[i];
    }
	closestpair2d(close2dl,left,n-mid);
	dl = distance2d(close2dl[0],close2dl[1]);
	closestpair2d(close2dr,right,mid);
	dr = distance2d(close2dr[0],close2dr[1]);
	
	float d = findmin(dl,dr);
	merge2d(close2d, points, n,d);
	d = findmin3(dl,dr,distance2d(close2d[0],close2d[1]));
	if ( d == dl){
		close2d[0] = close2dl[0];
		close2d[1] = close2dl[1];
	}
	else if ( d == dr){
		close2d[0] = close2dr[0];
		close2d[1] = close2dr[1];
	}
	
}
void merge2d(struct point2d *close2d,struct point2d *points,int n,float d)
{
	struct point2d strip[n];
	int i, j, count=0, mid = n/2;
    for(i=mid-1;i>=0;i--){
       if(points[mid].x-points[i].x<=d){
          strip[count++] = points[i];
       }
   }
   for(i=mid;i<n;i++){
		if(points[i].x-points[mid].x<=d){
   		strip[count++] = points[i];
		}
   }
	qsort(strip, count, sizeof(struct point2d), cmp2dy); 
	float min = FLT_MAX;
	for ( i = 0; i < n; i++){
		for ( j = i+1; j < n; j++){
			if(distance2d(points[i],points[j]) < min){
				min = distance2d(points[i],points[j]);
				close2d[0] = points[i];
				close2d[1] = points[j];
			}
		}
	}
	return;	
}
void closestpair3d(struct point3d *close3d, struct point3d *points,int n)
{

  /* find out the closest pair of points among the points in "plane" and store them in the array close3d */

	if ( n <= 3) {
		int i,j;
		float min = FLT_MAX;
		for ( i = 0; i < n; i++){
			for ( j = i+1; j < n; j++){
				if(distance3d(points[i],points[j]) < min){
					min = distance3d(points[i],points[j]);
					close3d[0] = points[i];
					close3d[1] = points[j];
				}
			}
		}
		return;
	}
	int i, j, mid;
	float dl,dr;
	mid = n/2;
	struct point3d close3dl[2], close3dr[2];
	struct point3d left[mid],right[n-mid];
	for ( i = 0; i < mid; i++){
		left[i] = points[i];
	}
   	for(i=mid;i<n;i++){
   		right[i-mid]=points[i];
    }
	closestpair3d(close3dl,left,n-mid);
	dl = distance3d(close3dl[0],close3dl[1]);
	closestpair3d(close3dr,right,mid);
	dr = distance3d(close3dr[0],close3dr[1]);
	
	float d = findmin(dl,dr);
	merge3d(close3d, points, n,d);
	d = findmin3(dl,dr,distance3d(close3d[0],close3d[1]));
	if ( d == dl){
		close3d[0] = close3dl[0];
		close3d[1] = close3dl[1];
	}
	else if ( d == dr){
		close3d[0] = close3dr[0];
		close3d[1] = close3dr[1];
	}

}
void merge3d(struct point3d *close3d,struct point3d *points,int n,float d)
{
	struct point3d strip[n];
	int i, j, count=0, mid = n/2;
    for(i=mid-1;i>=0;i--){
       if(points[mid].x-points[i].x<=d){
          strip[count++] = points[i];
       }
   }
   for(i=mid;i<n;i++){
		if(points[i].x-points[mid].x<=d){
   		strip[count++] = points[i];
		}
   }
//	qsort(strip, count, sizeof(struct point2d), cmp2dy); 
	float min = FLT_MAX;
	for ( i = 0; i < n; i++){
		for ( j = i+1; j < n; j++){
			if(distance3d(points[i],points[j]) < min){
				min = distance3d(points[i],points[j]);
				close3d[0] = points[i];
				close3d[1] = points[j];
			}
		}
	}
	return;	

}
void euclideanMST(struct point2d **mst,struct point2d *points,int n)
{
  /* find out the Euclidean MST and store the MST in 2d-array mst.
     Each of the n-1 edges are store by storing it's two endpoints.
  */
  int set[n];
  int i, j, k;
  make_set(set,n);
  for ( i = ; i  < n-1; i++){
  	struct point2d v[2];
  	int v1, v2;
  	closestpair2d(v, points, n);
  	for 
  	
  }
  
  
  
}

float distance2d(struct point2d p1,struct point2d p2)
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}

float distance3d(struct point3d p1, struct point3d p2)
{
	return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) + (p1.z-p2.z)*(p1.z-p2.z) );
}

int cmp2d(const void *a, const void *b)
{
   int ax=((struct point2d *)a)->x;
   int bx=((struct point2d *)b)->x;
   return ax-bx;
}
int cmp2dy(const void *a, const void *b)
{
   int ax=((struct point2d *)a)->y;
   int bx=((struct point2d *)b)->y;
   return ax-bx;
}
int cmp3d(const void *a, const void *b)
{
   int ax=((struct point3d *)a)->x;
   int bx=((struct point3d *)b)->x;
   return ax-bx;
}

