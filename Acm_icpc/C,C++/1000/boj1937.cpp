/* 판다 */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500 + 1

using namespace std;

int forest[MAX][MAX], dr[4] = { -1,0,1,0 }, dc[4] = { 0,1,0,-1 };
int dp[MAX][MAX];
int N, ANS;

int dfs(int r, int c);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; (cin >> forest[i][j++]));	

	int maxi = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			maxi = max(maxi, dfs(i, j));
		}
	}
	cout << maxi;
	return 0;

}

bool is_range(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < N;
}

// 이제 dfs를 할 것이다.
int dfs(int r, int c){
	int& ret = dp[r][c];
	if (ret != 0)
		return ret;

	ret = 1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		
		if (is_range(nr, nc) == true && forest[r][c] < forest[nr][nc]) {
			ret = max(ret, dfs(nr, nc) + 1);
		}
	}

	return ret;
}