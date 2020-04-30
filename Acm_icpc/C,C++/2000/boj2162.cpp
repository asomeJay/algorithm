/* 선분 그룹 */

#include <iostream>
#include <algorithm>

#define ll long long int
#define pp pair<ll,ll>

using namespace std;

class line {
public:

	pp p1, p2;

};

void input();
void solve();
void output();

int find_parent(int child);
void find_union(int line1, int line2);

ll ccw(pp a, pp b, pp c);
bool intersect(int, int);

int N;
ll MAX;
pp parent[3010];
line edge[3010];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();
	output();

	return 0;
}

ll ccw(pp a, pp b, pp c) {
	long long int temp = (a.first * b.second) + (b.first * c.second) + (c.first * a.second);
	temp -= ((b.first * a.second) + (c.first * b.second) + (a.first * c.second));
	if (temp > 0)return 1;
	if (temp == 0)return 0;
	if (temp < 0) return -1;

}

bool intersect(int line1, int line2) {
	ll dir1 = ccw(edge[line1].p1, edge[line1].p2, edge[line2].p1)
		* ccw(edge[line1].p1, edge[line1].p2, edge[line2].p2);

	ll dir2 = ccw(edge[line2].p1, edge[line2].p2, edge[line1].p1)
		* ccw(edge[line2].p1, edge[line2].p2, edge[line1].p2);

	if (dir1 == 0 && dir2 == 0) {
		pp a, b, c, d;
		a = edge[line1].p1;
		b = edge[line1].p2;
		c = edge[line2].p1;
		d = edge[line2].p2;

		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}

	return dir1 <= 0 && dir2 <= 0;

}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		parent[i].first = -1;
		parent[i].second = 1;
	}
	MAX = 1;

	for (int i = 0; i < N; i++) {
		cin >> edge[i].p1.first >> edge[i].p1.second >> edge[i].p2.first >> edge[i].p2.second;
	}
		
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)continue;
			if (intersect(i, j)) {
				find_union(i, j);
			}
		}
	}
}

void output() {
	int temp = 0;

	for (int i = 0; i < N; i++) 
		if (parent[i].first == -1)
			temp++;
	
	cout << temp << '\n' << MAX;
}

int find_parent(int child) {
	if (parent[child].first == -1) return child;
	return (parent[child].first = find_parent(parent[child].first));
}

void find_union(int line1, int line2) {
	int par1 = find_parent(line1);
	int par2 = find_parent(line2);
	
	if (par1 == par2) return;

	if (parent[par1].second >= parent[par2].second) {
		parent[par2].first = par1;
		find_parent(line2);
		parent[par1].second += parent[par2].second;

		MAX = max(MAX, parent[par1].second);
	}
	else {
		parent[par1].first = par2; 
		find_parent(line1);
		parent[par2].second += parent[par1].second;

		MAX = max(MAX, parent[par2].second);
	}
}