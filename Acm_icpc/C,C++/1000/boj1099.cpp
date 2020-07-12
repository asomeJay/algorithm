/* 1099 알 수 없는 문장*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define INT_MAX 1000000000
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

	main_str.push_back('0');
	string t; cin >> t; main_str += t;

	cin >> N;

	dp.resize(main_str.size() + 1, 0);

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		words[temp.size()].push_back(temp);
	}

	solve();
	int ANS = ((dp[main_str.size() - 1] == INT_MAX / 2) ? -1 : dp[main_str.size() - 1]);
	cout << ANS;

	return 0;
}

void solve() {

	for (int i = 1; i < main_str.length(); i++) {
		// Determine DP		
		// DP[i] = DP[i-1] + S[1] ...
		int mini = INT_MAX / 2;
//		cout << i << endl;
		for (int j = 0; j < i; j++){ 
			mini = min(mini, dp[j] + cost(j+1, i - j));
		}
		dp[i] = mini;
	}
}

int cost(int start_idx, int range) {
//	cout << start_idx << " " << range << endl;
	int answer = INT_MAX/2, idx, j;

	for (auto word : words[range]) { // word를 받음
		int dif = 0;
		string temp = word; // 얘는 지울거라 복사함 
		//cout << word << endl;
		for (j = start_idx; j < start_idx + range; j++) {
			if ((idx = temp.find(main_str[j])) == string::npos) {
				break;
			}
			else {
				// 순서로 Cost를 써야하는뎅 
				// 좋아 간드아~~
				temp[idx] = '0';
			}
		}

		if (j == start_idx + range) { // 매칭되는 애가 있음 이제 그 비용을 구해야지
			for (int k = 0; k < word.size(); k++) {
				if (word[k] != main_str[start_idx + k]) {
					dif++;
				}
			}
			answer = min(dif, answer);
		}	
	}
	
	return answer;
}