/* Hashing */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

long long int r = 1, M = 1234567891;
long long int Ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int L;
	char c;
	cin >> L; 

	for (int i = 0; i < L; i++) {
		cin >> c;
		Ans = Ans + (c - 'a' + 1) * r;
		r *= 31; r %= M;
	}
	Ans %= M;
	
	cout << Ans;
	
	return 0;
}