#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, K;
int b[1001];
int a[1001][1001];
int l[1001];
int r[1001];

int main()
{
    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        cin >> b[i];
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < K; i++)
    {
        cin >> l[i];
    }
    for(int i = 0; i < K; i++)
    {
        cin >> r[i];
    }

    
}