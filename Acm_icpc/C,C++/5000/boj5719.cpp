/* 거의 최단 경로 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>

#define pp pair<int,int>
#define INTMAX 2100000000

using namespace std;

void init();
void input();
void solve();

int N, M, S, D, cur_maxi; 
vector<pp> edge[501];
vector<int> trace[501];
int dist[501];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true) {
		init();
		input();
		solve();
	}
	return 0;
}

void init() {
	for (int i = 0; i <= 500; i++) {
		edge[i].clear();
		trace[i].clear();
	}
}

void input() {
	cin >> N >> M;
	if (N == 0 && M == 0) {
		exit(0);
	}

	cin >> S >> D;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		
		edge[a].push_back({ b,c });
	}
}

void dijkstra() {

	for (int i = 0; i <= 500; i++) {
		dist[i] = INTMAX;
	}
	dist[S] = 0;
	priority_queue<pp> pq;

	pq.push({ 0, S });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		
		pq.pop();

		if (cost > dist[node])
			continue;

		for (int i = 0; i < edge[node].size(); i++) {
			int nxtNode = edge[node][i].first;
			int nxtCost = edge[node][i].second + cost;

			if (edge[node][i].second == -1)
				continue;

			if (nxtCost < dist[nxtNode]) {
				dist[nxtNode] = nxtCost;
				pq.push({ -nxtCost, nxtNode });

				trace[nxtNode].clear();
				trace[nxtNode].push_back(node);
			}

			else if (nxtCost == dist[nxtNode]) {
				trace[nxtNode].push_back(node);
			}
		}
	}

}

void cutting(int after) {
	queue<int> q;
	bool is_visit[501] = { false, };
	is_visit[after] = true;
	q.push(after);
	while (!q.empty()) {
		int node = q.front();
		q.pop();		

		for (int i = 0; i < trace[node].size(); i++) {
			int beforeNode = trace[node][i];
			for (int j = 0; j < edge[beforeNode].size(); j++){
			
				if (edge[beforeNode][j].first == node) {
					edge[beforeNode][j].second = -1;
					break;
				}
			}

			q.push(beforeNode);
		}
	}
}

void solve() {
	dijkstra();
	cutting(D);
	dijkstra();
	if (dist[D] == INTMAX)
	{
		dist[D] = -1;
	}
	cout << dist[D] << '\n';

}