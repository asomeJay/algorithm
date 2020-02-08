/* �� �μ��� �̵��ϱ� */

#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

#define MAX_MAP 1001
#define IN_RANGE 1
#define OUT_RANGE 0
#define VISIT 1
#define UNVISIT 0
#define INTMAX 2000000

using namespace std;

int N, M, ANS;
int map[MAX_MAP][MAX_MAP];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
bool is_visit[MAX_MAP][MAX_MAP][2] = { 0, };

bool is_range(int, int);
int bfs(int, int);

int main(void) {
	cin >> N >> M;
	int i, j;

	for (i = 1; i <= N; i++) {
		getchar();
		for (j = 1; j <= M; j++) {
			map[i][j] = getchar() - '0';
		}
	}
	
	ANS = INTMAX;
	ANS= min(ANS,bfs(1, 1)); 
	
	cout << ANS << '\n';
	return 0;
}

bool is_range(int r, int c) {
	return r >= 1 && r <= N && c >= 1 && c <= M;
}

int bfs(int fr, int fc) {
	int i, j, r, c, tr, tc, nr, nc;
	int visit, cnt;

	queue<tuple<int, int, int, int>> q;
	q.push(make_tuple(fr, fc, 0, 1));

	while (!q.empty()) {
		tr = get<0>(q.front());
		tc = get<1>(q.front());
		visit = get<2>(q.front());
		cnt = get<3>(q.front());

		q.pop();
		if (tr == N && tc == M) {
			return cnt;
		}

		for (i = 0; i < 4; i++) {
			nr = tr + dr[i];
			nc = tc + dc[i];

			if (is_range(nr, nc) == OUT_RANGE) continue;

			// �� ���� ĭ�� ���̰� ���� �ѹ��̻� �ν���.
			if (map[nr][nc] == 1 && visit >= 1)
				continue;

			// �� ���� ĭ�� ���̰� ���� �ѹ��̻� �μ��� �ʾҴ�.
			if (map[nr][nc] == 1 && visit < 1) {
				is_visit[nr][nc][visit + 1] = VISIT;
				q.push(make_tuple(nr, nc, visit+1, cnt + 1));
			}

			// �� ���� ĭ�� ���� �ƴϰ� ���� �ѹ��̻� �ν���. 
			// �� ���� ĭ�� ���� �ƴϰ� ���� �ѹ��̻� �μ��� �ʾҴ�. 
			if (map[nr][nc] == 0 && is_visit[nr][nc][visit] != VISIT) {
				is_visit[nr][nc][visit] = VISIT;
				q.push(make_tuple(nr, nc, visit, cnt + 1));
			}
		}
	}
	return -1;
}