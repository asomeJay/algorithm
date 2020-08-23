/* LCA2 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define pp pair<int,int>
#define INTMAX 2100000000

using namespace std;

int N, first_touch[100001], path_idx;
vector<pair<int, int>> path, seg_tree;
vector<int> edge[100001];

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
	int h = (int)ceil(log2(2 * N));
	seg_tree.resize((int)pow(2, h + 1));
	path.resize(2 * N);

	for (int i = 1; i < N; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
}

void make_path(int depth,int curr, int before) {
	if (first_touch[curr] == 0)
		first_touch[curr] = path_idx;

	path[path_idx].first = depth;
	path[path_idx++].second = curr;
	/* 현재 노드와 연결된 엣지를 dfs로 순회한다. */
	for (auto nxt : edge[curr]) {
		if (nxt == before) continue;

		make_path(depth + 1,nxt, curr);
		path[path_idx].first = depth;
		path[path_idx++].second = curr;
	}
}

pp seg_init(int s, int e, int n) {
	if (s == e) {
		return seg_tree[n] = path[s];
	}

	pp l = seg_init(s, (s + e) / 2, n * 2);
	pp r = seg_init((s + e) / 2 + 1, e, n * 2 + 1);

	return seg_tree[n] = (l.first < r.first ? l : r);
}

pp seg_find(int s, int e, int l, int r, int n) {
	if (r < s || e < l) return { INTMAX,INTMAX };
	if (l <= s && e <= r) return seg_tree[n];

	pp ll = seg_find(s, (s + e) / 2, l, r, n * 2);
	pp rr = seg_find((s + e) / 2 + 1, e, l, r, n * 2 + 1);

	return (ll.first < rr.first ? ll : rr);
}

void solve() {
	int n_of_target;
	cin >> n_of_target;

	make_path(0, 1, -1);
	first_touch[1] = 0;
	seg_init(0, 2 * N - 1, 1);

	for (int i = 0; i < n_of_target; i++) {
		int a, b; cin >> a >> b;
		int t_a = first_touch[a], t_b = first_touch[b];

		if (t_a > t_b)
			swap(t_a, t_b);

		cout << seg_find(0, 2 * N-1, t_a,t_b, 1).second << '\n';
	}
}