#include <bits/stdc++.h>
using namespace std;

void countsort(char** c, int n, int index, int len)
{
    int count[26] ;
    memset(count,0,26*sizeof(int));
    int i;
    int j = 0;
    for(i = n - 1; i >= 0; i--) {
        if(strlen(c[i]) <= index)
            continue;
        count[c[i][index] - 'a']++;
    }
    for(i = 1; i < 26; i++)
        count[i] += count[i - 1];

    char output[100][100];

    for(i = 0; i < n; i++) {
        if(strlen(c[i]) <= index) {
            strcpy(output[j++],c[i]);
        }
    }
    for(i = n - 1; i >= 0; i--) {
        if(strlen(c[i]) <= index)
            continue;
        strcpy(output[count[c[i][index] - 'a'] - 1 + j],c[i]);
        count[c[i][index] - 'a']--;
    }
    for(i = 0; i < n; i++) {
            strcpy(c[i],output[i]);
    }
}

void radixsort(char** c, int n)
{
    int i, x;
    int len = 0;
    for(i = 0 ; i < n; i++) {
        x = strlen(c[i]);
        if(x > len)
            len = x;
    }
    for(i = len - 1; i >= 0; i--) {
        countsort(c,n,i,len);
    }
}

int main()
{
    int n,i;
    cin >> n;
    char **c;
    c = (char**)malloc(sizeof(char*)*100);
    for(i = 0 ; i < n; i++) {
        c[i] = (char*)malloc(sizeof(char)*100);
        cin >> c[i];
    }
    radixsort(c,n);
    for(i = 0 ; i < n; i++)
        cout << c[i] << endl;
    return 0;
}

