#include <stdio.h>
#include <limits.h>
int arr[100005],k;
void max_heapify(int ind,int hs)
{
	int i,mx=arr[ind],p;
	int child[k+1];
	for(i=1;i<=k;i++)
	{
		child[i]=(k*ind+i)<hs?k*ind+i:-1;
	}
	p=ind;
	for(i=1;i<=k;i++)
	{
		if(child[i]!=-1&&arr[child[i]]>mx)
		{
			p=child[i];
			mx=arr[child[i]];
		}
	}
	if(p!=ind)
	{
		int tmp=arr[ind];
		arr[ind]=arr[p];
		arr[p]=tmp;
		max_heapify(p,hs);
	}
}
int exmx(int *hs)
{
	*(hs)--;
	int mx=arr[0];
	arr[0]=arr[*hs];
	max_heapify(0,*hs);
	return mx;
}
void increase_key(int ind,int key)
{
	int tmp;
	if(key<arr[ind])
	{
		return;
	}
	arr[ind]=key;
	while(ind>0&&arr[(ind-1)/k]<arr[ind])
	{
		tmp=arr[ind];
		arr[(ind-1)/k]=arr[ind];
		arr[ind]=tmp;
		ind=(ind-1)/k;
	}
}
void insert(int x,int *hs)
{
	(*hs)++;
	arr[*hs-1]=INT_MIN;
	increase_key(*hs-1,x);
}
int main()
{
	k=2;
    int t,x,hs=0,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%d",&x);
    	insert(x,&hs);
    	if(hs<3)
    	{
    		printf("-1\n");
    	}
    	else
    	{
    		a=exmx(&hs);
    		b=exmx(&hs);
    		c=exmx(&hs);
    		printf("%d %d %d\n",a,b,c);
    		insert(a,&hs);
    		insert(b,&hs);
    		insert(c,&hs);
    	}
    }
    return 0;
}
