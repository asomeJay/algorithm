/* °³¹Ì±¼ */

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void input();
void solve();

int N;
struct trieNode {
	bool is_terminal;
	map<string, trieNode*> trie;

	trieNode() {
		is_terminal = false;
		trie.clear();
	}

	void insert(vector<string> vs, int idx) {
		if (idx == vs.size()) {
			this->is_terminal = true;
			return;
		}

		if (trie.count(vs[idx]) == 0) {
			trie.insert(make_pair(vs[idx], new trieNode()));
		}

		trie.find(vs[idx])->second->insert(vs, idx + 1);
		return;
	}

	void iter(int depth) {
		for (auto iterator : trie) {
			for (int i = 0; i < depth; i++) 
				cout << "-";
			
			cout << iterator.first << '\n';;
			iterator.second->iter(depth + 2);
		}
	}
};

trieNode* root = new trieNode();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	solve();

	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int m; cin >> m;
		vector<string> v_s;
		for (int i = 0; i < m; i++) {
			string s; cin >> s;
			v_s.push_back(s);
		}

		root->insert(v_s, 0);
	}
}

void solve() {
	root->iter(0);
}