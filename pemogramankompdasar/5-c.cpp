#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a, b, c, n;

ll fast_exp(ll base, ll power, ll mod) {
    ll ans = 1;
    while(power > 0)
    {
        if(power % 2 == 1)
        {
            ans = (ans * base) % mod;
        }
        power /= 2;
        base = (base * base) % mod;
    }
    return ans;
}
int main() {
    cin >> a >> b >> c >> n;
    for(ll i = 0; i < c; i++) {
        a = fast_exp(a, b, n);
    }
    cout << a + 1;
}