/* 종이의 개수 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper;
int N, number[3];

void dfs(int sr, int sc, int er, int ec);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	paper.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		paper[i].resize(N + 1);
		for (int j = 1; j <= N; j++) {
			cin >> paper[i][j];
		}
	}

	dfs(1, 1, N, N);

	for (int i = 0; i < 3; i++)
		cout << number[i] << '\n';

	return 0;
}

void dfs(int sr, int sc, int er, int ec) {
	int dist = (er - sr + 1) / 3, i , j;
	bool flag;
	for (int k = -1; k <= 1; k++) {
		flag = true;
		for (i = sr; i <= er; i++) {
			for (j = sc; j <= ec; j++) {
				if (paper[i][j] != k) {
					flag = false;
					break;
				}
			}
		}
		if (flag == true) {
			//cout << sr << " " << sc << " " << er << " " << ec << endl;
			//cout << dist << endl;
			number[k + 1]++;
			return;
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			dfs(sr + dist * i, sc + dist * j, sr + (i+1) * dist - 1, sc + (j+1) * dist - 1);
		}
	}
	
}