/* ÇÉº¼ °ÔÀÓ */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_MAP 100 + 2
#define N 0
#define E 1
#define S 2
#define W 3
#define EMPTY 0

using namespace std;

int N_map, Ans = 0;
int map[MAX_MAP][MAX_MAP];
int dp[MAX_MAP][MAX_MAP][4];
vector<pair<int, int>> worm_hall[5];
const int dr[4] = { -1,0,1,0 };
const int dc[4] = { 0, 1, 0,-1 };

void init();
void input();
bool is_range(int r, int c);
pair<int,int> into_the_hall(int,int);
int hit_the_wall(int,int,int);

void dfs(int r, int c, int dir);
inline int dir_change(int dir);
void wall();
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t_case;
	cin >> t_case;

	for (int x = 1; x <= t_case; x++) {
		input();
		wall();

		for (int i = 1; i <= N_map; i++) {
			for (int j = 1; j <= N_map; j++) {
				for (int k = 0; k < 4; k++) {

					if (map[i][j] == 0) {
						dfs(i, j, k);
					}
				}
			}
		}
		cout << "#" << x << " " << Ans << '\n';
		init();
	}

	return 0;
}

void init() {
	Ans = 0;
	for (int i = 0; i < 5; i++) {
		worm_hall[i].clear();
	}
	for (int i = 1; i <= N_map; i++) {
		for (int j = 1; j <= N_map; j++) {
			for (int k = 0; k < 4; k++) {
				dp[i][j][k] = 0;
			}
		}
	}
}

void input() {
	cin >> N_map;
	for (int i = 1; i <= N_map; i++) {
		for (int j = 1; j <= N_map; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 6 && map[i][j] <= 10) {
				worm_hall[map[i][j] - 6].push_back({ i,j });
			}
		}
	}
}

bool is_range(int r, int c) {
	return r >= 1 && r <= N_map && c >= 1 && c <= N_map;
}

inline int dir_change(int dir) {
	switch (dir) {
	case N:
		return S;
	case E:
		return W;
	case W:
		return E;
	case S:
		return N;
	}
}

void dfs(int r, int c, int dir) {
	int tr, tc, tdir, tcnt;
	tr = r; tc = c; tdir = dir; tcnt = 0;

	while (true) {
		
		tr += dr[tdir];
		tc += dc[tdir];

		if ((tr == r && tc == c) || map[tr][tc] == -1) {
			Ans = max(Ans, tcnt);
			return;
		}
			
		if (map[tr][tc] == EMPTY)
			dp[tr][tc][tdir] = tcnt;

		if (map[tr][tc] != EMPTY) {
			if (map[tr][tc] >= 1 && map[tr][tc] <= 5) { //  ºí·°¿¡ ºÎµúÈû
				tdir = hit_the_wall(tr, tc, tdir);
				tcnt++;
			}
			if (map[tr][tc] >= 6 && map[tr][tc] <= 10) { // ¿úÈ¦ ÀÌµ¿
				pair<int, int> a;
				a = into_the_hall(tr, tc);
				tr = a.first;
				tc = a.second;
			}
		}		
	}
}

int hit_the_wall(int r, int c, int dir) {
	switch (map[r][c]) {
	case 1:
		if (dir == N || dir == E)
			dir = dir_change(dir);
		else if (dir == W)
			dir = N;
		else if (dir == S)
			dir = E;
		break;
	case 2:
		if (dir == S || dir == E)
			dir = dir_change(dir);
		else if (dir == N)
			dir = E;
		else if (dir == W)
			dir = S;
		break;
	case 3:
		if (dir == S || dir == W)
			dir = dir_change(dir);
		else if (dir == N)
			dir = W;
		else if (dir == E)
			dir = S;
		break;
	case 4:
		if (dir == N || dir == W)
			dir = dir_change(dir);
		else if (dir == E)
			dir = N;
		else if (dir == S)
			dir = W;
		break;
	case 5:
		dir = dir_change(dir);
		break;
	}
	return dir;
}

pair<int,int> into_the_hall(int r, int c) {
	// ¿úÈ¦ µé¾î°¡´Â ÄÉÀÌ½º 
	int tr, tc;
	switch (map[r][c]) {
	case 6:
		if (r == worm_hall[0][0].first && c == worm_hall[0][0].second) {
			tr = worm_hall[0][1].first;
			tc = worm_hall[0][1].second;
		}
		else {
			tr = worm_hall[0][0].first;
			tc = worm_hall[0][0].second;
		}
		break;
	case 7:
		if (r == worm_hall[1][0].first && c == worm_hall[1][0].second) {
			tr = worm_hall[1][1].first;
			tc = worm_hall[1][1].second;
		}
		else {
			tr = worm_hall[1][0].first;
			tc = worm_hall[1][0].second;
		}
		break;
	case 8:
		if (r == worm_hall[2][0].first && c == worm_hall[2][0].second) {
			tr = worm_hall[2][1].first;
			tc = worm_hall[2][1].second;
		}
		else {
			tr = worm_hall[2][0].first;
			tc = worm_hall[2][0].second;
		}
		break;
	case 9:
		if (r == worm_hall[3][0].first && c == worm_hall[3][0].second) {
			tr = worm_hall[3][1].first;
			tc = worm_hall[3][1].second;
		}
		else {
			tr = worm_hall[3][0].first;
			tc = worm_hall[3][0].second;
		}
		break;
	case 10:
		if (r == worm_hall[4][0].first && c == worm_hall[4][0].second) {
			tr = worm_hall[4][1].first;
			tc = worm_hall[4][1].second;
		}
		else {
			tr = worm_hall[4][0].first;
			tc = worm_hall[4][0].second;
		}
		break;
	}
	return { tr,tc };
}

void wall() {
	for (int i = 0; i <= N_map + 1; i++) {
		map[0][i] = map[N_map + 1][i] = 5;
		map[i][0] = map[i][N_map + 1] = 5;
	}
}