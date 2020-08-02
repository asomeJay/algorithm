/* ���ڿ� ���� */

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

	for (int i = 0; i <= s_length; i++) { // O(N) �� �ð� ���⵵�� �ذ��ؾ� �ϴ� ������.
		res[idx++] = s[i];

		if (res[idx - 1] == t[t_length - 1]) { // ��� �Է��� ���ڰ� bomb ������ ���� �������� ���ٸ�
			// �������� �����س�����.
			flag = true;

			for (int trace = 0; trace < t_length - 1; trace++) {
				if (res[idx - t_length + trace] != t[trace]) { // ���� �ʴٸ� bomb�� �ȵ�
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