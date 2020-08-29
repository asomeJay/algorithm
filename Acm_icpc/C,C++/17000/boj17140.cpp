/* ������ �迭�� ���� */

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

#define pp pair<int,int>

using namespace std;

void input();
void solve();

inline bool comp(pp& a, pp& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int r, c, k, R,C;
vector<vector<int>> v_main;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	solve();
	return 0;
}

void input() {
	cin >> r >> c >> k;
	R = 3;
	C = 3;
	v_main.resize(4);
	for (int i = 1; i <= 3; i++) {
		v_main[i].resize(4);
		for (int j = 1; j <= 3; j++) {
			cin >> v_main[i][j];
		}
	}
}

void solve() {
	int time = 0;
	
	while (true) {
		vector<vector<int>> v_temp;

		int maxi = 0;

		if (r <= R && c <= C&& v_main[r][c] == k) 
			break;
		if (time > 100) {
			time = -1;
			break;
		}
	
		time++;
		if (R >= C) {
			v_temp.resize(R + 1);
			for (int i = 1; i <= R; i++) {
				vector<pp> v;
				map<int, int> m;
				for (int j = 1; j <= C; j++) {
					// ������
					if (m.count(v_main[i][j]) == 0) {
						m.insert(make_pair(v_main[i][j], 1));
					}
					// ������
					else {
						m.find(v_main[i][j])->second++;
					}
				}
				m.erase(0);
				maxi = max(maxi, 2 * (int)m.size());
				
				//�� �� �� ������. 

				// m�� {����, ����}�� �����Ǿ��ִµ� �켱 ���� �������� ���������� �ϹǷ�
				// ���� �������� �������� �� �ڿ� ���� �������� ���������� �Ѵ�. 
				// �׷����� vector v�� �������� �־�� �Ѵ�. 
				for (auto iter = m.begin(); iter != m.end(); iter++) {
					if (iter->first == 0)
						continue;
					v.push_back(make_pair(iter->first, iter->second));
				}

				// value, key ������ �����ȴ�. 
				sort(v.begin(), v.end(), comp);
				
				v_temp[i].push_back(0);
				//  �Է��Ѵ�.
				for (auto k : v) {
					v_temp[i].push_back(k.first);
					v_temp[i].push_back(k.second);
				}
			}

			// �� ���������� ���� �Լ��� �Űܾ��Ѵ�. 
			for (int i = 1; i <= R; i++) {
				v_temp[i].resize(maxi + 1, 0);
			}
			C = min(100 + 1, maxi);

			v_main = v_temp;
		}

		else {
			v_temp.resize(C + 1);
			for (int i = 1; i <= C; i++) {
				vector<pp> v;
				map<int, int> m;
				for (int j = 1; j <= R; j++) {
					// ������
					if (m.count(v_main[j][i]) == 0) {
						m.insert(make_pair(v_main[j][i], 1));
					}
					// ������
					else {
						m.find(v_main[j][i])->second++;
					}
				}
				m.erase(0);
				maxi = max(maxi,2 * (int)m.size());
				
				//�� �� �� ������. ����// ����// �� ����Ǿ� �ִ���
				// ������ ���ؼ� ����, ���ڷ� �����Ѵ�. 
				for (auto iter = m.begin(); iter != m.end(); iter++) {
					if (iter->first == 0) continue;
					v.push_back(make_pair(iter->first, iter->second));
				}

				// �����ϸ� ���� ��������, ���ϰ����� ���� ���������� �ȴ�.
				sort(v.begin(), v.end(), comp);
				v_temp[i].push_back(0);

				for (auto k : v) {
					v_temp[i].push_back(k.first);
					v_temp[i].push_back(k.second);
				}
			}

			// �� ���������� ���� �Լ��� �Űܾ��Ѵ�. 
			for (int i = 1; i <= C; i++) {
				v_temp[i].resize(maxi + 1, 0);
			}
			
			vector<vector<int>> vv;
			vv.resize(maxi+1);

			for (int i = 1; i <= maxi; i++) {
				vv[i].resize(C + 1, 0);
			}
			R = min(100 + 1, maxi);
			for (int i = 1; i <= C; i++) {
				for (int j = 1; j <= maxi; j++) {
					vv[j][i] = v_temp[i][j];
				
				};
			}

			v_main = vv;
		}
	}

	cout << time << '\n';
	return;
}