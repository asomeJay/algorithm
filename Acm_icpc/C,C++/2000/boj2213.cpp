/* 트리의 독립집합 */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 10000 + 1
using namespace std;

void input();
void solve();

int N; 
int weight[MAX_N], dp[MAX_N][2];
vector<int> edge[MAX_N], result;
bool chk[MAX_N];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < MAX_N; i++) {
		dp[i][0] = dp[i][1] = -1;
	}

	input();
	solve();

	return 0;
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> weight[i];

	for (int i = 0; i < N-1; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
}

int dfs(int curr, int before, bool include){
	int& ret = dp[curr][include];
	if (ret != -1) 
		return ret;

	if (include) {
		ret = weight[curr];
		for (auto i : edge[curr]) {
			if (i == before) continue;

			// 현재 노드를 포함시켰으니 반드시 다음 노드는 포함시키지 않아야 한다.
			ret += dfs(i, curr, false);
		}
	}
	// 현재 노드를 포함하지 않는 경우
	else {
		ret = 0;
		for (auto i : edge[curr]) {
			if (i == before) continue;
			// 다음 노드를 포함하는 것과 포함하지 않는 것 중에서 더 큰 걸 골라야 한다.
			int r1 = dfs(i, curr, false);
			int r2 = dfs(i, curr, true);

			if (r1 < r2) {
				ret += r2;
				chk[i] = true;
			}
			else {
				ret += r1;
				chk[i] = false;
			}
		}
	}

	return ret;
}

void track(int now, int before, int include) {
	if (include == true) {
		result.push_back(now);
		for (auto i : edge[now]) {
			if (i == before) continue;
			track(i, now, 0);
		}
	}
	else {
		for (auto i : edge[now]) {
			if (i == before) continue;
			track(i, now, chk[i]);
		}
	}
}

void solve() {
	
	int r1 = dfs(1, 0, false);
	int r2 = dfs(1, 0, true);
	int rr = max(r1, r2);

	chk[1] = (r1 < r2 ? true : false);
	
	track(1, 0, chk[1]);
	sort(result.begin(), result.end());

	cout << rr << '\n';
	for (auto i:result) {
		cout << i << " ";
	}
}