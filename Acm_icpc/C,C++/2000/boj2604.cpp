/* IP аж╪р */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
vector<vector<string>>token;
unsigned char dp[1000][4];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	string IP, T;
	token.resize(N);
	
	for (int i = 0; i < N; i++) {
		cin >> IP;

		for (int j = 0; j < (int)IP.size(); j++) {
			while (IP[j] != '.' && j < (int)IP.size()) {
				T.push_back(IP[j++]);
			}
			token[i].push_back(T);
			T.clear();
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			unsigned int int_ip = (unsigned int)stoi(token[i][j]);
			while (int_ip != 0) {
				dp[i][j] = dp[i][j] << 1;
				dp[i] |= (int_ip % 2);
				int_ip / 2;
			}

		}
	}

	return 0;
}

/*
for (int i = 0; i < N; i++) {
	for (int j = 0; j < token[i].size(); j++) {
		cout << token[i][j] << " ";
	}
	cout << endl;
}
*/