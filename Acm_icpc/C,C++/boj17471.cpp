/* 게리맨더링 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

#define MAX_N 11
#define VISIT 1
#define UNVISIT 0
#define NO 0
#define YES 1
#define SELECT 1
#define UNSELECT 0

using namespace std;

int ward[MAX_N]; // 선거구라는 뜻
int connect[MAX_N]; // 연결 여부를 파악할 변수
bool is_visit[MAX_N], connection; 
vector<int> selected_num; // 선택된 수
vector<int> adj[MAX_N];
vector<int>A, B;
int N, ans = 987654321;

void select_num(int cnt);
void connection_chk();
void init();
int dfs(int cnt, bool [MAX_N]);

bool comp(int a, int b) {
	return a > b;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int j, a, b;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> ward[i];

	for (int i = 1; i <= N; i++) {
		cin >> a;
		for (j = 1; j <= a; j++) {
			cin >> b;
			adj[i].push_back(b);
		}
	}

	selected_num.resize(N);
	
	int select_cnt = 1, a_sum, b_sum;

	while (select_cnt != N) {
		select_num(select_cnt);

		do {
			init();
			for (int i = 0; i < N; i++) {
				if (selected_num[i] == SELECT)
					A.push_back(i + 1);
				else
					B.push_back(i + 1);
			}

			a_sum = ward[A[1]]; b_sum = ward[B[1]];
			connection_chk();

			for (int i = 2; i < A.size(); i++) {
				a_sum += ward[A[i]];
				if (connect[A[i]] != connect[A[i - 1]])
					connection = false;
			}
			for (int i = 2; i < B.size(); i++) {
				b_sum += ward[B[i]];
				if (connect[B[i]] != connect[B[i - 1]])
					connection = false;
			}

			if (connection == true) 
				ans = min(ans, abs(b_sum - a_sum));

		} while (next_permutation(selected_num.begin(), selected_num.end(), comp));

		select_cnt++;
	}
	if (ans == 987654321)
		ans = -1;

	cout << ans;	
	return 0;
}

void init() {
	A.clear(); B.clear();
	A.push_back(0); B.push_back(0);
	connection = true;
	memset(connect, 0, sizeof(connect));
}

void connection_chk() {
	bool visit[MAX_N] = { false };
	int cnt = 1;
	for (int i = 1; i < B.size(); i++)
		visit[B[i]] = true;

	cnt = dfs(cnt, visit); 	

	memset(visit, false, sizeof(visit));
	for (int i = 1; i < A.size(); i++)
		visit[A[i]] = true;

	cnt = dfs(cnt, visit);
}

void select_num(int cnt) {
	for (int i = 0; i < cnt; i++) 
		selected_num[i] = 1;
	for (int i = cnt; i < N; i++)
		selected_num[i] = 0;
}

int dfs(int cnt, bool visit[MAX_N]) {
	
	stack<int> s;

	for (int i = 1; i <= N; i++) {
		if (connect[i] != 0 || visit[i] == true) continue;

		s.push(i);
		connect[i] = cnt;

		while (!s.empty()) {
			int t = s.top(); s.pop();
			for (int j = 0; j < adj[t].size(); j++) {
				if (connect[adj[t][j]] != 0) continue;
				if (visit[adj[t][j]] == true) continue;

				connect[adj[t][j]] = cnt;
				s.push(adj[t][j]);
			}
		}
		cnt++;
	}
	return cnt;
}