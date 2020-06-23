#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int

using namespace std;

bool comp(ll a, ll b) {
	return a > b;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t_case; cin >> t_case;

	for (int i = 0; i < t_case; i++) {
		int n, k; cin >> n >> k;
		vector<ll> integer(n), give_to_friend(k);
		
		for (int j = 0; j < n; j++) 
			cin >> integer[j];	
		for (int j = 0; j < k; j++) 
			cin >> give_to_friend[j];
		
		sort(integer.begin(), integer.end());
		sort(give_to_friend.begin(), give_to_friend.end(), comp);

		ll summation = 0;
		int left = 0, right = integer.size() - 1;
		int give_right = give_to_friend.size() - 1;

		while (give_right >= 0 && give_to_friend[give_right] == 1) {
			give_right--;
			summation += (integer[right] * 2);
			right--;
		}

		for (int j = 0; j <= give_right; j++) {
			summation += integer[left];
			left += (give_to_friend[j]-1);
			summation += integer[right];
			right--;
		}
	
		cout << summation << '\n';
	}
	
	return 0;
}