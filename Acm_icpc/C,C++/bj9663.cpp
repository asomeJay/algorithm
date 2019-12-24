/* ��Ʈ��ŷ : N-Queen ���� */

#include <iostream>

using namespace std;

void dfs(int);
int check(int, int);

int tb[20];
int n;
int count1;

int main(void) {
	int i, j, k;
	scanf("%d", &n); // ���� ü������ N X N �̴�. 
	
	for (i = 1; i <= n; i++) {
		tb[1] = i;
		dfs(2);
	}
	printf("%d\n", count1);

	return 0;
}
void dfs(int row) {
	int i, j, k;

	if (row > n) {
		count1++;
		return;
	}

	for (i = 1; i <= n; i++) {
		if (check(row, i) == 0) continue;
		tb[row] = i;
		dfs(row + 1);
	}
}

int check(int row, int index) {
	int i, j, k;
	for (i = 1; i <= row-1; i++) {
		if (index == tb[i]) return 0; // ���� ��
		if (index - tb[i] == row - i) return 0; // ���밢�� 
		if (tb[i] - index == row - i) return 0;
	}

	return 1;
}