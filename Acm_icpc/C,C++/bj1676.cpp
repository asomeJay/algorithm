/* ���丮�� 0�� ���� */

#include <iostream>

using namespace std;

int N;

int main(void) {
	scanf("%d", &N);
	int k, sum;
	k = 1, sum = 0;
	sum += N / 125 + N / 25 + N / 5;
	
	printf("%d\n", sum);
	
	return 0;
}