/* ¾Û */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define ll long long int 

using namespace std;

vector<int> memory, cost, res;
int n, m;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	memory.resize(n);  cost.resize(n);

	int cost_sum = 0;
	for (int i = 0; i < n; i++) cin >> memory[i];
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
		cost_sum += cost[i];
	}
	
	res.resize(cost_sum + 1, 0);
		
	
	for (int i = 0; i < n; i++) {
		for (int j = cost_sum; j >= cost[i]; j--) {
			res[j] = max(res[j], res[j - cost[i]] + memory[i]);
		}
	}

	int i;
	for (i = 0; res[i] < m; i++);
	cout << i << '\n';
	return 0;
}