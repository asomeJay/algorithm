/* BAZE RUNNER */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int maze[1050][5];
int N, col[5] = { 0 }, row[1050];
string s;

void input();
void solve();

int main(void) {
	
	input();
	solve();

	return 0;
}

// 2N 은 무조건 움직여야한다. 

void input() {
	cin >> N;

	for (int i = 1; i <= N - 2; i++) {
		cin >> s;
		for (int j = 1; j <= 4; j++) {
			maze[i][j] = s[j - 1] - '0';
			if (maze[i][j] == 0) {
				col[j]++;
				row[i] = j;
			}
		}
	}
}

void solve() {
	int maxi = 0, max_index = 0;

	for (int i = 1; i <= 4; i++) {
		if (maxi <= col[i]) {
			maxi = col[i];
			max_index = i;
		}
	}
	int sum = 3 + N - 1;

	for (int i = 1; i <= N - 2; i++) {
		if (max_index < row[i]) {
			sum += (min(row[i] - max_index, max_index + 4 - row[i]));
		}
		else {
			sum += min(max_index - row[i], row[i] + 4 - max_index);
		}
	}
	cout << sum << '\n';
}