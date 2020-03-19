/* 팰린드롬 개수 구하기 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string s;
	cin >> s;
	int ss = s.size();

	for (int i = 0; i < ss; i++) {
		for (int j = i; j < ss; j++) {
			if (s[i] == s[j]) {
				dp[j]++;
				for (int k = j + 1; k < ss; k++) {
					dp[j] += dp[k];
					dp[j] %= 10007;
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < ss; i++) {
		cnt += dp[i];
		cnt %= 10007;
	}

	cout << cnt << '\n';

	return 0;
}