#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define M 50

typedef struct _node {
   int key;
   double priority;
   struct _node *L, *R, *P;
} tnode;

int prnTreap ( tnode *T, int level )
{
   int i, cnt = 1;

   if (T == NULL) return 0;
   for (i=0; i<level; ++i) printf("   ");
   printf("(%d,%f) -> ", T -> key, T -> priority);
   if (T -> L) printf("(%d,%f), ", T -> L -> key, T -> L -> priority);
   else printf("(NULL,-), ");
   if (T -> R) printf("(%d,%f)\n", T -> R -> key, T -> R -> priority);
   else printf("(NULL,-)\n");
   cnt += prnTreap(T->L,level+1);
   cnt += prnTreap(T->R,level+1);
   return cnt;
}

tnode *insert ( tnode *T, int x, double y )
{
   tnode *p, *q;

   printf("+++ insert(%d,%f)\n", x, y);

   /* Search for x */
   p = T; q = NULL;
   while (p) {
      if (x == p -> key) {
         printf("+++ Key already present in treap\n");
         return T;
      }
      q = p;
      if (x < p -> key) p = p -> L; else p = p -> R;
   }

   /* Insert (x,y) at a leaf node */
   p = (tnode *)malloc(sizeof(tnode));
   p -> key = x;
   p -> priority = y;
   p -> L = p -> R = NULL;
   p -> P = q;
   if (q == NULL) T = p;
   else if (x < q -> key) q -> L = p;
   else q -> R = p;

   /* Restoration of heap ordering */
   while (1) {
      /* Here, q points to the parent of p */
      if (q == NULL) break;
      if (q -> priority >= p -> priority) break;

      if (q -> P == NULL) T = p;                          /* Rotation at root */
      else {                                                /* q has a parent */
         if (q == q -> P -> L) q -> P -> L = p;
         else q -> P -> R = p;
      }

      if (p == q -> R) {                                     /* Left rotation */
         q -> R = p -> L;
         p -> L = q;
         if (q -> R != NULL) q -> R -> P = q;
      } else {                                              /* Right rotation */
         q -> L = p -> R;
         p -> R = q;
         if (q -> L != NULL) q -> L -> P = q;
      }

      /* Adjust parent pointers of p and q for both types of rotations */
      p -> P = q -> P;
      q -> P = p;

      /* Move up by one step in the tree */
      q = p -> P;
   }

   return T;
}

tnode *delete ( tnode *T, int x )
{
   tnode *p, *q, *r;

   printf("+++ delete(%d)\n", x);

   /* Search for x in T */
   p = T; q = NULL;
   while (p) {
      if (x == p-> key) break;
      q = p;
      if (x < p -> key) p = p -> L; else p = p -> R;
   }

   if (p == NULL) {
      printf("+++ Key not present in treap\n");
      return T;
   }

   if ((p -> L == NULL) || (p -> R == NULL)) {
      /* At least one of the subtrees at p is empty */
      r = (p -> L == NULL) ? p -> R : p -> L;
      if (r) r -> P = q;
      if (q == NULL) T = r;                                   /* Root deleted */
      else if (x < q -> key) q -> L = r;
      else q -> R = r;
      free(p);

      /* Restoration of heap order is not necessary in this case */
   } else {
      /* Locate the immediate successor */
      r = p; p = p -> R;
      while (p -> L) p = p -> L;

      /* Copy immediate successor to the node being deleted */
      r -> key = p -> key;
      r -> priority = p -> priority;

      /* Delete the immediate successor */
      q = p -> P;
      if (p -> key < q -> key) q -> L = p -> R;
      else q -> R = p -> R;
      if (p -> R) p -> R -> P = q;
      free(p);

      /* Restore heap order from the deleted node down the tree */
      q = r;
      while (1) {
         /* Locate the child (if any) with the larger priority */
         p = NULL;
         if (q -> L == NULL) p = q -> R;
         else if (q -> R == NULL) p = q -> L;
         else p = (q -> L -> priority >= q -> R -> priority) ? q -> L : q -> R;

         if (p == NULL) break;                            /* Case of no child */
         if (q -> priority >= p -> priority) break;    /* Heap order restored */

         if (q -> P == NULL) T = p;                       /* Rotation at root */
         else {                                             /* q has a parent */
            if (q == q -> P -> L) q -> P -> L = p;
            else q -> P -> R = p;
         }

         if (p == q -> R) {                                  /* Left rotation */
            q -> R = p -> L;
            p -> L = q;
            if (q -> R != NULL) q -> R -> P = q;
         } else {                                           /* Right rotation */
            q -> L = p -> R;
            p -> R = q;
            if (q -> L != NULL) q -> L -> P = q;
         }

         /* Adjust parent pointers of p and q for both types of rotations */
         p -> P = q -> P;
         q -> P = p;

         /* Here, q is already a child of p, so nothing extra needs to be
            done for the next iteration. */
      }
   }

   return T;
}

int main ( int argc, char *argv[] )
{
   int n, m, i, cnt;
   tnode *T = NULL;

   srand((unsigned int)time(NULL));
   if (argc >= 3) { n = atoi(argv[1]); m = atoi(argv[2]); }
   else { n = N; m = M; }

   printf("--------------------------------------------------------------------------------\n");

   for (i=0; i<n; ++i) {
      if (i == 0) T = insert(T,50,0.5);
      else T = insert(T,1+rand()%99,(double)rand()/(1.0+(double)RAND_MAX));
      cnt = prnTreap(T,0);
      printf("Number of nodes = %d\n", cnt);
      printf("--------------------------------------------------------------------------------\n");
   }

   for (i=0; i<m; ++i) {
      if (i == 0) T = delete(T,T->key);
      else T = delete(T,1+rand()%99);
      cnt = prnTreap(T,0);
      printf("Number of nodes = %d\n", cnt);
      printf("--------------------------------------------------------------------------------\n");
   }

   exit(0);
}
