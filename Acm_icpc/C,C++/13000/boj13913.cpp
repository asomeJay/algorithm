/* ¼û¹Ù²ÀÁú 4 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

#define pp pair<int,int>

using namespace std;

int N, K;
int arr[200001];

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
	cin >> N >> K;
	memset(arr, -1, sizeof(arr));
}

void solve() {
	queue<int> q;
	q.push(N);

	int t = 1;

	while (true) {

		int curr = q.front();
		q.pop();

		if (curr == K) {
			break;
		}

		if (curr - 1 >= 0 && arr[curr - 1] == -1) {
			arr[curr - 1] = curr;
			q.push(curr - 1);
		}
		if (curr + 1 <= 200000 && arr[curr + 1] == -1) {
			arr[curr + 1] = curr;
			q.push(curr + 1);
		}
		if (curr * 2 <= 200000 && arr[curr * 2] == -1) {
			arr[curr * 2] = curr;
			q.push(curr * 2);
		}
	}
	int idx = K;
	stack<int> s;
	s.push(idx);

	while (idx != N) {
		idx = arr[idx];
		s.push(idx);
	}

	cout << s.size() - 1 << '\n';
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}