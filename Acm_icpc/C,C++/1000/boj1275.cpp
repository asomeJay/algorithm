/* Ä¿ÇÇ¼ó2 */

#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long int
#define iNF 2100000000

using namespace std;

void seg_init();
ll seg_find(int l, int r);
void seg_update(int i, ll data);
void input();
void solve();

int N, Q;
ll capacity;
vector<ll> arr, seg_tree;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	solve();
	return 0;
}

void input() {
	cin >> N >> Q;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void solve() {
	seg_init();
	for (int i = 0; i < Q; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		a--; b--; c--;
		if (a > b) swap(a, b);

		cout << seg_find(a, b) << '\n';

		seg_update(c, d);
	}
}

void seg_init() {
	for (capacity = 1; capacity < N; capacity *= 2);
	seg_tree.resize(capacity * 2);

	for (ll i = capacity; i < capacity + N; i++) {
		seg_tree[i] = arr[i - capacity];
	}

	for (ll i = capacity + N; i < capacity * 2; i++) {
		seg_tree[i] = 0;
	}

	for (ll i = capacity - 1; i > 0; i--) {
		seg_tree[i] = seg_tree[2 * i] + seg_tree[2 * i + 1];
	}
}

ll seg_find(int l, int r) {
	ll ret = 0;
	l += capacity;
	r += capacity;

	for (; l < r; l /= 2, r /= 2) {
		if (l % 2 == 1) ret += seg_tree[l++];
		if (r % 2 == 0) ret += seg_tree[r--];
	}
	if (l == r) ret += seg_tree[l];
	return ret;
}

void seg_update(int i, ll data) {
	ll idx = capacity + i;
	seg_tree[idx] = data;
	for (idx /= 2; idx > 0; idx /=2) {
		seg_tree[idx] = seg_tree[2 * idx] + seg_tree[2 * idx + 1];
	}
}

