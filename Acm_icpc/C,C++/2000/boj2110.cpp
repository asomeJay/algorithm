/* ������ ��ġ */

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

		if (cur_count < C) { // �Ÿ� ������ �ʹ� �����ؼ� ���ϴ� ��ŭ ��ġ���� ����
			right = mid - 1;
		}
		else { // �ش�Ǵ� �����Ⱑ �ʹ� ����. �Ÿ� ������ ��ȭ�ؾ� �Ѵ�. 
			answer = mid;
			left = mid + 1;
		}
	}

	cout << answer << '\n';

	return 0;
}
