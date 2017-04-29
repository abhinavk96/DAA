#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* parent;
	struct node *left;
	struct node *right;
};
void push(struct node *q[],int *front,int *rear,struct node *root)
{
	if(*front==-1)
		(*front)++;
	*rear=*rear+1;
	q[*rear]=root;
}
struct node *pop(struct node *q[],int *front,int *rear)
{
	struct node *t;
	t=q[*front];
	*front=*front+1;
	return t;
}
int empty(int front,int rear)
{
	if(front==-1||front==rear+1)
		return 1;
	else
		return 0;
}
struct node *insert(struct node *root,int t)
{
	struct node *tmp,*p;
	int n,f,y;
	int front=-1;
	int rear=-1;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=t;
	tmp->left=NULL;
	tmp->right=NULL;
	if(root==NULL)
	{
		tmp->parent=NULL;
		root=tmp;
		return root;
	}
	f=0;
	struct node *q[100];
	push(q,&front,&rear,root);
	while(!empty(front,rear))
	{
		p=pop(q,&front,&rear);
		if(p->left==NULL&&p->right==NULL)
		{
			f=1;
			break;
		}
		else if(p->left!=NULL && p->right==NULL)
		{
			f=2;
			break;
		}
		else
		{
			push(q,&front,&rear,p->left);
			push(q,&front,&rear,p->right);
		}
	}
	if(f==1)
	{
		p->left=tmp;
		tmp->parent=p;
		while(tmp!=NULL&&(tmp->parent!=NULL&&(tmp->parent->data)<tmp->data))
		{
			
			y=tmp->data;
			tmp->data=(tmp->parent->data);
			(tmp->parent->data)=y;
			tmp=tmp->parent;
		}
		return root;
	}
	else if(f==2)
	{
		p->right=tmp;
		tmp->parent=p;
		while(tmp!=NULL&&(tmp->parent!=NULL&&(tmp->parent->data)<(tmp->data)))
		{
			
			y=tmp->data;
			tmp->data=(tmp->parent->data);
			(tmp->parent->data)=y;
			tmp=tmp->parent;
		}
	}
	return root;

}
void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d   ",root->data);
	inorder(root->right);
}
void heapify(struct node *p)
{
	struct node *largest;
	largest=p;
	if(p->left !=NULL && largest->data<p->left->data)
		largest=p->left;
	if(p->right!=NULL &&largest->data<p->right->data)
		largest=p->right;
	if(largest!=p)
	{
		int tmp;
		tmp=p->data;
		p->data=largest->data;
		largest->data=tmp;
		heapify(largest);
	}
}
struct node *level_order(struct node *root)
{
	struct node *p=root;
	struct node *q[100];
	int front,rear;
	front=-1;
	rear=-1;
	push(q,&front,&rear,root);
	while(!empty(front,rear))
	{
		p=pop(q,&front,&rear);
		if(p->left!=NULL)
			push(q,&front,&rear,p->left);
		if(p->right!=NULL)
			push(q,&front,&rear,p->right);
	}
	return p;
}
int extract_max(struct node *root,int n)
{
	if(root==NULL)
		return -1;
	else
	{
		int max;
		max=root->data;
		struct node *p=root;
		if(root->left==NULL)
			return max;
		p=level_order(root);
		root->data=p->data;
		struct node *t=p->parent;
		p->parent=NULL;
		if(t->left==NULL)
			t->left=NULL;
		else
			t->right=NULL;
		heapify(root);
		return max;
	}
}
int main()
{
	struct node *root=NULL;
	int n,max;
	scanf("%d",&n);
	int i,t;
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		root=insert(root,t);
	}
	max=extract_max(root,n);
	printf("\n%d\n",max);
	 inorder(root);
}
