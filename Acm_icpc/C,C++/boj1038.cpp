/* �����ϴ� �� */

#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX_ARR 15

using namespace std;

int arr[15];
int N;
// 1�� ���ڸ�
// 2�� ��ȩ�ڸ� 
// 3�� �����ڸ�
// 4�� �ϰ��ڸ�
// 5�� �����ڸ� 
//1, 5, 15, 35, 70, 126 �ټ��ڸ�
//1, 4, 10, 20, 35, 56, 84 ���ڸ�
//1, 3, 6, 10, 15, 21, 28, 36 ���ڸ� 
//1, 2, 3 ,4, 5 , 6, 7, 8, 9 ���ڸ� 
//1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ���ڸ� 
// 10, 45, 120
// 98 7654 3210

void dp();
int dp_p, Dp[20];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N; 
	if (N <= 10)
		cout << N;
	else if (N > 1022)
		cout << -1;
	else
		dp();
	
	return 0;
	
}

void dp() {
	int ac = 0, k = 1, size = MAX_ARR;
	while (ac != N + 1) {
	
		for (k = size; k < MAX_ARR; k++) {
			if (arr[k] >= arr[k - 1]) break;
		}

		if (k == MAX_ARR) {
			ac++;
			if (arr[MAX_ARR - 1] == 9) {
				int t;
				for (t = MAX_ARR - 1; t >= size; t--) {
					if (arr[t] == 9) {
						arr[t] = 0;
						arr[t - 1]++;
					}
				}
				if (t < size)
					size--;
			}
			else {
				arr[MAX_ARR - 1]++;

			}
		}

		else {
			if (arr[k - 1] == 9) {
				int t;
				for (t = k - 1; t >= size; t--) {
					if (arr[t] == 9) {
						arr[t] = 0;
						arr[t - 1]++;
					}
				}
				if (t < size)
					size--;
			}
			else {
				arr[k - 1]++;
				for (; k < MAX_ARR; k++)
					arr[k] = 0;
			}
				
		}


	}
	arr[MAX_ARR - 1]--;
	
	for (k = 0; arr[k] == 0; k++);
	for (; k < MAX_ARR; k++)
		printf("%d", arr[k]);
}