#include <stdio.h>
#include <stdlib.h>
int LCS(char* X, char* Y, int n, int m);
int max(int a, int b);
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	char *X = (char*)malloc(n*sizeof(char));
	char *Y = (char*)malloc(m*sizeof(char));
	scanf("%s",X);
	scanf("%s",Y);
	printf("%d\n",LCS(X,Y,n,m));

}
int max(int a,int b)
{
	return a>b?a:b;
}
int LCS(char* X, char* Y, int n, int m)
{
	if(n==0||m==0){
		return 0;
	}
	if(X[n-1]==Y[m-1])
	{
		return 1 + LCS(X,Y,n-1,m-1);
	}
	else
	{
		return max(LCS(X,Y,n-1,m),LCS(X,Y,n,m-1));
	}
}
