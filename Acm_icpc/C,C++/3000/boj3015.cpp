/* 3015 오아시스 재결합 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#define ll pair<long long int, long long int>

using namespace std;
long long N, ANS;
stack<ll> people;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		ll h = { a, 1 };

		while (!people.empty() && people.top().first <= h.first) {
			
			ANS += people.top().second;
			if (people.top().first == h.first) {
				h.second = people.top().second + 1;
			}
			else {
				h.second = 1;
			}
		
			people.pop();
		}

		if (!people.empty()) {
		//	cout << people.top().first << " " << h.first << endl;
			ANS++;
		}

		people.push(h);
	}

	cout << ANS << '\n';
	return 0;
}