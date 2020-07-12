/* 소용돌이 이쁘게 출력하기 */

#include <iostream>
#include <algorithm>

using namespace std;

long long int map[50][5];
int dr[4] = { 0, 1, 0, -1};
int dc[4] = { -1, 0, 1, 0 };

int main(void) {
	int r1, c1, r2, c2;
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	// row : -1, col : +1  == an = a(n-1) + 2 + 8(n-2) , 2 + 8n - 8 + 2 + 8n -16  / 2
	// 4n2 -10n + 6
	// row : -1, col : -1 == an = a(n-1) + 4 + 8(n-1)
	// 4(n-1)^2 + a1
	// row : 1, col : 1 == an = a(n-1) + 8n
	// a1 + 4n^2 - 4n
	// row : 1, col : -1 == an = a(n-1) + 6 + 8(n-1)
	// a1 + 4n^2 - 6n + 2
	
	int x = 0, y = 0, num = 1, dir = 1;
	while (map[0][0] == 0 || map[0][c2-c1] == 0 || map[r2-r1][0] == 0 || map[r2-r1][c2-c1] == 0) {
		if (x >= r1 && x <= r2 && y >= c1 && y <= c2) {
			map[x-r1][y-c1] = num;
		}
		if (x >= 0 && x == y) {
			y++;
			dir = 3;
			num++;
			continue;
		}
		else if (abs(x) == abs(y)){
			dir = (dir + 1) % 4;
		}

		x += dr[dir];
		y += dc[dir];
		num++;
	}
		
	int count = 0;
	while (num > 0) {
		num /= 10;
		count++;
	}
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			{
				if (j > 0) printf(" ");
			printf("%*d", count,map[i][j]);

			}
		}printf("\n");
	}
	
	return 0;
}