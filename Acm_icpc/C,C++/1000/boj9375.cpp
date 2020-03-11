/* ÆÐ¼Ç¿Õ ½ÅÇØºó */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t_case, k;
	cin >> t_case;

	for (int i = 0; i < t_case; i++) {
		int tt_case, kind_index = 0;
		vector<pair<string, int>>kind;

		cin >> tt_case;
		for (int j = 0; j < tt_case; j++) {
			int size = (int)kind.size();
			string name, tkind;
			cin >> name >> tkind;
			for (k = 0; k < size; k++) {
				if (kind[k].first.compare(tkind) == 0) {
					kind[k].second++;
					break;
				}
			}
			if (k == size) 
				kind.push_back({ tkind, 1 });
		}

		int sum, mul;
		if (kind.size() == 1) {
			mul = kind[0].second + 1;
		}
		else {
			mul = 1, sum = 0;
			for (int i = 0; i < kind.size(); i++) {
				mul *= (kind[i].second + 1);
			}
		}
		cout << mul - 1<< '\n';
	}
	return 0;
}