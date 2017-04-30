#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void solve(float *,int);
float MatrixChain(int n,float p[],float operators[][n], float * expr);
void printBrackets(int i,int j, int n, int **bracket, float numbers[], float operators[][n], int *name, float * expr,int* flag);
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
	// for(i=0;i<2*n-1;i++)
	// {
	// 	printf("%f ",expr[i]);
	// }
	float operators[n][n];
	float numbers[n];
	for(i=0;i<n;i++)
	{
		numbers[i]= expr[2*i];
	}
	for(i=0;i<n;i++)
	{
		operators[i][i+1]=expr[2*(i)+1];
	}
	printf("=%f",MatrixChain(n,numbers,operators,expr));
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

float MatrixChain(int n,float p[],float operators[][n], float * expr)
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
		// printf("%f\n",m[i][i]);
	}
	for(l=2;l<=n;l++)
	{
		for(i=0;i<n-l+1;i++)
		{
			j = i +l-1;
			m[i][j]=INT_MIN;
			for(k=i;k<=j-1;k++)
			{
				q =  calculate(m[i][k],m[k+1][j],operators[k][k+1]);

				if(q>m[i][j])
				{
					m[i][j]=q;
					// printf("%f %d %d %d\n",q,i,j,k);
				// printf("%f %f %f %f\n",q,m[i][k],m[k+1][j],operators[k][k+1]);
					bracket[i][j]=k;
				}
			}
		}
	}
	 // The first matrix is printed as 'A', next as 'B',
    // and so on
    int name = 0;
    int flag=0;
    float ans = m[0][n-1];
    // printf("%d %d %d %d %d ", bracket[0][n-1],bracket[])
     printBrackets(0,n-1,n,bracket,p,operators,&name,expr,&flag);
	return ans;
}
int getOperator(float o)
{
	switch((int)o){
		case 0 :
			return '+';
		case 1:
			return '-';
		case 2: 
			return '*';
		case 3:
			return '/';
		default:
			return 0;
	}
}
void printBrackets(int i,int j, int n, int **bracket, float numbers[], float operators[][n], int *name, float* expr,int * flag)
{
	if (i==j)
	{		
		// if(i%2==1)
		//  printf("(%f %c %f)",numbers[i-1],getOperator(operators[i-1][i]),numbers[i]);
		// else
		//  printf("%c %f ",getOperator(operators[i-1][i]),numbers[i]);
		if(*flag)
			printf("%c",getOperator(operators[*name -1][*name]));
		printf("%f",numbers[*name]);
		*name = *name + 1;
		if(*flag)
		*flag = 0;
		else
			*flag=1;
		return;
	}
	if(*flag)
			printf("%c",getOperator(operators[*name -1][*name]));
			

	printf("(");
	*flag=0;
	printBrackets(i,bracket[i][j],n,bracket,numbers,operators,name, expr,flag);
	printBrackets(bracket[i][j]+1,j,n,bracket,numbers,operators,name, expr,flag);
	printf(")");
	*flag=1;

}
