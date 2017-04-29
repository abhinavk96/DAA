#include <stdio.h>
#include <stdlib.h>
#define SIZE 11
struct node
{
	int data;
	struct node* next;
};

void insert(struct node* array[], int value)
{
	int h = value % SIZE;
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp-> data = value;
	temp->next = NULL;
	struct node* root = array[h];
	if(root == NULL)
		array[h] = temp;
	else
	{
		temp->next = root;
		array[h] = temp;
	}
}

int search(struct node* array[], int value)
{
	int h = value % SIZE;
	struct node* root = array[h];
	while(root != NULL)
	{
		if(root->data == value)
			return 1;
		root = root->next; 
	}
	return 0;
}

void display(struct node* array[])
{
	printf("\n\nDISPLAY:\n");
	for(int i = 0; i < SIZE; i++)
	{
		printf("%d --> ", i);
		struct node* temp = array[i];
		while(temp != NULL)
		{
			printf("%d --> ", temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}
int main()
{
	int n;
	
	struct node* array[SIZE];
	for(int i = 0; i < SIZE; i++)
		array[i] = NULL;
	char choice;
	int x;
	while(1)
	{
		scanf("%c", &choice);
		switch(choice)
		{
			case 'd':
				display(array);
				printf("\n\n");
				break;

			case 'i':
				
				scanf("%d", &x);
				insert(array, x);
				printf("\nInserted...\n\n");
				break;
			case 's':
				scanf("%d", &x);
				if(search(array, x))
					printf("Found\n\n");
				else
					printf("Not found\n\n");
				break;
			case 'q':
				exit(0);
				break;
			default:
				printf("Wrong choice\n\n");
				break;
		}
		getchar();
	}
} 