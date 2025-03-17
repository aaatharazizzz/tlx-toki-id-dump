#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll v, h, n;

pair<ll, ll> p[501][501];
ll memo[501][501];
bool batu[501][501];

bool inBounds(ll x, ll y)
{
    return x >= 0 && x < h && y >= 0 && y < v;
}

ll dp(ll x, ll y)
{
    if(!inBounds(x, y)) return 0;
    

}

int main(){
    cin >> v >> h >> n;
    for(int i = 0; i < n; i++)
    {
        ll v1, h1, v2, h2;
        cin >> v1 >> h1 >> v2 >> h2;
        for(int j = v1; j <= v2; j++)
        {
            for(int k = h1; k <= h2; k++)
            {
                batu[j][k] = true;
                p[j][k] = {h1, h2};
            }
        }
    }

    ll maks = 0;
    
}