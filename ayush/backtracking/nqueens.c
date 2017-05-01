#include <stdio.h>

int issafe(int n, int board[][n], int row, int col)
{
	int i, j;
	for(i = 0; i < col; i++) {
		if(board[row][i])
			return 0;
	}

	for(i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if(board[i][j])
			return 0;
	}

	for(i = row, j = col; i < n && j >= 0; i++,j--) {
		if(board[i][j])
			return 0;
	}
	
	return 1;
}

int solve(int n, int board[][n], int col)
{
	if(col >= n)
		return 1;
	int i;
	for(i = 0; i < n; i++) {
		if(issafe(n, board, i, col)) {
			board[i][col] = 1;
			if(solve(n, board, col + 1))
				return 1;
			board[i][col] = 0;
		}
	}
	return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	int board[n][n];
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			board[i][j] = 0;
	int k = solve(n, board, 0);
	if(k == 0)
		printf("no solution\n");
	else {
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
 				printf("%d ", board[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}