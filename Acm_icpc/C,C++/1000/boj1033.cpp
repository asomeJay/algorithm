/* 1033 칵테일 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define ll long long int
#define MAX_N 11
#define pp pair<int,int>

using namespace std;

int N;
ll dp[MAX_N];
vector<pair<int, pp>> graph[MAX_N];

ll GCD(ll a, ll b);
void dfs(int x, int);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	ll lcm = 1;

	for (int i = 0; i < N - 1; i++) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		graph[a].push_back({ b, {c,d} });
		graph[b].push_back({ a, {d,c} });

		lcm *= (c * d / GCD(c, d)); // 트리 구조이므로 모든 가지가 뻗어나오는 정점이 있을 것이다 .
	}

	dp[0] = lcm;
	dfs(0, -1); // 그 정점부터 DFS를 해가면서 비율에 맞춰채운다. 
	ll global = dp[0];
	for (int i = 1; i < N; i++) {
		if (dp[i] == 0) continue;
		global = GCD(global, dp[i]); // 전체 최대공약수 구하기 
	}


	for (int i = 0; i < N; i++) 
		cout << dp[i] / global << " ";
	
	return 0;
}

ll GCD(ll a, ll b) {
	while (b != 0) {
		ll t = a % b;
		a = b;
		b = t;
	}

	return a;
}
void dfs(int x, int parent) {
	for (auto n : graph[x]) { // x의 자식 들 중 하나를 지목한다. 
		if (n.first == parent) { // 그게 p와 같으면, 이전 노드이므로 pass
			continue;
		} // 그 비율에 맞춰서 최소공배수를 구해서 넣어준다. 
		dp[n.first] = (dp[x] * (ll)n.second.second) / (ll)n.second.first;
		// 넣어주고나서 다시 그 자식 노드 중 하나로 들어간다.
		dfs(n.first, x);
	}
}
