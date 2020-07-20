/* 파티 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define pp pair<int,int>
#define MAX 1000+1

using namespace std;

int n_of_student, n_of_road, target_student;
int x_to_student[MAX], student_to_x[MAX];
vector<int> dist;
bool is_visit[MAX];

vector<pp> edge[1000 + 1];

void input();
void solve();

int bfs(int st, int);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> n_of_student >> n_of_road >> target_student;
	for (int i = 0; i < n_of_road; i++) {
		int source_student, target_student, cost;
		cin >> source_student >> target_student >> cost;
		edge[source_student].push_back({ target_student, cost });
	}
}

int bfs(int st, int tt) {
	priority_queue<pp> pq;
	pq.push({ 0, st });
	fill(dist.begin(), dist.end(), 987654321);

	dist[st] = 0;
	while (!pq.empty()) {

		int current_node_number = pq.top().second;
		int current_node_distance = -1 * pq.top().first; // 가까운 순서대로 처리하거라
		pq.pop();
		if (current_node_number == tt) {
			return current_node_distance;
		}

		// 현재 최적거리보다 더 멀면 점검할 필요 없다.
		if (dist[current_node_number] < current_node_distance) continue;

		for (int i = 0; i < edge[current_node_number].size(); i++) {
			int next_node_distance = current_node_distance + edge[current_node_number][i].second;
			int next_node = edge[current_node_number][i].first;

			if (dist[next_node] > next_node_distance) {
				dist[next_node] = next_node_distance;
				pq.push({ -1 * next_node_distance, next_node });
			}
		}
	}
}

void solve() {

	dist.resize(n_of_student + 1);
	for (int i = 1; i <= n_of_student; i++) {
		if (i == target_student) continue;
		x_to_student[i] = bfs(target_student, i);
		student_to_x[i] = bfs(i, target_student);
	}	

	for (int i = 1; i <= n_of_student; i++) {
		x_to_student[i] += student_to_x[i];
	}

	sort(x_to_student, x_to_student + n_of_student + 1);
	cout << x_to_student[n_of_student] << '\n';

}