#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string subsoal;
int N, M;
int K;
ll toko[36][36];
bool visited[36][36];
vector<ll> possiblePaths;

void visit(int x = 0, int y = 0, ll total = 0)
{
    if((x < 0 || y < 0 || x == N || y == M)) return;
    if(visited[x][y]) return;
    
    total += toko[x][y];
    visited[x][y] = true;
    if(x == N - 1 && y == M - 1)
    {
        possiblePaths.push_back(total);
    } else {
        visit(x - 1, y, total);
        visit(x + 1, y, total);
        visit(x, y - 1, total);
        visit(x, y + 1, total);
    }
    visited[x][y] = false;
}

int main(){
    memset(visited, false, sizeof(visited));
    cin >> subsoal;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> toko[i][j];
        }
    }
    visit();
    sort(possiblePaths.begin(), possiblePaths.end());
    
    cin >> K;
    while(K--)
    {
        ll p, q;
        cin >> p >> q;
        cout << upper_bound(possiblePaths.begin(), possiblePaths.end(), q) - 
                lower_bound(possiblePaths.begin(), possiblePaths.end(), p) << '\n';
    }
    return 0;
}