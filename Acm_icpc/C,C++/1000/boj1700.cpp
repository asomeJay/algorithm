/* 멀티탭 스케줄링 */

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
	// 뭘 빼야할까? 최대한 앞으로 쓰지 않을 걸 빼야지 
	int concentric_out = 0;

	for (int i = 0; i < n_of_use; i++) {
		int current_used = use_schedule[i];
	
		if (used.count(current_used) == 0) { // 콘센트에 꽂혀있지 않은 전기기구
			// 새로 꼽아야 한다. 

			if (total_used < n_of_hole) {// 콘센트 구멍이 꽉 차지 않았다면
				total_used++; // 콘센트 구멍이 하나 더 차게되고
				used.insert({ current_used, true }); // 사용 중인 전기기구의 목록에도 추가
			}
			else { // 콘센트 구멍이 꽉 찼다면
				map<int, bool> t = used;

				for (int j = i + 1; j < n_of_use; j++) { // 가까운 미래에 쓰이지 않을 녀석을 뽑을겁니다.
					int t_current_used = use_schedule[j];
					
					if (t.size() == 1) break;

					if (t.find(t_current_used)->second == true) { // 콘센트에 꽂혀있는 전기기구에요
						t.erase(t_current_used);
					}
				}
				used.erase(t.begin()->first); // 가장 쓰이지 않을 녀석을 지워버리고
				used.insert({ current_used, true });
				concentric_out++;
			}
		}

		else { // 이미 꼽혀있다면
			continue; // 그대로 진행하면 되죠.
		}
	}

	cout << concentric_out << '\n';
}