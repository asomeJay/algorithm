/* ���� */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_OFFICE 10
#define WALL 6

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

#define OUT_OF_RANGE 0
#define IN_RANGE 1

using namespace std;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int N, M, mini;
int office[MAX_OFFICE][MAX_OFFICE];
vector < pair<int, int>> cctv_cord; 
vector<int> cctv_kind;

/* �־��� �Ű������� �������� �������� üũ�ؼ�
  ��������̸� IN_RANGE�� return �ϰ� �ƴ϶�� OUT_OF_RANGE�� ��� */
bool is_range(int, int);

/* �Ű������� cctv�� ������ row���� col ��, CCTV�� �ٶ󺸴� �����
CCTV�� ��ġ�� field�� �޴´�.
*/

void cctv_monitor(int, int, int, int dir, int field[][MAX_OFFICE]);

/*  CCTV�� �簢���븦 ã��, �� ���α׷��� ��ǥ �Լ� */
void cctv_blind_spot(int, int[][MAX_OFFICE]);

/* �Ű������� CCTV�� ��� ���� ���� �ְ� �� CCTV�� �ٶ󺸴� ������ �ش�.
�׸��� �� CCTV�� ��ġ�� �迭�� �Ű������� �����ν� 
CCTV�� ������ ����, CCTV�� �ٶ󺸴� ���⿡ ��ġ�� 0�� #���� �ٲ��ش�. */
void dir_conquer(int r, int c, int dir, int field[][MAX_OFFICE]);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int i, j;
	cin >> N >> M;

	/* cctv_cord�� cctv_kind�� ���������� ����Ǿ���.
	cctv_cord���� �� cctv�� ��ǥ���� pair<int,int> �ڷ������� ����Ǿ��ְ�
	cctv_kind���� �� ��ǥ�� �����ϴ� cctv�� ������ ����Ǿ� �ִ�. */

	cctv_cord.push_back(make_pair(NULL, NULL));
	cctv_kind.push_back(NULL);

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			cin >> office[i][j];
			if(office[i][j] == 0)
				mini++;

			if (office[i][j] >= 1 && office[i][j] <= 5) {
				cctv_cord.push_back(make_pair(i, j));
				cctv_kind.push_back(office[i][j]);
			}
		}
	}

	//cctv_kind.size()�� 1�̶�� �� cctv�� �������� �ʴ´ٴ� �ǹ��̹Ƿ�
	// ĭ ���� ��ü(mini�� �ʱⰪ)�� ����Ѵ�. 
	if (cctv_kind.size() != 1) 
		cctv_blind_spot(1, office);
	
	cout << mini << '\n';
	return 0;
}

bool is_range(int r_, int c_) {
	if (r_ >= 1 && r_ <= N && c_ >= 1 && c_ <= M) {
		return IN_RANGE;
	}
	return OUT_OF_RANGE;
}

/* dir�� ���� �� �ִ� ���� NORTH, EAST, SOUTH, WEST �ۿ� ����. */
void dir_conquer(int r_, int c_, int dir, int field[][MAX_OFFICE]) {
	int r, c;
	r = r_; c = c_;

	/*��� ���� ���� ��������� ����ų� 
	  ���� ���������� ��� #���� �����. */

	while (is_range(r, c) == IN_RANGE && office[r][c] != WALL) {
		field[r][c] = '#';
		r += dr[dir];
		c += dc[dir];
	}
}

void cctv_blind_spot(int index, int field[][MAX_OFFICE]) {
	int i, j, cctv_k, countt = 0;

	/* index���� cctv_kind.size()��� �� vecor�� ���� �ٴٶ��ٴ� �ǹ��̹Ƿ�
	�����ִ� 0�� ������ ���� ��������� �ּڰ��� ���ؼ� �ּҰ� 
	mini�� �����Ѵ�. */
	if (index >= cctv_kind.size()) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= M; j++) {
				if (field[i][j] == 0)
					countt++;
			}
		}

		mini = min(mini, countt);
		return;
	}
	
	int t_field[MAX_OFFICE][MAX_OFFICE];

	cctv_k = cctv_kind[index];

	/* 
	cctv_k = cctv_kind 
	  cctv ������ 5�� �ƴ϶�� �� �� ������(���� �ٲ㰡�鼭)
	  ���� cctv 2������ ��� ���� �� �ִ� ����� �� ������ ����������
	  �������� ���ؼ� ���ƴ�. 
	*/
	if (cctv_k != 5) {
		for (i = 0; i < 4; i++) {
			copy(&field[0][0], &field[MAX_OFFICE - 1][MAX_OFFICE - 1],
				&t_field[0][0]);

			cctv_monitor(cctv_k, cctv_cord[index].first, cctv_cord[index].second,
				i, t_field);
			cctv_blind_spot(index + 1, t_field);
		}
	}

	else {
		copy(&field[0][0], &field[MAX_OFFICE - 1][MAX_OFFICE - 1],
			&t_field[0][0]);

		cctv_monitor(5, cctv_cord[index].first, cctv_cord[index].second,
			i, t_field);
		cctv_blind_spot(index + 1, t_field);
	}
}

/* cctv�� ������ ���ڷ� �޾Ƽ� �׿� �ɸ°� ó���Ѵ�. */
void cctv_monitor(int cctv_kind, int r, int c, int dir, int field[][MAX_OFFICE]) {
	switch (cctv_kind) {
	case 1:
		dir_conquer(r, c, dir, field);
		break;
	case 2:
		dir_conquer(r, c, dir, field);
		dir_conquer(r, c, (dir + 2) % 4, field);
		break;
	case 3:
		dir_conquer(r, c, dir, field);
		dir_conquer(r, c, (dir + 1) % 4, field);
		break;
	case 4:
		dir_conquer(r, c, dir, field);
		dir_conquer(r, c, (dir + 1) % 4, field);
		dir_conquer(r, c, (dir + 2) % 4, field);
		break; 
	case 5:
		dir_conquer(r, c, NORTH, field);
		dir_conquer(r, c, EAST, field);
		dir_conquer(r, c, SOUTH, field);
		dir_conquer(r, c, WEST, field);
		break;
	default : 
		cout << "WFT";
	}
}