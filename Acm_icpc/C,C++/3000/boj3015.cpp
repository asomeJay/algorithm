/* 3015 ���ƽý� ����� */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
vector<int> people;

void solve();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N; people.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> people[i];
	}

	solve();
	return 0;
}


void solve() {
	// �̺�Ž���ؼ� ���� ū�� 
	// ���� ���� ū��, ������ ����ū�� index ����

}
