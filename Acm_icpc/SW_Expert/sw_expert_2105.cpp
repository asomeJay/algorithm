/* ����Ʈ ī�� */
#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_CAFE 25
#define MAX_ROTATE 4
#define MAX_DESSERT 101
#define LEFT_DOWN 3
#define RIGHT_DOWN 2
#define LEFT_UP 0
#define RIGHT_UP 1
#define NOT 5
#define OUT_OF_RANGE 0
#define IN_RANGE 1

using namespace std;

int r[4] = {-1,-1,1,1 };
int c[4] = {-1, 1, 1, -1 };
int haved_dessert[MAX_DESSERT];
int haved_dir[MAX_ROTATE];
int dessert_cafe[MAX_CAFE][MAX_CAFE];
int maxi, N;

/* �Ű������� ���� ������ �ݴ������ return ���ش�. */
int opposite_dir(int dir);
/* �Ű������� ���� row�� column ���� �������� ���� �� ���� üũ�Ѵ�. */
bool is_range(int r, int c);
/* �� �׽�Ʈ�� �� ������ �迭�� �ʱ�ȭ����� �Ѵ�.*/
void init();
/* �̰� ���� �� �Լ��� */
void dfs(int s_r, int s_c, int c_r, int c_c, int dir, int cur_cnt);
/* ���� ����Ʈ���� üũ�ϱ� 
    ���� ����Ʈ�� true, �ٸ��� false�� return �Ѵ�. */
bool same_dessert(int a_r, int a_c, int b_r, int b_c);

int main(void) {
	int t; cin >> t;
	int i, j, k;
	for (k = 1; k <= t; k++) {
		init();
		cin >> N;
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				cin >> dessert_cafe[i][j];
			}
		}


		/* LEFT_DOWN���� ���� ���̽��� ������� ���̴�. ������ ���� ���Ƽ�
		�������� ���ƿ��� �� ã�°ǵ� "�� LEFT_DOWN�� �����! RIGHT_DOWN�� ����ؾ���
		"��� �ϸ� "���� �׷��� ���ҰŴ�"��� ����ϰ� �ʹ�.*/

		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				/* ���� ��� �ֵ��� üũ�� �ʿ䰡 ����~~ */
				if (is_range(i + r[3], j + c[3]) == OUT_OF_RANGE) continue;
				/* ���� ����Ʈ�̸� ������ �ʿ䵵 ���� ~~ */
				if (same_dessert(i, j, i + r[3], j + c[3])) continue;

				/* �� ������ ����~ ����ϰ�, �� ����Ʈ �Ծ���~ �����Ѵ� */
				haved_dir[LEFT_DOWN] = 1;
				haved_dessert[dessert_cafe[i][j]] = 1;
				haved_dessert[dessert_cafe[i + r[LEFT_DOWN]][j + c[LEFT_DOWN]]] = 1;

				dfs(i, j, i + r[LEFT_DOWN], j + c[LEFT_DOWN], LEFT_DOWN, 2);

				/* �� ����� ����Ʈ�� ���� dfs�� �Ϸ�������
				���󺹱��� ����� �ٸ� �ֵ��� �� ����� �� ����Ʈ�� ���� */

				haved_dir[LEFT_DOWN] = 0;
				haved_dessert[dessert_cafe[i][j]] = 0;
				haved_dessert[dessert_cafe[i + r[LEFT_DOWN]][j + c[LEFT_DOWN]]] = 0;
			}
		}
		cout << "#" << k << " " << maxi << endl;
	}

	return 0;
}

int opposite_dir(int dir) {
	if (dir == LEFT_DOWN) return RIGHT_UP;
	if (dir == RIGHT_DOWN) return LEFT_UP;
	if (dir == LEFT_UP) return RIGHT_DOWN;
	if (dir == RIGHT_UP) return LEFT_DOWN;
}

bool is_range(int r, int c) {
	if (r <= 0 || r > N || c <= 0 || c > N) return OUT_OF_RANGE;
	return IN_RANGE;
}

void dfs(int s_r, int s_c, int c_r, int c_c, int dir, int cur_cnt) {
	if (c_r == s_r && c_c == s_c) {
		maxi = max(cur_cnt, maxi);
		return;
	}

	int i, n_r, n_c, dessert;

	for (i = 0; i < 4; i++) {
		/* ���� ��������� ���ݴ�� �� �ʿ䰡 �����ϱ�. */
		if (i == opposite_dir(dir)) continue;
		if (i != dir && haved_dir[i] == 1) continue;

		n_r = c_r + r[i];
		n_c = c_c + c[i];
		if (is_range(n_r, n_c) == OUT_OF_RANGE) continue;

		dessert = dessert_cafe[n_r][n_c]; // �ش� ĭ�� ����Ʈ ������ �����ΰ�!

		if (n_r == s_r && n_c == s_c) dfs(s_r, s_c, n_r, n_c, i, cur_cnt);

		if (haved_dessert[dessert]) continue;

		haved_dir[i] = 1;
		haved_dessert[dessert] = 1;
		dfs(s_r, s_c, n_r, n_c, i, cur_cnt + 1);
		haved_dir[i] = 0;
		haved_dessert[dessert] = 0;
	}
}

void init() {
	fill(haved_dessert, haved_dessert + MAX_DESSERT, 0);
	fill(haved_dir, haved_dir + MAX_ROTATE, 0);
	fill(&dessert_cafe[0][0], &dessert_cafe[MAX_CAFE-1][MAX_CAFE], 0);
	maxi = -1;
}

bool same_dessert(int a_r, int a_c, int b_r, int b_c) {
	return dessert_cafe[a_r][a_c] == dessert_cafe[b_r][b_c];
}