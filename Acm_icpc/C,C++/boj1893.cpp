/* 시저암호 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> fail, shift, problem;
string main_str, sub_str, problem_str;
int main_size, sub_size, problem_size;
int N;

void get_fail(int);
void init();
void input();
void print();
bool kmp(int);
void str_transform();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	while (N--){
		init();
		input();
		for (int j = 0; j < sub_size; j++) {
			fail.resize(main_size, 0);
			if (kmp(0) == true) shift.push_back(j);
			str_transform();
		}
		print();
	}

	return 0;
}

void init() {
	sub_str.clear(); main_str.clear(); problem_str;
	shift.clear(); problem.clear();
}

void input() {
	cin >> sub_str >> main_str >> problem_str;

	main_size = (int)main_str.size();
	sub_size = (int)sub_str.size();
	problem_size = (int)problem_str.size();
	problem.resize(problem_size);

	for (int i = 0; i < problem_size; i++) {
		for (int j = 0; j < sub_size; j++) {
			if (problem_str[i] == sub_str[j]) {
				problem[i] = j;
				break;
			}
		}
	}
}

bool kmp(int index) {
	int cnt = 0;
	get_fail(index);
	for (int i = 0, j = 0; i < problem_size; i++) {
		while (j > 0 && problem_str[i] != main_str[index + j])
			j = fail[j - 1];
		if (problem_str[i] == main_str[index + j]) {
			if (j == main_size - 1) {
				cnt++;
				j = fail[j];
			}
			else
				j++;
		}
	}
	return cnt == 1;
}

void get_fail(int index) {
	for (int i = 1, j = 0; i < main_size; i++) {
		while (j > 0 && main_str[index + i] != main_str[index + j])
			j = fail[j - 1];
		if (main_str[index + i] == main_str[index + j])
			fail[i] = ++j;
	}
}

void print() {
	switch ((int)shift.size()) {
	case 0:
		cout << "no solution\n";
		break;
	case 1:
		cout << "unique: " << shift[0] << '\n';
		break;
	default:
		cout << "ambiguous: ";
		sort(shift.begin(), shift.end());
		for (int i = 0; i < (int)shift.size(); i++) {
			cout << shift[i] << " ";
		}
		cout << '\n';
	}	
}

void str_transform() {
	for (int i = 0; i < problem_size; i++) {
		if (problem_str[i] == sub_str[0])
			problem[i] = sub_size - 1;
		else
			problem[i]--;
		
		problem_str[i] = sub_str[problem[i]];
	}
}