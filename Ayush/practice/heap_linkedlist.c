#include <stdio.h>
#include <stdlib.h>

struct heap {
    int val;
    struct heap* left;
    struct heap* right;
    struct heap* parent;
};

struct heap* createnode(int data) {
    struct heap* node = (struct heap*)malloc(sizeof(struct heap));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

int binary(int a[],int n)
{
    int len = 0;
    while(n != 0) {
        a[len] = n % 2;
        n /= 2;
        len++;
    }
    return len;
}

struct heap* insert(struct heap* root,int n,int val)
{
    struct heap* node = createnode(val);
    if(n == 1) {
        root = node;
        return root;
    }
    int bin[1000], len, i;
    len = binary(bin,n);
    struct heap* trav = root;
    for(i = len - 2; i >= 1; i--) {
        if(bin[i] == 1)
            trav = trav -> right;
        else
            trav = trav -> left;
    }
    node->parent = trav;
    if(i <= 0) {
        if(bin[0] == 1)
            trav->right = node;
        else
            trav->left = node;
    }
    int temp;
    while(node->parent != NULL && node->parent->val < node->val) {
        temp = node->val;
        node->val = node->parent->val;
        node->parent->val = temp;
        node = node->parent;
    }
    return root;
}

void heapify(struct heap* root,int n)
{
    int left;
    int right;
    if(root->left != NULL)
        left = root->left->val;
    if(root->right != NULL)
        right = root->right->val;
    int dir = 0;
    int largest = root->val;
    int cur = largest;
    if(root->left != NULL && left > cur) {
        cur = left;
        dir = 0;
    }
    if(root->right != NULL && right > cur) {
        cur = right;
        dir = 1;
    }
    struct heap* node;
    if(dir == 0)
        node = root->left;
    else
        node = root->right;
    int temp;
    if(largest != cur) {
        temp = root->val;
        root->val = cur;
        node->val = temp;
        //root = node;
        heapify(node,n);
    }
}

struct heap* delete(struct heap* root,int* n)
{
    if((*n) == 1) {
        root = NULL;
        (*n)--;
        return root;
    }
    struct heap* last = root;
    int bin[1000], len, i;
    int dir = 0;
    int x = *n;
    len = binary(bin,x);
    for(i = len - 2; i >= 0; i--) {
        if(bin[i] == 1) {
            last = last -> right;
            dir = 1;
        }
        else {
            last = last -> left;
            dir = 0;
        }
    }
    //printf("%d\n",last->val);

    if(dir == 0)
        last->parent->left = NULL;
    else
        last->parent->right = NULL;

    root->val = last->val;
    (*n)--;
    heapify(root,n);
    return root;
}

void printGivenLevel(struct heap* root, int level);
int height(struct heap* node);

void display(struct heap* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}


void printGivenLevel(struct heap* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->val);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

int height(struct heap* node)
{
    if (node==NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

int main() {
    struct heap* root = NULL;
    int ans,val;
    int n = 0;
    while(1) {
        printf("1. to insert element.\n2. to delete element.\n3.to display elements\n4.to exit\n\n");
        scanf("%d",&ans);
        switch(ans) {
            case 1:{
                    printf("enter element\n");
                    scanf("%d",&val);
                    n++;
                    root = insert(root,n,val);
                    break;
            }
            case 2: {
                    root = delete(root,&n);
                    break;
            }
            case 3: {
                    display(root);
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
