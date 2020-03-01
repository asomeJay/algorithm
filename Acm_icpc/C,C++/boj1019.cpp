/* å ������ */

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int N, digit_of_N;

int digit();
int num[10];
long long int page_per_digit[11] = { 0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000, 10000000000 };
long long int square[12] = { 0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	digit_of_N = digit();
	
	int n = N, cur_digit = digit_of_N;

	string t = to_string(N);

	for (int i = 0; i < t.size(); i++, cur_digit--) {
		int current = t[i] - '0';

		for (int j = 0; j < 10; j++) {
			// ������ ���ڰ� �� �� �־����� �ľ��ϸ� ������ ������ų �� �ִ�. 
	
			num[j] += (page_per_digit[cur_digit - 1] * (current));
			if (cur_digit == digit_of_N && j == 0) continue;

			if (j < current) {
				num[j] += square[cur_digit]; // ���� �ڸ����� ������
			}
			else if (j == current) {
				num[j] = num[j] + (N - (current * square[cur_digit]) + 1);
			}
		}
		N %= square[cur_digit];
	}
	for(int i = 0; i < digit_of_N; i++)
		num[0] -= square[i];
	for (int i = 0; i <= 9; i++) 
		cout << num[i] << " "; 
	
	return 0;
}
/* �ڸ��� ���ϴ� �Լ� */
int digit() {
	string s = to_string(N);
	return s.size();
}