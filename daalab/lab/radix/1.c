# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

void radix_sort(char **,int,int);

int main()
{
  char **input;
  char ch=' ';
  int n,k,i,j;
  srand(time(NULL));
  scanf("%d",&n);
  scanf("%d",&k);
	printf("Input list:\n");
  input = (char **)malloc(n*sizeof(char *));
  	for(i=0;i<n;i++) {
    	  input[i]=(char *)malloc((k+1)*sizeof(char));
    	  for(j=0;j<k;j++)
	input[i][j]=(rand()%95)+32;
      input[i][k]='\0';
    }
	 for(i=0;i<n;i++)
    {
      printf("%s\n",input[i]);
    }
	printf("\nSorted list:\n");
  	radix_sort(input,n,k);
  	for(i=0;i<n;i++) {
	      printf("%s\n",input[i]);
 	 }
  
  return 0;
}

void countsort(char **str,int n,int index,int len,char output [][len + 1])
{
    int count[100] = {0};
    int i;
    for(i = 0; i < n; i++) {
        count[str[i][index] - 32]++;
    }
    for(i = 1; i < 100; i++) {
        count[i] += count[i - 1];
    }
    for(i = n - 1; i >= 0; i--) {
        strcpy(output[count[str[i][index] - 32] - 1],str[i]);
        count[str[i][index] - 32]--;
    }
    for(i = 0; i < n; i++) {
        strcpy(str[i],output[i]);
    }
}

void count_sort(char **str,int n,int index,int len)
{
	int count[100] = {0};
    int i;
    for(i = 0; i < n; i++) {
        count[str[i][index] - 32]++;
    }
    for(i = 1; i < 100; i++) {
        count[i] += count[i - 1];
    }
	char temp [len + 1];
	int j;
	char ch;
	int flag = 1;
	for(i = n - 1; i >= 0; i--) {	
		flag = 1;
		while(1) {
			if(count[str[i][index] - 32] - 1 == i) {
					count[str[i][index] - 32]--;					
					break;
			}			
			for(j = 0; j < len; j++) {
				ch = str[count[str[i][index] - 32] - 1][j];
				str[count[str[i][index] - 32] - 1][j] = str[i][j];
				str[i][j] = ch;
				flag = 0;			
			}
			//if(flag == 1)
			//	break;
		}
    }
}

void radix_sort(char **input,int n,int k)
{	
	int i;
	int len = k;
	char output[n][len + 1];
    for(i = len - 1; i >= 0; i--) {
        countsort(input, n, i,len,output);
		//count_sort(input, n, i, len);	
    }
}

