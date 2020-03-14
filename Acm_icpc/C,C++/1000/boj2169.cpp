/* 로봇 조종하기 */

#include <iostream>
#include <algorithm>
#include <queue>

#define ll long long int
#define MAX 1000 + 1
#define VISIT 1
#define W 3
#define E 1
#define DOWN 0
#define LEFT 1
#define RIGHT 2
using namespace std;

int N, M, Ans = -987654231;
bool visited[MAX][MAX];
ll map[MAX][MAX], dp[3][MAX][MAX];

const int dr[4] = { 0,1,0 };
const int dc[4] = { 1,0,-1 };

inline bool is_range(int r, int c) {
	return r >= 1 && r <= N && c >= 1 && c <= M;
}

ll dfs(int,int,int );
void input();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();

	cout << dfs(1, 1, 0);

	return 0;
}


ll dfs(int r, int c, int from) {
	if (r == N && c == M) {
		return map[N][M];
	}

	ll& result = dp[from][r][c];
	if (result != -987654321) 
		return result;
	
	visited[r][c] = true;

	ll temp = -987654321;
	
	for (int i = 0; i < 3; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!is_range(nr, nc) || visited[nr][nc]) continue;
		temp = max(dfs(nr, nc, i), temp); 
	}
	visited[r][c] = false;

	return result = temp + map[r][c];
}

void input() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = -987654321;
		}
	}
}



/*
cout << endl;
for (int i = 1; i <= N; i++) {
	for (int j = 1; j <= M; j++) {
		cout << dp[i][j] << " ";
	}
	cout << endl;
}
cout << endl;*/