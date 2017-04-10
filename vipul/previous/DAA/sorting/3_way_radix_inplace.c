# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

void radix_sort(char **,int,int);
void stableSort(char **, int, int, int, int [], char **);
void quicksortX(char **, int, int, int, int);
void exch(char **a, int p, int q, int k) ;

int main()
{
  char **input;
  char ch=' ';
  int n,k,i,j;
  srand(time(NULL));
  scanf("%d",&n);
  scanf("%d",&k);
  input = (char **)malloc(n*sizeof(char *));
  for(i=0;i<n;i++)
    {
      input[i]=(char *)malloc((k+1)*sizeof(char));
      for(j=0;j<k;j++)
	input[i][j]=(rand()%95)+32;
      input[i][k]='\0';
    }
  radix_sort(input,n,k);
  for(i=0;i<n;i++)
    {
      printf("%s\n",input[i]);
    }
  
  return 0;
}

void radix_sort(char **input,int n,int k)
{
  /* The function sorts the array input using radix sort
     Write the two versions of the radix sort here, one after another.
     To execute one of the version just comment out the other version.
   */
/*
	int j;
	char **output;
	output = (char **) malloc(n*sizeof(char *));
	int i;
	for(i = 0; i < n; i++) {
		output[i] = (char *) malloc((k+1) * sizeof(char));
	}
	int arr[100];
	for(j = k-1; j >= 0 ; j--) {
		stableSort(input, n, j, k, arr, output);
	}
*/
	quicksortX(input, 0, n-1,0, k );

}

void stableSort(char **input, int n, int j, int k, int arr[100], char **output)
{
	int i;
	for(i = 0; i < 100; i++) {
		arr[i] = 0;
	}
	
	for(i = 0; i < n; i++) {
		arr[(int)(input[i][j] - 32)]++ ;
	}
	
	for(i = 0; i < 99; ++i){
		arr[i+1] += arr[i];	
	}

	for(i = n-1; i >= 0; --i) {
		strcpy(output[arr[(int)(input[i][j]-32)] - 1], input[i]);
		arr[(int)(input[i][j]-32)]--;
	}

	for(i = 0; i < n; i++) {
		strcpy(input[i], output[i]);
	}

}

void quicksortX(char **a, int lo, int hi, int d, int k)
{
	if (hi - lo <= 0) return;
	int i = lo-1, j = hi;
	int p = lo-1, q = hi;
	char v = a[hi][d];
	while (i < j)
	{
		while (a[++i][d] < v) if (i == hi) break;
		while (v < a[--j][d]) if (j == lo) break;
		if (i > j) break;
		exch(a, i, j, k);
		if (a[i][d] == v) exch(a, ++p, i, k);
		if (a[j][d] == v) exch(a, j, --q, k);
	}
	if (p == q)
	{
		if (v != '\0') quicksortX(a, lo, hi, d+1, k);
		return;
	}
	if (a[i][d] < v) i++;
	for (k = lo; k <= p; k++) exch(a, k, j--, k);
	for (k = hi; k >= q; k--) exch(a, k, i++, k);
	quicksortX(a, lo, j, d, k);
	if ((i == hi) && (a[i][d] == v)) i++;
	if (v != '\0') 
		quicksortX(a, j+1, i-1, d+1, k);
	quicksortX(a, i, hi, d, k);
}

void exch(char **a, int p, int q, int k) {
	char temp;
	int i;
	for(i = 0; i < k; i++) {
		temp = a[p][i];
		a[p][i] = a[q][i];
		a[q][i] = temp;
	}
	return;
}