#include <stdio.h>
#include <string.h>

int lcs(char x[100], char y[100], char b[][100], int c[][100], int m, int n)
{
	int i, j;
	for(i = 0; i <= m; i++) 
		c[i][0] = 0;
	for(j = 0; j <= n; j++)
		c[0][j] = 0;
	for(i = 1; i <= m; i++) {
		for(j = 1; j <= n; j++) {
			if(x[i - 1] == y[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 'd';
			}
			else if(c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = 'u';
			}
			else {
				c[i][j] = c[i][j - 1];
				b[i][j] = 'l';
			}
		}
	}
	return c[m][n];
}

void printlcs(char b[][100], char x[100], int i, int j)
{
	if ( i == 0 || j == 0) 
		return;
	if(b[i][j] == 'd') {
		printlcs(b, x, i - 1, j - 1);
		printf("%c",x[i - 1]);
	}
	else if(b[i][j] == 'u')
		printlcs(b, x, i - 1, j);
	else
		printlcs(b, x , i, j - 1);
}

int main()
{
	char x[100];
	char y[100];
	int c[100][100];
	char b[100][100];
	char ch;
	int i, j;
	scanf("%s",x);
	scanf("%s",y);
	int m = strlen(x);
	int n = strlen(y);
	/*for(i = m; i > 0; i--) {
		x[i] = x[i - 1];
	}
	for(i = n; i > 0; i--) {
		y[i] = y[i - 1];
	}
	*/
	//printf("%s\n%s\n", x, y);
	for(i = 0; i <= 100; i++) {
		for(j = 0; j <= 100; j++)
			b[i][j] = 'x';
	}
	int len = lcs(x, y, b, c, m, n);
	printf("%d\n",len);
	printlcs(b, x, m, n);
	return 0;
}