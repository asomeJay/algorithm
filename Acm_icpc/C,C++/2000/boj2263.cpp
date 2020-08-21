/* 트리의 순회 */

#include <iostream>
#include <vector>

using namespace std;

void recur(int, int, int, int);
void input();
void solve();

int N;
vector<int> pre_order, post_order, in_order;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	input();
	solve();	

	return 0;
}

// Postorder에서 r-1을 Inorder에서 찾아서 그 r-1을 찾아서 
// 그 찾은 target의 바로 왼쪽을 다시 r로 보낸다. 
void recur(int in_order_start, int in_order_end, int post_order_start, int post_order_end) {

	if (in_order_start > in_order_end || post_order_start > post_order_end) return;

	int target = post_order[post_order_end];

	cout << target << " ";

	for (int i = in_order_start; i <= in_order_end; i++) {
		if (in_order[i] == target) {
			recur(in_order_start, i - 1, post_order_start, post_order_start + i - in_order_start - 1 );
			recur(i + 1, in_order_end, post_order_start + i - in_order_start, post_order_end-1);
		}
	}
}

void input() {
	cin >> N;
	in_order.resize(N); post_order.resize(N);

	for (int i = 0; i < N; i++) cin >> in_order[i];
	for (int i = 0; i < N; i++) cin >> post_order[i];
}

void solve() {
	recur(0, N - 1, 0, N-1);
}
