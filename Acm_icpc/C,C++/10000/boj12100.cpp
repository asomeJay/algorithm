/* 2048 EASY */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX_BOARD 25
#define N 0
#define E 1
#define W 3
#define S 2
#define MIXED 1

using namespace std;

int board_N, Ans;
const int limit = 5;

void dfs(int depth, int[MAX_BOARD][MAX_BOARD]);
void move(int dir, int[MAX_BOARD][MAX_BOARD]);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> board_N;
	int board[MAX_BOARD][MAX_BOARD];
	for (int i = 1; i <= board_N; i++) {
		for (int j = 1; j <= board_N; j++) {
			cin >> board[i][j];
			Ans = max(Ans, board[i][j]);
		}
	}
	
	dfs(0, board);

	/*
	for (int i = 1; i <= board_N; i++) {
		for (int j = 1; j <= board_N; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << Ans;
	return 0;
}

void dfs(int depth, int t_board[MAX_BOARD][MAX_BOARD]) {
	if (depth > limit)
		return;
	for (int i = 1; i <= board_N; i++) {
		for (int j = 1; j <= board_N; j++) {
			Ans = max(Ans, t_board[i][j]);
		}
	}
	
	int t[MAX_BOARD][MAX_BOARD];

	for (int q = 0; q < 4; q++) {
		copy(&t_board[0][0], &t_board[MAX_BOARD - 1][MAX_BOARD], &t[0][0]);
		move(q, t);
		
		dfs(depth + 1, t);
	}
}

void move(int dir, int t[MAX_BOARD][MAX_BOARD]) {
	int i, j, k;
	bool chk[MAX_BOARD][MAX_BOARD] = { false };

	switch (dir) {
	case N:
		for (k = 1; k < board_N; k++) { // 어느 행에 넣으실건데요
			for (i = 1; i <= board_N; i++) { // 열 차렷
				for (j = k + 1; j <= board_N; j++) { // 행기준
					if (t[j][i] != 0) {
						if (t[k][i] == t[j][i] && chk[k][i] == false
							&& chk[j][i] == false) {
							chk[k][i] = true;

							t[k][i] += t[j][i];
							t[j][i] = 0;
						}
						else if (t[k][i] == 0) {
							if (chk[j][i] == true)
								chk[k][i] = true;
							t[k][i] = t[j][i];

							t[j][i] = 0;
							j = k + 1;
							continue;
						}
						break;
					}
				}
			}
		}
		break;
	case E:
		for (k = board_N; k > 1; k--) { // 어느 열에 넣으실건데요
			for (i = 1; i <= board_N; i++) { // 행 차렷
				for (j = k - 1; j >= 1; j--) { // 열 기준
					if (t[i][j] != 0) {
						if (t[i][k] == t[i][j] && chk[i][k] == false
							&& chk[i][j] == false) {
							chk[i][k] = MIXED;
							t[i][k] += t[i][j];
							t[i][j] = 0;
						}
						else if (t[i][k] == 0) {
							if (chk[i][j] == MIXED)
								chk[i][k] = MIXED;
							t[i][k] = t[i][j];

							t[i][j] = 0;
							j = k - 1;
							continue;
						}
						break;
					}
				}
			}
		}
		break;

	case S:
		for (k = board_N; k > 1; k--) { // 어느 행에 넣으실건데요
			for (i = 1; i <= board_N; i++) { // 열 차렷
				for (j = k - 1; j >= 1; j--) { // 행기준
					if (t[j][i] != 0) {
						if (t[k][i] == t[j][i] && chk[k][i] == false) {
							chk[k][i] = true;
							t[k][i] += t[j][i];
							t[j][i] = 0;
						}
						else if (t[k][i] == 0) {
							if (chk[j][i] == true)
								chk[k][i] = true;
							t[k][i] = t[j][i];

							t[j][i] = 0;
							chk[k][i] = false;
							j = k - 1;
							continue;
						}
						break;
					}
				}
			}
		}
		break;
	case W:
		for (k = 1; k < board_N; k++) { // 어느 행에 넣으실건데요
			for (i = 1; i <= board_N; i++) { // 행 차렷
				for (j = k + 1; j <= board_N; j++) { // COLUMN
					if (t[i][j] != 0) {
						if (t[i][k] == t[i][j] && chk[i][k] == false) {
							chk[i][k] = true;
							t[i][k] += t[i][j];
							t[i][j] = 0;
						}
						else if (t[i][k] == 0) {
							if (t[i][j] == true)
								t[i][k] = true;
							t[i][k] = t[i][j];

							t[i][j] = 0;
							chk[k][i] = false;
							j = k + 1;
							continue;
						}
						break;
					}
				}
			}
		}
		break;
	default:
		cout << "ERROR at move" << endl;
	}
	/*
	cout << endl;
	for (i = 1; i <= board_N; i++) {
		for (j = 1; j <= board_N; j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}*/
}
