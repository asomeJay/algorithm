/* IP¡÷º“ */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<long long int> ip;
int mask; 

bool comp(long long int a, long  long int b) {
	return a > b;
}

void input(int);
void solve(int);
void print(long long int target);

int main(void) {
	int tCase;
	cin >> tCase;

	
	input(tCase);
	solve(tCase);
	print(ip[0] & mask);
	print(mask);

	return 0;
}

void input(int t_case) {
	ip.resize(t_case);

	for (int i = 0; i < t_case; i++) {
		for (int j = 0; j < 4; j++) {
			int a;
			cin >> a;
			ip[i] <<= 8;
			ip[i] |= a;
			getchar();
		}
	}
}

void solve(int t_case) {
	sort(ip.begin(), ip.end());
	sort(ip.begin() + 1, ip.end(), comp);

	bool end;

	for (int i = 31; i >= 0; i--) {
		int bit = 1 << i;
		end = false;

		for (int j = 1; j < t_case; j++) {
			if ((ip[0] & bit) != (ip[j] & bit)) {
				end = true;
				break;
			}
		}
		
		if (end)
			break;
		else 
			mask |= bit;
	}
}

void print(long long int mask) {
	int shift = 24;
	for (int i = 0; i < 4; i++, shift -= 8) {
		cout << ((mask >> shift) & (1 << 8) -1 ) ;
		if (i != 3) cout << '.';
	}
	cout << '\n';
}