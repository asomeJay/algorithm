/* Cubeditor */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void input();
void solve();

int fail(string , vector<int> &);

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
}

// aabab
int fail(string p, vector<int> & failed) {
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
