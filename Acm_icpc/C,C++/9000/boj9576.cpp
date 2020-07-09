/* 백준 9576 : 책 나눠주기 */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_PARENT 1000

using namespace std;

int N, M, t_case;
int parent[MAX_PARENT];

int find_parent(int x);
int union_parent(int x, int y);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t_case;

	for (int ii = 0; ii < t_case; ii++){
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
		}
	}


	return 0;
}

int find_parent(int x) {
	if (parent[x] == -1) return x;
	return parent[x] = find_parent(parent[x]);
}

int union_parent(int x, int y) {
	int x_parent = find_parent(x);
	int y_parent = find_parent(y);

	if (x == y) return 0;


}
