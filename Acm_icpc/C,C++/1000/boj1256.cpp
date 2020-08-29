/* ���� */

#include <iostream>
#include <algorithm>

#define ll long long int 

using namespace std;

void input();
void solve();

int N, M, K;
/* ��� j�� �ش��ϴ� ������ �迭�� 201�� �� �ʿ䰡 ������ 
���� �ڵ带 ���̱����� �����ߴ�. 
*/
ll arr[201][201];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
	return 0;
}

void input() {
	cin >> N >> M >> K;

	arr[1][0] = arr[1][1] = 1;
	
	// i�� ������ ����, j�� 'a'�� ����
	for (int i = 2; i <= 200; i++) {
		for(int j = 0; j <= i; j++){
			if (j == 0) {
				arr[i][j] = 1;
				continue;
			}
			arr[i][j] = min((ll)1e9 + 7, arr[i - 1][j] + arr[i - 1][j - 1]);
		}
	}
}

void recur(int n, int m, int k,int len) {
	if (len <= 0) return;
	if (n <= 0) {
		cout << 'z';
		recur(0, m - 1, k, len - 1);
	}
	else if (m <= 0) {
		cout << 'a';
		recur(n - 1, 0, k, len - 1);
	}
	else if ((arr[n - 1 + m][n - 1]) >= k) {
		cout << 'a';
		recur(n - 1, m, k, len - 1);
	}
	else {
		cout << 'z';
		recur(n, m - 1, k - arr[n + m - 1][n-1], len-1);
	}
}

void solve() {
	if (arr[N + M][N] < K) 
		cout << -1 << '\n';
	else 
		recur(N, M, K, N + M);

	return;
}