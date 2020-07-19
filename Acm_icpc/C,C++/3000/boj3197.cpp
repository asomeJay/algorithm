/* 백조의 호수 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int R, C;
int up, down, l, r;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

char map[1500 + 1][1500 + 1];
bool is_visit[1500 + 1][1500 + 1];
vector<pair<int, int>> swan_position[2];

void input();
void solve();
void dfs();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> R >> C;
	int k = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') {
				swan_position[k++].push_back({ i,j });
			}
		}
	}
}

bool is_range(int dr, int dc) {
	return dr >= up && dr <= down && dc >= l && dc <= r;
}

int dist(pair<int, int> a, pair<int, int> b) {
	return abs(b.first - a.first) + abs(b.second - a.second);
}
void dfs(int idx, int r, int c) {
	stack<pair<int, int>> s;
	s.push({ r,c });

	while (!s.empty()) {
		int cr = s.top().first;
		int cc = s.top().second;
		s.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];
		
			if (is_range(nr, nc) == true && map[nr][nc] == '.' && is_visit[nr][nc] == false) {
				is_visit[nr][nc] = true;
				s.push({ nr, nc });
				swan_position[idx].push_back({ nr,nc });
			}
		}
	}
	up = swan_position[0][0].first;
	down = swan_position[1][0].first;
	l = min(swan_position[0][0].second, swan_position[1][0].second);
	r = max(swan_position[0][0].second, swan_position[1][0].second);
	
}

void solve() {
	dfs(0, swan_position[0][0].first, swan_position[0][0].second);

	stack<pair<int, int>> s;
	s.push({ swan_position[1][0].first, swan_position[1][0].second });
	
	int sum = dist(swan_position[0][0], swan_position[1][0]);

	while (!s.empty()) {
		int cr = s.top().first;
		int cc = s.top().second;
		s.pop();

		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];

			if (is_range(nr, nc) == true && map[nr][nc] == '.' && is_visit[nr][nc] == false) {
				is_visit[nr][nc] = true;
				s.push({ nr, nc });
				for (int j = 0; j < swan_position[0].size(); j++) {
					sum = min(sum, dist(swan_position[0][j], { nr, nc }));
				}
			}
		}
	}
	cout << sum / 2<< '\n';
}
