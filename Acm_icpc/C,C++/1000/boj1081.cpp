#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int L, U;
long number[10];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> L >> U;

	int cur = 0;
	string s_L = to_string(L);
	string s_U = to_string(U);

	while (cur != s_L.size()){
		if (s_L[cur] == s_U[cur]) {
			string t_L = s_L.substr(cur);
			string t_U = s_U.substr(cur);
			number[s_L[cur] - '0'] += (stoi(t_L) - stoi(t_U));
		}
		else {

		}
		
	}
	
	return 0;
}