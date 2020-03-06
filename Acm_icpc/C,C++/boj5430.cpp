/* AC */

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <stack>

#define LAST 1
#define FIRST -1

using namespace std;

int flag, pointer = FIRST;
deque<int> number;
string func, input_num;

deque<int> refine(string s);
void R();
void D();
void init();
void print();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int T, n_of_num;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		init();

		cin >> func >> n_of_num >> input_num;

		number = refine(input_num); // 숫자만 빼낼거야
		
		for (int i = 0; i < (int)func.size(); i++) {
			switch (func[i]) {
			case 'R':
				pointer *= -1;
				break;
			case 'D':
				if (number.empty()) {
					flag = 1;
					break;
				}
				D();
				break;
			}
		}
		if (pointer == LAST)
			R();
		print();
		
	}
	return 0;
}

void init() {
	func.clear(); input_num.clear(); // string
	number.clear();

	flag = 0; pointer = FIRST;
}

deque<int> refine(string s) {
	deque<int> res;

	for (int i = 0; i < s.size(); i++) {
		int sum = 0;
		while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
			sum = sum * 10 + s[i] - '0';
			i++;
		}
		if (sum != 0)
			res.push_back(sum);
	}

	return res;
}

void print() {
	if (flag == 1) {
		cout << "error\n";
		return;
	}
	int i;
	cout << '[';
	while (number.size() > 1) {
		cout << number.front() << ',';
		number.pop_front();
	}
	if (!number.empty()) {
		cout << number.front(); 
		number.pop_front();
	}
		
	cout << "]\n";
}

void R(){
	stack<int> t;
	while (!number.empty()) {
		t.push(number.front());
		number.pop_front();
	}

	while (!t.empty()) {
		number.push_back(t.top());
		t.pop();
	}
}

void D() {
	if (pointer == FIRST) {
		number.pop_front();
	}
	else
		number.pop_back();
	
}