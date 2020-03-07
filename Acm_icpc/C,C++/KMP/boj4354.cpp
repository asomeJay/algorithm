/* 문자열 제곱 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int>pi;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int i, j, ans, s_size, prefix, suffix;
	while (1) {
		string s;
		cin >> s;
		s_size = (int)s.size();

		if (s.find('.') != string::npos) break;
		pi.clear();
		pi.resize(s_size, 0);

		for (i = 1, j = 0; i < s_size; i++) {
			while (j != 0 && s[i] != s[j])
				j = pi[j - 1];
			if (s[i] == s[j])
				pi[i] = ++j;
		}

		for (prefix = 0; prefix < s_size && pi[prefix] == 0; prefix++);
		suffix = pi[s_size - 1];

		if (suffix == 0 || (suffix % prefix != 0))
			ans = 1;
		else
			ans = (s_size / (s_size - suffix));

		cout << ans << '\n';
	}

	return 0;
}