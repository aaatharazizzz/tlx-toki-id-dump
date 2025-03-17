#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, E, Q, R;

pii edges[200005];
int khusus[50005];
bool removed[200005];

int main()
{
    int T;
    cin >> T;
    while(T--){
        vector<int> adjList[50005];
        cin >> N >> E >> Q >> R;
        for(int i = 0; i < E; i++)
        {
            cin >> edges[i].first >> edges[i].second;
        }
        for(int i = 0; i < Q; i++)
        {
            cin >> khusus[i];
        }
        for(int i = 0; i < R; i++)
        {
            int removeIdx;
            cin >> removeIdx;
            
        }
        
    }
    
    return 0;
}