#include <iostream>
#include <string>
#include <algorithm>

#define ll long long int

using namespace std;

int L, U;

ll sum(ll n) {
	ll number[10] = { 0, };
	ll s = 1, result = 0;
	while (s <= n) {
		ll l = n / (s * 10);
		ll r = n % (s * 10);
	
		for (int i = 0; i < 10; i++) number[i] += l * s;
		for (int i = 0; i < r / s; i++) number[i] += s;
		number[r / s] += 1+ r % s;
		
		/*cout << "S : " << s << endl;
		for (int i = 1; i < 10; i++) {
			cout << number[i] << " ";
		}cout << endl;*/
		s *= 10;
	}

	for (int i = 1; i < 10; i++) {
		result += i * number[i];
		//cout << number[i] << " ";
	} //cout << endl;
	//cout << result << endl;
	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> L >> U;

	cout << sum(U) - sum(L-1) << '\n';

	
	return 0;
}