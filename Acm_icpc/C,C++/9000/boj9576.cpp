/* 백준 9576 : 책 나눠주기 */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_PARENT 1001

using namespace std;

int N, M, t_case, cnt;
int parent[MAX_PARENT];

int find_parent(int x);
void union_parent(int left, int);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t_case;

	for (int ii = 0; ii < t_case; ii++){
		cnt = 0;
		for (int i = 0; i < MAX_PARENT; i++) {
			parent[i] = i;
		}

		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			union_parent(a, b);
		}
		cout << cnt << '\n';
	}
	return 0;
}

int find_parent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find_parent(parent[x]);
}

void union_parent(int left, int right) {
	int x_parent = find_parent(right);
	
	if (x_parent >= left && x_parent <= N) {
		cnt++;
	}
	if (x_parent != 0) 
		parent[x_parent] = find_parent(x_parent - 1);
	return;
}
