/* ���ڿ� ���� */

#include <iostream>
#include <string>

using namespace std;

struct trieNode {
	bool is_terminal;
	trieNode* trie[26];

	trieNode() {
		is_terminal = false;
		for (int i = 0; i < 26; i++) {
			trie[i] = NULL;
		}
	}

	void insert(const char* alphabet) {
		// �̹� ���ĺ��� string�� ������ �̶�� 
		if ((*alphabet) == '\0') {
			// SetIsTerminal(false);
			is_terminal = true;
			return;
		}
		if(trie[(*alphabet)-'a'] == NULL)
			trie[(*alphabet) - 'a'] = new trieNode();

		return trie[(*alphabet)-'a']->insert(alphabet + 1);
	}

	bool find(const char* alphabet) {
		// ���� ���� ������ alphabet�̰�is_terminal �Ǿ�������
		if ((*alphabet) == '\0') {
			return (is_terminal == true ? true : false);
		}

		if (trie[(*alphabet) - 'a'] == NULL) 
			return false;

		return trie[(*alphabet) - 'a' ]->find(alphabet + 1);
	}

};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	trieNode * S = new trieNode();

	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		S->insert(s.c_str());
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		string s; cin >> s;
		if (S->find(s.c_str()) == true) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}