#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NINIT 100
#define NMAX 200

typedef struct {
   int id;
   int rating;
} hnode;

void initDB ( hnode H[], int n )
{
   int i;

   for (i=0; i<n; ++i) {
      H[i].id = i;
      H[i].rating = rand() % 11;
   }
}

void heapify ( hnode H[], int n, int i )
{
   int l, r, m;
   hnode t;

   while (i < n) {
      l = 2*i + 1; r = 2*i + 2;
      if (l >= n) return;
      if (r >= n) m = l;
      else m = (H[l].rating >= H[r].rating) ? l : r;
      if (H[m].rating <= H[i].rating) return;
      t = H[m]; H[m] = H[i]; H[i] = t;
      i = m;
   }
}

void makeHeap ( hnode H[], int n )
{
   int i;

   for (i=n/2-1; i>=0; --i) heapify(H,n,i);
}

void initIndex ( hnode H[], int IDX[], int n )
{
   int i;

   for (i=0; i<n; ++i) IDX[H[i].id] = i;
}

void moveUp (  hnode H[], int n, int i, int IDX[] )
{
   int p;
   hnode t;

   while (i > 0) {
      p = (i - 1) / 2;
      if (H[p].rating >= H[i].rating) return;
      t = H[p]; H[p] = H[i]; H[i]= t;
      IDX[H[p].id] = p; IDX[H[i].id] = i;
      i = p;
   }
}

void moveDown ( hnode H[], int n, int i, int IDX[] )
{
   int l, r, m;
   hnode t;

   while (i < n) {
      l = 2*i + 1; r = 2*i + 2;
      if (l >= n) return;
      if (r >= n) m = l;
      else m = (H[l].rating >= H[r].rating) ? l : r;
      if (H[m].rating <= H[i].rating) return;
      t = H[m]; H[m] = H[i]; H[i] = t;
      IDX[H[m].id] = m; IDX[H[i].id] = i;
      i = m;
   }
}

void insert ( hnode H[], int n, int id, int r, int IDX[] )
{
   if (id < 0) {
      fprintf(stderr, "Error in insert(): Invalid index\n");
      return;
   }
   H[n].id = id; H[n].rating = r; IDX[id] = n;
   moveUp(H,n+1,n,IDX);
}

void upVote ( hnode H[], int n, int i, int IDX[] )
{
   i = IDX[i];
   if (i < 0) {
      fprintf(stderr, "Error in upVote(): Invalid index\n");
      return;
   }
   ++(H[i].rating);
   moveUp(H,n,i,IDX);
}

void downVote ( hnode H[], int n, int i, int IDX[] )
{
   i = IDX[i];
   if (i < 0) {
      fprintf(stderr, "Error in downVote(): Invalid index\n");
      return;
   }
   if (H[i].rating > 0) {
      --(H[i].rating);
      moveDown(H,n,i,IDX);
   }
}

void delete ( hnode H[], int n, int i, int IDX[] )
{
   int j, delval;

   j = IDX[i];
   if (j < 0) {
      fprintf(stderr, "Error in delete(): Invalid index\n");
      return;
   }
   delval = H[j].rating; IDX[i] = -(1 + delval);
   if (j == n-1) return;
   H[j] = H[n-1]; IDX[H[j].id] = j;
   if (H[j].rating > delval)
      moveUp(H,n-1,j,IDX);
   else
      moveDown(H,n-1,j,IDX);
}

void prnHeap ( hnode H[], int n )
{
   int i;

   printf("Current heap (%d nodes)", n);
   for (i=0; i<n; ++i) {
      if (i%10) printf(" "); else printf("\n\t");
      printf("(%d,%d)", H[i].id, H[i].rating);
   }
   printf("\n");
}

void prnIndex ( int IDX[], int N )
{
   int i;

   printf("Current index array (%d cells used)", N);
   for (i=0; i<N; ++i) {
      if (i%10) printf(" "); else printf("\n\t");
      printf("%d(%d)", i, IDX[i]);
   }
   printf("\n");
}

int main ( int argc, char *argv[] )
{
   int n, N, IDX[NMAX], r, i;
   hnode H[NMAX];

   srand((unsigned int)time(NULL));
   if (argc > 1) n = atoi(argv[1]); else n = NINIT;
   if (n < 0) n = -n;
   if (n > NMAX) n = NMAX;
   N = n;

   initDB(H,n);

   prnHeap(H,n);

   makeHeap(H,n);
   initIndex(H,IDX,n);

   printf("--------------------------------------------------------------------------------\n");
   prnHeap(H,n); prnIndex(IDX,N);
   printf("--------------------------------------------------------------------------------\n");

   while (1) {
      r = rand() % 100;
      if (r == 0) {
         printf("Operation: break\n");
         printf("--------------------------------------------------------------------------------\n");
         break;
      } else if (r <= 15) {
         i = rand() % 11;
         printf("Operation: insert(%d)\n", i);
         if (N == NMAX) {
            printf("*** Error during insert: Database is full\n");
         } else {
            insert(H,n,N,i,IDX); ++n; ++N;
         }
      } else if (r < 25) {
         i = rand() % N;
         while ((i < N) && (IDX[i] >= 0)) ++i;
         if (i == N) continue;
         printf("Operation: undelete(%d)\n", i);
         insert(H,n,i,-(IDX[i]+1),IDX); ++n;
      } else if (r < 55) {
         i = rand() % N;
         while ((i < N) && (IDX[i] < 0)) ++i;
         if (i == N) continue;
         printf("Operation: upvote(%d)\n", i);
         upVote(H,n,i,IDX);
      } else if (r < 85) {
         i = rand() % N;
         while ((i < N) && (IDX[i] < 0)) ++i;
         if (i == N) continue;
         printf("Operation: downvote(%d)\n", i);
         downVote(H,n,i,IDX);
      } else {
         i = rand() % N;
         while ((i < N) && (IDX[i] < 0)) ++i;
         if (i == N) continue;
         printf("Operation: delete(%d)\n", i);
         delete(H,n,i,IDX); --n;
      }
      prnHeap(H,n); prnIndex(IDX,N);
      printf("--------------------------------------------------------------------------------\n");
   }

   exit(0);
}
