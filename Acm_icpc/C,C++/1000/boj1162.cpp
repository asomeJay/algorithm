/* 도로포장 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define INF 2100000000
#define ll long long int

struct node {
public:
	ll num, cost, cnt;
	
	node(ll num, ll cost, ll cnt) {
		this->num = num; 
		this->cost = cost; 
		this->cnt = cnt;
	}
	bool operator < (const node n) const {
		return n.cost < cost;
	}
};

using namespace std;

int N, M, K;
ll dist[10001][21];
vector<pair<int,int>> edge[10000 + 1];

void input();
void solve();
void dijkstra(int src);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

void dijkstra(int src) {
	priority_queue<node>  pq;

	pq.push({ src, 0, 0 });

	while (!pq.empty()) {

		ll cst = pq.top().cost;
		ll num = pq.top().num;
		ll cnt = pq.top().cnt;
		pq.pop();

		if (cst > dist[num][cnt]) continue;

		for (auto conn_node : edge[num]) {
			ll nxt_node = conn_node.first;
			ll nxt_cost = conn_node.second + cst;

			if (nxt_cost < dist[nxt_node][cnt]) {
				dist[nxt_node][cnt] = nxt_cost;
				pq.push({ nxt_node, nxt_cost, cnt });
			}

			if (cnt < K && cst < dist[nxt_node][cnt+1]) {
				dist[nxt_node][cnt + 1] = cst;
				pq.push({ nxt_node, cst, cnt + 1 });
			}
		}
	}
}

void input() {
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}
}

void solve() {
	memset(dist, 0x7F, sizeof(dist));
	// K개 만큼 포장을 할 수 있다.
	dist[1][0] = 0;
	dijkstra(1);
	ll maxi = 1e18;
	for (int i = 0; i <= K; i++) {
		maxi = min(maxi, dist[N][i]);
	}
	cout << maxi << '\n';
}
