/* CCW */

#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	pair<int, int> a, b, c;
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	cin >> c.first >> c.second;
	int temp = a.first * b.second + b.first * c.second + c.first * a.second;

	int temp_b = a.second * b.first + b.second * c.first + c.second * a.first;
	int dir = temp - temp_b;
	if (dir < 0)
		cout << "-1";
	else if (dir == 0)
		cout << "0";
	else
		cout << "1";

	return 0;
}