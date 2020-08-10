/* บา */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define EMPTY '.'
#define WALL '#'
#define SANGEUN '@'
#define FIRE '*'

using namespace std;

int W, H;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

vector<vector<char>> map;
queue<pair<int, int>> fire, sangeun;
bool sangeun_visit[1000 + 1][1000 + 1];

void init();
void input();
void solve();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t_case; cin >> t_case;
	while (t_case--) {
		init();
		input();
		solve();
	}

	return 0;
}

void init() {
	map.clear();
	while (!fire.empty()) fire.pop();
	while (!sangeun.empty()) sangeun.pop();
	memset(sangeun_visit, false, sizeof(sangeun_visit));
}

void input() {
	cin >> W >> H;

	map.resize(H);
	for (int i = 0; i < H; i++) {
		map[i].resize(W);
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			if (map[i][j] == FIRE) {
				fire.push({ i,j });
			}
			if (map[i][j] == SANGEUN) {
				map[i][j] = EMPTY;
				sangeun.push({ i,j });
				sangeun_visit[i][j] = true;
			}
		}
	}
}

inline bool is_range(int r, int c) {
	return r >= 0 && r < H&& c >= 0 && c < W;
}

void solve() {
	// Fire Explosion logic
	int time = 0;
	while (true) {
		time++;

		if (sangeun.size() == 0)
			break;

		
		int q_size = fire.size();
		while (q_size--) {
			int rr = fire.front().first;
			int cc = fire.front().second;
			fire.pop();

			for (int i = 0; i < 4; i++) {
				int nr = rr + dr[i];
				int nc = cc + dc[i];

				if (is_range(nr, nc) == true && map[nr][nc] == EMPTY) {
					map[nr][nc] = FIRE;
					fire.push({ nr, nc });
				}
			}
		}
		
		int s_size = sangeun.size();
		while (s_size--) {
			int rr = sangeun.front().first;
			int cc = sangeun.front().second;
			sangeun.pop();
			
				for (int i = 0; i < 4; i++) {
					int nr = rr + dr[i];
					int nc = cc + dc[i];

					if (is_range(nr, nc) == false) {
						cout << time << '\n';
						return;
					}
					if (map[nr][nc] == EMPTY && sangeun_visit[nr][nc] == false) {
						sangeun_visit[nr][nc] = true;
						sangeun.push({ nr,nc });
					}
				}
		}

	}
	cout << "IMPOSSIBLE" << '\n';
}