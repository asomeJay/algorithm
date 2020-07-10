#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t_case; cin >> t_case;

	for (int i = 0; i < t_case; i++) {
		int cnt = 0;
		string tkn; cin >> tkn;

		for (int j = 1; j < tkn.size(); j++) {
			if (tkn[j] != tkn[j - 1]) {
				tkn.erase(tkn.begin() + j);
				tkn.erase(tkn.begin() + j - 1);
				j = 0;
				cnt++;
			}
		}
			
		cout << (cnt % 2 == 1 ? "DA" : "NET") << '\n';
	}
		
	return 0;
}