#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
   int priority;
   int min;
} node;

#define MAXSIZE 1024

/* Initialize a heap from n random priority values. No min calculations
   are done here. */
void initHeap ( node Q[], int n )
{
   int i, j, l, r, m, t;

   if (n > MAXSIZE) {
      fprintf(stderr, "*** Error in initHeap(): Queue capacity exceeded\n");
      exit(1);
   }

   /* Populate the array with random priority values */
   for (i=1; i<=n; ++i) {
      Q[i].priority = 1 + rand() % 99;
      printf("%d ", Q[i].priority);
   }

   for (i=n/2; i>0; --i) { /* Loop for buildheap */
      j = i;
      while (j<=n/2) {     /* Loop for heapify */
         l = 2*j; r = 2*j+1;
         if (r > n) m = l; else m = (Q[l].priority >= Q[r].priority) ? l : r;
         if (Q[j].priority > Q[m].priority) break;
         t = Q[m].priority; Q[m].priority = Q[j].priority; Q[j].priority = t;
         j = m;
      }
   }
}

/* Function to calculate the min values at all nodes in an initialized heap */
void initMin ( node Q[], int n )
{
   int i;

   /* For the leaf nodes, the min values are the same as the priority values */
   for (i=n; i>n/2; --i) Q[i].min = Q[i].priority;

   /* Handle the last non-leaf node */
   if (n % 2) /* n is odd, so this node has two children */
      Q[i].min = (Q[n-1].min < Q[n].min) ? Q[n-1].min : Q[n].min;
   else       /* n is even, so this node has only one child */
      Q[i].min = Q[n].min;

   /* For other non-leaf nodes, both the children are present. The min value
      at such a node is the smaller of the min values of the child nodes. */
   while (--i)
      Q[i].min = (Q[2*i].min < Q[2*i+1].min) ? Q[2*i].min : Q[2*i+1].min;
}

void printQ ( node Q[], int n )
{
   int i;

   for (i=1; i<=n; ++i) {
      printf("    %2d,%-2d  ", Q[i].priority, Q[i].min);
      if (2*i>n) printf("(  _   : ");
      else printf("(%2d,%-2d : ", Q[2*i].priority, Q[2*i].min);
      if (2*i+1>n) printf("  _  )\n");
      else printf("%2d,%-2d)\n", Q[2*i+1].priority, Q[2*i+1].min);
   }
}

/* Function to adjust the min values in Q (size n) on the path starting
   at index j toward the root (at index 1) */
void adjustMin ( node Q[], int n, int j )
{
   int l, r;

   while (j >= 1) {
      l = 2*j; r = 2*j+1;
      if (l > n) Q[j].min = Q[j].priority;                          /* Leaf node */
      else if (r > n) Q[j].min = Q[l].min;                          /* Only one child */
      else Q[j].min = (Q[l].min <= Q[r].min) ? Q[l].min : Q[r].min; /* Two children */
      j /= 2;
   }
}

/* Insert x in queue Q of pre-insertion size n */
void insert ( node Q[], int n, int x )
{
   int i, j, t;

   if (n == MAXSIZE) {
      fprintf(stderr, "*** Error in insert(): Queue capacity exceeded\n");
      exit(2);
   }

   printf("%d ", x);
   ++n;
   Q[n].priority = x;
   i = n;
   while (i > 1) { /* Standard insertion procedure */
      j = i / 2;
      if (Q[j].priority > Q[i].priority) break;
      t = Q[i].priority; Q[i].priority = Q[j].priority; Q[j].priority = t;
      i = j;
   }

   /* Min values on only one path are potentially affected */
   adjustMin(Q,n,n);
}

void deleteMax ( node Q[], int n )
{
   int j, l, r, m, t;

   if (n == 0) {
      fprintf(stderr, "*** Error in deleteMax(): Queue is empty\n");
      exit(3);
   }

   /* First, delete using the standard deletion procedure */
   printf("%d ", Q[1].priority);
   Q[1].priority = Q[n].priority;
   --n; j = 1;
   while (j <= n/2) { /* Loop for heapify */
      l = 2*j; r = 2*j+1;
      if (r > n) m = l; else m = (Q[l].priority >= Q[r].priority) ? l : r;
      if (Q[j].priority > Q[m].priority) break;
      t = Q[j].priority; Q[j].priority = Q[m].priority; Q[m].priority = t;
      j = m;
   }

   /* Adjust the minimum values on the heapify path */
   adjustMin(Q,n,j);

   /* The last leaf was deleted. Adjust the min values from its parent. */
   adjustMin(Q,n,(n+1)/2);
}

void deleteMin ( node Q[], int n )
{
   int i, j, k, t;

   if (n == 0) {
      fprintf(stderr, "*** Error in deleteMin(): Queue is empty\n");
      exit(4);
   }

   printf("%d ", Q[1].min);

   /* Guided by the mmin values stored in the heap, locate a leaf storing
      the minimum value. Notice that locating a non-leaf node storing the
      minimum value will also perfectly work. If such an internal node does
      exist, the entire subtree beneath it will consist of priority values
      equal to the minimum value. In particular, we can choose any leaf
      from that subtree. In other words, a leaf storing the minimum value
      can always be located. However, the following algorithm is perfectly
      fine even if an internal node storing the minimum priority is chosen.
      Indeed, the minimum priority will be replaced by a potentially larger
      priority value, so the restoration attempt of heap ordering will go
      up, starting from a minimum-priority node chosen, leaf or internal. */
   i = 1; t = Q[1].min;
   while (i <= n/2) i = (Q[2*i].min == t) ? 2*i : 2*i+1;

   /* Copy the last leaf to the located leaf storing the minimum value */
   Q[i].priority = Q[n].priority;
   --n;

   if (n == 0) return;

   /* Restore heap property from the leaf toward the root (similar to insert) */
   j = i;
   while (j > 1) {
      k = j / 2;
      if (Q[k].priority > Q[j].priority) break;
      t = Q[k].priority; Q[k].priority = Q[j].priority; Q[j].priority = t;
      j = k;
   }

   /* Adjust the min values on the path from root to the leaf which stored the
      deleted minimum value. */
   adjustMin(Q,n,i);

   /* The last leaf was relocated, so min adjustments are necessary from the
      node which was the parent of the leaf before its relocation. */
   adjustMin(Q,n,(n+1)/2);
}

int main ( int argc, char *argv[] )
{
   int i, n, ninit, nins, ndelmax, ndelmin;
   node Q[1+MAXSIZE];

   srand((unsigned int)time(NULL));
   if (argc >= 5) {
      ninit = atoi(argv[1]);
      nins = atoi(argv[2]);
      ndelmax = atoi(argv[3]);
      ndelmin = atoi(argv[4]);
   } else {
      printf("ninit = "); scanf("%d", &ninit);
      printf("nins = "); scanf("%d", &nins);
      printf("ndelmax = "); scanf("%d", &ndelmax);
      printf("ndelmin = "); scanf("%d", &ndelmin);
   }

   printf("+++ Initializing queue: ");
   initHeap(Q,ninit); initMin(Q,ninit); n = ninit;
   printf("\n+++ Queue initialized\n"); printQ(Q,n);

   printf("\n+++ Inserting elements: ");
   for (i=0; i<nins; ++i) { insert(Q,n,1+rand()%99); ++n; }
   printf("\n+++ Insertions done\n"); printQ(Q,n);

   printf("\n+++ Deleting maximum: ");
   for (i=0; i<ndelmax; ++i) { deleteMax(Q,n); --n; }
   printf("\n+++ Deletions done\n"); printQ(Q,n);

   printf("\n+++ Deleting minimum: ");
   for (i=0; i<ndelmin; ++i) { deleteMin(Q,n); --n; }
   printf("\n+++ Deletions done\n"); printQ(Q,n);

   printf("\n");

   exit(0);
}
