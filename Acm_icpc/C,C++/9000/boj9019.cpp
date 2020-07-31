/* DSLR */

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

void input();
void solve();

int A, B, ANS;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tt; cin >> tt;
	for (int i = 0; i < tt; i++) {
		input();
		solve();
	}
	return 0;
}

void input() {
	cin >> A >> B;
}

void solve() {
	queue<pair<int, string>> q;
	bool is_visit[10000 + 1] = { false, };

	int result, idx = 0;
	
	q.push({ A, "" });

	while (true) {
		int current = q.front().first;
		string current_instruction = q.front().second;

		q.pop();

		if (current == B) {
			cout << current_instruction << '\n';
			return;
		}

		result = (current * 2 > 9999 ? current * 2 % 10000 : current * 2);

		if (is_visit[result] == false) {
			is_visit[result] = true;
			q.push({ result, current_instruction + 'D' });
		}

		result = (current == 0 ? 9999 : current - 1);
		if(is_visit[result] == false){
			is_visit[result] = true;
			q.push({ result, current_instruction + 'S' });
		}

		result = (current % 1000) * 10 + current / 1000;
		if (is_visit[result] == false) {
			q.push({ result, current_instruction + 'L' });
			is_visit[result] = true;
		}

		result = current % 10 * 1000 + current / 10;
		if(is_visit[result] == false){
			q.push({ result, current_instruction + 'R' });
			is_visit[result] = true;
		}
	}
}
