#include <stdio.h>
#include <stdlib.h>
#include <float.h>

void solve(float *,int);

int main()
{
    int i, n, m;
    float num, operator, *expr;
    char *par_expr;
    scanf("%d", &n);  /* Enter how many numbers are there in the expression */
    expr = (float *)malloc(((2 * n) - 1) * sizeof(float)); /* n numbers and n-1 operators */
    scanf("%f", &expr[0]);  /* first number */
    for(i = 1; i <= n; i = i + 2) {
      scanf("%f",&expr[i]); /* operator */
      scanf("%f",&expr[i + 1]); /* Number */
    }
   /* for(i = 0; i < 2 * n - 1; i++) {
    	printf("%f ",expr[i]);
    }*/
    solve(expr,n);
    return 0;
}

float matrixchain(int n, float* expr, float mx[][n + 1], float mn[][n + 1])
{
	float opr[n];
	int n1 = 0;
	float num[n];
	int n2 = 0;
    int i, j;

    for(i = 0; i < 2 * n - 1; i = i + 2) {
    	num[n2++] = expr[i];
    }

    for(i = 1; i < 2 * n - 1; i = i + 2) {
    	opr[n1++] = expr[i];
    }
    /*for(i = 0; i < n; i++) {
    	printf("%f ",expr[i]);
    }
    printf("\n");
    for(i = 0; i < n2;i++) {
    	printf("%f ",num[i]);
    }
    printf("\n");
    for(i = 0; i < n1;i++) {
    	printf("%f ",opr[i]);
    }
    printf("\n");*/
    for(i = 0; i <= n; i++) {
    	for(j = 0; j <= n; j++) {
    		mn[i][j] = 	999999.9;
    		mx[i][j] = -999999.9;
    	}
    }

    for(i = 1; i <= n; i++) {
        mn[i][i] = num[i - 1];
    	mx[i][i] = num[i - 1];
    }

    int L;
    float mint;
    float maxt;
    int k;
    for(L = 2; L <= n; L++) {
        for(i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            for(k = i; k < j; k++) {
               if(opr[k - 1] == 1) {
               		mint = mn[i][k] + mn[k + 1][j];
               		maxt = mx[i][k] + mx[k + 1][j];
               }
               if(opr[k - 1] == 2) {
               		mint = mn[i][k] - mx[k + 1][j];
               		maxt = mx[i][k] - mn[k + 1][j];
               }
               if(opr[k - 1] == 3) {
               		mint = mn[i][k] * mn[k + 1][j];
               		maxt = mx[i][k] * mx[k + 1][j];
               }
               if(opr[k - 1] == 4) {
               		mint = mn[i][k] / mx[k + 1][j];
               		maxt = mx[i][k] / mn[k + 1][j];
               }
               	if(mint < mn[i][j])
               		mn[i][j] = mint;
               	if(maxt > mx[i][j])
               		mx[i][j] = maxt;
        	}
    	}
	}
    return mx[1][n];
}

void solve(float *expr, int n)
{
    float mx[n + 1][n + 1];
    float mn[n + 1][n + 1];
    float ans = matrixchain(n, expr, mx, mn);
    printf("%f\n",ans);
}