
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void solve(int **);

int main()
{
    int i,**board;

    board = (int **)malloc(3*sizeof(int *));
    board[0] = (int *)malloc(3*sizeof(int));
    board[1] = (int *)malloc(3*sizeof(int));
    board[2] = (int *)malloc(3*sizeof(int));

    for ( i = 0; i < 3; i = i + 1 ) {
        scanf("%d %d %d", &board[i][0], &board[i][1], &board[i][2]);
    }
    solve (board);
    return 0;
}

void push(int qu[], int *front, int *rear, int val) {
	if(*front == -1 && *rear == -1) {
		*front = *front + 1;
	}
	*rear = (*rear + 1)%400000;
	qu[*rear] = val;
}
int dequeue(int qu[], int *front, int *rear) {
	int val = qu[*front];
	if(*front == *rear) {
		*front = -1;
		*rear = -1;
	}
	else {
		*front = (*front + 1)%400000;
	}
	return val;
}
void insert(int id, int arr[][2], int a[], int par[], int val, int *cnt) {
	if(id == 9) {
		arr[*cnt][0] = val;
		arr[*cnt][1] = 0;
		*cnt = *cnt + 1;
		return;
	}
	int i;
	for(i = 0; i < 9; i++) {
		int j;
		int f = 1;
		for(j = 0; j < id; j++) {
			if(a[j] == i) {
				f = 0;
				break;
			}
		}
		if(f) {
			a[id] = i;
			insert(id + 1, arr, a, par, val * 10 + i, cnt);
		}
	}
}
void print_matrix(int a[][3]) {
	int i, j;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
void print_val(int val) {
	int a[3][3];
	int i, j;
	for(i = 2; i >= 0; i--) {
		for(j = 2; j >= 0; j--) {
			a[i][j] = val%10;
			val/=10;
		}
	}
	print_matrix(a);
}
int arr[400000][2];
int par[400000];
int qu[400000];
int calc_value(int board[][3]) {
	int i, j;
	int val = 0;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			val = val * 10 + board[i][j];
		}
	}
	return val;
}
int find_id(int arr[][2], int n, int val) {
	int l = 0;
	int u = n - 1;
	while(l <= u) {
		int mid = (l + u) >> 1;
		if(arr[mid][0] == val) {
			return mid;
		}
		if(arr[mid][0] > val) {
			u = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
}
int empty(int front) {
	if(front == -1) {
		return 1;
	}
	return 0;
}
int find_sol(int n, int **board) {
	int front = -1, rear = -1;
	int nboard[3][3];
	int i, j;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			nboard[i][j] = board[i][j];
		}
	}
	int val = calc_value(nboard);
	int id = find_id(arr, n, val);
	arr[id][1] = 1;
	par[id] = -1;
	push(qu, &front, &rear, id);
	while(!empty(front)) {
		id = dequeue(qu, &front, &rear);
		val = arr[id][0];
		if(val == 12345678) {
			return 1;
		}
		int nval = val;
		for(i = 2; i >= 0; i--) {
			for(j = 2; j >= 0; j--) {
				nboard[i][j] = nval%10;
				nval/=10;
			}
		}
		int idi = -1, idj = -1;
		for(i = 0; i < 3; i++) {
			for(j = 0; j < 3; j++) {
				if(nboard[i][j] == 0) {
					idi = i;
					idj = j;
					break;
				}	
			}
		}
		//cout << idi << " " << idj << endl;
		if(idi > 0) {
			int temp = nboard[idi][idj];
			nboard[idi][idj] = nboard[idi - 1][idj];
			nboard[idi - 1][idj] = temp;
			int val2 = calc_value(nboard);
			int id2 = find_id(arr, n, val2);
			if(!arr[id2][1]) {
				arr[id2][1] = 1;
				par[id2] = id;
				push(qu, &front, &rear, id2);
			}
			temp = nboard[idi][idj];
			nboard[idi][idj] = nboard[idi - 1][idj];
			nboard[idi - 1][idj] = temp;
		}
		if(idi < 2) {
			int temp = nboard[idi][idj];
			nboard[idi][idj] = nboard[idi + 1][idj];
			nboard[idi + 1][idj] = temp;
			int val2 = calc_value(nboard);
			int id2 = find_id(arr, n, val2);
			if(!arr[id2][1]) {
				arr[id2][1] = 1;
				par[id2] = id;
				push(qu, &front, &rear, id2);
			}
			temp = nboard[idi][idj];
			nboard[idi][idj] = nboard[idi + 1][idj];
			nboard[idi + 1][idj] = temp;
		
		}
		if(idj > 0) {
			int temp = nboard[idi][idj];
			nboard[idi][idj] = nboard[idi][idj - 1];
			nboard[idi][idj - 1] = temp;
			int val2 = calc_value(nboard);
			int id2 = find_id(arr, n, val2);
			if(!arr[id2][1]) {
				arr[id2][1] = 1;
				par[id2] = id;
				push(qu, &front, &rear, id2);
			}
			temp = nboard[idi][idj];
			nboard[idi][idj] = nboard[idi][idj - 1];
			nboard[idi][idj - 1] = temp;
		}
		if(idj < 2) {
			int temp = nboard[idi][idj];
			nboard[idi][idj] = nboard[idi][idj + 1];
			nboard[idi][idj + 1] = temp;
			int val2 = calc_value(nboard);
			int id2 = find_id(arr, n, val2);
			if(!arr[id2][1]) {
				arr[id2][1] = 1;
				par[id2] = id;
				push(qu, &front, &rear, id2);
			}
			temp = nboard[idi][idj];
			nboard[idi][idj] = nboard[idi][idj + 1];
			nboard[idi][idj + 1] = temp;
		}
	}
	return 0;
}
void print(int id) {
	if(id == -1) {
		return;
	}
	print(par[id]);
	print_val(arr[id][0]);
	printf("\n");
	
}
void solve(int **board) {
	int a[10];
	int i;
	int cnt = 0;
	insert(0, arr, a, par, 0, &cnt);
	int ctr = 0;
	int f = find_sol(cnt, board);
	if(!f) {
		printf("No solution\n");
	}
	else {
		printf("\n");
		int val = find_id(arr, cnt, 12345678);
		print(val);
	}
}
