#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 1000
#define MAX_BINARY_SIZE 1000
struct node 
{
	int value;
	struct node* left;
	struct node* right;
	struct node* parent;
};

struct heap
{
	struct node* root;
	int heapsize;
};

struct node** createQueue(int *, int *);
void enQueue(struct node **, int *, struct node *);
struct node *deQueue(struct node **, int *);
void initialize(struct heap* hp)
{
	hp->root = NULL;
	hp->heapsize = 0;
}
void printLevelOrder(struct node* root)
{
    int rear, front;
    struct node **queue = createQueue(&front, &rear);
    struct node *temp_node = root;
 
    while (temp_node)
    {
        printf("%d ", temp_node->value);
 
        /*Enqueue left child */
        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);
 
        /*Enqueue right child */
        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);
 
        /*Dequeue node and make it temp_node*/
        temp_node = deQueue(queue, &front);
    }
}
struct node** createQueue(int *front, int *rear)
{
    struct node **queue =
        (struct node **)malloc(sizeof(struct node*)*MAX_Q_SIZE);
 
    *front = *rear = 0;
    return queue;
}
 
void enQueue(struct node **queue, int *rear, struct node *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}
 
struct node *deQueue(struct node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}
 
int binary_rep(int val)
{
	if(val == 0)
		return 0;
	else
		return ((val % 2) + 10 * binary_rep(val/2));
}

struct node* getnode(int x)
{
	struct node* temp = (struct node*) malloc((sizeof(struct node)));
	temp->value = x;
	temp->left = NULL;
	temp->left = NULL;
	temp->parent = NULL;
}
void restore_up(struct node* temp)
{
	if (temp->parent == NULL) {
		return;
	}

	if (temp->parent->value < temp->value) {
		// Swap child and parent
		int t = temp->value;
		temp->value = temp->parent->value;
		temp->parent->value = t;

		restore_up(temp->parent);
	}
}
void insert_util(struct heap* hp, struct node* new_node)
{
	int bin = binary_rep(hp->heapsize);
	int ar[MAX_BINARY_SIZE];
	int count = 0;
	int b;
	//printf("%d", bin);
	while(bin > 0)
	{
		ar[count++] = bin % 10;
		bin /= 10;
	}
	struct node *temp = hp->root;
	count--; // For ignoring the first bit as it signifies root
	while(count >= 2)
	{
		if(ar[--count] == 1)
			temp = temp->right;
		else
			temp = temp->left;
	}
	// Adjusting parent and left/right child
	new_node->parent = temp;
	if(temp != NULL)
	{
		if(ar[0] == 0)
			temp->left = new_node;
		else
			temp->right = new_node;
	}
	
}
struct node* insert(struct heap* hp, int element)
{
	hp->heapsize += 1;
	//printf("heap_size = %d\n", hp->heapsize);
	struct node* temp = getnode(element);
	if(hp->heapsize == 1)
	{
		hp->root = temp;
		return temp;
	}
	insert_util(hp, temp);
	restore_up(temp);
	return hp->root;
}
void printInorder(struct node* node)
{
     if (node == NULL)
          return;
     printInorder(node->left);
     printf("%d ", node->value);  
     printInorder(node->right);
}
void max_heapify(struct node* root)
{
	if(root->left != NULL && root->right != NULL)
	{
		if(root->value < root->left->value && root->value < root->right->value)
		{
			if(root->right->value > root->left->value)
			{
				int temp = root->value;
				root->value = root->right->value;
				root->right->value = temp;
				max_heapify(root->right);
			}
			else
			{
				int temp = root->value;
				root->value = root->left->value;
				root->left->value = temp;
				max_heapify(root->left);
			}
		}
		else if(root->value > root->right->value && root->value < root->left->value)
		{
			int temp = root->value;
			root->value = root->left->value;
			root->left->value = temp;
			max_heapify(root->left);
		}
		else if(root->value < root->right->value && root->value > root->left->value)
		{
			int temp = root->value;
			root->value = root->right->value;
			root->right->value = temp;
			max_heapify(root->right);
		}

	}
	else if(root->left != NULL && root->)
}
struct node* delete(struct heap* hp)
{

}
int main()
{
	struct heap hp;
	initialize(&hp);
	//printf("*");
	while(1)
	{
		int n;
		scanf("%d", &n);
		
		hp.root = insert(&hp, n);
		printLevelOrder(hp.root);
		printf("\n");
	}
	return 0;
}