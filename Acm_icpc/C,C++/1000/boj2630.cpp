/* »öÁ¾ÀÌ */

#include <iostream>
#include <vector>

#define B 1
#define W 0
 
using namespace std;

int N, blue, white;
vector<vector<bool>> board;

bool chk(int sr, int sc, int er, int ec, bool);
void recursive_cut(int,int,int,int);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	board.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		board[i].resize(N + 1);
		for (int j = 1; j <= N; j++) {
			bool t;
			cin >> t;
			board[i][j] = t;
		}
	}


	recursive_cut(1, 1, N, N);
	cout << white << '\n' << blue;
	return 0;
}

bool chk(int sr, int sc, int er, int ec, bool color) {
	for (int i = sr; i <= er; i++) {
		for (int j = sc; j <= ec; j++) {
			if (board[i][j] != color)
				return false;
		}
	}
	return true;
}

void recursive_cut(int sr, int sc, int er, int ec) {
	//cout << sr << " " << sc << " " << er << " " << ec << '\n';
	//cout << white << " " << blue << '\n';
	int dist = (ec - sc - 1) / 2;

	if (chk(sr, sc, er, ec, W))
		white++;
	else if (chk(sr, sc, er, ec, B))
		blue++;
	else {
		recursive_cut(sr, sc, sr + dist, sc + dist);
		recursive_cut(sr, ec - dist, sr + dist, ec);
		recursive_cut(er - dist, sc, er, sc + dist );
		recursive_cut(er -dist, ec - dist, er, ec);
	}
}