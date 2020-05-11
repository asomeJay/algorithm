/* 조각 움직이기 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char map[5][5];
vector<pair<int, int>> axis;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') {
				axis.push_back({ i,j });
			}
		}
	}

	int minimum = 987654321;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int temp = 0;
			for (int k = 0; k < (int)axis.size(); k++) {
				temp += (abs(axis[k].first - i) + abs(axis[k].second - j));
			}
			minimum = min(minimum, temp);
		}
	}

	cout << minimum << '\n';
	return 0;
}