#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float cube(float n)
{
	float start = 0;
	float end = n;
	float e = 0.0001;
	while(1)
	{
		float mid = (start+end)/2;
		float error;
		error = (abs(n - (mid*mid*mid)));
		if(error <= e)
			return mid;
		if((mid*mid*mid)>n)
			end = mid;
		else
			start = mid;
	}
}
int main()
{
	float n;
	float c;
	scanf("%f",&n);
	c = cube(n);
	printf("%f",c);
}
