#include <bits/stdc++.h>
using namespace std;

int n;
int memo[1001];
bool computed[1001];

int emasMax(int emas)
{
    if(emas == 0) return 0;
    if(computed[emas]) return memo[emas];
    int best = emas;
    best = max(emas, emasMax(emas/2) + emasMax(emas/3) + emasMax(emas/4));
    computed[emas] = true;
    memo[emas] = best;
    return best;
}

int main()
{
    cin >> n;
    cout << emasMax(n);
    return 0;
}