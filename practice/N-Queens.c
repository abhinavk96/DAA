#include <stdio.h>
#include <stdlib.h>
int solve(int **board,int col,int n);
void NQueens(int **board,int n);
int check(int**board,int i,int j, int n);
int main()
{
	int n,i;
	scanf("%d",&n);
	int **board = (int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		board[i] = (int*)malloc(n*sizeof(int));
	}
	NQueens(board,n);
}
void NQueens(int **board,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			board[i][j] = 0;
		}
	}
	int x = solve(board,0,n);
	if(x)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(board[i][j]==0)
					printf(". ");
				else
					printf("Q ");
			}
			printf("\n");
		}	
	}
}
int solve(int **board,int col, int n)
{
	if(col>=n)
	{
		return 1;
	}
	int i,j;
	
	for(i=0;i<n;i++)
	{
		if(check(board,i,col,n))
		{
			board[i][col] = 1;
			if(solve(board,col+1,n)){
				return 1;
			}
			board[i][col]=0;
		}
	}
	return 0;
}
int check(int**board,int row,int col, int n)
{
	int k,l;
	for(k=0;k<col;k++)
	{
		if(board[row][k]==1)
			return 0;
	}
	for(k=row,l=col;k<n&&l>=0;k++,l--)
	{
		if(board[k][l]==1)
			return 0;
	}
	for(k=row,l=col;k>=0&&l>=0;k--,l--)
	{
		if(board[k][l]==1)
			return 0;
	}
	return 1;
}