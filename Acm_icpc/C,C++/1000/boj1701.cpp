/* Cubeditor */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void input();
void solve();

int fail(string , vector<int> &);
bool kmp(string, const vector<int> );

string s;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	solve();
	return 0;
}

void input() {
	cin >> s;
}

void solve() {

	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		string anti = s.substr(i);
		vector<int> failed(anti.length(), 0);
		res = max(res, fail(anti, failed));
	}

	cout << res << '\n';
	// length
	/*for (int i = s.length() / 2; i >=1; i--) {
		for (int j = 0; j <= s.length() - i * 2; j++) {
			string anti = s.substr(j, i);
			vector<int> failed(anti.length(), 0);

			fail(anti, failed);

			if (kmp(anti, failed)== true) {
				cout << i << '\n';
				return;
			}
		}
	}*/
}


// aabab
int  fail(string p, vector<int> & failed) {
	int j = 0, res = 0;
	for (int i = 1; i < p.length(); i++) {
		while (j > 0 && p[j] != p[i])
			j = failed[j-1];

		if (p[i] == p[j]) {
			failed[i] = ++j;
			res = max(res, j);
		}
	}
	return res;
}

bool kmp(string p, const vector<int> failed) {
	int j = 0, cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		while (j > 0 && s[i] != p[j])
			j = failed[j - 1];

		if (s[i] == p[j]) {
			if (j == p.length() - 1) {
				cnt++;
				if (cnt >= 2)
					return true;
				j = failed[j];
			}

			else
				j++;
		}
	}

	return false;
}

