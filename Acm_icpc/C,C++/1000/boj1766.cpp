/* 문제집 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, ancestor_of_[32001];
bool is_used[32001];
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
		now_ancestor.pop();

		cout << now << " ";

		for (auto n : connection[now]) {
			if (!ancestor_of_[n]) 
				continue;
			ancestor_of_[n]--;

			if(!ancestor_of_[n])
				now_ancestor.push(n);
		}
	}

	return 0;
}

void parent_child(int par, int child) {
	ancestor_of_[child]++;
	connection[par].push_back(child);

	return;
}

void who_ancestor() {
	for (int i = 1; i <= N; i++) {
		if (ancestor_of_[i] == 0) {
			now_ancestor.push(i);
		}
	}

	return;
}