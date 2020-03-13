/* 단어 수학 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long int maxi;
int max_size, N, cnt;
bool is_used[10];
vector<string> s;
vector<pair<char,long long int>>alphabet;
vector<char> first_alphabet;

long long int string_change(string a);
void alpha(string);
void b_track(int st_index, int depth);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	s.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> s[i];
		max_size = max(max_size, (int)s[i].size());
		// 문자열 중 가장 긴 길이가 몇인지 알아냅니다. 

		alpha(s[i]);	// INput으로 들어온 String에 속한 Alphabet을 추출합니다.
	}
		// 이제 각 문자에 값을 할당할 차례입니다. 
	// 가장 큰 값을 얻으려면 9부터 할당하는 게 옳습니다.
	for (int i = 9; i > 9 - (int)alphabet.size(); i--) { // 아까 저장한 max_size입니다
		// 만약 max_size가 5이다. 즉 제일 긴 문자열의 길이가 5라면
		// 9 8 7 6 5 까지만 쓰일 것이므로 9 - max_size를 해줬습니다. 
		alphabet[0].second = i;	// 실질적으로 값을 할당하는 과정입니다. 
		is_used[i] = true;	// 다른 문자가 같은 값을 가지는 경우는 없어야하므로 중복을 체크합니다.
		b_track(1, 1);		// 그 다음 문자에 값을 할당할 것입니다. 
		is_used[i] = false;	// 한번의 recursion이 끝났으니 그 다음으로 넘어가야합니다
							// 원상복구 시켜줍니다. 
	}

	cout << maxi;
	return 0;
}

void alpha(string a) {
	int i;
	/* Input으로 들어온 줄마다 문자를 추출해서 저장합니다.
	만약 이미 들어와있는 문자라면 저장하지않습니다. 
	이 함수를 돌리면 Input으로 들어온 모든 문자의 종류가 저장됩니다.
	예를 들면 AAA BBC가 들어오면 alphabet에 {A , 0} {B, 0} {C,0}가 저장됩니다.*/
	for (auto n : a) {
		for (i = 0; i < (int)alphabet.size(); i++) {
			if (alphabet[i].first == n) break;
		}
		if (i == alphabet.size()) {
			alphabet.push_back({ n, 0 });
		}
	}

	/* 만약 Input으로 들어온 string의 길이가 2이상이면 제일 앞에 0이 들어올 수는 없다고
	생각했습니다. (0이 들어와도 되는 경우로 제출해도 틀렸습니다가 뜨기때문에...)
	그러므로 string의 길이가 2이상이면 제일 앞 문자를 저장했습니다. 
	first_alphabet의 길이는 길어봐야 10이기 때문에 중복체크를 하지않았습니다. */
	if ((int)a.size() >= 2) 
		first_alphabet.push_back(a[0]);
}

void b_track(int st_index,int depth) {
	/* depth가 alphabet vector의 사이즈와 같다면 모든 알파벳에 값이 할당된 상황입니다.
	그러므로 이제 각 문자에 할당된 값에 맞추어서 그 String 각각의 정수값을 얻어낸 후 이들을 더하고
	그 더한 값이 최종적으로 가장 큰 값인지 비교합니다.
	큰 값이라면 갱신하고 큰 값이 아니라면 버립니다. */
	if (depth == (int)alphabet.size()) {
		
		long long int tep = 0;
		for (auto n : s) 
			tep += string_change(n);
		
		if (maxi < tep) 
			maxi = tep;
		
		return;
	}

	int j = 0;
	for (int i = 9; i > (9 - (int)alphabet.size()); i--) {
		if (is_used[i] == true) continue;	//이미 쓴 값입니다. 중복할당하지 않습니다. 
		/*if (i == 0) { // 만약 i가 0이라면, 문자열의 제일 앞에 가서는 안됩니다. 
						//이를 검사하는 파트입니다. 
			for (j = 0; j < (int)first_alphabet.size(); j++) { //first_alphabet을 순회하면서 
				// 현재 alphabet이 첫번째 알파벳인지 체크합니다.
				// 만약 첫번째 alphabet이라면 0을 할당해서는 안되고, 0을 할당해서는 안된다는 말은
				// 이 케이스는 정답이 될 수 없다는 의미입니다. 
				// 그러므로 절대 정답이 될 수 없도록 return 시킵니다. 
				if (alphabet[st_index].first == first_alphabet[j]) {
					return;
				}
			}
		}*/
		is_used[i] = true;
		alphabet[st_index].second = i;
		b_track(st_index + 1, depth + 1);
		is_used[i] = false;
	}

}

long long int string_change(string a) {

	/* 알파벳에 할당된 값에 맞춰서 정수값을 돌려줍니다. */
	long long int temp = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		for (auto n : alphabet) {
			if (n.first == a[i]) {
				temp *= 10;
				temp += n.second;
				break;
			}
		}
	}
	return temp;
}


/*cout << "alphabet ::: " << endl;
for (long long int i = 0; i < alphabet.size(); i++) {
	cout << alphabet[i].first << " " << alphabet[i].second << endl;
	cnt++;
		cout << "alphabet ::: " << endl;
		for (long long int i = 0; i < alphabet.size(); i++) {
			cout << alphabet[i].first << " " << alphabet[i].second << endl;
		}
}*/

//cout << "max_size : " << max_size << endl;
	//cout << "alpha : " << alphabet.size() << endl;
		//cout << "i:" << i << endl;
		//cout << "is_used[i] : " << is_used[i] << endl;

/*cout << "AT FINAL ::: " << endl;
			long long int tt = 0;
			for (auto n : s) {
				cout << n << endl;
				cout << string_change(n) << endl;
			}
			for (long long int i = 0; i < alphabet.size(); i++) {
				cout << alphabet[i].first << " " << alphabet[i].second << endl;
			}*/

			//cout << endl;
				//cout << alphabet.size() << endl;
				//for (auto n : alphabet) {
				//	cout << n.first << " " << n.second << endl;
				//}
				//cout << depth << " " << alphabet.size() << endl;