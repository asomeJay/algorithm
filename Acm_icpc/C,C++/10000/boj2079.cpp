/* ÆÓ¸°µå·Ò */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define S 2500

using namespace std;

int cnt = S;
int s_string;
bool dp[2001][2001];
int dp_cnt[S][S];

int dfs(int depth, int index, int before);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;
	s.push_back(0);
	s_string = (int)s.size();

	for (int i = 0; i < s_string; i++) {
		for (int j = 0; j < s_string; j++) {
			dp_cnt[i][j] = S;
		}
		dp[i][i] = true;
		if (s[i] == s[i + 1])
			dp[i][i + 1] = true;
	}

	for (int i = 1; i <= s_string - 1; i++) {
		for (int j = 0; j < s_string - i; j++) {
			if (s[j] == s[j + i]) {
				if (dp[j + 1][j + i - 1]) {
					dp[j][j + i] = true;
				}
			}
		}
	}

	for (int i = 0; i < s_string; i++) {
		if(dp[0][i])
			dp_cnt[0][0] = min(dfs(1, i + 1, 0), dp_cnt[0][0]);
	}
	cout << dp_cnt[0][0]<< '\n';

	
	return 0;
}

int dfs(int depth, int index, int before) {
	if (index == s_string) {
		cnt = min(cnt, depth);
		return 0;
	}
	if (dp_cnt[before][index] != S) 
		return dp_cnt[before][index];
	
	for (int i = index; i < s_string; i++) {
		if (dp[index][i]) {
			dp_cnt[before][index] = min(dp_cnt[before][index], dfs(depth + 1, i + 1, index));
		}
	}		
	dp_cnt[before][index] += 1;
	return dp_cnt[before][index];
}