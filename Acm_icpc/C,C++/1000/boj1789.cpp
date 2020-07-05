#include <iostream>

using namespace std;

long S;

int main(void) {
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	cin >> S;
	long l = 0, r = S, ANS = 0;

	while (l <= r) {
		long mid = (l + r) / 2;
		long sum = mid * (mid + 1) / 2;
		if (sum > S) {
			r = mid - 1;
		}
		else {
			ANS = mid;
			l = mid + 1;
		}
	}
	cout << ANS << '\n';
	return 0;
}