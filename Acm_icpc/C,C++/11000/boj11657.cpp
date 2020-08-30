/* 타임머신 */

#include <iostream>
#include <algorithm>
#include <vector>

#define INF 2100000000
#define ll long long int
#define pp pair<ll,ll>

using namespace std;

void input();
void solve();

struct line {
	int src, dst, wgt;
	line(int a, int b, int c) {
		src = a; dst = b; wgt = c;
	}
};

int N, M;
ll dist[501];
vector<line> edge;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
	return 0;
}

void input() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge.push_back(line(a, b, c));
	}
}

bool bellman_ford(int src) {
	fill(dist, dist + 501, INF);
	dist[src] = 0;

	for (int i = 1; i < N; i++) {
		for (auto node : edge) {
			if (dist[node.src] != INF && dist[node.dst] > dist[node.src] + node.wgt) {
				dist[node.dst] = dist[node.src] + node.wgt;
			}
		}
	}

	for (auto node : edge) {
		if (dist[node.src] != INF && dist[node.dst] > dist[node.src] + node.wgt) {
			return true;
		}
	}
	return false;
}

void solve() {
	if (bellman_ford(1) == true) {
		cout << "-1\n";
		return;
	}
	for (int i = 2; i <= N; i++) {
		dist[i] = (dist[i] == INF ? -1 : dist[i]);
		cout << dist[i] << '\n';
	}
	return;
}