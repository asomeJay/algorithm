/* �ٱ⼼�� ��� */

#include <iostream>
#include <vector>
#include <cstring>

#define IN_RANGE 1
#define MAX_MAP 1000
#define INDEX_START 450

bool is_range(int r, int c);
void init();

using namespace std;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0, 1, 0 ,-1 };
int map[MAX_MAP][MAX_MAP]; // Input�� 450/450���� ������ �� ���ڴ�.
int n_dead_cell[11];
int n_t_case, N, M, tick, for_tick, alive_cell;

class cell {
public:
	int r, c, life_power;
	int wake_up_time, dead_time;

	cell(int a, int b, int c) {
		this->r = a;
		this->c = b;
		this->life_power = c;

		this->wake_up_time = tick + life_power;
		this->dead_time = tick + 2 * life_power;
	}
};
vector<cell> cell_map[11];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n_t_case;

	int i, j, k;
	for (int t = 0; t < n_t_case; t++) {
		init();
		cin >> N >> M >> for_tick;

		// ���� [450][450]���� ä�������� �����ҰŴ�.
		// �ֵ��� �����ϴϱ� ���ʿ� �߾Ӻ��� �����ϴ� ����
		for (i = INDEX_START; i < INDEX_START + N; i++) {
			for (j = INDEX_START; j < INDEX_START + M; j++) {
				cin >> map[i][j];

				// �ٱ⼼������ ��ġ�� �� �����ϵ��� ����
				// �׸��� Ȱ�������� ��Ȱ������ ����� ������ ���� �����̹Ƿ�
				// �� ���̿� ������ �����ʰ� ��� ����.
				if (map[i][j] != 0) {
					cell_map[map[i][j]].push_back(cell(i, j, map[i][j]));
					alive_cell++;
				}
			}
		}

		while (tick++ != for_tick) {
			for (i = 10; i >= 1; i--) {
				int vector_size = cell_map[i].size();

				for (j = n_dead_cell[i]; j < vector_size; j++) {
					int wake_time = cell_map[i][j].wake_up_time;
					if (wake_time > tick) // Not yet
						break;

					if (wake_time + 1 == tick) { //  ���� �ܰ�
						for (k = 0; k < 4; k++) {
							int nr = cell_map[i][j].r + dr[k];
							int nc = cell_map[i][j].c + dc[k];
							
							if (is_range(nr, nc) == IN_RANGE && map[nr][nc] == 0) {
								map[nr][nc] = i;
								cell_map[i].push_back(cell(nr, nc, i));
								alive_cell++;
							}
						}
					}
				}

				for (j = n_dead_cell[i]; j < vector_size; j++) {
					int d_time = cell_map[i][j].dead_time;
					if (d_time > tick) break;
					if (d_time == tick) {
						alive_cell--;
						n_dead_cell[i]++;
					}
						
				}
			}
		}

		cout << "#" << t+1 << " " << alive_cell << '\n';
	}

	return 0;
}

bool is_range(int r, int c) {
	return r <= MAX_MAP && r >= 1 && c <= MAX_MAP && c >= 1;
}

void init() {
	int i, j;
	tick = 0; alive_cell = 0;
	memset(n_dead_cell, 0, sizeof(n_dead_cell));
	for (i = 0; i < 11; i++) {
		cell_map[i].clear();
	}

	memset(&map[0][0], 0, sizeof(map));
}