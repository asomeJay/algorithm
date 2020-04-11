/* ¹ßÀü¼Ò */

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

#define PP 17

using namespace std;

int N, normal, object, power_plant[PP][PP];
int dp[1 << PP];
int bit_mask;

void input();
int dfs(int, int);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int result = 987654321;

	input();
	
	if (normal >= object)
		cout << '0' << '\n';
	else if (normal == 0)
		cout << "-1" << '\n';

	else {
		result = min(result, dfs(normal, bit_mask));

		cout << result;
	}

	

	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> power_plant[i][j];
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
	memset(dp, -1, sizeof(dp));
	cin >> object;
}

int dfs(int depth, int visit) {
	if (depth >= object) {
		
		return 0;
	}

	int& ret = dp[visit] ;

	if (ret != -1)
		return ret;

	ret = 987654321;

	for (int src = 0; src < N; src++) {
		if (!(visit & (1 << src))) continue;
		for (int obj = 0; obj < N; obj++) {
			if (src == obj || (visit &(1 << obj))) 
				continue;
			ret = min(ret, power_plant[src][obj] + dfs(depth + 1,  (visit | (1 << obj))));
		}
	}

	return ret;
}