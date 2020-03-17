/* ÆÓ¸°µå·Ò? */

#include <iostream>

#define MAX 2001

using namespace std;

bool dp[MAX][MAX];
int number[MAX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num, question;
	cin >> num ;
	number[0] = -1;
	for (int i = 1; i <= num; i++)
		cin >> number[i];

	for (int i = 1; i <= num; i++) {
		dp[i][i] = true;
		if (number[i] == number[i - 1]) {
			dp[i][i - 1] = true;
			dp[i - 1][i] = true;
		}
			
	}

	for (int i = 2; i < num; i++) {
		for (int j = 1; j <= num - i; j++) {
			if (number[j] == number[j + i]) {
				if (dp[j + 1][j + i - 1] == true) {
					dp[j][j + i] = true;
				}
					
			}
		}
	}

	cin >> question;

	for (int i = 0; i < question; i++) {
		int a, b;
		cin >> a >> b;
		cout << dp[a][b] << '\n';
	}

	return 0;
}