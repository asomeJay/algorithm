/* ปýลยวะ */

#include <iostream>
#include <map>
#include<string>

using namespace std;

map<string, double> frequent;
int total;

void input();
void solve();


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {

	while (true) {
		string s; getline(cin, s);

		if (s.empty()) break;
		total++;

		if (frequent.find(s) == frequent.end() ) {
			frequent.insert({ s,1 });
		}
		else {
			frequent.find(s)->second++;
		}
	}
}

void solve() {
	cout << fixed; cout.precision(4);
	for (auto & entry : frequent) {
		entry.second = entry.second / (double)total * 100;

		cout << entry.first << " " << entry.second << '\n';
	}
	return;
}