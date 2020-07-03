#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2100000000
#define VISIT 1

using namespace std;

int edge[1001][1001];
int dist[1001];
int weight[1001];
bool is_visit[1001];
int N, P, K;

int getSmallest(); 
bool dijkstra(int limit); 

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> P >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			edge[i][j] = INF;
		} 
	}
	
	for (int i = 1; i <= N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a][b] = c;
		edge[b][a] = c;
	}

	int l = 0, r = 1000000000;

	while (l < r) {
		int mid = (l + r) / 2;
		for (int i = 1; i <= N; i++) 
			dist[i] = INF;	

		bool stand = dijkstra(mid);
		if (stand) { 
			l++;
		}
		else {
			r--;
		}
	}

	cout << l << endl;
	return 0;
}

int getSmallest() {
	int min = INF;
	int index = -1;

	for (int i = 1; i <= N; i++) {
		if (dist[i] < min && !is_visit[i]) {
			min = dist[i];
			index = i;
		}
	}

	return index;
}

bool dijkstra(int limit) {
	for (int i = 1; i <= N; i++) {
		dist[i] = edge[1][i];
	}
	is_visit[1] = true;
	
	for (int i = 0; i < N - 2; i++) {
		int current = getSmallest();
		is_visit[current] = true;
		for (int j = 1; j <= N; i++) {
			if (dist[current] + edge[current][j] < dist[j]) {
				dist[j] = dist[current] + edge[current][j];
				weight[j] = dist[j] - dist[current];
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (weight[i] >= limit)
			cnt++;
	}

	cout << "Cnt : " << cnt << endl;
	return (cnt <= K);
}
