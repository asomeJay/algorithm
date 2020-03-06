/* Á¦·Î */

#include <iostream>
#include <stack>

using namespace std;

stack<int> jaemin;
int K;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> K;
	while (K--) {
		int t;
		cin >> t;
		if (t == 0)
			jaemin.pop();
		else
			jaemin.push(t);
	}

	int sum = 0;
	while (!jaemin.empty()) {
		sum += jaemin.top();
		jaemin.pop();
	}

	cout << sum;

	return 0;
}