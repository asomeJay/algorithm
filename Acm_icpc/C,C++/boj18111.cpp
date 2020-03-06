/* 마인 크래프트 */

#include <iostream>
#include <vector>
#include <algorithm>

#define MINUS_BLOCK 2
#define PLUS_BLOCK 1
#define MAX_LAND 500
#define MAX_FREQ 257
#define MAX_TIME 2100000000
using namespace std;

int Standard_height, R, C, Inventory, Final_height, Final_Time = MAX_TIME;
int Land[MAX_LAND][MAX_LAND], mini, maxi;
vector<pair<int, int>> Land_freq;

bool comp(pair<int,int> a, pair<int,int>b) {
	return a.second > b.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C >> Inventory;
	mini = MAX_TIME; maxi = -1 * MAX_TIME;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> Land[i][j];

			if (Land[i][j] < mini)
				mini = Land[i][j];
			if (Land[i][j] > maxi)
				maxi = Land[i][j];
		}
	}
	
	for(Standard_height = mini; Standard_height <= maxi; Standard_height++){

		int acc_time = 0, inv = Inventory;
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				if (Standard_height > Land[j][k]) {
					inv -= (Standard_height - Land[j][k]);
					acc_time += (PLUS_BLOCK * (Standard_height - Land[j][k]));
				}
				else if (Standard_height < Land[j][k]){
					inv += (Land[j][k] - Standard_height);
					acc_time += (MINUS_BLOCK * (Land[j][k] - Standard_height));
				}
			}
		}

		if (inv < 0) continue;
		if (Final_Time > acc_time) {
			Final_Time = acc_time;
			Final_height = Standard_height;
		}
		else if (Final_Time == acc_time) {
			if (Final_height < Standard_height)
				Final_height = Standard_height;
		}
	}
	if (Final_Time == MAX_TIME) 
		Final_Time = 0;
	
	cout << Final_Time << " " << Final_height;

	return 0;
}