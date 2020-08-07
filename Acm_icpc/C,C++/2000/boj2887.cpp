/* 행성터널 */

#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>


#define ll long long int 
#define MAX_N 100000 + 1

using namespace std;

class planet {
public:
	int x, y, z;
	planet(int a, int b, int c) {
		x = a; y = b; z = c;
	}
};

int N;
pair<int, int> xx[MAX_N], yy[MAX_N], zz[MAX_N];
int parent[MAX_N];

ll dist(planet a, planet b) {
	return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
}

inline bool comp(pair<int,int> & a, pair<int,int> & b) {
	return a.first > b.first;
}

int find_parent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find_parent(parent[x]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N; 
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		xx[i] = make_pair(a, i);
		yy[i] = make_pair(b, i);
		zz[i] = make_pair(c, i);

		parent[i] = i;
	}

	sort(xx, xx + N, comp); sort(yy, yy + N, comp); sort(zz, zz + N, comp);

	priority_queue<pair<int, pair<int,int>>> pq;
	for (int i = 1; i < N; i++) {
		pq.push({ -(abs(xx[i].first - xx[i - 1].first)), {xx[i].second, xx[i-1].second} });
		pq.push({ -(abs(yy[i].first - yy[i - 1].first)), {yy[i].second, yy[i-1].second} });
		pq.push({ -(abs(zz[i].first - zz[i - 1].first)), {zz[i].second, zz[i-1].second} });
	}
	int summation = 0; N--;
	while (N) {
		int cur_dist = -pq.top().first;
		int cur_idx1 = pq.top().second.first; 
		int cur_idx2 = pq.top().second.second;

		pq.pop();

		int par1 = find_parent(cur_idx1); 
		int par2 = find_parent(cur_idx2);
		
		if (par1 == par2) continue;
		parent[par1] = par2;
		summation += cur_dist;
		N--;
	}

	cout << summation;
	return 0;
}