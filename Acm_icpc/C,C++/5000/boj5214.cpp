/* È¯½Â */

#include <iostream>
#include <vector>
#include <queue>

#define MAX 100000 + 1

using namespace std;

int N, K, M;
vector<int> edge[MAX], dummy[1000 + 1];
int time[MAX];

void input();
void solve();


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input(); solve();

	return 0;
}

void input() {
	cin >> N >> K >> M;

	for (int i = 0; i < M; i++) {
		int a;
	
		for (int j = 0; j < K; j++) {
			cin >> a;
			dummy[i].push_back(a);
			edge[a].push_back(i);
		}
	}
}


void solve() {
	queue<int> q;
	bool visitied[MAX] = { false , };
	bool dummy_visit[MAX] = { false, };
	int k;
	
	q.push(1);
	time[1] = k = 1;
	visitied[1] = true;

	while (!q.empty()) {
		k++;
		int edge_queue = q.size();

		while (edge_queue--) {
			int current = q.front();
			q.pop();
			for(int i = 0; i < edge[current].size(); i++){
				int cc = edge[current][i];
				if (dummy_visit[cc] == false) {
					dummy_visit[cc] = true;
					q.push(cc);
				}
			}
		}

		int q_size = q.size();
		
		while (q_size--) {
			int current = q.front();
			q.pop();

			for (auto i : dummy[current]) {
				if (time[i] == 0) {
					time[i] = k;
					q.push(i);
				}
			}
		}
	}
	if (time[N] == 0)
		time[N] = -1;
	cout << time[N] << '\n';

}