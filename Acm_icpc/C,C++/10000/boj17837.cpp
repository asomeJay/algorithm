/* 새로운 게임 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define WHITE 0
#define RED 1
#define BLUE 2
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

vector<int> token_map[14][14];
vector<node> token_order;

void input();
void solve();
bool token_move(int, int, int);

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

	for (int i = 0; i <= N + 1; i++) {
		map[0][i] = BLUE;
		map[N + 1][i] = BLUE;
		map[i][0] = BLUE;
		map[i][N + 1] = BLUE;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j]; 
		}
	}

	token_order.push_back({ 0,0,0,0 });

	for (int i = 1; i <= K; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		token_map[a][b].push_back(i);
		token_order.push_back({ a,b,c, i});
	}
}

void solve() {
	int turn;
	for (turn = 1; turn <= 1000; turn++) {
		for (int i = 1; i <= K; i++) {
			if (token_move(i, 0, turn)) {
				cout << turn << '\n';
				return;
			}
		}
	}

	if (turn == 1001)
		cout << "-1\n";

	return;
}

bool token_move(int t_index, int flag, int turn) {
	node& cur_tk = token_order[t_index];
	stack<int> temp;

	int i;
	int cr = cur_tk.row;
	int cc = cur_tk.col;
	int nr = cur_tk.row + dr[cur_tk.dir];
	int nc = cur_tk.col + dc[cur_tk.dir];

	if (map[nr][nc] == BLUE) {
		if (flag == 1)
			return false;
		token_order[t_index].dir = change_dir(token_order[t_index].dir);
		if (flag == 0)
			return token_move(t_index, 1, turn);
	}

	else if (map[nr][nc] == RED) {
		i = token_map[cr][cc].size() - 1;

		while (token_map[cr][cc][i] != t_index) {
			int c_index = token_map[cr][cc][i];

			token_map[nr][nc].push_back(c_index);
			token_order[c_index].row = nr;
			token_order[c_index].col = nc;
			
			token_map[cr][cc].pop_back();
			i--;
		}

		token_map[nr][nc].push_back(t_index);
		token_map[cr][cc].pop_back();

		token_order[t_index].row = nr;
		token_order[t_index].col = nc;
	} 
	else if (map[nr][nc] == WHITE) {
		i = token_map[cr][cc].size() - 1;

		while (token_map[cr][cc][i] != t_index) {
			int c_index = token_map[cr][cc][i];

			temp.push(c_index);
			token_order[c_index].row = nr;
			token_order[c_index].col = nc;

			token_map[cr][cc].pop_back();
			i--;
		}

		temp.push(t_index);
		
		token_map[cr][cc].pop_back();

		token_order[t_index].row = nr;
		token_order[t_index].col = nc;

		while (!temp.empty()) {
			token_map[nr][nc].push_back(temp.top());
			temp.pop();
		}
	}

	else {
		cout << "ERROR at MOVE\n";
	}

	if (token_map[nr][nc].size() >= 4) 
		return true;
	return false;
}