#pragma once
/* ž */

#include <iostream>
#include <stack>

#define MAX_HEIGHT 500000 + 1

using namespace std;

int N, height, cnt;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	stack<pair<int,int>> s;

	for (int i = 1; i <= N; i++) {
		cin >> height;

		while (!s.empty()) {
			if (s.top().second > height) {
				cout << s.top().first << " ";
				break;
			}

			s.pop();
		}

		if (s.empty()) cout << 0 << '\n';
		s.push({ i, height });
	}

	return 0;
}
