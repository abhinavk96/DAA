#include <stdio.h>
struct pq
{
    int data;
    int priority;

};

void insert(struct pq arr[],int* n,int e, int p)
{
    struct pq temp;
    arr[*n].data = e;
    arr[*n].priority = p;
    (*n)++;
    int child = *n - 1;
    int parent = *n / 2;
    while(parent >= 0 && arr[parent].priority < arr[child].priority) {
        temp = arr[child];
        arr[child] = arr[parent];
        arr[parent] = temp;
        child = parent;
        parent = child / 2;
    }
}

void heapify(struct pq arr[],int n, int i)
{
    struct pq temp;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[left].priority > arr[largest].priority)
        largest = left;
    if(right < n && arr[right].priority > arr[largest].priority)
        largest = right;
    if(i != largest){
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr,n,largest);
    }
}

void build_heap(struct pq arr[],int n)
{
    int i;
    for(i = n/2 - 1; i >= 0; i--) {
        heapify(arr,n,i);
    }
}

void delete(struct pq arr[],int* n)
{
    arr[0] = arr[(*n) - 1];
    (*n)--;
    heapify(arr,&n,0);
}

int main() {
    int ans,e,p;
    struct pq arr[10000];
    int n = 0;
    while(1) {
        printf("1. to insert element in priority queue.\n2. to delete element.\n3.to display elements\n4.to exit\n\n");
        scanf("%d",&ans);
        switch(ans) {
            case 1:{
                    printf("enter element and its priority\n");
                    scanf("%d%d",&e,&p);
                    insert(arr,&n,e,p);
                    break;
            }
            case 2: {
                    delete(arr,&n);
                    break;
            }
            case 3: {
                    //printf("hello");
                    int i;
                    for(i = 0; i < n; i++)
                        printf("%d ",arr[i].data);
                    printf("\n");
                    break;
            }
            case 4:{
                    exit(0);
            }
        }
    }
    return 0;
}
