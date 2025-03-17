#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define ll long long

int N, K;
int dp[105][2005] = {0};
// bool dpvisited[105][2005] = {0};
int w[105];
int h[105];
// bool taken[101] = {0};

// int knaprec(int i, int c) {
//     if(i < 1) return 0;
//     if(dpvisited[i][c] == true) return dp[i][c];
//     int best = knaprec(i-1, c);
//     if(w[i] <= c) {
//         best = max(best, h[i] + knaprec(i-1, c - w[i]));
//     }
//     dpvisited[i][c] = best;
//     dp[i][c] = best;
//     return best;
// }

void knapbup() {
    for(int i = 1; i <= K; i++) {
        for(int c = 0; c <= N; c++) {
            int best = dp[i-1][c];
            if(w[i] <= c) {
                best = max(best, h[i] + dp[i-1][c - w[i]]);
            }
            dp[i][c] = best;
        }
    }

}

vector<int> ans;

void track(int i, int c) {
    if(i == 0) return;
    if(dp[i][c] == dp[i-1][c]) {
        track(i-1, c);
    } else {
        track(i-1, c - w[i]);
        ans.push_back(i);
    }
}

int main() {
    cin >> N >> K;
    for(int i = 1; i <= K; i++) {
        cin >> w[i] >> h[i];
    }
    knapbup();
    int tmp;
    for(int i = 1; i <= N; i++) {
        if(dp[K][i] == dp[K][N]) {
            tmp = i;
            break;
        }
    }
    for(int i = K; i >= 1; i--) {
        if(dp[i][tmp] != dp[i-1][tmp]) {
            ans.push_back(i);
            tmp -= w[i];
        }
    }
    // for(int i = 0; i <= K; i++) {
    //     for(int j = 0; j <= N; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for(int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << '\n';
    }
}