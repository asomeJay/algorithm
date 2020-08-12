/* 역사 */

#include <iostream>
#include <vector>

#define MAX_N 400 + 1
#define MAX_EDGE 50000 + 1

using namespace std;

int n, k, s;
vector<int> edge[MAX_N];
int order[MAX_N][MAX_N];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	/* Input */
	cin >> n >> k;
	for (int i =1; i <= k; i++) {
		int a, b;
		cin >> a >> b;
		
		edge[a].push_back(b);	
		order[a][b] = -1;
		order[b][a] = 1;
	}

	/* 플로이드 워셜 */
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int m = 1; m <= n; m++) {
				if (order[j][i] == -1 && order[i][m] == -1) {
					order[j][m] = -1;
				}
				else if (order[j][i] == 1 && order[i][m] == 1) {
					order[j][m] = 1;
				}
			}
		}
	}

	/* Application */
	cin >> s;
	for (int i = 0; i < s; i++) {
		int a, b;
		cin >> a >> b;
		cout << order[a][b] << '\n';
	}

	return 0;
}

