# include <stdio.h>
# include <stdlib.h>

struct node {
  struct node *left,*right;
  char data;
};

void decode(FILE *,FILE *,struct node *);
void encode(FILE *,FILE *,struct node *);
void constructHuffman(char *, int **, int , struct node **);
void buildMinHeap(char *, int **, int );
void collectFrequency(FILE *,int **,int );
int countDistinct(FILE *);

int main()
{
  FILE *fip,*fop,*fdec;
  int **frequency,n,i;
  char *heap;
  struct node *huffman;
  fip = fopen("input2.txt","r");
  fop = fopen("encode.txt","w");
  n = countDistinct(fip);
  frequency = (int **)malloc(n*sizeof(int *));
  heap = (char *)malloc(n*sizeof(char));
  for(i=0;i<n;i++)
    frequency[i]=(int *)malloc(2*sizeof(int));
  rewind(fip);
  collectFrequency(fip,frequency,n);
  buildMinHeap(heap,frequency,n);
  constructHuffman(heap,frequency,n,&huffman);
  rewind(fip);
  encode(fip,fop,huffman);
  fclose(fop);
  fop = fopen("encode.txt","r");
  fdec = fopen("decode.txt","w");
  decode(fop,fdec,huffman);
  fclose(fip);
  fclose(fop);
  fclose(fdec);
  return 0;
}

int countDistinct(FILE *fp) {
	int n = 0;
	int i;
	int cnt[300];
	for(i = 0; i < 300; i++) {
		cnt[i] = 0;
	}
	char ch;
	while((fscanf(fp, "%c", &ch)) != EOF) {
		//printf("%c", ch);
		cnt[ch]++;
	}
	/* Count the total number of distinct characters in the file */
	for(i = 0; i < 300; i++) {
		if(cnt[i]) {
			n++;
		}
	}
	return n;
}

void collectFrequency(FILE *fp,int **frequency,int n) {
	int cnt[300];
	int i;
	for( i= 0; i < 300; i++) {
		cnt[i] = 0;
	}
	char ch;
	while((fscanf(fp, "%c", &ch)) != EOF) {
		cnt[ch]++;
	}
	int c = 0;
	for(i = 0; i < 300; i++) {
		if(cnt[i]) {
			frequency[c][0] = i;
			frequency[c][1] = cnt[i];
			c++;
			//printf("%c %d\n", i, cnt[i]);
		}
	}
  /*
    You need to figure out how many times each character appears in the file. For this we will use hash table.

    create a proper hash function by looking at the file and use the frequency array as a hash table.
    For collision and it's resolution, we allow two cells at every position of the hash table.
    The first cell will contain the ascii code of the character and the second cell will contain the frequency of that character.
  */
}

int gfreq_id(int **frequency, int val, int n) {
	int i;
	for(i = 0; i < n; i++) {
		if(frequency[i][0] == val) {
			return i;
		}
	}
}
int gfreq(int **frequency, int val, int n) {
	return frequency[gfreq_id(frequency, val, n)][1];
}
void heapify(char *heap, int id, int **frequency, int sz, int n) {
	int l = 2 * id + 1;
	int r = l + 1;
	int sm = id;
	if(l < sz && gfreq(frequency, heap[l], n) < gfreq(frequency, heap[sm], n)) {
		sm = l;
	}
	if(r < sz && gfreq(frequency, heap[r], n) < gfreq(frequency, heap[sm], n)) {
		sm = r;
	}
	if(sm != id) {
		char temp = heap[id];
		heap[id] = heap[sm];
		heap[sm] = temp;
		heapify(heap, sm, frequency, sz, n);
	}
	
}
char get_min(char *heap, int **frequency, int *sz, int n) {
	char ch = heap[0];
	*sz = *sz - 1;
	heap[0] = heap[*sz];
	heapify(heap, 0, frequency, *sz, n);
	return ch;
}
void restore_up(char *heap, int **frequency, int id, int n) {
	if(!id) {
		return;
	}
	int par = (id - 1)/2;
	if(gfreq(frequency, heap[id], n) < gfreq(frequency, heap[par], n)) {
		char ch = heap[id];
		heap[id] = heap[par];
		heap[par] = ch;
		restore_up(heap, frequency, par, n);
	}
}
void insert(char ch, char *heap, int **frequency, int *sz, int n) {
	heap[*sz] = ch;
	*sz = *sz + 1;
	restore_up(heap, frequency, *sz - 1, n);
}
void print_heap(char *heap, int n) {
	int i;
	for(i = 0; i < n; i++) {
		if(heap[i] == ' ') {
			printf("sp ");
		}
		else if(heap[i] == '\n') {
			printf("en ");
		}
		else {
			printf("%c ", heap[i]);
		}
	}
	printf("\n");
}
void buildMinHeap(char *heap, int **frequency, int n)
{
  /* 
     This is exactly similar to the buil_max_heap that you have created in previous lab assignment with the following difference:
     In heap you store the characters, but unlike previous implementation the comaprison between different characters are not by their ASCII but by their frequency.
     You should use the same hash function to look for the frequency of the specific character
  */
	int i;
	for(i = 0; i < n; i++) {
		heap[i] = frequency[i][0];
	}
	//print_heap(heap, n);
	for(i = n/2; i >= 0; i--) {
		heapify(heap, i, frequency, n, n);
	}
	//print_heap(heap, n);
}
struct node *get_node() {
	struct node *temp;
	temp = (struct node *)(malloc(sizeof(struct node)));
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void inorder(struct node *temp) {
	if(temp == NULL) {
		return;
	}
	inorder(temp->left);
	printf("%c ", temp->data);
	inorder(temp->right);
}
void constructHuffman(char *heap, int **frequency, int n, struct node **huffman)
{
	struct node *pre[n];
	int i;
	for(i = 0; i < n; i++) {
		pre[i] = get_node();
		pre[i]->data = frequency[i][0];
	}
	int size = n;
	while(size != 1) {
		char ch1 = get_min(heap, frequency, &size, n);
		char ch2 = get_min(heap, frequency, &size, n);
		int id1 = gfreq_id(frequency, ch1, n);
		int id2 = gfreq_id(frequency, ch2, n);
		struct node *temp;
		temp = get_node();
		temp->left = pre[id1];
		temp->right = pre[id2];
		temp->data = pre[id1]->data;
		frequency[id1][1]+=frequency[id2][1];
		insert(temp->data, heap, frequency, &size, n);
		pre[id1] = temp;
	}
	char ch = get_min(heap, frequency, &size, n);
	int id = gfreq_id(frequency, ch, n);
	*huffman = pre[id];
	//inorder(*huffman);
  /*
    Construct the huffman tree from the given heap.
    Note that you may need to change the heap while contruction (deletion, insertion). Please import the appropriate function written in previous classes.
    Also, note that, you may need to store frequency of new elements that are not there in the file and thus in the array fequency.
    For this you may change the content of the array frequency correctly and figure out a way to store the frequency of tree nodes in the array.
    Otherwise you may use your own data structure
  */
}
void print_path(char path[], int len, struct node *huffman, char ch, FILE *fop) {
	if(huffman == NULL) {
		return;
	}
	if(huffman->left == NULL && huffman->right == NULL) {
		if(huffman->data == ch) {
			path[len] = '\0';
			fprintf(fop, "%s", path);
		}
		return;
	}
	else {
		path[len] = '1';
		print_path(path, len + 1, huffman->left, ch, fop);
		path[len] = '0';
		print_path(path, len + 1, huffman->right, ch, fop);
	}
}
void path(struct node *huffman, char ch, FILE *fop) {
	char path[1000];
	print_path(path, 0, huffman, ch, fop);
}
void encode(FILE *fip, FILE *fop,struct node *huffman)
{
	//printf("true");
	char ch;
	while((fscanf(fip, "%c", &ch)) != EOF) {
		path(huffman, ch, fop);
	}
  /*
    Encode fip using huffman code and write properly to fop.
  */
}

void decode(FILE *fip,FILE *fop,struct node *huffman)
{
	struct node *temp;
	temp = huffman;
	char ch;
	while((fscanf(fip, "%c", &ch)) != EOF) {
		if(ch == '0') {
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
		if(temp->left == NULL && temp->right == NULL) {
			fprintf(fop, "%c", temp->data);
			temp = huffman;
		}
	}
	
  /*
    Decode fip using huffman code and write properly to fop.
  */
}
