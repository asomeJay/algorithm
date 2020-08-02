/* 게임 개발 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, in[500 + 1], time[500 + 1], precedence[500 + 1];
bool is_visit[500 + 1];
vector<int> building[500 + 1];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <=N; i++) {
		cin >> time[i];
		while (true) {
			int temp;
			cin >> temp;

			if (temp == -1) {
				break;
			}
			
			building[temp].push_back(i);
			in[i]++;
		}
	}

	priority_queue<pair<int,int>> history;
	for (int i = 1; i <= N; i++) {
		if (in[i] == 0) {
			is_visit[i] = true;
			history.push({ time[i], i });
		}
	}
	
	while (!history.empty()) {	
		int current_building = history.top().second;
		int current_time = history.top().first;
		history.pop();

		for (auto i : building[current_building]) {
			if (is_visit[i]) continue;
			precedence[i] = max(precedence[i], current_time);
			in[i]--;
			if (in[i] == 0){
				is_visit[i] = true;
				time[i] += precedence[i];
				history.push({ time[i], i });
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << time[i] << '\n';
	}
	return 0;
}