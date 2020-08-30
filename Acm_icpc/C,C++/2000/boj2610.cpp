/* ȸ���غ� */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define ll long long int
#define pp pair<ll,ll>
#define INF 2100000000

using namespace std;

void input();
void solve();

int N, M;
bool is_visit[101];
vector<ll> answer;
ll dp[110][110];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	fill(&dp[0][0], &dp[110 - 1][110], INF);
	
	input(); solve();
	return 0;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		dp[a][b] = 1;
		dp[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		dp[i][i] = 0;
	}
	return;
}

void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dp[i][j] > dp[i][k] + dp[k][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}

	return;
}

void representation() {

	queue<int> q;

	for (int i = 1; i <= N; i++) {
		// �̹� �湮�� ���� �ٸ� �׷쿡 ���������� �н�. 
		if (is_visit[i] == true) continue;

		// ���� �湮���� �ʾ����� ���ο� �׷��� ������ �� �ִ�. 
		is_visit[i] = true;

		q.push(i);
		// maxi�� ���� �׷��� �ּڰ�, idx�� �� �ּڰ��� ��ȣ
		ll maxi = INF, idx = i;

		while (!q.empty()) {
			//t_maxi�� ���� ����� �ִ�
			// �� �ִ񰪵� �� �ּڰ��� ���ϴ� �� �� ������ �ٽ�
			ll curr = q.front(), t_maxi = 0;
			q.pop();

			// �̰ɷ� ���� ��尡 �� �� �ִ� ��� weight�� ���Ѵ�. 
			for (int j = 1; j <= N; j++) {
				// ���� ���� ������ ������� �ʾƵ� �ȴ�.
				if (j == curr) continue;

				// ���� �湮���� ���� ���� ���� ���� ����Ǿ� �ִ� �����
				if (dp[curr][j] != INF && is_visit[j] == false) {
					// �湮üũ�ϰ� ť�� �����Ѵ�. 
					is_visit[j] = true;
					q.push(j);
				}

				// �湮���ο� ������� ���� ���(curr)�� ����� ��� weight �� �ִ��� ã�´�.
				if (dp[curr][j] != INF) {
					t_maxi = max(t_maxi, dp[curr][j]);
				}
			}
			
			// t_maxi �� ���� ����� ������ ���� ū ���̴�. �� ����� ���� �׷��� �ּڰ��̶�� �ּڰ��� ��ü�Ѵ�. 
			if (t_maxi < maxi) {
				maxi = t_maxi;
				idx = curr;
			}
		}

		// ���� �׷��� �ּڰ� Index�� �����Ѵ�. 
		answer.push_back(idx);
	}

	return;
}

void solve() {
	// �ϴ� �� ������ �� �������� �ִ� �Ÿ��� ���Ѵ�. 
	// �׷��� ����� ���� INF�� �ƴϰ����� ������ ���� INF�� �ȴ�/
	floyd();
	//���� ���� ������ ��ǥ�� ���Ѵ�.
	representation();
	cout << answer.size() << '\n';
	sort(answer.begin(), answer.end());
	for (auto i : answer) {
		cout << i << '\n';
	}
	return;
}