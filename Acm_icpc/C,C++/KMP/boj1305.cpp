/* ±¤°í */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pi;
vector<char> p;
int N, Ans; 

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	cin >> N;
	char c; p.resize(N);
	pi.resize(N);
	for (int i = 0; i < N; i++)
		cin >> p[i];
	
	for (int i = 1, j = 0; i < N; i++) {
		while (j != 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j]) {
			pi[i] = ++j;
			
		}
	}

	cout << N - pi[N-1];
	return 0;
}