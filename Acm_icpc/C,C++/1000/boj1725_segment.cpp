/* 히스토그램 */
/*  1. 전체에서 제일 작은 높이를 찾는다.
	2. Divide and Conquer 전략을 채택해서 절반으로 나눈 후
	그 절반 중에 제일 낮은 걸 찾는다. 
	3. 2를 반복한다. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX 987654321
#define ll long long int

using namespace std;

long long int Ans = -1;
int last_height;
int N, M;
vector<long long int> height, tree;

ll largest(int start, int end);

void segment_init(int node, int start, int end);
ll segment_area(int node, int left, int right, int start, int end);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	ll  tree_size = (ll)ceil(log2(N));
	tree_size = 1 << (tree_size + 1);
	height.resize(N); tree.resize(tree_size);

	for (int i = 0; i < N; i++) {
		cin >> height[i];
		Ans = max(Ans, height[i]);
	}
	
	segment_init(1, 0, N - 1);
	cout << largest(0, N - 1);

	return 0;
}

void segment_init(int node, int start, int end) {
	if (start == end) {
		tree[node] = start;
		return;
	}
	segment_init(node * 2, start, (start + end) / 2);
	segment_init(node * 2 + 1, (start + end) / 2 + 1, end);

	if (height[tree[node * 2]] < height[tree[node * 2 + 1]]) {
		tree[node] = tree[node * 2];
	}
	else {
		tree[node] = tree[node * 2 + 1];
	}
}

ll segment_area(int node, int left, int right, int start, int end) {
	if (end < left || right < start) return -1;
	if (left <= start && end <= right)	return tree[node];

	ll lefts = segment_area(node * 2, left, right, start, (start + end) / 2);
	ll rights = segment_area(node * 2 + 1, left, right, (start + end) / 2 + 1, end);

	if (lefts == -1) {
		return rights;
	}
	else if (rights == -1) {
		return lefts;
	}
	else {
		if (height[lefts] <= height[rights]) {
			return lefts;
		}
		return rights;
	}
}

ll largest(int start, int end) {
	int m = segment_area(1, start, end, 0 , N-1);
	ll area = (end - start + 1) * height[m];
	if (start < m) {
		area = max(area, largest(start, m - 1));
	}
	if (m < end) {
		area = max(area, largest(m + 1, end));
	}

	return area;
}