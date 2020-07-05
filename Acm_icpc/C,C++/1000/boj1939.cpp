#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define pp pair<int,int>

using namespace std;

bool dfs(int);

int N, M, fac1, fac2;
vector<pp> bridge[10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		bridge[a].push_back({ b,c });
		bridge[b].push_back({ a,c });
	}
	
	cin >> fac1 >> fac2;
	int l = 0, r = 1e9, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (dfs(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	
	cout << ans << '\n';

	return 0;
}

bool dfs(int limit) {
	stack<int> s;
	bool is_visit[10001] = { false };

	s.push(fac1);
	is_visit[fac1] = true;

	while (!s.empty()) {
		int cur = s.top(); s.pop();
		if (cur == fac2) 
			return true;
		
		for (auto i : bridge[cur]) {
			if (i.second < limit || is_visit[i.first]) continue;
			s.push(i.first);
			is_visit[i.first] = true;
		}
	}
	return false;
}