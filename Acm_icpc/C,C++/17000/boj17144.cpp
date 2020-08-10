/* 미세먼지 안녕! */

#include <iostream>
#include <queue>

#define MAX_N 50 + 1

using namespace std;

void input();
void solve();

int R, C, T;
int A[50 + 1][50 + 1];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

vector<pair<int, int>> air_cleaner;
queue<pair<int, pair<int, int>>> dust;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	input(); solve();
	return 0;
}

void input() {
	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> A[i][j];

			if (A[i][j] == -1) {
				air_cleaner.push_back({ i,j }); // 위쪽 좌표를 저장하게 된다.
			}
			else if (A[i][j] != 0) {
				dust.push({ A[i][j], {i,j} });
			}
		}
	}
}

inline bool is_range(int r, int c) {
	return r >= 0 && r < R&& c >= 0 && c < C;
}

inline bool is_air_cleaner(int r, int c) {
	if (r == air_cleaner[0].first && c == air_cleaner[0].second) return true;
	if (r == air_cleaner[1].first && c == air_cleaner[1].second) return true;
	return false;
}

void solve() {

	while (T--) {
		// 미세먼지
		while (!dust.empty()) {
			int val = dust.front().first;
			int rr = dust.front().second.first;
			int cc = dust.front().second.second;

			dust.pop();

			int dir = 0;
			for (int i = 0; i < 4; i++) {
				int nr = rr + dr[i];
				int nc = cc + dc[i];
				
				if (is_range(nr, nc) == true && is_air_cleaner(nr,nc) == false){
					dir++;
					A[nr][nc] += (val / 5);
				}
			}

			A[rr][cc] = A[rr][cc] - val + (val - (val / 5) * dir);
		}

		// 공기청정기 
		int r = air_cleaner[0].first, c = air_cleaner[0].second;
		
		while (c > 0) {
			A[r][c] = A[r][c - 1]; 
			c--;
		}
		while (r > 0) {
			A[r][c] = A[r - 1][c];
			r--;
		}

		while (c < C - 1) {
			A[r][c] = A[r][c + 1];
			c++;
		}

		while (r < air_cleaner[0].first) {
			A[r][c] = A[r + 1][c];
			r++;
		}

		while (c > air_cleaner[0].second + 1) {
			A[r][c] = A[r][c - 1];
			c--;
		}
		A[r][c] = 0;
		// 아래쪽 공기청정기
		r = air_cleaner[1].first, c = air_cleaner[1].second;
		while (r < R - 1) {
			A[r][c] = A[r + 1][c];
			r++;
		}
		while (c < C-1) {
			A[r][c] = A[r][c + 1];
			c++;
		}
		while (r > air_cleaner[1].first) {
			A[r][c] = A[r - 1][c];
			r--;
		}
		while (c > air_cleaner[1].second + 1) {
			A[r][c] = A[r][c - 1];
			c--;
		}
		A[r][c] = 0;
		A[air_cleaner[0].first][air_cleaner[0].second] = -1;
		A[air_cleaner[1].first][air_cleaner[1].second] = -1;

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {

				if (is_air_cleaner(i, j) == false && A[i][j] != 0) {
					dust.push({ A[i][j], { i,j } });
				}
			}
		}
	}

	int summation = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {

			if (is_air_cleaner(i,j) == true) continue;
			summation += A[i][j];
		}
	}
	cout << summation;
}