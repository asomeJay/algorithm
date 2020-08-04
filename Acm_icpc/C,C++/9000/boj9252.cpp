/* LCS2 */

#include <iostream>
#include <string>
#include <algorithm>

#define N 1
#define NS 2
#define W 3

using namespace std;

pair<int,int> map[1000 + 1][1000 + 1];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string a, b; cin >> a >> b;
	for (int i = 0; i <= 1000; i++) {
		map[i][0] = { 0,0 };
		map[0][i] = { 0,0 };
	}

	int a_size = a.size();
	int b_size = b.size();

	for (int i = 1; i <= a_size; i++) {
		for (int j = 1; j <= b_size; j++) {
			if (a[i - 1] == b[j - 1]) {
				map[i][j].first = map[i - 1][j - 1].first + 1;
				map[i][j].second = NS;
			}
			else {
				if (map[i - 1][j].first > map[i][j - 1].first) {
					map[i][j].first = map[i - 1][j].first;
					map[i][j].second = N;
				}
				else {
					map[i][j].first = map[i][j - 1].first;
					map[i][j].second = W;
				}
			}
		}
	}
	
	string res;

	if (map[a_size][b_size].first == 0) 
		cout << 0 << '\n';

	else {
		int i = a_size, j = b_size, summation = 0;
		while (map[i][j].first != 0) {
			if (map[i][j].second == NS) {
				res += a[i-1];
				i--; j--;
			}
			else if (map[i][j].second == W) {
				j--;
			}
			else { // N
				i--;
			}
		}
		cout << res.size() << '\n';
		for (auto i = res.rbegin(); i != res.rend(); i++) {
			cout << *i;
		}
	}
	return 0;
}