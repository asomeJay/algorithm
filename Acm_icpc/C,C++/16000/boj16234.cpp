/* 인구 이동 */

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

#define pp pair<int,int>
#define MAXN 50 + 1

using namespace std;

bool open_the_gate[MAXN][MAXN][4];
int map[MAXN][MAXN];
int N, L, R;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

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
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
}

inline bool is_range(int r, int c) {
	return r > 0 && r <= N && c > 0 && c <= N;
}

void solve() {
	bool is_sustain = false; 
	bool is_visit[MAXN][MAXN];
	int day = -1;

	stack<pp> s;
	vector<pp> open;


	while (is_sustain == false) {
		day++;
		is_sustain = true;
		memset(is_visit, false, sizeof(is_visit));

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (is_visit[i][j] == true || map[i][j] == 0) continue;

				s.push({ i,j });

				is_visit[i][j] = true;
				int summation = map[i][j];
				open.push_back({ i,j });

				while (!s.empty()) {
					int rr = s.top().first;
					int cc = s.top().second;

					s.pop();

					for (int k = 0; k < 4; k++) {
						int nr = rr + dr[k];
						int nc = cc + dc[k];

						if (is_range(nr, nc) == true && is_visit[nr][nc] == false &&
							map[nr][nc] != 0) {
							int diff = abs(map[nr][nc] - map[rr][cc]);

							if (diff >= L && diff <= R) {
								is_sustain = false;
								is_visit[nr][nc] = true;
								open.push_back({ nr, nc });
								summation += map[nr][nc];

								s.push({ nr, nc });
							}
						}
					}
				}

				for (auto vec : open) {
					map[vec.first][vec.second] = summation / open.size();
				}
				open.clear();
			}
		}
	}
	cout << day << '\n';
}