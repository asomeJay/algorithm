/* ZOAC */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string s, result, temp;
stack<string> st;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
		
	cin >> s;
	st.push(s);

	while (!s.empty()) {
		result.clear();

		for (int i = 0; i != s.size(); i++) {
			temp = s;
			temp.erase(temp.begin() + i);

			if (result.empty()) {
				result = temp;
			}
			else if (result.compare(temp) > 0) {
				result = temp;
			}
		}
		st.push(result);
		s = result;
	}
	st.pop();

	while (!st.empty()) {
		cout << st.top() << '\n';
		st.pop();
	}
	return 0;
}