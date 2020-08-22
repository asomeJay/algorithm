/* »§Áý */

#include <iostream>

#define WALL 'x'
#define EMPTY '.'
#define MAXR 10010
#define MAXC 510

using namespace std;

int R, C, Ans;
int dr[3] = { -1, 0, 1 };

char map[MAXR][MAXC];

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

bool b_t(int r, int c) {
	if (is_range(r, c) == false) return false;
	if (map[r][c] == WALL) return false;
	map[r][c] = WALL;

	if (c == C - 1) return true;

	if (b_t(r - 1, c + 1) == true) return true;
	if (b_t(r, c + 1) == true) return true;
	if (b_t(r + 1, c + 1) == true) return true;
	return false;
}

void solve() {
	for (int i = 0; i < R; i++) {
		if (b_t(i, 0) == true) Ans++;
	}
	cout << Ans << '\n';
	return;
}