#include <bits/stdc++.h>
#define ll long long
using namespace std;



int main()
{
    int n;
    cin >> n;
    //pair of Hi, Ai
    stack<pair<ll, ll>> ha;
    ll total = 0;
    for(int i = 0; i < n; i++)
    {
        ll h;
        cin >> h;
        ll a = 1;
        while(!ha.empty() && h >= ha.top().first)
        {
            a += ha.top().second;
            ha.pop();
        } 
        ha.push({h, a});
        total += a;
        
    }
    cout << total;
    return 0;
}