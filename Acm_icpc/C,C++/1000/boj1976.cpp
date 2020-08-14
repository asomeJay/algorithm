/* 여행 가자 */

#include <iostream>
#include <queue>

using namespace std;

int n_of_city, n_of_travel;
bool edge[200 + 1][200 + 1];
int travel[1000 + 1];
int parent[200 + 1];

void input();

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void unions(int x, int y) {
	int px = find(x);
	int py = find(y);
	parent[px] = py;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();

	return 0;
}

void input() {
	cin >> n_of_city >> n_of_travel;

	for (int i = 1; i <= n_of_city; i++) {
		parent[i] = i;

		for (int j = 1; j <= n_of_city; j++) {
			cin >> edge[i][j];
			if (edge[i][j] == true) { // 연결한다. 
				unions(i, j);
			}
		}
	}

	cin >> travel[1];
	for (int i = 2; i <= n_of_travel; i++) {
		cin >> travel[i];
		if (parent[travel[i - 1]] != parent[travel[i]]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	return;
}
