#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int M, N;
bool visited[100][100];
int maze[100][100];
int dist[100][100];

void explore(int x, int y)
{
    dist[y][x] = 1;
    visited[y][x] = true;
    queue<pii> node;
    node.push({x, y});
    while(!node.empty())
    {
        int curx = node.front().first;
        int cury = node.front().second;
        node.pop();

        if(maze[cury - 1][curx] != -1 && !visited[cury - 1][curx] && cury > 0)
        {
            visited[cury - 1][curx] = true;
            dist[cury - 1][curx] = dist[cury][curx] + 1;
            node.push({curx, cury - 1});
        }
        if(maze[cury + 1][curx] != -1 && !visited[cury + 1][curx] && cury < N - 1)
        {
            visited[cury + 1][curx] = true;
            dist[cury + 1][curx] = dist[cury][curx] + 1;
            node.push({curx, cury + 1});
        }
        if(maze[cury][curx - 1] != -1 && !visited[cury][curx - 1] && curx > 0)
        {
            visited[cury][curx - 1] = true;
            dist[cury][curx - 1] = dist[cury][curx] + 1;
            node.push({curx - 1, cury});
        }
        if(maze[cury][curx + 1] != -1 && !visited[cury][curx + 1] && curx < M - 1)
        {
            visited[cury][curx + 1] = true;
            dist[cury][curx + 1] = dist[cury][curx] + 1;
            node.push({curx + 1, cury});
        }
    }
}

int main()
{
    memset(dist, 0, sizeof(dist));
    memset(visited, false, sizeof(visited));
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> maze[i][j];
        }
    }

    int x, y;
    cin >> y >> x;
    if(x == 0 && y == 0)
    {
        cout << 0;
        return 0;
    }

    explore(x - 1,  y - 1);

    int minPath = INT32_MAX;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if((i == 0 || j == 0 || i == N-1 || j == M-1) && dist[i][j] > 0)
            {
                minPath = min(minPath, dist[i][j]);
            }
        }
    }

    cout << minPath;
    return 0;
}