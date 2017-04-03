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

void closestpair2d(struct point2d *,struct point2d *, int);
void closestpair3d(struct point3d *,struct point3d *,int);
void euclideanMST(struct point2d **,struct point2d *,int);
float findMin2d(struct point2d *points,struct point2d close2d[], int n);
float stripClosest2d(struct point2d strip[], struct point2d close2d[], int size, float d);
float bruteForce2d(struct point2d P[], struct point2d close2d[], int n);
float min(float a, float b);
float dist2d(struct point2d p1, struct point2d p2);
float findMin3d(struct point3d *points,struct point3d close3d[], int n);
float stripClosest3d(struct point3d strip[], struct point3d close3d[], int size, float d);
float bruteForce3d(struct point3d P[], struct point3d close3d[], int n);
float dist3d(struct point3d p1, struct point3d p2);
void closestpair2Kd(struct point2d *close2d, struct point2d *points, struct point2d store[][2], int n);
float findMinK2d(struct point2d *points,struct point2d close2d[], int n, float existing);
float stripClosest2Kd(struct point2d strip[], struct point2d close2d[], int size, float d, float existing);
float bruteForce2Kd(struct point2d P[], struct point2d close2d[], int n, float existing);

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
  closestpair2d(close2d,points,n);
   closestpair3d(close3d,plane,m);
  mst = (struct point2d **)malloc((n-1)*sizeof(struct point2d *));
   for(i=0;i<n;i++)
  mst[i]=(struct point2d *)malloc(2*sizeof(struct point2d));
  euclideanMST(mst,points,n);


    return 0;
}



void closestpair2d(struct point2d *close2d, struct point2d *points, int n)
{

  int i,j;
  
  /* find out the closest pair of points among the points in "points" and store them in the array close2d */
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-1;j++)
    {
      if(points[j].x>points[j+1].x)
      {
        struct point2d temp = points[j+1];
        points[j+1] = points[j];
        points[j] =  temp;
      }
    }

  }
  close2d[0].x = 9999;
  close2d[0].y = 9999;
  close2d[1].x = 0;
  close2d[1].y = 0;

  findMin2d(points, close2d, n);

  // for(i=0;i<n;i++)
  // {
  //   printf("%d %d\n", points[i].x,points[i].y);

  // }
    printf("The closest 2D points are:(%d,%d) and (%d,%d) and the distance between them is: %f \n", close2d[0].x,close2d[0].y,close2d[1].x,close2d[1].y,dist2d(close2d[0],close2d[1]));
    

}
void closestpair2Kd(struct point2d *close2d, struct point2d *points, struct point2d store[][2], int n)
{

  int i,j,k=0,flag =0;
  
  /* find out the closest pair of points among the points in "points" and store them in the array close2d */
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-1;j++)
    {
      if(points[j].x>points[j+1].x)
      {
        struct point2d temp = points[j+1];
        points[j+1] = points[j];
        points[j] =  temp;
      }
    }

  }

    float d[n*n];
    d[0] = 0.0;
     j = 0;
    for(i=1;i<n*(n-1);i++)
    {
      close2d[0].x = 0;
      close2d[0].y = 0;
      close2d[1].x = 9999;
      close2d[1].y = 9999;
      d[i] = findMinK2d(points, close2d,n, d[i-1]);
    // if(close2d[0].x == 0 && close2d[1].x == 9999)
    //   break;
    for(k=0;k<j&&j!=0;k++)
    {
      flag =0;
      if(store[k][0].x==close2d[0].x && store[k][1].x == close2d[1].x&&store[k][0].y==close2d[0].y && store[k][1].y == close2d[1].y)
      {
        d[i]+=1;
        flag = 1;
        break;
      }
    }
    if(flag!=1)
    {
    store[j][0] = close2d[0];
    store[j][1] = close2d[1];
          printf("(%d,%d) (%d,%d)\n", store[j][0].x,store[j][0].y, store[j][1].x,store[j][1].y);
          j++;
    }

    }

}
void closestpair3d(struct point3d *close3d, struct point3d *plane,int m)
{

  /* find out the closest pair of points among the points in "plane" and store them in the array close3d */
  int i,j;
  
  /* find out the closest pair of plane among the plane in "plane" and store them in the array close3d */
  for(i=0;i<m;i++)
  {
    for(j=0;j<m-1;j++)
    {
      if(plane[j].x>plane[j+1].x)
      {
        struct point3d temp = plane[j+1];
        plane[j+1] = plane[j];
        plane[j] =  temp;
      }
    }

  }
  close3d[0].x = 9999;
  close3d[0].y = 9999;
  close3d[0].z = 9999;
  close3d[1].x = 0;
  close3d[1].y = 0;
  close3d[1].z = 0;
  findMin3d(plane, close3d, m);
  printf("The closest 3d points are:(%d,%d,%d) and (%d,%d,%d) and the distance between them is: %f \n", close3d[0].x,close3d[0].y,close3d[0].z,close3d[1].x,close3d[1].y,close3d[1].z,dist3d(close3d[0],close3d[1]));

}

void euclideanMST(struct point2d **mst,struct point2d *points,int n)
{
  /* find out the Euclidean MST and store the MST in 2d-array mst.
     Each of the n-1 edges are store by storing it's two endpoints.
  */
  int i,j;
  int distance [n][n];
  struct point2d store[n*(n-1)][2];
  struct point2d close2d [2];
  
  closestpair2Kd(close2d, points, store,n);
  // for(i=0;i<n*(n-1);i++)
  //   {
  //     printf("(%d,%d) (%d,%d)\n", store[i][0].x,store[i][0].y, store[i][1].x,store[i][1].y);
  //   }
  /* find out the closest pair of points among the points in "points" and store them in the array close2d */


}
float findMin2d(struct point2d *points,struct point2d close2d[], int n)
{
  if(n<=3)
  {
    return bruteForce2d(points, close2d,n);
  }

  int mid = n/2;
  struct point2d midPoint;
  midPoint = points[mid];
  float dl = findMin2d(points,close2d, mid);
  float dr = findMin2d(points + mid,close2d, n - mid);
  float d = min(dl,dr);
  struct point2d strip[n];
  int i,j = 0;
  for(i=0;i<n;i++)
  {
    if(abs(midPoint.x-points[i].x)<d)
    {
      strip[j++] = points[i];
    }
  }
  return min(d, stripClosest2d(strip,close2d, j, d) );

}

float findMinK2d(struct point2d *points,struct point2d close2d[], int n, float existing)
{
  if(n<=3)
  {
    return bruteForce2Kd(points, close2d,n,existing);
  }

  int mid = n/2;
  struct point2d midPoint;
  midPoint = points[mid];
  float dl = findMinK2d(points,close2d, mid,existing);
  float dr = findMinK2d(points + mid,close2d, n - mid,existing);
  float d = min(dl,dr);
  struct point2d strip[n];
  int i,j = 0;
  for(i=0;i<n;i++)
  {
    if(abs(midPoint.x-points[i].x)<d)
    {
      strip[j++] = points[i];
    }
  }
  return min(d, stripClosest2Kd(strip,close2d, j, d,existing) );

}


float stripClosest2d(struct point2d strip[], struct point2d close2d[], int size, float d)
{
    float min = d;  // Initialize the minimum distance as d
 
    int i,j;

  /* find out the closest pair of points among the points in "points" and store them in the array close2d */
  for(i=0;i<size;i++)
  {
    for(j=0;j<size-1;j++)
    {
      if(strip[j].y>strip[j+1].y)
      {
        struct point2d temp = strip[j+1];
        strip[j+1] = strip[j];
        strip[j] =  temp;
      }
    }

  }
 
    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (i = 0; i < size; ++i)
        for ( j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist2d(strip[i],strip[j]) < min)
            {
                min = dist2d(strip[i], strip[j]);
                close2d[0] = strip[i];
                close2d[1] = strip[j];
            }
 
    return min;
}
float stripClosest2Kd(struct point2d strip[], struct point2d close2d[], int size, float d, float existing)
{
    float min = d;  // Initialize the minimum distance as d
 
    int i,j;

  /* find out the closest pair of points among the points in "points" and store them in the array close2d */
  for(i=0;i<size;i++)
  {
    for(j=0;j<size-1;j++)
    {
      if(strip[j].y>strip[j+1].y)
      {
        struct point2d temp = strip[j+1];
        strip[j+1] = strip[j];
        strip[j] =  temp;
      }
    }

  }
 
    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (i = 0; i < size; ++i)
        for ( j = i+1; j < size && (strip[j].y - strip[i].y) <=min; ++j)
            if (dist2d(strip[i],strip[j]) <=min && dist2d(strip[i],strip[j])>=existing)
            {
                min = dist2d(strip[i], strip[j]);
                close2d[0] = strip[i];
                close2d[1] = strip[j];
            }
 
    return min;
}

float dist2d(struct point2d p1, struct point2d p2)
{
  float r;
  r = sqrt(((p1.x-p2.x)*(p1.x-p2.x))+((p1.y-p2.y)*(p1.y-p2.y)));
  return r;
}

float bruteForce2d(struct point2d P[], struct point2d close2d[], int n)
{
    float min = dist2d(close2d[0],close2d[1]);
    int i,j;
    for ( i = 0; i < n; ++i)
        for ( j = i+1; j < n; ++j)
            if (dist2d(P[i], P[j]) < min)
            {
                close2d[0] = P[i];
                close2d[1] = P[j];
                min = dist2d(P[i], P[j]);
            }
    return min;
}
float bruteForce2Kd(struct point2d P[], struct point2d close2d[], int n, float existing )
{
    float min = dist2d(close2d[0],close2d[1]);
    int i,j;
    for ( i = 0; i < n; ++i)
        for ( j = i+1; j < n; ++j)
            if (dist2d(P[i], P[j]) <= min && dist2d(P[i],P[j])>=existing)
            {
                close2d[0] = P[i];
                close2d[1] = P[j];
                min = dist2d(P[i], P[j]);
            }
    return min;
}

float dist3d(struct point3d p1, struct point3d p2)
{
  float r;
  r = sqrt(((p1.x-p2.x)*(p1.x-p2.x))+((p1.y-p2.y)*(p1.y-p2.y)) + ((p1.z-p2.z)*(p1.z-p2.z)));
  return r;
}
float findMin3d(struct point3d *plane,struct point3d close3d[], int n)
{
  if(n<=3)
  {
    return bruteForce3d(plane, close3d,n);
  }

  int mid = n/2;
  struct point3d midPoint;
  midPoint = plane[mid];
  float dl = findMin3d(plane,close3d, mid);
  float dr = findMin3d(plane + mid,close3d, n - mid);
  float d = min(dl,dr);
  struct point3d strip[n];
  int i,j = 0;
  for(i=0;i<n;i++)
  {
    if(abs(midPoint.x-plane[i].x)<d)
    {
      strip[j++] = plane[i];
    }
  }
  return min(d, stripClosest3d(strip,close3d, j, d) );

}
float min(float a, float b)
{
  return a<b?a:b;
}

float stripClosest3d(struct point3d strip[], struct point3d close3d[], int size, float d)
{
    float min = d;  // Initialize the minimum distance as d
 
    int i,j;

  /* find out the closest pair of plane among the plane in "plane" and store them in the array close3d */
  for(i=0;i<size;i++)
  {
    for(j=0;j<size-1;j++)
    {
      if(strip[j].y>strip[j+1].y)
      {
        struct point3d temp = strip[j+1];
        strip[j+1] = strip[j];
        strip[j] =  temp;
      }
    }

  }
 
    // Pick all plane one by one and try the next plane till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (i = 0; i < size; ++i)
        for ( j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist3d(strip[i],strip[j]) < min)
            {
                min = dist3d(strip[i], strip[j]);
                close3d[0] = strip[i];
                close3d[1] = strip[j];
            }
 
    return min;
}



float bruteForce3d(struct point3d P[], struct point3d close3d[], int n)
{
    float min = dist3d(close3d[0],close3d[1]);
    int i,j;
    for ( i = 0; i < n; ++i)
        for ( j = i+1; j < n; ++j)
            if (dist3d(P[i], P[j]) < min)
            {
                close3d[0] = P[i];
                close3d[1] = P[j];
                min = dist3d(P[i], P[j]);
            }
    return min;
}