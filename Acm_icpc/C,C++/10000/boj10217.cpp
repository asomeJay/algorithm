/* KCM Travel */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX_N 2100000000

#define pp pair<int,int>

class node {
public:
	int cost, time, dest;
	node(int dest, int cost, int time) {
		this->cost = cost;
		this->time = time;
		this->dest = dest;
	}
	node() { ; }
};

using namespace std;

void init();
void input();
void solve();

int N, M, K, Ans;
vector<node> airport[100 + 1];
int dist[100 + 1][10000 + 1]; 

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		init();
		input();	
		solve();
	}

	return 0;
}

void init() {
	Ans = MAX_N;

	for (int i = 0; i <= 100; i++) {
		airport[i].clear();
	}
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int u, v, c, d;
		cin >> u >> v >> c >> d;
		airport[u].push_back(node( v, c, d ));
	}
}

void dfs() {
	priority_queue<pair<int, pair<int, int>>> pq;

	pq.push({ 0,{0,1} });

	while (!pq.empty()) {
		int current_node = pq.top().second.second;
		int current_cost = pq.top().first * -1;
		int current_time = pq.top().second.first;
		pq.pop();

		if (dist[current_node][current_cost] < current_time)
			continue;
		for (auto i : airport[current_node]) {
			int nxtTime = current_time + i.time;
			int nxtCost = current_cost + i.cost;
			
			if (nxtCost > M) continue;

			if (dist[i.dest][nxtCost] > nxtTime) {
				for (int j = nxtCost; j <= M; j++) {
					
					dist[i.dest][j] = min(dist[i.dest][j], nxtTime);
				}
				pq.push({ -1 * nxtCost, {nxtTime, i.dest} });
			}
		}
	}
}
void solve() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			dist[i][j] = MAX_N;
		}
	}
	dist[1][0] = 0;

	dfs();
	
	for (int i = 1; i <= M; i++) {
		Ans = min(Ans, dist[N][i]);
	}
	if (Ans== MAX_N)
		cout << "Poor KCM" << '\n';
	else 
		cout << Ans << '\n';
}
