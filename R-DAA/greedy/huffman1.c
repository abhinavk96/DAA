#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct node{
	int freq;
	char data;
	struct node *left,*right;

};
struct node *newNode(char data,int freq)
{
	struct node *tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = data;
	tmp->freq = freq;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}
void minHeapify(struct node *array[], int n, int index)
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
		struct node *temp;
		temp = array[smallest];
		array[smallest] = array[index];
		array[index] = temp;
		minHeapify(array, n, smallest);
	}
}
void buildHeap(struct node *array[], int n)
{
	int i;
	for(i = (n-1)/2; i >= 0; i--)
	{
		minHeapify(array, n, i);
	}
}
struct node *extractMin(struct node *array[], int n)
{
	struct node *tmp = array[0];
	array[0] = array[n-1];
	n = n - 1;
	minHeapify(array, n, 0);
	return tmp;
	
}
void insertMinHeap(struct node *array[], int n, struct node *top)
{
	int parent;
	int j = n;
	array[n] = top;
	n = n + 1;
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
			tmp = array[parent];
			array[parent] = array[j];
			array[j] = tmp;
			j = parent;
			if(j%2 == 0)
				parent = (j-2)/2;
			else
				parent = (j-1)/2;
		}
	}
}
struct node *build_huffman(char data[], int freq[], int n)
{
	struct node *left, *right, *top;
	struct node *array[100];
	int i;
	for(i = 0;i < 100; i++)
		array[i] = (struct node *)malloc(sizeof(struct node));
	for(i = 0; i < n; i++)
	{
		array[i] = newNode(data[i],freq[i]);
	}
	buildHeap(array,n);
	while(n != 1)
	{
		left = extractMin(array, n);
		n = n - 1;
		right = extractMin(array, n);
		n = n - 1;
		top = newNode('$',left->freq+right->freq);
		top->left = left;
		top->right = right;
		insertMinHeap(array, n, top);
		n = n + 1;
	}
	return top;

}
void Preorder(struct node *n)
{
	if(n == NULL)
		return;
	printf("%c ",n->data);
	Preorder(n->left);
	Preorder(n->right);
}
void huffman(char data[], int freq[], int n)
{
	struct node *root = NULL;
	root = build_huffman(data, freq, n);
	Preorder(root);
}
int main()
{
	char arr[100];
	int freq[100];
	int n,i;
	char c;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		c = getchar();
		arr[i] = c;
		scanf("%d",&freq[i]);
	}
	huffman(arr,freq,n);
	return 0;
}
