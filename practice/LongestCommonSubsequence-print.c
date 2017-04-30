#include <stdio.h>
#include <stdlib.h>
int LCS(char* X, char* Y,char*L ,int n, int m, int size);
int max(int a, int b);
void printLCS(char*L, int l);
int main()
{
	int n,m,l;
	scanf("%d %d",&n,&m);
	l = max(n,m);
	char *X = (char*)malloc(n*sizeof(char));
	char *Y = (char*)malloc(m*sizeof(char));
	char *L = (char*)malloc(l*sizeof(char));
	scanf("%s",X);
	scanf("%s",Y);
	l = LCS(X,Y,L,n,m,0);
	printf("Length: %d\n",l);
	printLCS(L,l);

}
int max(int a,int b)
{
	return a>b?a:b;
}
int LCS(char* X, char* Y, char*L, int n, int m, int size)
{
	if(n==0||m==0){
		return 0;
	}
	if(X[n-1]==Y[m-1])
	{
		L[size++] = X[n-1];
		return 1 + LCS(X,Y,L,n-1,m-1,size);
	}
	else
	{
		return max(LCS(X,Y,L,n-1,m,size),LCS(X,Y,L,n,m-1,size));
	}
}
void printLCS(char*L, int l)
{
	int i;
	for(i=l-1;i>=0;i--)
	{
		printf("%c",L[i]);
	}
	printf("\n");	
}
