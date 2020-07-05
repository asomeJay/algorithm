#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int start = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int a; cin >> a;
			if (a == 0) {
				a = 9;
			}

			start = start * 10 + a;
		}
	}

	map<int, int> dist;
	dist[start] = 0;

	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int now = q.front(); q.pop();
		string now_string = to_string(now);
	
		int pos = now_string.find('9');
		int r = pos / 3;
		int c = pos % 3;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nr < 3 && nc >= 0 && nc < 3) {
				string next_string = now_string;
				swap(next_string[r * 3 + c], next_string[nr * 3 + nc]);
				if (dist.count(stoi(next_string)) == 0) {
					dist[stoi(next_string)] = dist[now] + 1;
					q.push(stoi(next_string));
				}
			}
		}
	}

	if (dist.count(123456789) == 0) {
		cout << -1 << '\n';
	}
	else {
		cout << dist[123456789] << '\n';
	}

	return 0;
}
