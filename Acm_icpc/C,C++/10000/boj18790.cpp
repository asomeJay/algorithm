/* N�� ��� */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, cnt, for_n, dp[501] = { 0 }, ans_index;
int ans[1000];
int now[500];
vector<int> arr;

void dfs(int depth, int tar, int sum);
void ddfs(int depth, int index);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for_n = 2 * N - 1;

	arr.resize(for_n); 

	for (int i = 0; i < for_n; i++) {
		cin >> arr[i];
		/* ���� ���� N�� ������ �׳� �� ���ڰ� �����̴ϱ� ������� */
		if (dp[arr[i]] == N - 1) {
			for (int j = 0; j < N; j++) {
				cout << arr[i] << " ";
			}
			return 0;
		}
		dp[arr[i]]++;
	}
	
	if (N == 1) { // 1���� �׳� ����ϸ� ��. 
		cout << arr[0];
	}

	else {
		for (int i = 0; i < N; i++) {
			if (dp[i] != 0) { // 1�� : i N-1�� : N-i �Ӵϴ� 
				dp[i]--;		// i�� 0�� ���� N%N=0�̴ϱ� N-1���� 0!
				ans[ans_index++] = i;
				//ans.push_back(i);

				if (i == 0)
					dfs(N - 1, 0, i);
				else
					dfs(N - 1, N - i,i);

				dp[i]++;
				//ans.pop_back();
				ans_index--;
			}
		}
		cout << -1;
	}
	
	return 0;
}

void dfs(int depth, int tar, int sum) {
	if (depth == 1) {
		if (dp[tar] != 0) {
			//ans.push_back(tar);
			ans[ans_index++] = tar;

			if ((sum + tar) % N == 0) {
				//cout << "ASN";
				for (int i = 0; i < ans_index; i++) {
					cout << ans[i] << " ";
				}
				exit(0);
			}

			//ans.pop_back();
			ans_index--;
		}
		return;
	}

	for (int j = 0; j < N; j++) {
		for (int k = j; k < N; k++) {
			if ((j + k) % N == tar) {
				if (dp[k] > 0) {
					//ans.push_back(k);
					ans[ans_index++] = k;
					dp[k]--;

					dfs(depth - 1, j, sum + k);

					dp[k]++;
					//ans.pop_back();
					ans_index--;
				}
			}
		}
	}
}

void ddfs(int depth, int index) {
	if (depth == N) {
		for (int i = 0; i < N; i++) {
			if (now[i] % N == 0) {
				/* ��� ����ϰ� */

				exit(0);
			}
		}
		return;
	}

	for (int i = index; i < N; i++) {
		if (dp[i] == 0) continue;
		dp[i]--;
		for (int j = 0; j < N; j++) {

		}
	}

}