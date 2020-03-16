/* ÃÖ¼Ú°ª°ú ÃÖ´ñ°ª */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
vector<pair<int, int>> tree;
vector<int> number;

pair<int,int> init(int node, int start, int end);
pair<int, int> search(int node, int left, int right, int start, int end);
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	int tree_size = (int)ceil(log2(N));
	tree_size = 1 << (tree_size + 1);
	number.resize(N); tree.resize(tree_size);
	for (auto n : tree) {
		n.first = -100000001;
		n.second = 100000001;
	}
	for (int i = 0; i < N; i++) 
		cin >> number[i];
	
	init(1, 0, N - 1);
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		pair<int, int> s;
		s = search(1, a, b, 0, N - 1);
		cout << s.second << " " << s.first << '\n';
	}
	return 0;
}

pair<int,int> init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = { number[start], number[end] };
	}
	else {
		pair<int, int> left, right;
		int large, small;
		left = init(node * 2, start, (start + end) / 2);
		right = init(node * 2 + 1, (start + end) / 2 + 1, end);

		large = max(left.first, right.first);
		small = min(left.second, right.second);
		return tree[node] = { large, small };
	}
}

pair<int, int> search(int node, int left, int right, int start, int end) {
	if (right < start || end < left) return { -1000000001,1000000001};
	if (left <= start && end <= right) return tree[node];
	else {
		pair<int, int> l, r;
		l = search(node * 2, left, right, start, (start + end) / 2);
		r = search(node * 2 + 1, left, right, (start + end) / 2 + 1, end);

		int large, small;
		large = max(l.first, r.first);
		small = min(l.second, r.second);
		return { large, small };
	}
}