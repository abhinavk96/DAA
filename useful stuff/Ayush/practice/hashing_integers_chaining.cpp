#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
};


struct node* getnode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = NULL;
}

void insert(struct node* table[],int x,int pos)
{
    struct node* temp = getnode(x);
    struct node* head = table[pos];
    if(table[pos] == NULL)
        table[pos] = temp;
    else {
        while(head -> next != NULL) {
            head = head -> next;
        }
        head -> next = temp;
    }
}

void display(struct node* table[11])
{
    int i;
    for(i = 0; i < 11 ; i++) {
        if(table[i] == NULL) {
            printf("NULL\n");
        }
        else {
            struct node* head = table[i];
            while(head != NULL) {
                printf("%d->",head->data);
                head = head -> next;
            }
            printf("\n");
        }
    }
}

int search(struct node* table[11],int x)
{
    struct node* head;
    int i;
    int len = 0;
    for(i = 0; i < 11; i++) {
        len = 0;
        if(table[i] != NULL) {
            head = table[i];
            while(head != NULL) {
                len++;
                if(head->data == x)
                    return len;
                head = head -> next;
            }
        }
    }
    return 0;
}

int main()
{
        struct node* table[11];
        int i;
        for(i = 0; i < 11; i++)
            table[i] = NULL;
        int n;
        cin >> n;

        int a[n];
        for(i = 0 ; i < n; i++) {
            cin >>a[i];
            int v = a[i] % 11;
            insert(table,a[i],v);
        }
        display(table);
        int x;
        cin >> x;
        int ans = search(table,x);
        cout << ans;
        return 0;
}
