# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void hybridSort(int *,int);

int main()
{
  int *arr,n;
  srand((unsigned int)time(NULL));
  scanf("%d",&n);
  arr = (int *)malloc(n*sizeof(int));
  hybridSort(arr,n);
  return 0;
}


void hybridSort(int *arr, int n)
{

  /* write your program here.....
     use the following block of code to find out the time of running a particular routine
     clock_t begin,end;



     begin = clock();
     
     perform your computation here

     end = clock();

     time required will be end-begin


     For random input use the following code

     arr[i] = rand();


     output should be printed in the following way for each k.

     printf("%d,%d",k,end-begin);

  */
     

}