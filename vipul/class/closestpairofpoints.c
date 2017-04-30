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
int cmp(const void *a,const void *b)
{
   int ax=((struct point *)a)->x;
   int bx=((struct point *)b)->x;
   return ax-bx;
}
float dis(struct point p1,struct point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
float merge(struct point arr[],int n,float delta)
{
	   struct point strip[n];
   int cnt=0,i,j;
   int mid=n/2;
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
   for(i=0;i<cnt;i++)
   {
   	for(j=i+1;j<cnt;j++)
   	{
   		if(dis(strip[i],strip[j])<ans&&abs(strip[i].y-strip[j].y)<delta)
   		{
   			ans=dis(strip[i],strip[j]);
   		}
   	}
   }
   return ans;
}
float cp(struct point arr[],int n)
{
   if(n<=3)
   {
   	int i,j;
   	float ans=FLT_MAX;
   	for(i=0;i<n;i++)
   	{
   		for(j=i+1;j<n;j++)
   		{
            if(dis(arr[i],arr[j])<ans)
            {
            	ans=dis(arr[i],arr[j]);
            }
   		}
   	}
   	return ans;
   }
   int i,mid;
   mid=n/2;
   struct point left[mid],right[n-mid];
   float dl,dr;
   for(i=0;i<mid;i++)
   {
   	left[i]=arr[i];
   }
   for(i=mid;i<n;i++)
   {
   	right[i-mid]=arr[i];
   }
   dl=cp(left,mid);
   dr=cp(right,n-mid);
   float delta=dl;
   if(dr<delta)
   {
   	delta=dr;
   }
   float ans=merge(arr,n,delta);
   if(delta<ans)
   {
   	ans=delta;
   }
   return ans;
}
int main()
{
	int i,n,x,y;
	srand(time(NULL)); 
	n=rand()%10+2;
   struct point arr[n+1];
	for(i=1;i<=n;i++)
	{
	    x=rand()%20;
	    y=rand()%20;
		arr[i-1].x=x;
		arr[i-1].y=y;
		printf("%d  %d\n",x,y);
	}
	qsort(arr,n,sizeof(struct point),cmp);
	printf("Min distance = %f\n",cp(arr,n));
	return 0;
}