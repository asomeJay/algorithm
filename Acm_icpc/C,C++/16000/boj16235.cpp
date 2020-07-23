/* 나무 재테크 */

#include <iostream>
#include <vector>
#include<algorithm>

#define BOARD 10 + 1

using namespace std;

void input();
void solve();

int N, M, K;
int dr[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dc[8] = { -1,0,1,1,1,0,-1,-1 };

int map[BOARD][BOARD];
vector<int> tree[BOARD][BOARD];
vector<pair<pair<int, int>, int>> dead_tree;
int A[BOARD][BOARD];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;

}

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			map[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		int r, c, age;
		cin >> r >> c >> age;
		tree[r][c].push_back(age);
	}

}

inline bool is_range(int r, int c) {
	return r >= 1 && r <= N && c >= 1 && c <= N;
}

void spring() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tree[i][j].empty() == false) {
				if (tree[i][j].size() > 1) {
					sort(tree[i][j].begin(), tree[i][j].end());
				}
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (map[i][j] >= tree[i][j][k]) {
						map[i][j] -= tree[i][j][k];
						tree[i][j][k]++;
					}
					else {
						dead_tree.push_back({ {i,j}, tree[i][j][k] });
						tree[i][j].erase(tree[i][j].begin() + k);
						k--;
					}
				}
			}
		}
	}
}

void summer() {
	int dead_size = dead_tree.size();
	for (int i = 0; i < dead_size; i++) {
		map[dead_tree[i].first.first][dead_tree[i].first.second] +=
			dead_tree[i].second / 2;
	}
	dead_tree.clear();
}

void fall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int t_size = tree[i][j].size();
			for (int k = 0; k < t_size; k++) {
				if (tree[i][j][k] % 5 == 0) { // 5의 배수라면
					for (int t = 0; t < 8; t++) {
						int nr = i + dr[t];
						int nc = j + dc[t];

						if (is_range(nr, nc) == true) {
							tree[nr][nc].push_back(1);
						}
					}
				}
			}
		}
	}
}
void winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] += A[i][j];
		}
	}
}

void solve() {
	for (int year = 1; year <= K; year++) {
		//spring
		spring();
		//summer 
		summer();
		//fall
		
		fall();
		//winter
		winter();
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cnt += tree[i][j].size();
		}
	}

	cout << cnt << '\n';
}