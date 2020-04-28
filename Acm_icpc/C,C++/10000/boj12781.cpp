/* PIZZA ALVOLOC */

#include <iostream>
#include <cstring>

#define pp pair<int,int>

using namespace std;

pp edge[4];

// (x2- x1)(y3 - y1) - (y2 - y1)(x3 - x1)
inline int ccw(pp a, pp b, pp c) {
	int op = a.first * b.second + b.first * c.second + c.first * a.second;
	op -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if (op > 0)return 1;
	else if (op == 0)return 0;
	else return -1;

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 4; i++) 
		cin >> edge[i].first >> edge[i].second;
	
	bool flag = false;

	if (ccw(edge[0], edge[1], edge[2]) * ccw(edge[0], edge[1], edge[3]) < 0) 
		flag = true;
	
	if (flag)
		cout << 1;
	else
		cout << 0;

	
	return 0;
}