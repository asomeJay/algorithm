/* 구간 합 구하기 */

#include <iostream>
#include <vector>
#include <algorithm>

#include <cmath>

#define ll long long int 

using namespace std;

int n_of_number, n_of_change, n_of_sum;
vector<ll> number, tree;

ll init(int node_number, int start, int end);
ll segment_sum(int, int left, int right, int start, int end);
void update(int node, int index, int start, int end, ll diff);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n_of_number >> n_of_change >> n_of_sum;
	int height = (int)ceil(log2(n_of_number));
	height = (1 << (height + 1));

	number.resize(n_of_number);
	tree.resize(height);

	for (int i = 0; i < n_of_number; i++) 
		cin >> number[i];
	n_of_change += n_of_sum;
	init(1, 0, n_of_number-1);

	for (int i = 0; i < n_of_change; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		switch (a) {
		case 1:
			b--;
			update(1, b, 0, n_of_number - 1, c - number[b]);
			number[b] = c;

			break;
		case 2:
			cout << segment_sum(1, b - 1, c - 1, 0, n_of_number-1) << '\n';
			break;
		default : 
			cout << "ERROR AT SWITCH" << endl;
		}
	}

	return 0;
}

ll init(int node_number, int start, int end) {
	if (start == end) 
		return tree[node_number] = number[start];
	
	else {
		return tree[node_number] = init(node_number * 2, start, (start + end) / 2) +
			init(node_number * 2 + 1, (start + end) / 2 + 1, end);
	}
}

ll segment_sum(int node, int left, int right, int start, int end) {
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node];

	else {
		return segment_sum(node * 2, left, right, start, (start + end) / 2) + 
		segment_sum(node * 2 + 1, left, right, (start + end) / 2 + 1, end);
	}
}

void update(int cur_node, int index, int start, int end, ll diff) {
	if (start > index || end < index) return;
	tree[cur_node] += diff;

	if (start != end) {
		update(cur_node * 2, index, start, (start + end) / 2, diff);
		update(cur_node * 2 + 1, index, (start + end) / 2 + 1, end, diff);
	}
}