#include <iostream>
#include <vector>


using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    vector<int> stones;
    int N, l = 200000000 , r = -1;
    cin >> N;
    stones.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> stones[i];
        if (r < stones[i])
            r = stones[i];
        if (l > stones[i])
            l = stones[i];
    }
        
    int k;
    cin >> k;
    int answer = (l + r)  / 2;
    int n = stones.size();

    while (l <= r) {
        //mid 명의 사람이 건넌다고 가정
        bool can = true;
        int mid = (l + r) / 2;
        int length = 0;
        //O(n) 선형 탐색
        for (int i = 0; i < stones.size(); i++) {
            //못건너게 되는 stone
            if (stones[i] < mid) {
                length++;
            }
            else length = 0;

            if (length == k) {
                answer = mid;
                can = false;
                break;
            }
        }
        if (can) l = mid + 1;
        else r = mid - 1;
    }
    cout <<  answer;
    return 0;
}