#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> node_for_sort;
vector<int> node_for_seq;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		node_for_sort.push_back(a);
		node_for_seq.push_back(a);

		if (i % 2 == 0) {
			sort(node_for_sort.begin(), node_for_sort.end());
			cout << node_for_sort[node_for_sort.size() / 2] << '\n';
		}
		else {	
			cout << min(node_for_seq[i / 2], node_for_seq[i/ 2 + 1]) << '\n';
		}
	}
	return 0;
}