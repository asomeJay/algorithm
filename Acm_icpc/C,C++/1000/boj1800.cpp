#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
	
	for (int i = 1; i <= P; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a][b] = c;
		edge[b][a] = c;
	}
	int l = 0, r = 1e7, ans = -1;

	while (l < r) {
		int mid = (l + r) / 2;
		for (int i = 1; i <= N; i++) {
			is_visit[i] = false;
			weight[i] = 0;
			dist[i] = INF;	
		}

		bool stand = dijkstra(mid);
		if (stand) { 
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}

	cout << r << endl;
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
		
	dist[1] = 0;
	for (int i = 0; i < N; i++) {
		int current = getSmallest();
		if (current == -1) break;
		is_visit[current] = true;
		for (int j = 1; j <= N; j++) {
			if (edge[current][j] < dist[j] && !is_visit[j] ){
						//cout << "current : " << current << " edge : " << j << endl;
				dist[j] = edge[current][j];
				if (weight[j] == 0 || weight[j] > weight[current] + (edge[current][j] >= limit))
					weight[j] = weight[current] + (edge[current][j] > limit);
			}
		}
	}
	/*cout << limit << endl;
	for (int i = 0; i <= N; i++) {
		cout << weight[i] << " ";
	} cout << endl;*/
	
	return (weight[N] <= K);
}
