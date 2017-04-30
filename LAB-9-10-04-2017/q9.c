#include <stdio.h>
#include <stdlib.h>

void solve(float *,int);
int main()
{
  int i,n,m;
  float num,operator,*expr;
  char *par_expr;
  scanf("%d",&n);  /* Enter how many numbers are there in the expression */
  expr = (float *)mallloc(((2*n)-1)*sizeof(float)); /* n numbers and n-1 operators */
  scanf("%f",&expr[0]);  /* first number */
  for(i=1;i<n;i=i+2) {
    scanf("%f",&expr[i]); /* operator */
    scanf("%f",&expr[i+1]); /* Number */
  }
  solve(expr,n);
  return 0;
}

void solve(float *expr, int n)
{

  /* solve the puzzle and use printf to print the parenthesized expression and result to screen */
}
#include <stdio.h>
#include <stdlib.h>

void solve(float *,int);
int main()
{
  int i,n,m;
  float num,operator,*expr;
  char *par_expr;
  scanf("%d",&n);  /* Enter how many numbers are there in the expression */
  expr = (float *)mallloc(((2*n)-1)*sizeof(float)); /* n numbers and n-1 operators */
  scanf("%f",&expr[0]);  /* first number */
  for(i=1;i<n;i=i+2) {
    scanf("%f",&expr[i]); /* operator */
    scanf("%f",&expr[i+1]); /* Number */
  }
  solve(expr,n);
  return 0;
}

void solve(float *expr, int n)
{

  /* solve the puzzle and use printf to print the parenthesized expression and result to screen */
}
