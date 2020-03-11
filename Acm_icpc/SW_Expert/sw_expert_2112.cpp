/* 보호 필름 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define A 0
#define B 1
#define MAX_WIDTH 20 + 1
#define MAX_THICK 13 + 1
#define PASS 1

using namespace std;

bool protective_film[MAX_THICK][MAX_WIDTH];
int width, thickness, accept_criteria, n_of_medications;

bool performance_test();
void input();
inline void init();
void medication_management(int count, int index, bool[MAX_THICK][MAX_WIDTH]);
void medication_administration(int number, bool);
void medication_recovery(int index, bool[MAX_THICK][MAX_WIDTH], bool[MAX_THICK][MAX_WIDTH]);

int main(void) {
	int t_case;
	cin >> t_case;

	for (int tt = 1; tt <= t_case; tt++) {
		init();
		input();

		medication_management(0, 1, protective_film);

		cout << "#" << tt << " " << n_of_medications << '\n';
	}
	return 0;
}

bool performance_test() {
	if (accept_criteria == 1)
		return PASS;
	int row, col, cnt;
	bool flag;
	for (col = 1; col <= width; col++) {
		cnt = 1;
		flag = false;

		for (row = 2; row <= thickness; row++) {
			if (protective_film[row][col] == protective_film[row - 1][col]) {
				cnt++;
				if (cnt == accept_criteria) {
					flag = true;
					break;
				}
			}
			else {
				cnt = 1;
			}
		}

		if (flag == false)
			return false;
	}
	return PASS;
}

void init() {
	memset(protective_film, false, sizeof protective_film);
	n_of_medications = 987654321;
}

void input() {
	scanf("%d %d %d", &thickness, &width, &accept_criteria);
	//cin >> thickness >> width >> accept_criteria;
	for (int i = 1; i <= thickness; i++) {
		for (int j = 1; j <= width; j++) {
			cin >> protective_film[i][j];
		}
	}
}

void medication_management(int count, int index, bool film[MAX_THICK][MAX_WIDTH]) {
	if (count == n_of_medications)
		return;
	if (performance_test() == PASS) {
		n_of_medications = min(n_of_medications, count);
		return;
	}
	if (count == thickness)
		return;

	bool save[MAX_THICK][MAX_WIDTH];
	for (int i = index; i <= thickness; i++) {
		medication_recovery(i, save, film);

		for (int color = 0; color <= 1; color++) {

			medication_administration(i, color);
			medication_management(count + 1, i + 1, film);
			medication_recovery(i, film, save);
		}
	}
}

void medication_administration(int number, bool type) {
	for (int i = 1; i <= width; i++) {
		protective_film[number][i] = type;
	}
}

void medication_recovery(int index, bool target[MAX_THICK][MAX_WIDTH], bool save[MAX_THICK][MAX_WIDTH]) {
	for (int i = 1; i <= width; i++)
		target[index][i] = save[index][i];
}