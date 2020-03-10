/* ±³È¯ */

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int Ans = -2, N, K, s_size;
bool is_visit[1000001];

inline void swap(int a, int b, string &t);
void bfs();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	string s;
	s = to_string(N);
	s_size = s.size();

	if (s_size == 1 || (s_size == 2 && s[1] == '0')) {
		cout << -1;
		return 0;
	}

	bfs();

	cout << Ans;

	return 0;
}

inline void swap(int a, int b, string &t) {
	char c;
	c = t[a];
	t[a] = t[b];
	t[b] = c;
}

void bfs() {
	int cnt = 0;
	queue<int> q;

	q.push(N);
	is_visit[N] = true;
	while (!q.empty()) {
		//cout << "q.size : " << q.size() << endl;
		//cout << "cnt :  " << cnt << endl;
		int size = q.size();
		++cnt;
		memset(is_visit, false, sizeof (is_visit));

		for (int i = 0; i < size; i++) {
			int cur = q.front();
			q.pop();
			string tt = to_string(cur);

			for (int n = 0; n < s_size; n++) {
				for (int m = n + 1; m < s_size; m++) {
					string tmp = tt;
					if (n == 0 && tt[m] == '0') continue;
					swap(n, m, tmp);
					if (!is_visit[stoi(tmp)]) {
						is_visit[stoi(tmp)] = true;
						q.push(stoi(tmp));
						if (cnt == K) Ans = max(Ans, stoi(tmp));
					}
				}
			}
		}
		//cout << cnt << "vs" << K << endl;
		if (cnt == K) break;
	}
}