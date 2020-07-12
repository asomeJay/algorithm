/* 1099 알 수 없는 문장*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string main_str;
int N;
vector<string> words[51];
vector<int> dp;

void solve();
int cost(int, int);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> main_str >> N;
	dp.resize(N);

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		words[temp.size()].push_back(temp);
	}

	solve();
	cout << dp[N] << '\n';

	return 0;
}

void solve() {

	for (int i = 1; i <= N; i++) {
		// Determine DP		

		int mini = 0;
		for (int j = 1; j <= i; j++) {
			mini = min(mini, dp[i - j] + cost(j, i-j));
		}
	}
}

int cost(int idx) {
		
}