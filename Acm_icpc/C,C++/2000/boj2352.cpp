/* 반도체 설계 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		if (arr.empty())
			arr.push_back(temp);
		else {
			int idx = lower_bound(arr.begin(), arr.end(), temp) - arr.begin();

			if (idx == arr.size()) {
				arr.push_back(temp);
			}
			else {
				arr[idx] = temp;
			}
		}
	}
	cout << arr.size();

	return 0;
}