/* 적록색약 */

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

void input();
void solve();

int N, WEAKNESS, NO_WEAKNESS;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

char map[100 + 1][100 + 1];
char weakness_map[100 + 1][100 + 1];

bool is_visit[100 + 1][100 + 1];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	solve();
	return 0;
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

			weakness_map[i][j] = map[i][j];
			if (weakness_map[i][j] == 'R' || weakness_map[i][j] == 'G') {
				weakness_map[i][j] = 'R';
			}
		}
	}
}

inline bool is_range(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < N;
}
void dfs(char board[][100+1],char alphabet, int r, int c) {
	stack<pair<int, int>>s;
	s.push({ r,c });
	is_visit[r][c] = true;

	while (!s.empty()) {
		int rr = s.top().first;
		int cc = s.top().second;
		s.pop(); 

		for (int i = 0; i < 4; i++) {
			int nr = rr + dr[i];
			int nc = cc + dc[i];

			if (is_range(nr, nc) == true && board[nr][nc] == alphabet && is_visit[nr][nc] == false) {
				is_visit[nr][nc] = true;
				s.push({ nr, nc });
			}
		}

	}
}

void solve() {
	/* 적녹 색약 아님 */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (is_visit[i][j] == false) {
				dfs(map, map[i][j], i, j);
				WEAKNESS++;
			}
		}
	}

	memset(is_visit, false, sizeof(is_visit));

	/* 적록 색약 */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (is_visit[i][j] == false) {
				dfs(weakness_map, weakness_map[i][j], i, j);
				NO_WEAKNESS++;
			}
		}
	}
	cout << WEAKNESS << " " << NO_WEAKNESS << '\n';
}
