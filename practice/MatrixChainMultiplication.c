#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int MatrixChain(int *p, int n);
void printBrackets(int i,int j, int n, int **bracket, char* name);

int main()
{
	int n,i,X;
	scanf("%d",&n);
	int *p = (int*)malloc(sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	X=MatrixChain(p,n);
	printf("%d\n",X);
}

int MatrixChain(int *p, int n)
{
	int m[n+1][n+1];
	int i,j,l,k,q;
	int** bracket=(int **)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		bracket[i] = (int*)malloc(n*sizeof(int));
	}
	// int bracket [n][n];
	for(i=1;i<n;i++)
	{
		m[i][i] = 0;
	}
	for(l=2;l<n;l++)
	{
		for(i=1;i<n-l+1;i++)
		{
			j = i +l-1;
			m[i][j]=INT_MAX;
			for(k=i;k<=j-1;k++)
			{
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(q<m[i][j])
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
    int ans = m[1][n-1];
    printBrackets(1,n-1,n,bracket,&name);
	return ans;
}

void printBrackets(int i,int j, int n, int **bracket, char *name)
{
	if (i==j)
	{
		printf("%c",*name);
		*name = *name +1;
		return;
	}
	printf("(");
	printBrackets(i,bracket[i][j],n,bracket,name);
	printBrackets(bracket[i][j]+1,j,n,bracket,name);
	printf(")");

}
