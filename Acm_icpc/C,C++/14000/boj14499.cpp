/* 주사위 굴리기 */

#include <iostream>

#define MAX 21

using namespace std;

int N, M, x, y, K;
int map[MAX][MAX], dice[7];
int dy[5] = { 0, 0,0,-1,1 };
int dx[5] = { 0,1,-1,0,0 };

void input();
void solve();
void roll_the_dice(int);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> N >> M >> y >> x >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
}

void roll_the_dice(int operation) {
	int temp = dice[4];
		switch (operation) {
		case 1: 
			dice[4] = dice[3];
			dice[3] = dice[1];
			dice[1] = dice[6];
			dice[6] = temp;
			break;
		case 2:
			dice[4] = dice[6];
			dice[6] = dice[1];
			dice[1] = dice[3];
			dice[3] = temp;
					break; 
		case 3: 
			dice[4] = dice[5];
			dice[5] = dice[1];
			dice[1] = dice[2];
			dice[2] = temp;
			break;
		case 4:
			dice[4] = dice[2];
			dice[2] = dice[1];
			dice[1] = dice[5];
			dice[5] = temp;
			break;
		}

}

void solve() {
	for (int i = 0; i < K; i++) {
		int operation; cin >> operation;
		int nx = x + dx[operation];
		int ny = y + dy[operation];
		if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
			roll_the_dice(operation);
			x = nx; y = ny;
			if (map[y][x] == 0) {
				map[y][x] = dice[4];
			}
			else  {
				dice[4] = map[y][x];
				map[y][x] = 0;
			}
			cout << dice[1] << '\n';
		}	
	}
}
