/* ���ڼҸ� �ùķ��̼� */

/*
1. ���� �̵� ��Ų��. 0.5��.
2. �� ������ �߰� �浹���� ���� ���´ٴ� �� Ư¡�̴�. �׷��� �̵����� 0.5�� �ߴ�
3. �ε����� �� �� �������� �����ϹǷ� �̰� Ans�� ���ϰ� �� ������ �������� 0���� �����.
4. �� ������ ������ �������� 0�� �ֵ��� vector���� pop ��Ų��.
5. �� ������ 4000�� �ݺ��Ѵ�. -1000 ~ 1000���� �����̴°� 2000�ε� �츰 
0.5�� �����̱� �����̴�. 
��
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

#define N 0
#define S 1
#define W 2
#define E 3

using namespace std;

const int dr[4] = { 1, -1, 0, 0 };
const int dc[4] = { 0, 0, -1, 1 };

int Ans;

class atom {
public:
	double r, c;
	int dir, e; // row, column, energy, Time_Stamp
	atom(double r, double c, int dir, int energy) {
		this->r = r;
		this->c = c;
		this->dir = dir;
		this->e = energy;
	}
	atom() { ; }
};

int n_of_atom, zero_count;
//atom atom_vector[1001];
vector<atom> atom_vector;

void init();
void move();
inline bool is_range(double r, double c) {
	return r >= -1000 && r <= 1000 && c >= -1000 && c <= 1000;
}
inline bool comp(atom a, atom b) {
	if (a.e == 0 || b.e == 0) {
		return a.e > b.e;
	}

	if (a.r == b.r) {
		return a.c < b.c;
	}
	return a.r < b.r;
}

int main(void) {
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		init();
		cin >> n_of_atom;
		
		atom_vector.resize(n_of_atom);

		for (int j = 0; j < n_of_atom; j++) 
			scanf(" %lf %lf %d %d", &atom_vector[j].c, &atom_vector[j].r, &atom_vector[j].dir, &atom_vector[j].e);


		for (int j = 0; j < 4000; j++) {
			if (atom_vector.size() <= 0)
				break;
			move();
		}
		printf("#%d %d\n", i, Ans);
	}

	return 0;
}

void init() {
	Ans = 0;
	zero_count = 0;
}

void move() {
	int vs = (int)atom_vector.size();
	int before = zero_count;
	
	for (int i = 0; i < vs; i++) {
		if (!is_range(atom_vector[i].r, atom_vector[i].c)) {
			zero_count++;
			atom_vector[i].e = 0;
			continue;
		}

		atom_vector[i].r += (dr[atom_vector[i].dir] * 0.5);
		atom_vector[i].c += (dc[atom_vector[i].dir] * 0.5);
	}

	sort(atom_vector.begin(), atom_vector.end(), comp);

	auto n = atom_vector.end() - 1;
	
	for (int i = atom_vector.size() - 1; i >= 0;) {
		if (atom_vector[i].e == 0) {
			i--;
			atom_vector.pop_back();
		}
		else {
			break;
		}
	}

	vs = atom_vector.size();
	for (int i = 0; i < vs - 1; i++) {
		if ((atom_vector[i].r == atom_vector[i + 1].r) &&
			(atom_vector[i].c == atom_vector[i + 1].c)) {
			Ans += atom_vector[i].e;
			Ans += atom_vector[i + 1].e;
			atom_vector[i + 1].e = 0;
			atom_vector[i].e = 0;

			int j;
			for (j = i + 1; j < vs - 1; j++) {
				if (!((atom_vector[j].r == atom_vector[j + 1].r) &&
					(atom_vector[j].c == atom_vector[j + 1].c))) {
					break;
				}
				Ans += atom_vector[j + 1].e;
				atom_vector[j + 1].e = 0;
			}

			i = j-1;
		}

	}
}