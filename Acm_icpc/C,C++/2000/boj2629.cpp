/* 양팔 저울 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n_of_sinker, n_of_ball;
int sinker[30], s_of_sinker[30 + 1][40000 + 1];

/* 두 개를 더하거나, 두 개를 빼거나, 하나를 반대쪽에 놔두기 */
/* 일단 케이스를 생각해보는거야! */

void recursive(int cur, int hab) {
	if (cur > n_of_sinker) return;
	if (s_of_sinker[cur][hab] == true) return;

	s_of_sinker[cur][hab] = true;

	// 두 개를 더하기
	recursive(cur + 1, hab + sinker[cur]);
	recursive(cur + 1, hab);
	recursive(cur + 1, abs(hab - sinker[cur]));
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	/* Input */
	cin >> n_of_sinker;
	for (int i = 0; i < n_of_sinker; cin >> sinker[i++]);

	recursive(0, 0);

	cin >> n_of_ball;
	for (int i = 0; i < n_of_ball; i++) {
		int target; cin >> target;
		int j;
		for (j = 0; j <= n_of_sinker; j++) {
			if (s_of_sinker[j][target] == true) break;
		}

		if (j > n_of_sinker) cout << "N ";
		else cout << "Y ";
	}

	return 0;
}