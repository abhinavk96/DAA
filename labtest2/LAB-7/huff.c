# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct node {
  struct node *left,*right;
  unsigned char data;
};
int total=0;
int totalinput = 0;
void decode(FILE *,FILE *,struct node *);
void encode(FILE *,FILE *,struct node *, int **);
void constructHuffman(struct node **, int **, int , struct node *);
void buildMinHeap(struct node **, int **, int );
int collectFrequency(FILE *, int **);

void restoredown(struct node **, int **, int , int );
void restoreup(struct node **, int **, int );
void insert(struct node **, int **, int *, struct node *);
struct node *extract(struct node **, int **, int *);

void traverse(struct node *, char *, char [][100], int);

int getfirstbit(unsigned char *n){
	int x;
	if(*n >= 128)x=1;
	else x = 0;
	*n *= 2;
	return x;
}

int main()
{
  FILE *fip,*fop,*fdec;
  int **frequency,n,i;		//frequency[0] = frequency; frequency[1]=huffmancode
  struct node **heap;
  struct node huffman;
  fip = fopen("input.txt","r");
    if(!fip)
        printf("Error");
  fop = fopen("encode.txt","w");
  frequency = (int **)malloc(256*sizeof(int *));
  for(i=0;i<256;i++)
    frequency[i]=(int *)malloc(2*sizeof(int));
  n = collectFrequency(fip, frequency);
  printf("%d\n",n);
  heap = (struct node **)malloc(n*sizeof(struct node *));
  //rewind(fip);
  buildMinHeap(heap,frequency,n);
  constructHuffman(heap,frequency,n,&huffman);
  rewind(fip);
  encode(fip,fop,&huffman, frequency);
  fclose(fop);
  fop = fopen("encode.txt","r");
  fdec = fopen("decode.txt","w");
  decode(fop,fdec,&huffman);
  fclose(fip);
  fclose(fop);
  fclose(fdec);
  return 0;
}

int collectFrequency(FILE *fp,int **frequency)
{
  int n=0,c;
  /* Count the total number of distinct unsigned characters in the file */
  printf("collectFrequency:\n");
  while((c = fgetc(fp)) != EOF){
//      printf("%d ",c);
  	if(frequency[c][0] == 0)
  		n++;
//      printf("Error");

  		frequency[c][0]++;
  		frequency[c][1]++;
  		totalinput += 8;
  }
  printf("end\n");
  return n;
}

void restoredown(struct node **heap, int **frequency, int n, int ind){
	int minchild;
	if(2*ind+1 >= n)return;
	else if(2*ind+2 >= n)minchild = 2*ind+1;
	else {
		int val1 = frequency[heap[2*ind+1]->data][0];
		int val2 = frequency[heap[2*ind+2]->data][0];
		if(val1 < val2)minchild = 2*ind+1;
		else minchild = 2*ind+2;
	}

	int val1 = frequency[heap[ind]->data][0];
	int val2 = frequency[heap[minchild]->data][0];

	if(val2 < val1){
		struct node *x = heap[ind];
		heap[ind] = heap[minchild];
		heap[minchild] = x;
		restoredown(heap, frequency, n, minchild);
	}
}

void restoreup(struct node **heap, int **frequency, int ind){
	if(ind == 0)return;
	else{
		int parent = (ind-1)/2;
		int val2 = frequency[heap[ind]->data][0];
		int val1 = frequency[heap[parent]->data][0];

		if(val2 < val1){
			struct node *x = heap[ind];
			heap[ind] = heap[parent];
			heap[parent] = x;
			restoreup(heap,frequency,parent);
		}
	}
}

void insert(struct node **heap, int **frequency, int *n, struct node *x){
	heap[*n] = x;
	restoreup(heap,frequency, *n);
	(*n)++;
}

struct node *extract(struct node **heap, int **frequency, int *n){
	struct node *tmp = heap[0];
	heap[0] = heap[(*n)-1];
	heap[(*n)-1] = NULL;
	(*n)--;
	restoredown(heap,frequency, *n, 0);
	return tmp;
}

void buildMinHeap(struct node **heap, int **frequency, int n)
{
  /* 
     This is exactly similar to the buil_max_heap that you have created in previous lab assignment with the following difference:
     In heap you store the unsigned characters, but unlike previous implementation the comaprison between different unsigned characters are not by their ASCII but by their frequency.
     You should use the same hash function to look for the frequency of the specific unsigned character
  */
     int i,k=0;
     for(i=0;i<256;i++)
     	if(frequency[i][0] > 0){
     		struct node *tmp;
     		tmp = (struct node *)malloc(sizeof(struct node));
     		tmp->data = i;
     		tmp->left = NULL;
     		tmp->right = NULL;
     		heap[k++] = tmp;
     		//printf("%c : %d\n",i,frequency[i][0]);
     	}

     for(i=n/2;i>=0;i--){
     	restoredown(heap,frequency,n,i);
     }
}

void constructHuffman(struct node **heap, int **frequency, int n, struct node *huffman)
{
  /*
    Construct the huffman tree from the given heap.
    Note that you may need to change the heap while contruction (deletion, insertion). Please import the appropriate function written in previous classes.
    Also, note that, you may need to store frequency of new elements that are not there in the file and thus in the array fequency.
    For this you may change the content of the array frequency correctly and figure out a way to store the frequency of tree nodes in the array.
    Otherwise you may use your own data structure
  */
    struct node * tmp = NULL;
    while(n != 0){
    	struct node *x = extract(heap,frequency, &n);
    	//printf("%c %d\n",x->data,frequency[x->data][0]);
    	if(tmp == NULL){
    		tmp = (struct node*)malloc(sizeof(struct node));
    		tmp->left = x;
    		tmp->right = NULL;
    		tmp->data = x->data;
    	}
    	else if(tmp->right == NULL){
    		tmp->right = x;
    		frequency[tmp->data][0] += frequency[x->data][0];
    		insert(heap,frequency,&n,tmp);
    		tmp = NULL;
    	}
    }
    huffman->data = tmp->left->data;
    huffman->left = tmp->left->left;
    huffman->right = tmp->left->right;
}

int btoi(unsigned char *str){
	int i=0;
	int total = 0;
	while(1){
		unsigned char c = str[i++];
		if(c == '\0')break;
		total *= 2;
		if(c == '1')total++;
	}
	return total;
}

void traverse(struct node *p, char *str, char codes[][100], int top){
	
	if(p->left == NULL && p->right == NULL){
		str[top] = '\0';
		strcpy(codes[p->data],str);
		//total += strlen(str)*frequency[p->data][1];
		//printf("%c->%s\n",p->data, codes[p->data]);
		return;
	}
	if(p->left){
		str[top] = '0';
		traverse(p->left, str, codes, top+1);
	}
	if (p->right){
		str[top] = '1';
		traverse(p->right, str, codes, top+1);
	}

}

void encode(FILE *fip,FILE *fop,struct node *huffman, int **frequency)
{
  /*
    Encode fip using huffman code and write properly to fop.
  */
    char tmp[100];
    char codes[128][100];
    traverse(huffman, tmp, codes, 0);

    int c;
    int x=0;
    int count = 0;
    while(fread(&c,1,1,fip) > 0){
    	//printf("%c",c);
    	
    	int i=0;
    	while(codes[c][i]!='\0'){
    		x*=2;
    		x += codes[c][i]-'0';
    		count++;
    		if(count == 8){
    			//printf("%c",126);
    			fprintf(fop,"%c",x);
    			count = 0;
    			x = 0;
    		}
    		i++;
    	}
    }
   
    

    /*c = getc(fip);
    	int i=0;
    while(codes[' '][i]!=0){
    	x*=2;
    	x += codes[' '][i]-'0';
    	i++;
    }

    fprintf(fop,"%c",x);
    printf("%d\n",x);
    fread(&x,1,1,fop);
    printf("%c\n",x);*/
}

void decode(FILE *fip,FILE *fop,struct node *huffman)
{
  /*
    Decode fip using huffman code and write properly to fop.
  */
  	unsigned char x;
  	int count = 0;
  	struct node *p = huffman;
  	fread(&x,1,1,fip);
  	while(1){
  		if(p->left == NULL && p->right == NULL){
  			fprintf(fop,"%c",p->data);
  			p = huffman;
  		}
  		if(getfirstbit(&x) == 0){
  			p = p->left;
  		}
  		else p = p->right;
  		count++;
  		if(count == 8){
  			if(fread(&x,1,1,fip) == 0)break;
  			count = 0;

  		}
  	}
}
