/* 2342 : Dance Dance Revolution */

#include <iostream>

#define SAME 1
#define CENTER 2
#define ADJACENT 3
#define OPPOSITE 4

using namespace std;

pair<int, int> foot;

inline bool is_already(int);
inline bool is_middle();


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int input, power;

	foot.first = 0;
	foot.second = 0;
	power = 0;

	while (1) {
		cin >> input;
		if (input == 0)
			break;

		if (is_already(input)) { // already one foot is there
			power += SAME;
		}
		else if (is_middle()) { // at least one foot on the middle
			power += CENTER;
		}
		else { // adjacent
			power += ADJACENT;
		}
	}

	cout << power;
	
	return 0;
}

inline bool is_already(int number) {
	if (foot.first == number || foot.second == number)
		return true;
	return false;
}

inline bool is_middle() {
	if (foot.first == 0 || foot.second == 0)
		return true;
	return false;
}