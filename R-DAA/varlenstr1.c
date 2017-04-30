# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

void radix_sort(char **,int);
void swap(char **a,char **b){
	char *temp;	
	temp = *a;
	*a = *b;
	*b = temp;	
}

void counting_sort1 (char **input, int n, int k, int l){
	int count[100], i, j;
	//char **output;
	//output = (char **)malloc(n*sizeof(char *));
	char output[n][k+1];	
	memset (count, 0, sizeof (count));
	int a = 0;
	for(i = 0; i < n; i++){
		int t = strlen(input[i]);
		if (t < (l+1)) {
			strcpy(output[a], input[i]);
			a++;
		}
	}
	for(i = 0;i < n;i++){
		int t = strlen(input[i]);
		if(t >= (l+1)){
			count[input[i][l]-32] += 1;
		}
	}
	/*for (i = 0; i < 100; i++){
		printf ("%d %d\n",i, count[i]);	
	}*/
	for (i = 1; i < 100; i++){
		count[i] += count[i-1];
	}
	/*
	for (i = 0; i < 100; i++){
		printf ("%d %d\n",i, count[i]);	
	}*/
	for(i = n-1; i >= 0; i--){
		int t = strlen (input[i]);
		if (t >= (l+1)){	
			strcpy (output[a+(count[input[i][l]-32]-1)], input[i]);
			count[input[i][l]-32]--;
		}
	}
	for(i = 0; i < n; i++){
		strcpy (input[i], output[i]);	
	}
}

int main()
{
	char **input;
	char ch=' ';
	int n,k,i,j;
	srand(time(NULL));
	scanf("%d",&n);
  //scanf("%d",&k);
	//k = 5;
	input = (char **)malloc(n*sizeof(char *));
	for(i=0;i<n;i++)
	{
		input[i]=(char *)malloc((100)*sizeof(char));
		scanf (" %s", input[i]);
	}
	k = strlen(input[0]);
	///printf ("%d", k);
	for(i=0;i<n;i++)
	{
		printf("%s\n",input[i]);
	}
	radix_sort(input,n);
	printf("output--\n");
	for(i=0;i<n;i++)
	{
		printf("%s\n",input[i]);
	}

	return 0;
}

void radix_sort(char **input,int n){
	int i, j;
	int k = strlen(input[0]);
	for(i=0;i<n;i++)
	{
		int t = strlen(input[i]);
		if (t > k){
			k = t;
		}
		//printf("%s\n",input[i]);
	}
	for (i = k-1; i >=0; i--){
		counting_sort1(input, n, k, i);
	}
}
