/* 백조의 호수 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define pp pair<int,int>
#define MAX 1500+1

using namespace std;

int R, C;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

queue<pp> waterQ;
vector<pp> swanV;
char map[MAX][MAX];
bool is_visit[MAX][MAX];

void input();
bool is_range(int, int);
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
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') {
				swanV.push_back({ i,j });
			}
			if (map[i][j] == 'L' || (map[i][j] == '.')) {
				waterQ.push({ i,j });
			}
		}
	}
}

bool is_range(int dr, int dc) {
	return dr >= 1 && dr <= R && dc >= 1&&  dc <= C;
}

void solve() {
	queue<pp> q;
	q.push(swanV[0]);	// 
	is_visit[swanV[0].first][swanV[0].second] = true; // 방문 체크


	int day = 0;
	while (true) {

		bool chk = false;
		queue<pp> nextQ;

		while (!q.empty()) { // 현재 백조가 이동할 수 있는 공간을 체크한다.
			int rr = q.front().first;
			int cc = q.front().second;
			q.pop();

			if (rr == swanV[1].first && cc == swanV[1].second) {
				chk = true;
				break;
			}

			for (int d = 0; d < 4; d++) {
				int nr = rr + dr[d]; // 사방을 확인한다. 
				int nc = cc + dc[d];

				if (is_range(nr, nc) == true && is_visit[nr][nc] == false) {
					is_visit[nr][nc] = true;

					if (map[nr][nc] == 'X')  // 백조의 인접 빙판은 내일 녹는다.
						nextQ.push({ nr,nc });

					else					// 지금 물인 곳을 백조가 헤엄쳐다닌다. 
						q.push({ nr, nc });
				}
			}
		}

		if (chk)
			break;

		q = nextQ;

		int water_size = waterQ.size(); // 한 번에 끝까지 돌리는 게 아니라 지금 큐에 있는것만 점검한다.
		while (water_size--) {
			int rr = waterQ.front().first;
			int cc = waterQ.front().second;
			waterQ.pop();

			for (int i = 0; i < 4; i++) {
				int nr = rr + dr[i];
				int nc = cc + dc[i];

				if (is_range(nr, nc) == true && map[nr][nc] == 'X') {
					map[nr][nc] = '.';
					waterQ.push({ nr,nc });
				}
			}
		}
		day++;	// 하루 증가
	}

	cout << day << '\n';
}
