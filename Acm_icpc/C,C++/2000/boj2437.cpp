/* Àú¿ï */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> chu;
int N;

void input();
void solve();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> N;
	chu.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> chu[i];
	}
}

void solve() {
	
	sort(chu.begin(), chu.end());

	int summation = 0;
	for (int i = 0; i < N; i++) {
		if (summation + 1 < chu[i]) {
			break;
		}
		summation += chu[i];
	}

	cout << summation + 1;
}