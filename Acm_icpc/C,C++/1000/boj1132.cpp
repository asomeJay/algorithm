#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define ll long long int
#define MAX 10

using namespace std;
class node {
public :	
	char character;
	ll value;
	bool is_first = false;
	node(char a, ll b, bool c) {
		this->character = a;
		this->value = b;
		this->is_first= c;
	}
	node() {
		;
	}
};
node dp[MAX];
ll char_value[MAX];
ll ANS, N, value;

vector<string> str_set, temp_set;

ll str_to_int(string);
void init();
inline bool comp(node a, node b) {
	return a.value > b.value;
	/*if (a.is_first == true && b.is_first == true) {
		return a.value > b.value;
	}
	else if (a.is_first == true && b.is_first == false) {
		return true;
	} 
	else if (a.is_first == false && b.is_first == true) {
		return false;
	}
	else {
		return a.value > b.value;
	}*/
}
// 뭐가 할당될 지는 생각하지 말고 일단 자릿수의 개수부터 구한다음
// 제일 많은 순서대로 값을 ASsign 한다. 
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	init();

	for (int i = 0; i < N; i++) {
		cin >> str_set[i];
		for (int k = temp_set[i].size()-1 , j = str_set[i].size()-1; j>=0; k--,j--) {
			temp_set[i][k] = str_set[i][j];
		}
		dp[str_set[i][0] - 'A'].is_first = true;
	}	
	
	ll digit = 1;
	for (int idx = 11; idx >= 0; idx--) {
		for (int i = 0; i < N; i++) {
			if (temp_set[i][idx] != '0') {
				dp[temp_set[i][idx] - 'A'].value += digit;
			}
		}

		digit *= 10;
	}
	sort(dp, dp + 10, comp);


	if (dp[9].is_first == true) {
		for (int i = 8; i >= 0; i--) {
			if (dp[i].is_first == false) {
				node temp = dp[i];
				for (int j = i; j <= 8; j++)
					dp[j] = dp[j + 1];
				
				dp[9] = temp;
				break;
			}
		}
	}
	int value = 9;
	/*for (int i = 0; i < 10; i++) {
		cout << dp[i].character << " " << dp[i].value << " " << dp[i].is_first << endl;
	}*/
	for (int i = 0; i < 10; i++) {
		char_value[dp[i].character- 'A'] = value--;

	}

	//for (int i = 0; i < 10; i++) cout << char_value[i]<< endl;
	for (int i = 0; i < N; i++) {
		ANS += str_to_int(str_set[i]);
	}

	cout << ANS << '\n';

	return 0;
}

ll str_to_int(string s) {
	ll temp = 0;
	for (int i = 0; i< s.size(); i++) {
		temp *= 10;
		temp += char_value[s[i] - 'A'];
	}
	//cout << s << " " << temp << endl;
	return temp;
		
}
void init() {
	
	str_set.resize(N);
	temp_set.resize(N);

	for (int i = 0; i < N; i++) {
		temp_set[i] = "000000000000";
	}
	for (int i = 0; i < 10; i++) {
		dp[i].character = 'A' + i;
		dp[i].value = 0;
		dp[i].is_first = false;
	}
}
