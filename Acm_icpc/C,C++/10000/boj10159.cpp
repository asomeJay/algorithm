/* Àú¿ï */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void input();
void solve();
	
int N, M;
bool edge[100 + 1][100 + 1];


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		edge[a][b] = true;
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (edge[j][i] == true && edge[i][k] == true) {
					edge[j][k] = true;
				}
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (!edge[i][j] && !edge[j][i]) cnt++;
		} 
		cout << cnt - 1 << '\n';
	}
}