/* ��Ƽ�� �����ٸ� */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n_of_hole, n_of_use, total_used;
vector<int> use_schedule;
map<int, bool> used;
//vector<bool> used;
void input();
void solve();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> n_of_hole >> n_of_use;

	//used.resize(n_of_use); 
	use_schedule.resize(n_of_use);

	for (int i = 0; i < n_of_use; i++){
		cin >> use_schedule[i];
	}
}

void solve() {
	// �� �����ұ�? �ִ��� ������ ���� ���� �� ������ 
	int concentric_out = 0;

	for (int i = 0; i < n_of_use; i++) {
		int current_used = use_schedule[i];
	
		if (used.count(current_used) == 0) { // �ܼ�Ʈ�� �������� ���� ����ⱸ
			// ���� �žƾ� �Ѵ�. 

			if (total_used < n_of_hole) {// �ܼ�Ʈ ������ �� ���� �ʾҴٸ�
				total_used++; // �ܼ�Ʈ ������ �ϳ� �� ���Եǰ�
				used.insert({ current_used, true }); // ��� ���� ����ⱸ�� ��Ͽ��� �߰�
			}
			else { // �ܼ�Ʈ ������ �� á�ٸ�
				map<int, bool> t = used;

				for (int j = i + 1; j < n_of_use; j++) { // ����� �̷��� ������ ���� �༮�� �����̴ϴ�.
					int t_current_used = use_schedule[j];
					
					if (t.size() == 1) break;

					if (t.find(t_current_used)->second == true) { // �ܼ�Ʈ�� �����ִ� ����ⱸ����
						t.erase(t_current_used);
					}
				}
				used.erase(t.begin()->first); // ���� ������ ���� �༮�� ����������
				used.insert({ current_used, true });
				concentric_out++;
			}
		}

		else { // �̹� �����ִٸ�
			continue; // �״�� �����ϸ� ����.
		}
	}

	cout << concentric_out << '\n';
}