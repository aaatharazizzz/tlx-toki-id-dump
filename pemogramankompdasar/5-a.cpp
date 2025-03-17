#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M; 
ll a[1 << 18];

enum canstate {
    OVER,
    UNDER,
    YAY
};

canstate can(ll n) {
    ll ctr = 0;
    for(ll i = 0; i < N; i++) {
        ctr += n / a[i];
    }
    if(ctr > M) return OVER;
    if(ctr < M) return UNDER;
    return YAY;
}

ll duwang(ll l, ll r) {
    ll mid;
    while(l <= r) {
        mid = (l+r)/2;
        canstate state = can(mid);
        if(state == YAY) return mid;
        if(state == OVER) {
            r = mid - 1;
        }
        if(state == UNDER) {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    ll x;
    cin >> N >> M;
    ll mina = INT64_MAX;
    for(ll i = 0; i < N; i++) {
        cin >> a[i];
        mina = min(mina, a[i]);
    }
    ll doodoo = duwang(0, mina * M);
    if(doodoo == -1) {
        cout << 0; return 0;
    }
    ll minlow = INT64_MAX, minhigh = INT64_MAX;
    for(ll i = 0; i < N; i++) {
        minlow = min(minlow, doodoo % a[i]);
        minhigh = min(minhigh, a[i] - (doodoo % a[i]));
    }
    cout << minlow + minhigh;
    
}

