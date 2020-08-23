/* 우수 마을 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input();
void solve();

int N, weight[10000 + 1], Ans;
int treeDp[10000 + 1][2];

vector<int> house[10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	input();
	solve();

	return 0;
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> weight[i];

	for (int i = 1; i < N; i++) {
		int a, b; cin >> a >> b;

		house[a].push_back(b);
		house[b].push_back(a);
	}
}

int recur( int curr, bool include, int before) {
	int& ret = treeDp[curr][include];

	// 중복은 뺀다. 
	if (ret != 0) {
		return ret;
	}

	int summation = 0;
	// 현재 마을은 우수 마을이다.
	if (include) {
		summation += weight[curr];

	/* 현재 마을이 우수 마을이면 다음 마을은 무조건 우수마을이 아니다. */
		for (auto nxt_node : house[curr]) {
			if (nxt_node == before) continue;
			summation += recur( nxt_node, false, curr);
		}
	}
	
	// 현재 마을은 우수 마을이 아니다.
	else {
		for (auto nxt_node : house[curr]) {
			if (nxt_node == before) continue;

	/* 현재 마을이 우수 마을이 아닐 때, 다음 마을은 우수 마을일 수도 있고 아닐 수도 있다.*/
	/* 만약 우수 마을이 아닌 경우가 세 번 이상이면 어떡하는가, 질문이 나올 수도 있지만 
	   하나의 마을이라도 더 포함하는 게 주민 수를 늘리기 때문에 세 번 연속 우수마을이 아닌 경우보다
	   적어도 하나의 마을이 우수마을이 더 많은 주민을 포함하고, 정답이다.
	   그러므로 세 번 연속 우수마을이 아닌 경우를 따로 처리하는 로직을 넣지 않았다. 
	*/
			summation += max(recur(nxt_node, true, curr), recur(nxt_node, false, curr));
		}
	}

	return ret = summation;
}

 void solve() { 
	 // 첫번째 마을이 우수마을인 경우 vs 우수마을이 아닌 경우
	 Ans = max(recur(1, true, -1), recur(1, false, -1));

	 cout << Ans << '\n';
}

