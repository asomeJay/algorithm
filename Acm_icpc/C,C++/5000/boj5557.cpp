/* 1ÇÐ³â */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define ll long long int

using namespace std;

void input();
void solve();

int N;
ll dp[101][21];
vector<int> arr;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input(); solve();
	return 0;
}

void input() {
	cin >> N;
	arr.resize(N);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++)
		cin >> arr[i];
}

ll b_t(int idx, ll summation) {
	if (summation > 20 || summation < 0)
		return 0;

	if (idx == N - 1) {
		if (summation == arr[idx])
			return 1;
		return 0;
	}

	ll& res = dp[idx][summation];
	if (res != -1) {
		return res;
	}

	return res = b_t(idx + 1, summation + arr[idx]) + b_t(idx + 1, summation - arr[idx]);
}

void solve() {
	cout << b_t(0, 0) << '\n';
	return;
}