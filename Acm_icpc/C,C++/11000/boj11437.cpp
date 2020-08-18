/* LCA */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define pp pair<int,int>
#define MAX_NODE 50000 + 1

using namespace std;

int N, max_depth, tree_idx;
int node[MAX_NODE];
vector<int> edge[MAX_NODE];
vector<pp> tree, seg_node;

void input();
void solve();

void depth_node(int here, int depth, int );
void match_node_depth();

pp seg_init(int start, int end, int node);
pp seg_find(int start, int end, int left, int right, int node);


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();

	depth_node(1, 0, -1);
	match_node_depth();
	seg_init(0, 2 * N -1, 1);

	solve();

	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	int h = (int)ceil(log2(2 * N));

	seg_node.resize(pow(2, h + 1));
	tree.resize(2 * N);
}

// {depth, node} 로 이루어진 배열을 만든다. 
void depth_node(int here, int depth, int parent) {
	tree[tree_idx].first = depth;
	tree[tree_idx++].second = here;

	for (auto there : edge[here]) {
		if (there == parent) continue;

		depth_node(there, depth + 1, here);

		tree[tree_idx].first = depth;
		tree[tree_idx++].second = here;
	}
}

void match_node_depth() {
	for (int i = 0; i < tree_idx; i++) {
		// tree 안에 있는 노드가 몇 번인지 파악한다.
		int curr = tree[i].second;
		// 그 노드가 최초로 등장한 idx를 저장한다/
		if (node[curr] == 0) {
			node[curr] = i;
		}
	}

	node[1] = 0;
}

pp seg_init(int start, int end, int node) {
	if (start == end) {
		return seg_node[node] = tree[start];
	}

	pp l = seg_init(start, (start + end) / 2, node * 2);
	pp r = seg_init((start + end) / 2 + 1, end, node * 2 + 1);

	return seg_node[node] = (l.first < r.first ? l : r);
}

pp seg_find(int start, int end, int left, int right, int node) {
	if (right < start || end < left) return { 987654321, 9876545321 };
	if (left <= start && end <= right) return seg_node[node];

	pp l = seg_find(start, (start + end) / 2, left, right, node * 2);
	pp r = seg_find((start + end) / 2 + 1, end, left, right, node * 2 + 1);

	return (l.first < r.first ? l : r);
}

void solve() {
	int K; cin >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		if (node[a] < node[b])
			cout << seg_find(0, 2 * N - 1, node[a], node[b], 1).second << '\n';
		else
			cout << seg_find(0, 2 * N - 1, node[b], node[a], 1).second << '\n';
	}
}
