#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0, 1, 0, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int start = 0;
	for (int i = 0; i < 9; i++) {
		int a; cin >> a;
		if (a == 0) a = 9;
		start = start * 10 + a;
	}

	map<string, int> dist;
	queue<int> bfs;

	bfs.push(start);
	dist[to_string(start)] = 0;

	while (!bfs.empty()) {
		int now = bfs.front(); bfs.pop();
		
		string now_str = to_string(now);
		int distance = now_str.find('9');
		int r = distance / 3; int c = distance % 3;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			
			if (nr >= 0 && nr < 3 && nc >= 0 && nc < 3) {
				string next_string = now_str;
				swap(next_string[nr * 3 + nc], next_string[r * 3 + c]);
				if (dist.count(next_string) == 0) {
					dist[next_string] = dist[now_str] + 1;
					bfs.push(stoi(next_string));
				}
			}
		}
	}

	if (dist.count("123456789") == 0) {
		cout << -1 << '\n';
	}
	else {
		cout << dist["123456789"] << '\n';
	}

	return 0;
}