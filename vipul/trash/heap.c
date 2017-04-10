///heaps
#include <stdio.h>
#include <stdlib.h>

struct node {
    char ch;
    int fre;
    struct node* l;
    struct node* r;


};
void build_min_heap(struct node a[], int *hs);
void min_heapify(struct node a[], int i, int *hs);
void increase_priority(struct node a[], int i, int np);
struct node* delete_min(struct node a[], int *hs);
void printcode(struct node *root, int path[], int e, int dir);
void insert(struct node a[], struct node *, int *hs);
void printPathsRecur(struct node* node, int path[], int pathLen, int dir);

void huffman(struct node a[], int *hs) {
    while ((*hs) != 1) {
        struct node *p = (struct node *) malloc(sizeof (struct node));
        p = delete_min(a, hs);
        struct node *q = (struct node *) malloc(sizeof (struct node));
        q = delete_min(a, hs);
        struct node *new;
        new = (struct node *) malloc(sizeof (struct node));
        new -> fre = p->fre + q->fre;
        new -> l = p;
        new -> r = q;

        insert(a, new, hs);
        //printf("\n\n %d %d %d \n\n",p->fre,q->fre,new->fre);

    }
}

void print(struct node * root) {
    if (root == NULL) return;
    printf("%d ", root->fre);
    print(root->l);
    print(root->r);
}

int main() {
    int i;
    int hs = 0;
    int n;
    int ab[26];

    for (i = 0; i < 26; i++)
        ab[i] = 0;
    scanf("%d", &n);
    for (i = 0; i <= n; i++) {
        char c;
        scanf("%c", &c);
        ab[c - 'a']++;

    }
    //for(i=0;i<26;i++)
    //	printf("%d\t",ab[i]);
    for (i = 0; i < 26; i++) {
        if (ab[i] != 0)
            hs++;
    }
    struct node a[hs];
    int j = 0;
    for (i = 0; i < 26; i++) {
        if (ab[i] != 0) {

            a[j].ch = i + 'a';
            a[j].fre = ab[i];
            a[j].l = a[j].r = NULL;
            j++;
        }
    }

    build_min_heap(a, &hs);
    for (i = 0; i < hs; i++)
        printf("%c %d\t", a[i].ch, a[i].fre);
    huffman(a, &hs);



    int path[100];
    print(&a[0]);
    printf("\n\n");
    printcode(&a[0], path, 0, 0);



    return 0;
}

void min_heapify(struct node a[], int i, int *hs) {
    int parent, lchild, rchild, min;
    parent = i;
    lchild = 2 * i + 1;
    rchild = 2 * i + 2;
    min = parent;
    if (lchild < *hs && a[parent].fre > a[lchild].fre)
        min = lchild;
    if (rchild < *hs && a[min].fre > a[rchild].fre)
        min = rchild;

    if (min != parent) {


        struct node temp = a[min];
        a[min] = a[parent];
        a[parent] = temp;
        parent = min;
        min_heapify(a, parent, hs);
    }

}

void build_min_heap(struct node a[], int *hs) {
    int i = (*hs - 1) / 2;
    for (; i >= 0; i--) {
        min_heapify(a, i, hs);
    }
}

void decrease_priority(struct node a[], int i, int np) {
    a[i].fre = np;
    int parent = (i - 1) / 2;
    while (a[i].fre < a[parent].fre && parent >= 0) {

        struct node temp = a[i];
        a[i] = a[parent];
        a[parent] = temp;

        i = parent;
        parent = (i - 1) / 2;
    }
}

struct node* delete_min(struct node a[], int *hs) {


    struct node* temp = (struct node *) malloc(sizeof (struct node));
    *temp = a[0];
    a[0] = a[(*hs) - 1];
    a[(*hs) - 1] = *temp;

    (*hs)--;
    min_heapify(a, 0, hs);
    return temp;
}

void insert(struct node a[], struct node *p, int *hs) {
    (*hs)++;
    a[(*hs) - 1] = *p;
    decrease_priority(a, (*hs) - 1, p->fre);
}

void printcode(struct node *root, int path[], int e, int dir) {
    if (root != NULL) {

        if (root ->l == NULL && root->r == NULL) {
            path[e] = dir;
            int i = 0;
            printf("code for %c :", root->ch);
            for (i = 1; i <= e; i++) {
                printf("%d ", path[i]);
            }
            printf("\n");
            return;
        } else if (root->l != NULL || root->r != NULL) {
            path[e] = dir;
            e++;
            printcode(root->l, path, e, 0);

            printcode(root->r, path, e, 1);
        }
    }
}




