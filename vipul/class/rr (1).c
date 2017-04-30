#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct point2d {
  int x,y;
};

struct point3d {
  int x,y,z;
};
struct Edge
{
    //struct point2d a;
    //struct  point2d b;
    int a,b;
    float distt;
   
};
struct subset
{
    int parent;
    int rank;
};
 

int find(struct subset subsets[], int i)
{
   
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->distt > b1->distt;
}

























int cmp(const void *a,const void *b)
{
   int ax=((struct point2d *)a)->x;
   int bx=((struct point2d *)b)->x;
   return ax-bx;
}
void closestpair2d(struct point2d *,struct point2d *, int);
void closestpair3d(struct point3d *,struct point3d *,int);
void euclideanMST(struct point2d **,struct point2d *,int);
float dist(struct point2d p1,struct point2d p2)
{
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
float dist3d(struct point3d p1,struct point3d p2)
{
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
}
void merge(struct point2d *close2d, struct point2d *points, int n)
{
   struct point2d strip[n];
   int j,cnt=0,i,mid;
   mid=n/2;
   for(i=mid-1;i>=0;i--)
   {
       if(points[mid].x-points[i].x<=dist(close2d[0],close2d[1]))
       {
          strip[cnt++]=points[i];
       }
   }
   for(i=mid;i<n;i++)
   {
      
      if(points[i].x-points[mid].x<=dist(close2d[0],close2d[1]))
       {
          strip[cnt++]=points[i];
       }
   }
   float ans=dist(close2d[0],close2d[1]);
  
   
   for(i=0;i<cnt;i++)
   {
      for(j=i+1;j<cnt;j++)
      {
         if(dist(strip[i],strip[j])<ans)
         {
            close2d[0]=strip[i];
            close2d[1]=strip[j];
            ans=dist(close2d[0],close2d[1]);
            
         }
      }
   }
   
}
void cp(struct point2d *close2d, struct point2d *points, int n)
{
   if(n<=3)
   {
    int i,j;
      
    float ans=dist(close2d[0],close2d[1]);
     
    for(i=0;i<n;i++)
    {
      for(j=i+1;j<n;j++)
      {
            if(dist(points[i],points[j])<ans)
            {
               ans=dist(points[i],points[j]);
               close2d[0]=points[i];
               close2d[1]=points[j];
               
            }
      }
    }
    return;
   }
   int i,mid,j;
   mid=n/2;
   struct point2d left[mid],right[n-mid];
   
      for(i=0;i<mid;i++)
   {
    left[i]=points[i];
   }
   for(i=mid;i<n;i++)
   {
    right[i-mid]=points[i];
   }
   cp(close2d,left,mid);
   cp(close2d,right,n-mid);
  
   
   merge(close2d,points,n);
   
}



void merge3d(struct point3d *close3d, struct point3d *plane, int m)
{
   struct point3d strip[m];
   int j,cnt=0,i,mid;
   mid=m/2;
   for(i=mid-1;i>=0;i--)
   {
       if(plane[mid].x-plane[i].x<=dist3d(close3d[0],close3d[1]))
       {
          strip[cnt++]=plane[i];
       }
   }
   for(i=mid;i<m;i++)
   {
      
      if(plane[i].x-plane[mid].x<=dist3d(close3d[0],close3d[1]))
       {
          strip[cnt++]=plane[i];
       }
   }
   float ans=dist3d(close3d[0],close3d[1]);
  
   
   for(i=0;i<cnt;i++)
   {
      for(j=i+1;j<cnt;j++)
      {
         if(dist3d(strip[i],strip[j])<ans)
         {
            close3d[0]=strip[i];
            close3d[1]=strip[j];
            ans=dist3d(close3d[0],close3d[1]);
            
         }
      }
   }
   
}
void cp3d(struct point3d *close3d, struct point3d *plane, int m)
{
   if(m<=3)
   {
    int i,j;
      
    float ans=dist3d(close3d[0],close3d[1]);
     
    for(i=0;i<m;i++)
    {
      for(j=i+1;j<m;j++)
      {
            if(dist3d(plane[i],plane[j])<ans)
            {
               ans=dist3d(plane[i],plane[j]);
               close3d[0]=plane[i];
               close3d[1]=plane[j];
               
            }
      }
    }
    return;
   }
   int i,mid,j;
   mid=m/2;
   struct point3d left[mid],right[m-mid];
   
      for(i=0;i<mid;i++)
   {
    left[i]=plane[i];
   }
   for(i=mid;i<m;i++)
   {
    right[i-mid]=plane[i];
   }
   cp3d(close3d,left,mid);
   cp3d(close3d,right,m-mid);
  
   
   merge3d(close3d,plane,m);
   
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
  qsort(points,n,sizeof(struct point2d),cmp);
  close2d[0].x=9999;
  close2d[0].y=9999;
  close2d[1].x=0;
  close2d[1].y=0;
  close3d[0].x=9999;
  close3d[0].y=9999;
  close3d[0].z=9999;
  close3d[1].x=0;
  close3d[1].y=0;
  close3d[1].z=0;

//    closestpair2d(close2d,points,n);


  /*scanf("%d",&m);
  plane = (struct point3d *)malloc(m*sizeof(struct point3d));
  for(i=0;i<m;i++)
    scanf("%d%d%d",&(plane[i].x),&(plane[i].y),&(plane[i].z));
  closestpair2d(close2d,points,n);
  qsort(plane,m,sizeof(struct point3d),cmp);

 closestpair3d(close3d,plane,m);*/
  mst = (struct point2d **)malloc((n-1)*sizeof(struct point2d *));
  for(i=0;i<n;i++)
    mst[i]=(struct point2d *)malloc(2*sizeof(struct point2d));
  euclideanMST(mst,points,n);
  return 0;
}

void closestpair2d(struct point2d *close2d, struct point2d *points, int n)
{
    cp(close2d,points,n);
printf("Points of 2D are :");
  printf("%d %d and ",close2d[0].x,close2d[0].y);

    printf("%d %d \n",close2d[1].x,close2d[1].y);
    printf(" Distance is %0.5f\n",dist(close2d[0],close2d[1]));


}

void closestpair3d(struct point3d *close3d, struct point3d *plane,int m)
{
  cp3d(close3d,plane,m);
printf("Points of 3D are :");
  printf("%d %d %d and ",close3d[0].x,close3d[0].y,close3d[0].z);

    printf("%d %d %d \n",close3d[1].x,close3d[1].y,close3d[1].z);
    printf(" Distance is %0.6f\n",dist3d(close3d[0],close3d[1]));


}

void euclideanMST(struct point2d **mst,struct point2d *points,int n)
{
  

  int x=n*(n-1)/2;
  int i,j,k=0;
  struct  Edge ed[x+1];
  struct Edge result[n];

 
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      ed[k].a=i;
      ed[k].b=j;
      ed[k].distt=dist(points[i],points[j]);
      k++;
    }
  }
qsort(ed,k,sizeof(struct Edge),myComp);

struct subset *subsets =
        (struct subset*) malloc( n * sizeof(struct subset) );
int v;
for (v = 0; v < n; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    int e=0;
    i=0;
    int kk=0;
    for(i=0;i<x;i++)
    {	printf("while\n");
      struct Edge next_edge = ed[i];
      int x = find(subsets, next_edge.a);
        int y = find(subsets, next_edge.b);
        if(x!=y)
        {	printf("if\n");
        	result[kk++]=next_edge;
        	Union(subsets,x,y);
        }
        e++;
    }

    for(i=0;i<kk;i++)
    {
    	printf("%d %d %f\n",result[i].a,result[i].b,result[i].distt);
    }







}
