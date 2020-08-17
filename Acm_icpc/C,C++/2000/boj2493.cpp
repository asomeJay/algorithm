#pragma once
/* ž */

#include <iostream>

#define MAX_HEIGHT 500000 + 1

using namespace std;

int N;
int dp[MAX_HEIGHT], height[MAX_HEIGHT];

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
	cin >> N;
	cin >> height[1];
	dp[0] = -1;
	dp[1] = 0;

	for (int i = 2; i <= N; i++) {
		cin >> height[i];

		if (height[i - 1] >= height[i]) {
			dp[i] = i - 1;
		}
		else {
			int idx = i - 1;
			while (dp[idx] != -1 && height[dp[idx]] < height[i]) {
				idx = dp[idx];
			}

			if (dp[idx] != -1) {
				dp[i] = dp[idx];
			}
		}
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		cout << dp[i] << " ";
	}
}
