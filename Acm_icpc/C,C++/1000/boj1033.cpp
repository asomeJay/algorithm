/* 1033 칵테일 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX_N 11
#define pp pair<int,int>
#define EMPTY 0

using namespace std;

int N, result, dp[MAX_N], result_dp[MAX_N];
int ingredient[MAX_N][MAX_N];
bool is_visit[MAX_N];

int LCM(int a, int b);
int GCD(int a, int b);
void bfs();
void dfs(int start_point);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		ingredient[a][b] = c;
		ingredient[b][a] = d;
	}

	bfs();

	for (int i = 0; i < N; i++) 
		cout << result_dp[i] << " ";
	
	return 0;
}

int LCM(int a, int b) {
	return a * b / GCD(a, b) ;
}

int GCD(int a, int b) {
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}

	return a;
}
/*
void dfs(int now) {
	//그 노드의 최소공배수 집어넣기.
	int lcm = 0;
	for (int i = 0; i < N; i++) {
		if (ingredient[now][i] == 0) continue;
		if (lcm == 0)
			lcm = ingredient[now][i];
		else 
			lcm = LCM(lcm, ingredient[now][i]);
	}
	dp[now] =  lcm;

	bool flag = true;

	for(int i = 0; i <N; i++)
		if (!is_visit[i]) 
			flag = false;
		
	if (flag) { // 모든 노드를 점검했다면 
		int last_gcd = dp[0], temp_result;
		for (int i = 1; i < N; i++)
			last_gcd = GCD(last_gcd, dp[i]); // 그 노드들 사이의 최대공약수를 구한다. 

		temp_result = 0;
		for (int i = 0; i < N; i++) {
			dp[i] /= last_gcd;
			cout << dp[i] << " ";
			temp_result += dp[i];
		}

		cout << endl;
		if (temp_result > result) {
			result = temp_result;
			for (int i = 0; i < N; i++)
				result_dp[i] = dp[i];
		}

		return;
	}

	for (int i = 0; i < N; i++) {
		if (is_visit[i]) continue;
		is_visit[i] = true;
		dfs(i);
		is_visit[i] = false;
	}
}
*/

void bfs() {
	vector<int> index;
	int temporal_ingredient[MAX_N][MAX_N];

	index.resize(N);
	for (int i = 0; i < N; i++)
		index[i] = i;

	do {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				temporal_ingredient[i][j] = ingredient[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			int now = index[i];

			/* STEP 1 : 최소 공배수 등록하기 */
			int lcm = 0;
			for (int j = 0; j < N; j++) {
				if (temporal_ingredient[now][j] == 0) continue;
				if (lcm == 0)
					lcm = temporal_ingredient[now][j];
				else
					lcm = LCM(lcm, temporal_ingredient[now][j]);
			}
			
			dp[now] = lcm;

			/* STEP 2 : 최소공배수랑 연결된 Edge 업데이트 하기 */
			for (int j = 0; j < N; j++) {
				if (temporal_ingredient[now][j] == EMPTY)
					continue; 
				temporal_ingredient[j][now] *= (dp[now] / temporal_ingredient[now][j]);
			}
		}
		int now = index[0];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << temporal_ingredient[i][j] << " ";
			}
			cout << endl;
		}	

		for (int i = 0; i < N; i++)
			cout << dp[i] << " ";
		cout << endl;
		/* Step 3 : 전체 순회 끝났으면 그 값들의 최대공약수 구해서 각각 값 나누고 합 구하기 */

		int last_gcd = dp[0];
		for (int i = 1; i < N; i++)	
			last_gcd = GCD(last_gcd, dp[i]); // 그 노드들 사이의 최대공약수를 구한다. 

		int sum = 0;
		for (int i = 0; i < N; i++) {
			dp[i] /= last_gcd;
			sum += dp[i];
		}

		/* Step 4 : 합 */
		if (sum < result) {
			result = sum;
			for (int i = 0; i < N; i++) {
				result_dp[i] = dp[i];
			}
		}
	} while (next_permutation(index.begin(), index.end()));
}

	/* Step 3 : 전체 순회 끝났으면 그 값들의 최대공약수 구해서 각각 값 나누고 합 구하기 */




	/*
	vector<pp> now_ingredient[MAX_N];
	int now_dp[MAX_N];

	for (int i = 0; i < N; i++) {
		now_dp[i] = 0;
		now_ingredient[i].resize((int)ingredient[i].size());

		for (int j = 0; j < ingredient[i].size(); j++) {
			now_ingredient[i][j] = ingredient[i][j];
		}
	}
	
	queue<int> start;
	start.push(start_point);
	
	bool is_visit[MAX_N] = { false };
	is_visit[start_point] = true;

	while(!start.empty()) {
		int now = start.front(); 
			start.pop();

		int lcm = now_ingredient[now][0].second;
		int size = (int)now_ingredient[now].size();

		for (int i = 1; i < size; i++) 
			lcm = LCM(lcm, now_ingredient[now][i].second);
		
		// 이상으로 최소 공배수 구함.

		now_dp[now] = lcm;

		// 각 Out direcon Update
		for (int i = 0; i < size; i++) {
			pp now_edge;
			now_edge = now_ingredient[now][i];

			if (!is_visit[now_edge.first]) {
				is_visit[now_edge.first] = true;
				start.push(now_edge.first);
			}
			
			int multiplier = lcm / now_edge.second;

			int out_edged = now_edge.first;
			int sizez = (int)now_ingredient[out_edged].size();
			
			// 같은 거 찾는 과정 
			for (int j = 0; j < sizez; j++) {
				if (now_ingredient[out_edged][j].first == now) { // now랑 연결된 걸 찾았다.
					now_ingredient[out_edged][j].second *= multiplier;
					break;
				}
			}
		}
	}

	int sum = 0;
	cout << "??????????????????????????????\n";
	for (int i = 0; i < N; i++) {
		cout << dp[i] << " ";
		sum += now_dp[i];
	}
	cout << '\n';

	if (result < sum) {
		result = sum;
		for (int i = 0; i < N; i++) {
			dp[i] = now_dp[i];
		}
	}
}*/