/* ã�� */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1) comp�� �ߺ��Ǵ� �迭�� ���Ѵ�.
// 2) kmp �Լ��� �����Ѵ�. 

vector<int> comp_str, ans;
string T, P;

void get_comp();
void kmp();

int main(void) {
	char c;
	while ((c = getchar()) != '\n') 
		T += c;

	while ((c = getchar()) != '\n') 
		P += c;

	kmp();

	cout << (int)ans.size() << '\n';
	for (auto n : ans)
		cout << n << " ";

	return 0;
}

void get_comp() {
	comp_str.resize((int)P.size(), 0);

	for (int i = 1 , j = 0; i < (int)P.size(); i++) {
		while (j > 0 && P[i] != P[j])
			j = comp_str[j - 1];
		if (P[i] == P[j])
			comp_str[i] = ++j;
	}
}

void kmp() {
	get_comp();

	for (int i = 0, j = 0; i < (int)T.size(); i++) {
		while (j > 0 && (T[i] != P[j]))
			j = comp_str[j - 1];
		if (T[i] == P[j]) {
			if (j == (int)P.size() - 1) {
				ans.push_back(i - j + 1);
				j = comp_str[j];
			}
			else
				j++;
		}
	}
}