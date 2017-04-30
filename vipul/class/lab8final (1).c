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
struct edge 
  {
    struct point2d a;
    struct point2d b;
    int u;
    int v;
    float dis;
  };
void closestpair2d(struct point2d *,struct point2d *, int);
void closestpair3d(struct point3d *,struct point3d *,int);
void euclideanMST(struct point2d **,struct point2d *,int);
int cmp(const void *a,const void *b)
{
  int ax=((struct point2d *)a)->x;
  int bx=((struct point2d *)b)->x;
  return ax-bx;
}
int cmpp(const void *a,const void *b)
{
  float ax=((struct edge *)a)->dis;
  float bx=((struct edge *)b)->dis;
  if(ax>bx)
  {
  	return 1;
  }
  else if(ax<bx)
  {
  	return -1;
  }
  else
  {
  	return 0;
  }
}
float dis(struct point2d a,struct point2d b)
{
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
float dist3d(struct point3d a,struct point3d b)
{
  return (sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z)));
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
void merge(struct point2d arr[],int n,struct point2d *cp,float delta)
{
  struct point2d strip[n];
   int j,cnt=0,i,mid;
   mid=n/2;
   for(i=mid-1;i>=0;i--)
   {
       if(arr[mid].x-arr[i].x<=delta)
       {
          strip[cnt++]=arr[i];
       }
   }
   for(i=mid;i<n;i++)
   {
      if(arr[i].x-arr[mid].x<=delta)
      {
         strip[cnt++]=arr[i];
      }
   }
   float ans=FLT_MAX;
   cp[0].x=10000;
   cp[0].y=10000;
   cp[1].x=0;
   cp[1].y=0;
   for(i=0;i<cnt;i++)
   {
      for(j=i+1;j<cnt;j++)
      {
         if(dis(strip[i],strip[j])<ans)
         {
            cp[0]=strip[i];
            cp[1]=strip[j];
            ans=dis(strip[i],strip[j]);
         }
      }
   }
}
void closestpair(struct point2d arr[],int n,struct point2d *cp)
{
  int i,j;
  if(n<=3)
  {
     float ans=FLT_MAX;
     for(i=0;i<n;i++)
     {
      for(j=i+1;j<n;j++)
      {
        if(dis(arr[i],arr[j])<ans)
        {
          ans=dis(arr[i],arr[j]);
          cp[0]=arr[i];
          cp[1]=arr[j];
        }
      }
     }
     return;
  }
  int mid=n/2;
  struct point2d left[mid],right[n-mid];
  for(i=0;i<mid;i++)
  {
    left[i]=arr[i];
  }
  for(i=mid;i<n;i++)
  {
    right[i-mid]=arr[i];
  }
  struct point2d cl[2],cr[2];
  closestpair(left,mid,cl);
  closestpair(right,n-mid,cr);
  float delta,dl,dr;
  dl=dis(cl[0],cl[1]);
  dr=dis(cr[0],cr[1]);
  delta=dl;
  if(delta>dr)
  {
    delta=dr;
  }
  struct point2d cstr[2];
  merge(arr,n,cstr,delta);
  float ans=dis(cstr[0],cstr[1]);
  if(dl<=dr&&dl<=ans)
  {
    cp[0]=cl[0];
    cp[1]=cl[1];
  }
  else if(dr<=dl&&dr<=ans)
  {
    cp[0]=cr[0];
    cp[1]=cr[1];
  }
  else
  {
    cp[0]=cstr[0];
    cp[1]=cstr[1];
  }
}
void merge3(struct point3d arr[],int n,struct point3d *cp,float delta)
{
  struct point3d strip[n];
   int j,cnt=0,i,mid;
   mid=n/2;
   for(i=mid-1;i>=0;i--)
   {
       if(arr[mid].x-arr[i].x<=delta)
       {
          strip[cnt++]=arr[i];
       }
   }
   for(i=mid;i<n;i++)
   {
      if(arr[i].x-arr[mid].x<=delta)
      {
         strip[cnt++]=arr[i];
      }
   }
   float ans=FLT_MAX;
   cp[0].x=10000;
   cp[0].y=10000;
   cp[1].x=0;
   cp[1].y=0;
   for(i=0;i<cnt;i++)
   {
      for(j=i+1;j<cnt;j++)
      {
         if(dist3d(strip[i],strip[j])<ans)
         {
            cp[0]=strip[i];
            cp[1]=strip[j];
            ans=dist3d(strip[i],strip[j]);
         }
      }
   }
}
void closestpair3(struct point3d arr[],int n,struct point3d *cp)
{
  int i,j;
  if(n<=3)
  {
     float ans=FLT_MAX;
     for(i=0;i<n;i++)
     {
      for(j=i+1;j<n;j++)
      {
        if(dist3d(arr[i],arr[j])<ans)
        {
          ans=dist3d(arr[i],arr[j]);
          cp[0]=arr[i];
          cp[1]=arr[j];
        }
      }
     }
     return;
  }
  int mid=n/2;
  struct point3d left[mid],right[n-mid];
  for(i=0;i<mid;i++)
  {
    left[i]=arr[i];
  }
  for(i=mid;i<n;i++)
  {
    right[i-mid]=arr[i];
  }
  struct point3d cl[2],cr[2];
  closestpair3(left,mid,cl);
  closestpair3(right,n-mid,cr);
  float delta,dl,dr;
  dl=dist3d(cl[0],cl[1]);
  dr=dist3d(cr[0],cr[1]);
  delta=dl;
  if(delta>dr)
  {
    delta=dr;
  }
  struct point3d cstr[2];
  merge3(arr,n,cstr,delta);
  float ans=dist3d(cstr[0],cstr[1]);
  if(dl<=dr&&dl<=ans)
  {
    cp[0]=cl[0];
    cp[1]=cl[1];
  }
  else if(dr<=dl&&dr<=ans)
  {
    cp[0]=cr[0];
    cp[1]=cr[1];
  }
  else
  {
    cp[0]=cstr[0];
    cp[1]=cstr[1];
  }
}
void closestpair2d(struct point2d *close2d, struct point2d *points, int n)
{

  /* find out the closest pair of points among the points in "points" and store them in the array close2d */
   qsort(points,n,sizeof(struct point2d),cmp);
   int i;
   closestpair(points,n,close2d);
  // printf("%d %d %d %d %f\n",close2d[0].x,close2d[0].y,close2d[1].x,close2d[1].y,dis(close2d[0],close2d[1]));
}
void closestpair3d(struct point3d *close3d, struct point3d *plane,int m)
{

  /* find out the closest pair of points among the points in "plane" and store them in the array close3d */
   qsort(plane,m,sizeof(struct point3d),cmp);
   int i;
   closestpair3(plane,m,close3d);
  // printf("%d %d %d %d %d %d %f\n",close3d[0].x,close3d[0].y,close3d[0].z,close3d[1].x,close3d[1].y,close3d[1].z,dist3d(close3d[0],close3d[1]));
}
int fp(int *par,int u)
{
  if(par[u]==u)
  {
    return u;
  }
  else
  {
    return par[u]=fp(par,par[u]);
  }
}
void uni(int *par,int u,int v)
{
    int pu,pv;
    pu=fp(par,u);
    pv=fp(par,v);
    if(pu!=pv)
    {
      par[pu]=pv;
    }
}
void euclideanMST(struct point2d **mst,struct point2d *points,int n)
{
   /*find out the Euclidean MST and store the MST in 2d-array mst.
     Each of the n-1 edges are store by storing it's two endpoints.*/
  
  int num=n*(n-1);
  num/=2;
  struct edge arr[num];
  int i,j,ct=0;
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
       arr[ct].a=points[i];
       arr[ct].b=points[j];
       arr[ct].dis=dis(points[i],points[j]);
       arr[ct].u=i;
       arr[ct].v=j;
       ct++;
    }
  }
  qsort(arr,num,sizeof(struct edge),cmpp);
  int *par;
  par=(int *)malloc((n)*sizeof(int));
  for(i=0;i<n;i++)
  {
    par[i]=i;
  }
  int cnt=0,pu,pv,u,v;
  for(i=0;i<num;i++)
  {
  	printf("%d %d %d %d %f\n",arr[i].a.x,arr[i].a.y,arr[i].b.x,arr[i].b.y,arr[i].dis);
    u=arr[i].u;
    v=arr[i].v;
    pu=fp(par,u);
    pv=fp(par,v);
    if(pu!=pv)
    {
      uni(par,arr[i].u,arr[i].v);
      mst[cnt][0].x=arr[i].a.x;
      mst[cnt][0].y=arr[i].a.y;
      mst[cnt][1].x=arr[i].b.x;
      mst[cnt][1].y=arr[i].b.y;
      cnt++;
    }
  }
  printf("MST\n");
  for(i=0;i<n-1;i++)
  {
  	printf("%d %d %d %d\n",mst[i][0].x,mst[i][0].y,mst[i][1].x,mst[i][1].y);
  }
}
