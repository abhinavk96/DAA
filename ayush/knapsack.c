#include <stdio.h>

int knapsack(int n, int v[], int w[], int W)
{
	int dp[n + 1][W + 1];
	int i;
	int j;
	int keep[n + 1][W + 1];
	for(i = 0; i <= W; i++) 
		dp[0][i] = 0;
	for(i = 1; i <= n; i++) {
		for(j = 0; j <= W; j++) {
			if( w[i] <= j && v[i] + dp[i - 1][j - w[i]] > dp[i - 1][j]) {
				dp[i][j] = v[i] + dp[i - 1][j - w[i]];
				keep[i][j] = 1;
			}
			else {
				dp[i][j] = dp[i - 1][j];
				keep[i][j] = 0;
			}
		}
	}
	int x = W;
	for(i = n; i >= 1; i--) {
		if(keep[i][x] == 1) {
			printf("%d ",i);
			x = x - w[i];
		}
	}
	printf("\n");
	return dp[n][W];
}

int main()
{
	int n;
	scanf("%d",&n);
	int v[n + 1];
	int w[n + 1];
	int i;
	for(i = 1; i <= n; i++) {
		scanf("%d",&v[i]);
	}
	for(i = 1; i <= n; i++) {
		scanf("%d",&w[i]);
	}
	for(i = 1; i <= n; i++) {
		printf("%d ",v[i]);
	}
	printf("\n");
	for(i = 1; i <= n; i++) {
		printf("%d ",w[i]);
	}
	printf("\n");
	int W;
	scanf("%d",&W);
	int ans = knapsack(n, v, w, W);
	printf("%d\n",ans);
	return 0;
}