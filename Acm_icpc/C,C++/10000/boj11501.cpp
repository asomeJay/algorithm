/* 11501 аж╫д */

#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll test, count_of_num;
vector<int> container;

ll dfs(int current_point);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> test;
	for (int i = 0; i < test; i++) {
		container.clear();

		cin >> count_of_num;
		container.resize(count_of_num);

		for (int j = 0; j < count_of_num; j++) {
			cin >> container[j];
		}

		cout << dfs(count_of_num - 1) << '\n';
	}

	return 0;
}

ll dfs(int last_point) {
	ll largest, largest_point, l;

	l = 0;
	largest = container[last_point];
	largest_point = last_point;

	for (int i = last_point - 1; i >= 0; i--) {
		if (largest < container[i]) {
			largest = container[i];
		}
		else {
			l += (largest - container[i]);
		}
	}

	return l;
}