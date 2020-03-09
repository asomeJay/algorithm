/* Four Squares */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int limit = 224;
int dp[226];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, mini = 9876654321;
	cin >> N;

	for (int i = 1; i < limit; i++) {
		dp[i] = i * i;
		if (dp[i] > N) break;
		if (dp[i] == N) {
			cout << 1;
			return 0;
		}
	}

	for (int i = 1; i < limit; i++) {
		for (int j = i; j < limit; j++) {
			if (dp[i] + dp[j] > N) 
				break;
			if (dp[i] + dp[j] == N) {
				mini = min(mini, 2);
			}
			for (int k = j; k < limit; k++) {
				if (dp[i] + dp[j] + dp[k] > N) 
					break;

				if (dp[i] + dp[j] + dp[k] == N) {
					mini = min(mini, 3);
				}

				for (int m = k; m < limit; m++) {
					if (dp[i] + dp[j] + dp[k] + dp[m] > N)
						break;
					if (dp[i] + dp[j] + dp[k] + dp[m] == N) {
						mini = min(mini, 4);
					}
				}
			}
		}
	}

	cout << mini;

	return 0;
}