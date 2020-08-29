/* ���� �뼱 */

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
	/* �� ���� �������� sort */
	sort(bus.begin(), bus.end(), comp);

	/* first point�� ������ ������ ���� ���� �װͿ� ���Ե�*/
	/* first point�� ũ���� second point�� ������ ���Ե� */
	/* second point�� ũ�� ������ ���� �ȵ� */
	
	pair<int, pp> curr = bus[0];
	for (int i = 1; i < bus.size(); i++) {
		
		// �� ���������� �������� ����
		if (curr.second.second == bus[i].second.second) {
			is_visit[bus[i].first] = true;
		}
		// ���������� �������� ���� ���������� ����.
		else {
			// ���ο� ���������� �������� ���� ���������� �� ���̸�
			// ���� ������ ���Ե�. 
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