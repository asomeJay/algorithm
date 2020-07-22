/* 게임 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input();
void solve();

int N, M, ANS;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

char board[50][50];
int dp[50][50];
bool is_visit[50][50];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			board[i][j] = (board[i][j] == 'H' ? 'H' : board[i][j] - '0');
		}
	}
}

inline bool is_range(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < M;
}

int dfs(int r, int c) {
	if (is_range(r, c) == false || board[r][c] == 'H') { // 끝났습니다.
		return 0;
	}
	int& ret = dp[r][c];
	if (ret != 0)
		return ret;

	if (is_visit[r][c]) {
		cout << -1 << '\n';
		exit(0);
	}

	int sum = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i] * board[r][c];
		int nc = c + dc[i] * board[r][c];
	
		is_visit[r][c] = true;
		sum = max(sum, dfs(nr, nc) + 1);
		is_visit[r][c] = false;
	}

	return ret = sum;
}

void solve() {
	cout << dfs(0, 0) << '\n';
}
