/* Ä«µå 2*/

#include <iostream>
#include <queue>

using namespace std;
int N;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	queue<int> q;
	for (int i = 0; i < N; i++)
		q.push(i + 1);

	while (q.size() != 1) {
		q.pop();
		if (q.size() == 1) break;
		q.push(q.front());
		q.pop();
	}

	cout << q.front();

	return 0;
}