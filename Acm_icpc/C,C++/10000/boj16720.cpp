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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	input();
	solve();

	return 0;
}

// 2N 은 무조건 움직여야한다. 

void input() {
	cin >> N;
	
	for (int i = 1; i <= N-2; i++) {
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
	int sum = 3 + N-1;
	cout << max_index << endl;
	for (int i = 1; i <= N-2; i++) {
		cout << i << " " << sum << " " << row[i] << endl;
		sum += (min(abs(max_index - row[i]), abs(row[i] + 4 - max_index)));
	}
	cout << sum << '\n';
}