/* 주사위 윷놀이 */

#include <iostream>
#include <algorithm>

using namespace std;

int map[50], order[10], stakeholde[4];
int Ans;

void input();
void solve();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

// 10 --> 5, 오른쪽으로 가면 13 --> 21 밑으로 가면 5,6, 7...
// 25 -- > 24 위로 가면 25, 26(35)

// 20 --> 10. 오른쪽으로 가면 11, 12 위쪽으로 가면 27, 28(24)
// 30 --> 15. 위쪽으로 가면 16,17,18,19,20... 왼쪽으로 가면 30, 31 32(26)
void input() {
	for (int i = 0; i < 50; i++) {
		map[i] = i+1;
	}

	for (int i = 0; i < 10; i++) {
		cin >> order[i];
	}
	//10에서 오른쪽으로 간다 
	map[5] = 21;
	map[23] = 24;

	// 20에서 위로 간다
	map[10] = 27;
	map[28] = 24;

	// 30에서 외쪽으로 간다 
	map[15] = 30;
	map[32] = 24;

	map[26] = 40;
	map[40] = 45;

	map[32] = 32;
}

void dfs(int idx, int sum) {
	if (idx == 10) {
		Ans = max(Ans, sum);
		return;
	}

	if(stakeholder[0] )
	if(stakeholder[0])
	if(stakeholder[0])
	if(stakeholder[0])


}

void solve() {
		
}

