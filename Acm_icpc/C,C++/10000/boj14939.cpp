/* ºÒ²ô±â */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 987654321

int Ans = MAX;

inline void change(char& c) {
	if (c == '#') c = 'O';
	else c = '#';
}
inline void switch_turn(int r, int c, char V[10][10]) {
	change(V[r][c]);
	if (r) change(V[r - 1][c]);
	if (c) change(V[r][c - 1]);
	if (r != 9) change(V[r + 1][c]);
	if (c != 9) change(V[r][c + 1]);
}

int main(void) {
	char map[10][10], t_map[10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = getchar();
		}
		getchar();
	}
	
	for (int outer = (1 << 10) - 1; outer >= 0; outer--) {
		int push = 0;
		copy(&map[0][0], &map[9][10], &t_map[0][0]);

		for (int i = 0; i < 10; i++) {
			if (outer & (1 << i)) {
				switch_turn(0, i, t_map);
				push++;
			}		
		}

		bool flag = true;
		for (int i = 1; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (t_map[i - 1][j] == '#') continue;
				switch_turn(i, j, t_map);
				++push;
			}
		}

		for (int i = 0; i < 10; i++) {
			if (t_map[9][i] == 'O') {
				flag = false;
				break;
			}
		}

		if (flag == true) {
			Ans = min(Ans, push);
		}
	}

	if (Ans == MAX)
		cout << -1;
	else
		cout << Ans;
	
	return 0;
}