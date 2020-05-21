/* 공유기 설치 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C, answer;
vector<int> house, maxi;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> C;
	house.resize(N); maxi.resize(C);

	for (int i = 0; i < N; i++) 
		cin >> house[i];

	sort(house.begin(), house.end());

	int left = 1; 
	int right = house[N - 1] - house[0];
	
	while (left <= right) {
		int mid = (left + right) / 2;
		int start = house[0];
		int cur_count = 1;

		for (int i = 1; i < N; i++) {
			int dist = house[i] - start;
			if (dist >= mid) {
				cur_count++;
				start = house[i];
			}
		}

		if (cur_count < C) { // 거리 기준이 너무 빡빡해서 원하는 만큼 설치하지 못함
			right = mid - 1;
		}
		else { // 해당되는 공유기가 너무 많다. 거리 기준을 강화해야 한다. 
			answer = mid;
			left = mid + 1;
		}
	}

	cout << answer << '\n';

	return 0;
}
