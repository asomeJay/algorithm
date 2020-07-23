/* Çà·Ä °ö¼À ¼ø¼­ */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500 + 1
#define IMAX 2100000000 // IMAX º¸°í½Í´Ù

using namespace std;

void input();
void solve();

long long int N, ANS;
pair<int, int> matrix[MAX];
int dp[MAX][MAX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		matrix[i].first = a;
		matrix[i].second = b;
	}
}

int recur(int x, int y) {
	if (x == y) return 0;

	int& ret = dp[x][y];
	if (ret != 0) return ret;

	ret = INT_MAX;
	for (int i = x; i < y; i++) {
		ret = min(ret, recur(x, i) + recur(i + 1, y) + matrix[x].first * matrix[i].second * matrix[y].second);
	}
	return ret;
}

void solve() {
	cout << recur(0, N - 1) << '\n';
}
