#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *left;
	struct node *right;

};
struct node *q[100];
int front,rear;
front=-1;rear=-1;
struct node *create(int n)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=n;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}
void push(struct node *ptr)
{
	if(front == -1)
	{
		front++;
		rear++;
		q[rear]=ptr;
	}
	else
	{
		rear++;
		q[rear]=ptr;
	}
}
struct node *pop()
{
	struct node *tmp;
	tmp=q[front];
	front=front+1;
	return tmp;
}
int empty()
{
	if(front==-1||front == rear+1)
	{
		return 1;
	}
	else
		return 0;
}
struct node *insert(struct node *root,int n)
{
	if(root==NULL)
	{
		root=create(n);
	}
	else if(n<=root->data)
		root->left=insert(root->left,n);
	else if(n>root->data)
		root->right=insert(root->right,n);
	return root;
}
int min(struct node *root)
{
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root->data;
}
struct node *del(struct node *root,int n)
{
	if(n<root->data)
	{
		root->left=del(root->left,n);
	}
	else if(n>root->data)
	{
		root->right=del(root->right,n);
	}
	else
	{
		if(root->right==NULL&&root->right==NULL)
			root=NULL;
		else if(root->left==NULL)
			root=root->right;
		else if(root->right==NULL)
		       root=root->left;
		else
		{
			int k;
			k=min(root->right);
			root->data=k;
			root->right=del(root->right,k);
		}	
	}
	return root;
}

void level(struct node *root)
{
	struct node *ptr=root;
	push(ptr);
	while(!empty())
	{
		ptr=pop();
		printf("%d  ",ptr->data);
		if(ptr->left!=NULL)
			push(ptr->left);
		if(ptr->right!=NULL)
			push(ptr->right);

	}
}
void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d",root->data);
	inorder(root->right);
}
int main()
{
	int t,n;
	struct node *root=NULL;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&t);
		root=insert(root,t);
	}
	del(root,root->data);
	level(root);
	printf("\n");
	inorder(root);

}
