/* 구간 곱 구하기 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long int
#define NUMERATOR 1000000007

using namespace std;

int N, M, K;
vector<int> a, tree;

ll segment_init(int node, int start, int end);
ll segment_multi(int node, int left, int right, int start, int end);
void segment_update(int node, int index, int start, int end, ll diff);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;
	a.resize(N);
	
	int tree_size = (int)ceil(log2(N));
	tree_size = 1 << (tree_size + 1);
	tree.resize(tree_size);
	M += K;

	for (int i = 0; i < N; i++) 
		cin >> a[i];
	
	segment_init(1, 0, N - 1);
	for (auto n : tree)
		cout << n << " "; 
	cout << endl;
	for (int i = 0; i < M; i++) {
		int tt,b, c,diff;
		cin >> tt >> b >> c;
		switch (tt) {
		case 1:
			b--; 
			diff = c / a[b];
			segment_update(1, b, 0, N - 1, diff);
			a[b] = c;
			break;
		case 2:
			b--; c--;
			cout << segment_multi(1, b, c, 0, N - 1) % NUMERATOR << '\n';
			break;
		default:
			cout << "ERROR AT CASE" << endl;
		}
	}

	return 0;
}

ll segment_init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = a[start];
	}
	else {
		return tree[node] = ((segment_init(node * 2, start, (start + end) / 2)) % NUMERATOR
			* (segment_init(node * 2 + 1, (start + end) / 2 + 1, end) % NUMERATOR)) % 
			NUMERATOR;
	}
}

// left ~ right : 합을 구하려는 구간
// start ~ end : 현재 node의 합을 담당.
ll segment_multi(int node, int left, int right, int start, int end) {
	if (end < left || right < start) return 1;
	if (left <= start && end <= right) return tree[node];
	else {
		return ((segment_multi(node * 2, left, right, start, (start + end) / 2)) % NUMERATOR
			* (segment_multi(node * 2 + 1, left, right, (start + end) / 2 + 1, end)) % NUMERATOR)
			% NUMERATOR;
	}
}

void segment_update(int node, int index, int start, int end, ll diff) {
	if (index < start || index > end) return;
	tree[node] *= diff;
	if (start != end) {
		segment_update(node * 2, index, start, (start + end) / 2, diff);
		segment_update(node * 2 + 1, index, (start + end) / 2 + 1, end, diff);
	}
}