/* 백준 9576 : 책 나눠주기 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX_PARENT 1001
#define p pair<int,int>

using namespace std;

int N, M, t_case, cnt;
vector<p> user;
bool book[MAX_PARENT];

void solve();

inline bool comp(p a, p b) {
	if (a.second != b.second)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main(void) {
	cin >> t_case;

	for (int ii = 0; ii < t_case; ii++){
		cnt = 0;
		cin >> N >> M;
		user.clear();
		memset(book, false, sizeof(book));

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
	for (int i = 0; i < M; i++) {
		for (int j = user[i].first; j <= user[i].second; j++) {
			if (!book[j]) {
				book[j] = true;
				cnt++;
				break;
			}
		}
	}
}
