#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 2100000000
#define VISIT 1
#define p pair<int,int>

using namespace std;

vector<p> edge[1001];
int dist[1001];
int N, P, K;

int getSmallest(); 
bool dijkstra(int limit); 

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> P >> K;
	for (int i = 1; i <= P; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}
	int l = 0, r = 1e7, ans = -1;

	while (l <= r) {
		int mid = (l + r) / 2;
		for (int i = 1; i <= N; i++) {
			dist[i] = INF;	
		}

		bool stand = dijkstra(mid);
		if (stand) { 
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans;
	return 0;
}

bool dijkstra(int limit) {
	priority_queue<p> pq; pq.push({ 0,1 });
	dist[1] = 0;
	
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = -1 * pq.top().first;
		pq.pop();

		if (dist[now] < cost) continue;
		for (auto i : edge[now]) {
			int nxt = i.first;
			int nxtcost = cost + (i.second > limit);
			if (nxtcost < dist[nxt]) {
				dist[nxt] = nxtcost;
				pq.push({ -nxtcost, nxt });
			}
		}
	}
	return dist[N] <= K;
}
