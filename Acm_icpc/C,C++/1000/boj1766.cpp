/* 문제집 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
bool is_desc[32001], is_used[32001];
vector<int> connection[32001];
priority_queue<int, vector<int>, greater<int>> now_ancestor;

void parent_child(int par, int chi);
void who_ancestor();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >>  M;

	int par, child;
	for (int i = 1; i <= M; i++) {
		cin >> par >> child;
		parent_child(par, child);
	}

	who_ancestor(); // 제일 위에 가장 값이 낮은 ancestor가 들어있다. 

	while (!now_ancestor.empty()) {
		int now =  now_ancestor.top();
		if (is_used[now])
			continue;
		is_used[now] = true;

		cout << now << " ";

		now_ancestor.pop();

		for (auto n : connection[now]) {
			if (is_used[n]) continue;
			now_ancestor.push(n);
		}
	}

	return 0;
}

void parent_child(int par, int chi) {
	is_desc[chi] = true;
	connection[par].push_back(chi);

	return;
}

void who_ancestor() {
	for (int i = 1; i <= N; i++) {
		if (is_desc[i] == false) {
			now_ancestor.push(i);
		}
	}
	return;
}