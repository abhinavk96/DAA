
#include <stdio.h>
#include <stdlib.h>

int knapsack_basic(int,int,int *,int *);
int knapsack_constrained(int,int,int *,int *,int);
int knapsack_multiple(int,int *,int,int *,int *);

struct Item{
int weight;
int value;
};

struct node {
	int level, profit, bound;
	float weight;
};
int main()
{
  int i,W,n,m,*c,*w,p,*mW;
  scanf("%d",&n);
  scanf("%d",&W);
  c=(int *)malloc(n*sizeof(int));
  w=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
    scanf("%d",&c[i]);
  for(i=0;i<n;i++)
    scanf("%d",&w[i]);
  printf("Knapsack Basic : %d\n",knapsack_basic(W,n,c,w));
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
  // scanf("%d",&n);
  // scanf("%d",&m);
  // mW=(int *)malloc(m*sizeof(int));
  // c=(int *)malloc(n*sizeof(int));
  // w=(int *)malloc(n*sizeof(int));
  // for(i=0;i<m;i++)
  //   scanf("%d",&mW[i]);
  // for(i=0;i<n;i++)
  //   scanf("%d",&c[i]);
  // for(i=0;i<n;i++)
  //   scanf("%d",&w[i]);
  // printf("Knapsack Multiple : %d\n",knapsack_multiple(m,mW,n,c,w));
  // return 0;
}
int comparator(const void * p, const void* q)
{
	struct Item a = *(const struct Item*)p;
	struct Item b = *(const struct Item*)q;
	float A = a.value/a.weight;
	float B = b.value/b.weight;
	float C = A-B;
	if(C>0)
		return 1;
	else
		return -1;
}
void push(struct node Q[], struct node root, int* size)
{
  Q[*size] = root;
  *size = *size + 1;
  int i,j;
  

}
struct node pop(struct node Q[], int *size)
{
  struct node top = Q[*size -1];
  *size = *size -1;
  return top;
}

int bound(struct node u, int n, int W, struct Item arr[])
{
    if (u.weight >= W)
        return 0;
    int profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;
    while ((j < n) && (totweight + arr[j].weight <= W))
    {
        totweight    += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }
    if (j < n)
        profit_bound += (W - totweight) * arr[j].value /
                                         arr[j].weight;
    return profit_bound;
}
int boundP(struct node u, int n, int W, struct Item arr[], int flag[], int* p)
{
	if(*p <=0)
		return 0;
    if (u.weight >= W)
        return 0;
    int profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;
    while ((*p > 0) && (j < n) && (totweight + arr[j].weight <= W))
    {
        totweight    += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
        
    }
    if (j < n){
    	if(!flag[j]){
        	*p = *p-1;
        	flag[j]=1;
        }
        profit_bound += (W - totweight) * arr[j].value /
                                         arr[j].weight;
    }
    return profit_bound;
}
int knapsack_basic(int W,int n,int *c,int *w)
{
  /* Implement basic 0/1 knapsack problem */
	struct Item items[n];
	int i,j;
	for(i=0;i<n;i++)
	{
		items[i].weight= w[i];
		items[i].value = c[i];
	}
		for(i=0;i<n;i++)
	{
		printf("%d %d\n", items[i].value,items[i].weight);
	}
	qsort((void*)items, n, sizeof(items[0]), comparator);
	for(i=0;i<n;i++)
	{
		printf("%d %d\n", items[i].value,items[i].weight);
	}
	struct node Q[10000];
	struct node u,v;
	u.level = -1;
	u.profit =0;
	u.weight = 0;
	int size =0;
	push(Q, u, &size);
	int maxProfit = 0;
	while(size>0)
	{
		u = pop(Q,&size);
		if(u.level == -1)
		{
			v.level = 0;

		}
		if(u.level == n-1)
			continue;
		v.level = u.level + 1;
		v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].value;
 
        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;
        v.bound = bound(v, n, W, items);
        if (v.bound > maxProfit)
            push(Q,v,&size);
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, items);
        if (v.bound > maxProfit)
            push(Q,v,&size);
	}
	return maxProfit;


}

int knapsack_constrained(int W,int n,int *c,int *w,int p)
{
  /* implement the constrained knapsack with the maximum number of elements*/
	struct Item items[n];
	int flag[n];
	int i,j;
	for(i=0;i<n;i++)
	{
		items[i].weight= w[i];
		items[i].value = c[i];
		flag[i] = 0;
	}
		for(i=0;i<n;i++)
	{
		printf("%d %d\n", items[i].value,items[i].weight);
	}
	qsort((void*)items, n, sizeof(items[0]), comparator);
	for(i=0;i<n;i++)
	{
		printf("%d %d\n", items[i].value,items[i].weight);
	}
	struct node Q[10000];
	struct node u,v;
	u.level = -1;
	u.profit =0;
	u.weight = 0;
	int size =0;
	push(Q, u, &size);
	int maxProfit = 0;
	while(size>0 && p>0)
	{
		u = pop(Q,&size);
		if(u.level == -1)
		{
			v.level = 0;

		}
		if(u.level == n-1)
			continue;
		v.level = u.level + 1;
		v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].value;
 
        if (v.weight <= W && v.profit > maxProfit){
        	flag[v.level] = 1;
        	p = p -1;
            maxProfit = v.profit;
        }
        v.bound = boundP(v, n, W, items, flag, &p);
        if (v.bound > maxProfit)
            push(Q,v,&size);
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = boundP(v, n, W, items,flag,&p);
        if (v.bound > maxProfit)
            push(Q,v,&size);
	}
	return maxProfit;
}

int knapsack_multiple(int m,int *mW,int n,int *c,int *w)
{
  
}
