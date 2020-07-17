/* 트리의 지름 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

#define pp pair<int,int>
#define MAX 100000 + 1
using namespace std;

int z_of_tree, ANS;
int diameter, farthestNode;
vector<pp> tree[MAX];
bool is_visit[MAX];

void solve();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> z_of_tree;
	for (int i = 1; i <= z_of_tree; i++) {
		int num; cin >> num;
		while (true) {
			int edge_num, edge_weight;
			cin >> edge_num;
			if (edge_num == -1) break;

			cin >> edge_weight;
			tree[num].push_back({ edge_num, edge_weight });
		}
	}

	solve();

	return 0;
}


void dfs(int sp, int weight) {
	if (is_visit[sp])
		return;

	is_visit[sp] = true;

	if (diameter < weight) {
		diameter = weight;
		farthestNode = sp;
	}

	for (int i = 0; i < tree[sp].size(); i++) {
		dfs(tree[sp][i].first, weight + tree[sp][i].second);
	}
}

void solve() {
	dfs(1, 0);
	fill(is_visit, &is_visit[MAX] - 1, 0);
	dfs(farthestNode, 0);

	cout << diameter << '\n';

}
