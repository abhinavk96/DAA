#include <string.h>
#include <stdio.h>
#define SIZE 80
#define COUNT_SIZE 26
void input(char str[][SIZE], int n)
{
	for(int i = 0; i < n; i++)
			scanf("%s", str[i]);
}
void display(char str[][SIZE], int n)
{
	for(int i = 0; i < n; i++)
	{
			printf("%s\n",  str[i]);
	}
}
int max_len(char str[][SIZE], int n)
{
	int max = strlen(str[0]);
	for(int i = 1; i < n; i++)
	{
		printf("%zu ", strlen(str[i]));
		if((int)strlen(str[i]) > max)
			max = strlen(str[i]);
	}
	return max;
}
void pad_zeroes(char str[][SIZE], int n, int max)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = strlen(str[i]); j < max; j++)
			str[i][j] = '0';
		str[i][max] = '\0';
	}
}
void Counting_sort(char str[][SIZE], int n, int ind)
{

	char res[n][SIZE];
	int count[COUNT_SIZE];
	int x;
	int i;
	for( i = 0; i < COUNT_SIZE; i++)
	{
		count[i] = 0;
	}
	for(i = 0; i < n; i++)
	{
		count[str[i][ind] - 'a']++;
	}
	for( i = 1; i < COUNT_SIZE; i++)
	{
		count[i] = count[i] + count[i-1];
	}
	

	for(i = n-1; i >= 0; i--)
	{
		x = count[str[i][ind] - 'a'];
		count[str[i][ind] - 'a']--;
		strcpy(res[x-1], str[i]);
	}
	for(i = 0; i < n; i++)
		strcpy(str[i], res[i]);

}
void Radix_sort(char str[][SIZE], int n)
{
	// int max = max_len(str, n);
	// printf("%d\n", max);
	// pad_zeroes(str, n, max);
	int l = strlen(str[0]);
	//printf("%d \n", l);
	for(int i = l - 1; i >= 0; i--)
	{
		Counting_sort(str, n, i);
	}
}
int main()
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int n;
		scanf("%d ", &n);
		char str[n][SIZE];
		input(str, n);
		Radix_sort(str, n);
		display(str, n);
	}
}