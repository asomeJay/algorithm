/* º¸¼® µµµÏ */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
vector<pair<int, int>> jewelry;
vector<int> backpack;

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
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		jewelry.push_back({ a,b });
	}

	for (int i = 0; i < K; i++) {
		int a; cin >> a;
		backpack.push_back(a);
	}
}

void solve() {
	sort(jewelry.begin(), jewelry.end());
	sort(backpack.begin(), backpack.end());

	priority_queue<int> pq;
	long long int result = 0;
	for (int i = 0, j = 0; i < K; i++) {
		while (j < N && jewelry[j].first <= backpack[i]) {
			pq.push(jewelry[j++].second);
		}

		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}

	cout << result << '\n';
}