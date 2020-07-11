/* 3015 오아시스 재결합 */

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
	// 이분탐색해서 제일 큰거 
	// 왼쪽 제일 큰거, 오른쪽 제일큰거 index 차이

}
