# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

void radix_sort(char **,int,int);
void counting_sort(char **input, int n, int k, int d);
void counting_sort2 ( char **input, int n, int k, int d);

int main()
{
  char **input;
  char ch=' ';
  int n,k,i,j;
  srand(time(NULL));
  scanf("%d",&n);
  scanf("%d",&k);
  input = (char **)malloc(n*sizeof(char *));
 /* for(i=0;i<n;i++)
    {
      input[i]=(char *)malloc((k+1)*sizeof(char));
      for(j=0;j<k;j++)
	input[i][j]=(rand()%95)+32;
      input[i][k]='\0';
    }*/

	for ( i = 0 ; i < n; i++) {
		input[i] = (char*)malloc((k+1)*sizeof(char));
		scanf("%s", input[i]);
	}


	printf("\n");
      for(i=0;i<n;i++)
    {
      printf("%s\n",input[i]);
    }
    printf("Sorted\n\n");
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
   int i;
   for ( i = k-2; i >=0 ; i--){
  // 	counting_sort(input,n,k,i);
   	counting_sort2(input,n,k,i);
   }

}

void counting_sort(char **input, int n, int k, int d)
{
	char output[n+1][k+1];
	int count[100];
	int i;
	for ( i = 0; i < 100; i++){
		count[i] = 0;
	}
	for ( i = 0; i < n; i++){
		count [input[i][d]-32]++ ; 
	}
	for ( i = 1 ; i < 100; i++){
		count[i] += count[i-1];
	}
	for ( i = n-1 ; i >= 0; i--){
		strcpy(output[count[input[i][d]-32]-1],input[i]);
		count [input[i][d]-32]-- ;
	}
	for ( i = 0; i < n; i++){
		strcpy(input[i],output[i]);
	}
}

void counting_sort2 ( char **input, int n, int k, int d)
{
	int count[100];
	int i,j;
	for ( i = 0; i < 100; i++){
		count[i] = 0;
	}
	for ( i = 0; i < n; i++){
		count[input[i][d]-32]++;
	}
	for ( i = 1; i < 100; i++){
		count[i] += count[i-1];
	}
	for ( i = 0; i < n-1 ; i++){
		for ( j = 0; j < n-1-i ; j++) {
			if (input[j][d] > input[j+1][d] ){
				char tmp[20];
				strcpy(tmp, input[j]);
				strcpy(input[j],input[j+1]);
				strcpy(input[j+1], tmp);
			}
		}
	}				

}

