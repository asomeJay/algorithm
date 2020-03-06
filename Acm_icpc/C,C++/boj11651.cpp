/* 좌표출력하기2 */

#include <iostream>
#include <vector>
#include <algorithm>

#define pa pair<int,int>

using namespace std;

int N;
vector<pa> p;
bool comp(const pa a, const pa b) {
	if (a.second != b.second)
		return a.second < b.second;
	else return a.first < b.first;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N; p.resize(N);
	for (int i = 0; i < N; i++) 
		cin >> p[i].first >> p[i].second;
	
	sort(p.begin(), p.end(), comp);

	for (int i = 0; i < N; i++) 
		cout << p[i].first << " " << p[i].second << '\n';
	

	return 0;
}