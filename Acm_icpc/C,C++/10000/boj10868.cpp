/* 최솟값 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve();
int seg_init(int s, int e, int node);
int seg_find(int s, int e, int l, int r, int node);

int N,M, arr[100000];
vector<int> tree;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	solve();

	return 0;
}

int seg_init(int s, int e, int node) {
	if (s == e) 
		return tree[node] = arr[s];

	return (tree[node] = min(seg_init(s, (s + e) / 2, node * 2), seg_init((s + e) / 2 + 1, e, node * 2 + 1)));
}

int seg_find(int s, int e, int l, int r, int node) {
	if (e < l || r < s) return 2100000000; // 각 노드의 최댓값이 10억임
	if (l <= s && e <= r) return tree[node];
	return min(seg_find(s, (s + e) / 2, l, r, node * 2), seg_find((s + e) / 2 + 1, e, l, r, node * 2 + 1));
}

void solve() {
	cin >> N >> M;

	int height = log2(N + 1) + 1;
	tree.resize(1 << (height + 1));

	for (int i = 0; i < N; i++) 
		cin >> arr[i];

	seg_init(0, N - 1, 1);

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;

		cout << seg_find(0, N - 1, a-1, b-1, 1) << '\n';
	}

}
