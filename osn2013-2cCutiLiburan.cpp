#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, P, Q;
int B[101], D[101], W[101];
int ans = -1;
int memo[101][501];
bool computed[101][501];

int dp(int x, int y)
{
    if(y < 0) return INT32_MIN + 1;
    if(x == 0) return 0;
    if(computed[x][y]){
        return memo[x][y];
    } else {
        computed[x][y] = true;
        return memo[x][y] = max(dp(x-1, y), dp(x-1, y - B[x]) + D[x]);
    }
}

int main()
{
    memset(memo, -1, sizeof(memo));
    memset(computed, false, sizeof(computed));
    string subsoal;
    int subId;
    cin >> subsoal >> subId;
    cin >> N >> P >> Q;
    for(int i = 1; i <= N; i++)
    {
        cin >> B[i] >> D[i] >> W[i];
    }
    cout << dp(N, P);

}