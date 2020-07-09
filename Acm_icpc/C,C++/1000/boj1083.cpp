#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> A;
	cin >> N; A.resize(N);

	for (int i = 0; i < N; i++) 
		cin >> A[i];
	
	cin >> S;

	// N<=50 ÀÚ¿¬¼ö
	int cur = 0;
	while (cur < N && S) {
		if (A[cur] < A[cur + 1]) {
			swap(A[cur], A[cur + 1]);
			S--;
			int temp_cur = cur;
			while (temp_cur >= 1 && S) {
				if (A[temp_cur - 1] < A[temp_cur]) {
					swap(A[temp_cur], A[temp_cur - 1]);
					temp_cur--;
					S--;
				}
				else {
					break;
				}
			}
		}

		cur++;
	}

	for (auto i : A) {
		cout << i << " ";
	}
	return 0;
}