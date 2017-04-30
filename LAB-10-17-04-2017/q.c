#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct node{
struct node* parent;
int **board;
int x,y;
int cost;
int level;
};

void print(int ** board)
{
  int i,j;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

struct node* newNode(int **board, int x, int y, int newX, int newY, int level, struct node* parent)
{
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->parent = parent;
  temp->board = (int **)malloc(3*sizeof(int *));
  temp->board[0] = (int *)malloc(3*sizeof(int));
  temp->board[1] = (int *)malloc(3*sizeof(int));
  temp->board[2] = (int *)malloc(3*sizeof(int));

  int i,j;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      temp->board[i][j] = board[i][j];
    }
  }
  int t = temp->board[x][y];
  temp->board[x][y]= temp->board[newX][newY];
  temp->board[newX][newY] = t;
  temp->cost = INT_MAX;
  temp->level = level;
  temp->x = newX;
  temp->y = newY;
  return temp;
}

int calculateCost(int ** board)
{
    int x = 0,i,j, final[3][3];
    for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
      {
        final[i][j]=x++;
      }
    }
    int count = 0;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        if (board[i][j] && board[i][j] != final[i][j])
           count++;
    return count;
}
int isSafe(int x, int y)
{
    return (x >= 0 && x < 3 && y >= 0 && y < 3);
}
void printPath(struct node* root)
{
    if (root == NULL)
        return;
    printPath(root->parent);
    print(root->board); 
    printf("\n");
}



void solve(int **);
int main()
{
  int i,**board;
  board = (int **)malloc(3*sizeof(int *));
  board[0] = (int *)malloc(3*sizeof(int));
  board[1] = (int *)malloc(3*sizeof(int));
  board[2] = (int *)malloc(3*sizeof(int));
  for(i=0;i<3;i=i+1) {
    scanf("%d%d%d",&board[i][0],&board[i][1],&board[i][2]);
  }
  solve(board);
  return 0;
}
int isSolvable(int **board)
{
  int i,j,k,l,x=0, z,y,solvable = 0, inversion_count = 0;

  int arr[9];
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      arr[x++] = board[i][j];
    }
  }
  for(i=0;i<8;i++)
  {
    for(j=i;j<9;j++)
    {
      if(arr[i]&&arr[j]&&arr[i]>arr[j])
      {
        inversion_count++;
      }
    }
  }
  if(inversion_count%2!=0)
  {
    return 0;
  }
  return 1;
}
int comparator(const void * p, const void* q)
{
  struct node* a = ( struct node*)p;
  struct node* b = ( struct node*)q;
  if(a->cost>b->cost)
    return 1;
  else
    return -1;
}
void push(struct node*Q[], struct node* root, int* size)
{
  Q[*size] = root;
  *size = *size + 1;
  qsort((void*)Q,*size,sizeof(Q[0]),comparator);
}
struct node* pop(struct node*Q[], int *size)
{
  struct node* top = Q[*size -1];
  *size = *size -1;
  return top;
}
void findCoordinates(int** board, int *x, int* y)
{
  int i,j;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      if(board[i][j] == 0)
      {
        *x = i;
        *y = j;
        return;
      }
    }
  }
}
void solve(int **board)
{
  /* Print the steps required to solve the puzzle or print unsolvable */
  if(!isSolvable(board))
  {
    printf("unsolvable\n");
    return;
  }
   int x,y,i;
  findCoordinates(board, &x, &y);
   printf("%d %d",x,y);
  int row[] = { 1, 0, -1, 0 };
  int col[] = { 0, -1, 0, 1 };
  int size = 0;
  struct node* root = newNode(board,x,y,x,y,0,NULL);
  root->cost = calculateCost(board);
  struct node* Q[1000000];
  push(Q,root,&size);
  while(size > 0)
  {

    struct node* min = pop(Q,&size);
    if(min->cost==0)
    {
      printPath(min);
      return;
    }
    for(i=0;i<4;i++)
    {
       if (isSafe(min->x + row[i], min->y + col[i]))
            {
                
                struct node* child = newNode(min->board, min->x,
                              min->y, min->x + row[i],
                              min->y + col[i],
                              min->level + 1, min);
                child->cost = calculateCost(child->board);
 
                push(Q,child,&size);
            }
    }
  }



}
