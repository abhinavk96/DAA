#include <stdio.h>
#include <stdlib.h>
//void insert (int input, int hashtable[], int k);
//int hash(int n, int k);
int main()

{


	int k= 5,i;
	int hashtable[5] = {0};
	//printf("Hello");
	insert(1234,hashtable,k);
	insert(1101,hashtable,k);
	insert(104,hashtable,k);
	insert(89,hashtable,k);
	insert(754,hashtable,k);
	for(i=0;i<k;i++)
	{
	 printf("%d\t",hashtable[i]);
	}

}




	
