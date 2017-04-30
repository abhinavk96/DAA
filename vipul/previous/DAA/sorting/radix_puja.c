#include<stdio.h>
#include<string.h>
#define RANGE 94
int l;

// A function to do counting sort of arr[]
void countSort(char arr[100][100], int n,char output[][100],int k)
{
    char ch; // output array
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));
    for (i = 0; i < n; i++) {

            ch=arr[i][k];
            count[ch-32]++;

    }


    for (i = 1; i < RANGE+1; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
            ch=arr[i][k];
            strcpy(output[count[ch-32]-1],arr[i]);
            count[ch-32]--;
    }

    for (i = 0; i < n; i++) {
        strcpy(arr[i],output[i]);
    }
}


void radixsort(char arr[100][100], int n,char output[][100])
{

    // Find the maximum number to know number of digits
    int i,j;
    // Do counting sort for every digit.
    for (i=l;i>=0;i--) {
        countSort(arr, n,output,i);

    }
}


void print(char arr[100][100], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("\n%s  \n",arr[i]);
	printf("\n");
}


int main()
{
    char arr[100][100],n,j;
    scanf("%d",&n);
    char output[n][100];
    int i;
    for(i=0;i<n;i++) {
	scanf("%s",arr[i]);
    }
    l=strlen(arr[0])-1;
    radixsort(arr, n,output);
    print(arr, n);
    return 0;
}


