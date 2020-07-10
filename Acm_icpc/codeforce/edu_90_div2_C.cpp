#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t_case; cin >> t_case;
	for (int i = 0; i < t_case; i++) {
		int res = 0, init = 1;
		string s; cin >> s;

		while (init) {
			int cur = init - 1;
			bool ok = true;
			for (int j = 0; j < s.size(); j++) {
				res++;
				if (s[j] == '+')
					cur++;
				else
					cur--;
				if (cur < 0) {
					ok = false;
					break;
				}
			}

			if (ok == true) {
				break;
			}
			init++;
		}
		cout << res << '\n';
	}
	return 0;
}