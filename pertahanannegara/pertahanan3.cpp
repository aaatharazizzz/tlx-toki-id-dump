#include <bits/stdc++.h>
using namespace std;

int poop;
int N, M, K;

int main()
{
    freopen("pertahanan_3.in", "r", stdin);
    freopen("pertahanan_3.out", "w", stdout);
    int y = 0;
    int tmpY;
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++)
    {
        cin >> tmpY;
        cout << "0 1 " << y << ' ' << tmpY + y << '\n';
        y += tmpY;
    }
    
}