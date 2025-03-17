#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

int N, K;
int coin_vals[502];
int dp[50002];


int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> coin_vals[i];
    }
    cin >> K;
    dp[0] = 0;
    fill_n(dp + 1, 50001, INT32_MAX);
    for(int i = 1; i <= K; i++) {
        for(int j = 0; j < N; j++) {
            if(i - coin_vals[j] >= 0 && dp[i - coin_vals[j]] != INT32_MAX) {
                dp[i] = min(dp[i], dp[i - coin_vals[j]] + 1);
            }
        }
    }
    printf("%d", dp[K]);

}