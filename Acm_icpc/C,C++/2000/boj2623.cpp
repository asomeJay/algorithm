#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int singer, pd;

vector<int> in_edge, pd_singer[1001];
int order[1001];

void input();
void solve();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> singer >> pd;

	in_edge.resize(singer + 1, 0);

	int before, temp;
	for (int i = 1; i <= pd; i++) {
		int n; cin >> n;
		for (int j = 0; j < n; j++) {
			if (j == 0) {
				cin >> before;
			}
			else {
				cin >> temp;
				pd_singer[before].push_back(temp);
				in_edge[temp]++;
				before = temp;
			}
		}
	}
}

void solve() {
	queue<int>q;
	for (int i = 1; i <= singer; i++) {
		if (in_edge[i] == 0) q.push(i);
	}
	for (int i = 1; i <= singer; i++) {
		if (q.empty()) {
			cout << 0 << '\n';
			exit(0);
		}

		int cur = q.front();  q.pop();
		order[i] = cur;
		/*cout << cur << " ";
		for (auto n : in_edge) {
			cout << n << " ";
		} cout << endl;*/
		for (int j = 0; j < pd_singer[cur].size(); j++) {
			in_edge[pd_singer[cur][j]]--;
			if (in_edge[pd_singer[cur][j]] == 0) {
				q.push(pd_singer[cur][j]);
			}
		}
	}

	for (int i = 1; i <= singer; i++) {
		cout << order[i] << '\n';
	}
	return;
}
