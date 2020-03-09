/*µË∫∏¿‚*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> no_hear;
vector<string> no_see;
vector<string> ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b;
	cin >> a >> b;
	string s;

	for (int i = 0; i < a; i++) {
		cin >> s;
		no_hear.push_back(s);
	}
	for (int i = 0; i < b; i++) {
		cin >> s;
		no_see.push_back(s);
	}
	sort(no_hear.begin(), no_hear.end());
	sort(no_see.begin(), no_see.end());

	int i = 0, j = 0;
	while (i < a && j < b) {
		int temp = no_hear[i].compare(no_see[j]);
		if (temp == 0) {
			ans.push_back(no_hear[i]);
			i++; j++;
		}
		else if (temp > 0) {
			j++;
		}
		else {
			i++;
		}
	}

	cout << (int)ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}