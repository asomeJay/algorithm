/* 트리의 높이와 너비 */

#include <iostream>
#include <queue>
#include <vector>
#include <stack>

#define MAX_NODE 10000 + 1

class node {
public:
	int left, right;
	bool root;
	node() { root = true; }
};

using namespace std;

int root_node, x_pos, max_height;
int level_min[MAX_NODE], level_max[MAX_NODE];
node node_relation[MAX_NODE];

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
	int n_of_node; cin >> n_of_node;
	x_pos = 1; // x 값은 1부터 시작.
	for (int i = 0; i < n_of_node; i++) {
		int src, left, right;
		cin >> src >> left >> right;

		if(left != -1)
			node_relation[left].root = false;
		if(right != -1)
			node_relation[right].root = false;

		node_relation[src].left = left;
		node_relation[src].right = right;
	}

	for (int i = 1; i <= n_of_node; i++) {
		level_min[i] = 987654321;
		if (node_relation[i].root == true) {
			root_node = i;
		}
	}
}

void inorder(int root, int height) {
	node temp = node_relation[root];

	if (temp.left != -1) {
		inorder(temp.left, height + 1);
	}

	max_height = max(max_height, height); // 최대 높이를 저장한다. 
	level_min[height] = min(level_min[height], x_pos);
	level_max[height] = x_pos++;

	if (temp.right != -1) {
		inorder(temp.right, height + 1);
	}
}

void solve() {
	inorder(root_node, 1);
	int maxi = 0, max_index;

	for (int height = 1; height <= max_height; height++) {
		if (maxi < level_max[height] - level_min[height] + 1) {
			maxi = level_max[height] - level_min[height] + 1;		// 최고 차이를 저장한다.
			max_index = height;								// 그 height를 저장한다.
		}
	}
	cout << max_index << ' ' << maxi << '\n';
}