/* 최대 문자열 붙여넣기 */

#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAX_N 501
#define MAX_L 100001
#define MAX_I 10001
using namespace std;

int pi[MAX_I], Dp[MAX_L] = { 0 }, len[MAX_N];
char main_str[MAX_L], sub_str[MAX_N][MAX_I];
bool can_str[MAX_N][MAX_L];
int Ans, N_of_short, Main_size;

void getpi(int);
void kmp(int index);
void dynamic();

int main(void) {
    scanf("%[^\n]", main_str);
    scanf("%d", &N_of_short);
    Main_size = strlen(main_str);

    memset(&can_str[0][0], 0, sizeof(can_str));

    for (int i = 0; i < N_of_short; i++) {
        getchar();
        scanf("%[^\n]", sub_str[i]);
        len[i] = strlen(sub_str[i]);
        memset(pi, 0, sizeof(pi));

        getpi(i);
        kmp(i);
    }
 
    dynamic();
    
    for (int i = 0; i < Main_size; i++) {
        if (Ans < Dp[i])
            Ans = Dp[i];
    }
    printf("%d\n", Ans);
    return 0;
}

void getpi(int index) {
    for (int i = 1, j = 0; i < len[index]; i++) {
        while (j > 0 && (sub_str[index][i] != sub_str[index][j]))
            j = pi[j - 1];
        if (sub_str[index][i] == sub_str[index][j]) {
            pi[i] = ++j;
        }
    }
}

void kmp(int index) {
    for (int i = 0, j = 0; i < Main_size; i++) {
        while (j > 0 && main_str[i] != sub_str[index][j])
            j = pi[j - 1];
        if (main_str[i] == sub_str[index][j]) {
            if (j == (len[index] - 1)) {
                can_str[index][i - j] = true;
                j = pi[j];
            }
            else
                ++j;
        }
    }
}

void dynamic() {
    for (int i = 0; i < MAX_N; i++) {
        if (can_str[i][0] == true) {
            Dp[len[i] - 1] = len[i];
        }
    }

    int maxi = Dp[0];
    
    for (int i = 1; i < Main_size; i++) {
        for (int j = 0; j < MAX_N; j++) {
            if (can_str[j][i] == true) {
                Dp[i + len[j] - 1] =
                    max(Dp[i + len[j] - 1], maxi + len[j]);
            }
        }
        maxi = max(maxi, Dp[i]);
    }
}