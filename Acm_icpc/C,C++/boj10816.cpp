/* 숫자 카드 */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_S 500000 + 1

using namespace std;

class card {
public:
	int rank, freq, value;
};

bool v_comp(const card a, const card b) {
	return a.value < b.value;
}
bool r_comp(const card a, const card b) {
	return a.rank < b.rank;
}

int N, M, s_index, a_index;
vector<card> sang, alt;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N; sang.resize(N);

	for (int i = 0; i < N; i++) 
		cin >> sang[i].value;
	
	cin >> M; alt.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> alt[i].value;
		alt[i].rank = i;
	}

	sort(sang.begin(), sang.end(), v_comp);
	sort(alt.begin(), alt.end(), v_comp);
	s_index = 0; a_index = 0;
	while (s_index < sang.size() && a_index < alt.size()) {
		if (sang[s_index].value == alt[a_index].value) {
			alt[a_index].freq++;
			s_index++;
		}
		else if (sang[s_index].value > alt[a_index].value) 
			a_index++;
		
		else if(sang[s_index].value < alt[a_index].value)
			s_index++;
	}

	for (int i = 1; i < M; i++) {
		if (alt[i].value == alt[i - 1].value)
			alt[i].freq = alt[i - 1].freq;
	}

	sort(alt.begin(), alt.end(), r_comp);
	for (int i = 0; i < M; i++) 
		cout << alt[i].freq << " ";
	
	
	return 0;
}