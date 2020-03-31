/* °è´Ü ¼ö */

#include <iostream>
#include <string>

#define DIV 1000000000

using namespace std;

long long es[100 + 1][100 + 1][1 << 10];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= 9; i++) {
		es[1][i][1 << i] = 1;
	}

	int last = (1 << 10) - 1;

	int i, j, k;
	for (i = 2; i <= N; i++) {
		for (j = 0; j <= 9; j++) {
			for (k = 0; k <= last; k++) {
				if (j == 0) {
					es[i][j][k | (1 << j)] += es[i - 1][j + 1][k] % DIV ;
				}
				else if (j == 9) {
					es[i][j][k | (1 << j)] += es[i - 1][j - 1][k] %DIV;
				}
				else {
					es[i][j][k | (1 << j)] += ((es[i - 1][j - 1][k] % DIV) + (es[i - 1][j + 1][k] % DIV)) % DIV;
				}
			}
		}
		es[i][j][k | (1 << j)] %= DIV;
	}

	long long int ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += (es[N][i][last] % DIV);
		ans %= DIV;
	}
	cout << ans << '\n';
	return 0;
}