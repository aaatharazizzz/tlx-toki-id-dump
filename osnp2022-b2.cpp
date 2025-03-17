#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct pc {
    ll p;
    ll c;
};

ll K, N, b[100005];
pc k[1005];

int main() {
    cin >> K;
    for(int i = 0; i < K; i++) {
        cin >> k[i].p;
    }
    for(int i = 0; i < K; i++) {
        cin >> k[i].c;
    }
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> b[i];
    }
    sort(k, k + K, [](pc a, pc b) {return a.c < b.c;});
    sort(b, b + N, greater<ll>());
    ll res = 0;
    int k_idx = 0;
    for(int i = 0; i < N; i++) {
        if(k_idx >= K) break;
        if(k[k_idx].p <= 0) k_idx++;
        res += b[i] * k[k_idx].c;
        k[k_idx].p -= 1;
    }
    cout << res;
}