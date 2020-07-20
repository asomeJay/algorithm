/* �� ������Ʈ */

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

	history_of_visit[st].second = 1; // �̹� DFS���� �湮�� ������� üũ�Ѵ�. 
	history_of_visit[st].first = day; // ���� DFS���� �湮�� ������� üũ�Ѵ�. 
	
	while (!s.empty()) {
		int current_node = s.top();
		int current_node_weight = history_of_visit[current_node].second;
		s.pop();

		int next_node = pick_the_student[current_node];
	
		// ���� DFS���� �湮�ߴ�.
		if (history_of_visit[next_node].first != 0 && history_of_visit[next_node].first != day){ // �ٸ� DFS���� �湮�� �����
		
			return 0; // �� ����� ����
		}
	
		if (history_of_visit[next_node].first== day) {// �̹� DFS���� �湮�� ����� 
			current_node_weight = current_node_weight - history_of_visit[next_node].second + 1;
			return current_node_weight;
		}

		history_of_visit[next_node].first = day;
		history_of_visit[next_node].second = history_of_visit[current_node].second + 1;
		s.push(next_node);
	}
}

void solve() {
	// �� ��帶�� DFS�� ������ ���� ���ƿ� �� �ִ� �� üũ�Ѵ�. 
	int sum = 0, cnt = 1;
	for (int i = 1; i <=n_of_student; i++) {
		if (history_of_visit[i].first == false) {
			sum += dfs(i, cnt++);
		}
	}

	cout << n_of_student - sum << '\n';
}
