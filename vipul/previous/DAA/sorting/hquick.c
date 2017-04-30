# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void hybridSort(int *,int);
void swap(int *a,int *b);
void quick(int *arr,int l,int h,int k);
int partition(int *arr,int l,int h);
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
  int min=99999,k=10;
  clock_t begin,end;
  //for(k=1;k<=100;k++){
         begin = clock();
        quick(arr,0,n,10);
    end = clock();
    printf("%d,%d",k,end-begin);
  //}


}
void quick(int *arr,int l,int h,int k){
    if(l<h){
    if(h-l<=k)
        insertion(arr,l,h);
    else{
        int p=partition(arr,l,h);
        quick(arr,l,p,k);
        quick(arr,p+1,h,k);
    }
    }
}
int partition(int *arr,int l,int h){
    int i=l+1,j=h-1,m=(h-1+l)/2;
    if(arr[l]>arr[m])
        swap(&arr[l],&arr[m]);
    if(arr[l]>arr[h-1])
        swap(&arr[l],&arr[h-1]);
        if(arr[m]>arr[h-1])
        swap(&arr[m],&arr[h-1]);
        swap(&arr[l],&arr[m]);
    int p=l;
    while(i<j){
            while(i<h && arr[i]<arr[p]){
                    i++;
            }
            while(arr[j]>arr[p])
                j--;
            if(i<j){
                    swap(&arr[i],&arr[j]);
                    i++;
                    j--;
            }
            else
                i++;
    }
    swap(&arr[p],&arr[j]);
    return j;
}
void insertion(int *arr,int l,int h){
     int i, key, j;
   for (i = l; i < h; i++)
   {
       key = arr[i];
       j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

