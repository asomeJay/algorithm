/* 전화번호 목록 */

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX 26

using namespace std;

struct TrieNode {
	bool terminal;
	TrieNode* children[MAX];

	TrieNode() : terminal(false) {
		memset(children, NULL, sizeof(children));
	}

	~TrieNode() {
		for (int i = 0; i < MAX; i++) {
			if (children[i]) {
				delete children[i];
			}
		}
	}

	int charToNum(const char ch) {
		return ch - '0';
	}

	void insert(const char* key) {
		if (*key == '\0') {
			this->terminal = true;
		}
		else {
			int next = charToNum(*key);
			// 노드가없으면 만들어라

			if (children[next] == NULL) {
				children[next] = new TrieNode();
			}

			children[next]->insert(key + 1);
		}
	}

	bool find(const char* key) {
		if (*key == '\0') return true;

		if (terminal) return false;

		int next = charToNum(*key);

		return children[next]->find(key + 1);
	}
};



int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;

	while (t--) {
		int n; cin >> n;
		bool is_valid = true;

		char phone_books[10000][11];

		TrieNode* root = new TrieNode();
		for (int i = 0; i < n; i++) {
			cin >> phone_books[i];
			root->insert(phone_books[i]);
		}

		for (int i = 0; i < n; i++) {
			if (root->find(phone_books[i]) == false) {
				is_valid = false;
				break;
			}
		}
		delete root;
		cout << (is_valid == true ? "YES" : "NO") << '\n';
	}
		return 0;
}