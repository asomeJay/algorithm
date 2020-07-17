/* 낚시왕 */

#include <iostream>
#include <queue>

#define MAX 500+ 1

using namespace std;

class shark {
public :
	int size, dir, speed, count;
	shark(int a, int b, int c, int d) {
		size = a;
		dir = b;
		speed = c;
		count = d;
	}
	shark() {
		size = 0;
		dir = 0;
		speed = 0;
		count = 0;
	}
};

deque<shark> map[500 + 1][500 + 1];
int R, C, M, ANS;
int dr[5] = {0, -1, 1, 0,0 };
int dc[5] = {0, 0,0,1,-1 };

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
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int r, c, speed, dir, size;
		cin >> r >> c >> speed >> dir >> size;
		map[r][c].push_back(shark(size, dir, speed, 0));
	}
}

bool is_range(int r, int c) {
	return r >= 1 && r <= R&& c >= 1 && c <= C;
}

int direction(int dir) {
	switch (dir) {
	case 1:
		return 2;
	case 2: 
		return 1;
	case 3:
		return 4;
	case 4:
		return 3;
	}
}

void shark_move() {
	queue<pair<int, int>> q;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if(!map[i][j].empty())
				q.push({ i,j });
		}
	}
	while (!q.empty()) {
		int nr = q.front().first;	
		int nc = q.front().second;
		q.pop();
		int t_dir = map[nr][nc].front().dir;
		int t_size = map[nr][nc].front().size;
		int t_speed = map[nr][nc].front(). speed;
		int t_count = map[nr][nc].front().count;

		int cnt = 0;
	
		map[nr][nc].pop_front();

		while (cnt != t_speed) {
			if (is_range(nr, nc) == false) {
				t_dir = direction(t_dir);

				nr += dr[t_dir];
				nc += dc[t_dir]; 
			}

			nr += dr[t_dir];
			nc += dc[t_dir]; 

			cnt++;
		}

		if (!map[nr][nc].empty()) {
			// 아직 옮기지 않은거거나 이미 옮겨진거거나
			if (map[nr][nc].back().count > t_count) {
				// 이미 옮겨진거라면 얘도 옮길건데
				if (map[nr][nc].back().size > t_size) {
					// 이제 도착하는 즉시 잡아먹힌다. 
					;
				}
				else {
					map[nr][nc].pop_back();
					map[nr][nc].push_back(shark(t_size, t_dir, t_speed, t_count + 1));
					// 도착하면 얘가 잡아먹을거야
				}
			}
			else {
				// 아직 옮기기 전이야.
				map[nr][nc].push_back(shark(t_size, t_dir, t_speed, t_count + 1));
			}
		}
		else {
			// 비어있는 곳임
			map[nr][nc].push_back(shark(t_size, t_dir, t_speed, t_count + 1));
		}
	}
//	for (int i = 1; i <= R; i++) {
//		for (int j = 1; j <= C; j++) {
//			if (map[i][j].size != 0) {
		
//			}
//		}
//	}
}
void solve() {
	for (int person = 1; person <= C; person++) {
		for (int r = 1; r <= R; r++) {
			if (!map[r][person].empty()) {

				cout << r << " " << person << " " << map[r][person].front().size << endl;
				ANS += map[r][person].front().size;
				map[r][person].pop_front();
				break;
			}	
		}
		shark_move();
	}

	cout << ANS;
}
