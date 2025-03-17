#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod 998244353

int main()
{
    ll n, m;
    cin >> n >> m;
    
    cout << (n*m) - max(n, m);
    return 0;
}