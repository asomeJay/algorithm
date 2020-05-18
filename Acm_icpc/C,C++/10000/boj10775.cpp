/* 10775 °øÇ× */

#include <iostream>

#define MAX 100001

using namespace std;

int G, P, child;
int parent[MAX];
bool is_used[MAX];

int find(int x);
void merge(int u, int v);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> G >> P;

	int i;

	for (i = 0; i <= G; i++) {
		parent[i] = -1;
	}

	for (i = 1; i <= P; i++) {
		cin >> child;
		if (is_used[0]) continue;
		int p = find(child);
		is_used[p] = true;

		merge(p - 1, p);
	}
		
	int sum = 0;
	for (i = 1; i <= G; i++) {
		if (is_used[i])
			sum++;
	}

	cout << sum << '\n';

	return 0;
}

int find(int x) {
	if (x <= 0) return 0;

	if (parent[x] == -1) return x;
	else
		return parent[x] = find(parent[x]);
}

void merge(int u, int v) {
	int a = find(u);
	int b = find(v);

	parent[b] = a;
}