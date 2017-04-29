#include<stdio.h>
#include<stdlib.h>

int partition_(int a[][2], int start, int end_)
{
    int pivot  = a[end_][0];
    int pivot2 = a[end_][1];
    int pindex = start;
    int i,temp;
    for(i = start; i < end_; i++) {
        if(a[i][0] < pivot) {
             temp = a[i][0];
                a[i][0] = a[pindex][0];
                a[pindex][0] = temp;
                temp = a[i][1];
                a[i][1] = a[pindex][1];
                a[pindex][1] = temp;
            pindex++;
        }
        else if (a[i][0] == pivot) {
            if(a[i][1] < pivot2) {
                temp = a[i][0];
                a[i][0] = a[pindex][0];
                a[pindex][0] = temp;
                temp = a[i][1];
                a[i][1] = a[pindex][1];
                a[pindex][1] = temp;
                pindex++;

            }
        }
    }
    temp = a[end_][0];
    int t1 = a[end_][1];
    a[end_][0] = a[pindex][0];
    a[end_][1] = a[pindex][1];
    a[pindex][0] = temp;
    a[pindex][1] = t1;
    return pindex;
}


void quicksort(int a[][2], int start, int end_)
{
    if(start < end_) {
        int pindex = partition_(a,start,end_);
        quicksort(a,start,pindex - 1);
        quicksort(a,pindex + 1,end_);
    }
}

int main()
{
    int a[100][2];
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    quicksort(a,0,n - 1);
    for(int i = 0; i < n; i++) {
        printf("%d %d\n",a[i][0],a[i][1]);
    }
    return 0;
}
