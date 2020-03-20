/* 팰린드롬 분할 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int ss, Ans = 987654321 ; 
bool dp[2501][2501];
int dps[2501];
int dfs(int, int);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string s;
	cin >> s;
	ss = s.size(); 

	dp[0][0] = true;
	for (int i = 0; i < ss; i++)
		dps[i] = 987654321;
	for (int i = 1; i < ss; i++) {
		dp[i][i] = true;
		if (s[i] == s[i - 1]) {
			dp[i - 1][i] = true;
		}
	}

	for (int i = 2; i < ss; i++) {
		for (int j = 0; j < ss - i; j++) {
			if (s[j] == s[j + i]) {
				if (dp[j+1][j + i - 1]) {
					dp[j][j + i] = true;
				}
			}
		}
	}

	int c = 987654321;
	for (int i = 0; i < ss; i++) {
		if (dp[0][i])
			c =  min(dfs(i + 1, 1), c);
	}

	cout << c << '\n';

	return 0;
}

int dfs(int index, int cnt) {
	if (index == ss) 		
		return 1;
	
	int& ret = dps[index];
	
	if (ret != 987654321) 
		return ret;
	

	for (int i = index; i < ss; i++) {
		if (dp[index][i]) {
			ret = min(ret, dfs(i + 1, cnt + 1) + 1);
		}
	}

	return ret;
}