#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void solve(float *,int);
float MatrixChain(int n,float p[],float operators[][n]);
int main()
{
  int i,n,m;
  float num,operator,*expr;
  char *par_expr;
  scanf("%d",&n);  /* Enter how many numbers are there in the expression */
  expr = (float *)malloc(((2*n)-1)*sizeof(float)); /* n numbers and n-1 operators */
  scanf("%f",&expr[0]);  /* first number */
  for(i=1;i<2*n-1;i=i+2) {
    scanf("%f",&expr[i]); /* operator */
    scanf("%f",&expr[i+1]); /* Number */
  }
  solve(expr,n);
  return 0;
}

void solve(float *expr, int n)
{
  /* solve the puzzle and use printf to print the parenthesized expression and result to screen */
	int i =0;
	for(i=0;i<2*n-1;i++)
	{
		printf("%f ",expr[i]);
	}
	float operators[n][n];
	float numbers[n];
	for(i=0;i<n;i+=2)
	{
		numbers[i]= expr[i];
	}
	for(i=1;i<n;i+=2)
	{
		operators[i-1][i+1]=expr[i];
	}
	printf("%f",MatrixChain(n,numbers,operators));
}
float calculate(float a, float b, float o)
{
	if ((int)o==0)
		return a+b;
	else if((int)o==1)
		return a-b;
	else if((int)o==2)
		return a*b;
	else
		return a/b;
}

float MatrixChain(int n,float p[],float operators[][n])
{
	float m[n+1][n+1];
	int i,j,l,k;
	float q;
	int** bracket=(int **)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		bracket[i] = (int*)malloc(n*sizeof(int));
	}
	// int bracket [n][n];
	for(i=0;i<n;i++)
	{
		m[i][i] = p[i];
	}
	for(l=2;l<n;l++)
	{
		for(i=1;i<n-l+1;i++)
		{
			j = i +l-1;
			m[i][j]=INT_MIN;
			for(k=i;k<=j-1;k++)
			{
				q = m[i][k] + m[k+1][j] + calculate(m[i][k],m[k+1][j],operators[k][k+1]);
				if(q>m[i][j])
				{
					m[i][j]=q;
					bracket[i][j]=k;
				}
			}
		}
	}
	 // The first matrix is printed as 'A', next as 'B',
    // and so on
    char name = 'A';
    float ans = m[1][n-1];
    // printBrackets(1,n-1,n,bracket,&name);
	return ans;
}