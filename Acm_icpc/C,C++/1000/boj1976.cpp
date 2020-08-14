/* 여행 가자 */

#include <iostream>
#include <queue>

using namespace std;

int n_of_city, n_of_travel;
bool edge[200 + 1][200 + 1];
int travel[1000 + 1];

void input();
void solve();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> n_of_city >> n_of_travel;
	for (int i = 1; i <= n_of_city; i++) {
		for (int j = 1; j <= n_of_city; j++) {
			cin >> edge[i][j];
		}
	}

	for (int i = 1; i <= n_of_city; i++) {
		edge[i][i] = true;
	}

	for (int i = 1; i <= n_of_travel; i++) {
		cin >> travel[i];
	}
}

void bfs(int idx) {
	queue<int> q;
	q.push(idx);
	bool is_visit[200 + 1] = { false, };
	is_visit[idx] = true;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 1; i <= n_of_city; i++) {
			if (edge[curr][i] == true && is_visit[i] == false) {
				edge[idx][i] = true;
				edge[i][idx] = true;

				is_visit[i] = true;

				q.push(i);
			}
		}
	}
}

void solve() {
	for (int i = 1; i <= n_of_city; i++) {
		bfs(i);
	}

/*	for (int i = 1; i <= n_of_city; i++) {
		for (int j = 1; j <= n_of_city; j++) {
			cout << edge[i][j] << ' ';
		}cout << endl;
	}*/

	for (int i = 1; i <= n_of_travel-1; i++) {
		if (edge[travel[i]][travel[i + 1]] == false) {
			cout << "NO" << '\n';
			return;
		}
	}

	cout << "YES\n";
	return;
}