/* 1799 ��� */

#include <iostream>
#include <algorithm>

#define BLACK 0
#define WHITE 1

using namespace std;

void input();
void solve();

int dr[4] = { -1,-1,1,1 };
int dc[4] = { -1,1,1,-1 };
int N, ANS[2];

bool chess[10][10];
bool is_visit[10][10];


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	input();
	solve();
	
	return 0;
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> chess[i][j];
		}
	}
}

/* �ʰ� ���ϴ� ĭ�� ����� ���� �� �ִ��� simulation�Ѵ� */
/* �����ϸ� true, �Ұ����ϸ� false*/
bool simulation(int r, int c) { 
	if (chess[r][c] == false) return false;

	for (int i = 0; i < 4; i++) {
		int nr, nc;
		nr = r; nc = c;

		while (true) {
			nr += dr[i];
			nc += dc[i];

			if (!(nr >= 0 && nr < N && nc >= 0 && nc < N))
				break;
			if (is_visit[nr][nc] == true)
				return false;
		}
	}
	return true;
}

void b_t(int r, int c, int cnt, int color) { // back tracking �ٿ��� b_t��� �Ѵ�
	if (c >= N) { // C�� ������ ����� ���� ������ �����Ѵ�. 
		r++; 
		if (r % 2 == 0) c = (color == BLACK ? 0 : 1);
		else c = (color == BLACK ? 1 : 0);
	}

	if (r >= N) { // Ž�� ����
		ANS[color] = max(ANS[color], cnt);
		return;
	}

	if (simulation(r,c) == true) { // ���� �� ĭ�� ����� ���� �� �ִ°�?
		is_visit[r][c] = true;
		b_t(r, c + 2, cnt + 1, color); // �� ĭ�� ��� �־����ϱ� +1 �ϱ�!
		is_visit[r][c] = false;
	}

	b_t(r, c + 2, cnt, color);
}

void solve() {
	// b_t( row, column, count, color) << �䷱ �Ű�������.
	b_t(0, 0, 0, BLACK); // Black
	b_t(0, 1, 0, WHITE); // WHITE

	cout << ANS[0] + ANS[1];
}