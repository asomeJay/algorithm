/* 이차원 배열과 연산 */

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
					// 없으면
					if (m.count(v_main[i][j]) == 0) {
						m.insert(make_pair(v_main[i][j], 1));
					}
					// 있으면
					else {
						m.find(v_main[i][j])->second++;
					}
				}
				m.erase(0);
				maxi = max(maxi, 2 * (int)m.size());
				
				//한 행 다 끝났음. 

				// m은 {숫자, 개수}로 정리되어있는데 우선 개수 기준으로 오름차순을 하므로
				// 개수 기준으로 오름차순 한 뒤에 숫자 기준으로 오름차순을 한다. 
				// 그럴려면 vector v에 개수부터 넣어야 한다. 
				for (auto iter = m.begin(); iter != m.end(); iter++) {
					if (iter->first == 0)
						continue;
					v.push_back(make_pair(iter->first, iter->second));
				}

				// value, key 순으로 나열된다. 
				sort(v.begin(), v.end(), comp);
				
				v_temp[i].push_back(0);
				//  입력한다.
				for (auto k : v) {
					v_temp[i].push_back(k.first);
					v_temp[i].push_back(k.second);
				}
			}

			// 다 정렬했으면 원래 함수에 옮겨야한다. 
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
					// 없으면
					if (m.count(v_main[j][i]) == 0) {
						m.insert(make_pair(v_main[j][i], 1));
					}
					// 있으면
					else {
						m.find(v_main[j][i])->second++;
					}
				}
				m.erase(0);
				maxi = max(maxi,2 * (int)m.size());
				
				//한 열 다 끝났음. 숫자// 개수// 로 저장되어 있던걸
				// 정렬을 위해서 개수, 숫자로 저장한다. 
				for (auto iter = m.begin(); iter != m.end(); iter++) {
					if (iter->first == 0) continue;
					v.push_back(make_pair(iter->first, iter->second));
				}

				// 정렬하면 개수 오름차순, 동일개수는 숫자 오름차순이 된다.
				sort(v.begin(), v.end(), comp);
				v_temp[i].push_back(0);

				for (auto k : v) {
					v_temp[i].push_back(k.first);
					v_temp[i].push_back(k.second);
				}
			}

			// 다 정렬했으면 원래 함수에 옮겨야한다. 
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