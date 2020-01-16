/* ���� �� �����ϴ� �κ� ���� */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	vector<int> longest;
	int i, j, k, n; cin >> n;

	longest.push_back(-1100000000);

	for (i = 1; i <= n; i++) {
		scanf("%d", &k);
		if (longest.back() < k) {
			longest.push_back(k);
		}

		else {
			auto it = lower_bound(longest.begin(), longest.end(), k);
			*it = k;
		}
	}

	printf("%d\n", longest.size() - 1);
	
	return 0;
}