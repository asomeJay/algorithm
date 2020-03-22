/* º¼·Ï ²®Áú */

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

#define pa pair<int,int>
#define ll long long int

using namespace std;

class node {
public:
	ll x, y;
	ll p, q;
};

ll N;
vector<node> block;

ll ccw(node a, node b, node c);
inline bool comp(node &a, node &b) {
	if (a.y == b.y) 
		return a.x < b.x;
	return a.y < b.y;
}

inline bool angle(node &a, node &b) {
	ll cc = ccw(block[0], a, b);
	if (cc != 0) return cc > 0;
	return (a.x + a.y) < (b.x + b.y);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N; 
	block.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> block[i].x >> block[i].y;
	}
	sort(block.begin(), block.end(), comp);

	//for (int i = 1; i < N; i++) {
	//	block[i].p = block[i].x - block[0].x;
	//	block[i].q = block[i].y - block[0].y;
	//}
	sort(block.begin() + 1, block.end(), angle);

	stack<ll> s;
	ll prev, now, next = 2;
	s.push(0);
	s.push(1);

	while (next < N) {
		while (s.size() >= 2) {
			now = s.top(); s.pop();
			prev = s.top();

			if (ccw(block[prev], block[now], block[next]) > 0) {
				s.push(now);
				break;
			}
		}
		s.push(next++);
	}
		
	cout << s.size() << '\n';

	return 0;
}

ll ccw(node a, node b, node c) {
	return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (c.x - a.x) * (b.y - a.y);

}