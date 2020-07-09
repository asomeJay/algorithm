#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;

int main(void) {	
	while (~scanf("%d", &N)) {
		vector<int> A;
		A.resize(N);

		for (int i = 0; i < N; i++) scanf("%d", &A[i]);
		scanf("%d", &S);

		for (int i = 0; i < N && S; i++) {
			int maxi = A[i], max_idx = i;
			
			for (int j = i + 1; j < N && j <= i + S; j++) {
				if (maxi < A[j]) {
					maxi = A[j];
					max_idx = j;
				}
			}

			S -= (max_idx - i);
			while (max_idx > i) A[max_idx] = A[max_idx - 1], max_idx--;
			A[i] = maxi;
		}
		for (auto i : A) {
			printf("%d ", i);
		}
		putchar('\n');
	}
	return 0;
}