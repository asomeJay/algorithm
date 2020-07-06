#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

vector<int> one_two, three_four;
inline bool comp(int a, int b) {
	return a > b;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	vector<int>one, two, three, four;
	one.resize(N); two.resize(N); three.resize(N); four.resize(N);
	
	for (int i = 0; i < N; i++) 
		cin >> one[i] >> two[i] >> three[i] >> four[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			one_two.push_back(one[i] + two[j]);
			three_four.push_back(three[i] + four[j]);
		}
	}

	sort(three_four.begin(), three_four.end());
	long ans = 0;
	vector<int>::iterator lo, up;
	for (int i = 0; i < one_two.size(); i++) {

		int l = lower_bound(three_four.begin(), three_four.end(), -1 * one_two[i]) - three_four.begin();
		int r = upper_bound(three_four.begin(), three_four.end(), -1 * one_two[i]) - three_four.begin();
		ans += (r - l);
	}
	cout << ans << '\n';
	return 0;
}
