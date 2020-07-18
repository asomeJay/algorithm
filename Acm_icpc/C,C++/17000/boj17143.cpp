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

	input();
	solve();
	
	return 0;
}

void input() {
	scanf("%d %d %d", &R, &C, &M);
	getchar();
for (int i = 0; i < M; i++) {
	int r, c, speed, dir, size;
	scanf("%d %d %d %d %d", &r, &c, &speed, &dir, &size);
	getchar();
	map[r][c].push_back(shark(size, dir, speed, 0));
}
}

bool is_range(int r, int c) {
	return r >= 1 && r <= R && c >= 1 && c <= C;
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

void shark_move(int column) {
	bool is_first = false;

	queue<pair<int, int>> q;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (!map[i][j].empty()) {
				if (is_first == false && j == column) {
					is_first = true;
					ANS += map[i][column].front().size;
					map[i][column].pop_front();
				}
				else {
					q.push({ i,j });
				}
			}
		}
	}

	while (!q.empty()) {

		int nr = q.front().first;
		int nc = q.front().second;
		q.pop();
		int t_dir = map[nr][nc].front().dir;
		int t_size = map[nr][nc].front().size;
		int t_speed = map[nr][nc].front().speed;
		int t_count = map[nr][nc].front().count;

		int cnt = 0;

		map[nr][nc].pop_front();

		/* 속도에 의해서 Position 구하기 */
		int d, temp_speed = t_speed, dividend;
		switch (t_dir) {
		case 1: // 위쪽으로 향하기
			d = nr - 1;
			if (t_speed <= d) {
				// 끝까지 겨우 도달할 정도
				nr += dr[t_dir] * t_speed;
			}
			else {
				dividend = R - 1;
				temp_speed -= d;
				t_dir = direction(t_dir);

				int div1 = temp_speed / dividend;
				int div2 = temp_speed % dividend;
				if (div1 % 2 == 0) {
					nr = 1;
				}
				else {
					nr = R;
					t_dir = direction(t_dir);
				}

				nr += dr[t_dir] * div2;
			}
			break;
		case 2: // 아래쪽으로 향하기
			d = R - nr;
			if (t_speed <= d) {
				// 끝까지 겨우 도달할 정도
				nr += dr[t_dir] * t_speed;
			}
			else {
				dividend = R - 1;
				temp_speed -= d;

				int div1 = temp_speed / dividend;
				int div2 = temp_speed % dividend;
				t_dir = direction(t_dir);

				if (div1 % 2 == 1) {
					nr = 1;
					t_dir = direction(t_dir);
				}
				else {
					nr = R;
				}
				nr += dr[t_dir] * div2;
			}
			break;
		case 3: // 오른쪽으로 향하기
			d = C - nc;
			if (t_speed <= d) {
				// 끝까지 겨우 도달할 정도
				nc += dc[t_dir] * t_speed;
			}
			else {
				dividend = C - 1;
				temp_speed -= d;

				t_dir = direction(t_dir);

				int div1 = temp_speed / dividend;
				int div2 = temp_speed % dividend;
			
				if (div1 % 2 == 0) {
					nc = C;
				}
				else {
					nc = 1;
					t_dir = direction(t_dir);
				}
				nc += dc[t_dir] * div2;
			}
			break;
		case 4: // 왼쪽으로 향하기
			d = nc - 1;
			if (t_speed <= d) {
				// 끝까지 겨우 도달할 정도
				nc += dc[t_dir] * t_speed;
			}
			else {
				dividend = C - 1;
				temp_speed -= d;

				t_dir = direction(t_dir);

				int div1 = temp_speed / dividend;
				int div2 = temp_speed % dividend;

				if (div1 % 2 == 0) {
					nc = 1;
				}
				else {
					nc = C;
					t_dir = direction(t_dir);
				}

				nc += dc[t_dir] * div2;
			}
			break;
		default:
			cout << "?"; 
		}

		if (!map[nr][nc].empty()) {
			// 아직 옮기지 않은거거나 이미 옮겨진거거나
			if (map[nr][nc].back().count > t_count) {
				// 이미 옮겨진거라면 얘도 옮길건데
				if (map[nr][nc].back().size <= t_size) {
					map[nr][nc].pop_back();
					map[nr][nc].push_back(shark(t_size, t_dir, t_speed, t_count + 1));
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
}

void solve() {
	for (int person = 1; person <= C; person++) {
		shark_move(person);
	}

	printf("%d\n", ANS);
}
