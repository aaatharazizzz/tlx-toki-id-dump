#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> e[100010];
ll n, p, q;

int main() {
    cin >> n >> p >> q;
    for(int i = 0; i < n; i++) {
        cin >> e[i].first;
        e[i].second = i;
    }
    
}