#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *left,*right;
  char data;
  int freq;
};

void decode(FILE *,FILE *,struct node *);
void encode(FILE *,FILE *,struct node *);
void constructHuffman(char *, int **, int , struct node *, FILE* );
void buildMinHeap(char *, int **, int, FILE* );
void collectFrequency(FILE *,int **,int );
int countDistinct(FILE *);
int* hash(FILE* fp, int ** frequency, int n);
int main()
{
  FILE *fip,*fop,*fdec;
  int **frequency,n,i;
  char *heap;
  struct node *huffman;

  fip = fopen("input.txt","r");
   if(fip == NULL) 
   {
      perror("Error in opening file");
      return(-1);
   }
  fop = fopen("encode","w");
   n = countDistinct(fip);
   printf("Number of distinct characters %d\n",n);
   frequency = (int **)malloc(n*sizeof(int *));
   heap = (char *)malloc(n*sizeof(char));
   for(i=0;i<n;i++)	for(i=0;i<n;i++)

     frequency[i]=(int *)malloc(2*sizeof(int));
   rewind(fip);
   collectFrequency(fip,frequency,n);
   buildMinHeap(heap,frequency,n,fip);
   // constructHuffman(heap,frequency,n,huffman,fip);
   rewind(fip);
  // encode(fip,fop,huffman);
  // fclose(fop);
  // fop = fopen("encode","w");
  // fdec = fopen("decode","r");
  // decode(fop,fdec,huffman);
  // fclose(fip);
  // fclose(fop);
  // fclose(fdec);
  return 0;
}

int countDistinct(FILE *fp)
{
  int n=0,c,i;
  int arr[128]={0};
   while ((c = fgetc(fp)) != EOF) {
   		  // printf("%d ",c);
        arr[c] = 1;
    }
    for(i=0;i<=128;i++)
    {
    	if(arr[i]==1)
    	{
    			n++;
    			// printf("%d ",c);
    	}
    }
  /* Count the total number of distinct characters in the file */

  return n;
}

void collectFrequency(FILE *fp,int **frequency,int n)
{
	int i,c,k=0;
	for(i=0;i<n;i++)
    {
    	frequency[i][1] = 0;
    }
    int * x = hash(fp,frequency,n);
 
 //    int arr[128]={0},distinct[128];
	// while ((c = fgetc(fp)) != EOF) {
 //        arr[c] = 1;
 //    }
 //    for(i=0;i<=128;i++)
 //    {
 //    	if(arr[i]==1)
 //    	{
 //    			distinct[i] = k++;
 //    	}
 //    }
 //    rewind(fp);
	while ((c = fgetc(fp)) != EOF) {
   		  // printf("%d ",c);
        frequency[x[c]][0] = c;
        frequency[x[c]][1]++;
    }
    for(i=0;i<n;i++)
    {
    	printf("Character : %d Frequency: %d\n",frequency[i][0], frequency[i][1] );
    }

  /*
    You need to figure out how many times each character appears in the file. For this we will use hash table.

    create a proper hash function by looking at the file and use the frequency array as a hash table.
    For collision and it's resolution, we allow two cells at every position of the hash table.
    The first cell will contain the ascii code of the character and the second cell will contain the frequency of that character.
  */
}

void buildMinHeap(char *heap, int **frequency, int n, FILE* fp)
{
	int *X = hash(fp,frequency,n);
	int i;
	for(i=0;i<n;i++)
	{
		heap[i] = (char)frequency[i][0];
	}
	for(i = n/2; i>=0; i--)
	{
		Min_Heapify(heap,i,X,n);
	}
	for(i=0;i<n;i++)
	{
		printf("%d. %c\n", i,heap[i]);
	}

  /* 
     This is exactly similar to the buil_max_heap that you have created in previous lab assignment with the following difference:
     In heap you store the characters, but unlike previous implementation the comaprison between different characters are not by their ASCII but by their frequency.
     You should use the same hash function to look for the frequency of the specific character
  */
}

void constructHuffman(char *heap, int **frequency, int n, struct node *huffman , FILE *fp)
{
		int *X = hash(fp,frequency,n);

	 	int  y = delete(heap,X,n);
	 	int  z = delete(heap,X,n);
	 printf("%c %c\n", y,z);
	 	int newf = y+z;
	 
	 	insert(heap, '{', n, X);
	// 	struct node* NodeArray[n];
	// 	for(i=0;i<n;i++)
	// 	{
	// 		struct node* temp = (struct node*)malloc(sizeof(struct node));
	// 		temp->freq = frequency[i][1];
	// 		temp->left = NULL;
	// 		temp->right = NULL;
	// 		temp->data = frequency[i][0];
	// 		NodeArray[i] = temp;

	// 	}
	// 	x = deleteNode(structNode);
	// 	y = deleteNode(structNode);
	// 	struct node* temp = (struct node*)malloc(sizeof(struct node));
	// 		temp->freq = x->freq+y->freq;
	// 		temp->left = x;
	// 		temp->right = y;
	// 		temp->data = '$';


		
	// 	struct node* temp2 = (struct node*)malloc(sizeof(struct node));
	// 	temp2->freq = y+z;
	// 	temp2->left = NULL;
	// 	temp2->right = NULL;
	// 	temp2->data = '$';
	// 	struct node* temp = (struct node*)malloc(sizeof(struct node));
	// 	temp->freq = y+z;
	// 	temp->left = temp1;
	// 	temp->right = temp2;
	// 	temp->data = '$';
		







  /*
    Construct the huffman tree from the given heap.
    Note that you may need to change the heap while contruction (deletion, insertion). Please import the appropriate function written in previous classes.
    Also, note that, you may need to store frequency of new elements that are not there in the file and thus in the array fequency.
    For this you may change the content of the array frequency correctly and figure out a way to store the frequency of tree nodes in the array.
    Otherwise you may use your own data structure
  */
}

void encode(FILE *fip,FILE *fop,struct node *huffman)
{
  /*
    Encode fip using huffman code and write properly to fop.
  */
}

void decode(FILE *fip,FILE *fop,struct node *huffman)
{
  /*
    Decode fip using huffman code and write properly to fop.
  */
}
int* hash( FILE* fp, int ** frequency, int n)
{
int i,c,k=0;
	int * distinct = (int*)malloc(sizeof(int)*128);
     int arr[128]={0};
	while ((c = fgetc(fp)) != EOF) {
        arr[c] = 1;
    }
    for(i=0;i<=128;i++)
    {
    	if(arr[i]==1)
    	{
    			distinct[i] = k++;
    	}
    }

    rewind(fp);
    return distinct;
}
void Min_Heapify(char *a, int i, int * X, int heapsize)
{
	int l, r, temp, largest;
	l = left(i);
	r = right(i);
	if(l<heapsize && X[a[i]]>X[a[l]])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if(r<heapsize  && 	X[a[largest]]>X[a[r]])
	{
		largest = r;
	}
	if (largest!=i)
	{
		temp = a[largest];
		a[largest] = a[i];
		a[i] = temp;
		Min_Heapify(a,largest,X,heapsize);
	}

}
int left(int i)
{
	return 2*i + 1;

}

int right(int i)
{
	return 2*i + 2;
}
int  delete(char *a, int *X, int n)
{
	char max, temp;
	max = a[0];
	temp = a[0];
	a[0] = a[n-1];
	a[n-1] = temp;
	n--;
	Min_Heapify(a,0,X,n);
	return max;
}
void insert(char* a, char e, int n, int *X)
{
	a[n-1] = e;
	increase(a, e, n-1, X);
}

void increase(char *a, char val, int i, int *X)
{
	int temp;
	if( X[a[i]]<X[val] )
		return;
	a[i] = val;
	while(i>0 && X[a[parent(i)]] > X[a[i]])
	{
		temp = a[parent(i)];
		a[parent(i)] = a[i];
		a[i] = temp;
		i = parent(i);
	}

}
int parent(i)
{
	if(i==0)
		return 0;
	if(i%2==0)
		return i/2 -1;
	else
		return i/2;
}
















































































































