/* �ܾ� ���� */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long int maxi;
int max_size, N, cnt;
bool is_used[10];
vector<string> s;
vector<pair<char,long long int>>alphabet;
vector<char> first_alphabet;

long long int string_change(string a);
void alpha(string);
void b_track(int st_index, int depth);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	s.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> s[i];
		max_size = max(max_size, (int)s[i].size());
		// ���ڿ� �� ���� �� ���̰� ������ �˾Ƴ��ϴ�. 

		alpha(s[i]);	// INput���� ���� String�� ���� Alphabet�� �����մϴ�.
	}
		// ���� �� ���ڿ� ���� �Ҵ��� �����Դϴ�. 
	// ���� ū ���� �������� 9���� �Ҵ��ϴ� �� �ǽ��ϴ�.
	for (int i = 9; i > 9 - (int)alphabet.size(); i--) { // �Ʊ� ������ max_size�Դϴ�
		// ���� max_size�� 5�̴�. �� ���� �� ���ڿ��� ���̰� 5���
		// 9 8 7 6 5 ������ ���� ���̹Ƿ� 9 - max_size�� ������ϴ�. 
		alphabet[0].second = i;	// ���������� ���� �Ҵ��ϴ� �����Դϴ�. 
		is_used[i] = true;	// �ٸ� ���ڰ� ���� ���� ������ ���� ������ϹǷ� �ߺ��� üũ�մϴ�.
		b_track(1, 1);		// �� ���� ���ڿ� ���� �Ҵ��� ���Դϴ�. 
		is_used[i] = false;	// �ѹ��� recursion�� �������� �� �������� �Ѿ���մϴ�
							// ���󺹱� �����ݴϴ�. 
	}

	cout << maxi;
	return 0;
}

void alpha(string a) {
	int i;
	/* Input���� ���� �ٸ��� ���ڸ� �����ؼ� �����մϴ�.
	���� �̹� �����ִ� ���ڶ�� ���������ʽ��ϴ�. 
	�� �Լ��� ������ Input���� ���� ��� ������ ������ ����˴ϴ�.
	���� ��� AAA BBC�� ������ alphabet�� {A , 0} {B, 0} {C,0}�� ����˴ϴ�.*/
	for (auto n : a) {
		for (i = 0; i < (int)alphabet.size(); i++) {
			if (alphabet[i].first == n) break;
		}
		if (i == alphabet.size()) {
			alphabet.push_back({ n, 0 });
		}
	}

	/* ���� Input���� ���� string�� ���̰� 2�̻��̸� ���� �տ� 0�� ���� ���� ���ٰ�
	�����߽��ϴ�. (0�� ���͵� �Ǵ� ���� �����ص� Ʋ�Ƚ��ϴٰ� �߱⶧����...)
	�׷��Ƿ� string�� ���̰� 2�̻��̸� ���� �� ���ڸ� �����߽��ϴ�. 
	first_alphabet�� ���̴� ������ 10�̱� ������ �ߺ�üũ�� �����ʾҽ��ϴ�. */
	if ((int)a.size() >= 2) 
		first_alphabet.push_back(a[0]);
}

void b_track(int st_index,int depth) {
	/* depth�� alphabet vector�� ������� ���ٸ� ��� ���ĺ��� ���� �Ҵ�� ��Ȳ�Դϴ�.
	�׷��Ƿ� ���� �� ���ڿ� �Ҵ�� ���� ���߾ �� String ������ �������� �� �� �̵��� ���ϰ�
	�� ���� ���� ���������� ���� ū ������ ���մϴ�.
	ū ���̶�� �����ϰ� ū ���� �ƴ϶�� �����ϴ�. */
	if (depth == (int)alphabet.size()) {
		
		long long int tep = 0;
		for (auto n : s) 
			tep += string_change(n);
		
		if (maxi < tep) 
			maxi = tep;
		
		return;
	}

	int j = 0;
	for (int i = 9; i > (9 - (int)alphabet.size()); i--) {
		if (is_used[i] == true) continue;	//�̹� �� ���Դϴ�. �ߺ��Ҵ����� �ʽ��ϴ�. 
		/*if (i == 0) { // ���� i�� 0�̶��, ���ڿ��� ���� �տ� ������ �ȵ˴ϴ�. 
						//�̸� �˻��ϴ� ��Ʈ�Դϴ�. 
			for (j = 0; j < (int)first_alphabet.size(); j++) { //first_alphabet�� ��ȸ�ϸ鼭 
				// ���� alphabet�� ù��° ���ĺ����� üũ�մϴ�.
				// ���� ù��° alphabet�̶�� 0�� �Ҵ��ؼ��� �ȵǰ�, 0�� �Ҵ��ؼ��� �ȵȴٴ� ����
				// �� ���̽��� ������ �� �� ���ٴ� �ǹ��Դϴ�. 
				// �׷��Ƿ� ���� ������ �� �� ������ return ��ŵ�ϴ�. 
				if (alphabet[st_index].first == first_alphabet[j]) {
					return;
				}
			}
		}*/
		is_used[i] = true;
		alphabet[st_index].second = i;
		b_track(st_index + 1, depth + 1);
		is_used[i] = false;
	}

}

long long int string_change(string a) {

	/* ���ĺ��� �Ҵ�� ���� ���缭 �������� �����ݴϴ�. */
	long long int temp = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		for (auto n : alphabet) {
			if (n.first == a[i]) {
				temp *= 10;
				temp += n.second;
				break;
			}
		}
	}
	return temp;
}


/*cout << "alphabet ::: " << endl;
for (long long int i = 0; i < alphabet.size(); i++) {
	cout << alphabet[i].first << " " << alphabet[i].second << endl;
	cnt++;
		cout << "alphabet ::: " << endl;
		for (long long int i = 0; i < alphabet.size(); i++) {
			cout << alphabet[i].first << " " << alphabet[i].second << endl;
		}
}*/

//cout << "max_size : " << max_size << endl;
	//cout << "alpha : " << alphabet.size() << endl;
		//cout << "i:" << i << endl;
		//cout << "is_used[i] : " << is_used[i] << endl;

/*cout << "AT FINAL ::: " << endl;
			long long int tt = 0;
			for (auto n : s) {
				cout << n << endl;
				cout << string_change(n) << endl;
			}
			for (long long int i = 0; i < alphabet.size(); i++) {
				cout << alphabet[i].first << " " << alphabet[i].second << endl;
			}*/

			//cout << endl;
				//cout << alphabet.size() << endl;
				//for (auto n : alphabet) {
				//	cout << n.first << " " << n.second << endl;
				//}
				//cout << depth << " " << alphabet.size() << endl;