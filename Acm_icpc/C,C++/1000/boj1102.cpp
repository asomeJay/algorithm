/* ¹ßÀü¼Ò */

#include <iostream>
#include <string>
#include <algorithm>

#define PP 17

using namespace std;

int N, normal, object, power_plant[1<<16][PP][PP];
int bit_mask;

void input();
int dfs(int, int, int, int, int);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int result = 987654321;

	input();
	for (int i = 0; i < N; i++) {
		if (!(bit_mask & (1 << i))) continue;
		for (int j = 0; j < N; j++) {
			if (bit_mask & (1 << j))
				continue;
			result = min(result, dfs(normal, power_plant[0][i][j], i, j, (bit_mask | (1 << j))));
		}
	}

	if (result == 987654321)
		result = -1;
	cout << result;

	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> power_plant[0][i][j];
		}
	}

	string ok;
	cin >> ok;

	for (int i = 0; i < N; i++) {
		if (ok[i] == 'Y') {
			normal++;
			bit_mask |= (1 << i);
		}
	}

	cin >> object;
}

int dfs(int depth, int price, int cur, int tar, int visit) {
	cout << cur << " " << tar << '\n';
	if (depth >= object) {
		return 0;
	}

	int& ret = power_plant[visit][cur][tar];

	if (ret != 0)
		return ret;

	ret = 987654321;

	for (int src = 0; src < N; src++) {
		if (!(visit & (1 << src))) continue;
		for (int obj = 0; obj < N; obj++) {
			if (src == obj || (visit &(1 << obj))) 
				continue;
			ret = min(dfs(depth + 1, price + power_plant[0][src][obj], src, obj, (visit | (1 << obj))), ret);
		}
	}

	return ret;
}