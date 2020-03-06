/* 속타는 저녁 메뉴 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int Denominator, Numerator, N;

string Meat, Circle;
vector<int> Meat_get;

void get_meat();
void kmp();
void prime_factor();

int main(void) {
	scanf("%d ", &N);
	Denominator = N;

	Meat.resize(N); Circle.resize(N);
	for (int i = 0; i < N; i++) 
		scanf(" %c", &Meat[i]);
	
	for (int i = 0; i < N; i++) 
		scanf(" %c", &Circle[i]);

	Circle += Circle; Circle.pop_back();
	get_meat();
	kmp();
	if (Numerator == Denominator + 1) {
		cout << "1/1";
		return 0;
	}

	prime_factor();
	return 0;
}

void get_meat() {
	Meat_get.resize(N);
	for (int i = 1, j = 0; i < N; i++) {
		while (j > 0 && Meat[i] != Meat[j])
			j = Meat_get[j - 1];
		if (Meat[i] == Meat[j])
			Meat_get[i] = ++j;
	}
}

void kmp() {
	for (int i = 0, j = 0; i < (int)Circle.size(); i++) {
		while (j > 0 && Meat[j] != Circle[i])
			j = Meat_get[j - 1];
		if (Meat[j] == Circle[i]) {
			if (j == N - 1) {
				Numerator++;
				j = Meat_get[j];
			}
			else
				j++;
		}
	}
}

void prime_factor() {
	
	int a = Numerator, b = Denominator;
	while (a != 0)
	{
		int t = b % a;
		b = a;
		a = t;
	}
	printf("%d/%d\n", Numerator / b, Denominator / b);
}