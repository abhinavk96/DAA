# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

void radix_sort(char **,int,int);
void count_sort(char **,int,int,int,int);

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
    //scanf("%s",input[i]);       
    }
    for(i=0;i<n;i++)
    {
      printf("%s\n",input[i]);
    }
    printf("\n");
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
    for(i=k-1;i>=0;i--) {
        count_sort(input,i,n,0,k);
    }
}

void count_sort(char **input,int j,int n, int s,int l) {
    if(s==n)
        return;
    char temp[l],ch;
    int count[100]={0},i,k,x;
    for(i=s;i<n;i++) {
        ch=input[i][j]-32;
        count[ch]+=1;
    }
    for(i=1;i<=n;i++) {
        count[i]+=count[i-1];
    }
    for(i=0;i<100;i++) {
        if(count[i]!=0) 
            break;
    }
    for(k=s;k<n;k++) {
        if(input[k][j]==i+32) {
            strcpy(temp,input[k]);
            for(x=k;x>s;x--){
		        
		        strcpy(input[x],input[x-1]);
	        }
            strcpy(input[s],temp);
            break;
        }
    }
    //printf("%d \n",s);
    //for(k=0;k<n;k++) 
      //  printf("%s\n",input[k]);
    count_sort(input,j,n,s+1,l);
}












