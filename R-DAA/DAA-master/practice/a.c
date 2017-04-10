#include <stdio.h>
void bubbleSort(float a[], int n)
{
	int i,j;
	float temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[i]>a[i+1])
			{
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
		}
	}
	for(i = 0; i<n;i++)
	{
		printf("Bubblesort : %f\n",a[i]);
	}
	printf("break========||");
}
int main()
{
		float a[10] = {0.002f, 0.245f ,0.235f, 0.89f, 0.292f , 0.775f, 0.221f, 0.664f, 0.887f , 0.885f};
		bubbleSort(a,10);

}