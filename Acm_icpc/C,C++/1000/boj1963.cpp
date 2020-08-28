/* 소수 경로 */

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>

#define INTMAX 10000 + 1

using namespace std;

string a, b;
int check[INTMAX];
bool decimal[INTMAX];

void input();
void solve();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int ttt; cin >> ttt;

	for (int t_case = 0; t_case < ttt; t_case++) {
		memset(check, -1, sizeof(check));
		memset(decimal, true, sizeof(decimal));
		input();
		solve();
	}

	return 0;
}

void input() {
	cin >> a >> b;
}

void eratos() {
	decimal[1] = decimal[0] = false;

	for (int i = 2; i < INTMAX; i++) {
		if (decimal[i] == false)
			continue;

		for (int j = 2; i * j < INTMAX; j++) {
			decimal[i * j] = false;
		}
	}
}

void solve() {
	check[(int)stoi(a)] = 0;

	int depth = 0;
	eratos();

	queue<string> q;
	q.push(a);

	while (!q.empty()) {
		string cur = q.front();
		q.pop();
	
		for (int here = 0; here < 4; here++) {
			for (int to = 0; to < 10; to++) {
				string nxt = cur;
				nxt[here] = to + '0';

				if (nxt.compare(cur) == 0)
					continue;

				if (stoi(nxt) >= 1000 && check[stoi(nxt)] == -1 &&
					decimal[stoi(nxt)] == true) {
					check[stoi(nxt)] = check[stoi(cur)] + 1;

					q.push(nxt);
				}

			}
		}
	}

	cout << check[stoi(b)] << '\n';
}
