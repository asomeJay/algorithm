/* ¼Ò¼öÀÇ °ö */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

#define INTMAX 2147483647
using namespace std;

int n_of_decimal, target;
int decimal[100];
set<int> is_it;

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
	cin >> n_of_decimal >> target;
	for (int i = 0; i < n_of_decimal; i++) {
		cin >> decimal[i];
	}
}

void solve() {
	priority_queue<int> pq;

	for (int i = 0; i < n_of_decimal; i++) {
		pq.push(-1 * decimal[i]);
	}
	
	int cnt = 0;
	while ((++cnt) < target) {
		int curr = pq.top();
		while (!pq.empty() && pq.top() == curr) pq.pop();


		for (int i = 0; i < n_of_decimal; i++) {
			long long int temp = (long long int)curr * (long long int)decimal[i];
			if (-1 * temp >= INTMAX) continue;
			pq.push(temp);
		}
	}

	cout << -1 * pq.top() << '\n';
	return;
}
