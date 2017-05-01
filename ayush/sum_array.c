#include <stdio.h>

int max(int a, int b)
{
	return (a > b)? a : b;
}


int find_max(int ar[], int i, int j, int dp[])
{
	if(i > j)
		return 0;
	if(dp[i] != -1)
		return dp[i];
	return dp[i] = max(ar[i] + find_max(ar, i+2, j, dp), find_max(ar, i+1, j, dp));
}

int main()
{
	int n;
	scanf("%d", &n);
	int ar[n];

	for(int i = 0; i < n; i++)
		scanf("%d", &ar[i]);
	
	int dp[n+2];
	for(int i = 0; i <= n+1; i++)
		dp[i] = -1;
	int ans = find_max(ar, 0, n - 1, dp);
	printf("%d\n", ans);
}