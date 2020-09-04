/* 가장 긴 팰린드롬 부분 문자열 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> vc;
string s;

void input();
void solve();
void manacher();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input(); solve();

	return 0;
}

void manacher() {
	int p = 0, r = 0;
	for (int i = 0; i < N; i++) {
		if (i <= r) {
			vc[i] = min(r - i, vc[2 * p - i]);
		}
		else{
			vc[i] = 0;
		}

		while (i - vc[i] - 1 >= 0 && i + vc[i] + 1 < N && s[i - vc[i] - 1] == s[i + vc[i] + 1]) {
			vc[i]++;
		}

		if (r < i + vc[i]) {
			r = i + vc[i];
			p = i;
		}
	}
}

void input() {
	string t;  cin >> t;
	for (int i = 0; i < t.size(); i++) {
		s += "#";
		s += t[i];
	}
	s += "#";
	N = s.length();

	vc.resize(N);
}

void solve() {
	manacher();
	int maxi = -1;
	for (int i = 0; i < vc.size(); i++) {
		maxi = max(maxi, vc[i]);
	}
	cout << maxi;
}