/* 배열에서 이동 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, small, large;
int map[100 + 1][100 + 1];
bool is_visit[100 + 1][100 + 1];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

inline bool is_range(int r, int c) {
	return r > 0 && r <= n && c > 0 && c <= n;
}

void solve();
bool bfs(int);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	small = 2100000000;
	large = -1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			small = min(small, map[i][j]);
			large = max(large, map[i][j]);
		}
	}

	solve();
	return 0;
}

void solve() {
	int start = 0;
	int end = large - small;
	int mid;

	while (start <= end) {
		mid = (start + end) / 2;

		if (bfs(mid) == true)  end = mid - 1;
		else  start = mid + 1;
	}
	cout << end + 1 << '\n';
}

bool bfs(int mid) {
	for (int value = small; value <= large; value++) {
		memset(is_visit, false, sizeof(is_visit));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (value <= map[i][j] && map[i][j] <= value + mid) {
					is_visit[i][j] = true;
				}
			}
		}

		queue<pair<int, int>> q;
		q.push({ 1, 1 });
		
		while (!q.empty()) {
			int rr = q.front().first;
			int cc = q.front().second;
			q.pop();

			if (is_visit[rr][cc] == false) continue;
			is_visit[rr][cc] = false;

			if (rr == n && cc == n) {
				return true;
			}

			for (int i = 0; i < 4; i++) {
				int nr = rr + dr[i];
				int nc = cc + dc[i];

				if (is_range(nr, nc) == true){
					q.push({ nr,nc });
				}
			}
		}
	}
	return false;
}