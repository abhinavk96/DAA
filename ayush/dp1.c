#include <stdio.h>

int maxsum(int arr[], int i, int j)
{
	if(i > j)
		return 0;
	int x = arr[i] + maxsum(arr, i + 2, j);
	int y = maxsum(arr, i + 1, j);
	if(x < y)
		return y;
	else 
		return x;
}

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	int i;
	for(i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}
	int ans = maxsum(arr, 0, n - 1);
	printf("%d",ans);
	return 0;
}