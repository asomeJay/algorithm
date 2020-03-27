/* °íÃþ ºôµù */

#include <iostream>

#define MAX_BUILDING 100 + 1
#define DEV 1000000007

using namespace std;

int N, L, R;
long long int building[MAX_BUILDING][MAX_BUILDING][MAX_BUILDING];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L >> R;
	building[1][1][1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= L; j++) {
			for (int k = 1; k <= R; k++) {
				building[i][j][k] +=
					(building[i - 1][j - 1][k] % DEV + building[i - 1][j][k - 1] % DEV +
					(building[i - 1][j][k] * (i - 2)) % DEV);

				building[i][j][k] %= DEV;
			}
		}
	}

	cout << building[N][L][R];

	
	return 0;
}