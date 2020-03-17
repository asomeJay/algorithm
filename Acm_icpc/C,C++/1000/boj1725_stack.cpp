/* 히스토그램 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>

#define MAX 987654321
#define ll long long int

using namespace std;

long long int Ans = -1;
int N;
vector<long long int> height, tree;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	ll  tree_size = (ll)ceil(log2(N));
	tree_size = 1 << (tree_size + 1);
	height.resize(N); tree.resize(tree_size);

	for (int i = 0; i < N; i++) {
		cin >> height[i];
	}
	height.push_back(0);
	stack<int> remain;

	int result = 0;
	for (int i = 0; i <= N; i++) {
		while (!remain.empty() && height[remain.top()] >= height[i]) {
			int index = remain.top();
			remain.pop();

			int width;
			if (remain.empty()) {
				width = i;
			}
			else
				width = i - remain.top() - 1;
			Ans = max(Ans, height[index] * width);
		}
		remain.push(i);
	}

	cout << Ans << '\n';
	return 0;
}