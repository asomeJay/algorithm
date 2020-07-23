/* Çà·Ä °ö¼À ¼ø¼­ */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500 + 1

using namespace std;

void input();
void solve();

long long int N, ANS;
bool is_visit[MAX];
pair<int, int> matrix[MAX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		matrix[i].first = a;
		matrix[i].second = b;
	}
}

void solve() {
	int size_of_N = N;
	while (--size_of_N) {
		int before = 0, after = 0, sum = 2000000000;
		int temp_sum = 0, temp_before = 0;

		for (int i = 0; i < N; i++) {
			if (is_visit[i] == false) {
				temp_before = i;
				break;
			}
		}
		
		for (int i = temp_before + 1; i < N; i++) {	
			if (is_visit[i] == false) {
				temp_sum = matrix[temp_before].first * matrix[temp_before].second * matrix[i].second;
				if (sum > temp_sum) {
					before = temp_before;
					after = i;
					sum = temp_sum;
				}
				temp_before = i;
			}
		}
		matrix[before].second = matrix[after].second;
		is_visit[after] = true;
		ANS += sum;
		
	}

	cout << ANS << '\n';
}
