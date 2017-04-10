#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *left;
	struct node *right;
};
struct node *create(int n){
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=n;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}
struct node *insert(struct node *root,int n)
{
	if(root==NULL)
		root=create(n);
	else if(root->data>=n)
		root->left=insert(root->left,n);
	else if(root->data<n)
		root->right=insert(root->right,n);
	return root;
}
void leaf(struct node *root)
{
	int ar[100];
	path(root,ar,0);
}
void path(struct node *root,int ar[100],int len)
{
	if(root==NULL)
		return root;
	ar[len]=root->data;
	len++;
	if(root->left==NULL&&root->right==NULL)
		print(ar,len);
	path(root->left,ar,len);
	path(root->right,ar,len);
}
void print(int ar[100],int len)
{
	int i;
	for(i=0;i<len;i++)
		printf("%d  ",ar[i]);
	printf("\n");
}
int main()
{
	int n,t;
	struct node *root=NULL;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&t);
		root=insert(root,t);
	}
	leaf(root);
	return 0;
}
