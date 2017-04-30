#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,i,s=0,r,t;
	scanf("%d %d",&a,&b);
	float g,h;
	g=sqrt(a);
	h=sqrt(b);
	r=(int)g;
	t=(int)h;
	if(a<b)
	{
		for(i=0;i<b;i++)
		{
			if(a%i==0&&b%i==0)
				s=s+1;
		}
	}
	else
	{
		for(i=0;i<a;i++)
		{
			if(a%i==0&&b%i==0)
				s=s+1;
		}
	}
}

