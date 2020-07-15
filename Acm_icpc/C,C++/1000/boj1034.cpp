/* 램프 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, K, ANS;
bool lamp[51][51];

void dfs(int, bool[51][51], int);

int main(void) {
	scanf("%d %d", &R, &C);
	getchar();

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%c", &lamp[i][j]);
			lamp[i][j] -= '0';
		}
		getchar();
	}

	scanf("%d", &K);
	dfs(0, lamp, K);
	cout << ANS;

	return 0;
}

void dfs(int c, bool before_lamp[51][51], int k) {
	if (c == C) { // 끝까지 도착함.
		int i, j, cur_max = 0;
		for (i = 0; i < R; i++) {
			for (j = 1; j < C; j++) {
				if (before_lamp[i][j - 1] != before_lamp[i][j] || before_lamp[i][j] != 1)
					break;
			}
			if (j == C) cur_max++;
		}
		ANS = max(ANS, cur_max);
		return;
	}

	bool cur_lamp[51][51];

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cur_lamp[i][j] = before_lamp[i][j];
		}
	}

	dfs(c + 1, cur_lamp, k); // 이번에 불을 안 켤거임.
	for (int i = 0; i < R; i++) {
		cur_lamp[i][c] = (cur_lamp[i][c] == 0 ? 1 : 0);
	}

	if (k != 0) {
		dfs(c + 1, cur_lamp, k - 1);
	}	
}
