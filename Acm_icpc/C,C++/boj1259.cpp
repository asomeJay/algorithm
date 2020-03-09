/* Æç¸°µå·Ò¼ö */

#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	while (s.compare("0") != 0) {
		int size = (int)s.size(), i;
		for (i = 0; i < size / 2; i++) {
			if (s[i] != s[size - 1 - i])
				break;
		}
		if (i == size / 2)
			cout << "yes\n";
		else
			cout << "no\n";
		s.clear();
		cin >> s;
	}

	return 0;
}