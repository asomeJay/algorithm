/* 빵집 */

#include <iostream>

#define WALL 'X'
#define EMPTY '.'
#define MAXR 10010
#define MAXC 510

using namespace std;

int R, C;
int dr[3] = { -1, 0, 1 };

char map[MAXR][MAXC];
bool dp[MAXR][MAXC];
bool is_used[MAXR][MAXC];

void input();
void solve();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;

}

void input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
}

inline bool is_range(int r, int c) {
	return r >= 0 && r < R&& c >= 0 && c < C;
}

void solve() {
	/* 제일 오른쪽 열부터 왼쪽으로 열을 하나씩 이동하면서 */
	/* 도착점에 도달할 수 있는 칸을 찾는다. */
	for (int i = 0; i < R; i++) {
		dp[i][C - 1] = true;
	}

	for (int c = C - 2; c >= 0; c--) {
		for (int r = 0; r < R; r++) {
			for (int k = 0; k < 3; k++) {
				int nr = r + dr[k];
				int nc = c + 1;

				if (is_range(nr, nc) == true && dp[nr][nc] == true 
					&& is_used[nr][nc] == false && map[r][c] == '.') {
					is_used[nr][nc] = true;
					dp[r][c] = true;
					break;
				}
			}
		}
	}
/*
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/

	int summation = 0;
	for (int i = 0; i < R; i++) {
		if (dp[i][0] == true) {
			summation++;
		}
	}
	cout << summation << '\n';
	return;
}