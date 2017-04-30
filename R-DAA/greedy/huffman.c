#include <stdio.h>
# include <stdlib.h>

struct node {
  	struct node *left,*right;
  	char data;
	int freq;	
};
void minHeapify(int **frequency, int index, int n)
{
	int smallest = index;
	int left = 2*index + 1;
	int right = 2*index + 2;
	int k;
	char j;
	if(left<n && frequency[smallest][1] > frequency[left][1])
		smallest = left;
	if(right < n && frequency[smallest][1] > frequency[right][1])
		smallest = right;
	if(smallest != index)
	{
		j = frequency[smallest][0];
		k = frequency[smallest][1];
		frequency[smallest][0] = frequency[index][0];
		frequency[smallest][1] = frequency[index][1];
		frequency[index][0] = j;
		frequency[index][1] = k;
		minHeapify(frequency, smallest, n);	
	}
}
struct node *newNode(char c, int d)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->data = c;
	tmp->freq = d;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}
void printpath(char pathar[], int len, struct node *huffman, char ch, FILE *fop)
{
	if(huffman == NULL)
		return;
	if(huffman->left == NULL && huffman->right == NULL)
	{
		if(huffman->data == ch)
		{
			pathar[len] = '\0';
			fprintf(fop,"%s",pathar);
		}
	}
	else
	{
		pathar[len] = '0';
		printpath(pathar, len+1, huffman->left, ch, fop);
		pathar[len] = '1';
		printpath(pathar, len+1, huffman->right, ch, fop);
	}
	
}
void print(struct node *huffman, char ch, FILE *fop)
{
//	fprintf(fop, "KKK");
	char pathar[1000];
	printpath(pathar, 0, huffman, ch, fop);
}
void decode(FILE *,FILE *,struct node *);
void encode(FILE *,FILE *,struct node *);
struct node *constructHuffman(char *, int **, int , struct node *);
void buildMinHeap(char *, int **, int );
void collectFrequency(FILE *,int **,int );
int countDistinct(FILE *);
void minheapify(struct node *array[], int n, int index)
{
	int smallest = index;
	int left = 2*index + 1;
	int right = 2*index + 2;
	if(left < n && array[smallest]->freq > array[left]->freq)
		smallest = left;
	 if(right < n && array[smallest]->freq > array[right]->freq)
		smallest = right;
	if(smallest != index)
	{
		struct node *tmp;
		tmp = array[smallest];
		array[smallest] = array[index];
		array[index] = tmp;
		minheapify(array, n, smallest);
	}	
}
void buildheap(struct node *array[], int n)
{
	int i;
	for(i = (n-1)/2; i >= 0; i--)
	{
		minheapify(array, n, i);
	}
}
struct node *extractMin(struct node *array[], int n)
{
        struct node *tmp;
        tmp = array[0];
	array[0] = array[n-1];
        n = n - 1;
        minheapify(array, n, 0);
        return tmp;
}
void insert(struct node *array[], int n, struct node *top)
{
	int j = n;
	array[n] = top;
	n = n + 1;
	int parent;
	if(n % 2 == 0)
		parent = (n - 2)/2;
	else
		parent = (n - 1)/2;
	while(1)
	{
		if(array[parent]->freq <= array[j]->freq)
			break;
		else
		{
			struct node *tmp;
			tmp = array[j];
			array[j] = array[parent];
			array[parent] = tmp;
			j = parent;
			if(j % 2 == 0)
				parent = (j - 2)/2;
			else
				parent = (j - 1)/2;
		}
	}
}
int main()
{
  	FILE *fip,*fop,*fdec;
  	int **frequency,n,i;
  	char *heap;
  	struct node *huffman;
  	fip = fopen("input2.txt","r");
  	fop = fopen("encode","w");
  	n = countDistinct(fip);
  	frequency = (int **)malloc(n*sizeof(int *));
 	 heap = (char *)malloc(n*sizeof(char));
  	for(i=0;i<n;i++)
    		frequency[i]=(int *)malloc(2*sizeof(int));
  	rewind(fip);
  	collectFrequency(fip,frequency,n);
  	buildMinHeap(heap,frequency,n);
 	huffman = constructHuffman(heap,frequency,n,huffman);
  	rewind(fip);
  	encode(fip,fop,huffman);
  	fclose(fop);
 	fop = fopen("encode","r");
  	fdec = fopen("decode","w");
 	decode(fop,fdec,huffman);
 	fclose(fip);
  	fclose(fop);
 	fclose(fdec);
  	return 0;
}

int countDistinct(FILE *fp)
{
	
  	int n=0;
	int arr[256];
	int i;
	for(i = 0; i < 256; i++)
		arr[i] = 0;
	char c;
	while((c = fgetc(fp))!=EOF)
	{
//			printf("%c",c);
			arr[c] = arr[c] + 1;
			if(arr[c] == 1)
				n = n + 1;
	}
  	return n;
}

void collectFrequency(FILE *fp,int **frequency,int n)
{
  
	int i;
	int arr[256];
	for(i = 0; i < 256; i++)
	{
		arr[i] = 0;
	}
	char c;
	while((c = fgetc(fp)) != EOF)
	{
//		printf("%c\n",c);
		arr[c] = arr[c] + 1;
	
	}
	int k  = 0;
	for(i = 0; i < 256; i++)
	{
		
		if(arr[i] != 0)
		{
			frequency[k][0] = i;
			frequency[k][1] = arr[i];
			k = k + 1;
		}
	}
  
}

void buildMinHeap(char *heap, int **frequency, int n)
{
	int i;

	for(i = (n-1)/2; i >= 0; i--)
	{
		minHeapify(frequency, i, n);
	}
	
}

struct node *constructHuffman(char *heap, int **frequency, int n, struct node *huffman)
{
 	int i;
  	struct node *array[100];
	for(i = 0; i < n; i++)
		array[i] = (struct node *)malloc(sizeof(struct node));
	for(i = 0;i < n; i++)
	{
		array[i] = newNode(frequency[i][0], frequency[i][1]);
	}
	buildheap(array, n);
	struct node *top, *left, *right;
	while(n != 1)
	{
		left = extractMin(array, n);
		n = n - 1;
		right = extractMin(array, n);
		n = n - 1;
		top = newNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		insert(array, n, top);
		n = n + 1;
	}
	
	return top;
}

void encode(FILE *fip,FILE *fop,struct node *huffman)
{
//	fprintf(fop,":L:");
	char ch;
	while((ch = fgetc(fip))!= EOF)
	{
		print(huffman, ch, fop);
	}	
}
void decode(FILE *fip,FILE *fop,struct node *huffman)
{
	struct node *tmp = huffman;
	char ch;
	while((ch=fgetc(fip))!=EOF)
	{
		if(ch == '0')
		{
			tmp = tmp->left;
		}
		else
			tmp = tmp->right;
		if(tmp->left == NULL && tmp->right == NULL)
		{
			fprintf(fop,"%c",tmp->data);
			tmp  = huffman;
		}
	}
}

