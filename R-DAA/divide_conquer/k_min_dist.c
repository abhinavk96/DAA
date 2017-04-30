#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Point
{
	int x;
	int y;
};
float dist(struct Point p1, struct Point p2)
{
	float r;
	r = sqrt(((p1.x-p2.x)*(p1.x-p2.x))+((p1.y-p2.y)*(p1.y-p2.y)));
	return r;
}
float brute(struct Point p[], int n, float calc)
{
	printf("%f\n",calc);
	int i, j;
	float min = 9999.99;
	for(i = 0; i < n; i++)
	{
		for(j = i+1; j < n; j++)
		{
			if(((dist(p[i],p[j]))<min)&&((dist(p[i],p[j]))>calc))
				min = dist(p[i], p[j]);
		}
	}
	printf("%f\n",min);
	return min;
}
float findd(struct Point strip[], int n, float d, float calc)
{
	float min = d;
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n-1; j++)
		{
			if(strip[j].y > strip[j+1].y)
			{
				struct Point tmp;
				tmp = strip[j];
				strip[j] = strip[j+1];
				strip[j+1] = tmp;
			}
		}
	}
	for(i = 0; i < n; i++)
	{
		for(j = i+1; j < n && (strip[j].y - strip[i].y)<min; j++)
		{
			if((dist(strip[i],strip[j])<min)&&(dist(strip[i],strip[j])>calc))
				min = dist(strip[i],strip[j]);
		}
	}
	return min;
}
float find(struct Point p[], int n,float calc)
{
	int i;
	if(n <= 3)
		return brute(p, n, calc);
	float dl, dr, d;
	int mid = n/2;
	dl = find(p, mid, calc);
	dr = find(p+mid, n-mid, calc);
	if(dl < dr)
		d=dl;
	else
		d=dr;
	struct Point strip[n];
	int j = 0;
	for(i = 0; i < n; i++)
	{
		if((abs(p[i].x - p[mid].x)) < d)
		{
			strip[j] = p[i];
			j = j +1;
		}
	}
	float dd = findd(strip, j, d, calc);
	if(dd < d)
		return dd;
	else
		return d;

}
float closest(struct Point p[], int n, float d[],int which, int k)
{
	int i, j;
	struct Point tmp;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n-1; j++)
		{
			if(p[j].x > p[j+1].x)
			{
				tmp = p[j];
				p[j] = p[j+1];
				p[j+1] = tmp;
			}
		}
	}
	d[0] = 0.0;
	for(i = 1; i <= k; i++)
	{	
		 d[i] = find(p, n, d[i-1]);
		printf("%f\n",d[i]);
	}
}
int main()
{
	struct Point p[100];
	int  n, i, k;
	float d[100];
	scanf("%d",&n);
	for(i = 0; i < n; i++)
		scanf("%d %d",&p[i].x,&p[i].y);
	scanf("%d",&k);
	
	closest(p, n, d, i, k);
	
	for(i = 1; i <= k; i++)
		printf("%f\n",d[i]);
	return 0;
}
