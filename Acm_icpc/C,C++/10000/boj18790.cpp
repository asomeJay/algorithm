/* N의 배수 */

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
		/* 같은 숫자 N번 들어오면 그냥 그 숫자가 정답이니까 출력하자 */
		if (dp[arr[i]] == N - 1) {
			for (int j = 0; j < N; j++) {
				cout << arr[i] << " ";
			}
			return 0;
		}
		dp[arr[i]]++;
	}
	
	if (N == 1) { // 1개면 그냥 출력하면 됨. 
		cout << arr[0];
	}

	else {
		for (int i = 0; i < N; i++) {
			if (dp[i] != 0) { // 1개 : i N-1개 : N-i 임니당 
				dp[i]--;		// i가 0일 때는 N%N=0이니까 N-1개도 0!
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
				/* 결과 출력하고 */

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