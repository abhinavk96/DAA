#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
struct Point
{
	int x;
	int y;
	int z;
};

float dist(struct Point p1, struct Point p2)
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y) +
                 (p1.z - p2.z)*(p1.z - p2.z)
               );
}

int main()
{
	int n;
	scanf("%d", &n);
	struct Point p[n];
	for(int i = 0; i < n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		p[i].x = a;
		p[i].y = b;
		p[i].z = c;
	}
	float min_dist = FLT_MAX;
	struct Point close[2];
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(dist(p[i], p[j]) < min_dist)
			{
				min_dist = dist(p[i], p[j]);
				close[0] = p[i];
				close[1] = p[j];
			}
		}
	}
	printf("closest dist=%f\n", min_dist);
	for(int i = 0; i < 2; i++)
		printf("%d %d %d\n", close[i].x, close[i].y, close[i].z);
	return 0;
}