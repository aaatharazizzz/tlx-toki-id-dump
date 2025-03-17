#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> poop(n);
    for(int i = 0; i < n; i++)
    {
        cin >> poop[i];
    }
    int aBound = lower_bound(poop.begin(), poop.end(), a) - poop.begin();
    int bBound = upper_bound(poop.begin(), poop.end(), b) - poop.begin();
    std::cout << bBound - aBound;
    return 0;
}