/* �̻��� �ݸ� */

/* Input
���� �迭�� ���������� �����ϰ� �ű⿡ Input data�� �޴´�.
*/

/*Implementation 
void move() �� ��� �̻����� ������ �������� �����̰� �Ѵ�. 
i) �����̷��� ���� ��ǰ�� ĥ���� ���̸� �̻��� ���� �������� ���δ�.(0�̸� �׳� ���ش�.)
ii) �������� ���̰� �̵������� �ݴ�� �ٲ۴�. ���� �̵��Ϸ��� ���� �̻����� �ִ��� 
�� ������ �����Ѵ�. 
���� �����̷��� ���� �̹� �̻����� �ִٸ�
i) �� �̻����� Time_Stamp�� �˻��ؼ� �� �̻����� �����ϸ� -> �� �̻����� �� �̻����� �ڿ� �ִ´�(push_back)
ii) �� �̻����� Time_Stamp�� �� ������ �̹� �̵��� �̻����̹Ƿ� ���� ��ģ��. (void combine())
ii-2) ��ĥ �� �̵������� �̻��� ���� �� ���� ���� �������� �Ѵ�. 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_AREA 102
#define EMPTY 0

using namespace std;

class microbe {
public:
	int index, r, c, n_of_cluster, direction;
	microbe(int a, int b, int cc, int d) {
		this->r = a;
		this->c = b;
		this->n_of_cluster = cc;
		this->direction = d;

	}
	microbe() { ; }
};

struct cmp {
	bool operator()(microbe a, microbe b) {
		if (a.r != b.r) {
			return a.r > b.r;
		}
		else {
			return a.c > b.c;
		}
	}
};

priority_queue < microbe, vector<microbe>, cmp> m_q;

int CELL, TIME, CLUSTER;
int dr[5] = { 0, -1,1,0,0 };
int dc[5] = { 0, 0,0,-1,1 };

void move(); // ��� �̻����� �����̰� �ϴ� �Լ�
int direction_change(int dir); // ������ ���ݴ�� �ٲ��ִ� �Լ�
bool is_touch(int r, int c); // �̻����� ���� ���ᰡ ĥ���� ������ �ִ��� �˻��ϴ� �Լ� 
int sum();

int main(void) {
	int i, j, t_case;
	int row, col, cluster, direct;
	cin >> t_case;

	microbe t;

	for (i = 1; i <= t_case; i++) {		
		cin >> CELL >> TIME >> CLUSTER;

		for (j = 0; j < CLUSTER; j++) {
			cin >> row >> col >> cluster >> direct;

			t = microbe(row, col, cluster, direct);
			m_q.push(t);
		}

		for (j = 1; j <= TIME; j++) 
			move();
		
		cout << "#" << i << " " << sum() << '\n';
	}

	return 0;
}
/*
void move() �� ��� �̻����� ������ �������� �����̰� �Ѵ�.
i) �����̷��� ���� ��ǰ�� ĥ���� ���̸� �̻��� ���� �������� ���δ�.(0�̸� �׳� ���ش�.)
ii) �������� ���� �� �̵������� �ݴ�� �ٲ۴�*/

void move() {
	microbe t_m, f, s;
	priority_queue<microbe, vector<microbe>, cmp> t;

	while(!m_q.empty()){
		t_m = m_q.top();
		m_q.pop();

		t_m.r += dr[t_m.direction];
		t_m.c += dc[t_m.direction];

		/*���ᰡ ĥ���� ���̸� ��ü���� �������� ���̰� ������ ���ݴ�� �ٲ۴�. */
		if (is_touch(t_m.r, t_m.c)) {
			
			t_m.n_of_cluster /= 2;
			t_m.direction = direction_change(t_m.direction);

		/* ��ü ���� 0�̸� �� �̻� ������ �ʿ䵵 ������ queue�� ������ ��������*/
			if (t_m.n_of_cluster == EMPTY)
				continue;
		}

		t.push(t_m);
	}

	if (t.empty())
		return;

	f = t.top(); t.pop();
	
	int max_d, max_v, s_v;

	while (!t.empty()) {

		max_d = f.direction;
		max_v = f.n_of_cluster;
		s_v = f.n_of_cluster;

		s = t.top(); t.pop();
		while (f.r == s.r && f.c == s.c) {
			if (max_v < s.n_of_cluster) {
				max_d = s.direction;
				max_v = s.n_of_cluster;
			}

			s_v += s.n_of_cluster;
			if (t.empty()) {
				m_q.push(microbe(f.r, f.c, s_v, max_d));
				return;
			}

			f = s;
			s = t.top(); t.pop();
		}

		m_q.push(microbe(f.r, f.c, s_v, max_d));

		f = s;
	}
	m_q.push(f);
}

int direction_change(int dir) {
	switch (dir) {
	case 1:
		return 2;
	case 2:
		return 1;
	case 3:
		return 4;
	case 4:
		return 3;
	default :
		cout << "Direction_Change(int dir) Error " << '\n';
	}
}

bool is_touch(int r, int c) {
	return (r <= 0 || r >= CELL - 1) || (c <= 0 || c >= CELL - 1);
}

int sum() {
	int j;
	j = 0;
	while (!m_q.empty()) {
		microbe t_m = m_q.top();

		m_q.pop();
		j += t_m.n_of_cluster;
	}

	return j;
}