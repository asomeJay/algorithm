/* 텀 프로젝트 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void input();
void solve();
void init();

int t_case, n_of_student;
vector<int> pick_the_student;
vector<pair<int, int>> history_of_visit;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t_case;

	for (int i = 0; i < t_case; i++) {
		init();
		input();
		solve();
	}


	return 0;
}

void init() {
	pick_the_student.clear();
	history_of_visit.clear();
}

void input() {
	cin >> n_of_student;
	pick_the_student.resize(n_of_student + 1);
	history_of_visit.resize(n_of_student + 1, { 0, 0 });

	for (int i = 1; i <= n_of_student; i++) {
		cin >> pick_the_student[i];
	}
}

int dfs(int st, int day) {
	stack<int> s;
	s.push(st);

	history_of_visit[st].second = 1; // 이번 DFS에서 방문한 노드인지 체크한다. 
	history_of_visit[st].first = day; // 이전 DFS에서 방문한 노드인지 체크한다. 
	
	while (!s.empty()) {
		int current_node = s.top();
		int current_node_weight = history_of_visit[current_node].second;
		s.pop();

		int next_node = pick_the_student[current_node];
	
		// 이전 DFS에서 방문했다.
		if (history_of_visit[next_node].first != 0 && history_of_visit[next_node].first != day){ // 다른 DFS에서 방문한 노드라면
		
			return 0; // 팀 만들기 실패
		}
	
		if (history_of_visit[next_node].first== day) {// 이번 DFS에서 방문된 노드라면 
			current_node_weight = current_node_weight - history_of_visit[next_node].second + 1;
			return current_node_weight;
		}

		history_of_visit[next_node].first = day;
		history_of_visit[next_node].second = history_of_visit[current_node].second + 1;
		s.push(next_node);
	}
}

void solve() {
	// 각 노드마다 DFS를 돌려서 나로 돌아올 수 있는 지 체크한다. 
	int sum = 0, cnt = 1;
	for (int i = 1; i <=n_of_student; i++) {
		if (history_of_visit[i].first == false) {
			sum += dfs(i, cnt++);
		}
	}

	cout << n_of_student - sum << '\n';
}
