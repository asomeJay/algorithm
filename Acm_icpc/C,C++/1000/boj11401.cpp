/* 이항계수 3 */

#include <iostream>

#define ll long long int
#define THAT 1000000007
#define MAX 4000001
using namespace std;

ll arr[MAX];
ll inv[MAX];
ll N, K;

ll power(ll n, ll r);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K;
	arr[1] = 1;
	if (N == 1 || K == 0 || (N == K)) {
		cout << 1;
		return 0;
	}

	for (int i = 2; i < MAX; i++) 
		arr[i] = (arr[i - 1] * i) % THAT;
	inv[4000000] = power(arr[4000000], THAT - 2);
	for (int i = 4000000 - 1; i > 0; i--) {
		inv[i] = (inv[i + 1] * (i + 1)) % THAT;
	}
	
	ll ret = arr[N];
	ret = (ret * inv[K]) % THAT;
	ret = (ret * inv[N - K]) % THAT;

	cout << ret;

	return 0;
}

ll power(ll n, ll r) {
	ll ret = 1;
	while (r > 0) {
		if (r % 2) {
			ret *= n;
			ret %= THAT;
		}

		n *= n;
		n %= THAT;
		r /= 2;
	}
	return ret;
}