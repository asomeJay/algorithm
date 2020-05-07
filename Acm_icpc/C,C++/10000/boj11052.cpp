/* 카드 구매하기 */

#include <iostream>
#include <algorithm>

using namespace std;

int N; 
int card[1001], backpack[1001];


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> card[i];
	}

	backpack[1] = card[1];
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= i; j++)
			backpack[i] = max(backpack[i], backpack[j] + card[i - j]);
	}

	cout << backpack[N];

	return 0;
}