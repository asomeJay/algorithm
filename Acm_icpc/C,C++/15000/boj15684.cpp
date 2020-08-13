/* 사다리 조작 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void input();
void solve();

int N, M, H;
bool ghost_leg[30 + 2][30 + 2];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> N >> M >> H;
	for (int j = 1; j <= M; j++) {
		int a, b;
		cin >> a >> b;

		ghost_leg[a][b] = true;
	}
}

bool dfs(int idx, int row, int col) {
	while (row <= H && ghost_leg[row][col - 1] == false && ghost_leg[row][col] == false) {
		row++;
	}
	// 탐색이 끝났으면 시작했던 그 Column으로 돌아왔는지 확인한다.
	if (row > H) { return col == idx; }

	if (ghost_leg[row][col] == true) {
		return dfs(idx, row + 1, col + 1);
	}

	else if (ghost_leg[row][col - 1] == true) {
		return dfs(idx, row + 1, col-1);
	}
}

bool chk() {
	for (int i = 1; i <= N; i++) {
		if (dfs(i, 1, i) ==false) {
			return false;
		}
	}
	return true;
}

bool make_the_bridge(int cnt) {

	if (cnt == 0) {
		return chk();
	}

	bool flag = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= H; j++) {
			// 이미 연결되어있으면
			if (ghost_leg[j][i] == true || ghost_leg[j][i-1] == true || ghost_leg[j][i+1] == true) {
				continue;
			}

			ghost_leg[j][i] = true;
			flag |= make_the_bridge(cnt - 1);
			ghost_leg[j][i] = false;
		}
	}
	return flag;
}

void solve() {
	int i;
	for (i = 0; i <= min(H, 3); i++) {

		if (make_the_bridge(i) == true) {
			cout << i << '\n';
			return;
		}
	}

	cout << "-1" << '\n';
	return;
}