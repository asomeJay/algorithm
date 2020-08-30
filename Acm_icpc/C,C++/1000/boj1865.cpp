/* ¿úÈ¦ */

#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
#include <cstring>
#include <queue>

#define ll long long int
#define pp pair<ll, ll>
#define INTMAX 2100000000

using namespace std;

void init();
void input();
void solve();

struct edgeNode {
	int src, des, weight;
	edgeNode(int a, int b, int c) {
		src = a;
		des = b;
		weight = c;
	}
};

int N, M, W;
int dist[505];
vector<edgeNode> edge;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tt; cin >> tt;
	for (int i = 0; i < tt; i++) {
		init();
		input();
		solve();
	}
	return 0;
}

void init() {
	edge.clear();
}

void input() {
	cin >> N >> M >> W;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge.push_back(edgeNode(a, b, c));
		edge.push_back(edgeNode(b, a, c));
	}

	for (int i = 0; i < W; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge.push_back(edgeNode(a, b, -c));
	}
}

bool bellman_ford(int src) {
	fill(&dist[0], &dist[505], 0);
	dist[src] = 0;

	for (int i = 1; i <= N - 1; i++) {
		for (auto node : edge) {
			if (dist[node.des] > dist[node.src] + node.weight) {
				dist[node.des] = dist[node.src] + node.weight;
			}
		}
	}

	for (auto node : edge) {
		if (dist[node.des] > dist[node.src] + node.weight) {
			return true;
		}
	}
	
	return false;
}

void solve() {
	if (bellman_ford(1) == true) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
	return;
}