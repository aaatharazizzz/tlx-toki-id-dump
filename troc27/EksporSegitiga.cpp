#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int a[100];
int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    bool foundEven = false;
    for(int i = 0; i < N; i++)
    {
        if(a[i] % 2 == 0)
        {
            foundEven = true;
            break;
        }
    }
    cout << (foundEven ? "YA" : "TIDAK");
    return 0;
}