#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll p, q, r, T;
    cin >> p >> q >> r >> T;
    for(int i = 0; i < T; i++) {
        ll n; cin >> n;
        if(n % p == 0 && n % q == 0 && n % r == 0) {
            printf("YA\n");
        } else {
            printf("TIDAK\n");
        }
    }
    return 0;
}