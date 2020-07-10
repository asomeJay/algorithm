/* 열혈 강호 다시 풀기 */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;

int N, M, person[MAX], work[MAX], cnt;
vector<int> adj[MAX];
bool is_visit[MAX];

bool dfs(int x);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		for (int ii = 0; ii < a; ii++) {
			int temp; cin >> temp;
			adj[i].push_back(temp);
		}
	}

	for (int i = 1; i <= N; i++) {
		fill(is_visit, is_visit + MAX, false);
		if (dfs(i)) cnt++;
	}

	cout << cnt << '\n';
	return 0;
}

bool dfs(int x) {
	for (auto i : adj[x]) {
		if (is_visit[i]) continue;
		is_visit[i] = true;

		if (work[i] == 0 || dfs(work[i])) {
			person[x] = i;
			work[i] = x;
			return true;
		}
	}
	return false;
}
