/* 플로이드 */

#include <iostream>
#include <algorithm>

#define MAX_MAP 100+ 1
#define INF 987654321

using namespace std;

int N, M;
int map[MAX_MAP][MAX_MAP];

void init();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	init(); 

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		map[a][b] = min(map[a][b], c);
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == INF) cout << 0 << " ";
			else cout << map[i][j] << " ";
		} cout << '\n';
	}

	return 0;
}

void init() {
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			map[i][j] = INF;
			if (i == j) map[i][j] = 0;
		}
	}


}