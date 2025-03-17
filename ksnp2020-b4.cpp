#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pow2(x) ((x) * (x))

ll n, y[100005];
ll dp[100005];


int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> y[i];
    }
    fill_n(dp, n+2, INT64_MAX);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        
        if(i > 0) dp[i-1] = min(dp[i-1], dp[i] + pow2(y[i-1]-y[i]));
        if(i > 1) dp[i-2] = min(dp[i-2], dp[i] + 3 * pow2(y[i-2]-y[i]));
        
        if(i > 0) dp[i] = min(dp[i], dp[i-1] + pow2(y[i-1]-y[i]));
        if(i > 1) dp[i] = min(dp[i], dp[i-2] + 3 * pow2(y[i-2]-y[i]));

        if(i < n-1) dp[i+1] = min(dp[i+1], dp[i] + pow2(y[i+1]-y[i]));
        if(i < n-2) dp[i+2] = min(dp[i+2], dp[i] + 3 * pow2(y[i+2]-y[i]));

    }
    cout << dp[n-1];
}