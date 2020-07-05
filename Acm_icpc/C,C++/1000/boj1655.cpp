#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<int> node;

priority_queue<int, vector<int>, greater<int>> min_heap;
priority_queue<int, vector<int> ,less<int>> max_heap;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
	
		node.push_back(a);

		if (min_heap.size() == max_heap.size()) {
			max_heap.push(a);	
		}
		else {
			min_heap.push(a);
		}

		if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
			int a = max_heap.top(); max_heap.pop();
			int b = min_heap.top(); min_heap.pop();

			min_heap.push(a); max_heap.push(b);
		}
		cout << max_heap.top() << '\n';
	}
	return 0;
}