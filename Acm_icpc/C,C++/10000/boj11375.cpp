/* 11375 ¿­Ç÷°­È£ */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;

int N, M, cnt, person[MAX], work[MAX];
vector<int> adj[MAX];

bool visited[MAX];

void solve();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int nn; cin >> nn;
		for (int j = 0; j < nn; j++) {
			int temp; cin >> temp;
			adj[i].push_back(temp);
		}
	}
	
	solve();
	cout << cnt << '\n';

	return 0;
}

bool dfs(int x) {
	for (int b : adj[x]) {
		if (visited[b]) continue;
		visited[b] = true;
		if (work[b] == 0 || dfs(work[b])) {
			person[x] = b;
			work[b] = x;
			return true;
		}
	}
	return false;
}

void solve() {
	for (int i = 1; i <= N; i++) {
		fill(visited, visited + MAX, false);
		if (dfs(i)) cnt++;
	}
}

