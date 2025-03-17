#include <bits/stdc++.h>
using namespace std;
#define ll long long

std::vector<ll> getPrimeList(ll n)
{
    vector<ll> primeList;
    bool eliminated[n + 1];
    for(ll p = 2; p < sqrt(n); p++)
    {
        if(!eliminated[p])
        {
            primeList.push_back(p);
            for(ll j = p * p; j <= n; j += p)
            {
                eliminated[j] = true;
            }
        }
    }
    return primeList;
}

ll fucktorial(ll n)
{
    ll res = 1;
    for(int i = 2; i <= n; i++)
    {
        res *= i;
    }
    return res;
}

ll kombinasi(ll n, ll r)
{
    fucktorial(n) / (fucktorial(r) * fucktorial(n - r));
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<long long> var(n);
    vector<ll> primeList = getPrimeList(k);
    vector<ll> factorK; 
    
    for(auto v : primeList)
    {
        if(k % v == 0)
        {
            ll tmp = 0;
            while (k % v == 0 && k > 1)
            {
                k /= v;
                tmp++;
            }
            factorK.push_back(tmp);
        }
    }
    
    ll total;
    for(auto v : factorK)
    {
        total *= kombinasi()
    }
    return 0;
}
