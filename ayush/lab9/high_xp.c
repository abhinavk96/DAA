#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void solve(float *,int, char *);
int main()
{
  int i,n,m;
  float num,operator,*expr;
  char *par_expr;
  scanf("%d",&n);  /* Enter how many numbers are there in the expression */
  expr = (float *)malloc(((2*n)-1)*sizeof(float)); /* n numbers and n-1 operators */
  scanf("%f",&expr[0]);  /* first number */
  for(i=1;i<2 * n - 1;i=i+2) {
    scanf("%f",&expr[i]); /* operator */
    scanf("%f",&expr[i+1]); /* Number */
  }
  par_expr = (char *)(malloc(4 * n * sizeof(char)));
  solve(expr,n, par_expr);
  return 0;
}

void maximize(int st, int en, int ****dp, int id, int af[], int bef[], int sign[]) {
	bef[st]++;
	af[en]++;
	if(st == en) {
		return;
	}
	int val[4];
	int i;
	for(i = 0; i < 4; i++) {
		val[i] = dp[id][st][en][i];
	}
	maximize(st, val[0], dp, val[2], af, bef, sign);
	maximize(val[0] + 1, en, dp, val[3], af, bef, sign);
	sign[val[0]] = val[1];
}
void get_expr(float *expr, int n, int ****dp2, char *s, int p) {
	int af[n];
	int bef[n];
	int sign[n];
	int i;
	for(i = 0; i < n; i++) {
		af[i] = 0;
		bef[i] = 0;
		sign[i] = -1;
	}
	maximize(0, n - 1, dp2, p, af, bef, sign);
	/*for(i = 0; i < n; i++) {
		printf("%d ", af[i]);
	}
	printf("\n");
	for(i = 0; i < n; i++) {
		printf("%d ", bef[i]);
	}
	printf("\n");
	for(i = 0; i < n; i++) {
		printf("%d ", sign[i]);
	}
	printf("\n");*/
	int id = 0;
	int ctr = 0;
	while(1) {
		for(i = 1; i < bef[id]; i++) {
			s[ctr++] = '(';
		}
		if(expr[2 * id] < 0) {
			s[ctr++] = '(';
		}
		else {
			af[id]--;
		}
		char str[50];
		sprintf(str, "%f", expr[2 * id]);
		int len = strlen(str);
		while(str[len - 1] == '0') {
			len--;
		}
		if(str[len - 1] == '.') {
			len++;
		}
		for(i = 0; i < len; i++) {
			s[ctr++] = str[i];
		}
		for(i = 1; i <= af[id]; i++) {
			s[ctr++] = ')';
		}
		id++;
		if(id == n) {
			break;
		}
		s[ctr++] = ' ';
		switch(sign[id - 1]) {
			case 1:
				s[ctr++] = '+';
			break;
			case 2:
				s[ctr++] = '-';
			break;
			case 3:
				s[ctr++] = '*';
			break;
			case 4:
				s[ctr++] = '/';
			break;
			default:
				printf("invalid output");
		}
		s[ctr++] = ' ';
	}
	s[ctr] = '\0';
}
void solve(float *expr, int n, char *par_expr)
{
	float dp[4][n][n];
	int ****dp2;			// 0 -> k 1->sign 2-> id1 3->id2;
	dp2 = (int ****)(calloc(4, sizeof(int ***)));
	int i, j, k;
	for(i = 0; i < 4; i++) {
		dp2[i] = (int ***)(calloc(n, sizeof(int**)));
	}
	for(i = 0; i < 4; i++) {
		for(j = 0; j < n; j++) {
			dp2[i][j] = (int **)(calloc(n, sizeof(int *)));
		}
	}
	
	for(i = 0; i < 4; i++) {
		for(j = 0; j < n; j++) {
			for(k = 0; k < n; k++) {
				dp2[i][j][k] = (int *)(calloc(4, sizeof(int)));
			}
		}
	}
	for(i = 0; i < 2 * n - 1; i++) {
		printf("%.6f ",expr[i]);
	}
	printf("\n\n");
	float inf1 = 1000000;
	for(i = 0; i < n; i++) {
		if(expr[2 * i] >= 0) {
			//printf("1 %d\n", i);
			dp[0][i][i] = expr[2 * i];
			dp[1][i][i] = expr[2 * i];
			dp[2][i][i] = -inf1;
			dp[3][i][i] = inf1;
		}
		else {

			//printf("2 %d\n", i);
			dp[0][i][i] = -inf1;
			dp[1][i][i] = inf1;
			dp[2][i][i] = expr[2 * i];
			dp[3][i][i] = expr[2 * i];
		}
	}
	
	/*for(k = 0; k < 4; k++) {
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				printf("%f ", dp[k][i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
	}*/
	int l;
	int x, y;
	for(l = 2; l <= n; l++) {
		for(i = 0; i <= n - l; i++) {
			int j = i + l - 1;
			dp[0][i][j] = -inf1;
			dp[1][i][j] = inf1;
			dp[2][i][j] = -inf1;
			dp[3][i][j] = inf1;
			for(k = i; k < j; k++) {
				float val = expr[2 * k + 1];
				for(x = 0; x < 4; x++) {
					for(y = 0; y < 4; y++) {
						
						if((dp[x][i][k] == inf1) || (dp[x][i][k] == -inf1)) {
							continue;
						}
						if((dp[y][k+1][j] == inf1) || (dp[y][k+1][j] == -inf1)) {
							continue;
						}
						
						if(!val) {
							float p = dp[x][i][k] + dp[y][k + 1][j];
							float p1 = -inf1, p2 = inf1, p3 = -inf1, p4 = inf1;
							int op1, op2, op3, op4;
							if(p >= 0) {
								if(p > p1) {
									op1 = 1;
									p1 = p;
								}
								if(p < p2) {
									op2 = 1;
									p2 = p;
								}
							}
							else {
								if(p > p3) {
									op3 = 1;
									p3 = p;
								}
								if(p < p4) {
									op4 = 1;
									p4 = p;
								}
							}
							p = dp[x][i][k] - dp[y][k + 1][j];
							if(p >= 0) {
								if(p > p1) {
									op1 = 2;
									p1 = p;
								}
								if(p < p2) {
									op2 = 2;
									p2 = p;
								}
							}
							else {
								if(p > p3) {
									op3 = 2;
									p3 = p;
								}
								if(p < p4) {
									op4 = 2;
									p4 = p;
								}
							}
							p = dp[x][i][k] * dp[y][k + 1][j];
							if(p >= 0) {
								if(p > p1) {
									op1 = 3;
									p1 = p;
								}
								if(p < p2) {
									op2 = 3;
									p2 = p;
								}
							}
							else {
								if(p > p3) {
									op3 = 3;
									p3 = p;
								}
								if(p < p4) {
									op4 = 3;
									p4 = p;
								}
							}

							p = dp[x][i][k] / dp[y][k + 1][j];
							if(p >= 0) {
								if(p > p1) {
									op1 = 4;
									p1 = p;
								}
								if(p < p2) {
									op2 = 4;
									p2 = p;
								}
							}
							else {
								if(p > p3) {
									op3 = 4;
									p3 = p;
								}
								if(p < p4) {
									op4 = 4;
									p4 = p;
								}
							}
							if(p1 > dp[0][i][j]) {
								dp[0][i][j] = p1;
								dp2[0][i][j][0] = k;
								dp2[0][i][j][1] = op1;
								dp2[0][i][j][2] = x;
								dp2[0][i][j][3] = y;
							}
							if(p2 < dp[1][i][j]) {
								dp[1][i][j] = p2;
								dp2[1][i][j][0] = k;
								dp2[1][i][j][1] = op2;
								dp2[1][i][j][2] = x;
								dp2[1][i][j][3] = y;
							}
							if(p3 > dp[2][i][j]) {
								dp[2][i][j] = p3;
								dp2[2][i][j][0] = k;
								dp2[2][i][j][1] = op3;
								dp2[2][i][j][2] = x;
								dp2[2][i][j][3] = y;
							}
							if(p4 < dp[3][i][j]) {
								dp[3][i][j] = p4;
								dp2[3][i][j][0] = k;
								dp2[3][i][j][1] = op4;
								dp2[3][i][j][2] = x;
								dp2[3][i][j][3] = y;
							}
							continue;
						}
						float p;
						if(val == 1) {
							p = dp[x][i][k] + dp[y][k + 1][j];
						}
						else if(val == 2) {
							p = dp[x][i][k] - dp[y][k + 1][j];
						}
						else if(val == 3) {
							p = dp[x][i][k] * dp[y][k + 1][j];
						}
						else if(val == 4) {
							p = dp[x][i][k] / dp[y][k + 1][j];
						}
						
						if(p >= 0) {
							if(p > dp[0][i][j]) {
								dp[0][i][j] = p;
								dp2[0][i][j][0] = k;
								dp2[0][i][j][1] = val;
								dp2[0][i][j][2] = x;
								dp2[0][i][j][3] = y;
							}
							if(p < dp[1][i][j]) {
								dp[1][i][j] = p;
								dp2[1][i][j][0] = k;
								dp2[1][i][j][1] = val;
								dp2[1][i][j][2] = x;
								dp2[1][i][j][3] = y;
							}
						}
						else {
							if(p > dp[2][i][j]) {
								dp[2][i][j] = p;
								dp2[2][i][j][0] = k;
								dp2[2][i][j][1] = val;
								dp2[2][i][j][2] = x;
								dp2[2][i][j][3] = y;
							}
							if(p < dp[3][i][j]) {
								dp[3][i][j] = p;
								dp2[3][i][j][0] = k;
								dp2[3][i][j][1] = val;
								dp2[3][i][j][2] = x;
								dp2[3][i][j][3] = y;
							}
						}
					}
				}
			}
		}
	}
	int in = 0;
	if(dp[2][0][n - 1] > dp[0][0][n - 1]) {
		in = 2;
	}
	get_expr(expr, n, dp2, par_expr, in);
	/*for(k = 0; k < 4; k++) {
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				printf("%f ", dp[k][i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
	}
	for(i = 0; i < 4; i++) {
		printf("%f ", dp[i][0][n - 1]);
	}
	printf("\n");*/
	printf("maximum value ->\t%f\n", dp[in][0][n - 1]);
	printf("%s\n", par_expr);
  /* solve the puzzle and use printf to print the parenthesized expression and result to screen */
}

