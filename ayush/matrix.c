#include <stdio.h>
#include <limits.h>

int matrixchain(int n, int p[], int m[][n], int s[][n])
{
	int i;
	for(i = 1; i <= n; i++) {
		m[i][i] = 0;
	}
	int L;
	int j;
	int q;
	int k;
	for(L = 2; L <= n; L++) {
		for(i = 1; i <= n - L + 1; i++) {
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for(k = i; k < j; k++) {
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if(q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	return m[1][n];
}

void printmatrix(int n, int s[][n], int i, int j)
{
	if(i == j){
		printf("A%d",i);
	}
	else {
		printf("(");
		printmatrix(n,s,i,s[i][j]);
		printmatrix(n,s,s[i][j] + 1, j);
		printf(")");
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int s[n + 1][n + 1], m[n + 1][n + 1];
	int p[n + 1];
	int i;
	for(i = 0; i <= n; i++) {
		scanf("%d",&p[i]);
	}
	int ans = matrixchain(n, p, m, s);
	printf("%d\n",ans);
	printmatrix(n, s, 1, n);
	return 0;
}