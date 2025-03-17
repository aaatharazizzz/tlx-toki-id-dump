#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int main()
{
    cin >> N;
    int ctr = 0;
    while(N != 0)
    {
        if((N & (N+1)) == 0){
            N = 0;
        } else {
            N++;
        }
        ctr++;
    }
    cout << ctr;
    return 0;
}