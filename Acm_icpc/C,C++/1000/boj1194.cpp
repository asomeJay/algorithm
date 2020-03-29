/* 달이 차오른다, 가자 */
/* 완전탐색 하면 될듯
1. 민식이 위치랑 출구 위치 저장
2. 민식이 위치부터 위 아래 양 옆을 탐색한다.
2-1. 열쇠가 없을 때 문은 벽으로 인식한다. */
#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_MAZE 52
#define pi pair<int,int>

using namespace std;

class minsik{
public:
	int r, c, cnt, key;
	minsik(int rr, int cc, int ccnntt, int kkeeyy) {
		this->r = rr;
		this->c = cc;
		this->cnt = ccnntt;
		this->key = kkeeyy;
	}
};

int R, C, ANS = 987654321;
const int dr[4] = { -1, 0, 1, 0 };
const int dc[4] = { 0, 1, 0,-1 };
char maze[MAX_MAZE][MAX_MAZE];
bool is_visit[1 << 6][MAX_MAZE][MAX_MAZE];

pi minsik_pos; // 민식이 위치랑 출구 위치 저장할거야. 

void input();
void bfs();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	is_visit[0][minsik_pos.first][minsik_pos.second] = true;
	bfs();
	if (ANS == 987654321)
		ANS = -1;
	cout << ANS;

	return 0;
}

void input() {
	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		maze[i][0] = maze[i][C + 1] = '#';
	}
	for (int i = 1; i <= C; i++) {
		maze[0][i] = maze[R + 1][i] = '#';
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == '0') {
				minsik_pos.first = i;
				minsik_pos.second = j;
			}
		}
	}
}

void bfs() {

	queue<minsik> q;
	q.push(minsik(minsik_pos.first, minsik_pos.second, 0, 0));

	while (!q.empty()) {
		int tr = q.front().r;
		int tc = q.front().c;
		int tcnt = q.front().cnt;
		int tkey = q.front().key;
		q.pop();

		if (maze[tr][tc] == '1') {
			ANS = tcnt;
			return;
		}
			
		for (int i = 0; i < 4; i++) {
			int nr = tr + dr[i];
			int nc = tc + dc[i];

			if (is_visit[tkey][nr][nc] || maze[nr][nc] == '#') continue;			
			// 재방문 하지 않고, 벽도 통과할 수 없음.

			if (maze[nr][nc] >= 'A' && maze[nr][nc] <= 'F') {	// 문인데 열쇠가 없어도 못가요~
				if (!(tkey & (1 << (maze[nr][nc] - 'A'))) ) continue;
			}

			if (maze[nr][nc] >= 'a' && maze[nr][nc] <= 'f') {	
				// 열쇠가 있는 곳이면 줍줍
				// 줍줍하려면 그 방향으로 이동해야함니다. 

				is_visit[tkey | (1 << (maze[nr][nc] - 'a'))][nr][nc] = true;
				q.push(minsik(nr, nc, tcnt + 1, tkey | (1 << (maze[nr][nc] - 'a'))));				// 백트랙했으면 열쇠 다시 내려놔야죠
			}
			else {
				// 와 그냥 빈공간이군요 갑시다
				is_visit[tkey][nr][nc] = true;
				q.push(minsik(nr, nc, tcnt + 1, tkey));
			}
		}
	}
}
