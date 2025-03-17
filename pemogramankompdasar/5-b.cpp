#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool over1mil = false;
ll base, expo;
ll mod = 1000000;
int main()
{
    cin >> base >> expo;
    
    ll ans = 1;
    while(expo > 0)
    {
        //cout << ans << ' ' << base << '\n';
        if(ans * base >= 1000000) over1mil = true;
        base %= mod;
        if(expo % 2 == 1)
        {
            ans = (ans * base) % mod;
            
        }
        base = (base * base);
        expo /= 2;
    }
    
    if(over1mil) cout << setw(6) << setfill('0');
    cout << ans;
    return 0;
}