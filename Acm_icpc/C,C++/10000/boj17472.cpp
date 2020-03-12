/* �ٸ� �����2 */

#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>

#define MAX_MAP 15
#define MAX_LAND 6 + 1
#define SEA 0
#define LAND 1

using namespace std;
class node {
public:
	int a, b, w;
	node(int x, int y, int z) {
		this->a = x;
		this->b = y;
		this->w = z;
	}
};

inline bool comp(const node& a, const node& b) {
	return a.w < b.w;
}

int parent[MAX_MAP];
vector<pair<int, int>> cord[MAX_LAND];
vector<node> nodes;
int dist[MAX_MAP][MAX_MAP];
const int dr[4] = { -1, 0, 1, 0 };
const int dc[4] = { 0, 1, 0 , -1 };
int map[MAX_MAP][MAX_MAP];
int island[MAX_MAP][MAX_MAP];

int ROW, COL, last_island, mst_weight;

// Initializing
void init();
void input();

// Island Work : Identificaion, Seiz�� Connection Relation
int island_identification();
void identification(int, int, int& island_num);
bool bridge_connection(int, int);

// MST : Kruskal Algorithm
void kruskal();
int finds(int a);
void merge(int, int);
bool end_check();


inline bool is_range(int r, int c) {
	return r <= ROW && 1 <= r && c <= COL && 1 <= c;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	init();
	input();
	last_island = island_identification();

	for (int i = 2; i <= last_island; i++) {
		for (int j = i + 1; j <= last_island; j++) {
			bridge_connection(i, j);
			dist[j][i] = dist[i][j];
		}
	}

	kruskal();
	if (!end_check())
		mst_weight = -1;

	cout << mst_weight;
	
	return 0;
}

int island_identification() {
	int land_number = 2;
	for (int i = 1; i <= ROW; i++) {
		for (int j = 1; j <= COL; j++) {
			if (map[i][j] == 1) {
				identification(i, j, land_number);
			}
		}
	}

	return land_number - 1;
}

void input() {
	cin >> ROW >> COL;
	for (int i = 1; i <= ROW; i++) {
		for (int j = 1; j <= COL; j++) {
			cin >> map[i][j];
		}
	}
}

void identification(int r, int c, int& island_num) {
	stack<pair<int, int>> s;
	s.push({ r,c });

	map[r][c] = island_num;

	int tr, tc, nr, nc;
	while (!s.empty()) {
		nr = s.top().first;
		nc = s.top().second;
		cord[island_num].push_back({ nr, nc });
		s.pop();
		for (int i = 0; i < 4; i++) {
			tr = nr + dr[i];
			tc = nc + dc[i];
			if (is_range(tr, tc) && map[tr][tc] == 1) {
				s.push({ tr, tc });
				map[tr][tc] = island_num;
			}
		}
	}

	island_num++;
}

bool bridge_connection(int one, int two) {
	int i, j, k, t,p;
	for (i = 0; i < cord[one].size(); i++) {
		for (j = 0; j < cord[two].size(); j++) {
			if (cord[one][i].first == cord[two][j].first) { // Row�� ���� ���̽�
				//one �� two �߿� ���� �� �����ʿ� �ִ����� ����������� 
				// k�� ����, t�� �����ʿ� �ְ� k ~ t ���� �����ϸ鼭 �ٸ� ���ִ��� üũ�Ұž�
				if (cord[one][i].second > cord[two][j].second) {
					k = cord[two][j].second;
					t = cord[one][i].second;
				}
				else {
					k = cord[one][i].second;
					t = cord[two][j].second;
				}
				for (p = k + 1; p < t; p++) { // �����ϴٰ� �ٸ� �ֵ� ������ ���� ���� ������
					if (map[cord[one][i].first][p] != SEA)
						break;
				}

				if (p == t) { // �ٸ��ְ� ����? �׷��� ���� ���� �� �ֳ�!!! 
								// �Ÿ� ���ؼ� �ּҰ� ��� �������ٰž�!! 
					int alt = abs(k - t) - 1;
					if (alt <= 1) continue;
					dist[one][two] = min(dist[one][two], alt);
				}

			}

			else if ((cord[one][i].second == cord[two][j].second)) { // COlumn�� ���� ���̽�
				if (cord[one][i].first > cord[two][j].first) {
					k = cord[two][j].first;
					t = cord[one][i].first;
				}
				else {
					k = cord[one][i].first;
					t = cord[two][j].first;
				}
				for (p = k + 1; p < t; p++) {
					if (map[p][cord[one][i].second] != SEA)
						break;
				}
				if (p == t) {
					int alt = abs(k - t) - 1;
					if (alt <= 1) continue;
					dist[one][two] = min(dist[one][two], alt);
				}
			}
		}
	}
	// ���̵��� MST �������� �� �� ������ ��ȿ�� ����鸸 ���ܳ���
	if (dist[one][two] != 987654321 && dist[one][two] > 1) 
		nodes.push_back(node(one, two, dist[one][two]));
	
	return true;
}

void init() {
	for (int i = 2; i <= MAX_LAND; i++) {
		for (int j = 2; j <= MAX_LAND; j++) {
			dist[i][j] = 987654321;
		}
	}

	for (int i = 2; i <= MAX_LAND; i++)
		parent[i] = -1;
}

int finds(int a) {
	if (parent[a] == -1) return a;
	return parent[a] = finds(parent[a]);
}

void merge(int a, int b) {
	int pa = finds(a);
	int pb = finds(b);

	if (pa != -1 && pa == pb) return;

	parent[pa] = pb;
}
void kruskal() {
	sort(nodes.begin(), nodes.end(), comp);

	for (auto it = nodes.begin(); it != nodes.end(); it++) {
		int u = it->a;
		int v = it->b;

		int fu = finds(u), fv = finds(v);
		if (fu != -1 && fu == fv) continue;

		mst_weight += it->w;
		merge(u, v);
	}
}

/* ������ �ȵǾ��ִ� �� ������ -1 ����ؾ��ϴϱ�.*/
bool end_check() {
	int cnt = 0;
	for (int i = 2; i <= last_island; i++) {
		if (parent[i] == -1)
			cnt++;
	}

	if (cnt >= 2)
		return false;
	return true;
}