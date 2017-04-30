int partition(int *A, int left, int right){
    int pivot = A[right], i = left, x;

    for (x = left; x < right; x++){
        if (A[x] <= pivot){
            swap(&A[i], &A[x]);
            i++;
        }
    }

    swap(&A[i], &A[right]);
    return i;
}


int quickselect(int *A, int left, int right, int k){

    //p is position of pivot in the partitioned array
    int p = partition(A, left, right);

    //k equals pivot got lucky
    if (p == k-1){
        return A[p];
    }
    //k less than pivot
    else if (k - 1 < p){
        return quickselect(A, left, p - 1, k);
    }
    //k greater than pivot
    else{
        return quickselect(A, p + 1, right, k);
    }
}
