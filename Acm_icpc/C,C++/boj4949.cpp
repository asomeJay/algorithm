/* ±ÕÇüÀâÈù ¼¼»ó */

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

bool char_comp(char, char t);
stack<char> brace;
char c, t;

int main(void) {
	int cnt = 1, flag;

	while (1) {
		cnt = 0;
		flag = 1;

		while ((c = getchar()) != '.') {
			cnt++;
			if (c == '(' || c == '[')
				brace.push(c);

			if (!char_comp(')', '(') || !char_comp(']', '['))
				flag = 0;
		}

		while (!brace.empty()) {
			flag = 0;
			brace.pop();
		}

		getchar();

		if (cnt == 0) break;

		if (flag == 0)
			cout << "no" << '\n';
		else
			cout << "yes" << '\n';
	}

	return 0;
}

bool char_comp(char com, char t) {
	if (c == com) {
		if (brace.empty())
			return false;

		if (brace.top() == t)
			brace.pop();
		else 
			return false;
	}
	return true;
}