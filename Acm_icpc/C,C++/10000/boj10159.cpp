/* Àú¿ï */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void input();
void solve();
	
int N, M, dp[100 + 1];
vector<int> edge[100 + 1];


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
		edge[a].push_back(b);
	}
}

void bfs(int idx) {
	queue<int> q;
	q.push(idx);

	bool is_visit[100 + 1] = { false, };
	is_visit[idx] = true;
	dp[idx] ++;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (auto i : edge[curr]) {
			if (is_visit[i] == false) {
				is_visit[i] = true;
				q.push(i);
				dp[idx]++;
				dp[i]++;
			}
		}
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		bfs(i);
	}

	for (int i = 1; i <= N; i++) {
		cout << N - dp[i] << "\n";
	}
}