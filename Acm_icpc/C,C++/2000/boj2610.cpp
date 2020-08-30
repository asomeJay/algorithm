/* 회의준비 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define ll long long int
#define pp pair<ll,ll>
#define INF 2100000000

using namespace std;

void input();
void solve();

int N, M;
bool is_visit[101];
vector<ll> answer;
ll dp[110][110];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	fill(&dp[0][0], &dp[110 - 1][110], INF);
	
	input(); solve();
	return 0;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		dp[a][b] = 1;
		dp[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		dp[i][i] = 0;
	}
	return;
}

void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dp[i][j] > dp[i][k] + dp[k][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}

	return;
}

void representation() {

	queue<int> q;

	for (int i = 1; i <= N; i++) {
		// 이미 방문한 노드는 다른 그룹에 속해있으니 패스. 
		if (is_visit[i] == true) continue;

		// 아직 방문하지 않았으니 새로운 그룹을 형성할 수 있다. 
		is_visit[i] = true;

		q.push(i);
		// maxi는 현재 그룹의 최솟값, idx는 그 최솟값의 번호
		ll maxi = INF, idx = i;

		while (!q.empty()) {
			//t_maxi는 현재 노드의 최댓값
			// 이 최댓값들 중 최솟값을 구하는 게 이 문제의 핵심
			ll curr = q.front(), t_maxi = 0;
			q.pop();

			// 이걸로 현재 노드가 갈 수 있는 모든 weight를 구한다. 
			for (int j = 1; j <= N; j++) {
				// 현재 노드와 같으면 계산하지 않아도 된다.
				if (j == curr) continue;

				// 아직 방문하지 않은 노드고 현재 노드와 연결되어 있는 노드라면
				if (dp[curr][j] != INF && is_visit[j] == false) {
					// 방문체크하고 큐에 삽입한다. 
					is_visit[j] = true;
					q.push(j);
				}

				// 방문여부와 상관없이 현재 노드(curr)와 연결된 모든 weight 중 최댓값을 찾는다.
				if (dp[curr][j] != INF) {
					t_maxi = max(t_maxi, dp[curr][j]);
				}
			}
			
			// t_maxi 는 현재 노드이 가지는 가장 큰 값이다. 이 비용이 현재 그룹의 최솟값이라면 최솟값을 교체한다. 
			if (t_maxi < maxi) {
				maxi = t_maxi;
				idx = curr;
			}
		}

		// 현재 그룹의 최솟값 Index를 삽입한다. 
		answer.push_back(idx);
	}

	return;
}

void solve() {
	// 일단 각 점에서 각 점으로의 최단 거리를 구한다. 
	// 그러면 연결된 점은 INF가 아니겠지만 끊어진 점은 INF가 된다/
	floyd();
	//같은 구역 내에서 대표를 구한다.
	representation();
	cout << answer.size() << '\n';
	sort(answer.begin(), answer.end());
	for (auto i : answer) {
		cout << i << '\n';
	}
	return;
}