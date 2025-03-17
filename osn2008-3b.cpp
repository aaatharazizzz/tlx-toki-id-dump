#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
ll dp[1001][1001];

int main() {
    for(int i = 0; i < 1001; i++) {
        fill_n(dp[i], 1001, 0);
    }
    fill_n(dp[0], 1001, 1);
    cin >> n;
    for(int i = 1; i <= 1000/3; i++) {

        for(int j = i*3; j <= 1000; j++) {
            dp[i][j] =  dp[i][j-1] + dp[i-1][j-3];
            dp[i][j] %= 1000000;
        }
    }
    ll ans = 0;
    for(int i = 0; i <= n/3; i++) {
        ans += dp[i][n];
        ans %= 1000000;
    }
    cout << ans;
}