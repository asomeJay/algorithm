/* 3665 최종 순위 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<cstring>

#define MAX 500 + 1

using namespace std;

void init();
void input();
void solve();

int n_of_team, n_of_change;
bool win_loss_between_team[MAX][MAX];
int last_year_rank[MAX];
int num_of_in[MAX];
vector<int> answer;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t_case; cin >> t_case;
	for (int i = 0; i < t_case; i++) {
		init();
		input();
		solve();
	}

	return 0;
}

void init() {
	// rank 초기화
	memset(win_loss_between_team, false, sizeof(win_loss_between_team));
	memset(last_year_rank, 0, sizeof(last_year_rank));
	memset(num_of_in, 0, sizeof(num_of_in));
	answer.clear();
}

void input() {
	cin >> n_of_team;
	for (int i = 1; i <= n_of_team; i++)
		cin >> last_year_rank[i];

	for (int i = 1; i <= n_of_team; i++) {
		for (int j = i + 1; j <= n_of_team; j++) {
			win_loss_between_team[last_year_rank[i]][last_year_rank[j]] = true;
			num_of_in[last_year_rank[j]]++;
		}
	}

	cin >> n_of_change;
	for (int i = 0; i < n_of_change; i++) {
		int a, b; cin >> a >> b;
		if (win_loss_between_team[a][b] == false)
			swap(a, b);

		win_loss_between_team[a][b] = false;
		win_loss_between_team[b][a] = true;

		num_of_in[b]--;
		num_of_in[a]++;
	}
}

void solve() {
	int root;
	bool exist = false;
	queue<int> q;
	for (int i = 1; i <= n_of_team; i++) {
		if (num_of_in[i] == 0) {
			root = i;
			exist = true;
		}
	}

	if (exist == false) {
		cout << "IMPOSSIBLE" << '\n';
		return;
	}

	q.push(root);

	int sizes = n_of_team ;
	while (sizes--) {
		if (q.empty()) {
			cout << "IMPOSSIBLE" << '\n';
			return;
		}
		
		int cur_node = q.front();
		answer.push_back(cur_node);
		q.pop();

		if (!q.empty()) {
			cout << "?" << '\n';
			return;
		}

		for (int i = 1; i <= n_of_team; i++) {
			if (win_loss_between_team[cur_node][i] == true) {
				num_of_in[i]--;

				if (num_of_in[i] == 0) {
					q.push(i);
				}
			}
		}
	}	
	for (auto i : answer) {
		cout << i << " ";
	} cout << '\n';
}