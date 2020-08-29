/* 버스 노선 */

#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int
#define pp pair<ll,ll>

using namespace std;

ll N, M;
bool is_visit[500000 + 1];
vector<pair<int, pp> > bus;

void input();
void solve();
inline bool comp(pair<int, pp> & a, pair<int, pp> & b) {
	if (a.second.second == b.second.second) {
		return a.second.first < b.second.first;
	}
	return a.second.second < b.second.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	solve();
	return 0;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		ll a, b; cin >> a >> b;
		if (a > b) 
			b += N;
		
		bus.push_back(make_pair(i, make_pair(a, b)));
	}

	for (int i = 0; i < M; i++) {
		bus.push_back(make_pair(i, make_pair(N + bus[i].second.first, N + bus[i].second.second)));
	}
}

void solve() {
	/* 끝 지점 기준으로 sort */
	sort(bus.begin(), bus.end(), comp);

	/* first point가 작으면 무조건 현재 것이 그것에 포함됨*/
	/* first point가 크더라도 second point가 같으면 포함됨 */
	/* second point가 크면 무조건 포함 안됨 */
	
	pair<int, pp> curr = bus[0];
	for (int i = 1; i < bus.size(); i++) {
		
		// 두 버스라인의 도착점이 같음
		if (curr.second.second == bus[i].second.second) {
			is_visit[bus[i].first] = true;
		}
		// 버스라인의 도착점이 현재 도착점보다 뒤임.
		else {
			// 새로운 버스라인의 시작점이 현재 시작점보다 더 앞이면
			// 현재 라인은 포함됨. 
			if (curr.second.first >= bus[i].second.first) {
				is_visit[curr.first] = true;
			}

			curr = bus[i];
		}
	}
	
	for (int i = 0; i < M; i++) {
		if (is_visit[bus[i].first] == false) {
			cout << bus[i].first + 1 << " ";
		}
	}
}