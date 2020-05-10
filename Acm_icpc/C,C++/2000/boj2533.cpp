/* 사회망 서비스 (SNS) */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 1000001
#define FULL true
#define EMPTY false

using namespace std;

int N, odd, even;
vector<int> node[MAX];
bool is_color[MAX];
bool is_visit[MAX];

//void bfs();
bool recursive(int);

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int parent, child;

		cin >> parent >> child;
		node[parent].push_back(child);
		node[child].push_back(parent);
	}
	
	recursive(1);
	int sum = 0;
	for (int i = 1; i <= N; i++) 
		if (is_color[i] == FULL) sum++;
	
	
	cout << sum;
	return 0;
}
bool recursive(int now) {
	is_visit[now] = true;

	if (node[now].size() == EMPTY) 
		return EMPTY;
	
	int all_color = true;
	for (auto n : node[now]) {
		if (is_visit[n]) continue;

		if (recursive(n) == EMPTY) {
			all_color = false;
		}
	}

	if (!all_color) {
		is_color[now] = FULL;
		return FULL;
	}
	else
		return EMPTY;
}