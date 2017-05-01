// C++ program to solve knapsack problem using
// branch and bound
//#include <bits/stdc++.h>
//using namespace std;

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    // level  --> Level of node in decision tree (or index
    //             in arr[]
    // profit --> Profit of nodes on path from root to this
    //            node (including this node)
    // bound ---> Upper bound of maximum profit in subtree
    //            of this node/
    int level, profit, bound,total;
    float weight;
};
  
// Stucture for Item which store weight and corresponding
// value of Item
struct Item
{
    float weight;
    int value;
};
 
void enqueue(struct Node * queue, int * front , int * rear, struct Node nw )
{
    int element;
    if(*rear==500)
    {
        printf("\nOverflow!!");
    }
    else
    {
    	if(*front==-1)
    		*front = 0;
        queue[++(*rear)]=nw;
        
    }
 
}
 
struct Node dequeue(struct Node * queue, int * front , int * rear)
{
    if(*rear+1==*front)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        (*front)++;
    }
	
    return (queue[(*front)-1]);
}
 
int empty(struct Node * queue, int * front, int *rear)
{
	if(*front==*rear+1)
		return 1;
	return 0;
} 
// Node structure to store information of decision
// tree
// Comparison function to sort Item according to
// val/weight ratio
bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
 
// Returns bound of profit in subtree rooted with u.
// This function mainly uses Greedy solution to find
// an upper bound on maximum profit.
int bound(Node u, int n, int W, Item arr[])
{
    // if weight overcomes the knapsack capacity, return
    // 0 as expected bound
    if (u.weight >= W)
        return 0;
 
    // initialize bound on profit by current profit
    int profit_bound = u.profit;
 
    // start including items from index 1 more to current
    // item index
    int j = u.level + 1;
    int totweight = u.weight;
 
    // checking index condition and knapsack capacity
    // condition
    while ((j < n) && (totweight + arr[j].weight <= W))
    {
        totweight    += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }
 
    // If k is not n, include last item partially for
    // upper bound on profit
    if (j < n)
        profit_bound += (W - totweight) * arr[j].value /
                                         arr[j].weight;
 
    return profit_bound;
}
 
// Returns maximum profit we can get with capacity W
int knapsack(int W, struct Item arr[], int n)
{
   
    int i,j;
    for(i=0;i<n;i++)
	for(j=i+1;j<n;j++)
	if( (arr[j].value/arr[j].weight) < (arr[j+1].value/arr[j+1].weight)  )
	{
	struct Item tmp=arr[j];
	arr[j]=arr[j+1];
	arr[j+1]=tmp;
	}

 
    
    struct Node queue[100];
  //  int front=0,rear=0;
  int front=-1,rear=-1; 
    struct Node u, v;
 
    u.level = -1;
    u.profit = u.weight = 0;
   
    enqueue(queue,&front,&rear,u);
   
    int maxProfit = 0;
    while (!(front==rear+1))
    {
        

	u=dequeue(queue,&front,&rear);
        
 
       
        if (u.level == -1)
            v.level = 0;
 
        
        if (u.level == n-1)
            continue;
 
      
        v.level = u.level + 1;
 
       
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;
 
        
        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;
 
        
        v.bound = bound(v, n, W, arr);
 
       
        if (v.bound > maxProfit)
            enqueue(queue,&front,&rear,v);
 
      
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
           enqueue(queue,&front,&rear,v);
    }
 
    return maxProfit;
}

int knapsack_const(int W, struct Item arr[], int n,int m)
{
   
    int i,j;
    for(i=0;i<n;i++)
	for(j=i+1;j<n;j++)
	if( (arr[j].value/arr[j].weight) < (arr[j+1].value/arr[j+1].weight)  )
	{
	struct Item tmp=arr[j];
	arr[j]=arr[j+1];
	arr[j+1]=tmp;
	}

 
    
    struct Node queue[100];
  //  int front=0,rear=0;
  int front=-1,rear=-1; 
    struct Node u, v;
 
    u.level = -1;
    u.profit = u.weight = u.total = 0;
   
    enqueue(queue,&front,&rear,u);
   
    int maxProfit = 0;
    while (!(front==rear+1))
    {
        

	u=dequeue(queue,&front,&rear);
       
	if(u.total >= m)
		continue;    
 
       
        if (u.level == -1)
            v.level = 0;
 
        
        if (u.level == n-1)
            continue;
 
      
        v.level = u.level + 1;
 		v.total = u.total +1;
       
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;
 
        
        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;
 
        
        v.bound = bound(v, n, W, arr);
 
       
        if (v.bound > maxProfit)
            enqueue(queue,&front,&rear,v);
 
      
        v.weight = u.weight;
        v.profit = u.profit;
        v.total = u.total;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
           enqueue(queue,&front,&rear,v);
    }
 
    return maxProfit;
}
 
// driver program to test above function
#include <stdio.h>
#include <stdlib.h>

int knapsack_basic(int,int,int *,int *);
int knapsack_constrained(int,int,int *,int *,int);
int knapsack_multiple(int,int *,int,int *,int *);
int main()
{
  int i,W,n,m,*c,*w,p,*mW;
 /*scanf("%d",&n);
  scanf("%d",&W);
  c=(int *)malloc(n*sizeof(int));
  w=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
    scanf("%d",&c[i]);
  for(i=0;i<n;i++)
    scanf("%d",&w[i]);
  printf("Knapsack Basic : %d\n",knapsack_basic(W,n,c,w));*/
  scanf("%d",&n);
  scanf("%d",&W);
  c=(int *)malloc(n*sizeof(int));
  w=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
    scanf("%d",&c[i]);
  for(i=0;i<n;i++)
    scanf("%d",&w[i]);
  scanf("%d",&p);
  printf("Knapsack Constrained : %d\n",knapsack_constrained(W,n,c,w,p));
  /*scanf("%d",&n);
  scanf("%d",&m);
  mW=(int *)malloc(m*sizeof(int));
  c=(int *)malloc(n*sizeof(int));
  w=(int *)malloc(n*sizeof(int));
  for(i=0;i<m;i++)
    scanf("%d",&mW[i]);
  for(i=0;i<n;i++)
    scanf("%d",&c[i]);
  for(i=0;i<n;i++)
    scanf("%d",&w[i]);
  printf("Knapsack Multiple : %d\n",knapsack_multiple(m,mW,n,c,w));*/
  return 0;
}

int knapsack_basic(int W,int n,int *c,int *w)
{
	int i;
	struct Item arr[n];
	for(i=0;i<n;i++)
	{
		arr[i].value=c[i];
		arr[i].weight=w[i];
	}	
  knapsack(W,arr, n);
 /* W = 50;   // Weight of knapsack
    Item arr[] = {{2, 40}, {3.14, 50}, {1.98, 100}};
    n = sizeof(arr) / sizeof(arr[0]);
    knapsack(W,arr,n);*/
}

int knapsack_constrained(int W,int n,int *c,int *w,int p)
{
  int i;
	struct Item arr[n];
	for(i=0;i<n;i++)
	{
		arr[i].value=c[i];
		arr[i].weight=w[i];
	}	
  knapsack_const(W,arr, n,p);
}

int knapsack_multiple(int m,int *mW,int n,int *c,int *w)
{
  /* implement the multiple knapsack problem */ 
}
