/* ���� ��������, ���� */
/* ����Ž�� �ϸ� �ɵ�
1. �ν��� ��ġ�� �ⱸ ��ġ ����
2. �ν��� ��ġ���� �� �Ʒ� �� ���� Ž���Ѵ�.
2-1. ���谡 ���� �� ���� ������ �ν��Ѵ�. */
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

pi minsik_pos; // �ν��� ��ġ�� �ⱸ ��ġ �����Ұž�. 

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
			// ��湮 ���� �ʰ�, ���� ����� �� ����.

			if (maze[nr][nc] >= 'A' && maze[nr][nc] <= 'F') {	// ���ε� ���谡 ��� ������~
				if (!(tkey & (1 << (maze[nr][nc] - 'A'))) ) continue;
			}

			if (maze[nr][nc] >= 'a' && maze[nr][nc] <= 'f') {	
				// ���谡 �ִ� ���̸� ����
				// �����Ϸ��� �� �������� �̵��ؾ��Դϴ�. 

				is_visit[tkey | (1 << (maze[nr][nc] - 'a'))][nr][nc] = true;
				q.push(minsik(nr, nc, tcnt + 1, tkey | (1 << (maze[nr][nc] - 'a'))));				// ��Ʈ�������� ���� �ٽ� ����������
			}
			else {
				// �� �׳� ������̱��� ���ô�
				is_visit[tkey][nr][nc] = true;
				q.push(minsik(nr, nc, tcnt + 1, tkey));
			}
		}
	}
}
