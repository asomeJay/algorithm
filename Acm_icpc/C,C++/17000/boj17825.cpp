/* �ֻ��� ������ */

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

// 10 --> 5, ���������� ���� 13 --> 21 ������ ���� 5,6, 7...
// 25 -- > 24 ���� ���� 25, 26(35)

// 20 --> 10. ���������� ���� 11, 12 �������� ���� 27, 28(24)
// 30 --> 15. �������� ���� 16,17,18,19,20... �������� ���� 30, 31 32(26)
void input() {
	for (int i = 0; i < 50; i++) {
		map[i] = i+1;
	}

	for (int i = 0; i < 10; i++) {
		cin >> order[i];
	}
	//10���� ���������� ���� 
	map[5] = 21;
	map[23] = 24;

	// 20���� ���� ����
	map[10] = 27;
	map[28] = 24;

	// 30���� �������� ���� 
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

