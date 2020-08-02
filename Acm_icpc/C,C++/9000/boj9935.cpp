/* 문자열 폭발 */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string s, t;
char res[1000000 + 1];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> s >> t; 

	int s_length = s.length();
	int t_length = t.length();
	int idx = 0;
	bool flag;

	for (int i = 0; i <= s_length; i++) { // O(N) 의 시간 복잡도로 해결해야 하는 문제다.
		res[idx++] = s[i];

		if (res[idx - 1] == t[t_length - 1]) { // 방금 입력한 문자가 bomb 문자의 제일 마지막과 같다면
			// 역순으로 추적해나간다.
			flag = true;

			for (int trace = 0; trace < t_length - 1; trace++) {
				if (res[idx - t_length + trace] != t[trace]) { // 같지 않다면 bomb가 안됨
					flag = false;
					break;
				}
			}

			if (flag == true) { // Bomb!
				idx -= t_length;
			}
		}
	}

	if (strlen(res) == 0) {
		cout << "FRULA";
	}
	else {
		cout << res;
	}

	return 0;
}