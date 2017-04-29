#include <stdio.h>
#include <stdlib.h>

struct minheapnode
{
    char data;
    int freq;
    struct minheapnode* left;
    struct minheapnode* right;
};

struct minheap
{
    int size;
    int capacity;
    struct minheapnode** array;
};

struct code
{
	char data;
	char array[100];
};

struct minheapnode* newnode(char data, int freq)
{
    struct minheapnode* temp = (struct minheapnode*)malloc(sizeof(struct minheapnode));
    temp -> data = data;
    temp -> freq = freq;
    temp -> left = temp -> right = NULL;
    return temp;
}

void swap(struct minheapnode** a, struct  minheapnode** b)
{
    struct minheapnode* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct minheap* heap, int index)
{
    int n = heap -> size;
    int largest = index;
    //int value = heap -> array[index] -> freq;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if(left < n  && heap -> array[largest]->freq > heap -> array[left]->freq)
        largest = left;
    if(right < n  && heap -> array[largest]->freq > heap -> array[right]->freq)
        largest = right;
    if(index != largest) {
        swap(&heap -> array[index],&heap -> array[largest]);
        heapify(heap, largest);
    }
}

void buildheap(struct minheap* heap)
{
    int n = heap -> size;
    int i;
    for(i = n - 1; i >= 0; i--)
        heapify(heap, i);
 }

struct minheap* createheap(char data[], int freq[], int size)
{
    struct minheap* temp = (struct minheap*)malloc(sizeof(struct minheap));
    temp -> size = 0;
    temp -> capacity = size;
    temp -> array = (struct minheapnode**)malloc(sizeof(struct minheapnode*) * temp -> capacity);
    int i;
    for(i = 0; i < size; i++) {
        temp -> array[i] = newnode(data[i], freq[i]);
        (temp -> size)++;
    }
    buildheap(temp);
    return temp;
}

struct minheapnode* extract(struct minheap* heap)
{
    struct minheapnode* temp = heap->array[0];
    heap->array[0] = heap->array[(heap -> size) - 1];
    (heap->size)--;
    heapify(heap, 0);
    return temp;
}

void insert(struct minheap* heap, struct minheapnode* node)
{
    heap -> array[heap -> size] = node;
    (heap -> size)++;
    int n = heap -> size;
    int parent = (n - 2) / 2;
    int child = n - 1;
    while(parent >= 0 && heap -> array[parent] -> freq > heap -> array[child] -> freq) {
        swap(&heap -> array[child],&heap -> array[parent]);
        child = parent;
        parent = (child - 1) / 2;
    }
}

struct minheapnode* createhuffman(char data[], int freq[], int size)
{
    int i;
    struct minheap* heap = createheap(data, freq, size);
    struct minheapnode *left, *right, *top;
    while(heap -> size != 1) {
        left = extract(heap);
        right = extract(heap);
        top = newnode('$', left -> freq + right -> freq);
        top -> left = left;
        top -> right = right;
        insert(heap, top);
    }
    return extract(heap);
}

void printArr(int arr[], int n,struct code codes[], int* k)
{
    int i;
    for (i = 0; i < n; ++i) {
        codes[*k].array[i] = arr[i] + 48;
    }
    codes[*k].array[i] = '\0';
    (*k)++;
}

void printCodes(struct minheapnode* root,int arr[], int top,struct code codes[], int* k)
{
    if (root -> left)
    {
        arr[top] = 0LL;
        printCodes(root->left, arr, top + 1, codes, k);
    }

    if (root -> right)
    {
        arr[top] = 1LL;
        printCodes(root->right, arr, top + 1, codes, k);
    }

    if (root -> left == NULL && root -> right == NULL)
    {
        /*printf("%c: ", root->data);
    	int i;
    	for(i = 0; i < top; i++)
    		printf("%lld", arr[i]);
    	printf("\n");*/
        codes[*k].data = root -> data;
        printArr(arr, top, codes, k);
    }
}

 int countDistinct(FILE *fp)
{
    int n = 0;
    int i;
    int cnt[300];
    for(i = 0; i < 300; i++) {
        cnt[i] = 0;
    }
    char ch;
    while((ch = fgetc(fp)) != EOF) {
        cnt[ch]++;
    }
    for(i = 0; i < 300; i++) {
        if(cnt[i]) {
            n++;
        }
    }
    rewind(fp);
    return n;
}

void collectFrequency(FILE *fp,int *frequency,int n, char* c)
{
    int i;
    int cnt[300] = {0};
    char ch;
    while((ch = fgetc(fp)) != EOF) {
        cnt[ch]++;
    }
    int j = 0;
    for(i = 0; i < 300; i++) {
        if(cnt[i]) {
            c[j] = (char)i;
            frequency[j] = cnt[i];
            j++;
        }
    }
    rewind(fp);
}


void encode(FILE *fip, FILE *fop, struct minheapnode *root, struct code codes[], int n)
{
	char ch;
	int i;
  	while((ch = fgetc(fip)) != EOF) {
        for(i = 0; i < n; i++) {
        	if((int)codes[i].data == ch){
        		fprintf(fop, "%s",codes[i].array);
        	}
        }
    }
	rewind(fip);
	rewind(fop);
}

void decode(FILE *fip,FILE *fop,struct minheapnode *root, struct code codes[], int n)
{
  	char ch;
  	struct minheapnode* temp = root;
  	//printf("%d ", root->freq);

  	while((ch = fgetc(fip)) != EOF) {
  		int l = (int)ch;
  		//printf("%c ", l);
  		if(l == 48 && temp -> left != NULL) {
  			temp = temp -> left;
  			if(temp -> left == NULL && temp -> right == NULL) {
  				printf("%c ", temp -> data);
  				fprintf(fop, "%c",temp -> data);
  				temp = root;
  			}
  		}
  		else if(l == 49 && temp -> right != NULL) {
  			temp = temp -> right;
  			if(temp -> left == NULL && temp -> right == NULL) {
  				printf("%c ", temp -> data);
  				fprintf(fop, "%c",temp -> data);
  				temp = root;
  			}
  		}

  	}
  	rewind(fip);
  	rewind(fop);
}

struct minheapnode* huffman(char data[], int freq[], int n,struct code codes[], int* k)
{
    struct minheapnode* root = createhuffman(data, freq, n);
    int arr[n];
    printCodes(root, arr, 0, codes, k);
    int i;

    return root;
}

int main()
{
	FILE *fip,*fop,*fdec;
	fip = fopen("input","r");
    fop = fopen("encode.txt","w");
    int n = countDistinct(fip);
    char arr[n];
    int freq[n];
    int size = n;
    int i;
    //printf("%d\n",n);
    collectFrequency(fip,freq,n,arr);
    /*for(i = 0; i < n; i++)
    	printf("%d ", freq[i]);*/
    struct code codes[n];
    int k = 0; //index for code array
    struct minheapnode* root = huffman(arr, freq, size, codes, &k);
    /*for(i = 0; i < n; i++) {
    	printf("%c: %s\n",codes[i].data, codes[i].array);
    }*/
    encode(fip,fop,root,codes,n);
    fclose(fop);
    fop = fopen("encode.txt","r");
    fdec = fopen("decode.txt","w");
    decode(fop,fdec,root,codes,n);
    fclose(fip);
    fclose(fop);
    fclose(fdec);
    return 0;
}



