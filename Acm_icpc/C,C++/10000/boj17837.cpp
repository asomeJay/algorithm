/* 새로운 게임 */

#include <iostream>
#include <vector>
#include <algorithm>

#define W 0
#define R 1
#define B 2
#define R 1
#define L 2
#define U 3
#define D 4

using namespace std;

struct node {
	int row, col, dir, order;
	node() {
		;
	}
	node(int r, int c, int d, int o) {
		this->row = r;
		this->col = c;
		this->dir = d;
		this->order = o;
	}
};

int K, N;
int dr[5] = { 0,0,0,-1 ,1};
int dc[5] = { 0, 1, -1, 0, 0 };
int map[14][14];

//vector<pair<int, int>> token[14][14];
//vector<node> token_sort_by_order;
vector<node> token;
vector<pair<int,int>> parent_child;

int find_parent(int u);
int find_child(int u);
int unions(int v, int u);
void token_reverse()
void update();

void input();
void solve();
bool move_token(int, int, int, int, int);

int change_dir(int dir) {
	switch (dir) {
	case R: return L;
	case L: return R;
	case U: return D;
	case D: return U;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {

	cin >> N >> K;
	//token_sort_by_order.resize(K);
	parent_child.resize(K + 1, { -1, -1});

	for (int i = 0; i <= N + 1; i++) {
		map[0][i] = B;
		map[N + 1][i] = B;
		map[i][0] = B;
		map[i][N + 1] = B;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j]; 
		}
	}


	for (int i = 0; i < K; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		//token[a][b].push_back({ c, 0 });
		token.push_back({ a,b,c,i + 1 });
		//token_sort_by_order.push_back({ a, b, c, i + 1 });
		
	}
}

void solve() {
	int turn;
	for (turn = 1; turn <= 1000; turn++) {
		for (int order = 0; order < token.size(); order++) {
			
		}
	}

	if (turn == 1001)
		cout << "-1\n";

	return;
}

bool move_token(int t_index, int flag, int turn) {
	node& cur_tk = token[t_index];

	int nr = cur_tk.row + dr[cur_tk.dir];
	int nc = cur_tk.col + dc[cur_tk.dir];

	if (map[nr][nc] == B) {
		cur_tk.dir = change_dir(cur_tk.dir);
		if (flag == 0)
			return move_token(t_index, flag + 1, turn);
	}

	else if (map[nr][nc] == R) {
		reverse(token[nr][nc].begin(), token[nr][nc].end());

		token[r][c].clear();
		token[nr][nc][0].second = turn;
	} 
	else if (map[nr][nc] == W) {
		/* map */
		for (int i = 0; i < token[r][c].size(); i++) {
			token[nr][nc].push_back(token[r][c][i]);
		}
		token[r][c].clear();
		token[nr][nc][0].second = turn;
	
		/* token_order */

	}
	else {
		cout << "ERROR at MOVE\n";
	}

	if (token[nr][nc].size() >= 4) 
		return true;
	return false;
}

int find_parent(int u) {
	if (parent_child[u].first == -1) return u;
	else return parent_child[u].first = find_parent(parent_child[u].first);
}

int find_child(int u) {
	if (parent_child[u].second == -1) return u;
	else return parent_child[u].second = find_parent(parent_child[u].second);
}

int unions(int u, int v) {
	int pv = find_parent(v);
	int pu = find_parent(u);

	int cv = find_child(v);
	int cu = find_child(u);

	parent_child[pu].first = pv;
	parent_child[cv].second = cu;
}

