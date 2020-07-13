/* 파일 합치기 */

#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 0x3f3f3f3f

using namespace std;

int dp[501][501];
int cost[501], sum[501];
int n_of_number, ANS;

void init();
int dfs(int, int);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t_case; cin >> t_case;

	for (int i = 0; i < t_case; i++) {

		int a; cin >> a;
		init();

		for (int j = 1; j <= a; j++) {
			cin >> cost[j];
			sum[j] = sum[j - 1] + cost[j];
		}
		
		cout << dfs(1, a) << '\n';

	}
	return 0;
}

void init() {
	for (int i = 0; i < 501; i++) {
		cost[i] = sum[i] = 0;
		for (int j = 0; j < 501; j++) {
			dp[i][j] = MAX;
		}
	}
}

int dfs(int x, int y) {
	if (dp[x][y] != MAX) {
		return dp[x][y];
	}
	if (x == y) {
		return dp[x][y] = 0;
	}
	if (y == x + 1) {
		return dp[x][y] = cost[x] + cost[y];
	}

	for (int mid = x; mid <= y; mid++) {
		int left = dfs(x, mid);
		int right = dfs(mid + 1, y);
		dp[x][y] = min(dp[x][y], left + right);
	}
	
	return dp[x][y] += sum[y] - sum[x - 1];
}
