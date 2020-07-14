/* º¹¸é»ê */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define ll long long int

using namespace std;

vector<int> alphabet_pos;
int alphabet_value[40];
string a, b, c;
bool is_used[10];
bool alphabet_used[40];

void alphabet_assign(string s);
ll alphabet_to_int(string s);
void dfs(int);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> a >> b >> c;

	alphabet_assign(a);
	alphabet_assign(b);
	alphabet_assign(c);

	for (int i = 0; i < 40; i++) {
		if (alphabet_used[i]) {
			alphabet_pos.push_back(i);
		}
	}

	if (alphabet_pos.size() <= 10) {
		dfs(0);
	}
	
	cout << "NO";
	
	return 0;
}

void alphabet_assign(string s) {
	for (int i = 0; i < s.size(); i++) {
		alphabet_used[s[i] - 'A'] = true;
	}
}

ll alphabet_to_int(string s) {
	ll sum = 0;
	for (int i = 0; i < s.length(); i++) {
		sum *= 10;
		sum += alphabet_value[s[i] - 'A'];
	}

	return sum;
}

void dfs(int cur) {
/*	for (auto i = alphabet_value.begin(); i != alphabet_value.end(); i++) {
		cout << i->first << " " << i->second << endl;
	}*/
	if (cur == alphabet_pos.size()) {
		if (alphabet_to_int(c) == alphabet_to_int(a) + alphabet_to_int(b)) {
			cout << "YES";
			exit(0);
		}
		return;
	}
	
	int idx = alphabet_pos[cur];
	for (int i = 0; i < 10; i++) {
		if (is_used[i] == false) {
			is_used[i] = true;
			alphabet_value[idx] = i;
			dfs(cur + 1);
			alphabet_value[idx] = -1;
			is_used[i] = false;
		}
	}
}

