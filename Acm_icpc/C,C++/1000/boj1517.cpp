/* ���� ��Ʈ */

#include <iostream>
#include <algorithm>

#define MAX 500000 + 1

using namespace std;
int N, arr[MAX], temp[MAX];
long long int ANS;

void merge(int p, int m, int q);
void mergeSort(int p, int q);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	mergeSort(0, N - 1);
	cout << ANS << '\n';

	return 0;
}
void merge(int p, int m, int q) {
	int i = p, j = m + 1;
	int idx = p, cnt = 0;

	while (i <= m || j <= q) {
		if (i > m) { // �� ���� ���� �� ������
			temp[idx++] = arr[j++];
		} 
		else if (j > q) {	// ���������� �� ���� ���� �� ����
			temp[idx++] = arr[i++];
			ANS += (long long)cnt;
		} 
		else if (arr[i] <= arr[j]) {	// arr[i]�� �ڱ� ��ġ�� ���� �� ���ݱ��� j �������� ��ŭ ���Ѵ�. 
			temp[idx++] = arr[i++];
			ANS += (long long)cnt;
		}
		else {
			temp[idx++] = arr[j++];
			cnt++;
		}
	}
	for (int i = p; i <= q; i++) arr[i] = temp[i];
}

void mergeSort(int p, int q) {
	if (p < q) {
		int m = (p + q) / 2;
		mergeSort(p, m);
		mergeSort(m + 1, q);
		merge(p, m, q);
	}
}