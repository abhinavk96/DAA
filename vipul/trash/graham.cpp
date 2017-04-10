#include <bits/stdc++.h>
using namespace std;
struct point
{
	int x;
	int y;
};
struct point P0;
float dis(struct point a,struct point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));	
}
int ck_ack_cl(struct point p0,struct point p1,struct point p2)
{
	int v;
	v=(p2.x-p0.x)*(p1.y-p0.y)-(p1.x-p0.x)*(p2.y-p0.y);
	if(v==0)
	{
		return 0;
	}
	else if(v<0)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
int cmp(const void *a,const void *b)
{
	struct point p1=*((struct point *)a);
	struct point p2=*((struct point *)b);
   int v=ck_ack_cl(P0,p1,p2);
   if(v==0)
   {
   	if(dis(P0,p1)<dis(P0,p2))
   	{
   		return -1;
   	}
   	else
   	{
   		return 1;
   	}
   }
   else
   {
   	return v;
   }
}
int main()
{
	int n;
	int i,x,y,mny,mnx,p;
	scanf("%d",&n);
	struct point arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		arr[i].x=x;
		arr[i].y=y;
		if(i==0)
		{
			p=i;
			mny=y;
			mnx=x;
		}
		else if(y<mny)
		{
			p=i;
			mny=y;
			mnx=x;
		}
		else if(y==mny&&x<mnx)
		{
			p=i;
			mnx=x;
		}
	}
	struct point tmp;
	tmp=arr[0];
	arr[0]=arr[p];
	arr[p]=tmp;
	P0=arr[0];
    qsort(arr+1,n-1,sizeof(struct point),cmp);
    stack <struct point> s;
    int m=1;
    for(i=0;i<n;i++)
    {
    //	cout<<arr[i].x<<" "<<arr[i].y<<endl;
    }
    for(i=1;i<n;i++)
    {
    	while(i<n-1&&ck_ack_cl(P0,arr[i],arr[i+1])==0)
    	{
    		i++;
    	}
    	arr[m]=arr[i];
    	m++;
    }
    if(m<3)
    {
      return 0;
    }
    s.push(arr[0]);
    s.push(arr[1]);
    s.push(arr[2]);
  //  cout<<m<<endl;
  for(i=1;i<m;i++)
  {
  //	cout<<arr[i].x<<" "<<arr[i].y<<endl;
  }
    for(i=3;i<m;i++)
    {
    	struct point u,v,w;
        v=s.top();
    	s.pop();
    	u=s.top();
    	s.push(v);
    	w=arr[i];
    	while(ck_ack_cl(u,v,w)!=-1)
    	{
    		s.pop();
        v=s.top();
    	s.pop();
    	u=s.top();
    	s.push(v);
    	w=arr[i];
    		//s.pop();
    	}
    	s.push(arr[i]);
    }
    cout<<"Hull\n";
    while(!s.empty())
    {
    	cout<<s.top().x<<" "<<s.top().y<<endl;
    	s.pop();
    }
	return 0;
}