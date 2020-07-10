/* 백준 9576 : 책 나눠주기 */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_PARENT 1001
#define p pair<int,int>

using namespace std;

int N, M, t_case, cnt;
vector<p> user;
vector<bool> book;

void solve();

inline bool comp(p a, p b) {
	if (a.second != b.second)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t_case;

	for (int ii = 0; ii < t_case; ii++){
		cnt = 0;
		cin >> N >> M;
		book.resize(MAX_PARENT, false);

		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			user.push_back({ a,b });
			
		}
		sort(user.begin(), user.end(), comp);
		
		solve();
	/*	for (auto i : user) {
			cout << i.first << " " << i.second << '\n';
		}*/
		
		cout << cnt << '\n';
	}
	return 0;
}

void solve() {
	for (auto i : user) {
		for (int j = i.first; j <= i.second; j++) {
			if (!book[j]) {
				book[j] = true;
				cnt++;
				break;
			}
		}
	}
}
