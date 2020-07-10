#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t_case; cin >> t_case;

	for (int i = 0; i < t_case; i++) {
		int a, b, c;
		int A, B;
		cin >> a >> b >> c;

		double price_per_one = (double)c / b;
		if (a <= price_per_one) {
			B = -1;
			A = 1;
		}
		else {
			if (a >= c) {
				A = -1;
				B = b;
			}
			else {
				A = 1;
				B = b;
			}
		}
		cout << A << " " << B << '\n';
	}
	return 0;
}