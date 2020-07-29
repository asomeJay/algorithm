/* 연구소 3 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>


#define pp pair<int,int>
#define MAX 50+1

using namespace std;

void input();
void solve();

int s_of_lab, n_of_virus, ANS = 987654321, empty_space ;
int lab[MAX][MAX];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int time[MAX][MAX];
bool used_virus[MAX];

vector<pp> virus;
queue<pp> q;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> s_of_lab >> n_of_virus;
	for (int i = 0; i < s_of_lab; i++) {
		for (int j = 0; j < s_of_lab; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 0) {
				empty_space++;
			}
			// 해당 지점에 바이러스가 있을 경우, 그 위치를 저장한다. 
			else if(lab[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}
}

void bfs() {
	int temp = 0;
	int temp_empty_space = 0;

	while (!q.empty()) {
		int rr = q.front().first;
		int cc = q.front().second;
		q.pop();

		// 비활성 바이러스 만나면 카운트 안하고 빈공간 만나면 카운트한다. 
		for (int i = 0; i < 4; i++) {
			int nr = rr + dr[i];
			int nc = cc + dc[i];

			if (nr >= 0 && nr < s_of_lab && nc >= 0 && nc < s_of_lab && 
				time[nr][nc] == -1 && lab[nr][nc] != 1) {
				time[nr][nc] = time[rr][cc] + 1;

				if (lab[nr][nc] == 0) {
					temp_empty_space++;
					temp = max(temp, time[nr][nc]);
				}
				q.push({ nr, nc });
			}
		}
	}
	if (ANS > temp && empty_space ==temp_empty_space ) {
		ANS = temp;
	}
}

void dfs(int idx, int cnt) {
	// back tracking 한계 조건
	if (cnt == n_of_virus) {
		memset(time, -1, sizeof(time));

		for (int i = 0; i < virus.size(); i++) {
			if (used_virus[i] == true) {
				q.push({ virus[i].first, virus[i].second });
				time[virus[i].first][virus[i].second] = 0;
			}
		}
		bfs();
		return;
	}

	for (int i = idx; i < virus.size(); i++) {
		if (used_virus[i] == false) {
			used_virus[i] = true;	
			dfs(i+1, cnt + 1);
			used_virus[i] = false;
		}
	}
}

void solve() {
	dfs(0, 0);
	if (ANS == 987654321) ANS = -1;
	cout << ANS << '\n';
}