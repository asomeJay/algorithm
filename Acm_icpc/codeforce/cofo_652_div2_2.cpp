#include <iostream>
#include <string>

using namespace std;

int t_case;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t_case;

     for (int i = 0; i < t_case; i++) {
		int length_of_string; cin >> length_of_string;
		int find_index = 0;
		string binary_string; cin >> binary_string;
		while ((find_index = binary_string.rfind("10")) != string::npos) {
			/*if (find_index == 0) {
				binary_string.erase(0, 1);
			}*/
			if ((find_index + 2 < binary_string.length())&& 
				binary_string[find_index + 2] == '0' ){
				binary_string.erase(find_index + 1, 1);
			}
			else {
				binary_string.erase(find_index, 1);	
			}
		}
		cout << binary_string << '\n';
	}

	return 0;
}