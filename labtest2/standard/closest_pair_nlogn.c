#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
struct Point
{
	int x;
	int y;
};
int cmpX(const void* p1, const void* p2)
{
	struct Point *a, *b;
	a = (struct Point*) p1;
	b = (struct Point*) p2;
	return (a->x - b->x);
}
int cmpY(const void* p1, const void* p2)
{
	struct Point *a, *b;
	a = (struct Point*) p1;
	b = (struct Point*) p2;
	return (a->y - b->y);
}
float dist(struct Point p1, struct Point p2)
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}
float min(float a, float b)
{
	return (a < b)? a : b;
}
float base_case(struct Point p[], int n)
{
	float min_dist = FLT_MAX;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(dist(p[i], p[j]) < min_dist)
				min_dist = dist(p[i], p[j]);
	return min_dist;
}
float strip_min_dist(struct Point s_p[], int n, float d)
{
	float min_dist = d;
	//qsort(s_p, n, sizeof(struct Point), cmpY);

	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n && (s_p[j].y - s_p[i].y) < min_dist; ++j)
			if(dist(s_p[j], s_p[i]) < min_dist)
				min_dist = dist(s_p[i], s_p[j]);
	return min_dist;
}
float divide_and_conquer(struct Point px[], struct Point py[], int n)
{
	if(n <= 3)
		return base_case(py, n);
	int mid = n / 2;
	struct Point midp = px[mid];

	struct Point py_left[mid+1];
	struct Point py_right[n-(mid+1)];
	int left_ind, right_ind;
	left_ind = right_ind = 0;
	for(int i = 0; i < n; i++)
	{
		if(py[i].x <= midp.x)
			py_left[left_ind++] = py[i];
		else
			py_right[right_ind++] = py[i];
	}

	float dist_left = divide_and_conquer(px, py_left, mid);
	float dist_right = divide_and_conquer(px + mid, py_right, n - mid);

	float d = min(dist_left, dist_right);

	struct Point s_p[n];
	int k = 0;
	for(int i = 0; i < n; i++)
		if(abs(py[i].x - midp.x) < d)
			s_p[k++] = py[i];
	return min(d, strip_min_dist(s_p, k, d));
}
float closest_dist(struct Point p[], int n)
{
	struct Point px[n], py[n];
	for(int i = 0; i < n; i++)
		px[i] = py[i] = p[i];
	qsort(px, n, sizeof(struct Point), cmpX);
	qsort(py, n, sizeof(struct Point), cmpY);
	return divide_and_conquer(px, py, n);
}
int main()
{
	int n;
	scanf("%d", &n);
	struct Point p[n];
	for(int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		p[i].x = a;
		p[i].y = b;
	}
	printf("The smallest distance is %f\n", closest_dist(p, n));
	return 0;
}