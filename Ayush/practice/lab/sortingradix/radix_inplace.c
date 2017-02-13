# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

void radix_sort(char **,int,int);
void countSort(char **input, int n, int exp);
//int getMax(char a[][100], int n);
void swap(char** a,char** b);

int main()
{
    char **input;
    char ch=' ';
    int n,k,i,j;
    srand(time(NULL));
    scanf("%d",&n);
    scanf("%d",&k);
    input = (char **)malloc(n*sizeof(char *));
    for(i=0;i<n;i++) {
        input[i]=(char *)malloc((k+1)*sizeof(char));
        scanf("%s",input[i]);
        input[i][k]='\0';
    }
    radix_sort(input,n,k);
    for(i=0;i<n;i++) {
      printf("%s\n",input[i]);
    }

    return 0;
}

void radix_sort(char **input,int n,int k)
{
	int i;
    for (i = k - 1; i >= 0; i--) {
		countSort(input, n, i);
	}
}

void countSort(char **input, int n, int exp)
{
    int i;
	int count[100] = {0};

 	char output[n][10];

    for (i = 0; i < n; i++) {
	count[input[i][exp] - 32]++;
	}
    
	int b=0,c=0,j=0;
	for(i=0;i<100 && b<n ;i++)
	{
		while(count[i]>0)
		{

			for(j=b;j<n;j++)
			{
				if(input[j][exp] == i+32)
				{
					c=j;
					break;
				}
			}
			char temp[10];
			strcpy(temp,input[b]);
			strcpy(input[b],input[c]);
			strcpy(input[c],temp);
			b++;
			count[i]--;
		}
	}

