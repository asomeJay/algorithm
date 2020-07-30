/* 완전 이진 트리*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>

#define MAX 1024 + 1

using namespace std;

void input();
void solve();

int K, n_in_height;
int in[MAX],building[MAX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> K;
	n_in_height = pow(2, K) - 1;
	for (int i = 1; i <= n_in_height; i++) {
		cin >> in[i];
	}
}

void solve() {
	queue<pair<int,int>> q;
	
	int l, r;
	q.push({ 1, n_in_height });
	
	while (!q.empty()) {
		int q_size = q.size();
		while (q_size--) {
			l = q.front().first;
			r = q.front().second;
			q.pop();

			int mid = (l + r) / 2;
			
			cout << in[mid] << " ";
			if(l < mid)
				q.push({ l, mid-1 });
			if( mid < r)
				q.push({ mid + 1, r });
		}
		cout << '\n';
	}
}