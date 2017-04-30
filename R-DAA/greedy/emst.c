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
float brute(struct Point p[], int n, float calc, struct Point close[])
{
	int i, j;
	float min = dist(close[0], close[1]);
	for(i = 0; i < n; i++)
	{
		for(j = i+1; j < n; j++)
		{
			if(((dist(p[i],p[j]))<min)&&(dist(p[i],p[j])>calc))
			{
				min = dist(p[i], p[j]);
				close[0] = p[i];
				close[1] = p[j];
			}
		}
	}
	return min;
}
float findd(struct Point strip[], int n, float d, float calc, struct Point close[])
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
			{
				min = dist(strip[i],strip[j]);
				close[0] = strip[i];
				close[1] = strip[j];
			}
		}
	}
	return min;
}
float find(struct Point p[], int n,float calc, struct Point close[])
{
	int i;
	if(n <= 3)
		return brute(p, n, calc, close);
	float dl, dr, d;
	int mid = n/2;
	dl = find(p, mid, calc, close);
	dr = find(p+mid, n-mid, calc, close);
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
	float dd = findd(strip, j, d, calc, close);
	if(dd < d)
		return dd;
	else
		return d;

}
float closest(struct Point p[], int n, float d[],struct Point close[], int k, struct Point store[][100])
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
	j = 0;
	for(i = 0; i < n*(n-1); i++)
	{
		close[0].x = 0;
		close[0].y = 0;
		close[1].x = 9999;
		close[1].y = 9999;
		d[i] = find(p, n, d[i-1],close);
		if(close[0].x == 0 && close[1].x == 9999)
			break;
		store[j][0] = close[0];

		store[j][1] = close[1];
		j++;
	}
/*	for(i = 0; i <j ;i++)
		printf("%d %d\n",store[i][0].x,store[i][1].x);*/
	store[j][0].x = 9999;

}
int find1(int parent[100], int x)
{
	if(parent[x] != x)
		parent[x] = find1(parent, parent[x]);
	return parent[x];
}
void unionn(int parent[], int rank[], int x, int y)
{
	int p, q;
	p = find1(parent, x);
	q = find1(parent, y);
	if(p == q)
		return;
	if (rank[p] < rank[q]) {
		parent[p] = q;
	}
	else if (rank[p] > rank[q]) {
		parent[q] = p;
	}
	else {
		parent[q] = p;
		rank[p]++;
	} 
}
int getid(struct Point p[], int x, int y, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(p[i].x == x && p[i].y == y)
			return i;
	}
}
void euclimst(struct Point store[][100], struct Point p[], int n)
{
	
	struct Point mst[100][3];
	int parent[100] ,rank[100];
	int total = 0;
	int i = 0;
	while(store[i][0].x != 9999)
	{
		total = total+1;
		i = i + 1;
	}	
	int join[100][3];
//	printf("%d\n",total);
	for(i = 0;i < total; i++)
	{
		join[i][0] = getid(p, store[i][0].x, store[i][0].y, n);	
		join[i][1] = getid(p, store[i][1].x, store[i][1].y, n);
	}	
	for(i = 0; i < total; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
	int result[100][3];
	int a = 0;
	int b = 0;
	int p1, p2;
	while(a < n-1)
	{
		p1 = find1(parent, join[b][0]);
		p2 = find1(parent, join[b][1]);
		if(p1 != p2)
		{
			result[a][0] = join[b][0];
			result[a][1] = join[b][1];
			a = a + 1;
			unionn(parent, rank, p1, p2);
		}
		b = b + 1;
	}
	for(i = 0; i < a; i++)
	{
		mst[i][0] = p[result[i][0]];
		mst[i][1] = p[result[i][1]];
	}
	for(i = 0; i < a; i++)
	{
		printf("(%d %d)  (%d %d)\n",mst[i][0].x,mst[i][0].y,mst[i][1].x,mst[i][1].y);
	}
}
int main()
{
	struct Point store[100][100];
	struct Point close[2];
	struct Point p[100];
	int  n, i, k;
	float d[100];
	scanf("%d",&n);
	for(i = 0; i < n; i++)
		scanf("%d %d",&p[i].x,&p[i].y);

	closest(p, n, d, close, k, store);
	euclimst(store, p, n);
	return 0;
}
