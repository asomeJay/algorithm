/* 우수 마을 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input();
void solve();

int N, weight[10000 + 1], Ans;
int treeDp[10000 + 1][2];

vector<int> house[10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	input();
	solve();

	return 0;
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> weight[i];

	for (int i = 1; i < N; i++) {
		int a, b; cin >> a >> b;

		house[a].push_back(b);
		house[b].push_back(a);
	}
}

int recur( int curr, bool include, int before) {
	int& ret = treeDp[curr][include];

	if (ret != 0) {
		return ret;
	}

	int summation = 0;
	// 현재 마을은 우수 마을이다.
	if (include) {
		summation += weight[curr];

		for (auto nxt_node : house[curr]) {
			if (nxt_node == before) continue;
			summation += recur( nxt_node, false, curr);
		}
	}
	
	// 현재 마을은 우수 마을이 아니다.
	else {
		for (auto nxt_node : house[curr]) {
			if (nxt_node == before) continue;

			summation += max(recur(nxt_node, true, curr), recur(nxt_node, false, curr));
		}
	}

	return ret = summation;
}

 void solve() { 
	 Ans = max(recur(1, true, -1), recur(1, false, -1));

	 cout << Ans << '\n';
}

