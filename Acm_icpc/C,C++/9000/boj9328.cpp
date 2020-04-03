/* 열쇠 */
/* BFS로 풀면된다. 
현재 방향에서 사방의 칸을 추가하는 방식으로 진행되는데,
중복이 많이 발생할 수 있으므로 추가할 때마다 방문 체크를 하는게 낫다. 
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int h, w, paper;
const int dr[4] = { -1, 0, 1, 0 };
const int dc[4] = { 0, 1, 0, -1 };
vector<vector<char>> map;
char key[26];
bool is_visit[102][102];

void init();
void input();
inline bool is_range(int r, int c);
void bfs(int r, int c);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tk; 
	cin >> tk;

	for (int i = 0; i < tk; i++) {
		init();
		input();
		bfs(0, 0);
		cout << paper << '\n';
	}

	return 0;
}

inline bool is_range(int r, int c) {
	return 0 <= r && r <= h+1 && 0 <= c && c <= w+1;
}

void bfs(int r, int c) {
	queue<pair<int, int>> search;

	is_visit[r][c] = true;
	search.push({ r,c });

	while (!search.empty()) {
		int tr = search.front().first;
		int tc = search.front().second;
		search.pop();

		if (map[tr][tc] == '$') {
			paper++;
			map[tr][tc] = '.';
		}

		for (int i = 0; i < 4; i++) {
			int nr = tr + dr[i];
			int nc = tc + dc[i];

			if (!is_range(nr, nc) || is_visit[nr][nc] || map[nr][nc] == '*') continue;
			if (map[nr][nc] >= 'A' && map[nr][nc] <= 'Z') continue;
			
			if (map[nr][nc] >= 'a' && map[nr][nc] <= 'z') {
				if (!key[map[nr][nc] - 'a']) {
					key[map[nr][nc] - 'a'] = true;
					memset(is_visit, false, sizeof(is_visit));
					for (int j = 1; j <= h; j++) {
						for (int k = 1; k <= w; k++) {
							if (map[j][k] - 'A' == map[nr][nc] - 'a')
								map[j][k] = '.';
						}
					}

					while (!search.empty())
						search.pop();
				}
				map[nr][nc] = '.';
			}

			search.push({ nr, nc });
		}
	}
}

void init() {
	paper = 0;
	memset(key, false, sizeof(key));
	memset(is_visit, false, sizeof(is_visit));
}

void input() {
	cin >> h >> w;
	map.resize(h + 2);

	for (int i = 0; i < h + 2; i++)
		map[i].resize(w + 2) ;

	for (int i = 0; i < h + 2; i++) {
		map[i][0] = map[i][h + 1] = '.';
	}
	for (int i = 0; i < w + 2; i++) {
		map[0][i] = map[h + 1][i] = '.';
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> map[i][j];
		}
	}

	string s;
	cin >> s;
	if (s[0] == '0') return;
	for (auto n : s) {
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (map[i][j] - 'A' == n - 'a')
					map[i][j] = '.';
			}
		}
	}

}