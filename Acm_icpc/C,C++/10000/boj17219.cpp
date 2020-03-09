/* 비밀번호 찾기 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	string pr, pt;
	vector<pair<string, string>> list[200];
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> pr >> pt;
		list[pr[0]].push_back({ pr, pt });
	}

	for (int i = 0; i < M; i++) {
		string p;
		cin >> p;
		for (int j = 0; j < list[p[0]].size(); j++) {
			if (list[p[0]][j].first.compare(p) == 0) {
				cout << list[p[0]][j].second << '\n';
				break;
			}	
		}
	}

	return 0;
}