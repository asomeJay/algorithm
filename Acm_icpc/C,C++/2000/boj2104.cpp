/* 부분 배열 고르기 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define pp pair<long long int,long long int>
#define ll long long int 

using namespace std;

void input();
void solve();
pp seg_init(int, int, int);
pp seg_find(int, int, int, int, int);

ll n_of_arr, arr[100000], ans;
vector<pp> tree;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> n_of_arr;
	for (int i = 0; i < n_of_arr; i++) {
		cin >> arr[i];
	}

	ll height = ceil(log2(n_of_arr) + 1);
	tree.resize(1 << (height + 1));
}

void divide(int l, int r) {
	if (l > r) return;
	pp curr = seg_find(0, n_of_arr-1, l, r, 1);
	//cout << l << " " << r << " " << curr.first << " " << curr.second << endl;
	
	ans = max(ans, arr[curr.first] * curr.second);

	divide(l, curr.first - 1);
	divide(curr.first + 1, r);

}

void solve() {
	seg_init(0, n_of_arr-1, 1);
	divide(0, n_of_arr-1);

	cout << ans << '\n';
}

pp seg_init(int start, int end, int node) {
	// first minvalue second summation
	if (start == end) {
		tree[node].first = start;
		tree[node].second = arr[start];
		return tree[node];
	}
	ll mid = (start + end) / 2;

	pp temp1 = seg_init(start, mid, node * 2);
	pp temp2 = seg_init(mid + 1, end, node * 2 + 1);
	
	tree[node].first = (arr[temp1.first] > arr[temp2.first] ? temp2.first : temp1.first);
	tree[node].second = (temp1.second + temp2.second);

	return tree[node];
}

pp seg_find(int start, int end, int left , int right, int node) {
	if (end < left || right < start) return { -1, 0 };
	if (left <= start  &&end <= right) return tree[node];
	else {
		int mid = (start + end) / 2, idx;
		pp t1 = seg_find(start, mid, left, right, node * 2);
		pp t2 = seg_find(mid + 1, end, left, right, node * 2 + 1);

		if (t1.first == -1) {
			return t2;
		}
		else if (t2.first == -1) {
			return t1;
		}
		else {
			idx = (arr[t1.first] > arr[t2.first] ? t2.first : t1.first);
			return { idx, t1.second + t2.second };
		}
	}
}