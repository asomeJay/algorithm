#include <iostream>

using namespace std;

int t_case;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int side; cin >> side;
	
		if (side % 4 == 0) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	
	return 0;
}