#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N; int K;
pair<int, int> bom[100005];
bool bombed[2002][2002];

int main()
{
    memset(bombed, false, sizeof(bombed));
    cin >> N >> K;
    for(int i = 0; i < K; i++)
    {
        cin >> bom[i].first >> bom[i].second;
    }
    for(int i = 0; i < K; i++)
    {
        //naive
        pair<int, int> upDiag = 
        //

        for(int j = bom[i].first; j <= N; j++)
        {

        }
    }
}