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
	int sum, max_sum = 987654321;
	for (int i = 1; i <= 4; i++) {
		sum = 3 + N-1;
		for (int j = 1; j <= N-2; j++){
			if (i < row[j]) {
				sum += min(row[j] - i, i + 4 - row[j]);
			} 
			else {
				sum += min(i - row[j], row[j] + 4 - i);
			}
		}
		max_sum = min(max_sum, sum);
	}
	cout << max_sum << '\n';
}