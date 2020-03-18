/* 팰린드롬 개수 구하기 */

#include <iostream>
#include <string>

using namespace std;

bool p[1001][1001];
int dp[1001][1001];
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string s;
	cin >> s;
	int ss = s.size();

	p[0][0] = true;
	for (int i = 1; i < ss; i++) {
		p[i][i] = true;
		if (s[i - 1] == s[i])
			p[i - 1][i] = true;
	}

	for (int i = 2; i < ss; i++) {
		for (int j = 0; j < ss - i; j++) {
			if (s[j] == s[j + i]) {
				if (p[j + 1][j + i - 1]) {
					p[j][j + i] = true;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < ss; i++) {
		for (int j = 0; j <= i; j++) {
			if (s[j] == s[i]) {
				cnt++;
				for (int k = j + 1; k <= i - 1; k++) {
					for (int m = k; m <= i - 1; m++) {
						if (p[k][m]) {
							cnt++;
							cnt %= 10007;
						}
					}
				}
			}
		}
	}

	cout << cnt % 10007 << '\n';

	return 0;
}