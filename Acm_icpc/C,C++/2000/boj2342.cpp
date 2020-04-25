/* 2342 : Dance Dance Revolution */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX 100000

using namespace std;

int depth, dp[5][5][100000];

vector<int> input;

int dfs(int, int, int);
int price(int now, int will);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int in;

	while (1) {
		cin >> in;
		if (in == 0)
			break;
		input.push_back(in);
	}

	depth = (int)input.size();

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 0, 0) << '\n';
	
	return 0;
}

int dfs(int _left, int _right, int dep) {
	if (dep == depth) return 0;
	if (dp[_left][_right][dep] != -1) return dp[_left][_right][dep];

	int left = price(_left, input[dep]) + dfs(input[dep], _right, dep + 1);
	int right = price(_right, input[dep]) + dfs(_left, input[dep], dep + 1);

	return dp[_left][_right][dep] = min(left, right);
}

int price(int now, int will) {
	if (now == will)
		return 1;
	else if (now == 0)
		return 2;
	else if (abs(now - will) == 2)
		return 4;
	else 
		return 3;
}