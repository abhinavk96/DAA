#include <stdio.h>

int lis( int arr[], int n )
{
    int lis[n], i, j, max = 0;
    
    for (i = 0; i < n; i++)
        lis[i] = 1;
 	
 	for (i = 1; i < n; i++ ) {
        for (j = 0; j < i; j++ ) {
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
    }
 	int max_ind;
    for (i = 0; i < n; i++ ) {
        if (max < lis[i]) {
            max = lis[i];
            max_ind = i;
        }
    }
    int tmp = max;
    tmp--;
    int count = 0;
    int p[n];
    p[0] = max_ind;
    count++;
    for(i = max_ind - 1; i >= 0; i--) {
        if(tmp == lis[i] && arr[i] < arr[max_ind]) {
            p[count++] = i;
            tmp--;
            max_ind = i;
        }
    }
    for(i = count - 1; i >= 0; i--) {
        printf("%d ",arr[p[i]]);
    }
    printf("\n");
    return max;
}
 

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int i;
    for(i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("Length of lis is %d\n", lis( arr, n ) );
    return 0;
}
