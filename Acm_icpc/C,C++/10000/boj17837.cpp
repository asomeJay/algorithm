/* 새로운 게임 */

#include <iostream>
#include <vector>
#include <algorithm>

#define W 0
#define R 1
#define B 2
#define R 1
#define L 2
#define U 3
#define D 4

using namespace std;

struct node {
	int row, col, dir;
};

int K, N;
int dr[5] = { 0,0,0,-1 ,1};
int dc[5] = { 0, 1, -1, 0, 0 };
int map[14][14];

vector<pair<int, int>> token[14][14];
vector<node> node_vector;


void input();
void solve();
bool move_token(int, int, int, int, int);

int change_dir(int dir) {
	switch (dir) {
	case R: return L;
	case L: return R;
	case U: return D;
	case D: return U;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> N >> K;

	for (int i = 0; i <= N + 1; i++) {
		map[0][i] = B;
		map[N + 1][i] = B;
		map[i][0] = B;
		map[i][N + 1] = B;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j]; 
		}
	}


	for (int i = 0; i < K; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		token[a][b].push_back({ c, 0 });
	}
}

void solve() {
	int turn;
	for (turn = 1; turn <= 1000; turn++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (token[i][j].size() != 0 && token[i][j][0].second < turn) {
					if (move_token(i, j, token[i][j][0].first, 0, turn)) {
						cout << turn << '\n';
						return;
					}
				}
			}
		}
	}

	if (turn == 1001)
		cout << "-1\n";

	return;
}

bool move_token(int r, int c, int dir, int flag, int turn) {
	cout << turn << '\n';
	int nr = r + dr[dir];
	int nc = c + dc[dir];
	if (map[nr][nc] == B) {
		token[r][c][0].first = change_dir(token[r][c][0].first);
		if (flag == 0)
			return move_token(r, c, token[r][c][0].first, flag+1, turn);
	}
	else if (map[nr][nc] == R) {
		for (int i = 0; i < token[r][c].size(); i++) {
			token[nr][nc].push_back(token[r][c][i]);
		}
		reverse(token[nr][nc].begin(), token[nr][nc].end());

		token[r][c].clear();
		token[nr][nc][0].second = turn;
	} 
	else if (map[nr][nc] == W) {
		for (int i = 0; i < token[r][c].size(); i++) {
			token[nr][nc].push_back(token[r][c][i]);
		}
		token[r][c].clear();
		token[nr][nc][0].second = turn;
	}
	else {
		cout << "ERROR at MOVE\n";
	}

	if (token[nr][nc].size() >= 4) 
		return true;
	return false;
}