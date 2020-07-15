/* ทฅวม */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int R, C, K, ANS;
string lamp[51];
//int lamp[51][51];
int line[51];

void dfs(int, int);
void input();
void solve();
void push_the_switch(int column);

int main(void) {
	input();
	solve();

	return 0;
}

void solve() {
	for (int i = 0; i < R; i++) {
		int cnt = 0;
		int same = 0;

		for (int j = 0; j < C; j++) {
			if (lamp[i][j] == '0') {
				cnt++;
			}
		}

		if (cnt <= K && (K - cnt) % 2 == 0) {
			for (int k = i; k < R; k++) {
				if (lamp[i] == lamp[k]) {
					same++;
				}
			}

			ANS = max(ANS, same);
		}
	}

	printf("%d\n", ANS);
}

void input() {

	scanf("%d %d", &R, &C);
	getchar();

	for (int i = 0; i < R; i++) {
		cin >> lamp[i];
	}

	scanf("%d", &K);
}
