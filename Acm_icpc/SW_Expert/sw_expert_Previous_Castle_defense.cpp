/* ĳ�� ���潺 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX_LAND 16
#define MAX_D 11
#define END 0
#define KEEP_GO 1
#define NOT_MATCHED -1

using namespace std;

int land[MAX_LAND][MAX_LAND];
int N, M, D;

vector<int>enemy[MAX_LAND];

/* �ü��� ��ġ�� �޾Ƽ� �����ϴ� �Լ� */
void attack(int arc1, int arc2, int arc3);
void destroy(pair<int, int>);

/* �ϳ��� �ü� ��ġ�� �Ű������� �޾Ƽ� ������ ������ �� 
�����ϴ� �Լ� */
pair<int,int> target_determine(int arc);

/* �Ÿ� ����ϴ� �Լ� */
int dist(int r, int c, int n_r, int n_c);
void copy_vector(vector<int>[], vector<int>[]);

/* ������ ������ �ؾ��� ���� �ϴ� �Լ�.*/
void after_attack();

bool is_end();

int counti, maxi;

int main(void) {
	/* for�� ������ �����鼭 ��� �ü��� ��ġ�� ���Ѵ�. */
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int i, j, k;

	cin >> N >> M >> D;
	
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			cin >> land[i][j];
			// ���� �ִ� ���̶�� ������ �����������. 
			if (land[i][j] == 1) {
				enemy[j].push_back(i);
			}
		}
	}
	vector<int> temporary_storage[MAX_LAND];
	copy_vector(temporary_storage, enemy);

	// �ü��� ��ġ�� ���ݾ� �ٲ㰡�鼭 ��� ����� ���� ����Ѵ�. 
	for (i = 1; i <= M; i++) {
		for (j = i + 1; j <= M; j++) {
			for (k = j + 1; k <= M; k++) {
				counti = 0;

				attack(i, j, k);

				maxi  = max(counti, maxi);
				copy_vector(enemy, temporary_storage);

			}
		}
	}

	cout << maxi << "\n";
	return 0;
}

void attack(int arc1, int arc2, int arc3) {
	// 1. �� �ü��� ���� ����� ã�´�. choose()
	pair<int, int> target1, target2, target3;

	while (is_end() == KEEP_GO) {
		target1 = target_determine(arc1);
		target2 = target_determine(arc2);
		target3 = target_determine(arc3);

		// 2. �����Ѵ�. (�����Ѵ�)
		destroy(target1); destroy(target2); destroy(target3);

		for (int i = 1; i <= M; i++) {
			if (!enemy[i].empty() && enemy[i].back() == 0) {
				enemy[i].pop_back();
			}
		}

		// 3. ���� �� ĭ�� ������. after_attack()
		after_attack();
	}
}

/* �ü��� ������ ��� ã�� �Լ��� */
pair<int,int> target_determine(int arc) {
	int col, row, t_dist, ind_r, ind_c, mini;

	ind_r = ind_c = NOT_MATCHED;
	mini = INT_MAX;

	// 1) �Ÿ��� D ���Ͽ��� �ϰ� 
	for (col = 1; col <= M; col++) {
		if (enemy[col].empty()) continue;

		row = enemy[col].back();
		t_dist = dist(row, col, N + 1, arc);

		if (t_dist > D) continue;

	// 2) ���� ����� ���̰�
		if (mini > t_dist) {
			mini = t_dist;
			ind_c = col;
			ind_r = row;
		}
	}
	// 3) �׷� ���� ������ ���� ������ �����Ѵ�.
	return make_pair(ind_r, ind_c);
}

/* ���� �Ŀ� �� �ϵ� */
void after_attack() {
	int i, j;
	for (i = 1; i <= M; i++) {
		if (enemy[i].empty()) continue;

		for (j = 0; j < enemy[i].size(); j++) {
			enemy[i][j]++;
		}

		if (enemy[i].back() > N) {
			enemy[i].pop_back();
		}
	}
}

void destroy(pair<int, int> target) {
	if (target.first == NOT_MATCHED \
		&& target.second == NOT_MATCHED)
		return;

	int r, c;
	r = target.first; c = target.second;

	if (enemy[c].back() != 0) {
		enemy[c].pop_back();
		enemy[c].push_back(0);
		counti++;
	}
}

int dist(int r, int c, int n_r, int n_c) {
	return abs(n_r - r) + abs(n_c - c);
}

bool is_end() {
	int i;
	for (i = 1; i <= M; i++) {
		if (enemy[i].empty())continue;
		return KEEP_GO;
	}
	return END;
}

void copy_vector(vector<int> temporary_storage[], vector<int> go[]) {
	int i, j;
	for (i = 1; i <= M; i++) {
		if (go[i].empty()) continue;
		for (j = 0; j < go[i].size(); j++) {
			temporary_storage[i].push_back(go[i][j]);
		}
	}
}