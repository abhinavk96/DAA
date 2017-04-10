
#include <stdio.h>
#include <stdlib.h>
float operator(float o, float a, float b );
void solve(float *,int);
struct vector evaluateAll(float * expr, int low, int high);
struct vector
{
	int n;
	float expr[1000];
};
int main()
{
  int i,n,m;
  float num,operator,*expr;
  char *par_expr;
  scanf("%d",&n);  /* Enter how many numbers are there in the expression */
  expr = (float *)malloc(((2*n)-1)*sizeof(float)); /* n numbers and n-1 operators */
  for(i=0;i<(2*n-1);i++) {
    scanf("%f",&expr[i]); 
    
  }
  solve(expr,n);
  return 0;
}
struct vector evaluateAll(float * expr, int low, int high)
{
	struct vector  result;
	int c = 0,i,j,s1,s2;
	if (low==high)
	{
		result.expr[c++] = expr[low];
		result.n = c;
		return result;
	}
	if (low==high-2)
	{
		int temp = operator(expr[low+1], expr[low], expr[low+2]);
		result.expr[c++] = temp;
		// printf("%d\t",temp);
		result.n = c;
		return result;
	}
	for(i=low+1;i<=high;i+=2)
	{
		struct vector l = evaluateAll(expr, low, i-1);
		struct vector r = evaluateAll(expr,i+1, high);
		for (s1=0;s1<l.n;s1++)
		{
			for(s2=0;s2<r.n;s2++)
			{
				int val = operator(expr[i],l.expr[s1],r.expr[s2]);
				result.expr[c++] = val;
				result.n = c;
			}
		}
	}
	return result;
}

float max(float a, float b)
{
	return a>b?a:b;
}
void solve(float *expr, int n)
{
	int operators[n],i;
	struct vector answer = evaluateAll(expr,0,2*n-2);
	float m = answer.expr[0];

	for(i=0;i<answer.n;i++)
	{
		if (answer.expr[i]>m)
			m = answer.expr[i];
		// printf("%f\n", answer.expr[i]);
	}
	printf("%f\n",m);
  /* solve the puzzle and use printf to print the parenthesized expression and result to screen */
}

float operator(float o, float a, float b )
{
	if((int)o==0)
	{

	}
	else if ((int)o == 1)
	{
		return a+b;
	}
	else if ((int)o == 2)
	{
		return a-b;
	}
	else if ((int)o == 3)
	{
		return a*b;
	}
	else if ((int)o == 4)
	{
		return a/b;
	}
	else
	{
		return 0.0;
	}
}