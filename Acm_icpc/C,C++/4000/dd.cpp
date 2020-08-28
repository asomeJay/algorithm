#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void init();
void input();
void solve();

int x;
string s;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t_case; cin >> t_case;
	for (int i = 0; i < t_case; i++) {
		init();
		input();
		solve();
	}

	return 0;
}

void init() {
	s.clear();
	s = "a";
}

void input() {
	string t;

	cin >> t;
	s += t;

	cin >> x;
}

void solve() {
	string res;
	res.resize(s.length(), 'a');

	for (int i = 1; i < s.length(); i++) {
		if (x < i) {
			if (res[i - x] == 'a') {
				res[i - x] = s[i];
			}
			else {
				if (res[i - x] != s[i]) {
					cout << "-1\n";
					return;
				}
			}
		}

		else if (i <= s.length()-1 - x) {
			if (res[i + x] == 'a') {
				res[i + x] = s[i];
			}
			else {
				if (res[i + x] != s[i]) {
					cout << "-1\n";
					return;
				}
			}
		}
	}
	cout << res << '\n';
	return;
}
