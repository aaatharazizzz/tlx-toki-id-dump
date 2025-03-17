#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod 998244353

int N, F;
int main()
{
    cin >> N >> F;
    if(F == 1)
    {
        for(int i = 0; i < N; i++)
        {
            if(i == 0 || i == N-1){
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
    } else {
        
        
    }
    return 0;
}