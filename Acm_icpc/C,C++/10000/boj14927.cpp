/* Àü±¸ ²ô±â */

#include <iostream>
#include <algorithm>

#define MAX_BALL 19

using namespace std;

int N, Ans = 987654321;
bool ball[MAX_BALL][MAX_BALL];

inline void balling(int r, int c) {
	ball[r][c] ^= 1;
	if (r) ball[r - 1][c] ^= 1;
	if (c) ball[r][c - 1] ^= 1;
	if (r + 1 <= N) ball[r + 1][c] ^= 1;
	if (c + 1 <= N) ball[r][c + 1] ^= 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	bool t_ball[MAX_BALL][MAX_BALL];

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> t_ball[i][j];
		}
	}

	for (int i = (1 << N) - 1; i >= 0; i--) {
		int push = 0;
		copy(&t_ball[0][0], &t_ball[MAX_BALL - 1][MAX_BALL], &ball[0][0]);
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) continue;
			balling(0, j);
			push++;
		}

		for (int j = 1; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (ball[j - 1][k] == 1) {
					balling(j, k);
					push++;
				}
			}
		}
		bool flag = true;
		for (int j = 0; j < N; j++) {
			if (ball[N - 1][j] == 1) {
				flag = false;
				break;
			}
		}

		if (flag == true)
			Ans = min(Ans, push);

	}
	cout << ((Ans == 987654321) ? -1 : Ans);
	
	return 0;
}