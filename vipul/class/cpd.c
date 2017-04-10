#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>
struct point
{
	int x;
	int y;
};
struct cpd
{
  struct point a;
  struct point b;
  float dis;
};
int cmp(const void *a,const void *b)
{
   int ax=((struct point *)a)->x;
   int bx=((struct point *)b)->x;
   return ax-bx;
}
float dist(struct point p1,struct point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
struct cpd merge(struct point arr[],int n,float delta)
{
   struct point strip[n];
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
   struct cpd cstr;
   cstr.dis=ans;
   for(i=0;i<cnt;i++)
   {
      for(j=i+1;j<cnt;j++)
      {
         if(dist(strip[i],strip[j])<ans)
         {
            cstr.a=strip[i];
            cstr.b=strip[j];
            ans=dist(strip[i],strip[j]);
            cstr.dis=ans;
         }
      }
   }
   return cstr;   
}
struct cpd cp(struct point arr[],int n)
{
   if(n<=3)
   {
   	int i,j;
      struct cpd pt;
   	float ans=FLT_MAX;
      pt.dis=FLT_MAX;
   	for(i=0;i<n;i++)
   	{
   		for(j=i+1;j<n;j++)
   		{
            if(dist(arr[i],arr[j])<ans)
            {
               ans=dist(arr[i],arr[j]);
               pt.a=arr[i];
               pt.b=arr[j];
               pt.dis=ans;
            }
   		}
   	}
   	return pt;
   }
   int i,mid,j;
   mid=n/2;
   struct point left[mid],right[n-mid];
   float dl,dr;
   struct cpd cl,cr;
   for(i=0;i<mid;i++)
   {
   	left[i]=arr[i];
   }
   for(i=mid;i<n;i++)
   {
   	right[i-mid]=arr[i];
   }
   cl=cp(left,mid);
   cr=cp(right,n-mid);
   dl=cl.dis;
   dr=cr.dis;
   float delta=dl;
   if(dr<delta)
   {
   	delta=dr;
   }
   struct cpd cstr=merge(arr,n,delta);
   float ans=cstr.dis;
   if(dl<=dr&&dl<=ans)
   {
      return cl;
   }
   else if(dr<=dl&&dr<=ans)
   {
     return cr;
   }
   else
   {
   return cstr;
   }
}
int main()
{
	int i,n,x,y;
	srand(time(NULL)); 
	//scanf("%d",&n);
   n=rand()%10+2;
   //n=11;
   struct point arr[n+1];
   for(i=1;i<=n;i++)
	{
      //scanf("%d%d",&x,&y);
	    x=rand()%20;
	    y=rand()%20;
       arr[i-1].x=x;
       arr[i-1].y=y;
		printf("%d  %d\n",arr[i-1].x,arr[i-1].y);
	}
	qsort(arr,n,sizeof(struct point),cmp);
   struct cpd ans=cp(arr,n);
	printf("Min distance b/w  %d,%d  and  %d,%d   = %f\n",(ans.a).x,(ans.a).y,(ans.b).x,(ans.b).y,ans.dis);
	return 0;
}