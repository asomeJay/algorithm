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

	sort(one_two.begin(), one_two.end());
	sort(three_four.begin(), three_four.end(), comp);
	
/*	for (auto i : one_two) {
		cout << i << " ";
	} cout << endl;
	for (auto i : three_four) {
		cout << i << " ";
	} cout << endl;*/

	int l = 0, r = 0, cnt = 0;
	while (l != one_two.size() && r != three_four.size()) {
		int summation = one_two[l] + three_four[r];
		//cout << one_two[l] << " " << three_four[r] << " " << summation << '\n';
		if (summation > 0) {
			r++;
		}
		else if (summation < 0) {
			l ++;
		}
		else {
			int left = 1, right = 1;
			l++; r++;
			while (l != one_two.size() && one_two[l] == one_two[l - 1]) {
				left++;
			}
			while (r != three_four.size() && three_four[r] == three_four[r - 1]) {
				right++;
			}
			cnt += (left * right);
		}
	}

	while (l != one_two.size()) {
		if (one_two[l] == 0) {
			cnt++;
		}
		l++;
	}
	
	while (r != three_four.size()) {
		if (three_four[r] == 0) {
			cnt++;
		}
		r++;
	}

	cout << cnt << '\n';
	return 0;
}
