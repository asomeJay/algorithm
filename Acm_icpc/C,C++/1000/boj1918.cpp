/* 후위 표기식 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s,res; cin >> s;
	
	stack<char> st;

	for (int i = 0; i < s.size(); i++) {
		
		if (s[i] >= 'A' && s[i] <= 'Z') {
			res += s[i];
		}
		else { // 스택 밑에 깔릴 수록 나중에연산되는 애임
			switch (s[i]) {
			case '*': 
			case '/': 
				while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
					res += st.top();
					st.pop();
				}
				st.push(s[i]);
				break;

			case '+':
			case '-':
				while (!st.empty() && !(st.top() == '(')) {
					res += st.top();
					st.pop();
				}
				st.push(s[i]);
				break;
			case ')':
				while (!(st.top() == '(')) {
					res += st.top();
					st.pop();
				}
				st.pop();
				break;

			case '(':
				st.push('(');
				break;
			}
		}
	}

	while (!st.empty()) {
		res += st.top();
		st.pop();
	}

	cout << res << '\n';

	return 0;
}