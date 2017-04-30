#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Point
{
	int x;
	int y;
};
float brute(struct Point P[], int n)
{
	int i, j;
	float min = 9999.99;
	for(i = 0; i < n; i++)
	{
		for(j = i+1; j < n; j++)
		{
			float dist;
			dist = sqrt(((P[i].x-P[j].x)*(P[i].x-P[j].x))+((P[i].y-P[j].y)*(P[i].y-P[j].y)));
			if(dist < min)
				min  = dist;
		}
	}
	return min;
}
float stripd(struct Point strip[], int n, float d)
{
	float min = d;
	struct Point tmp;
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n-1; j++)
		{
			if(strip[j].y > strip[j+1].y)
			{
				tmp = strip[j];
				strip[j] = strip[j+1];
				strip[j+1] = tmp;
			}
		}
	}
	for(i = 0; i < n; i++)
	{
		for(j = i+1; j < n && (strip[j].y - strip[i].y)<min;j++)
		{
			float dd;
			dd = sqrt(((strip[i].x-strip[j].x)*(strip[i].x-strip[j].x))+((strip[i].y-strip[j].y)*(strip[i].y-strip[j].y)));
			if(dd < min)
				min = dd;
		}
	}
	return min;
}
float find_closest(struct Point P[], int n)
{
	float d, r;
	if(n <= 3)
	{
		r =  brute(P, n);
		return  r;
	}
	int mid = n/2;
	float dl = find_closest(P, mid);
	float dr = find_closest(P + mid, n - mid);
	if(dl < dr)
		d = dl;
	else 
		d = dr;
	struct Point strip[n];
	int j = 0, i;
	for(i = 0; i < n; i++)
	{
		if(abs(P[i].x - P[mid].x) < d)
		{
			strip[j] = P[i];
			j = j + 1;
		}
	}
	float d1 = stripd(strip, j, d);
	if(d < d1)
		return d;
	else
		return d1;

}
float closest(struct Point p[], int n)
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
	float f;
	f = find_closest(p, n);
	return f;

}
int main()
{
	struct Point p[100];
	int i, n;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%d %d",&p[i].x,&p[i].y);
	}
	
	float d;
	d = closest(p, n);
	printf("%f",d);
	return 0;
}
