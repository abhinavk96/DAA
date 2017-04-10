#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
};

struct tree* queue[9999];
int rear = -1,front = -1;


void enqueue(struct tree* item)
{
	if(front == -1)
		front = 0;
	rear++;
	queue[rear] = item;
}

struct tree* dequeue()
{
	if(front == -1 || front == rear +1)
		return 0;
	struct tree* temp = queue[front];
	front++;
	return temp;	
}

int isempty()
{
	if(front == -1 || front == rear + 1)
		return 1;
	else 
		return 0;
}

struct tree* getnode(struct tree* root,int item)
{
	struct tree* temp = (struct tree*)malloc(sizeof(struct tree));
	temp -> data = item;
	temp -> left = temp -> right = NULL;
	return temp;
}

struct tree* insert(struct tree* root,int item)
{
	if(root == NULL){
		root = getnode(root,item);
	}	
	else if(root -> data >= item)
	{
		root -> left = insert(root -> left,item);
	}
	else{
		root -> right = insert(root -> right,item);
	}
	return root;
}

struct tree* remove(struct tree* root,int item)
{
	if(root == NULL)return root;
	else if(root -> data > item){
		root -> left = remove(root -> left,item);
	}
	else if(root -> data < item){
		root -> right = remove(root -> right,item);
	}
	else{
		if(root -> left == NULL && root -> right == NULL){
			free(root);
			return NULL;
		}
		else if(root -> left == NULL){
			struct tree* temp = root;
			root = root -> right;
			free(temp);
			return root;
		}
		else if(root -> right == NULL){
			struct tree* temp = root;
			root = root -> left;
			free(temp);
			return root;
		}
		else{
			struct tree* current = root -> right;
			while(current -> left != NULL)
				current = current -> left;
			root -> data = current -> data;
			root -> right = remove(root -> right,current -> data);	
			return root;
			}
		}
		return root;
}
int search_rec(struct tree* root,int item)
{
	if(root == NULL)
	 	return -1;
	
	if(root -> data == item)
		return 1;
	else if(root -> data > item)
		return (search_rec(root -> left,item));
	else if(root -> data < item) 		
		return (search_rec(root -> left,item));
	else 
		return 0;
}
	 
void preorder(struct tree* root)
{
	if(root == NULL)return;
	printf("%d ",root -> data);
	preorder(root -> left);	
	preorder(root -> right);
}	

void inorder(struct tree* root)
{
	if(root == NULL)return;
	inorder(root -> left);	
	printf("%d ",root -> data);
	inorder(root -> right);
}	

void postorder(struct tree* root)
{
	if(root == NULL)return;
	postorder(root -> left);	
	postorder(root -> right);
	printf("%d ",root -> data);
}

void levelorder(struct tree* root)
{	struct tree* item = root;
	enqueue(root);
	while(!isempty()){
		item = dequeue();	
		printf("%d ",item -> data);
		if(item -> left != NULL)
			enqueue(item -> left);
		if(item -> right != NULL)
			enqueue(item -> right);
	}	
}

int height(struct tree* root)
{
	if(root == NULL)
		return -1;
	int hleft = height(root->left);
	int hright = height(root->right);
	if(hleft > hright)
		return (1 + hleft);
	else 
		return	(1 + hright);	
}

int serach_nr(struct tree* root,int key)
{
	while(tree!=NULL){
		if( root -> data > key)
			root = root->left;
		else if(root ->data < key)
			root = root->right;
		else
			return 1;
	}
	return 0;
}

int main()
{	struct tree* root = NULL;
	int t,n,i,j;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&t);
		root = insert(root,t);
	}
	levelorder(root);
	int h = height(root);
	printf("\n%d",h);
	return 0;
}

	

