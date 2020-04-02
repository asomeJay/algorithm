/* ¿­¼è */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int h, w, paper;
const int dr[4] = { -1, 0, 1, 0 };
const int dc[4] = { 0, 1, 0, -1 };
vector<vector<char>> map;
char key[26];
bool is_visit[101][101];

void init();
void input();
inline bool is_range(int r, int c);
int open_the_door(int r, int c);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tk; cin >> tk;

	for (int i = 0; i < tk; i++) {

		input();


	}

	return 0;
}

inline bool is_range(int r, int c) {
	return 0 <= r && r < h && 0 <= c && c < w;
}

int open_the_door(int r, int c) {

	queue<pair<int, int>> search;
	search.push({ r,c });
	while (!search.empty()) {
		int tr = 
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (map[nr][nc] == '*' || !is_range(nr, nc)) continue;
			if (map[nr][nc] >= 'A' && map[nr][nc] <= 'Z') {
				char c = map[nr][nc];
				if (!key[c - 'A']) continue;
			}
			if (map[nr][nc] >= 'a' && map[nr][nc] <= 'z') {
				char c = map[nr][nc];
				key[c - 'a'] = true;
			}
	}

	


	}
}

void init() {
	paper = 0;
}

void input() {
	cin >> h >> w;
	map.resize(h);

	for (int i = 0; i < h; i++)
		map.resize(w);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
		}
	}


}