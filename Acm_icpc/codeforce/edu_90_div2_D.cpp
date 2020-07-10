#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int

using namespace std;

vector<ll> seg_tree, a;
ll maximum;
ll seg_init(int node, int left, int right);
ll seg_sum(int node, int left, int right, int start, int end);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t_case; cin >> t_case;
	for (int i = 0; i < t_case; i++) {
		int len_of_a;
		cin >> len_of_a;
	
		maximum = 0;
		ll height = log2(len_of_a) + 1;
		seg_tree.clear();
		seg_tree.resize(1 << (height+1), 0);
		a.resize(len_of_a+ 1);

		ll summation = 0;
		for (int j = 1; j <= len_of_a; j++) {
			cin >> a[j];
			if ((j-1) % 2 == 0) {
				summation += a[j];
				a[j] *= -1;
			}
		}
		cout << summation << endl;
		seg_init(1, 1, len_of_a);
		/*for (int jj = 0; jj < seg_tree.size(); jj++) {
			cout << seg_tree[jj] << " ";
		} cout << endl; */

		for (int k = 1; k <= len_of_a; k++) {
			for(int kk = k )
		}
		summation += maximum;
		cout << summation << '\n';

	}
	return 0;
}

ll seg_init(int node, int left, int right){
	//cout << node << " " << left << " " << right << endl;
	if (left == right) {
		return seg_tree[node] = a[left];
	}
	else {
		seg_tree[node] = seg_init(node * 2, left, (left + right) / 2)
			+ seg_init(node * 2 + 1, (left + right) / 2 + 1, right);
		maximum = max(maximum, seg_tree[node]);
		return seg_tree[node];
	}
}

ll seg_sum(int node, int left, int right, int start, int end) {
	if (end < left || right < start) {
		return 0;
	} 
	else if (left <= start && end <= right) {
		return seg_tree[node];
	}
	else {
		return seg_sum(node * 2, left, (left + right) / 2, start, end) +
			seg_sum(node * 2 + 1, (left + right) / 2 + 1, right, start, end);
	}
}
