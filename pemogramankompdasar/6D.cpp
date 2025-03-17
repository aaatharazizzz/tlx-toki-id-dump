#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n;
    ll d;
    std::cin >> n >> d;
    std::vector<std::pair<ll, ll>> hb;
    
    for(int i = 0; i < n; i++)
    {
        ll tmph, tmpb;
        std::cin >> tmph >> tmpb;
        hb.push_back({tmph, tmpb});
    }
    std::sort(hb.begin(), hb.end());

    ll bebekSenang = 0;
    for(int i = 0; i < n; i++)
    {
        ll bebek = min(hb[i].second, d / hb[i].first);
        d  -= bebek * hb[i].first;
        bebekSenang += bebek;
    }
    cout << bebekSenang;
    return 0;
}