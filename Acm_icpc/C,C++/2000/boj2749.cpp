/* 피보나치수 3*/

#include <iostream>

using namespace std;

const int mod = 1000000;
const int p = mod / 10 * 15;
int num[p] = { 0,1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long long int N;
	cin >> N;
	
	for (int i = 2; i < p; i++) {
		num[i] = num[i - 1] + num[i - 2];
		num[i] %= mod;
	}

	cout << num[N % p] << '\n';

	return 0;
}