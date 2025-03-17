#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll K, Q;
string subsoal;
ll bcount;
ll n;

int main()
{
    string s;
    cin >> subsoal;
    cin >> s;
    cin >> K >> Q;
    n = s.length() * K + 1;
    bcount = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'B') bcount++;
    }
    ll t = bcount * K + 1;

    while(Q--)
    {
        ll l, r;
        cin >> l >> r;
        if(l == 1 && r == n) cout << t;
        //i love Penis
        //penis
    }
}
